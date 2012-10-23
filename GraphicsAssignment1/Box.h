#include <freeglut.h>
#pragma once
class Box
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
	Box();
	Box(float x , float y , float z );
	~Box(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void update();
};

