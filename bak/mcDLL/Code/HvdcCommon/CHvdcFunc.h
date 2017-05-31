#pragma once

#include <stdarg.h>
#include <string>
#include <vector>

#include "CHvdcDefs.h"

using namespace std;

class CHvdcFunc
{
	CHvdcFunc() {};
	virtual ~CHvdcFunc() {};
	CHvdcFunc(const CHvdcFunc& vFunc) {};

public:

	static double R2D(double rad) { return rad / M_PI * 180; }
	static double D2R(double degree) { return degree / 180 * M_PI; }


	static void print(FILE* foutFile, const char* fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);//��apָ��fmt��ĵ�һ������
						  //vprintf(fmt, ap);
		vfprintf(foutFile, fmt, ap);
		va_end(ap);//��ap��ΪNULL
	}

};
