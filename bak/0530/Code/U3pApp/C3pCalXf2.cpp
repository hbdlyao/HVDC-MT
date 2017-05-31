
#include "C3pCalXf2.h"
#include "C3pDevXf2.h"

void C3pCalXf2::Prepare()
{
}


void C3pCalXf2::Update3pData(int vLoop)
{
	C3pDevXf2 * vDev;

	vDev = dynamic_cast<C3pDevXf2 *>(pDevice);


	int vStaIndex = StationIndex;
	int vValvoerIndex = vDev->GetPosOrNeg();

	int vDim = p3pProfile->n6pValor;

	for (int i = 0; i < vDim; i++)
	{
		if ((p3pProfile->pU3pData[i].StaIndex == vStaIndex) && (p3pProfile->pU3pData[i].ValvorIndex == vValvoerIndex))
		{

		}

	}
}
