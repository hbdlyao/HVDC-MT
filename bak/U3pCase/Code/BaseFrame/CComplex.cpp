///////////////////////////////////////////////////////////
//  CComplex.cpp
//  Created on:      06-4ÔÂ-2017 
//  Original author: Âí¿¥Åô
///////////////////////////////////////////////////////////
#include "CComplex.h"  
#include <cmath>  
#include <iomanip>


CComplex::CComplex(double x, double y)
{
	dat[0] = x;
	dat[1] = y;
}

CComplex::CComplex(const CComplex &z)
{
	dat[0] = z.dat[0];
	dat[1] = z.dat[1];
}

CComplex::~CComplex()
{

}

double CComplex::arg() const
{
	double x = dat[0];
	double y = dat[1];

	if (x == 0.0 && y == 0.0)
	{
		return 0;
	}
	return std::atan2(y, x);
}

double CComplex::abs2() const
{
	double x = dat[0];
	double y = dat[1];

	return (x * x + y * y);
}

double CComplex::logabs() const
{
	double xabs = fabs(dat[0]);
	double yabs = fabs(dat[1]);
	double max, u;

	if (xabs >= yabs)
	{
		max = xabs;
		u = yabs / xabs;
	}
	else
	{
		max = yabs;
		u = xabs / yabs;
	}

	/* Handle underflow when u is close to 0 */
	return log(max) + 0.5 * log1p(u * u);
}

CComplex CComplex::conjugate() const
{
	CComplex z(dat[0], -dat[1]);
	return z;
}

CComplex CComplex::inverse() const
{
	double s = 1.0 / fabs(*this);
	double x = this->real();
	double y = this->image();
	CComplex z(x * s * s, -y * s * s);
	return z;
}
CComplex CComplex::zsqrt() const
{
	double s = fabs(*this);
	double x = this->real();
	double y = this->image();
	double phi;
	phi = atan2(y,x);
	CComplex z(sqrt(s)*cos(phi / 2), sqrt(s)*sin(phi / 2));
	return z;
}

void CComplex::operator +=(const CComplex &other)
{
	dat[0] += other.dat[0];
	dat[1] += other.dat[1];
}

void CComplex::operator +=(const double &other)
{
	dat[0] += other;
}

void CComplex::operator -=(const CComplex &other)
{
	dat[0] -= other.dat[0];
	dat[1] -= other.dat[1];
}

void CComplex::operator -=(const double &other)
{
	dat[0] -= other;
}

void CComplex::operator *=(const CComplex &other)
{
	double x, y;
	x = (dat[0] * other.dat[0] - dat[1] * other.dat[1]);
	y = (dat[1] * other.dat[0] + dat[0] * other.dat[1]);
	dat[0] = x;
	dat[1] = y;
}

void CComplex::operator *=(const double &other)
{
	dat[0] = dat[0] * other;
	dat[1] = dat[1] * other;
}

void CComplex::operator /=(const CComplex &other)
{
	double x, y;
	double a = other.dat[0] * other.dat[0] + other.dat[1] * other.dat[1];
	x = ((dat[0] * other.dat[0]) + (dat[1] * other.dat[1])) / a;
	y = ((dat[1] * other.dat[0]) - (dat[0] * other.dat[1])) / a;
	dat[0] = x;
	dat[1] = y;
}

void CComplex::operator /=(const double &other)
{
	dat[0] = dat[0] / other;
	dat[1] = dat[1] / other;
}

bool CComplex::operator ==(const CComplex &other)
{
	if ((dat[0] == other.dat[0]) && (dat[1] == other.dat[1]))
		return 1;
	else
		return 0;
}

bool CComplex::operator ==(const double &other)
{
	if ((dat[0] == other) && (dat[1] == 0))
		return 1;
	else
		return 0;
}

bool CComplex::operator !=(const CComplex &other)
{
	if ((dat[0] == other.dat[0]) && (dat[1] == other.dat[1]))
		return 0;
	else
		return 1;
}

bool CComplex::operator !=(const double &other)
{
	if ((dat[0] == other) && (dat[1] == 0))
		return 0;
	else
		return 1;
}

