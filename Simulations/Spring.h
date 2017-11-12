#pragma once
#ifndef SPRING_H
#define SPRING_H

struct Spring
{
	Spring(int masspoint1, int masspoint2, float initialLength, float stiffness);
	int point1;
	int point2;
	float stifness;
	float initialLength;
};

#endif // SPRING_H

