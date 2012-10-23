#include <freeglut.h>
#pragma once
class Gear
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
	Gear();
	Gear(float x , float y , float z );
	~Gear(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void update();
};

