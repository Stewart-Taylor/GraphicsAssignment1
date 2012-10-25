#include <freeglut.h>
#pragma once
class Cylinder
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
	Cylinder();
	Cylinder(GLfloat x , GLfloat y , GLfloat z , GLfloat radius , GLfloat length , GLuint slices );
	~Cylinder(void);
	void display(void);
		void displayShadow(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
	void setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT);
	void spin(GLfloat speed);
};

