/**
*Proyecto 1 Gráficos por Computadora
*
* Integrantes:
*
*   Gianni Carlo
*   Roger Granda
*   Denisse Pintado
*
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

GLfloat x_Spin=0.0f;
GLfloat y_Spin=0.0f;
GLfloat z_Spin=0.0f;
GLfloat ancho_plano=500;
GLfloat alto_plano=500;
GLfloat xPosicion = 0.0f;
GLfloat yPosicion = 0.0f;

GLfloat pared[][2]={
	0.0,0.0,	
	100.0,0.0,	
	100.0,100.0,
	0.0,100.0	
};
GLfloat ventanaI[][2]={
	0.0,50.0,	
	25.0,50.0,						
	25.0,75.0,
	0.0,75.0
};

GLfloat ventanaD[][2]={
	75.0,50.0,	
	100.0,50.0,						
	100.0,75.0,
	75.0,75.0
};

GLfloat puerta[][2]={
	35.0,0.0,	
	65.0,0.0,						
	65.0,50.0,
	35.0,50.0
};

GLfloat techo[][2]={
	0.0,100.0,	
	100.0,100.0,						
	50.0,150.0					
};

/*
* Procedimiento: reshape
* Parámetros: int w, int h
* Descripción: Establece el worldspace, model, y viewport de la escena
* Autor: Gianni Carlo, Roger Granda
*/
void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ancho_plano/2,ancho_plano/2,-ancho_plano/2, ancho_plano/2, -ancho_plano/2, ancho_plano/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
* Procedimiento: display
* Parámetros: -
* Descripción: Realiza los procesos geométricos del cuerpo (Rotación y traslación del cuerpo), y Rasterizado del cuerpo y el plano cartesiano 
* Autores: Denisse Pintado, Roger Granda, Gianni Carlo
*/
void display (void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//Abscisa y Ordenada	
	glLineWidth (5);
	glBegin(GL_LINES);
		glColor3f(0.0,1.0,1.0);
		glVertex2f(-ancho_plano/2,0.0);
		glVertex2f(ancho_plano/2,0.0);
		glVertex2f(0.0,-ancho_plano/2);
		glVertex2f(0.0,ancho_plano/2);
	glEnd();
	//Grid
	glLineStipple(2,0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth (1);
	glBegin(GL_LINES);	
		glColor3f (0.5F, 0.5F, 0.5F);
		//Grid Vertical		
		for(int i=-ancho_plano/2;i<ancho_plano/2; i=i+ancho_plano/10){
			if(i!=0.0){			
				glVertex2f(i,alto_plano/2);
				glVertex2f(i,-alto_plano/2);
			}
		}
		//Grid Horizontal
		for(int i=-alto_plano/2;i<alto_plano/2; i=i+alto_plano/10){
			if(i!=0.0){
				glVertex2f(-ancho_plano/2,i);
				glVertex2f(ancho_plano/2,i);
			}
		}

	glEnd();
	glDisable(GL_LINE_STIPPLE);	
	glPushMatrix();	
	glTranslatef(xPosicion,yPosicion,0.0);
	glRotatef(x_Spin,1.0,0.0,0.0);
	glRotatef(y_Spin,0.0,1.0,0.0);
	glRotatef(z_Spin,0.0,0.0,1.0);
	//Casa: Pared y ventanas
	glBegin(GL_QUADS);
		glColor3f(1.0,1.0,0.5);
		for(int i=0;i<4;i++){		
			glVertex2f(pared[i][0],pared[i][1]);		
		}
		glColor3f(1.0,0.0,0.0);
		for(int i=0;i<4;i++){
			glVertex2f(ventanaI[i][0],ventanaI[i][1]);			
		}
		for(int i=0;i<4;i++){
			glVertex2f(ventanaD[i][0],ventanaD[i][1]);			
		}
		for(int i=0;i<4;i++){
			glVertex2f(puerta[i][0],puerta[i][1]);		
		}	
	glEnd();
	//Casa: Techo
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,1.0);
		for(int i=0;i<4;i++){
			glVertex2f(techo[i][0],techo[i][1]);				
		}	
	glEnd();	  	
	glPopMatrix();
	glutSwapBuffers();
}

/*
* Procedimiento: init
* Parámetros: -
* Descripción: Iniciliza los parametros del worldspace
* Autores: Denisse Pintado, Roger Granda, Gianni Carlo
*/
void init (void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
	glDisable(GL_CULL_FACE);
}

/*
* Procedimiento: keyboard
* Parámetros: unsigned char key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la rotación del cuerpo
* Autor: Roger Granda
*/
void keyboard( unsigned char key, int x, int y ){
	switch ( key ) {
		case 'q':
			z_Spin=z_Spin+5.0;	
			if (z_Spin>360.0)
				z_Spin=z_Spin-360.0;								
			break;
		case 'e':									
			z_Spin=z_Spin-5.0;	
			if (z_Spin<-360)
				z_Spin=z_Spin+360.0;					
			break;
		case 'a':
			y_Spin=y_Spin+5.0;	
			if (y_Spin>360.0)
				y_Spin=y_Spin-360.0;								
			break;
		case 'd':									
			y_Spin=y_Spin-5.0;	
			if (y_Spin<-360)
				y_Spin=y_Spin+360.0;					
			break;
		case 'w':
			x_Spin=x_Spin+5.0;	
			if (x_Spin>360.0)
				x_Spin=x_Spin-360.0;								
			break;
		case 's':									
			x_Spin=x_Spin-5.0;	
			if (x_Spin<-360)
				x_Spin=x_Spin+360.0;					
			break;
		default:		
			break;
	}
	glutPostRedisplay();	
}

/*
* Procedimiento: handleSpecialKeypress
* Parámetros: int key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la tranlación del cuerpo
* Autor: Gianni Carlo
*/
void handleSpecialKeypress(int key, int x, int y) {
	switch ( key ) {
		case GLUT_KEY_UP:									
			yPosicion=yPosicion+5.0;				
			break;
		case GLUT_KEY_DOWN:													
			yPosicion=yPosicion-5.0;
			break;
		case GLUT_KEY_RIGHT:									
			xPosicion=xPosicion+5.0;		
			break;
		case GLUT_KEY_LEFT:									
			xPosicion=xPosicion-5.0;		
			break;
		default:									
			break;
	}
	glutPostRedisplay();
}

/*
* Función: main
* Parámetros: int argc, char** argv
* Descripción: Punto de Inicio del programa
* Autor: Denisse Pintado, Gianni Carlo, Roger Granda
*/
int main( int argc, char** argv )
{
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( ancho_plano,alto_plano );
	glutCreateWindow( "Proyecto 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleSpecialKeypress);	
	glutMainLoop();
	return 0;	
}
