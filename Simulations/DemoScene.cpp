#include "DemoScene.h"
#include "MassSpringSystemSimulator.h"

void DemoScene::print_points_info()
{
	size_t i = 0;
	for (Point & p : simulator.getPoints())
	{
		std::cout << "The point " << ++i << ":" << std::endl;
		std::cout << "Position " << p.position << std::endl;
		std::cout << "Velocity " << p.velocity << std::endl;
	}
}
