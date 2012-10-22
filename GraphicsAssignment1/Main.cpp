#include "Camera.h"
#include "Main.h"
#include "SpaceWall.h"


#include <math.h>
#include <stdlib.h>
#include <freeglut.h>

void crossProduct(float *c,float a[3], float b[3]);
void normalize(float *vect);
void getFaceNormal(float *norm,float pointa[3],float pointb[3],float pointc[3]);



Camera camera = Camera();


SpaceWall testWall ; 

//positions of the cubes
float positionz[10];
float positionx[10];

GLfloat angleX;
GLfloat angleY;
GLfloat angleZ;

GLfloat cubeX;
GLfloat cubeY;
GLfloat cubeZ;

GLfloat light_position[] = {1.0 ,2.0 ,1.0 , 0.0};


GLfloat specular = 1.0;
GLfloat diffuse = 0.5;
GLfloat shiny = 50.0;



void cubepositions (void) 
{ //set the positions of the cubes

    for (int i=0;i<10;i++)
    {
    positionz[i] = rand()%5 + 1;
    positionx[i] = rand()%5 + 1;
    }
}

//draw the cube
void cube(GLfloat x , GLfloat y , GLfloat z , GLfloat size)
{



	GLfloat mat_d[] = {0.1, 0.5, 0.8, 1.0};
GLfloat mat_s[] = {1.0, 1.0, 1.0, 1.0};
GLfloat low_sh[] = {5.0};

	glPushMatrix(); 
	glTranslated(x ,y ,z);
	

	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(size ,size ,size);


	
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_POLYGON);



   GLfloat normal[3] ;
   GLfloat pointa[3] = {0.5,0.5,0.5};
   GLfloat pointb[3]= {-0.5,0.5,0.5};
   GLfloat pointc[3]= {-0.5,-0.5,0.5};
   GLfloat pointd[3]= {0.5,-0.5,0.5};
   
    getFaceNormal(normal, pointa, pointb, pointc);

	 glNormal3f(normal[0], normal[1], normal[2]);
     glVertex3f(0.5,0.5,0.5);
     glVertex3f(-0.5,0.5,0.5);
     glVertex3f(-0.5,-0.5,0.5);
     glVertex3f(0.5,-0.5,0.5);
   glEnd();

   
   glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
  
	   GLfloat normal1[3] ;
   GLfloat pointa1[3] = {0.5,0.5,0.5};
   GLfloat pointb1[3]= {0.5,-0.5,0.5};
   GLfloat pointc1[3]= {0.5,-0.5,-0.5};
   GLfloat pointd1[3]= {0.5,0.5,-0.5};
   
    getFaceNormal(normal1, pointa1, pointb1, pointc1);

	 glNormal3f(normal1[0], normal1[1], normal1[2]);


     glVertex3f(0.5,0.5,0.5);
     glVertex3f(0.5,-0.5,0.5);
     glVertex3f(0.5,-0.5,-0.5);
     glVertex3f(0.5,0.5,-0.5);
   glEnd();
  
   glColor3f(0.0,1.0,1.0);
   glBegin(GL_POLYGON);
 
   	   GLfloat normal2[3] ;
   GLfloat pointa2[3] = {0.5,0.5,-0.5};
   GLfloat pointb2[3]= {0.5,-0.5,-0.5};
   GLfloat pointc2[3]= {-0.5,-0.5,-0.5};
   GLfloat pointd2[3]= {-0.5,0.5,-0.5};
   
    getFaceNormal(normal2, pointa2, pointb2, pointc2);

	 glNormal3f(normal2[0], normal2[1], normal2[2]);

     glVertex3f(0.5,0.5,-0.5);
     glVertex3f(0.5,-0.5,-0.5);
     glVertex3f(-0.5,-0.5,-0.5);
     glVertex3f(-0.5,0.5,-0.5);
   glEnd();
  
   glColor3f(1.0,0.0,1.0);
   glBegin(GL_POLYGON);

      	   GLfloat normal3[3] ;
   GLfloat pointa3[3] = {-0.5,0.5,0.5};
   GLfloat pointb3[3]= {-0.5,0.5,0.5};
   GLfloat pointc3[3]= {-0.5,-0.5,-0.5};
   GLfloat pointd3[3]= {-0.5,-0.5,0.5};
   
    getFaceNormal(normal3, pointa3, pointb3, pointc3);

	 glNormal3f(normal3[0], normal3[1], normal3[2]);

     glVertex3f(-0.5,0.5,0.5);
     glVertex3f(-0.5,0.5,-0.5);
     glVertex3f(-0.5,-0.5,-0.5);
     glVertex3f(-0.5,-0.5,0.5);
   glEnd();
  
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_POLYGON);

         	   GLfloat normal4[3] ;
   GLfloat pointa4[3] = {0.5,0.5,0.5};
   GLfloat pointb4[3]= {0.5,0.5,-0.5};
   GLfloat pointc4[3]= {-0.5,0.5,-0.5};
   GLfloat pointd4[3]= {-0.5,0.5,0.5};
   
    getFaceNormal(normal4, pointa4, pointb4, pointc4);

	 glNormal3f(normal4[0], normal4[1], normal4[2]);

     glVertex3f(0.5,0.5,0.5);
     glVertex3f(0.5,0.5,-0.5);
     glVertex3f(-0.5,0.5,-0.5);
     glVertex3f(-0.5,0.5,0.5);
   glEnd();
  
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_POLYGON);

            	   GLfloat normal5[3] ;
   GLfloat pointa5[3] = {0.5,-0.5,0.5};
   GLfloat pointb5[3]= {-0.5,-0.5,0.5};
   GLfloat pointc5[3]= {-0.5,-0.5,-0.5};
   GLfloat pointd5[3]= {0.5,-0.5,-0.5};
   
    getFaceNormal(normal5, pointa5, pointb5, pointc5);

	 glNormal3f(normal5[0], normal5[1], normal5[2]);

     glVertex3f(0.5,-0.5,0.5);
     glVertex3f(-0.5,-0.5,0.5);
     glVertex3f(-0.5,-0.5,-0.5);
     glVertex3f(0.5,-0.5,-0.5);
   glEnd();


   
  glPopMatrix(); 
}



