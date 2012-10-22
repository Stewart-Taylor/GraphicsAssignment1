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
float scale;
	SpaceWall();
	SpaceWall(float x , float y , float z , float scaleT);
	~SpaceWall(void);
	void display(void);
void setAngle(float xAngleT , float yAngleT , float zAngleT);
void update();
GLuint texName;

};

