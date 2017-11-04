//Semestre 2018 - 1
//Alumno (s): Gutiérrez Benítez David Fernando

#include "Main.h"
#include "texture.h"
#include "figuras.h"
#include "Camera.h"

float posX = 0, posY = 2.5, posZ = -3.5;

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

#define MAX_FRAMES 60
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float angHombro;
	float angHombroInc;
	float angCodo;
	float angCodoInc;
	float angMano;
	float angManoInc;
	float angPulgar;
	float angPulgarInc;
	float angPulgar2;
	float angPulgar2Inc;
	float angIndice;
	float angIndiceInc;
	float angIndice2;
	float angIndice2Inc;
	float angIndice3;
	float angIndice3Inc;
	float angMedio;
	float angMedioInc;
	float angMedio2;
	float angMedio2Inc;
	float angMedio3;
	float angMedio3Inc;
	float angAnular;
	float angAnularInc;
	float angAnular2;
	float angAnular2Inc;
	float angAnular3;
	float angAnular3Inc;
	float angMeñique;
	float angMeñiqueInc;
	float angMeñique2;
	float angMeñique2Inc;
	float angMeñique3;
	float angMeñique3Inc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;
	KeyFrame[0].angHombro = 0;
	KeyFrame[0].angCodo = 0;
	KeyFrame[0].angMano = 0;
	KeyFrame[0].angPulgar = 0;
	KeyFrame[0].angPulgar2 = 0;
	KeyFrame[0].angIndice = 0;
	KeyFrame[0].angIndice2 = 0;
	KeyFrame[0].angIndice3 = 0;
	KeyFrame[0].angMedio = 0;
	KeyFrame[0].angMedio2 = 0;
	KeyFrame[0].angMedio3 = 0;
	KeyFrame[0].angAnular = 0;
	KeyFrame[0].angAnular2 = 0;
	KeyFrame[0].angAnular3 =0;
	KeyFrame[0].angMeñique = 0;
	KeyFrame[0].angMeñique2 = 0;
	KeyFrame[0].angMeñique3 = 0;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[1].angHombro = 0;
	KeyFrame[1].angCodo = 0;
	KeyFrame[1].angMano = 0;
	KeyFrame[1].angPulgar = 0;
	KeyFrame[1].angPulgar2 = 0;
	KeyFrame[1].angIndice = 0;
	KeyFrame[1].angIndice2 = 0;
	KeyFrame[1].angIndice3 = 0;
	KeyFrame[1].angMedio = 0;
	KeyFrame[1].angMedio2 = 0;
	KeyFrame[1].angMedio3 = 0;
	KeyFrame[1].angAnular = 0;
	KeyFrame[1].angAnular2 = 0;
	KeyFrame[1].angAnular3 = 0;
	KeyFrame[1].angMeñique = 0;
	KeyFrame[1].angMeñique2 = 0;
	KeyFrame[1].angMeñique3 = 0;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[2].angHombro = 0;
	KeyFrame[2].angCodo = 0;
	KeyFrame[2].angMano = 0;
	KeyFrame[2].angPulgar = -10;
	KeyFrame[2].angPulgar2 = 0;
	KeyFrame[2].angIndice = -10;
	KeyFrame[2].angIndice2 = -10;
	KeyFrame[2].angIndice3 = -10;
	KeyFrame[2].angMedio = -10;
	KeyFrame[2].angMedio2 = -10;
	KeyFrame[2].angMedio3 = -10;
	KeyFrame[2].angAnular = -10;
	KeyFrame[2].angAnular2 = -10;
	KeyFrame[2].angAnular3 = -10;
	KeyFrame[2].angMeñique = -10;
	KeyFrame[2].angMeñique2 = -10;
	KeyFrame[2].angMeñique3 = -10;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[3].angHombro = 0;
	KeyFrame[3].angCodo = 0;
	KeyFrame[3].angMano = 0;
	KeyFrame[3].angPulgar = -20;
	KeyFrame[3].angPulgar2 = 0;
	KeyFrame[3].angIndice = -20;
	KeyFrame[3].angIndice2 = -20;
	KeyFrame[3].angIndice3 = -20;
	KeyFrame[3].angMedio = -20;
	KeyFrame[3].angMedio2 = -20;
	KeyFrame[3].angMedio3 = -20;
	KeyFrame[3].angAnular = -20;
	KeyFrame[3].angAnular2 = -20;
	KeyFrame[3].angAnular3 = -20;
	KeyFrame[3].angMeñique = -20;
	KeyFrame[3].angMeñique2 =-20;
	KeyFrame[3].angMeñique3 = -20;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[4].angHombro = 0;
	KeyFrame[4].angCodo = 0;
	KeyFrame[4].angMano = 0;
	KeyFrame[4].angPulgar = -30;
	KeyFrame[4].angPulgar2 = 0;
	KeyFrame[4].angIndice = -30;
	KeyFrame[4].angIndice2 = -30;
	KeyFrame[4].angIndice3 = -30;
	KeyFrame[4].angMedio = -30;
	KeyFrame[4].angMedio2 = -30;
	KeyFrame[4].angMedio3 = -30;
	KeyFrame[4].angAnular = -30;
	KeyFrame[4].angAnular2 = -30;
	KeyFrame[4].angAnular3 = -30;
	KeyFrame[4].angMeñique = -30;
	KeyFrame[4].angMeñique2 = -30;
	KeyFrame[4].angMeñique3 = -30;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[5].angHombro = 0;
	KeyFrame[5].angCodo = 0;
	KeyFrame[5].angMano = 0;
	KeyFrame[5].angPulgar = -40;
	KeyFrame[5].angPulgar2 = 0;
	KeyFrame[5].angIndice = -40;
	KeyFrame[5].angIndice2 = -40;
	KeyFrame[5].angIndice3 = -40;
	KeyFrame[5].angMedio = -40;
	KeyFrame[5].angMedio2 = -40;
	KeyFrame[5].angMedio3 = -40;
	KeyFrame[5].angAnular = -40;
	KeyFrame[5].angAnular2 = -40;
	KeyFrame[5].angAnular3 = -40;
	KeyFrame[5].angMeñique = -40;
	KeyFrame[5].angMeñique2 = -40;
	KeyFrame[5].angMeñique3 = -40;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[6].angHombro = 0;
	KeyFrame[6].angCodo = 0;
	KeyFrame[6].angMano = 0;
	KeyFrame[6].angPulgar = -50;
	KeyFrame[6].angPulgar2 = 0;
	KeyFrame[6].angIndice = -50;
	KeyFrame[6].angIndice2 = -50;
	KeyFrame[6].angIndice3 = -50;
	KeyFrame[6].angMedio = -50;
	KeyFrame[6].angMedio2 = -50;
	KeyFrame[6].angMedio3 = -50;
	KeyFrame[6].angAnular = -50;
	KeyFrame[6].angAnular2 = -50;
	KeyFrame[6].angAnular3 = -50;
	KeyFrame[6].angMeñique = -50;
	KeyFrame[6].angMeñique2 = -50;
	KeyFrame[6].angMeñique3 = -50;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[7].angHombro = 0;
	KeyFrame[7].angCodo = 0;
	KeyFrame[7].angMano = 0;
	KeyFrame[7].angPulgar = -60;
	KeyFrame[7].angPulgar2 = 0;
	KeyFrame[7].angIndice = -60;
	KeyFrame[7].angIndice2 = -60;
	KeyFrame[7].angIndice3 = -60;
	KeyFrame[7].angMedio = -60;
	KeyFrame[7].angMedio2 = -60;
	KeyFrame[7].angMedio3 = -60;
	KeyFrame[7].angAnular = -60;
	KeyFrame[7].angAnular2 = -60;
	KeyFrame[7].angAnular3 = -60;
	KeyFrame[7].angMeñique = -60;
	KeyFrame[7].angMeñique2 = -60;
	KeyFrame[7].angMeñique3 = -60;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[8].angHombro = 0;
	KeyFrame[8].angCodo = 0;
	KeyFrame[8].angMano = 0;
	KeyFrame[8].angPulgar = -70;
	KeyFrame[8].angPulgar2 = 0;
	KeyFrame[8].angIndice = -70;
	KeyFrame[8].angIndice2 = -70;
	KeyFrame[8].angIndice3 = -70;
	KeyFrame[8].angMedio = -70;
	KeyFrame[8].angMedio2 = -70;
	KeyFrame[8].angMedio3 = -70;
	KeyFrame[8].angAnular = -70;
	KeyFrame[8].angAnular2 = -70;
	KeyFrame[8].angAnular3 = -70;
	KeyFrame[8].angMeñique = -70;
	KeyFrame[8].angMeñique2 = -70;
	KeyFrame[8].angMeñique3 = -70;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[9].angHombro = 0;
	KeyFrame[9].angCodo = 0;
	KeyFrame[9].angMano = 0;
	KeyFrame[9].angPulgar = -80;
	KeyFrame[9].angPulgar2 = 0;
	KeyFrame[9].angIndice = -80;
	KeyFrame[9].angIndice2 = -80;
	KeyFrame[9].angIndice3 = -80;
	KeyFrame[9].angMedio = -80;
	KeyFrame[9].angMedio2 = -80;
	KeyFrame[9].angMedio3 = -80;
	KeyFrame[9].angAnular = -80;
	KeyFrame[9].angAnular2 = -80;
	KeyFrame[9].angAnular3 = -80;
	KeyFrame[9].angMeñique = -80;
	KeyFrame[9].angMeñique2 = -80;
	KeyFrame[9].angMeñique3 = -80;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[10].angHombro = 0;
	KeyFrame[10].angCodo = 0;
	KeyFrame[10].angMano = 0;
	KeyFrame[10].angPulgar = -90;
	KeyFrame[10].angPulgar2 = 0;
	KeyFrame[10].angIndice = -90;
	KeyFrame[10].angIndice2 = -90;
	KeyFrame[10].angIndice3 = -90;
	KeyFrame[10].angMedio = -90;
	KeyFrame[10].angMedio2 = -90;
	KeyFrame[10].angMedio3 = -90;
	KeyFrame[10].angAnular = -90;
	KeyFrame[10].angAnular2 = -90;
	KeyFrame[10].angAnular3 = -90;
	KeyFrame[10].angMeñique = -90;
	KeyFrame[10].angMeñique2 = -90;
	KeyFrame[10].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[11].angHombro = 0;
	KeyFrame[11].angCodo = 0;
	KeyFrame[11].angMano = 0;
	KeyFrame[11].angPulgar = -90;
	KeyFrame[11].angPulgar2 = 0;
	KeyFrame[11].angIndice = -90;
	KeyFrame[11].angIndice2 = -90;
	KeyFrame[11].angIndice3 = -90;
	KeyFrame[11].angMedio = -90;
	KeyFrame[11].angMedio2 = -90;
	KeyFrame[11].angMedio3 = -90;
	KeyFrame[11].angAnular = -90;
	KeyFrame[11].angAnular2 = -90;
	KeyFrame[11].angAnular3 = -90;
	KeyFrame[11].angMeñique = -90;
	KeyFrame[11].angMeñique2 = -90;
	KeyFrame[11].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[12].angHombro = 0;
	KeyFrame[12].angCodo = 0;
	KeyFrame[12].angMano = 0;
	KeyFrame[12].angPulgar = -90;
	KeyFrame[12].angPulgar2 = 0;
	KeyFrame[12].angIndice = -70;
	KeyFrame[12].angIndice2 = -70;
	KeyFrame[12].angIndice3 = -70;
	KeyFrame[12].angMedio = -70;
	KeyFrame[12].angMedio2 = -70;
	KeyFrame[12].angMedio3 = -70;
	KeyFrame[12].angAnular = -90;
	KeyFrame[12].angAnular2 = -90;
	KeyFrame[12].angAnular3 = -90;
	KeyFrame[12].angMeñique = -90;
	KeyFrame[12].angMeñique2 = -90;
	KeyFrame[12].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[13].angHombro = 0;
	KeyFrame[13].angCodo = 0;
	KeyFrame[13].angMano = 0;
	KeyFrame[13].angPulgar = -90;
	KeyFrame[13].angPulgar2 = 0;
	KeyFrame[13].angIndice = -50;
	KeyFrame[13].angIndice2 = -50;
	KeyFrame[13].angIndice3 = -50;
	KeyFrame[13].angMedio = -50;
	KeyFrame[13].angMedio2 = -50;
	KeyFrame[13].angMedio3 = -50;
	KeyFrame[13].angAnular = -90;
	KeyFrame[13].angAnular2 = -90;
	KeyFrame[13].angAnular3 = -90;
	KeyFrame[13].angMeñique = -90;
	KeyFrame[13].angMeñique2 = -90;
	KeyFrame[13].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[14].angHombro = 0;
	KeyFrame[14].angCodo = 0;
	KeyFrame[14].angMano = 0;
	KeyFrame[14].angPulgar = -90;
	KeyFrame[14].angPulgar2 = 0;
	KeyFrame[14].angIndice = -30;
	KeyFrame[14].angIndice2 = -30;
	KeyFrame[14].angIndice3 = -30;
	KeyFrame[14].angMedio = -30;
	KeyFrame[14].angMedio2 = -30;
	KeyFrame[14].angMedio3 = -30;
	KeyFrame[14].angAnular = -90;
	KeyFrame[14].angAnular2 = -90;
	KeyFrame[14].angAnular3 = -90;
	KeyFrame[14].angMeñique = -90;
	KeyFrame[14].angMeñique2 = -90;
	KeyFrame[14].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[15].angHombro = 0;
	KeyFrame[15].angCodo = 0;
	KeyFrame[15].angMano = 0;
	KeyFrame[15].angPulgar = -90;
	KeyFrame[15].angPulgar2 = 0;
	KeyFrame[15].angIndice = 0;
	KeyFrame[15].angIndice2 = 0;
	KeyFrame[15].angIndice3 = 0;
	KeyFrame[15].angMedio = 0;
	KeyFrame[15].angMedio2 = 0;
	KeyFrame[15].angMedio3 = 0;
	KeyFrame[15].angAnular = -90;
	KeyFrame[15].angAnular2 = -90;
	KeyFrame[15].angAnular3 = -90;
	KeyFrame[15].angMeñique = -90;
	KeyFrame[15].angMeñique2 = -90;
	KeyFrame[15].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[16].angHombro = 0;
	KeyFrame[16].angCodo = 0;
	KeyFrame[16].angMano = 0;
	KeyFrame[16].angPulgar = -90;
	KeyFrame[16].angPulgar2 = 0;
	KeyFrame[16].angIndice = 0;
	KeyFrame[16].angIndice2 = 0;
	KeyFrame[16].angIndice3 = 0;
	KeyFrame[16].angMedio = 0;
	KeyFrame[16].angMedio2 = 0;
	KeyFrame[16].angMedio3 = 0;
	KeyFrame[16].angAnular = -90;
	KeyFrame[16].angAnular2 = -90;
	KeyFrame[16].angAnular3 = -90;
	KeyFrame[16].angMeñique = -90;
	KeyFrame[16].angMeñique2 = -90;
	KeyFrame[16].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[17].angHombro = 0;
	KeyFrame[17].angCodo = 0;
	KeyFrame[17].angMano = 0;
	KeyFrame[17].angPulgar = -70;
	KeyFrame[17].angPulgar2 = 0;
	KeyFrame[17].angIndice = -30;
	KeyFrame[17].angIndice2 = -30;
	KeyFrame[17].angIndice3 = -30;
	KeyFrame[17].angMedio = -30;
	KeyFrame[17].angMedio2 = -30;
	KeyFrame[17].angMedio3 = -30;
	KeyFrame[17].angAnular = -90;
	KeyFrame[17].angAnular2 = -90;
	KeyFrame[17].angAnular3 = -90;
	KeyFrame[17].angMeñique = -90;
	KeyFrame[17].angMeñique2 = -90;
	KeyFrame[17].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[18].angHombro = 0;
	KeyFrame[18].angCodo = 0;
	KeyFrame[18].angMano = 0;
	KeyFrame[18].angPulgar = -50;
	KeyFrame[18].angPulgar2 = 0;
	KeyFrame[18].angIndice = -50;
	KeyFrame[18].angIndice2 = -50;
	KeyFrame[18].angIndice3 = -50;
	KeyFrame[18].angMedio = -50;
	KeyFrame[18].angMedio2 = -50;
	KeyFrame[18].angMedio3 = -50;
	KeyFrame[18].angAnular = -90;
	KeyFrame[18].angAnular2 = -90;
	KeyFrame[18].angAnular3 = -90;
	KeyFrame[18].angMeñique = -90;
	KeyFrame[18].angMeñique2 = -90;
	KeyFrame[18].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[19].angHombro = 0;
	KeyFrame[19].angCodo = 0;
	KeyFrame[19].angMano = 0;
	KeyFrame[19].angPulgar = -30;
	KeyFrame[19].angPulgar2 = 0;
	KeyFrame[19].angIndice = -70;
	KeyFrame[19].angIndice2 = -70;
	KeyFrame[19].angIndice3 = -70;
	KeyFrame[19].angMedio = -70;
	KeyFrame[19].angMedio2 = -70;
	KeyFrame[19].angMedio3 = -70;
	KeyFrame[19].angAnular = -90;
	KeyFrame[19].angAnular2 = -90;
	KeyFrame[19].angAnular3 = -90;
	KeyFrame[19].angMeñique = -90;
	KeyFrame[19].angMeñique2 = -90;
	KeyFrame[19].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[20].angHombro = 0;
	KeyFrame[20].angCodo = 0;
	KeyFrame[20].angMano = 0;
	KeyFrame[20].angPulgar = -0;
	KeyFrame[20].angPulgar2 = 0;
	KeyFrame[20].angIndice = -90;
	KeyFrame[20].angIndice2 = -90;
	KeyFrame[20].angIndice3 = -90;
	KeyFrame[20].angMedio = -90;
	KeyFrame[20].angMedio2 = -90;
	KeyFrame[20].angMedio3 = -90;
	KeyFrame[20].angAnular = -90;
	KeyFrame[20].angAnular2 = -90;
	KeyFrame[20].angAnular3 = -90;
	KeyFrame[20].angMeñique = -90;
	KeyFrame[20].angMeñique2 = -90;
	KeyFrame[20].angMeñique3 = -90;
	FrameIndex++;

	printf("frameindex %d\n", FrameIndex);
	KeyFrame[21].angHombro = 0;
	KeyFrame[21].angCodo = 0;
	KeyFrame[21].angMano = 0;
	KeyFrame[21].angPulgar = -0;
	KeyFrame[21].angPulgar2 = 0;
	KeyFrame[21].angIndice = -90;
	KeyFrame[21].angIndice2 = -90;
	KeyFrame[21].angIndice3 = -90;
	KeyFrame[21].angMedio = -90;
	KeyFrame[21].angMedio2 = -90;
	KeyFrame[21].angMedio3 = -90;
	KeyFrame[21].angAnular = -90;
	KeyFrame[21].angAnular2 = -90;
	KeyFrame[21].angAnular3 = -90;
	KeyFrame[21].angMeñique = -90;
	KeyFrame[21].angMeñique2 = -90;
	KeyFrame[21].angMeñique3 = -90;
	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	angHombro = KeyFrame[0].angHombro;
	angCodo = KeyFrame[0].angCodo;
	angMano = KeyFrame[0].angMano;
	angPulgar = KeyFrame[0].angPulgar;
	angPulgar2 = KeyFrame[0].angPulgar2;
	angIndice = KeyFrame[0].angIndice;
	angIndice2 = KeyFrame[0].angIndice2;
	angIndice3 = KeyFrame[0].angIndice3;
	angMedio = KeyFrame[0].angMedio;
	angMedio2 = KeyFrame[0].angMedio2;
	angMedio3 = KeyFrame[0].angMedio3;
	angAnular = KeyFrame[0].angAnular;
	angAnular2 = KeyFrame[0].angAnular2;
	angAnular3 = KeyFrame[0].angAnular3;
	angMeñique = KeyFrame[0].angMeñique;
	angMeñique2 = KeyFrame[0].angMeñique2;
	angMeñique3 = KeyFrame[0].angMeñique3;
}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].angHombroInc = (KeyFrame[playIndex + 1].angHombro - KeyFrame[playIndex].angHombro) / i_max_steps;
	KeyFrame[playIndex].angCodoInc = (KeyFrame[playIndex + 1].angCodo - KeyFrame[playIndex].angCodo) / i_max_steps;
	KeyFrame[playIndex].angManoInc = (KeyFrame[playIndex + 1].angMano - KeyFrame[playIndex].angMano) / i_max_steps;
	KeyFrame[playIndex].angPulgarInc = (KeyFrame[playIndex + 1].angPulgar - KeyFrame[playIndex].angPulgar) / i_max_steps;
	KeyFrame[playIndex].angPulgar2Inc = (KeyFrame[playIndex + 1].angPulgar2 - KeyFrame[playIndex].angPulgar2) / i_max_steps;
	KeyFrame[playIndex].angIndiceInc = (KeyFrame[playIndex + 1].angIndice - KeyFrame[playIndex].angIndice) / i_max_steps;
	KeyFrame[playIndex].angIndice2Inc = (KeyFrame[playIndex + 1].angIndice2 - KeyFrame[playIndex].angIndice2) / i_max_steps;
	KeyFrame[playIndex].angIndice3Inc = (KeyFrame[playIndex + 1].angIndice3 - KeyFrame[playIndex].angIndice3) / i_max_steps;
	KeyFrame[playIndex].angMedioInc = (KeyFrame[playIndex + 1].angMedio - KeyFrame[playIndex].angMedio) / i_max_steps;
	KeyFrame[playIndex].angMedio2Inc = (KeyFrame[playIndex + 1].angMedio2 - KeyFrame[playIndex].angMedio2) / i_max_steps;
	KeyFrame[playIndex].angMedio3Inc = (KeyFrame[playIndex + 1].angMedio3 - KeyFrame[playIndex].angMedio3) / i_max_steps;
	KeyFrame[playIndex].angAnularInc = (KeyFrame[playIndex + 1].angAnular - KeyFrame[playIndex].angAnular) / i_max_steps;
	KeyFrame[playIndex].angAnular2Inc = (KeyFrame[playIndex + 1].angAnular2 - KeyFrame[playIndex].angAnular2) / i_max_steps;
	KeyFrame[playIndex].angAnular3Inc = (KeyFrame[playIndex + 1].angAnular3 - KeyFrame[playIndex].angAnular3) / i_max_steps;
	KeyFrame[playIndex].angMeñiqueInc = (KeyFrame[playIndex + 1].angMeñique - KeyFrame[playIndex].angMeñique) / i_max_steps;
	KeyFrame[playIndex].angMeñique2Inc = (KeyFrame[playIndex + 1].angMeñique2 - KeyFrame[playIndex].angMeñique2) / i_max_steps;
	KeyFrame[playIndex].angMeñique3Inc = (KeyFrame[playIndex + 1].angMeñique3 - KeyFrame[playIndex].angMeñique3) / i_max_steps;
}

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
		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void animacion()
{
	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq<-1)
		fig3.text_izq = 0;
	if (fig3.text_der<0)
		fig3.text_der = 1;

	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			angHombro += KeyFrame[playIndex].angHombroInc;
			angCodo += KeyFrame[playIndex].angCodoInc;
			angMano += KeyFrame[playIndex].angManoInc;
			angPulgar += KeyFrame[playIndex].angPulgarInc;
			angPulgar2 += KeyFrame[playIndex].angPulgar2Inc;
			angIndice += KeyFrame[playIndex].angIndiceInc;
			angIndice2 += KeyFrame[playIndex].angIndice2Inc;
			angIndice3 += KeyFrame[playIndex].angIndice3Inc;
			angMedio += KeyFrame[playIndex].angMedioInc;
			angMedio2 += KeyFrame[playIndex].angMedio2Inc;
			angMedio3 += KeyFrame[playIndex].angMedio3Inc;
			angAnular += KeyFrame[playIndex].angAnularInc;
			angAnular2 += KeyFrame[playIndex].angAnular2Inc;
			angAnular3 += KeyFrame[playIndex].angAnular3Inc;
			angMeñique += KeyFrame[playIndex].angMeñiqueInc;
			angMeñique2 += KeyFrame[playIndex].angMeñique2Inc;
			angMeñique3 += KeyFrame[playIndex].angMeñique3Inc;

			i_curr_steps++;
		}

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
		case 'q':		//
		case 'Q':
			if (FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'e':
		case 'E':
			if (play == false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
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

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}

void menu(int id)
{

}

int main ( int argc, char** argv )   // Main Function
{
	int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc(animacion);

  submenu = glutCreateMenu(menuKeyFrame);
  glutAddMenuEntry("Guardar KeyFrame", 0);
  glutAddMenuEntry("Reproducir Animacion", 1);
  glutCreateMenu(menu);
  glutAddSubMenu("Animacion Monito", submenu);

  glutAttachMenu(GLUT_RIGHT_BUTTON);


  glutMainLoop();          // 


  return 0;
}

