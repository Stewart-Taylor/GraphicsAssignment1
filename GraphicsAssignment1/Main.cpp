#include "Camera.h"
#include "Main.h"
#include "SpaceWall.h"
#include "TableSurface.h"
#include "Sun.h"
#include "Cylinder.h"
#include "Box.h"
#include "Gear.h"
#include "Planet.h"
#include "OutPole.h"

#include <math.h>
#include <stdlib.h>
#include <freeglut.h>

Camera camera = Camera();

Box boxTest; 
SpaceWall skybox; 
TableSurface table; 
Sun sun; 
Cylinder centralPole; 
Cylinder powerPole; 
Gear mainGear; 
Gear bigGear; 
Gear powerGear; 

GLfloat angleX;
GLfloat angleY;
GLfloat angleZ;


GLfloat specular = 1.0;
GLfloat diffuse = 0.5;
GLfloat shiny = 50.0;

GLfloat orbitTimer  = 9939;
GLfloat orbitSpeed = 0.001f;

GLfloat light_position[] = { 0.29999962 , 1.9000014 , -1.1000001};



struct PlanetPart
{
	Planet planet;
	Cylinder upPole;
	OutPole outPole;
	GLfloat radius;
	GLfloat rotateModifier;

	void update(void)
	{
		float	xPositionT= 0 + sin(orbitTimer*rotateModifier)*radius;
		float zPositionT = 0 + cos(orbitTimer*rotateModifier)*radius;

		planet.setPosition(xPositionT ,planet.yPosition , zPositionT);
		planet.spin();

		upPole.setPosition(xPositionT , upPole.yPosition , zPositionT);
		upPole.spin(1.0);

		outPole.spin();

		float angle = atan2(zPositionT , xPositionT);
		angle = -angle * 180 / 3.1415926;;
		angle+= 90;
		outPole.setAngle(0,  angle, 0);  // 57.3
	}

	void display(void)
	{
		planet.display();
		upPole.display();
		outPole.display();
	}

};

PlanetPart mercury;
PlanetPart venus;
PlanetPart earth;
PlanetPart mars;
PlanetPart jupiter;
PlanetPart saturn;
PlanetPart uranus;
PlanetPart neptune;


void setUpPlanet(PlanetPart& part , GLfloat radiusT , GLfloat mod , GLfloat y );


void setUpPlanet(PlanetPart& part , GLfloat radiusT , GLfloat mod , GLfloat y  , GLfloat planetScale , char* path )
{
	part.planet = Planet(10 ,(y+ 4) ,0 , path);
	part.planet.scale = planetScale;
	part.upPole = Cylinder(10 , (y + 2.0) ,0 , 0.1 , 4.0 , 30);
	part.outPole = OutPole(0 , y ,0 , 0.2 , radiusT + 0.2 , 30);
	part.outPole.setAngle(0,0,90);
	part.radius = radiusT;
	part.rotateModifier = mod;
}

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
	sun = Sun(0.0 , 8.0 , 0.0);
	centralPole = Cylinder(0,3.0,0 ,0.54 , 12.0 , 30);
	boxTest = Box(0,-3.99,0 , 10,10,2);
	mainGear = Gear(0 ,-2.7 ,0 , 0.5 , 4.0 ,  0.4 , 50 ,0.35);
	powerGear = Gear(4.3 ,-2.7 ,3.8 , 0.2 , 1.6 ,  0.4 , 20 ,0.35);
	powerPole = Cylinder(4.3 ,-1.7 ,3.8 ,0.18 , 2.0 , 30);

	setUpPlanet(mercury , 5 ,4.1 ,4.5 , 0.4 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\mercury.bmp");
	setUpPlanet(venus , 10 ,1.62 ,4.0 , 1.0 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\venus.bmp");
	setUpPlanet(earth , 15 ,1 ,3.5 , 1.0 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\earth.bmp");
	setUpPlanet(mars , 20 ,0.53 ,3.0 , 0.53 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\mars.bmp");
	setUpPlanet(jupiter , 25 ,0.08 ,2.5 , 2.0 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\jupiter.bmp");
	setUpPlanet(saturn , 30 ,0.0339 ,2.0 , 1.5 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\saturn.bmp");
	setUpPlanet(uranus , 35 ,0.011 ,1.5 , 1.2 , "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\uranus.bmp");
	setUpPlanet(neptune , 40 ,0.006 ,1.0 , 1.2, "C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\neptune.bmp");
}


void drawPlanets()
{
	mercury.display();
	venus.display();
	earth.display();
	mars.display();
	jupiter.display();
	saturn.display();
	uranus.display();
	neptune.display();
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
	

	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();


    camera.update();


	


	skybox.display();
	table.display();
	centralPole.display();
	mainGear.display();
	powerGear.display();
	powerPole.display();
	sun.display();
	boxTest.display();

	drawPlanets();


	glTranslated(light_position[0] ,light_position[1] ,light_position[2]);  // REMOVE LATER
	glutSolidSphere(1.0, 100, 100);

	        glPushMatrix();
			glTranslated(-light_position[0] ,-light_position[1] ,-light_position[2]);
            glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glPopMatrix();

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
	if (key=='m'){orbitSpeed += 0.001f;}
	if (key=='n'){orbitSpeed -= 0.001f;}
}

void mouseUpdate(int x , int y)
{
	//	camera.mouseControl(x,y);
}

void updatePlanets(void)
{
	orbitTimer+= orbitSpeed;

	mercury.update();
	venus.update();
	earth.update();
	mars.update();
	jupiter.update();
	saturn.update();
	uranus.update();
	neptune.update();
}




void idle(void)
{
	mainGear.spin(orbitSpeed * 60);  // 0.06
	powerGear.spin(-orbitSpeed * 200); // -0.2
	powerPole.spin(orbitSpeed * 200);   // 0.2
	sun.update();
	skybox.update();
	updatePlanets();

	glutPostRedisplay();
}


int main (int argc, char **argv)
{
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("Mechanical Orrey"); 
    init (); 
    glutDisplayFunc (display); 
    glutIdleFunc (idle); 
    glutReshapeFunc (reshape);

	glutPassiveMotionFunc(mouseUpdate); //check for mousemovement

    glutKeyboardFunc (keyboard); 
    glutMainLoop (); 
    return 0;
}




