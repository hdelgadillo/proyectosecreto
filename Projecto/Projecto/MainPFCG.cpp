//Semestre 2018-2 Computación gráfica Proyecto Final
//****************************************************************//
//****************************************************************//
//******			Proyecto Final					         *****//
//******			Alumno (s):								 *****//
//******													******//
//******			Angeles Avalos José Enrique				******//
//******			Monterrosas Ramirez Jorge				******//
//******			Landeros Diego							******//
//******			Hugo Delgadillo Cortez									******//
//****************************************************************//
//****************************************************************//
//****************************************************************//
//****************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture cielo; //Cielo
CTexture ventana; //Ventanas
CTexture pasto;
CTexture Textcasa;//Paredes blancas
CTexture Textcasa2;//Ladrillo negro
CTexture Textcasa3;//Castillos parte de abajo
CTexture cedro;//madera cedro
CTexture telaroja;
CTexture madera_cabecera;
CTexture tela_almohada;

//Se utilizarán para definir cada figura que el programador cree//
CFiguras f_enrique;
//CFiguras f_jorge;
CFiguras f_hugo;
//CFiguras f_diego;
CFiguras fig2;


////Figuras de 3D Studio
//CModel kit;   //DEclarar modelo 
//CModel llanta;
//
//float rot;
////Animación del coche
//float movKit = 0.0;
//bool g_fanimacion = false;
//bool g_fanimacion2 = false;
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    

	/*TEXTURAS*/
    cielo.LoadTGA("Exterior/cielo.tga");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	ventana.LoadTGA("Exterior/Vidrio2.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	pasto.LoadTGA("Exterior/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	Textcasa.LoadTGA("Casa/Textcasa.tga");
	Textcasa.BuildGLTexture();
	Textcasa.ReleaseImage();

	Textcasa2.LoadTGA("Casa/Ladrilloblack.tga");
	Textcasa2.BuildGLTexture();
	Textcasa2.ReleaseImage();

	Textcasa3.LoadTGA("Casa/Castillo.tga");
	Textcasa3.BuildGLTexture();
	Textcasa3.ReleaseImage();

	cedro.LoadTGA("Casa/cedro.tga");
	cedro.BuildGLTexture();
	cedro.ReleaseImage();

	telaroja.LoadTGA("Casa/telaroja.tga");
	telaroja.BuildGLTexture();
	telaroja.ReleaseImage();

	madera_cabecera.LoadTGA("Casa/madera_cabecera.tga");
	madera_cabecera.BuildGLTexture();
	madera_cabecera.ReleaseImage();

	tela_almohada.LoadTGA("Casa/tela_almohada.tga");
	tela_almohada.BuildGLTexture();
	tela_almohada.ReleaseImage();
	////Carga de Figuras
	//kit._3dsLoad("kitt.3ds");	
	////kit.VertexNormals();
	//llanta._3dsLoad("k_rueda.3ds");

	//objCamera.Position_Camera(0, 2.5f, 3, 0, 10.0f, 0, 1, 1, 0);
	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1 , 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void silla(void) {

	


}
void cama(void) { 
	
	
	glPushMatrix();
	

	glPushMatrix();
	glScalef(2, .5, 3);
	f_hugo.prisma2(telaroja.GLindex, telaroja.GLindex);
	glPopMatrix();
	//cabecera
	glPushMatrix();
	glTranslatef(0, 0.3, 1.5);
	glScalef(2, 1 , .1);
	f_hugo.prisma2(madera_cabecera.GLindex, madera_cabecera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.7, -0.2,1.2);
	glScalef(.2, .3, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.7, -.2, -1.2);
	glScalef(.2, .3, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.7, -.2, 1.2);
	glScalef(.2, .3, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.7, -.2, -1.2);
	glScalef(.2, .3, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	

	glPopMatrix();

}

void mesa(void) {
	glPushMatrix();
	glScalef(2, 0.1, 2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.7, -1, .7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.7, -1, -.7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.7, -1, .7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.7, -1, -.7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();


}
void casa()
{		


	glPushMatrix();
	glTranslatef(0, 2.3, 0);
		f_enrique.prisma(1, 1, 1, 0, 0, 0, 0, 0, 0);
			
	glPopMatrix();
	glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, 15);
		glPushMatrix();//Creación casa segundo piso
			glTranslatef(-20, 25.5, 20);
			f_enrique.prisma(20, 30, 3, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex); //CARA lateral, 30largo,20alto,3ancho
			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glTranslatef(23.5, 11.5, 0);
				glScalef(50,3,30);
				f_enrique.prisma(1, 1, 1,Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex); //Techo, 30largo, 3alto, 50ancho
				glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glTranslatef(0, -7.665, 0);
					f_enrique.prisma(1, 1, 1, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);//TEcho abajo, 30largo, 3 alto, 50 ancho
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glRotatef(180, 1, 0, 0);
				glTranslatef(25, -11.5, 63.5);
				glScalef(80,3,30);
				f_enrique.prisma(1, 1, 1, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);//Cara fondo 60 largo, 3 alto, 30 ancho
			glPopMatrix();
			glPushMatrix();
				glRotatef(180, 1, 0, 0);
				glTranslatef(25, 11.5, 63.5);
				glScalef(80, 3, 30);
				f_enrique.prisma(1, 1, 1, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-16.5,0,-63.5);
				glRotatef(90, 0, 1, 0);
				glScalef(30,26,3);
				f_enrique.prisma(1, 1, 1, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);//CAra trasera, largo 30, alto 26, ancho 3
			glPopMatrix();
			glPushMatrix();
				glTranslatef(23.5, 0, -80);
				glRotatef(180, 1, 0, 0);
				glScalef(83, 26, 3);
				f_enrique.prisma(1, 1, 1, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);//Lateral derecha, largo, 63, alto 26, ancho 3
			glPopMatrix();
			//PArte café de la casa
			glPushMatrix();
				glTranslatef(18, 0, -6.5);
				glRotatef(90, 0, 1, 0);
				glScalef(10, 20, 6);
				f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);//Frente ladrillo  largo 10, alto, 20 ancho 6
				glPushMatrix();
					glTranslatef(2.35, 0.4, 0);
					glScalef(3.7, 0.2, 1.0);
					f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);//Frente arriba
					glPushMatrix();
						glTranslatef(0, -4, 0);
						f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);//Frente abajo
						/*glPushMatrix();
							glRotatef(180, 1, 0, 0);
							glTranslatef(1,0,0);
							f_enrique.prisma(1, 1, 1, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);
						glPopMatrix();*/
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glTranslatef(-4.165, -0.4, 3.95);
					glScalef(7.335, 0.2, 0.5);
					f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);
					glPushMatrix();
						glTranslatef(0, 4, 0);
						f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);
					glPopMatrix ();
					glPushMatrix();
					//glRotatef(90, 0, 1, 0);
					glRotatef(180, 0, 0, 1);
					glTranslatef(0.55, 0, 3);
					glScalef(0.1, 1.0, 7.0);
					f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);
					glPushMatrix();
						glTranslatef(0.0, -4, 0);
						f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(0.00, -2.0, 0.543);//(profundidad,altura,)
						glScalef(1.0, 5.0, -0.085); //(profundidad,alto,)
						f_enrique.prisma(1, 1, 1, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex, Textcasa2.GLindex);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glEnable(GL_BLEND); //Para las ventanas usar esto
				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
				glRotatef(90, 0.0, 1.0, 0.0);
				glTranslatef(23.5, 0.0,-16.5);
				f_enrique.prisma(26.0,50.0,3.0,ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex);
				glDisable(GL_BLEND);
			glPopMatrix();
			glPushMatrix();
				glEnable(GL_BLEND); //Para las ventanas usar esto
				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
				glRotatef(90, 0.0, 1.0, 0.0);
				glTranslatef(30, 0.0, 18);
				f_enrique.prisma(12.0, 37.0, 6.0, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex);
				glDisable(GL_BLEND);
			glPopMatrix();
			glPushMatrix();
			glEnable(GL_BLEND); //Para las ventanas usar esto
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
			glRotatef(180, 0.0, 1.0, 0.0);
			glTranslatef(-45.2, 0.0, 46);
			f_enrique.prisma(12.0, 48.4, 5.0, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex);
			glDisable(GL_BLEND);
			glPopMatrix();
			glPushMatrix();
				glEnable(GL_BLEND); //Para las ventanas usar esto
				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
				glRotatef(90, 0.0, 1.0, 0.0);
				glTranslatef(64, 0.0, 67.2);
				f_enrique.prisma(12.0, 31.0, 4.5, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex, ventana.GLindex);
				glDisable(GL_BLEND);
			glPopMatrix();
			//PARTE DE ABAJO DE LA CASA
			//glPushMatrix();
			//	glTranslatef(0.0,0.0,-7.0);
			//		glPushMatrix();//Columna esquina de frente
			//			glTranslatef(10.5,-18.2,-10);
			//			f_enrique.prisma(10.4,3,3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			//			glPushMatrix();
			//				glTranslatef(-20.5, 0, 0);
			//				f_enrique.prisma(10.4, 3, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			//			glPopMatrix();
			//		glPopMatrix();
			//glPopMatrix();
			glPushMatrix();//Muro de la casa planta baja
				glTranslatef(0.5, -18.2, -5);
				f_enrique.prisma(10.4, 23, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(10.5,-18.2,-16);//-8,0de separación
				f_enrique.prisma(10.4, 3, 3,Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			glPopMatrix();
			glPushMatrix();
				glEnable(GL_BLEND); //Para las ventanas usar esto
				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
				glTranslatef(10.5, -18.2, -10.5);//ventana
				f_enrique.prisma(10.4, 3, 8, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex, Textcasa.GLindex);
				glDisable(GL_BLEND);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-9.5, -18.2, -16);//-8,0de separación parte trasera
				f_enrique.prisma(10.4, 3, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(10.5, -18.2, -26);//-8,0de separación
				f_enrique.prisma(10.4, 3, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-9.5, -18.2, -26);//-8,0de separación parte trasera
				f_enrique.prisma(10.4, 3, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
				glPopMatrix();
			glPushMatrix();
				glTranslatef(10.5, -18.2, -38);//-8,0de separación
				f_enrique.prisma(10.4, 3, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-9.5, -18.2, -38);//-8,0de separación parte trasera
			f_enrique.prisma(10.4, 3, 3, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex, Textcasa3.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(10.5, -18.2, -48);//-8,0de separación
				f_enrique.prisma(10.4, 3, 3, 0, 0, 0, 0, 0, 0);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-9.5, -18.2, -48);//-8,0de separación parte trasera
			f_enrique.prisma(10.4, 3, 3, 0, 0, 0, 0, 0, 0);
			glPopMatrix();
		glPopMatrix();
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
	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	f_enrique.skybox(200.0, 120.0, 200.0, cielo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creación del Piso/pasto
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	f_enrique.piso(200.8, 1.5, 200, pasto.GLindex, pasto.GLindex, pasto.GLindex, pasto.GLindex, pasto.GLindex, pasto.GLindex);
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();
	casa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 10, 0);
	
	silla();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();//Pop para todo el escenario
		glPopMatrix();

	
	glutSwapBuffers ( );

}



//void animacion()
//{
//
//
//	if(g_fanimacion)
//	{
//		movKit +=1.0;
//		rot += 1.0;
//	}
//
//	if (g_fanimacion2)
//	{
//		movKit -= 1.0;
//		rot  -= 1.0;
//	}
//	
//
//
//	glutPostRedisplay();
//}

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.4 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.4));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		//case ' ':		//Poner algo en movimiento
		//	g_fanimacion = true; //Activamos/desactivamos la animacíon
		//	break;

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
		objCamera.Rotate_View( CAMERASPEED);
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
  glutInitWindowSize  (700, 700);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final CG Area Residencial"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  //glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}


