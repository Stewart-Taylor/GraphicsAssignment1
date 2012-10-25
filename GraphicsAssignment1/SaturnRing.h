#include <freeglut.h>

#pragma once
class SaturnRing
{
public:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	SaturnRing();
	SaturnRing(GLfloat x , GLfloat y , GLfloat z , GLfloat radius , GLfloat length , GLuint slices );
	~SaturnRing(void);
	void display(void);
	void displayShadow(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
	void setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT);
private:
	GLfloat scale;
	GLuint texName;
	GLuint slices;
	GLfloat radius;
	GLfloat length;
};