void cube2(GLfloat x , GLfloat y , GLfloat z , GLfloat size) {

		glPushMatrix(); 
	glTranslated(x ,y ,z);
	

	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);

		glScaled(size ,size ,size);

   glColor3f(1.0,0.0,0.0);
   glBegin(GL_POLYGON);


               	   GLfloat normal1[3] ;
				   GLfloat pointa1[3] = {0.0, 0.0, 1.0};
   GLfloat pointb1[3]= {0.5,0.5,0.5};
   GLfloat pointc1[3]= {-0.5,0.5,0.5};
   GLfloat pointd1[3]= {0.5,-0.5,0.5};
   
    getFaceNormal(normal1, pointa1, pointb1, pointc1);

	 glNormal3f(normal1[0], normal1[1], normal1[2]);


   //  glNormal3f(0.0, 0.0, 1.0);
     glVertex3f(0.5,0.5,0.5);
     glVertex3f(-0.5,0.5,0.5);
     glVertex3f(-0.5,-0.5,0.5);
     glVertex3f(0.5,-0.5,0.5);
   glEnd();
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_POLYGON);
     glNormal3f(1.0, 0.0, 0.0);
     glVertex3f(0.5,0.5,0.5);
     glVertex3f(0.5,-0.5,0.5);
     glVertex3f(0.5,-0.5,-0.5);
     glVertex3f(0.5,0.5,-0.5);
   glEnd();
   glColor3f(0.0,1.0,1.0);
   glBegin(GL_POLYGON);
     glNormal3f(1.0, 0.0, -1.0);
     glVertex3f(0.5,0.5,-0.5);
     glVertex3f(0.5,-0.5,-0.5);
     glVertex3f(-0.5,-0.5,-0.5);
     glVertex3f(-0.5,0.5,-0.5);
   glEnd();
   glColor3f(1.0,0.0,1.0);
   glBegin(GL_POLYGON);
     glNormal3f(-1.0, 0.0, 0.0);
     glVertex3f(-0.5,0.5,0.5);
     glVertex3f(-0.5,0.5,-0.5);
     glVertex3f(-0.5,-0.5,-0.5);
     glVertex3f(-0.5,-0.5,0.5);
   glEnd();
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_POLYGON);
     glNormal3f(0.0, 1.0, 0.0);
     glVertex3f(0.5,0.5,0.5);
     glVertex3f(0.5,0.5,-0.5);
     glVertex3f(-0.5,0.5,-0.5);
     glVertex3f(-0.5,0.5,0.5);
   glEnd();
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_POLYGON);
     glNormal3f(0.0, -1.0, 0.0);
     glVertex3f(0.5,-0.5,0.5);
     glVertex3f(-0.5,-0.5,0.5);
     glVertex3f(-0.5,-0.5,-0.5);
     glVertex3f(0.5,-0.5,-0.5);
   glEnd();

   glPopMatrix();
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
   cubepositions();

   testWall   = SpaceWall(0.0 , 0.0 , -10.0  );
}



