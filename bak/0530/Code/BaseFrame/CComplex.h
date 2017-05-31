///////////////////////////////////////////////////////////
//  CComplex.cpp
//  Created on:      06-4月-2017 
//  Original author: 马骏鹏
///////////////////////////////////////////////////////////
#pragma once



#include <iostream>
class CComplex
{
public:
	CComplex(const CComplex &z);
	CComplex(double x = 0.0, double y = 0.0);
	~CComplex();
	double real() const { return dat[0]; }
	double image() const { return dat[1]; }
	double abs() const { return hypot(dat[0], dat[1]); }
	void set(double x, double y) { dat[0] = x; dat[1] = y; }
	double arg() const;
	double abs2() const;
	double logabs() const;
	CComplex conjugate() const;
	CComplex inverse() const;
	CComplex zsqrt() const;

	CComplex operator +(const CComplex &other) const;
	CComplex operator +(const double &other) const;

	CComplex operator -(const CComplex &other) const;
	CComplex operator -(const double &other) const;

	CComplex operator *(const CComplex &other) const;
	CComplex operator *(const double &other) const;

	CComplex operator /(const CComplex &other) const;
	CComplex operator /(const double &other) const;

	void operator +=(const CComplex &other);
	void operator +=(const double &other);

	void operator -=(const CComplex &other);
	void operator -=(const double &other);

	void operator *=(const CComplex &other);
	void operator *=(const double &other);

	void operator /=(const CComplex &other);
	void operator /=(const double &other);

	bool operator ==(const CComplex &other);
	bool operator ==(const double &other);

	bool operator !=(const CComplex &other);
	bool operator !=(const double &other);

	CComplex& operator =(const CComplex &other);
	CComplex& operator =(const double &other);

private:
	double dat[2];

	friend std::ostream& operator << (std::ostream&, const CComplex & z);
	friend CComplex operator -(const CComplex &other);


};

CComplex sqrt(const CComplex& a);
CComplex exp(const CComplex& a);
CComplex pow(const CComplex& a, const CComplex& b);
CComplex pow(const CComplex& a, double b);
CComplex log(const CComplex& a);
CComplex log10(const CComplex &a);
CComplex log(const CComplex &a, const CComplex &b);

// 三角函数  
CComplex sin(const CComplex& a);
CComplex cos(const CComplex& a);
CComplex tan(const CComplex& a);
CComplex cot(const CComplex& a);
CComplex sec(const CComplex& a);
CComplex csc(const CComplex& a);

// 反三角函数  
//CComplex arcsin_real(double a);
//CComplex arccos_real(double a);
//CComplex arcsec_real(double a);
//CComplex arctan_real(double a);
//CComplex arccsc_real(double a);
//CComplex arcsin(const CComplex& a);
//CComplex arccos(const CComplex& a);
//CComplex arctan(const CComplex& a);
//CComplex arcsec(const CComplex& a);
//CComplex arccsc(const CComplex& a);
//CComplex arccot(const CComplex& a);

/**********************************************************************
* CComplex Hyperbolic Functions
**********************************************************************/
CComplex sinh(const CComplex& a);
CComplex cosh(const CComplex& a);
CComplex tanh(const CComplex& a);
//CComplex sech(const CComplex& a);
//CComplex csch(const CComplex& a);
//CComplex coth(const CComplex& a);

/**********************************************************************
* Inverse CComplex Hyperbolic Functions
**********************************************************************/
//CComplex arccoth(const CComplex& a);
//CComplex arccsch(const CComplex& a);
//CComplex arcsech(const CComplex& a);
//CComplex arctanh_real(double a);
//CComplex arctanh(const CComplex& a);
//CComplex arccosh_real(double a);
//CComplex arccosh(const CComplex& a);
//CComplex arcsinh(const CComplex& a);

CComplex polar(double r, double theta);
double fabs(const CComplex &z);
