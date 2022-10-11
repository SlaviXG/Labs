#pragma once
#include<iostream>
#include"ComplexNum.h"
#include <cassert>
class ComplexMatrix
{
private:
	ComplexNum** matrix;
	int columns;
	int rows;
public:
	ComplexMatrix(unsigned int rows, unsigned int columns) {
		matrix = new ComplexNum * [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new ComplexNum[columns];
		}
		this->columns = columns;
		this->rows = rows;
	}

	ComplexMatrix(const ComplexMatrix& copy) {
		this->rows = copy.rows;
		this->columns = copy.columns;
		matrix = new ComplexNum * [rows];
		for (int i = 0; i < this->rows; i++)
			this->matrix[i] = new ComplexNum[copy.columns];

		for (int i = 0; i < copy.rows; i++)
			for (int j = 0; j < copy.columns; j++)
				this->matrix[i][j] = copy.matrix[i][j];
	}

	~ComplexMatrix() {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		this->rows = NULL;
		this->columns = NULL;
	}

	void auto_gen(int min_real, int max_real, int min_imag, int max_imag) {
		int span_real = abs(max_real - min_real) + 1;
		int span_imag = abs(max_imag - min_imag) + 1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i][j] = ComplexNum(rand() % span_real + min_real, rand() % span_imag + min_imag);
			}
		}
	}

	int get_columns() {
		return columns;
	}

	int get_rows() {
		return rows;
	}

	void set(unsigned int i, unsigned int j, double real, double imag) {
		assert(i < rows);
		assert(j < columns);
		matrix[i][j] = ComplexNum(real, imag);
	}

	void set(unsigned int i, unsigned int j, ComplexNum num) {
		assert(i < rows);
		assert(j < columns);
		matrix[i][j] = num;
	}

	void set_column(int j, ComplexNum* num)
	{
		for (int i = 0; i < this->rows; i++)
			this->set(i, j, num[i]);
	}

	void set_row(int i, ComplexNum* num)
	{
		for (int j = 0; j < this->columns; j++)
			this->set(i, j, num[j]);
	}

	ComplexNum get(unsigned int i, unsigned int j) {
		assert(i < rows);
		assert(j < columns);
		return matrix[i][j];
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << matrix[i][j] << "  ";
			}
			std::cout << '\n';
		}
		std::cout << "\n\n";
	}

    //function for exchanging two rows of a matrix
    void swapRows(int row1, int row2)
    {
        assert(row1 >= 0 and row1 < rows);
        assert(row2 >= 0 and row2 < columns);

        int col = this->get_columns();
        for (int i = 0; i < col; i++)
        {
            ComplexNum temp = matrix[row1][i];
            matrix[row1][i] = matrix[row2][i];
            matrix[row2][i] = temp;
        }
    }

    int getRank()
    {
        ComplexMatrix complexMatrix = *this;

        int R = complexMatrix.get_rows();
        int rank = complexMatrix.get_columns();

        for(int row = 0; row < rank; row++)
        {
            if(complexMatrix.get(row,row) != ComplexNum())
            {
                for (int col = 0; col < R; col++)
                {
                    if (col != row)
                    {
                        ComplexNum mult = complexMatrix.get(col, row) / complexMatrix.get(row, row);
                        for (int i = 0; i < rank; i++)
                            complexMatrix.set(col, i,
                                              complexMatrix.get(col, i) - mult * complexMatrix.get(row, i));
                    }
                }
            }
            else
            {
                bool reduce = true;

                for (int i = row + 1; i < R;  i++)
                {
                    if (complexMatrix.get(i,row) != ComplexNum())
                    {
                        complexMatrix.swapRows(row, i);
                        reduce = false;
                        break ;
                    }
                }
                if (reduce)
                {
                    rank--;
                    for (int i = 0; i < R; i ++)
                        complexMatrix.set(i, row, complexMatrix.get(i, rank));
                }

                row--;
            }
        }

        return rank;
    }

	ComplexMatrix& operator =(const ComplexMatrix& copy) {
		if (this != &copy)
		{
			for (int i = 0; i < this->rows; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;

			matrix = new ComplexNum * [copy.rows];
			this->rows = copy.rows;
			this->columns = copy.columns;
			for (int i = 0; i < copy.rows; i++)
				this->matrix[i] = new ComplexNum[copy.columns];

			for (int i = 0; i < copy.rows; i++)
				for (int j = 0; j < copy.columns; j++)
					this->matrix[i][j] = copy.matrix[i][j];
		}
		return *this;
	}

	ComplexMatrix operator +(const ComplexMatrix& other)const  //add 2 matrix
	{
		ComplexMatrix temp(this->rows, this->columns);
		if (rows != other.rows || columns != other.columns)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					temp.matrix[i][j] = this->matrix[i][j];
			return temp;
		}
		else
		{
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					temp.matrix[i][j] = other.matrix[i][j] + matrix[i][j];

				}
			}
		}
		return temp;
	}

	ComplexMatrix operator *(const ComplexMatrix& other)const  //multiply (o(n^3) way) 2 matrix
	{
		ComplexMatrix res(this->rows, other.columns);
		for (int i = 0; i < this->rows; i++) 
		{
			for (int j = 0; j < other.columns; j++) 
			{
				for (int k = 0; k < other.rows; k++)
				{
					auto to_check1 = this->matrix[i][k];
					auto to_check2 = other.matrix[k][j];
					res.matrix[i][j] = res.matrix[i][j] + this->matrix[i][k] * other.matrix[k][j];
				}
			}
		}
		return res;
	}

	bool operator ==(const ComplexMatrix& other)const
	{
		if (this->columns != other.columns || this->rows != other.rows)
			return false;

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				auto to_check1 = this->matrix[i][j];
				auto to_check2 = other.matrix[i][j];
				if (this->matrix[i][j] != other.matrix[i][j])
					return false;
			}
		}

		return true;
	}


	ComplexMatrix operator -(const ComplexMatrix& other)const  //subtract 2 matrix
	{
		ComplexMatrix temp(this->rows, this->columns);
		if (rows != other.rows || columns != other.columns)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					temp.matrix[i][j] = this->matrix[i][j];
			return temp;
		}
		else
		{
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					temp.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];

				}
			}
		}
		return temp;
	}

};

