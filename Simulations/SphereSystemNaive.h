#pragma once
#include "SphereSystem.h"

class SphereSystemNaive: public SphereSystem
{
public:
	SphereSystemNaive(float radius, float mass, float box_size)
		: SphereSystem(radius, mass, box_size)
	{	
	}

	void computeCollisionForces() override;
	void computeCollisionForcesTmp() override;
};
