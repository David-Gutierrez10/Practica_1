//Semestre 2018 - 1
//Alumno (s): Gutiérrez Benítez David Fernando

#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro=0.0f;
float angCodo=0.0f;
float angMano=0.0f;
float angPulgar=0.0f;
float angPulgar2=0.0f;
float angIndice=0.0f;
float angIndice2=0.0f;
float angIndice3=0.0f;
float angMedio=0.0f;
float angMedio2=0.0f;
float angMedio3=0.0f;
float angAnular=0.0f;
float angAnular2=0.0f;
float angAnular3=0.0f;
float angMeñique=0.0f;
float angMeñique2=0.0f;
float angMeñique3=0.0f;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
		
	glPushMatrix();
		//cabeza
		glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//cuello
		glPushMatrix();
			glTranslated(0.0, -0.75, 0.0);
			glScaled(0.5, 0.5, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		//torso
		glPushMatrix();
			glTranslated(0.0, -2.5, 0.0);
			glScaled(3.0, 3.0, 1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		//brazo derecho
		glPushMatrix();
			glTranslated(-3.0, -1.5, 0.0);
			glScaled(3.0, 1.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//mano derecha
		glPushMatrix();
			glTranslated(-5.5, -1.5, 0.0);
			glScaled(2.0, 2.0, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		//brazo izquierdo
		glPushMatrix();
			glTranslated(1.75, -1.25, 0.0);
			glRotatef(angHombro, 0.0, 0.0, 1.0);
			//hombro
			glPushMatrix();
				glColor3f(0.0, 1.0, 0.0);
				glScalef(0.5, 0.5, 1.0);
				prisma();
			glPopMatrix();
			//bicep
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glScalef(0.5, 1.0, 1.0);
				prisma();
			glPopMatrix();
			//codo
			glTranslatef(0.0, -0.75, 0.0);
			glRotatef(angCodo, 0.0, 0.0, 1.0);
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glScalef(0.5, 0.5, 1.0);
				prisma();
			glPopMatrix();
			//antebrazo
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 0.0);
				glScalef(0.5, 1.0, 1.0);
				prisma();
			glPopMatrix();
			//mano
			glTranslatef(0.0, -0.5, 0.5);
			glRotatef(angMano, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.25, -0.5);
			glPushMatrix();
				glColor3f(0.0, 1.0, 1.0);
				glScalef(0.5, 0.5, 1.0);
				prisma();
			glPopMatrix();
			//pulgar
			glPushMatrix();
				glTranslatef(0.25, 0.0, 0.0);
				glRotatef(angPulgar, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.5, 0.0);
				//parte1
				glPushMatrix();
					glScalef(0.2, 0.1, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.1, 0.0, 0.0);
				glRotatef(angPulgar2, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.6, 1.0);
				//parte2
				glPushMatrix();
					glScalef(0.2, 0.1, 1.0);
					prisma();
				glPopMatrix();
			glPopMatrix();
			//indice
			glPushMatrix();
				glTranslatef(0.20, -0.25, 0.5);
				glRotatef(angIndice, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 1.0);
				//parte1
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angIndice2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.6, 1.0);
				//parte2
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angIndice3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 0.0);
				//parte3
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
			glPopMatrix();
			//Medio
			glPushMatrix();
				glTranslatef(0.07, -0.25, 0.5);
				glRotatef(angMedio, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 1.0);
				//parte1
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angMedio2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.6, 1.0);
				//parte2
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angMedio3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 0.0);
				//parte3
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
			glPopMatrix();
			//anular
			glPushMatrix();
				glTranslatef(-0.07, -0.25, 0.5);
				glRotatef(angAnular, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 1.0);
				//parte1
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angAnular2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.6, 1.0);
				//parte2
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angAnular3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 0.0);
				//parte3
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
			glPopMatrix();
			//meñique
			glPushMatrix();
				glTranslatef(-0.20, -0.25, 0.5);
				glRotatef(angMeñique, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 1.0);
				//parte1
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angMeñique2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.6, 1.0);
				//parte2
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.1, 0.5);
				glRotatef(angMeñique3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, -0.5);
				glColor3f(0.3, 0.0, 0.0);
				//parte3
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		//pierna izquierdo
		glPushMatrix();
			glTranslated(1.0, -7.5, 0.0);
			glScaled(1.0, 7.0, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		//pierna derecha
		glPushMatrix();
			glTranslated(-1.0, -7.5, 0.0);
			glScaled(1.0, 7.0, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		//pie derecho
		glPushMatrix();
			glTranslated(-2.0, -12.5, 0.0);
			glScaled(3.0, 3.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//pie izquierdo
		glPushMatrix();
			glTranslated(2.0, -12.5, 0.0);
			glScaled(3.0, 3.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
	glPopMatrix();
  											
	glutSwapBuffers ( );
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch (key) {
		//manipulacion de brazo
		case 't':
			if (angHombro<180) {
				angHombro += 0.5f;
			}
				break;
		case 'T':
			if (angHombro>0) {
				angHombro -= 0.5f;
			}
			break;
		case 'y':
			if (angCodo<90) {
				angCodo += 0.5f;
			}
			break;
		case 'Y':
			if (angCodo>0) {
				angCodo -= 0.5f;
			}
			break;
		case 'u':
			if (angMano>-90) {
				angMano -= 0.5f;
			}
			break;
		case 'U':
			if (angMano<0) {
				angMano += 0.5f;
			}
			break;
		case 'i':
			if (angPulgar>-90) {
				angPulgar -= 0.5f;
			}
			break;
		case 'I':
			if (angPulgar<0) {
				angPulgar += 0.5f;
			}
			break;
		case 'o':
			if (angPulgar2>-90) {
				angPulgar2 -= 0.5f;
			}
			break;
		case 'O':
			if (angPulgar2<0) {
				angPulgar2 += 0.5f;
			}
			break;
		case 'z':
			if (angIndice>-90) {
				angIndice -= 0.5f;
			}
			break;
		case 'Z':
			if (angIndice<0) {
				angIndice += 0.5f;
			}
			break;
		case 'x':
			if (angIndice2>-90) {
				angIndice2 -= 0.5f;
			}
			break;
		case 'X':
			if (angIndice2<0) {
				angIndice2 += 0.5f;
			}
			break;
		case 'c':
			if (angIndice3>-90) {
				angIndice3 -= 0.5f;
			}
			break;
		case 'C':
			if (angIndice3<0) {
				angIndice3 += 0.5f;
			}
			break;
		case 'v':
			if (angMedio>-90) {
				angMedio -= 0.5f;
			}
			break;
		case 'V':
			if (angMedio<0) {
				angMedio += 0.5f;
			}
			break;
		case 'b':
			if (angMedio2>-90) {
				angMedio2 -= 0.5f;
			}
			break;
		case 'B':
			if (angMedio2<0) {
				angMedio2 += 0.5f;
			}
			break;
		case 'n':
			if (angMedio3>-90) {
				angMedio3 -= 0.5f;
			}
			break;
		case 'N':
			if (angMedio3<0) {
				angMedio3 += 0.5f;
			}
			break;
		case 'f':
			if (angAnular>-90) {
				angAnular -= 0.5f;
			}
			break;
		case 'F':
			if (angAnular<0) {
				angAnular += 0.5f;
			}
			break;
		case 'g':
			if (angAnular2>-90) {
				angAnular2 -= 0.5f;
			}
			break;
		case 'G':
			if (angAnular2<0) {
				angAnular2 += 0.5f;
			}
			break;
		case 'h':
			if (angAnular3>-90) {
				angAnular3 -= 0.5f;
			}
			break;
		case 'H':
			if (angAnular3<0) {
				angAnular3 += 0.5f;
			}
			break;
		case 'j':
			if (angMeñique>-90) {
				angMeñique -= 0.5f;
			}
			break;
		case 'J':
			if (angMeñique<0) {
				angMeñique += 0.5f;
			}
			break;
		case 'k':
			if (angMeñique2>-90) {
				angMeñique2 -= 0.5f;
			}
			break;
		case 'K':
			if (angMeñique2<0) {
				angMeñique2 += 0.5f;
			}
			break;
		case 'l':
			if (angMeñique3>-90) {
				angMeñique3 -= 0.5f;
			}
			break;
		case 'L':
			if (angMeñique3<0) {
				angMeñique3 += 0.5f;
			}
			break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}

