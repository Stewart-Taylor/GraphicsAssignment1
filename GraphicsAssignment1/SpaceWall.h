#include <freeglut.h>

#pragma once
class SpaceWall
{
public:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	GLfloat xAngleTexture;
	GLfloat yAngleTexture;
	GLfloat zAngleTexture;
	GLfloat scale;
	GLuint texName;
	SpaceWall();
	SpaceWall(float x , float y , float z );
	~SpaceWall(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void update();
};

