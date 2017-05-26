#pragma once
#include "iostream"
#include "string"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include<sstream>        //istringstream必须包含这个头文件
#include "CComplex.h"

using namespace std;

class CMatrix
{
public:
	CMatrix(){};
	CMatrix(const CMatrix &s);
	CMatrix(vector<vector<CComplex>> b);
	CMatrix(unsigned int n);
	CMatrix(unsigned int m,unsigned int n);
	CMatrix(unsigned int n,string &s);
	void set_dim(unsigned int n);
	void set_dim(unsigned int m, unsigned int n);
	void readMatrix(string fileName);
	void showMatrix();
	void writeMatrix(string str);
	double norm1();//求矩阵的逆矩阵
	double norm2();//求矩阵的逆矩阵
	double normInf();//求矩阵的逆矩阵
	CMatrix inversion();//求矩阵的逆矩阵
	CMatrix pow(int n);//求矩阵的幂


	//张硕
	void inversion(CMatrix & v_InverMat);//求矩阵的逆矩阵

	void PowMat(int n, CMatrix &vm);//求矩阵的幂

	//矩阵A、B、C、D合成为一个矩阵
	void Merge(CMatrix &A, CMatrix &B, CMatrix &C, CMatrix &D);

	//对称矩阵拆分为A、B两个矩阵
	void Split(CMatrix &A, CMatrix &B);

	void Cothx(CMatrix &v_CothXMat, unsigned int k);

	void Cschx(CMatrix &v_CschXMat, unsigned int k);
	//


	CMatrix coladd(unsigned int i, unsigned int j);//
	CMatrix rowadd(unsigned int i, unsigned int j);//
	CMatrix delet(unsigned int i);//
	CMatrix delet(unsigned int i, unsigned int j);//
	CMatrix deletcol(unsigned int i);//
	CMatrix deletrow(unsigned int i);//
	void change();//求矩阵的转置
	CMatrix operator +(CMatrix &a);//声明重载运算符的“+”函数
	CMatrix operator -(CMatrix &a);//声明重载运算符的“-”函数
	CMatrix operator *(CMatrix &a);//声明重载运算符的“*”函数
	CMatrix& operator =(CMatrix &a);//声明重载运算符的“=”赋值函数
	CMatrix operator *(CComplex &a);//声明重载运算符的“*”函数
	CMatrix operator *(double &a);//声明重载运算符的“*”函数

	vector<vector<CComplex>> _mat;
	int row;
	int col;

	friend ostream& operator << (ostream& out, CMatrix & m);
};


///////////////////

extern double BernoulliNum[];

extern const double Pn[];
extern const double CMsg[];
extern const double Hf[];
