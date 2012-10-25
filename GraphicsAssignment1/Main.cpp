/*		MECHANICAL ORRERY
 *	AUTHOR: STEWART TAYLOR
 *	DATE STARTED: 20/10/2012
 *------------------------------------
 * This program is part of the Graphics modules first assignment.
 * It demonstrates the use of defining 3D objects manually, 
 * making use of matrix manipulations, textures ,the use of shadows and lights.
 * 
 * The main class is used as a controler and is also used to set the program up.
 *
 * Last Updated: 25/10/2012
*/

#define _USE_MATH_DEFINES


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
#include "ShadowHelper.h"

#include <math.h>
#include <stdlib.h>
#include <freeglut.h>
#include <fstream>
#include <iostream>


Camera camera = Camera();

Box baseBox; 
Box coverBox;
Box coverBox2; 
Box coverBox3; 
Box coverBox4;
SpaceWall skybox; 
TableSurface table; 
Sun sun; 
Cylinder centralPole; 
Cylinder powerPole; 
Cylinder powerPole2; 
Cylinder powerPole3; 
Cylinder powerPole4; 
Cylinder saturnRing; 
Gear mainGear; 
Gear bigGear; 
Gear powerGear; 
Gear bigPowerGear; 
Gear smallMiddleGear; 
Gear sideGear; 
Cylinder sidePole; 

Cylinder neptunePole;
Cylinder uranusPole;
Cylinder saturnPole;
Cylinder jupiterPole;
Cylinder marsPole;
Cylinder earthPole;
Cylinder venusPole;
Cylinder mercuryPole;
Cylinder moonCylinder;



GLfloat specular = 1.0;
GLfloat diffuse = 0.5;
GLfloat shiny = 50.0;

GLfloat orbitTimer  = 9939;
GLfloat orbitSpeed = 0.001f;

GLfloat light_position[] = { 20.0 , 48.0 ,7.0 , 1.0};
GLfloat mat_specular[] = { specular, specular, specular, 1.0 };
GLfloat mat_diffuse[] = { diffuse, diffuse, 0.5, 1.0 };
GLfloat mat_shininess[] = { shiny };



struct PlanetPart
{
	Planet planet;
	Cylinder upPole;
	OutPole outPole;
	GLfloat radius;
	GLfloat rotateModifier;
	GLfloat spinSpeed;

	void update(void)
	{
		GLfloat xPositionT = 0 + sin(orbitTimer * rotateModifier) * radius;
		GLfloat zPositionT = 0 + cos(orbitTimer * rotateModifier) * radius;

		planet.setPosition(xPositionT ,planet.yPosition , zPositionT);
		upPole.setPosition(xPositionT , upPole.yPosition , zPositionT);
		upPole.spin(1.0);

		GLfloat angle = atan2(zPositionT , xPositionT);
		angle = -angle * 180 / M_PI;
		angle+= 90;
		outPole.setAngle(0,  angle, 0);
	}

	void display(void)
	{
		planet.display();
		upPole.display();
		outPole.display();
	}

