#include "Camera.h"
#include "Main.h"
#include "SpaceWall.h"
#include "TableSurface.h"
#include "Sun.h"
#include "Cylinder.h"
#include "Box.h"
#include "Gear.h"
#include "Earth.h"

#include <math.h>
#include <stdlib.h>
#include <freeglut.h>


Camera camera = Camera();

Box boxTest; 
SpaceWall skybox; 
TableSurface table; 
Sun sun; 
Cylinder tCylin; 
Gear gearT; 
Earth earth;


GLfloat angleX;
GLfloat angleY;
GLfloat angleZ;

GLfloat cubeX;
GLfloat cubeY;
GLfloat cubeZ;

GLfloat specular = 1.0;
GLfloat diffuse = 0.5;
GLfloat shiny = 50.0;

GLfloat light_position[] = { 10.0, 4.0, 10.0, 0.0 };



void init (void) 
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glCullFace(GL_BACK);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);

	skybox = SpaceWall(0.0 , 0.0 , -10.0);
	table = TableSurface(0.0 , -5.0 , 0.0);
	sun = Sun(0.0 , 3.0 , 0.0);
	tCylin = Cylinder(0,-5,0);
	boxTest = Box(0,-5,0);
	gearT = Gear(0 ,-2.5 ,0);
	earth = Earth(10 ,3 ,0);
}


void display (void)
{
	GLfloat density = 0.002f;
	GLfloat fogColor[4] = {0.10, 0.027, 0.188, 1.0};
	glFogi (GL_FOG_MODE, GL_LINEAR);
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density);
	glHint (GL_FOG_HINT, GL_NICEST);
	glFogf(GL_FOG_START, 100.0f);
	glFogf(GL_FOG_END, 600.0f); 
    glEnable(GL_FOG);




	GLfloat mat_specular[] = { specular, specular, specular, 1.0 };
	GLfloat mat_diffuse[] = { diffuse, diffuse, 0.5, 1.0 };
	GLfloat mat_shininess[] = { shiny };
	GLfloat mat_diffuse2[] = { 0.8, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse3[] = { 0.2, 0.8, 0.2, 1.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel (GL_SMOOTH);
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );  // WIREFRAME

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

    camera.update();

	skybox.display();
	table.display();
	tCylin.display();
	gearT.display();
	sun.display();
	earth.display();
	boxTest.display();
	
	glTranslated(5 ,0 ,0);  // REMOVE LATER
	glutSolidSphere(1.0, 100, 100);

    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1600.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void keyboard (unsigned char key, int x, int y)
{
	camera.keyboardControl(key , x , y);

	if (key=='k'){light_position[1] += 0.1f;}
	if (key=='i'){light_position[1] -= 0.1f;}
	if (key=='j'){light_position[0] += 0.1f;}
	if (key=='l'){light_position[0] -= 0.1f;}
	if (key=='u'){light_position[2] += 0.1f;}
	if (key=='o'){light_position[2] -= 0.1f;}

}

void mouseUpdate(int x , int y)
{
	//	camera.mouseControl(x,y);
}


void idle(void)
{
	gearT.update();
	sun.update();
	skybox.update();
	earth.update();

	glutPostRedisplay();
}


int main (int argc, char **argv)
{
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("Lighting Demo"); 
    init (); 
    glutDisplayFunc (display); 
    glutIdleFunc (idle); 
    glutReshapeFunc (reshape);

	glutPassiveMotionFunc(mouseUpdate); //check for mousemovement

    glutKeyboardFunc (keyboard); 
    glutMainLoop (); 
    return 0;
}