#pragma once

#include <string>

using namespace std;

class CxbMain
{
public:
	static void xbCreateGrid();

	static void xbTest(int vGnd);
	static void zkTest(int vGnd);
	static void lmTest();

	static void xbCalculate(string vCalName);	
	static void zkCalculate(string vCalName);

	static void xbMain();

};
