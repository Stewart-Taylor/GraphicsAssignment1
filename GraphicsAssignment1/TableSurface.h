#include <freeglut.h>

#pragma once
class TableSurface
{
public:
	TableSurface(void);
	~TableSurface(void);
	void display(void);
private:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	GLfloat scale;
	GLuint texName;
};

