#include "SpaceWall.h"


//#include "NormalHelper.h"

#include <windows.h>		// Header File For Windows
#include <stdio.h>	
#include <stdlib.h>
#include <freeglut.h>
#include <glaux.h>

#include <math.h>


#define auxDIBImageLoad auxDIBImageLoadW




SpaceWall::SpaceWall()
{

}

SpaceWall::SpaceWall(float x , float y , float z , float scaleT)
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 0;
	yAngle = 0;
	zAngle = 0;
	xAngleTexture = 0;
		yAngleTexture = 0;
		zAngleTexture = 0;
	scale = scaleT;

	texName = 0;


	   AUX_RGBImageRec *texture[1];


   char* Filename = "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\space2.bmp";

   	FILE *File=NULL;									// File Handle

	if (!Filename)										// Make Sure A Filename Was Given
	{
		//return NULL;		
							// If Not Return NULL
	}

	File=fopen(Filename,"r");							// Check To See If The File Exists

	if (File)											// Does The File Exist?
	{
		fclose(File);	
		texture[0] = auxDIBImageLoadA(Filename);				// Load The Bitmap And Return A Pointer
	}

	

  // texture[0] = auxDIBImageLoad("test.bmp");
/*  This uses the auxDIBImageLoad function from the glaux library. 
 *  To make glaux library available, go to Project -> Properties
 *  Choose Linker -> Input, and enter glaux.lib under "Additional dependencies" */

   /* Sets the pixel storage mode to unpack pixels in byte aligned mode */
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   /* provides unused texture identifier names */
   glGenTextures(1, &texName);

   /* Binds "texName" as a 2D texture and activates texture */
   glBindTexture(GL_TEXTURE_2D, texName);

   /* Controls texture wrapping */
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

   /* Defines a 2-dimensional texture */
   glTexImage2D(GL_TEXTURE_2D, 0, 3, texture[0]->sizeX,  texture[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture[0]->data);
  // glClearColor (0.0, 0.0, 0.0, 0.0);
 //  glEnable(GL_DEPTH_TEST);

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

			glMatrixMode(GL_TEXTURE);
			   glRotatef(xAngleTexture, 0.0, 0, 1.0);
 //  glRotatef(yangle, 0.0, 1.0, 0);
 //  glRotatef(zangle, 0.0, 0, 1.0);
      glMatrixMode(GL_MODELVIEW);
			   



   
	glTranslated(xPosition ,yPosition ,zPosition);
	

	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);

		glScaled(30.0 ,30.0 ,30.0);


	

	glColor3f( 1.0, 1.0, 0.0 );
	glBegin(GL_POLYGON);
 
	glTexCoord2f(-0.5, -0.5);	glVertex3f( -0.5, -0.5, -0.5);       // P1
	glTexCoord2f(-0.5,  0.5);	glVertex3f( -0.5,  0.5, -0.5);       // P2
	glTexCoord2f(0.5,  0.5);	glVertex3f(  0.5,  0.5, -0.5);       // P3
	glTexCoord2f(0.5, -0.5);	glVertex3f(  0.5, -0.5, -0.5);       // P4
 
glEnd();

   glPopMatrix();

   glDisable(GL_TEXTURE_2D);

}


void SpaceWall::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;


}

void SpaceWall::update()
{
	xAngleTexture += 0.0000001f;


}
