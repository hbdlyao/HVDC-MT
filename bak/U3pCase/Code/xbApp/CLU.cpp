#include "CLU.h"

void CLU::ALU(double* A, double* b, double* x, int Dim)
{
	double* l = new double[Dim*Dim]();
	double* u = new double[Dim*Dim]();
	double* y = new double[Dim]();

	int i, r, k;
	//进行U的第一行的赋值
	for (i = 0; i < Dim; i++)
	{
		u[0 * Dim + i] = A[0 * Dim + i];
	}

	//进行L的第一列的赋值
	for (i = 1; i < Dim; i++)
	{
		l[i*Dim + 0] = A[i*Dim + 0] / u[0 * Dim + 0];
	}

	//计算U的剩下的行数和L的剩下的列数
	for (r = 1; r < Dim; r++)
	{
		for (i = r; i < Dim; i++)
		{
			double sum1 = 0;
			for (k = 0; k < r; k++)
			{
				sum1 += l[r*Dim + k] * u[k*Dim + i];
				//cout << "" << r << "" << sum1 << endl;
			}
			u[r*Dim + i] = A[r*Dim + i] - sum1;
		}


		if (r != Dim)
			for (i = r + 1; i < Dim; i++)
			{
				double sum2 = 0;
				for (k = 0; k < r; k++)
				{
					sum2 += l[i*Dim + k] * u[k*Dim + r];
				}
				l[i*Dim + r] = (A[i*Dim + r] - sum2) / u[r*Dim + r];
			}

	}

	y[0] = b[0];
	for (i = 1; i < Dim; i++)
	{
		double sum3 = 0;
		for (k = 0; k < i; k++)
			sum3 += l[i*Dim + k] * y[k];
		y[i] = b[i] - sum3;
	}

	x[Dim - 1] = y[Dim - 1] / u[(Dim - 1)*Dim + (Dim - 1)];
	for (i = Dim - 2; i >= 0; i--)
	{
		double sum4 = 0;
		for (k = i + 1; k < Dim; k++)
			sum4 += u[i*Dim + k] * x[k];
		x[i] = (y[i] - sum4) / u[i*Dim + i];
	}

	delete[]l;
	delete[]u;
	delete[]y;
	return;
}