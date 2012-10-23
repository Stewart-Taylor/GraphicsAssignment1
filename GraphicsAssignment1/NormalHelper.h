#pragma once

#include <freeglut.h>
class NormalHelper
{
public:
	NormalHelper(void);
	~NormalHelper(void);
	void calculateSurfaceNormal(void);
	static void getFaceNormal(GLfloat *norm,GLfloat pointa[3],GLfloat pointb[3],GLfloat pointc[3]);
	static void normalize(GLfloat * vect);  // Move to private
	static void crossProduct(GLfloat *c,GLfloat a[3], GLfloat b[3]);
};

