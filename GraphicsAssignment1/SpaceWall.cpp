/*		SpaceWall Class
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class is used as a skybox
 *
 * Last Updated: 22/10/2012
*/

#include "SpaceWall.h"
#include "TextureLoader.h"

#include <stdio.h>	
#include <freeglut.h>


SpaceWall::SpaceWall(void)
{
	scale = 800; // it's a good size
	texName = TextureLoader::loadTexture("Textures\\spaceTile.bmp");
}


SpaceWall::~SpaceWall(void)
{
}


void SpaceWall::display(void)
{
	glPushMatrix(); 

	glEnable(GL_TEXTURE_2D); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texName);

	glMatrixMode(GL_MODELVIEW);


	glScaled(scale ,scale ,scale);
			   
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f(  0.5, -0.5, -0.5 );      
	glTexCoord2f(1.0,  1.0);	glVertex3f(  0.5,  0.5, -0.5 );     
	glTexCoord2f(-1.0,  1.0);   glVertex3f( -0.5,  0.5, -0.5 );      
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5, -0.5, -0.5 );      
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f(  0.5, -0.5, 0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f(  0.5,  0.5, 0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5,  0.5, 0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f( 0.5, -0.5, -0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f( 0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( 0.5,  0.5,  0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f( -0.5, -0.5,  0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f( -0.5,  0.5,  0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f(  0.5,  0.5,  0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f(  0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5,  0.5,  0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f(  0.5, -0.5, -0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f(  0.5, -0.5,  0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5, -0.5,  0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

