#include "Sun.h"

#pragma once
class Cylinder
{
public:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	GLfloat scale;
	GLuint texName;
	Cylinder();
	Cylinder(float x , float y , float z );
	~Cylinder(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void update();
};

