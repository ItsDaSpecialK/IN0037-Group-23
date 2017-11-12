#include "Spring.h"

Spring::Spring(int masspoint1, int masspoint2, float initialLength, float stiffness):
	point1(masspoint1), point2(masspoint2), initialLength( initialLength), stifness(stiffness)
{
}
