#pragma once

class CMath_Ax_B
{
private:

public:
	CMath_Ax_B();

	virtual ~CMath_Ax_B();

	virtual void Init();
	virtual void Clear();

	virtual void InitMatrix(int vN);

	/*
	* 解线性方程组
	*/
	virtual void Sovle();
	void Sovle(int vDim, double * vAMatrix, double * vBVect, double * vXVect);

protected:
	double* A_Matrix;
	double* B_Vect;
	double* X_Vect;

	int nDim;

	virtual void doInitMatrix();
	virtual void doInitData();

	virtual void UpdateA(double * vAMatrix);
	virtual void UpdateB(double * vBVect);


	virtual void doSovle();

};