/*
	//		glPushMatrix();
	//			//Para que el coche conserve sus colores
	//				glDisable(GL_COLOR_MATERIAL);
	//				glRotatef(90, 0, 1, 0);
	//				glScalef(0.3, 0.3, 0.3);

	//				if (movKit > 100)
	//				{
	//					g_fanimacion = false;
	//					g_fanimacion2 = true;
	//				
	//				}

	//				if (movKit == 0)
	//				{
	//					g_fanimacion2 = false;
	//					g_fanimacion = false;
	//				}


	//				glTranslatef(0, 4, movKit); //movkit
	//				//Pongo aquí la carroceria del carro
	//				kit.GLrender(NULL,_SHADED,1.0);  //_WIRED O _POINTS //Mandar a llamar al carro

	//				glPushMatrix();
	//					glTranslatef(-6.0, -1.0, 7.5);
	//					glRotatef(rot, 1, 0, 0);
	//					llanta.GLrender(NULL,_SHADED,1.0); //LLanta del lado derecho
	//				glPopMatrix();

	//				glPushMatrix();
	//					glTranslatef(6.0, -1.0, 7.5); //Lanta izquierda
	//					glRotatef(180, 0, 1, 0);
	//					glRotatef(-rot, 1, 0, 0);
	//					llanta.GLrender(NULL, _SHADED, 1.0);
	//				glPopMatrix();

	//				glPushMatrix();
	//					glTranslatef(6.0, -1.0, -9.5);//Lanta trasera
	//					glRotatef(180, 0, 1, 0);
	//					glRotatef(-rot, 1, 0, 0);
	//					llanta.GLrender(NULL, _SHADED, 1.0);
	//				glPopMatrix();

	//				glPushMatrix();
	//					glTranslatef(-6.0, -1.0, -9.5); //Llanta trasera
	//					glRotatef(rot, 1, 0, 0);
	//					llanta.GLrender(NULL, _SHADED, 1.0);
	//				glPopMatrix();
	//		glPopMatrix();

	//		//Para que el comando glColor funcione con iluminacion
	//		glEnable(GL_COLOR_MATERIAL);
	//		
	//	glPopMatrix();
	//glPopMatrix();*/



	//			casa();
	//			//glPushMatrix();
	//			//	glEnable(GL_BLEND); //Para las ventanas usar esto
	//			//	glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
	//			//	glRotatef(90, 1.0, 0.0, 0.0);
	//			//	glTranslatef(0.0, 0.0, 0.0);
	//			//	f_enrique.prisma(5.0,8.0,3.0,ventana.GLindex);
	//			//	glDisable(GL_BLEND);
	//			//glPopMatrix();