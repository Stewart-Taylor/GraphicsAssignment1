#include <freeglut.h>

#pragma once
class Sun
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
	Sun();
	Sun(float x , float y , float z );
	~Sun(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void update();
};

