#pragma once

#include "CxbCalOneDot.h"

class CxbCalShunt : public CxbCalOneDot
{
public:
	void UpdateY()  override;
	void SolveI()  override;

};
