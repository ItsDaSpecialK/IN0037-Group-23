#include "SphereSystemSimulator.h"

std::function<float(float)> SphereSystemSimulator::m_Kernels[5] = {
	[](float x) {return 1.0f; },              // Constant, m_iKernel = 0
	[](float x) {return 1.0f - x; },          // Linear, m_iKernel = 1, as given in the exercise Sheet, x = d/2r
	[](float x) {return (1.0f - x)*(1.0f - x); }, // Quadratic, m_iKernel = 2
	[](float x) {return 1.0f / (x)-1.0f; },     // Weak Electric Charge, m_iKernel = 3
	[](float x) {return 1.0f / (x*x) - 1.0f; },   // Electric Charge, m_iKernel = 4
};

// SphereSystemSimulator member functions
SphereSystemSimulator::SphereSystemSimulator(): m_fMass(1), m_fRadius(.5), m_fForceScaling(1), m_fDamping(0),
                                                m_iNumSpheres(0), m_iKernel(0), m_currentTestCase(0),
                                                m_iAccelerator(NAIVEACC), m_pSphereSystem(nullptr), m_pSphereSystemGrid(nullptr)
{
}

const char* SphereSystemSimulator::getTestCasesStr()
{
	return "Demo 1, Demo 2, Demo 3 - Accuracy";
}

void SphereSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	TwAddButton(DUC->g_pTweakBar, "Run Perf Tests", [](void * s) {runDemo3Performance();}, nullptr, "");
}

void SphereSystemSimulator::reset()
{
	notifyCaseChanged(m_currentTestCase);
}

void SphereSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
	m_pSphereSystem->drawFrame(pd3dImmediateContext);
	if (m_pSphereSystemGrid != nullptr)
	{
		m_pSphereSystemGrid->drawFrame(pd3dImmediateContext);
		
	}
}

void SphereSystemSimulator::notifyCaseChanged(int testCase)
{
	m_currentTestCase = testCase;
	m_pSphereSystem = new SphereSystem();
	m_pSphereSystemGrid = nullptr;
	switch (testCase)
	{
	case 0:
		//TODO: Add spheres into the system...
		m_iAccelerator = NAIVEACC;
		break;
	case 1:
		//TODO: Add spheres into the system...
		m_iAccelerator = GRIDACC;
		break;
	case 2:
		m_pSphereSystemGrid = new SphereSystem();
		m_iAccelerator = NAIVEACC; // for the first system..
		//TODO: Add spheres to both systems...
		break;
	default: ;
	}
}

void SphereSystemSimulator::externalForcesCalculations(float timeElapsed)
{

}

void SphereSystemSimulator::simulateTimestep(float timeStep)
{
	m_pSphereSystem->simulateTimestep(timeStep);
	if (m_pSphereSystemGrid !=nullptr)
	{
		m_pSphereSystemGrid->simulateTimestep(timeStep);
	}
}

void SphereSystemSimulator::onClick(int x, int y)
{
}

void SphereSystemSimulator::onMouse(int x, int y)
{
}

void runDemo3Performance()
{
	std::cout << "Performance tests: ";
	SphereSystem s;
	//TODO: Run demo 3 performance tests.
}
