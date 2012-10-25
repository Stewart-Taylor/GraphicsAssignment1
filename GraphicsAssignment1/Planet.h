#include <freeglut.h>
#pragma once
class Planet
{
public:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat scale;
	Planet();
	Planet(GLfloat x , GLfloat y , GLfloat z , char* path );
	~Planet(void);
	void display(void);
	void displayShadow(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
	void setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT);
private:
	GLfloat time;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	GLuint texName;
};
