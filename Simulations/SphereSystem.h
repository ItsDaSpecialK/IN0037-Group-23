#ifndef SPHERESYSTEM_H
#define SPHERESYSTEM_H

#pragma once
#include "util/FFmpeg.h"

class SphereSystem
{
public:

	void simulateTimestep(float timeStep);
	void drawFrame(ID3D11DeviceContext* pd3_d_immediate_context);
	//TODO: add Vector<Sphere> spheres & create the Sphere class...
};


#endif // SPHERESYSTEM_H