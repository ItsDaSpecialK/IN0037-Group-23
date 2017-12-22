#pragma once
#include "SphereSystem.h"

class SphereSystemNaive: public SphereSystem
{
public:
	SphereSystemNaive(float radius, float mass)
		: SphereSystem(radius, mass)
	{
	}

	void computeCollisionForces() override;
	void computeCollisionForcesTmp() override;
};
