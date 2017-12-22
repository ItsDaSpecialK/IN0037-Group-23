#include "SphereSystemSimulator.h"
#include "util/timer.h"
#include "SphereSystemNaive.h"
#include "SphereSystemGrid.h"

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
                                                m_iAccelerator(NAIVEACC), m_pSphereSystem(nullptr),
                                                m_pSphereSystemGrid(nullptr),m_gravityScale(1)
{
}

const char* SphereSystemSimulator::getTestCasesStr()
{
	return "Demo 1, Demo 2, Demo 3 - Accuracy";
}

void SphereSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	this->DUC = DUC;
	TwAddButton(DUC->g_pTweakBar, "Run Perf Tests", [](void * s) {runDemo3Performance();}, nullptr, "");
	TwType TW_TYPE_KERNEL = TwDefineEnumFromString("Kernel", "Constant, Linear, Quadratic, Electric Weak, Electric Charge");
	//Then, we create the listbox, the changed value will be directly written into the variable 'm_iIntegrator'
	TwAddVarRW(DUC->g_pTweakBar, "Kernel", TW_TYPE_KERNEL, &m_iKernel, "");
	TwAddVarRW(DUC->g_pTweakBar, "Gravity scale", TW_TYPE_FLOAT, &m_gravityScale, "");
	//TODO: add other user configuration: number of spheres, radius, mass..
}

void SphereSystemSimulator::reset()
{
	notifyCaseChanged(m_currentTestCase);
}

void SphereSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
	m_pSphereSystem->drawFrame(DUC, pd3dImmediateContext);
	if (m_pSphereSystemGrid != nullptr)
	{
		m_pSphereSystemGrid->drawFrame(DUC, pd3dImmediateContext);
		
	}
}

void SphereSystemSimulator::notifyCaseChanged(int testCase)
{
	m_currentTestCase = testCase;
	m_pSphereSystemGrid = nullptr;
	switch (testCase)
	{
	case 0:
		m_pSphereSystem = new SphereSystemNaive(m_fRadius, m_fMass);
		//TODO: Add spheres into the system...
		m_iAccelerator = NAIVEACC;
		m_pSphereSystem->addSphere(Vec3(0, 0, 0), Vec3(0, 0, 0), false, m_fMass);
		m_pSphereSystem->addSphere(Vec3(0, 1, 0), Vec3(0, 0, 0), false, m_fMass);
		break;
	case 1:
		//TODO: Add spheres into the system...
		m_pSphereSystem = new SphereSystemGrid(m_fRadius, m_fMass);
		m_iAccelerator = GRIDACC;
		break;
	case 2:
		m_pSphereSystem = new SphereSystemNaive(m_fRadius, m_fMass);
		m_pSphereSystemGrid = new SphereSystemGrid(m_fRadius, m_fMass);
		m_pSphereSystemGrid->set_color(0.6*Vec3(1, 0, 0));
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
	m_pSphereSystem->set_kernel_func(m_Kernels[m_iKernel]);
	m_pSphereSystem->simulateTimestep(timeStep);
	m_pSphereSystem->set_gravity_scale(m_gravityScale);
	if (m_pSphereSystemGrid !=nullptr)
	{
		m_pSphereSystemGrid->set_kernel_func(m_Kernels[m_iKernel]);
		m_pSphereSystemGrid->set_gravity_scale(m_gravityScale);
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
	std::cout << "Performance tests: " << std::endl;
	float radius = .5;
	float mass = 1;
	SphereSystemNaive naiveSystem(radius, mass);
	SphereSystemGrid gridSystem(radius, mass);
	MuTime timer;
	timer.get();
	std::cout << "Time passed " << timer.update().time << " milliseconds\n" << std::endl;
	//TODO: Run demo 3 performance tests.
}