void getFaceNormal(GLfloat *norm,GLfloat pointa[3],GLfloat pointb[3],GLfloat pointc[3])
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
	normalize(norm);									//makes the vector length 1
}


void normalize(GLfloat * vect)	//scales a vector a length of 1
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

void crossProduct(GLfloat *c,GLfloat a[3], GLfloat b[3])		//finds the cross product of two vectors
{															
	c[0]=a[1]*b[2] - b[1]*a[2];
	c[1]=a[2]*b[0] - b[2]*a[0];
	c[2]=a[0]*b[1] - b[0]*a[1];
}




void display (void)
{

    
       GLfloat mat_specular[] = { specular, specular, specular, 1.0 };
   GLfloat mat_diffuse[] = { diffuse, diffuse, 0.5, 1.0 };
   GLfloat mat_shininess[] = { shiny };
   GLfloat light_position[] = { 10.0, 0.0, 10.0, 0.0 };
  // GLfloat light_position[] = { xpos, ypos, zpos, 0.0 };

   GLfloat mat_diffuse2[] = { 0.8, 0.2, 0.2, 1.0 };
   GLfloat mat_diffuse3[] = { 0.2, 0.8, 0.2, 1.0 };

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

   glLightfv(GL_LIGHT0, GL_POSITION, light_position);


   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity();



    
	   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  



    camera.update();

	testWall.display();

	cube(light_position[0] , light_position[1] , light_position[2]  , 0.2);

	cube2(-2,0,0,0.6);
    cube(cubeX  - 3, cubeY , cubeZ , 1.0); //call the cube drawing function
	cube(cubeX + 4 , cubeY , cubeZ + 2 , 1.0); //call the cube drawing function
	cube(cubeX , cubeY  + 2, cubeZ + 10 , 1.0); //call the cube drawing function
	
	 glutSolidSphere(1.0, 100, 100);

    glutSwapBuffers(); //swap the buffers
   // angle++; //increase the angle
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void keyboard (unsigned char key, int x, int y)
{
	camera.keyboardControl(key , x , y);

    /*if (key=='q')
    {
    xrot += 1;
    if (xrot >360) xrot -= 360;
    }

    if (key=='z')
    {
    xrot -= 1;
    if (xrot < -360) xrot += 360;
    }

    if (key=='w')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f); 
    xpos += float(sin(yrotrad));
    zpos -= float(cos(yrotrad));
    ypos -= float(sin(xrotrad));
    }

    if (key=='s')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f); 
    xpos -= float(sin(yrotrad));
    zpos += float(cos(yrotrad));
    ypos += float(sin(xrotrad));
    }

    if (key=='d')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos += float(cos(yrotrad)) * 0.2;
    zpos += float(sin(yrotrad)) * 0.2;
    }

    if (key=='a')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos -= float(cos(yrotrad)) * 0.2;
    zpos -= float(sin(yrotrad)) * 0.2;
    }

    if (key==27)
    {
    exit(0);
    }
	*/
}




void idle(void)
{
		angleX += 0.01;
	angleY += 0.01;
	//angleZ += 0.01;
	testWall.update();

	 glutPostRedisplay();
}

void mouseUpdate(int x , int y)
{
//	camera.mouseControl(x,y);
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