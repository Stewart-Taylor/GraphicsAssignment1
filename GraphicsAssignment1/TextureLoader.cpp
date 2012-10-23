#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>

TextureLoader::TextureLoader(void)
{
}


TextureLoader::~TextureLoader(void)
{
}


 GLuint TextureLoader::loadTexture(char* Filename)
{
	GLuint id = 0;
	AUX_RGBImageRec *texture[1];
   	FILE *File=NULL;									// File Handle

	if (!Filename)										// Make Sure A Filename Was Given
	{
		// If Not Return NULL
	}

	File=fopen(Filename,"r");							// Check To See If The File Exists

	if (File)											// Does The File Exist?
	{
		fclose(File);	
		texture[0] = auxDIBImageLoadA(Filename);				// Load The Bitmap And Return A Pointer
	}


   /* Sets the pixel storage mode to unpack pixels in byte aligned mode */
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   /* provides unused texture identifier names */
   glGenTextures(1, &id);

   /* Binds "texName" as a 2D texture and activates texture */
   glBindTexture(GL_TEXTURE_2D, id);

    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, texture[0]->sizeX, texture[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, texture[0]->data );

   /* Controls texture wrapping */
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST );

   /* Defines a 2-dimensional texture */
   glTexImage2D(GL_TEXTURE_2D, 0, 3, texture[0]->sizeX,  texture[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture[0]->data);

   return id;
}
