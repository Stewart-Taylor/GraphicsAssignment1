#include <freeglut.h>
#pragma once
class Box
{
public:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat yAngle;
	GLfloat zAngle;
	GLfloat width;
	GLfloat height;
	GLfloat length;
	GLuint texName;
	Box();
	Box(float x , float y , float z , float widthT , float heightT , float lengthT );
	~Box(void);
	void display(void);
	void displayShadow(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void update();
};