CComplex CComplex::operator+(const CComplex &other)  const
{
	CComplex temp(*this);
	temp += other;
	return temp;
}

CComplex CComplex::operator +(const double &other) const
{
	CComplex temp(*this);
	temp += other;
	return temp;
}

CComplex CComplex::operator -(const CComplex &other) const
{
	CComplex temp(*this);
	temp -= other;
	return temp;
}

CComplex CComplex::operator -(const double &other) const
{
	CComplex temp(*this);
	temp -= other;
	return temp;
}

CComplex operator -(const CComplex &other)
{
	CComplex temp(-other.real(), -other.image());
	return temp;
}

CComplex CComplex::operator *(const CComplex &other) const
{
	CComplex temp(*this);
	temp *= other;
	return temp;
}

CComplex CComplex::operator *(const double &other) const
{
	CComplex temp(*this);
	temp *= other;
	return temp;
}

CComplex CComplex::operator /(const CComplex &other) const
{
	CComplex temp(*this);
	temp /= other;
	return temp;
}

CComplex CComplex::operator /(const double &other) const
{
	CComplex temp(*this);
	temp /= other;
	return temp;
}

CComplex& CComplex::operator =(const CComplex &other)
{
	this->dat[0] = other.dat[0];
	this->dat[1] = other.dat[1];
	return *this;
}

CComplex& CComplex::operator =(const double &other)
{
	this->dat[0] = other;
	this->dat[1] = 0;
	return *this;
}
std::ostream& operator << (std::ostream& out, const CComplex & z)
{
	//if (z.image() >= 0)
	//{
	//	out << z.real() << "+" << z.image() <<"i";
	//}
	//else
	//{
	//	out << z.real() << "-" << -z.image() << "i";
	//}
	out << z.abs() << "¡Ï" << z.arg();
	return out;
}


CComplex polar(double r, double theta)
{
	CComplex z(r * cos(theta), r * sin(theta));
	return z;
}

double fabs(const CComplex &z)
{
	return hypot(z.real(), z.image());
}

CComplex sqrt(const CComplex& a)
{
	CComplex z;

	if (a.real() == 0.0 && a.image() == 0.0)
	{
		z = CComplex(0, 0);
	}
	else
	{
		double x = fabs(a.real());
		double y = fabs(a.image());
		double w;

		if (x >= y)
		{
			double t = y / x;
			w = sqrt(x) * sqrt(0.5 * (1.0 + sqrt(1.0 + t * t)));
		}
		else
		{
			double t = x / y;
			w = sqrt(y) * sqrt(0.5 * (t + sqrt(1.0 + t * t)));
		}

		if (a.real() >= 0.0)
		{
			double ai = a.image();
			z.set(w, ai / (2.0 * w));
		}
		else
		{
			double ai = a.image();
			double vi = (ai >= 0) ? w : -w;
			z.set(ai / (2.0 * vi), vi);
		}
	}

	return z;
}

CComplex exp(const CComplex& a)
{
	double rho = exp(a.real());
	double theta = a.image();

	CComplex z(rho * cos(theta), rho * sin(theta));
	return z;
}

CComplex pow(const CComplex& a, const CComplex& b)
{                               /* z=a^b */
	CComplex z;

	if (a.real() == 0 && a.image() == 0.0)
	{
		if (b.real() == 0 && b.image() == 0.0)
		{
			z.set(1.0, 0.0);
		}
		else
		{
			z.set(0.0, 0.0);
		}
	}
	else if (b.real() == 1.0 && b.image() == 0.0)
	{
		return a;
	}
	else if (b.real() == -1.0 && b.image() == 0.0)
	{
		return a.inverse();
	}
	else
	{
		double logr = a.logabs();
		double theta = a.arg();

		double br = b.real(), bi = b.image();

		double rho = exp(logr * br - bi * theta);
		double beta = theta * br + bi * logr;

		z.set(rho * cos(beta), rho * sin(beta));
	}

	return z;
}

