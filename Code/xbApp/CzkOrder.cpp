
#include "CzkOrder.h"
#include "CHvdcDefs.h"

void CzkOrder::Init()
{
	CxbOrder::Init();

	FreStart = 10;

	FreStep = 10;

	FreDim = 300;

	ScanPort = 0;

	ScanPortPole = 0;
}

string CzkOrder::GetPortName(int i)
{
	string Pole = "";
	if (ScanPortPole == xb_Pos)
		Pole = "Pos";
	if (ScanPortPole == xb_Neg)
		Pole = "Neg";

	if (i = 0)
		return ScanPortStation + "---" + Pole + "ValveTerm";

	if(i=1)
		return ScanPortStation + "---" + Pole + "ValveGnd";

	return "";
}
