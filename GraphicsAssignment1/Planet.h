#include <freeglut.h>
#pragma once
class Planet
{
public:
	GLfloat xPosition;
	GLfloat time;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	GLfloat scale;
	GLuint texName;
	Planet();
	Planet(float x , float y , float z , char* path );
	~Planet(void);
	void display(void);
	void displayShadow(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void setPosition(float xPositionT , float yPositionT , float zPositionT);
	void spin();
};
