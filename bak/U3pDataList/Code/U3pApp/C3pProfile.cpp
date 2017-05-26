
#include "C3pProfile.h"


void C3pProfile::InitOrder(C3pOrder * vOrder)
{
	p3pOrder = vOrder;
}


void C3pProfile::ReSetData()
{
	//¡ı≥©£∫÷ÿ÷√º∆À„ ˝æ›
}

void C3pProfile::InitData()
{

}

void C3pProfile::SolveMiu()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveMiu(vK);
}

void C3pProfile::doSolveMiu(int vK)
{
	//¡ı≥©
}

void C3pProfile::SolveU3p()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveU3p(vK);
}

void C3pProfile::doSolveU3p(int vK)
{
	//¡ı≥©
}

void C3pProfile::SolveL()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveL(vK);
}

void C3pProfile::doSolveL(int vK)
{
	//¡ı≥©
}
