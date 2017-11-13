#pragma once
#include "Simulator.h"

struct Point
{
public:	
	Point(Vec3 position, Vec3 velocity, float mass, bool isFixed);
	Vec3 position;
	Vec3 velocity;
	Vec3 force;
	float mass;
	float damping;
	bool is_fixed;
	//For the midpoint calculation
	Vec3 positionTemp;
	Vec3 velocityTemp;
};