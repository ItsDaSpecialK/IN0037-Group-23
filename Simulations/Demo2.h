#ifndef DEMO2_H
#define DEMO2_H
#include "DemoScene.h"

class Demo2 : public DemoScene
{
public:

	explicit Demo2(MassSpringSystemSimulator& simulator)
		: DemoScene(simulator)
	{
	}

	void init() override;
	void stepPerformedCallback() override;
};



#endif // DEMO2_H