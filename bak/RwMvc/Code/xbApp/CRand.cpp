#include "CRand.h"

std::default_random_engine glseed(time(NULL));

CRand::CRand(double va, double vb, Enum_Distribution vtype){
	switch (vtype)
	{
	case Real_Dis:
		if (va < vb)
		{
			pRandreal = new std::uniform_real_distribution<double>(va, vb);
			RandType = Real_Dis;
		}
		else
			RandType = Const_Dis;
		break;
	case Norm_Dis:
		if (vb>0)
		{
			pRandnormal = new std::normal_distribution<double>(va, vb);
			RandType = Norm_Dis;
		}
		if (vb == 0)
			RandType = Const_Dis;
		break;
	}
	buf = va;
};


double CRand::getVal(){
	switch (RandType)
	{
	case Real_Dis:
		return (*pRandreal)(glseed);
	case Norm_Dis:
		return (*pRandnormal)(glseed);
	case Const_Dis:
		return buf;
	}
	return 0;
}
CRand::~CRand()
{
	switch (RandType)
	{
	case Real_Dis:
		delete pRandreal;
		break;
	case Norm_Dis:
		delete pRandnormal;
		break;
	}
};