//Semestre 2017 - 2
//Alumno: Gutiérrez Benítez David Fernando//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY= 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
float valx = 0.0f;
float valy = 0.0f;
float valz = 0.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float cr1, float cg1, float cb1, float cr2, float cg2, float cb2, float cr3, float cg3, float cb3, float cr4, float cg4, float cb4, float cr5, float cg5, float cb5, float cr6, float cg6, float cb6, float x, float y, float z)
{
	GLfloat vertice [8][3] = {
				{x,-y,z},    //Coordenadas Vértice 0 V0
				{-x,-y,z},    //Coordenadas Vértice 1 V1
				{-x,-y,-z},    //Coordenadas Vértice 2 V2
				{x,-y,-z},    //Coordenadas Vértice 3 V3
				{x,y,z},    //Coordenadas Vértice 4 V4
				{x,y,-z},    //Coordenadas Vértice 5 V5
				{-x,y,-z},    //Coordenadas Vértice 6 V6
				{-x,y,z},    //Coordenadas Vértice 7 V7
				};


		glBegin(GL_POLYGON);	//Front
			glColor3f(cr1,cg1,cb1);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(cr2, cg2, cb2);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(cr3, cg3, cb3);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(cr4, cg4, cb4);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(cr5, cg5, cb5);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(cr6, cg6, cb6);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//Poner Código Aquí.

	//se le cambia el color de las caras con el siguiente formato
	//prisma(front,front,front, right,right,right, back,back,back, left,left,left, bottom,bottom,botton, top,top,top, base,altura,volumen)
	//se le pude cambiar el valor de x con las teclas x,b
	//se le pude cambiar el valor de y con las teclas y,u
	//se le pude cambiar el valor de x con las teclas z,n
	//rota en el eje x con las teclas r,t
	//rota en el eje y con las teclas f,g
	//rota en el eje z con las teclas c,v
	//translada horizontal a,d
	//translada vertical q,e
	//translada eje z w,s

	glTranslatef(0.0+transX,0.0+transY,-5.0+transZ);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleZ, 0, 0, 1);
	prisma(0.0,1.0,0.0, 1.0,0.0,0.0, 0.0,0.0,1.0, 1.0,1.0,0.0, 0.0,1.0,1.0, 1.0,1.0,1.0, 1.0+valx,1.0+valy,1.0+valz);

    glutSwapBuffers ( );

    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'q':
		case 'Q':
			transY +=0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 'e':
		case 'E':
			transY -=0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 't':
		case 'T':
			angleX +=01.0f;
			break;
		case 'r':
		case 'R':
			angleX -=1.0f;
			break;
		case 'f':
		case 'F':
			angleY -=1.0f;
			break;
		case 'g':
		case 'G':
			angleY +=1.0f;
			break;
		case 'c':
		case 'C':
			angleZ -=1.0f;
			break;
		case 'v':
		case 'V':
			angleZ +=1.0f;
			break;
		case 'x':
		case 'X':
			valx += 0.5f;
			break;
		case 'b':
		case 'B':
			valx -= 0.5f;
			break;
		case 'y':
		case 'Y':
			valy += 0.5f;
			break;
		case 'u':
		case 'U':
			valy -= 0.5f;
			break;
		case 'z':
		case 'Z':
			valz += 0.5f;
			break;
		case 'n':
		case 'N':
			valz -= 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



