#pragma once


#include <string>
#include <comutil.h>

#include "CMyDefs.h"

using namespace std;


class CMyFunc
{

protected:
	CMyFunc();
	virtual ~CMyFunc();
	CMyFunc(const CMyFunc& theCMyFunc);

public:
	static string CreateObjID();

	static string GetString(string vX);
	static string GetString(int vX, const char* vfmt = "%f");
	static string GetString(double vX, const char * vfmt = "%f");
	static string VarToStr(_variant_t & vVar);

	static double R2D(double rad) { return rad / M_PI * 180; }
	static double D2R(double degree) { return degree / 180 * M_PI; }

};

