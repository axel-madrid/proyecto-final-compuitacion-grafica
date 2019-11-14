//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

CCamera objCamera;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;
int ventil = 0;
int rot = 0;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

CTexture text1;
CTexture text2;
CTexture pantalla1;
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture fachadaPrincipal;
CTexture fachadaParedes;
CTexture ventana1;
CTexture piso;
CTexture textint;/////textura interior de nubles
CTexture alfombra;
CTexture techo;
CTexture marcoposter;
CTexture poster;
CTexture lampn;
CTexture lampp;
CTexture lino;
CTexture madera;
CTexture maderablanca;
CTexture negro;
CTexture pantalla;
CTexture cama;
CTexture almohada;
CTexture pelota1;
CTexture venti;
CTexture mapamundi;


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;



CFiguras fig7; //Para el monito
CFiguras miobj;


//Figuras de 3D Studio
CModel kit;
CModel llanta;

//Animación del coche
float movKit = 0.0;
bool g_fanimacion = false;
bool g_animaicon = false;
bool aceptado = false;
bool recorrido1 = true;
bool recorrido2 = false;
float movh = -3.0;
float movv = 0.72;
static int spin = 0;

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	pantalla1.LoadTGA("pantalla1.tga");
	pantalla1.BuildGLTexture();
	pantalla1.ReleaseImage();


	marcoposter.LoadTGA("marcoposter.tga");
	marcoposter.BuildGLTexture();
	marcoposter.ReleaseImage();

	poster.LoadTGA("poster.tga");
	poster.BuildGLTexture();
	poster.ReleaseImage();

	mapamundi.LoadTGA("mapamundi.tga");
	mapamundi.BuildGLTexture();
	mapamundi.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	fachadaPrincipal.LoadTGA("fachadaprincipal.tga");
	fachadaPrincipal.BuildGLTexture();
	fachadaPrincipal.ReleaseImage();

	/////////////textura venti////////////////7
	venti.LoadTGA("venti.tga");
	venti.BuildGLTexture();
	venti.ReleaseImage();

	///////////////////////textura paredes///////////////////////////////////////

	fachadaParedes.LoadTGA("fachada.tga");
	fachadaParedes.BuildGLTexture();
	fachadaParedes.ReleaseImage();

	////////////////////////////ventanal////////////////////

	ventana1.LoadTGA("ventana1.tga");
	ventana1.BuildGLTexture();
	ventana1.ReleaseImage();

	/////////////////////////////////////piso///////////////////////////

	piso.LoadTGA("piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	////////////////////////////////textura derecha/////////////////////////////
	textint.LoadTGA("pared.tga");
	textint.BuildGLTexture();
	textint.ReleaseImage();

	///////////////////////////////alfombra///////////////////////////////

	alfombra.LoadTGA("alfombra.tga");
	alfombra.BuildGLTexture();
	alfombra.ReleaseImage();

	////////////////////////////////////////////////techo//////////////////////////////////////////

	techo.LoadTGA("techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	/////////////////////////////////lampara///////////////////////////////////////
	lampn.LoadTGA("negro.tga");
	lampn.BuildGLTexture();
	lampn.ReleaseImage();

	lampp.LoadTGA("plata.tga");
	lampp.BuildGLTexture();
	lampp.ReleaseImage();

	lino.LoadTGA("lino.tga");
	lino.BuildGLTexture();
	lino.ReleaseImage();
	//////////////////////textura muebles madera///////////////////////////

	madera.LoadTGA("madera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	maderablanca.LoadTGA("maderablanca.tga");
	maderablanca.BuildGLTexture();
	maderablanca.ReleaseImage();

	//////////////separacion de cajones/////////////77
	negro.LoadTGA("negro.tga");
	negro.BuildGLTexture();
	negro.ReleaseImage();


	pantalla.LoadTGA("pantalla.tga");
	pantalla.BuildGLTexture();
	pantalla.ReleaseImage();

	//////////////////texturas de la cama//////////////////
	cama.LoadTGA("cama.tga");
	cama.BuildGLTexture();
	cama.ReleaseImage();

	almohada.LoadTGA("almohada.tga");
	almohada.BuildGLTexture();
	almohada.ReleaseImage();

	////////////////////////textura de la pelota///////////////
	pelota1.LoadTGA("pelota1.tga");
	pelota1.BuildGLTexture();
	pelota1.ReleaseImage();


	///////////////////Carga de Figuras/////////////////////
	/*kit._3dsLoad("entradaC.3ds")*/;
	//kit.VertexNormals();

	//llanta._3dsLoad("k_rueda.3ds");


	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}



void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

	////////Creacion del cielo///////////////
	glPushMatrix();
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();

	////////////camino ///////////////
	glPushMatrix(); 
	glTranslatef(19.5, 0.0, 0.0);
	glScalef(48, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma2(text4.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); 
	glTranslatef(-23.5, 0.0, 0.0);
	glScalef(40, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma2(text4.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	////////////////pasto/////////////////
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, -4.0);
	glScalef(87, 0.1, 1);
	glDisable(GL_LIGHTING);
	fig4.prisma2(text5.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 4.0);
	glScalef(87, 0.1, 1);
	glDisable(GL_LIGHTING);
	fig4.prisma2(text5.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////////Pared fondo exterior///////
	glPushMatrix(); 
	glTranslatef(-3, 3.1, -17.4);
	glRotatef(270, 1, 0, 0);
	glScalef(12, 0.25, 6.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(fachadaParedes.GLindex, fachadaParedes.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////Pared del fondo interior////////
	glPushMatrix(); 
	glTranslatef(-3, 3.1, -17.2);
	glRotatef(-270, 1, 0, 0);
	glScalef(11.5, 0.05, 5.89);
	glDisable(GL_LIGHTING);
	fig5.prisma2(textint.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////ventana 1////////
	glPushMatrix(); 
	glTranslatef(-6, 3.1, -17.1);
	glRotatef(-270, 1, 0, 0);
	glScalef(2.5, 0.01, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(ventana1.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////ventana 2////////
	glPushMatrix();
	glTranslatef(-1.5, 3.1, -17.1);
	glRotatef(-270, 1, 0, 0);
	glScalef(2.5, 0.01, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(ventana1.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////////Pared entrada exterior/////////
	glPushMatrix(); 
	glTranslatef(-3.1, 3.0, -4.43);
	glRotatef(90, 1, 0, 0);
	glScalef(11.85, 0.05, 6.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(fachadaPrincipal.GLindex, fachadaPrincipal.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////////Pared entrada interior/////////////
	glPushMatrix(); 
	glTranslatef(-3, 3.0, -4.59);
	glRotatef(-180, 0, 90, 1);
	glRotatef(-90, -45, 0, 0);
	glScalef(11.6, 0.05, 5.93);
	glDisable(GL_LIGHTING);
	fig5.prisma2(textint.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////////Pared izquierda exterior///////////////
	glPushMatrix(); 
	glTranslatef(-8.9, 3.1, -11.0);
	//glTranslatef(-35.0, 3.2, -4.6);
	glRotatef(-90, 0, 90, 1);
	glRotatef(-90, -45, 0, 0);
	glScalef(13, 0.25, 6.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(fachadaParedes.GLindex, fachadaParedes.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////////Pared izquierda interior ///////////////
	glPushMatrix(); 
	glTranslatef(-8.7, 3.1, -11.0);
	glRotatef(-90, 0, 0, 1);
	glRotatef(-90, 0, -90, 0);
	glScalef(13, 0.05, 5.89);
	glDisable(GL_LIGHTING);
	fig5.prisma2(textint.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	////////////Pared derecha exterior///////////
	glPushMatrix(); 
	glTranslatef(2.89, 3.1, -11.0);
	glRotatef(-90, 0, 90, 1);
	glRotatef(90, -45, 0, 0);
	glScalef(13, 0.25, 6.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(fachadaParedes.GLindex, fachadaParedes.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////////Pared derecha interior///////////
	glPushMatrix(); 
	glTranslatef(2.7, 3.1, -11.0);
	glRotatef(-90, 0, 90, 1);
	glRotatef(-90, -45, 0, 0);
	glScalef(13, 0.05, 5.89);
	glDisable(GL_LIGHTING);
	fig5.prisma2(textint.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////techo///////////
	glPushMatrix(); 
	glTranslatef(-3, 6.05, -10.9);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 90, 0, 0);
	glScalef(11.6, 0.1, 12.85);
	glDisable(GL_LIGHTING);
	fig5.prisma2(techo.GLindex, fachadaParedes.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	////////////piso////////////
	glPushMatrix(); 
	glTranslatef(-3, 0.2, -11);
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 90, 0, 0);
	glScalef(12, 0.05, 13);
	glDisable(GL_LIGHTING);
	fig5.prisma2(piso.GLindex, fachadaParedes.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	///////////////alfombra /////////////////
    glPushMatrix(); 
	glTranslatef(-3, 0.3, -11);
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 90, 0, 0);
	glScalef(4, 0.05, 4);
	glDisable(GL_LIGHTING);
	fig5.prisma2(alfombra.GLindex, alfombra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	/////////////////////////////////muebles///////////////////////////////

	//////////////mueble para la lampara////////////////
	glPushMatrix();
	glTranslatef(-7.2f, 0.6f, -12.5f);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.prisma(0.7, 1.2, 1.2, maderablanca.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//////////////////////////////lampara////////////////////////////////////////////

	//////////////parte negra//////////////
	glPushMatrix();
	glTranslatef(-7.2f, 1.0f, -12.5f);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.cilindro(0.10, 0.5, 25, lampn.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//// parte plata//////
	glPushMatrix();
	glTranslatef(-7.2f, 1.5f, -12.5f);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.cilindro(0.10, 0.5, 25, lampp.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//////cabeza de la lampara//////
	glPushMatrix();
	glTranslatef(-7.2f, 2.0f, -12.5f);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.cilindro(0.4, 0.5, 25, lino.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	////////////////mueble esquinero derecho/////////////////////////

	////////parte trasera del mueble///////////////
	glPushMatrix();
	glTranslatef(1.1, 2.0, -16.35);
	glRotatef(90, 0, 1, 0);
	glScalef(0.2, 3.5, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//// parte izquierda/////////////

	glPushMatrix();
	glTranslatef(0.5, 2.1, -15.95);
	glScalef(0.2, 3.8, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////////parte derecha////////////////
	glPushMatrix();
	glTranslatef(1.7, 2.1, -15.95);
	glScalef(0.2, 3.8, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//////piso del mueble///////////

	glPushMatrix();
	glTranslatef(1.1, 0.3, -15.95);
	glScalef(1.0, 0.2, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////techo del mueble///////////
	glPushMatrix();
	glTranslatef(1.1, 3.8, -15.95);
	glScalef(1.0, 0.2, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////////divisiones del mueble ////////////////////
	glPushMatrix();
	glTranslatef(1.1, 1.2, -15.95);
	glScalef(1.0, 0.04, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.1, 2.1, -15.95);
	glScalef(1.0, 0.04, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.1, 3.0, -15.95);
	glScalef(1.0, 0.04, 1.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	////////// Mapamundi ////////

	glPushMatrix();
	glTranslatef(-7.2, 1.7, -10.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.cilindro(0.1, 0.3, 50, lampn.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.2, 2.42, -10.0);
	glRotatef(ventil, 0.0, 1.0, 0.0);
	glPushMatrix();
	glDisable(GL_LIGHTING);
	miobj.esfera(0.4f, 10.0f, 20.0f, mapamundi.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	//////////////////////////mueble medio ///////////////////////////

	glPushMatrix();
	glTranslatef(-7.2, 1.6, -10.0);
	glScalef(1.0, 0.3, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(maderablanca.GLindex, maderablanca.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glTranslatef(6.0, -1.3, 0.0);
    glPushMatrix();
	glTranslatef(1.2, 0.4, -10.0);
	glScalef(1.0, 0.3, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(maderablanca.GLindex, maderablanca.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.2, 0.5, -10.0);
	glScalef(1.0, 0.6, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(maderablanca.GLindex, maderablanca.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////lineas negras vericales para los cajones/////////////////

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -9.0);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -9.66);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -10.32);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -11.0);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	////////////Lineas negras horizontales de los cajones//////////
	glPushMatrix();
	glTranslatef(-6.7, 0.85, -10.0);
	glScalef(0.2, 0.04, 2.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.7, 0.35, -10.0);
	glScalef(0.2, 0.04, 2.0);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////manijas de los cajones///////////////

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -10.65);
	glScalef(0.2, 0.04, 0.15);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -9.99);
	glScalef(0.2, 0.04, 0.15);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.7, 0.6, -9.33);
	glScalef(0.2, 0.04, 0.15);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
    glPopMatrix();

//////////lineas negras verticales entre la base y la parte de abajo/////////////////

	glPushMatrix();
	glTranslatef(-7.3, 1.3, -9.0);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.3, 1.3, -9.66);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.3, 1.3, -10.32);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.3, 1.3, -11.0);
	glScalef(0.2, 0.5, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//////////////////pantalla////////////////////////////

	//////////////cuadro de la pantalla////////
	glPushMatrix();
	glTranslatef(2.45, 2.84, -12.3);
	glRotatef(90, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	miobj.prisma(3.11, 4.4, 0, pantalla.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	///////////////imagen de la pantalla ////////
	glPushMatrix();
	glTranslatef(2.45, 2.8, -12.3);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 0, 1, 0);
	glScalef(3.5, 0.02, 2);
	glDisable(GL_LIGHTING);
	fig3.prisma_anun(pantalla1.GLindex,0 );
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//////////////////poster/////////
	
	glPushMatrix();
	glTranslatef(-8.55, 4.523, -12.3);
	glRotatef(270, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glRotatef(90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	miobj.prisma(2.318, 2.53, 0, marcoposter.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-8.55, 4.5, -12.3);
	glRotatef(270, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glRotatef(90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	miobj.prisma(1.5, 2.0, 0, poster.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	

	//////////////////////////////////////////////////mueble derecho de la entrada ///////////////////////////////////////////////////
	/////base//// 
	glPushMatrix();
	glTranslatef(1.2, 0.4, -7.15);
	glScalef(1.0, 0.3, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////techo//////////
	glPushMatrix();
	glTranslatef(1.2, 3.6, -7.15);
	glScalef(1.0, 0.3, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////////////verticales izquierdo/////////
	glPushMatrix();
	glTranslatef(1.2, 2.0, -8.55);
	glScalef(1.0, 3.5, 0.3);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////verticales derecho///////////
	glPushMatrix();
	glTranslatef(1.2, 2.0, -6.0);
	glScalef(1.0, 3.5, 0.3);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////divisiones horizontales//////////
	glPushMatrix();
	glTranslatef(1.2, 2.15, -7.3);
	glScalef(1.0, 0.04, 2.3);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.2, 2.73, -7.3);
	glScalef(1.0, 0.04, 2.3);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////divisiones verticales///////
	glPushMatrix();
	glTranslatef(1.2, 2.45, -7.2);
	glScalef(1.0, 0.6, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 3.09, -7.6);
	glScalef(1.0, 0.7, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 3.09, -6.8);
	glScalef(1.0, 0.7, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.2, 1.25, -6.9);
	glScalef(1.0, 1.75, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 1.25, -7.65);
	glScalef(1.0, 1.75, 0.04);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////////cajones//////////////
	glPushMatrix();
	glTranslatef(1.2, 1.3, -6.52);
	glScalef(1.0, 0.3, 0.75);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0.7, -7.3);
	glScalef(1.0, 0.3, 0.74);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 1.0, -7.3);
	glScalef(1.0, 0.3, 0.74);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 1.3, -8.02);
	glScalef(1.0, 0.3, 0.7);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////////////////manijas de cajones////////////////////////////

	glPushMatrix();
	glTranslatef(1.1, 1.3, -6.52);
	glScalef(1.0, 0.06, 0.2);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.1, 0.7, -7.3);
	glScalef(1.0, 0.06, 0.2);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.1, 1.0, -7.3);
	glScalef(1.0, 0.06, 0.2);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.1, 0.85, -7.3);
	glScalef(1.0, 0.03, 0.74);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.1, 1.3, -8.02);
	glScalef(1.0, 0.06, 0.2);
	glDisable(GL_LIGHTING);
	fig5.prisma2(negro.GLindex, negro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	/////////////////////cama /////////////////////////// 

	///////base//////////
	glPushMatrix();
	glTranslatef(-4.7, 0.7, -14.8);
	glScalef(5.0, 1.0, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////// cabeceras ////////////
	glPushMatrix();
	glTranslatef(-2.0, 1.0, -14.8);
	glScalef(0.4, 1.4, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.4, 1.5, -14.8);
	glScalef(0.4, 2.5, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(madera.GLindex, madera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////////// cobija /////////////
	glPushMatrix();
	glTranslatef(-4.7, 1.4, -14.8);
	glScalef(5.0, 0.4, 2.5);
	glDisable(GL_LIGHTING);
	fig5.prisma2(cama.GLindex, cama.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	/////////almohada/////////////
	glPushMatrix();
	glTranslatef(-6.8, 1.7, -14.8);
	glScalef(0.5, 0.18, 1.3);
	glDisable(GL_LIGHTING);
	fig5.prisma2(almohada.GLindex, almohada.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/////////ventilador tubo///////////////
	glPushMatrix();
	glTranslatef(-3.2, 4.58, -11.15);
	glRotatef(ventil, 0.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(1, 3, 1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.prisma(0.001, 2.5, 2.5, venti.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glScalef(1,3,1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	miobj.cilindro(0.10, 0.5, 25, madera.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	//////////// pelota ///////// 
	glPushMatrix();
	glTranslatef(movh, movv, -11.0);
	glDisable(GL_LIGHTING);
	miobj.esfera(0.4f, 10.0f, 20.0f, pelota1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 0.0, 0.0);
	pintaTexto(-14, 12.0, -14.0, (void *)font, " PROYECTO FINAL LABORATORIO COMPUTACION GRAFICA");
	pintaTexto(-14, 10.5, -14, (void *)font, " CUARTO DE ANDY TOY STORY ");
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{

	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;



	{
		movKit += 1.0;
	}

	if (g_fanimacion)

		// Calculate the number of frames per one second:
		//dwFrames++;
		dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 40)

	{
		ventil = (ventil - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (g_animaicon) {
		if (recorrido1) {
			movh += 0.002;
			movv += 0.01;
			if (movv > 3) {
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2) {
			movh += 0.01;
			movv -= 0.01;
			if (movv < 0.72) {
				recorrido2 = false;
			}
		}
	}



	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case 'i':		//Poner algo en movimiento
		g_fanimacion ^= true;//Activamos/desactivamos la animacíon
		break;

	case 'p':		//Poner algo en movimiento
		g_animaicon = true;//Activamos/desactivamos la animacíon
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 10"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
