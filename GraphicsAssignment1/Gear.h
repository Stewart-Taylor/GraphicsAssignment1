#include <freeglut.h>
#pragma once
class Gear
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
	GLfloat inner_radius;
	GLfloat outer_radius;
	GLfloat width;
	GLint teeth;
	GLfloat tooth_depth;
	Gear();
	Gear(GLfloat x , GLfloat y , GLfloat z , GLfloat innerRad , GLfloat outerRad ,GLfloat widthT , GLuint teethT , GLfloat depthT );
	~Gear(void);
	void display(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
	void spin(GLfloat speed);
};

