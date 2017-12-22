#include "SphereSystemNaive.h"

void SphereSystemNaive::computeCollisionForces()
{
	//Computes the forces based on collisions
	for (size_t i = 0; i < spheres.size(); i++)
	{
		Point & point = spheres[i];
		for (size_t j = i + 1; j < spheres.size(); j++)
		{
			Point& point2 = spheres[j];
			Vec3 p2ToP1 = point.position - point2.position;
			float dist = norm(p2ToP1);
			if (dist < radius_ * 2)
			{
				p2ToP1 = p2ToP1 / dist;
				float force_magnitude = kernelFunc_(dist);
				point.force += p2ToP1* force_magnitude * FORCE_LAMBDA;
				point2.force += -p2ToP1 * force_magnitude * FORCE_LAMBDA;
			}
		}
	}
}

void SphereSystemNaive::computeCollisionForcesTmp()
{
	//Computes the forces based on collisions in temporary locations
	for (size_t i = 0; i < spheres.size(); i++)
	{
		Point & point = spheres[i];
		for (size_t j = i + 1; j < spheres.size(); j++)
		{
			Point& point2 = spheres[j];
			Vec3 p2ToP1 = point.positionTemp - point2.positionTemp;
			float dist = norm(p2ToP1);
			if (dist < radius_ * 2)
			{
				p2ToP1 = p2ToP1 / dist;
				float force_magnitude  = kernelFunc_(dist);
				point.force += p2ToP1* force_magnitude * FORCE_LAMBDA;
				point2.force += -p2ToP1 * force_magnitude * FORCE_LAMBDA;
			}
		}
	}
}
