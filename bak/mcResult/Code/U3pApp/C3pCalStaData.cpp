///////////////////////////////////////////////////////////
//  C3pCalStaData.cpp
//  Implementation of the Class C3pCalStaData
//  Created on:      26-5ÔÂ-2017 15:40:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pCalStaData.h"
#include "C3pDevStaData.h"

void C3pCalStaData::Update3pData(int vLoop)
{
	C3pDevStaData * vDev;

	vDev = dynamic_cast<C3pDevStaData *>(pDevice);

	int vStaIndex = StationIndex;

	int vDim = p3pProfile->n6pValor;

	for (int i = 0; i < vDim; i++)
	{
		if (p3pProfile->pU3pData[i].StaIndex == vStaIndex)
		{

		}

	}
}