CComplex pow(const CComplex &a, double b)
{                               /* z=a^b */
	CComplex z;

	if (a.real() == 0 && a.image() == 0)
	{
		if (b == 0)
		{
			z.set(1, 0);
		}
		else
		{
			z.set(0, 0);
		}
	}
	else
	{
		double logr = a.logabs();
		double theta = a.arg();
		double rho = exp(logr * b);
		double beta = theta * b;
		z.set(rho * cos(beta), rho * sin(beta));
	}

	return z;
}

CComplex log(const CComplex &a)
{                               /* z=log(a) */
	double logr = a.logabs();
	double theta = a.arg();

	CComplex z(logr, theta);
	return z;
}

CComplex log10(const CComplex &a)
{                               /* z = log10(a) */
	return log(a) / log(10.0);
}

CComplex log(const CComplex &a, const CComplex &b)
{
	return log(a) / log(b);
}

CComplex sin(const CComplex& a)
{                               /* z = sin(a) */
	double R = a.real(), I = a.image();
	CComplex z;

	if (I == 0.0)
	{
		/* avoid returing negative zero (-0.0) for the imaginary part  */

		z.set(sin(R), 0.0);
	}
	else
	{
		z.set(sin(R) * cosh(I), cos(R) * sinh(I));
	}

	return z;
}


CComplex cos(const CComplex& a)
{
	double R = a.real(), I = a.image();
	CComplex z;

	if (I == 0.0)
	{
		/* avoid returing negative zero (-0.0) for the imaginary part  */

		z.set(cos(R), 0.0);
	}
	else
	{
		z.set(cos(R) * cosh(I), sin(R) * sinh(-I));
	}

	return z;
}

CComplex tan(const CComplex& a)
{
	double R = a.real(), I = a.image();
	CComplex z;

	if (fabs(I) < 1)
	{
		double D = pow(cos(R), 2.0) + pow(sinh(I), 2.0);

		z.set(0.5 * sin(2 * R) / D, 0.5 * sinh(2 * I) / D);
	}
	else
	{
		double u = exp(-I);
		double C = 2 * u / (1 - pow(u, 2.0));
		double D = 1 + pow(cos(R), 2.0) * pow(C, 2.0);

		double S = pow(C, 2.0);
		double T = 1.0 / tanh(I);

		z.set(0.5 * sin(2 * R) * S / D, T / D);
	}

	return z;
}

CComplex cot(const CComplex& a)
{                               /* z = cot(a) */
	CComplex z = tan(a);
	return z.inverse();
}

CComplex sec(const CComplex& a)
{
	CComplex z = cos(a);
	return z.inverse();
}

CComplex csc(const CComplex& a)
{
	CComplex z = sin(a);
	return z.inverse();
}
/*
CComplex arcsin_real(double a)
{                               
	CComplex z;

	if (fabs(a) <= 1.0)
	{
		z.set(asin(a), 0.0);
	}
	else
	{
		if (a < 0.0)
		{
			z.set(-M_PI_2, acosh(-a));
		}
		else
		{
			z.set(M_PI_2, -acosh(a));
		}
	}

	return z;
}*/

