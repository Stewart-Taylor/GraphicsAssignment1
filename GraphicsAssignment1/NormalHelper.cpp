#include "NormalHelper.h"

#include <math.h>
#include <stdlib.h>


NormalHelper::NormalHelper(void)
{
}


NormalHelper::~NormalHelper(void)
{
}


void NormalHelper::getFaceNormal(GLfloat *norm,GLfloat pointa[3],GLfloat pointb[3],GLfloat pointc[3])
{
		float vect[2][3];
	int a,b;
	float point[3][3];

	for (a=0;a<3;++a)
	{
		point[0][a]=pointa[a];						//copies points into point[][]
		point[1][a]=pointb[a]; 
		point[2][a]=pointc[a];
	}

	for (a=0;a<2;++a)									//calculates vectors from point[0] to point[1]
	{														//and point[0] to point[2]
		for (b=0;b<3;++b)
		{
			vect[a][b]=point[2-a][b]-point[0][b];			
		}
	}

	crossProduct(norm,vect[0],vect[1]);			//calculates vector at 90° to to 2 vectors
	normalize(norm);	

}

void NormalHelper::normalize(GLfloat * vect)	//scales a vector a length of 1
{
	float length;
	int a;

	length=sqrt(					//A^2 + B^2 + C^2 = length^2
				pow(vect[0],2)+	
				pow(vect[1],2)+
				pow(vect[2],2)
				);

	for (a=0;a<3;++a)				//divides vector by its length to normalise
	{
		vect[a]/=length;
	}
}

void NormalHelper::crossProduct(GLfloat *c,GLfloat a[3], GLfloat b[3])		//finds the cross product of two vectors
{															
	c[0]=a[1]*b[2] - b[1]*a[2];
	c[1]=a[2]*b[0] - b[2]*a[0];
	c[2]=a[0]*b[1] - b[0]*a[1];
}