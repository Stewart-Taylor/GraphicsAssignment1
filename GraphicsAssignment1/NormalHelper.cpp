/*		Surface Normal Helper
 *	AUTHOR: STEWART TAYLOR
 *	DATE STARTED: 20/10/2012
 *------------------------------------
 * This class is used to help calculate surface normals. 
 * It uses the cross product.
 *
 * Last Updated: 22/10/2012
*/

#include "NormalHelper.h"

#include <math.h>
#include <stdlib.h>


NormalHelper::NormalHelper(void)
{
}


NormalHelper::~NormalHelper(void)
{
}


void NormalHelper::getSurfaceNormal(GLfloat *normalVector,GLfloat vertexA[3],GLfloat vertexB[3],GLfloat vertexC[3])
{
	GLfloat vectorTemp[2][3];
	GLuint a;
	GLuint b;
	GLfloat vertexTemp[3][3];

	for (a=0;a<3;++a)
	{
		vertexTemp[0][a]=vertexA[a];
		vertexTemp[1][a]=vertexB[a]; 
		vertexTemp[2][a]=vertexC[a];
	}

	for (a=0; a<2; ++a)								
	{													
		for (b=0; b<3; ++b)
		{
			vectorTemp[a][b]=vertexTemp[2-a][b]-vertexTemp[0][b];			
		}
	}

	crossProduct(normalVector,vectorTemp[0],vectorTemp[1]);	
	normalize(normalVector);	

}

void NormalHelper::normalize(GLfloat * vector)
{
	GLfloat length;
	GLuint a;

	length=sqrt(pow(vector[0],2) + pow(vector[1],2) + pow(vector[2],2));

	for (a=0;a<3;++a)// Divide by it's length to normalize
	{
		vector[a]/=length;
	}
}

void NormalHelper::crossProduct(GLfloat *c,GLfloat a[3], GLfloat b[3])
{															
	c[0]=a[1]*b[2] - b[1]*a[2];
	c[1]=a[2]*b[0] - b[2]*a[0];
	c[2]=a[0]*b[1] - b[0]*a[1];
}