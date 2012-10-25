#include <freeglut.h>

#pragma once
class SpaceWall
{
public:
	SpaceWall(void);
	~SpaceWall(void);
	void display(void);
private:
	GLfloat scale;
	GLuint texName;
};

