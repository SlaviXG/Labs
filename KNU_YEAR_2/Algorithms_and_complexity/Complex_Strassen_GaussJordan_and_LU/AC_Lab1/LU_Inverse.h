#include <iostream>
#include "ComplexNum.h"
#include "ComplexMatrix.h"
#include "Strassen.h"

bool LU_decomposition(ComplexMatrix a, ComplexMatrix& l, ComplexMatrix& u)
{
	if (a.get_columns() != a.get_rows())
		return false;

	int n = a.get_columns();

	l = ComplexMatrix(n, n);
	u = ComplexMatrix(n, n);

	ComplexNum zero;
	ComplexNum one(1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			l.set(i, j, zero);
			u.set(i, j, zero);
		}
		l.set(i, i, one);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ComplexNum to_add = a.get(i, j);
			if (i <= j)
			{
				for (int k = 0; k <= i - 1; k++)
					to_add = to_add - (l.get(i, k) * u.get(k, j));
				u.set(i, j, to_add);
			}
			else
			{
				ComplexNum divider = u.get(j, j);
				if (divider.get_real() == 0 && divider.get_imag() == 0)
					return false;;
				for (int k = 0; k <= j - 1; k++)
					to_add = to_add - (l.get(i, k) * u.get(k, j));
				to_add = to_add/ divider;
				l.set(i, j, to_add);
			}
		}
	}

	return true;
}

ComplexNum* createEmpty(int n)
{
	ComplexNum* result = new ComplexNum[n];
	for (int i = 0; i < n; i++)
		result[i] = ComplexNum();
	return result;
}

ComplexNum* ForwardSubstitution(ComplexMatrix l, ComplexNum* vector, int n)
{
	ComplexNum* result = new ComplexNum[n];
	for (int i = 0; i < n; i++)
	{
		ComplexNum to_add = vector[i];
		for (int j = 0; j < n - 1; j++)
			to_add = to_add - l.get(i, j) * result[j];
		to_add = to_add / l.get(i, i);
		result[i] = to_add;
	}
	return result;
}

ComplexNum* BackSubstitution(ComplexMatrix u, ComplexNum* vector, int n)
{
	ComplexNum* result = new ComplexNum[n];
	for (int i = n-1; i >= 0; i--)
	{
		ComplexNum to_add = vector[i];
		for (int j = i + 1; j < n; j++)
			to_add = to_add - u.get(i, j) * result[j];
		to_add = to_add / u.get(i, i);
		result[i] = to_add;
	}
	return result;
}

ComplexMatrix LU_inverse(ComplexMatrix a)
{
	ComplexMatrix l(0, 0);
	ComplexMatrix u(0, 0);

	if (!LU_decomposition(a, l, u))
		return ComplexMatrix(0, 0);

	int n = a.get_columns();
	ComplexMatrix res(n, n);

	for (int i = 0; i < n; i++)
	{
		ComplexNum* unit_vector = createEmpty(n);
		unit_vector[i] = ComplexNum(1, 0);
		ComplexNum* l_vector = ForwardSubstitution(l, unit_vector, n);
		ComplexNum* u_vector = BackSubstitution(u, l_vector, n);
		res.set_column(i, u_vector);
		delete[] unit_vector;
		delete[] l_vector;
		delete[] u_vector;
	}

	return res;
}



