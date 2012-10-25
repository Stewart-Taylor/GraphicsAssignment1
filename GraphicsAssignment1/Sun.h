#include <freeglut.h>

#pragma once
class Sun
{
public:
	Sun();
	Sun(GLfloat x , GLfloat y , GLfloat z );
	~Sun(void);
	void display(void);
	void displayShadow(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
	void update();
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

