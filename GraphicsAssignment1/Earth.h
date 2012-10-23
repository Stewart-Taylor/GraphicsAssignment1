#include <freeglut.h>
#pragma once
class Earth
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
	Earth();
	Earth(float x , float y , float z );
	~Earth(void);
	void display(void);
	void setAngle(float xAngleT , float yAngleT , float zAngleT);
	void setPosition(float xPositionT , float yPositionT , float zPositionT);
	void spin();
};
