#pragma once
#include "SphereSystem.h"

class SphereSystemGrid: public SphereSystem
{
public:
	SphereSystemGrid(float radius, float mass, float box_size, int cells_per_side)
		: SphereSystem(radius, mass, box_size), cells_per_side_(cells_per_side)
	{
		//TODO: Init the data structure
	}

	void computeCollisionForces() override;
	void computeCollisionForcesTmp() override;
private:
	int cells_per_side_;
};
