#include "Box.h"

#include "TextureLoader.h"
#include "NormalHelper.h"
#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

Box::Box()
{

}


Box::Box(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 90;
	yAngle = 0;
	zAngle = 0;
	scale = 10;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\brass.bmp");
}


Box::~Box(void)
{
}



void Box::display(void)
{
	glPushMatrix(); 

	

	glEnable(GL_TEXTURE_2D);  // move
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texName);

	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,4.0);
			   
	   glColor3f(0.0,1.0,0.0);
   glBegin(GL_POLYGON);


               	   GLfloat normal1[3] ;
	GLfloat pointa1[3] = {0.5,0.5,0.5};
	GLfloat pointb1[3]= {-0.5,0.5,0.5};
	GLfloat pointc1[3]= {-0.5,-0.5,0.5};
	GLfloat pointd1[3]= {0.5,-0.5,0.5};
   
    //getFaceNormal(normal1, pointd1, pointc1, pointb1);

	NormalHelper::getFaceNormal(normal1, pointd1, pointc1, pointb1);

	 glNormal3f(normal1[0], normal1[1], normal1[2]);


   //  glNormal3f(0.0, 0.0, 1.0);
   glTexCoord2f(1.0, -1.0);  glVertex3f(0.5,0.5,0.5);
   glTexCoord2f(1.0,  1.0);   glVertex3f(-0.5,0.5,0.5);
   glTexCoord2f(-1.0,  1.0);  glVertex3f(-0.5,-0.5,0.5);
  glTexCoord2f(-1.0, -1.0);    glVertex3f(0.5,-0.5,0.5);
   glEnd();

   glBegin(GL_POLYGON);

   GLfloat normal2[3] ;
   GLfloat pointa2[3] = {0.5,0.5,0.5};
   GLfloat pointb2[3]= {0.5,-0.5,0.5};
   GLfloat pointc2[3]= {0.5,-0.5,-0.5};
   GLfloat pointd2[3]= {0.5,0.5,-0.5};
   
    NormalHelper::getFaceNormal(normal2, pointd2, pointc2, pointb2);

	 glNormal3f(normal2[0], normal2[1], normal2[2]);

   //  glNormal3f(1.0, 0.0, 0.0);
  glTexCoord2f(1.0, -1.0);   glVertex3f(0.5,0.5,0.5);
  glTexCoord2f(1.0,  1.0);   glVertex3f(0.5,-0.5,0.5);
   glTexCoord2f(-1.0,  1.0);   glVertex3f(0.5,-0.5,-0.5);
 glTexCoord2f(-1.0, -1.0);    glVertex3f(0.5,0.5,-0.5);
   glEnd();

   glBegin(GL_POLYGON);

      GLfloat normal3[3] ;
	  GLfloat pointa3[3] = {0.5,0.5,-0.5};
	  GLfloat pointb3[3]= {0.5,-0.5,-0.5};
	  GLfloat pointc3[3]= {-0.5,-0.5,-0.5};
	  GLfloat pointd3[3]= {-0.5,0.5,-0.5};
   
    NormalHelper::getFaceNormal(normal3, pointc3, pointb3, pointa3);

	 glNormal3f(normal3[0], normal3[1], normal3[2]);

	 
	

   //  glNormal3f(1.0, 0.0, -1.0);
   glTexCoord2f(1.0, -1.0);   glVertex3f(0.5,0.5,-0.5);
  glTexCoord2f(1.0,  1.0);    glVertex3f(0.5,-0.5,-0.5);
   glTexCoord2f(-1.0,  1.0);    glVertex3f(-0.5,-0.5,-0.5);
 glTexCoord2f(-1.0, -1.0);    glVertex3f(-0.5,0.5,-0.5);
   glEnd();

   glBegin(GL_POLYGON);

         GLfloat normal4[3] ;
		 GLfloat pointa4[3] ={-0.5,0.5,0.5};
	  GLfloat pointb4[3]= {-0.5,0.5,-0.5};
	  GLfloat pointc4[3]= {-0.5,-0.5,-0.5};
	  GLfloat pointd4[3]={-0.5,-0.5,0.5};
   
    NormalHelper::getFaceNormal(normal4, pointc4, pointb4, pointa4);

	 glNormal3f(normal4[0], normal4[1], normal4[2]);


     //glNormal3f(-1.0, 0.0, 0.0);
glTexCoord2f(1.0, -1.0);      glVertex3f(-0.5,0.5,0.5);
   glTexCoord2f(1.0,  1.0);     glVertex3f(-0.5,0.5,-0.5);
   glTexCoord2f(-1.0,  1.0);     glVertex3f(-0.5,-0.5,-0.5);
     glTexCoord2f(-1.0, -1.0);     glVertex3f(-0.5,-0.5,0.5);
   glEnd();

   glBegin(GL_POLYGON);

      GLfloat normal5[3] ;
	  GLfloat pointa5[3] ={0.5,0.5,0.5};
		GLfloat pointb5[3]= {0.5,0.5,-0.5};
	  GLfloat pointc5[3]= {-0.5,0.5,-0.5};
	  GLfloat pointd5[3]={-0.5,0.5,0.5};
   
    NormalHelper::getFaceNormal(normal5, pointc5, pointb5, pointa5);

	 glNormal3f(normal5[0], normal5[1], normal5[2]);


    // glNormal3f(0.0, 1.0, 0.0);
glTexCoord2f(1.0, -1.0);      glVertex3f(0.5,0.5,0.5);
  glTexCoord2f(1.0,  1.0);      glVertex3f(0.5,0.5,-0.5);
  glTexCoord2f(-1.0,  1.0);     glVertex3f(-0.5,0.5,-0.5);
    glTexCoord2f(-1.0, -1.0);     glVertex3f(-0.5,0.5,0.5);
   glEnd();

   glBegin(GL_POLYGON);

         GLfloat normal6[3] ;
		 GLfloat pointa6[3] = {0.5,-0.5,0.5};
	  GLfloat pointb6[3]= {-0.5,-0.5,0.5};
		GLfloat pointc6[3]= {-0.5,-0.5,-0.5};
	  GLfloat pointd6[3]= {0.5,-0.5,-0.5};
   
    NormalHelper::getFaceNormal(normal6, pointc6, pointb6, pointa6);

	 glNormal3f(normal6[0], normal6[1], normal6[2]);

   //  glNormal3f(0.0, -1.0, 0.0);
  glTexCoord2f(1.0, -1.0);    glVertex3f(0.5,-0.5,0.5);
  glTexCoord2f(1.0,  1.0);    glVertex3f(-0.5,-0.5,0.5);
  glTexCoord2f(-1.0,  1.0);    glVertex3f(-0.5,-0.5,-0.5);
  glTexCoord2f(-1.0, -1.0);   glVertex3f(0.5,-0.5,-0.5);
   glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void Box::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void Box::update()
{
	xAngle += 0.01f;
	yAngle  += 0.01f;
	zAngle  += 0.005f;
}