CComplex arcsin(const CComplex& a)
{                               /* z = arcsin(a) */
	double R = a.real(), I = a.image();
	CComplex z;

	if (I == 0)
	{
		z = arcsin(R);
	}
	else
	{
		double x = fabs(R), y = fabs(I);
		double r = hypot(x + 1, y), s = hypot(x - 1, y);
		double A = 0.5 * (r + s);
		double B = x / A;
		double y2 = y * y;

		double real, imag;

		const double A_crossover = 1.5, B_crossover = 0.6417;

		if (B <= B_crossover)
		{
			real = asin(B);
		}
		else
		{
			if (x <= 1)
			{
				double D = 0.5 * (A + x) * (y2 / (r + x + 1) + (s + (1 - x)));
				real = atan(x / sqrt(D));
			}
			else
			{
				double Apx = A + x;
				double D = 0.5 * (Apx / (r + x + 1) + Apx / (s + (x - 1)));
				real = atan(x / (y * sqrt(D)));
			}
		}

		if (A <= A_crossover)
		{
			double Am1;

			if (x < 1)
			{
				Am1 = 0.5 * (y2 / (r + (x + 1)) + y2 / (s + (1 - x)));
			}
			else
			{
				Am1 = 0.5 * (y2 / (r + (x + 1)) + (s + (x - 1)));
			}

			imag = log1p(Am1 + sqrt(Am1 * (A + 1)));
		}
		else
		{
			imag = log(A + sqrt(A * A - 1));
		}

		z.set((R >= 0) ? real : -real, (I >= 0) ? imag : -imag);
	}

	return z;
}
/*
CComplex arccos(const CComplex& a)
{                             
	double R = a.real(), I = a.image();
	CComplex z;

	if (I == 0)
	{
		z = arccos(R);
	}
	else
	{
		double x = fabs(R), y = fabs(I);
		double r = hypot(x + 1, y), s = hypot(x - 1, y);
		double A = 0.5 * (r + s);
		double B = x / A;
		double y2 = y * y;

		double real, imag;

		const double A_crossover = 1.5, B_crossover = 0.6417;

		if (B <= B_crossover)
		{
			real = acos(B);
		}
		else
		{
			if (x <= 1)
			{
				double D = 0.5 * (A + x) * (y2 / (r + x + 1) + (s + (1 - x)));
				real = atan(sqrt(D) / x);
			}
			else
			{
				double Apx = A + x;
				double D = 0.5 * (Apx / (r + x + 1) + Apx / (s + (x - 1)));
				real = atan((y * sqrt(D)) / x);
			}
		}

		if (A <= A_crossover)
		{
			double Am1;

			if (x < 1)
			{
				Am1 = 0.5 * (y2 / (r + (x + 1)) + y2 / (s + (1 - x)));
			}
			else
			{
				Am1 = 0.5 * (y2 / (r + (x + 1)) + (s + (x - 1)));
			}

			imag = log1p(Am1 + sqrt(Am1 * (A + 1)));
		}
		else
		{
			imag = log(A + sqrt(A * A - 1));
		}

		z.set((R >= 0) ? real : M_PI - real, (I >= 0) ? -imag : imag);
	}

	return z;
}

CComplex arccos_real(double a)
{                              
	CComplex z;

	if (fabs(a) <= 1.0)
	{
		z.set(acos(a), 0);
	}
	else
	{
		if (a < 0.0)
		{
			z.set(M_PI, -acosh(-a));
		}
		else
		{
			z.set(0, acosh(a));
		}
	}

	return z;
}*/
/*
CComplex arctan(const CComplex& a)
{                              
	double R = a.real(), I = a.image();
	CComplex z;

	if (I == 0)
	{
		z.set(atan(R), 0);
	}
	else
	{


		double r = hypot(R, I);

		double imag;

		double u = 2 * I / (1 + r * r);

		if (fabs(u) < 0.1)
		{
			imag = 0.25 * (log1p(u) - log1p(-u));
		}
		else
		{
			double A = hypot(R, I + 1);
			double B = hypot(R, I - 1);
			imag = 0.5 * log(A / B);
		}

		if (R == 0)
		{
			if (I > 1)
			{
				z.set(M_PI_2, imag);
			}
			else if (I < -1)
			{
				z.set(-M_PI_2, imag);
			}
			else
			{
				z.set(0, imag);
			};
		}
		else
		{
			z.set(0.5 * atan2(2 * R, ((1 + r) * (1 - r))), imag);
		}
	}

	return z;
}

CComplex arcsec(const CComplex& a)
{                              
	CComplex z = a.inverse();
	return arccos(z);
}

CComplex arcsec_real(double a)
{                              
	CComplex z;

	if (a <= -1.0 || a >= 1.0)
	{
		z.set(acos(1 / a), 0.0);
	}
	else
	{
		if (a >= 0.0)
		{
			z.set(0, acosh(1 / a));
		}
		else
		{
			z.set(M_PI, -acosh(-1 / a));
		}
	}

	return z;
}*/

