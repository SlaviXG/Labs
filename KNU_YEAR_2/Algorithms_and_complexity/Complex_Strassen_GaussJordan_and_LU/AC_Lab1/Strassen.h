#pragma once
#include <iostream>
#include "ComplexMatrix.h"



ComplexMatrix* regular_mult(ComplexMatrix* a, ComplexMatrix* b) {
    ComplexMatrix* res = new ComplexMatrix(a->get_rows(), b->get_columns());
    for (int i = 0; i < a->get_rows(); i++)
    {
        for (int j = 0; j < b->get_columns(); j++)
        {
            for (int k = 0; k < b->get_rows(); k++)
            {
                res->set(i, j,res->get(i, j) + a->get(i,k) * b->get(k,j));
            }
        }
    }
    return res;
}

ComplexMatrix* Strassen_rec(ComplexMatrix* a, ComplexMatrix* b) {
    // matrices sizes are M x N and N x Q
    int N = a->get_columns();
    int M = a->get_rows();
    int Q = b->get_columns();
    if (N <= 8 || M <= 8 || Q <= 8) {
        return regular_mult(a, b);
    }
    int new_N = N / 2 + N % 2;
    int new_M = M / 2 + M % 2;
    int new_Q = Q / 2 + Q % 2;
    ComplexMatrix a11(new_M, new_N);
    ComplexMatrix a12(new_M, new_N);
    ComplexMatrix a21(new_M, new_N);
    ComplexMatrix a22(new_M, new_N);
    
    for (int i = 0; i < new_M; i++) {
        for (int j = 0; j < new_N; j++) {
            a11.set(i, j, a->get(i, j));
            a12.set(i, j, ((j + new_N) < N) ? a->get(i, j + new_N) : ComplexNum(0, 0));
            a21.set(i, j, ((i + new_M) < M) ? a->get(i + new_M, j) : ComplexNum(0, 0));
            a22.set(i, j, ((i + new_M) < M && (j + new_N) < N) ? a->get(i + new_M, j + new_N) : ComplexNum(0, 0));
        }
    }


    ComplexMatrix b11(new_N, new_Q);
    ComplexMatrix b12(new_N, new_Q);
    ComplexMatrix b21(new_N, new_Q);
    ComplexMatrix b22(new_N, new_Q);

    for (int i = 0; i < new_N; i++) {
        for (int j = 0; j < new_Q; j++) {
            b11.set(i, j, b->get(i, j));
            b12.set(i, j, ((j + new_Q) < Q) ? b->get(i, j + new_Q) : ComplexNum(0, 0));
            b21.set(i, j, ((i + new_N) < N) ? b->get(i + new_N, j) : ComplexNum(0, 0));
            b22.set(i, j, ((i + new_N) < N && (j + new_Q) < Q) ? b->get(i + new_N, j + new_Q) : ComplexNum(0, 0));
        }
    }
    ComplexMatrix D1 = a11 + a22;
    ComplexMatrix D2 = b11 + b22;
    ComplexMatrix D3 = a21 + a22;
    ComplexMatrix D4 = b12 - b22;
    ComplexMatrix D5 = b21 - b11;
    ComplexMatrix D6 = a11 + a12;
    ComplexMatrix D7 = a21 - a11;
    ComplexMatrix D8 = b11 + b12;
    ComplexMatrix D9 = a12 - a22;
    ComplexMatrix D10 = b21 + b22;
    ComplexMatrix* M1;// = new ComplexMatrix(new_M, new_Q);
    M1 = Strassen_rec(&D1/*(a11 + a22)*/, &D2/*(b11 + b22)*/);
    ComplexMatrix* M2;// = new ComplexMatrix(new_N, new_N);
    M2 = Strassen_rec(&D3/*(a21 + a22)*/, &b11);
    ComplexMatrix* M3;// = new ComplexMatrix(new_N, new_N);
    M3 = Strassen_rec(&a11, &D4/*(b12 - b22)*/);
    ComplexMatrix* M4;// = new ComplexMatrix(new_N, new_N);
    M4 = Strassen_rec(&a22, &D5/*(b21 - b11)*/);
    ComplexMatrix* M5;// = new ComplexMatrix(new_N, new_N);
    M5 = Strassen_rec(&D6/*(a11 + a12)*/, &(b22));
    ComplexMatrix* M6;// = new ComplexMatrix(new_N, new_N);
    M6 = Strassen_rec(&D7/*(a21 - a11)*/, &D8/*(b11 + b12)*/);
    ComplexMatrix* M7;// = new ComplexMatrix(new_N, new_N);
    M7 = Strassen_rec(&D9/*(a12 - a22)*/, &D10/*(b21 + b22)*/);

    /*ComplexMatrix* R1;
    ComplexMatrix *R2;
    ComplexMatrix *R3;
    ComplexMatrix *R4;*/
    ComplexMatrix R1 = *M1 + *M4 - *M5 + *M7;
    ComplexMatrix R2 = *M3 + *M5;
    ComplexMatrix R3 = *M2 + *M4;
    ComplexMatrix R4 = *M1 - *M2 + *M3 + *M6;
    ComplexMatrix* Res = new ComplexMatrix(M, Q);
    for (int i = 0; i < new_M; i++) {
        for (int j = 0; j < new_Q; j++) {
            Res->set(i, j, R1.get(i, j));
            if ((j + new_Q) < Q) {
                Res->set(i, j + new_Q, R2.get(i, j));
            }
            if ((i + new_M) < M) {
                Res->set(i + new_M, j, R3.get(i, j));
            }
            if ((i + new_M) < M && (j + new_Q) < Q) {
                Res->set(i + new_M, j + new_Q, R4.get(i, j));
            }
        }
    }
    delete M1; delete M2; delete M3; delete M4; delete M5; delete M6; delete M7; 
   // delete R1; delete R2; delete R3; delete R4;
    return Res;
}

ComplexMatrix* Strassen(ComplexMatrix* a, ComplexMatrix* b) {
    assert(a->get_columns() == b->get_rows());
    if (a->get_columns() <= 8 || a->get_rows() <= 8 || b->get_columns() <= 8) {
        return regular_mult(a,b);
    }
    
    return Strassen_rec(a,b);

}


