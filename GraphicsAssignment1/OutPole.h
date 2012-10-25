#include <freeglut.h>
#pragma once
class OutPole
{
public:
	GLfloat yAngle;
	OutPole();
	OutPole(GLfloat x , GLfloat y , GLfloat z , GLfloat radius , GLfloat length , GLuint slices );
	~OutPole(void);
	void display(void);
	void displayShadow(void);
	void setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT);
	void setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT);
	void setOriginPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT  );
private:
	GLfloat xPosition;
	GLfloat yPosition;
	GLfloat zPosition;
	GLfloat xAngle;
	GLfloat zAngle;
	GLfloat scale;
	GLuint texName;
	GLuint slices;
	GLfloat radius;
	GLfloat length;
	GLfloat originPosX;
	GLfloat originPosY;
	GLfloat originPosZ;

};