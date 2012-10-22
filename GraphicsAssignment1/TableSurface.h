#include <freeglut.h>
#pragma once
class TableSurface
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
	TableSurface();
	TableSurface(float x , float y , float z );
	~TableSurface(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
};

