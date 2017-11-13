#ifndef DEMO3_H
#define DEMO3_H


#include "DemoScene.h"
#include "TwoPointsDemoScene.h"

class Demo3 : public TwoPointsDemoScene
{
public:

	explicit Demo3(MassSpringSystemSimulator& simulator)
		: TwoPointsDemoScene(simulator)
	{
	}

	void init() override;
	void stepPerformedCallback() override;
};


#endif // DEMO3_H