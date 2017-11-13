#ifndef DEMO5_H
#define DEMO5_H

#pragma once
#include "DemoScene.h"

class Demo5: DemoScene
{
public:
	void init() override;
	void stepPerformedCallback() override;
};

#endif // DEMO5_H
