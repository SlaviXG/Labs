#include "ComplexMatrix.h"

ComplexMatrix GaussJordanInverse(ComplexMatrix A)
{
    int rank = A.get_rows(); //rows
    int columns = A.get_columns(); //columns

    assert(rank == columns);
    assert(rank == A.getRank());

    ComplexMatrix tempMatrix(rank, 2*rank);

    //setting the temp matrix
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < 2 * rank; j++)
        {
            if(j < rank)
                tempMatrix.set(i,j,A.get(i,j));
            if (j == (i + rank))
                tempMatrix.set(i,j,1, 0);
        }
    }

    for(int i = 0; i < rank; i++)
    {
        tempMatrix.set(i, i + rank, 1, 0);
    }

//    //interchanging the rows
//    for (int i = rank - 1; i > 0; i--)
//    {
//        if (tempMatrix.get(i-1,0).get_real() < tempMatrix.get(i,0).get_real())
//        {
//            tempMatrix.swapRows(i, i-1);
//        }
//    }

//    std::cout << std::endl;
//    tempMatrix.print();

    for(int i = 0; i < rank; i++)
    {

        bool swapped = false;
        while(tempMatrix.get(i, i)==ComplexNum(0,0)) {tempMatrix.swapRows(i, i+1); swapped = true;}
        if(swapped) {i = std::max(0, i-1); continue;}
        if(tempMatrix.get(i,i)==ComplexNum(0,0)) throw std::exception(); // checking nulls on a principal diagonal

        for(int j = 0; j < rank; j++)
        {
            if(i != j)
            {
                ComplexNum temp = tempMatrix.get(j, i) / tempMatrix.get(i, i);

                for(int k = 0; k < 2 * rank; k++)
                {
                    tempMatrix.set(j, k, tempMatrix.get(j, k) -  tempMatrix.get(i, k) * temp);
                }
            }
        }
    }

    for (int i = 0; i < rank; i++)
    {
        ComplexNum temp = tempMatrix.get(i, i);
        for (int j = 0; j < 2 * rank; j++)
        {
            tempMatrix.set(i, j, tempMatrix.get(i,j) / temp);
        }
    }

    ComplexMatrix resMatrix(rank, rank);

    for(int i = 0; i < rank; i++)
    {
        for(int j = rank; j < 2*rank; j++)
        {
            resMatrix.set(i, j - rank, tempMatrix.get(i,j));
        }
    }

    return resMatrix;
}