CComplex arccsc(const CComplex& a)
{                              
	CComplex z = a.inverse();
	return arcsin(z);
}
/*
CComplex arccsc_real(double a)
{                              
	CComplex z;

	if (a <= -1.0 || a >= 1.0)
	{
		z.set(asin(1 / a), 0.0);
	}
	else
	{
		if (a >= 0.0)
		{
			z.set(M_PI_2, -acosh(1 / a));
		}
		else
		{
			z.set(-M_PI_2, acosh(-1 / a));
		}
	}

	return z;
}

CComplex arccot(const CComplex& a)
{                               
	CComplex z;
	if (a.real() == 0.0 && a.image() == 0.0)
	{
		z.set(M_PI_2, 0);
	}
	else
	{
		z = a.inverse();
		z = arctan(z);
	}

	return z;
}*/

CComplex sinh(const CComplex& a)
{                               /* z = sinh(a) */
	double R = a.real(), I = a.image();

	CComplex z;
	z.set(sinh(R) * cos(I), cosh(R) * sin(I));
	return z;
}

CComplex cosh(const CComplex& a)
{                               /* z = cosh(a) */
	double R = a.real(), I = a.image();

	CComplex z;
	z.set(cosh(R) * cos(I), sinh(R) * sin(I));
	return z;
}

CComplex tanh(const CComplex& a)
{                               /* z = tanh(a) */
	double R = a.real(), I = a.image();

	CComplex z;

	if (fabs(R) < 1.0)
	{
		double D = pow(cos(I), 2.0) + pow(sinh(R), 2.0);

		z.set(sinh(R) * cosh(R) / D, 0.5 * sin(2 * I) / D);
	}
	else
	{
		double D = pow(cos(I), 2.0) + pow(sinh(R), 2.0);
		double F = 1 + pow(cos(I) / sinh(R), 2.0);

		z.set(1.0 / (tanh(R) * F), 0.5 * sin(2 * I) / D);
	}

	return z;
}

CComplex sech(const CComplex& a)
{                               /* z = sech(a) */
	CComplex z = cosh(a);
	return z.inverse();
}

CComplex csch(const CComplex& a)
{                               /* z = csch(a) */
	CComplex z = sinh(a);
	return z.inverse();
}

CComplex coth(const CComplex& a)
{                               /* z = coth(a) */
	CComplex z = tanh(a);
	return z.inverse();
}

/**********************************************************************
* Inverse CComplex Hyperbolic Functions
**********************************************************************/
/*
CComplex arcsinh(const CComplex& a)
{                               
	CComplex z = a * CComplex(0, 1.0);
	z = arcsin(z);
	z *= CComplex(0, -1);
	return z;
}

CComplex arccosh(const CComplex& a)
{                               
	CComplex z = arccos(a);
	if (z.image() > 0)
	{
		z *= CComplex(0, -1);
	}
	else
	{
		z *= CComplex(0, 1);
	}
	return z;
}*/
/*
CComplex arccosh(double a)
{                          
	CComplex z;

	if (a >= 1)
	{
		z.set(acosh(a), 0);
	}
	else
	{
		if (a >= -1.0)
		{
			z.set(0, acos(a));
		}
		else
		{
			z.set(acosh(-a), M_PI);
		}
	}

	return z;
}*/
/*
CComplex arctanh(const CComplex& a)
{                               
	if (a.image() == 0.0)
	{
		return arctanh(a.real());
	}
	else
	{
		CComplex z = a * CComplex(0, 1.0);
		z = arctan(z);
		z = z * CComplex(0, -1.0);
		return z;
	}
}*/
/*
CComplex arctanh_real(double a)
{                               
	CComplex z;

	if (a > -1.0 && a < 1.0)
	{
		z.set(atanh(a), 0);
	}
	else
	{
		z.set(atanh(1 / a), (a < 0) ? M_PI_2 : -M_PI_2);
	}

	return z;
}*/
/*
CComplex arcsech(const CComplex& a)
{                              
	CComplex t = a.inverse();
	return arccosh(t);
}

CComplex arccsch(const CComplex& a)
{                              
	CComplex t = a.inverse();
	return arcsinh(t);
}

CComplex arccoth(const CComplex& a)
{                               
	CComplex t = a.inverse();
	return arctanh(t);
}*/

