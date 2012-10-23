#include "EarthComponent.h"
#include "Earth.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

EarthComponent::EarthComponent(void)
{

}

EarthComponent::~EarthComponent(void)
{
}

void EarthComponent::setUp(void)
{
		Earth earth = Earth(10 ,3 ,0); // CHANGE
}

void EarthComponent::display(void)
{
	earth.display();

}

void EarthComponent::update(void)
{
	earth.update();

}