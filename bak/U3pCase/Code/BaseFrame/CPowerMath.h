
#pragma once

class CPower_YU_I
{
public:
	virtual ~CPower_YU_I();

	virtual void Init();
	virtual void Clear();
	virtual void Release();

	virtual void InitMatrix(int vN);
	virtual void InitData(int vN);

protected:
	int Ydim;

public:
	virtual int GetYdim();
	virtual void SetYdim(int vN);

public:
	double* Ur_Vect;
	double* Um_Vect;

	double* Ir_Vect;
	double* Im_Vect;

	double* Yg_Matrix;
	double* Yb_Matrix;

	virtual void UpdateY0(int iNode, double vYg, double vYb);
	virtual void UpdateI0(int iNode, double vIr, double vIm);

	virtual void UpdateY(int iNode, int jNode, double vYg, double vYb);
	virtual void UpdateI(int iNode, int jNode, double vIr, double vIm);

protected:
	virtual void doUpdateYg0(int iNode, double vY);
	virtual void doUpdateYb0(int iNode, double vY);

	virtual void doUpdateYg(int iNode, int jNode, double vY);
	virtual void doUpdateYb(int iNode, int jNode, double vY);

public:
	virtual void Solve();

protected:
	virtual void doInitMatrix();
	virtual void doInitData();

};