#ifndef DEMO3_H
#define DEMO3_H


#include "DemoScene.h"

class Demo3 : public DemoScene
{
public:

	explicit Demo3(MassSpringSystemSimulator& simulator)
		: DemoScene(simulator)
	{
	}

	void init() override;
	void stepPerformedCallback() override;
};


#endif // DEMO3_H