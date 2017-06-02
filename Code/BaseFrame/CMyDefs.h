#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

#define Epsilon 0.00001

//‘≤÷‹¬ 
#define PI 3.141592653589793
#define M_PI 3.14159265358979323846


/////////////////////////////////////
enum Enum_appState
{
	app_Start = 0,
	app_Logon   ,
	app_Waiting ,
	app_New  ,
	app_Open ,
	app_Edit, 
	app_Close,
	app_Exit,
	app_Closing
};



