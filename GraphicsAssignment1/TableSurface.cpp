/*		TableSurface CLASS
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * Generates a white plane with graident and surface normals.
 * 
 * Last Updated: 24/10/2012
*/

#include "TableSurface.h"

#include <stdio.h>	
#include <freeglut.h>

TableSurface::TableSurface(void)
{
	xPosition = 0;
	yPosition = 0;
	zPosition = 0;
	xAngle = -90;
	yAngle = 0;
	zAngle = 0;
	scale = 120;
}


TableSurface::~TableSurface(void)
{
}


void TableSurface::display(void)
{
	glPushMatrix(); 

	glMatrixMode(GL_MODELVIEW);

	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glScaled(scale ,scale ,scale);
			   
	glBegin(GL_POLYGON);
	glNormal3f(0.0 , 1.0 , 0.0);
	glColor3f( 1.0, 1.0, 1.0 );		glVertex3f(  0.5, -0.5, 0.0 );      
	glColor3f( 0.5, 0.5, 0.5 );		glVertex3f(  0.5,  0.5, 0.0 );     
	glColor3f( 0.0, 0.0, 0.0 );		glVertex3f( -0.5,  0.5, 0.0 );      
	glColor3f( 0.5, 0.5, 0.5 );		glVertex3f( -0.5, -0.5, 0.0 );      
	glEnd();

	glPopMatrix();
}
