#include <freeglut.h>
#pragma once
class Box
{
public:
	Box();
	Box(GLfloat x , GLfloat y , GLfloat z , GLfloat widthT , GLfloat heightT , GLfloat lengthT );
	~Box(void);
	void display(void);
	void displayShadow(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
private:
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
	GLfloat normal1[3];
	GLfloat normal2[3];
	GLfloat normal3[3];
	GLfloat normal4[3];
	GLfloat normal5[3];
	GLfloat normal6[3];
	void calculateNormals(void);
};