	void displayShadow(void)
	{
		planet.displayShadow();
		upPole.displayShadow();
		outPole.displayShadow();
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
PlanetPart moon;


void setUpPlanet(PlanetPart& part , GLfloat radiusT , GLfloat rotateMod , GLfloat y  , GLfloat planetScale , char* path )
{
	part.planet = Planet(10 ,(y+ 4) ,0 , path);
	part.planet.scale = planetScale;
	part.upPole = Cylinder(10 , (y + 2.0) ,0 , 0.1 , 4.0 , 15);
	part.outPole = OutPole(0 , y ,0 , 0.2 , radiusT + 0.2 , 15);
	part.outPole.setAngle(0,0,90);
	part.radius = radiusT;
	part.rotateModifier = rotateMod;
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

	skybox = SpaceWall();
	table = TableSurface();
	
	sun = Sun(0.0 , 13.0 , 0.0);
	centralPole = Cylinder(0,8.0,0 ,0.54 , 12.0 , 30);
	
	baseBox = Box(0,1.01,0 , 10,10,2);
	coverBox = Box(0,3.2,3.8 , 10,1,0.5);
	coverBox2 = Box(0,3.2,-3.8 , 10,1,0.5);
	coverBox3 = Box(4.4,3.3,0 , 9,1,0.5);
	coverBox3.setAngle(90 ,180 , 90);
	coverBox4 = Box(-4.4,3.3,0 , 9,1,0.5);
	coverBox4.setAngle(90 ,180 , 90);
	
	mainGear = Gear(0 ,2.3 ,0 , 0.5 , 4.0 ,  0.4 , 50 ,0.35);
	bigPowerGear = Gear(-4.3 ,2.8 ,3.8 , 0.2 , 4.0 ,  0.4 , 50 ,0.35);
	powerGear = Gear(4.3 ,2.3 ,3.8 , 0.2 , 1.6 ,  0.4 , 20 ,0.35);
	smallMiddleGear = Gear(0 ,2.8 ,0 , 0.5 , 1.6 ,  0.4 , 20 ,0.35);
	sideGear = Gear(5.9 ,1.5 ,3.8 , 0.2 , 0.7 ,  0.2 , 10 ,0.35);
	sidePole = Cylinder(5.9 ,1.5 ,3.8 ,0.18 , 2.0 , 30);
	sidePole.setAngle(180 ,90 ,0);
	sideGear.setAngle(180 ,90 ,0);
	
	powerPole = Cylinder(4.3 ,3.3 ,3.8 ,0.18 , 2.0 , 30);
	powerPole2 = Cylinder(-4.3 ,3.3 ,3.8 ,0.18 , 2.0 , 30);
	powerPole3 = Cylinder(-4.3 ,3.3 ,-3.8 ,0.18 , 2.0 , 30);
	powerPole4 = Cylinder(4.3 ,3.3 ,-3.8 ,0.18 , 2.0 , 30);
	
	moonCylinder = Cylinder(-4.3 ,3.3 ,2.0 ,0.3, 1.0 , 30);

	neptunePole = Cylinder(0,4.62,0 ,0.9 , 3.3 , 30);
	uranusPole = Cylinder(0,5.0,0 ,0.8 , 3.5 , 30);
	saturnPole = Cylinder(0,5.4,0 ,0.7 , 3.7 , 30);
	jupiterPole = Cylinder(0,5.8,0 ,0.6 , 3.9 , 30);
	marsPole = Cylinder(0,6.2,0 ,0.5 , 4.1 , 30);
	earthPole = Cylinder(0,6.58,0 ,0.4 , 4.3 , 30);
	venusPole = Cylinder(0,6.96,0 ,0.3 , 4.5 , 30);
	mercuryPole = Cylinder(0,8,0 ,0.2 , 5.0 , 30);

	saturnRing = Cylinder(0 ,11.0 ,0 ,2.4 , 0.2 , 30);
	saturnRing.yAngle = -12;
	
	setUpPlanet(mercury , 5 ,4.1 ,9.5 , 0.4 , "Textures\\mercury.bmp");
	setUpPlanet(venus , 10 ,1.62 ,9.0 , 1.0 , "Textures\\venus.bmp");
	setUpPlanet(earth , 15 ,1 ,8.5 , 1.0 , "Textures\\earth.bmp");
	setUpPlanet(mars , 20 ,0.53 ,8.0 , 0.53 , "Textures\\mars.bmp");
	setUpPlanet(jupiter , 25 ,0.08 ,7.5 , 2.0 , "Textures\\jupiter.bmp");
	setUpPlanet(saturn , 30 ,0.0339 ,7.0 , 1.5 , "Textures\\saturn.bmp");
	setUpPlanet(uranus , 35 ,0.011 ,6.5 , 1.2 , "Textures\\uranus.bmp");
	setUpPlanet(neptune , 40 ,0.006 ,6.0 , 1.2, "Textures\\neptune.bmp");
	setUpPlanet(moon , 2 ,13 ,8.8  , 0.3 , "Textures\\moon.bmp");

	//Earths Tilt
	earth.planet.setAngle(-90,23.5,0);
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
	moon.display();
	saturnRing.display();
}

void drawPlanetsShadow()
{
	mercury.displayShadow();
	venus.displayShadow();
	earth.displayShadow();
	moon.displayShadow();
	mars.displayShadow();
	jupiter.displayShadow();
	saturn.displayShadow();
	uranus.displayShadow();
	neptune.displayShadow();
	saturnRing.displayShadow();
	moon.displayShadow();
}


void drawShadows()
{
	GLfloat shadow_proj[16];
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glPushMatrix();
    GLfloat plane_eq[] = {0.0, 1.0, 0.0, 0.0};
	ShadowHelper::shadow_matrix(light_position,plane_eq,shadow_proj);
	glMultMatrixf(shadow_proj);
		
	coverBox.displayShadow();
	coverBox2.displayShadow();
	coverBox3.displayShadow();
	coverBox4.displayShadow();
	mainGear.displayShadow();
	powerGear.displayShadow();
	smallMiddleGear.displayShadow();
	bigPowerGear.displayShadow();
	sideGear.displayShadow();
	sidePole.displayShadow();
	powerPole.displayShadow();
	powerPole2.displayShadow();
	powerPole3.displayShadow();
	powerPole4.displayShadow();
	sun.displayShadow();
	baseBox.displayShadow();
	moonCylinder.displayShadow();
	drawPlanetsShadow();
	
	neptunePole.displayShadow();   // ONLY one visible at set lighting angle . Inner MIddle POle
	//uranusPole.displayShadow();  
	//saturnPole.displayShadow();
	//jupiterPole.displayShadow();
	//marsPole.displayShadow();
	//earthPole.displayShadow();
	//venusPole.displayShadow();
	//mercuryPole.displayShadow();

	glPopMatrix();

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}


void displayFog(void)
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
}


void display (void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel (GL_SMOOTH);
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );  // WIREFRAME
	
	displayFog();

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

	camera.update();

	glDisable(GL_CULL_FACE);
	skybox.display();
	glEnable(GL_CULL_FACE);

