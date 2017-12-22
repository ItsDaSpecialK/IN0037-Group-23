#pragma once
#include "SphereSystem.h"

class SphereSystemGrid: public SphereSystem
{
public:
	SphereSystemGrid(float radius, float mass)
		: SphereSystem(radius, mass)
	{
		//TODO: Init the data structure
	}

	void computeCollisionForces() override;
	void computeCollisionForcesTmp() override;
};
