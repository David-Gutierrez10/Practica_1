//Semestre 2018 - 1
//Alumno (s): Gutiérrez Benítez David Fernando

#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio=0;
int venus=0;
int tierra=0;
int luna=0;
int marte=0;
int jupiter=0;
int saturno=0;
int urano=0;
int neptuno=0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MercurioDiffuse[]= {0.545f,0.271f,0.075f , 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[]= { 0.957f,0.643f,0.376f, 1.0f };			// venus
GLfloat VenusSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 1.0f, 0.0f, 0.0f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.93f,0.943f,0.576f, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 0.957f,0.643f,0.376f, 1.0f };			// Saturno
GLfloat SaturnoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.0f,0.0f,0.5f , 1.0f };			// Urano
GLfloat UranoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NeptunoDiffuse[] = { 0.5f,0.0f,1.0f , 1.0f };			// Neptuno
GLfloat NeptunoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NeptunoShininess[] = { 50.0 };

GLfloat Aro1Diffuse[] = { 0.0f,0.5f,0.5f , 1.0f };			// Aro1
GLfloat Aro1Specular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat Aro1Shininess[] = { 50.0 };

GLfloat Aro2Diffuse[] = { 0.0f,1.0f,1.0f , 1.0f };			// Aro2
GLfloat Aro2Specular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat Aro2Shininess[] = { 50.0 };


void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	
	glLightfv(GL_LIGHT1,GL_DIFFUSE,SunDiffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,SunSpecular);

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glPushMatrix();
		glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
		glColor3f( 0.9,0.7,0.0 );	//Sol amarillo
		glLightfv(GL_LIGHT1,GL_POSITION,SunPosition);	
		glDisable(GL_LIGHTING);
		glutSolidSphere(2.0,20,20);  //Draw Sun (radio,H,V);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	//mercurio
	glPushMatrix();
		glColor3f(0.545,0.271,0.075);
		glRotatef(mercurio,0.0,1.0,1.0);
		glTranslatef(2.5,0.2,0.2);
		glRotatef(mercurio+2,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,MercurioDiffuse);
		glMaterialfv(GL_FRONT,GL_SPECULAR,MercurioSpecular);
		glMaterialfv(GL_FRONT,GL_SHININESS,MercurioShininess);
		glutSolidSphere(0.3,10,10);
	glPopMatrix();
	//venus
	glPushMatrix();
		glColor3f(0.957,0.643,0.376);
		glRotatef(venus,0.0,-1.0,0.5);
		glTranslatef(3.5,0.2,0.2);
		glRotatef(venus+2,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
		glutSolidSphere(0.4,10,10);
	glPopMatrix();
	//tierra
	glPushMatrix();
		glColor3f(0.0,0.0,0.5);
		glRotatef(tierra,0.0,0.7,-0.4);
		glTranslatef(4.8,0.2,0.2);
		glPushMatrix();
			glRotatef(tierra+2,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,EarthDiffuse);
			glMaterialfv(GL_FRONT,GL_SPECULAR,EarthSpecular);
			glMaterialfv(GL_FRONT,GL_SHININESS,EarthShininess);
			glutSolidSphere(0.6,10,10);
		glPopMatrix();
		//Luna
		glPushMatrix();
			glColor3f(0.5,0.5,0.5);
			//traslacion
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.0,0.8,0.2);
			//rotacion
			glRotatef(luna+2,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);
			glutSolidSphere(0.1,10,10);
		glPopMatrix();
	glPopMatrix();
	//marte
	glPushMatrix();
		glColor3f(1.0,0.0,0.0);
		glRotatef(marte,0.0,0.8,0.7);
		glTranslatef(6.7,0.2,0.2);
		glRotatef(marte+2,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,MarsDiffuse);
		glMaterialfv(GL_FRONT,GL_SPECULAR,MarsSpecular);
		glMaterialfv(GL_FRONT,GL_SHININESS,MarsShininess);
		glutSolidSphere(0.7,10,10);
	glPopMatrix();
	//jupiter
	glPushMatrix();
		glColor3f(0.93,0.943,0.576);
		glRotatef(jupiter,-1.0,0.0,0.5);
		glTranslatef(0.2,6.4,0.2);
		glPushMatrix();
			glRotatef(jupiter+2,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
			glutSolidSphere(1.4,10,10);
		glPopMatrix();
		glPushMatrix();
			//luna1
			glColor3f(0.5,0.5,0.5);
			//traslacion
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.0,1.6,0.2);
			//rotacion
			glRotatef(luna+2,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.2,10,10);
		glPopMatrix();
		glPushMatrix();
			//luna2
			glColor3f(0.5,0.5,0.5);
			//traslacion
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.0,-1.6,0.2);
			//rotacion
			glRotatef(luna+2,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.3,10,10);
		glPopMatrix();
	glPopMatrix();
	//saturno
	glPushMatrix();
		glColor3f(0.957,0.643,0.376);
		glRotatef(saturno,0.0,-1.0,1.0);
		glTranslatef(7.5,0.2,0.2);
		glPushMatrix();
			glRotatef(saturno+2,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
			glutSolidSphere(0.9,10,10);
		glPopMatrix();
		glPushMatrix();
			//luna1
			glColor3f(0.5,0.5,0.5);
			//traslacion
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.0,1.6,0.2);
			//rotacion
			glRotatef(luna+2,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.2,10,10);
		glPopMatrix();
		glPushMatrix();
			//luna2
			glColor3f(0.5,0.5,0.5);
			//traslacion
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.0,-1.6,0.2);
			//rotacion
			glRotatef(luna+2,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.2,10,10);
		glPopMatrix();
		glPushMatrix();
			//aro1
			glColor3f(0.0,0.5,0.5);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Aro1Diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Aro1Specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, Aro1Shininess);
			glutWireTorus(0.1,1.4,10,10);
		glPopMatrix();
		glPushMatrix();
			//aro2
			glColor3f(0.0,1.0,1.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Aro2Diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Aro2Specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, Aro2Shininess);
			glutWireTorus(0.1,1.1,10,10);
		glPopMatrix();
	glPopMatrix();
	//urano
	glPushMatrix();
		glColor3f(0.0,0.0,0.5);
		glRotatef(urano,0.0,-1.0,-0.5);
		glTranslatef(7.8,0.2,0.2);
		glRotatef(urano+2,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
		glutSolidSphere(0.8,10,10);
	glPopMatrix();
	//neptuno
	glPushMatrix();
		glColor3f(0.5,0.0,1.0);
		glRotatef(jupiter,0.0,1.0,0.0);
		glTranslatef(7.0,0.2,0.2);
		glRotatef(jupiter+2,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, NeptunoSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, NeptunoShininess);
		glutSolidSphere(0.7,10,10);
	glPopMatrix();
	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		mercurio = (mercurio - 9) % 360;

		dwLastUpdateTime = dwCurrentTime;

		venus = (venus - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;

		tierra = (tierra - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;

		luna = (luna - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;

		marte = (marte - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;

		jupiter = (jupiter - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		saturno = (saturno - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;

		urano = (urano - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;

		neptuno = (neptuno - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}