	table.display();
	drawShadows();
	mainGear.display();
	powerGear.display();
	smallMiddleGear.display();
	bigPowerGear.display();
	sideGear.display();
	sidePole.display();
	powerPole.display();
	powerPole2.display();
	powerPole3.display();
	powerPole4.display();
	sun.display();
	baseBox.display();
	coverBox.display();
	coverBox2.display();
	coverBox3.display();
	coverBox4.display();
	moonCylinder.display();
	drawPlanets();
	neptunePole.display();
	uranusPole.display();
	saturnPole.display();
	jupiterPole.display();
	marsPole.display();
	earthPole.display();
	venusPole.display();
	mercuryPole.display();

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
	key = tolower(key); // Allows Caps Lock to still work

	camera.keyboardControl(key , x , y);

	if (key=='k'){light_position[1] += 1;}
	if (key=='i'){light_position[1] -= 1;}
	if (key=='j'){light_position[0] += 1;}
	if (key=='l'){light_position[0] -= 1;}
	if (key=='u'){light_position[2] += 1;}
	if (key=='o'){light_position[2] -= 1;}
	
	if (key=='m')
	{
		orbitSpeed += 0.0001f;
	}
	else if (key=='n')
	{
		orbitSpeed -= 0.0001f;
	}
}

void mouseUpdate(int x , int y)
{
	//camera.mouseControl(x,y);
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

	//update saturn ring
	saturnRing.xPosition = saturn.planet.xPosition;
	saturnRing.zPosition = saturn.planet.zPosition;

	neptunePole.zAngle = -neptune.outPole.yAngle;
	uranusPole.zAngle = -uranus.outPole.yAngle;
	saturnPole.zAngle = -saturn.outPole.yAngle;
	jupiterPole.zAngle = -jupiter.outPole.yAngle;
	marsPole.zAngle = -mars.outPole.yAngle;
	earthPole.zAngle = -earth.outPole.yAngle;
	venusPole.zAngle = -venus.outPole.yAngle;
	mercuryPole.zAngle = -mercury.outPole.yAngle;

	GLfloat xPositionT= earth.planet.xPosition + sin(orbitTimer* moon.rotateModifier)*moon.radius;
	GLfloat zPositionT =  earth.planet.zPosition + cos(orbitTimer* moon.rotateModifier)*moon.radius;

	moon.planet.setPosition(xPositionT ,moon.planet.yPosition , zPositionT);

	moon.upPole.setPosition(xPositionT , moon.upPole.yPosition , zPositionT);
	moon.upPole.spin(1.0);
	moon.outPole.setOriginPosition(earth.planet.xPosition , 0 , earth.planet.zPosition); 

	GLfloat deltaZ = moon.planet.zPosition - earth.planet.zPosition;
	GLfloat deltaX = moon.planet.xPosition - earth.planet.xPosition;
	GLfloat angle = atan2(deltaZ , deltaX) ; 
	angle = -angle * 180 / 3.1415926;
	angle+= 90;

	moon.outPole.setAngle(0,  angle , 0);

	moonCylinder.setPosition(earth.upPole.xPosition ,earth.upPole.yPosition - 1.8 , earth.upPole.zPosition);
}



void idle(void)
{
	mainGear.spin(orbitSpeed * 60);  // values defined allow for good interlocking and speed , obtained through trial and error
	powerGear.spin(-orbitSpeed * 200); 
	smallMiddleGear.spin(orbitSpeed * 200);
	bigPowerGear.spin(-orbitSpeed * 60);
	sideGear.spin(-orbitSpeed * 400);
	sidePole.spin(orbitSpeed * 400);
	sun.update();
	updatePlanets();

	glutPostRedisplay();
}

void printInfo()
{
	std::cout << "	OpenGL Mechanical 3D Orrery" << std::endl << std::endl;
	std::cout << "	Created by Stewart Taylor" << std::endl << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "CONTROLS" << std::endl;
	std::cout << std::endl;
	std::cout << "CAMERA" << std::endl;
	std::cout << " W,A,S,D  - Move Camera" << std::endl;
	std::cout << " Q,E - Look Left/Right" << std::endl;
	std::cout << " R,F - Move Camera Up/Down " << std::endl;
	std::cout << " Z,X - Tilt Camera Up/Down" << std::endl;
	std::cout << std::endl;
	std::cout << "Main " << std::endl;
	std::cout << " M - Increase speed" << std::endl;
	std::cout << " N - Decrease speed" << std::endl;
	std::cout << std::endl;
	std::cout << "LIGHT " << std::endl;
	std::cout << " U,I,K,L,J - Move Light Source" << std::endl;
	std::cout << std::endl;
}

int main (int argc, char **argv)
{
	printInfo();
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 600); 
    glutInitWindowPosition (200, 100);
    glutCreateWindow ("Mechanical Orrery"); 
    init (); 
    glutDisplayFunc (display); 
    glutIdleFunc (idle); 
    glutReshapeFunc (reshape);
	glutPassiveMotionFunc(mouseUpdate); 
    glutKeyboardFunc (keyboard); 
    glutMainLoop (); 
    return 0;
}




