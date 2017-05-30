
#include "C3pCalConvertor.h"

#include "C3pDevConvertor.h"

void C3pCalConvertor::Prepare()
{

}

void C3pCalConvertor::Update3pData(int vLoop)
{
	C3pDevConvertor * vDev;

	vDev = dynamic_cast<C3pDevConvertor *>(pDevice);


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

