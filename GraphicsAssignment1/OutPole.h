#include <freeglut.h>
#pragma once
class OutPole
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
	GLuint slices;
	GLfloat radius;
	GLfloat length;
	OutPole();
	OutPole(float x , float y , float z , float radius , float length , int slices );
	~OutPole(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void setPosition(float xPositionT , float yPositionT , float zPositionT);
	void spin();
};