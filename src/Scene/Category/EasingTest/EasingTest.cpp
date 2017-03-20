#include "EasingTest.h"

#include "EasingTestObject/EasingTestObject.h"

void EasingTest::onCreate()
{
	Instantiate(new EasingTestObject());
}
