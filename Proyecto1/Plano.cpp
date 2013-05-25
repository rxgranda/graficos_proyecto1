
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <windows.h>
static GLfloat x_Spin=0.0;
static GLfloat y_Spin=0.0;
static GLfloat z_Spin=0.0;
static GLfloat ancho_plano=500;
static GLfloat alto_plano=500;
GLfloat xPosicion = 0.0f;
GLfloat yPosicion = 0.0f;
GLfloat yRotationAngle = 0.0f;


static GLfloat pared[4][2]={
	0.0,0.0,	
	100.0,0.0,	
	100.0,100.0,
	0.0,100.0	
};
GLfloat ventanaI[4][2]={
	0.0,50.0,	
	25.0,50.0,						
	25.0,75.0,
	0.0,75.0
};

GLfloat ventanaD[4][2]={
	75.0,50.0,	
	100.0,50.0,						
	100.0,75.0,
	75.0,75.0
};

GLfloat puerta[4][2]={
	35.0,0.0,	
	65.0,0.0,						
	65.0,50.0,
	35.0,50.0
};

GLfloat techo[4][2]={
	0.0,100.0,	
	100.0,100.0,						
	50.0,150.0					
};


void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ancho_plano/2,ancho_plano/2,-ancho_plano/2, ancho_plano/2, -ancho_plano/2, ancho_plano/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}



void display (void){
	glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();

	//Abscisa y Ordenada	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-ancho_plano/2,0.0);
	glVertex2f(ancho_plano/2,0.0);
	glVertex2f(0.0,-ancho_plano/2);
	glVertex2f(0.0,ancho_plano/2);

	glEnd();

	//Grid
	glLineStipple(2,0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glColor3f(0.0,1.0,1.0);
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
	glRotatef(x_Spin,1.0,0.0,0.0);
	glRotatef(y_Spin,0.0,1.0,0.0);
	glRotatef(z_Spin,0.0,0.0,1.0);
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.5);
	for(int i=0;i<4;i++){
		
		glVertex2f(pared[i][0]+xPosicion,pared[i][1]+yPosicion);
		
	}
	glColor3f(1.0,0.0,0.0);
	for(int i=0;i<4;i++){
		glVertex2f(ventanaI[i][0]+xPosicion,ventanaI[i][1]+yPosicion);	
		
	}
	for(int i=0;i<4;i++){
		glVertex2f(ventanaD[i][0]+xPosicion,ventanaD[i][1]+yPosicion);	
		
	}
	for(int i=0;i<4;i++){
		glVertex2f(puerta[i][0]+xPosicion,puerta[i][1]+yPosicion);
		
	}

	glEnd();	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,1.0);
	for(int i=0;i<4;i++){
		glVertex2f(techo[i][0]+xPosicion,techo[i][1]+yPosicion);		
		
	}														
	glEnd();	  	
	glPopMatrix();
	glutSwapBuffers();
}

void init (void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}


void keyboard( unsigned char key, int x, int y ){
	switch ( key ) {
		case 'q':
			z_Spin=z_Spin+10.0;	
			if (z_Spin>360.0)
				z_Spin=z_Spin-360.0;								
			break;
		case 'e':									
			z_Spin=z_Spin-10.0;	
			if (z_Spin<-360)
				z_Spin=z_Spin+360.0;					
			break;
		case 'w':
			y_Spin=y_Spin+10.0;	
			if (y_Spin>360.0)
				y_Spin=y_Spin-360.0;								
			break;
		case 's':									
			y_Spin=y_Spin-10.0;	
			if (y_Spin<-360)
				y_Spin=y_Spin+360.0;					
			break;
		case 'a':
			x_Spin=x_Spin+10.0;	
			if (x_Spin>360.0)
				x_Spin=x_Spin-360.0;								
			break;
		case 'd':									
			x_Spin=x_Spin-10.0;	
			if (x_Spin<-360)
				x_Spin=x_Spin+360.0;					
			break;
		default:		
			break;
	}
		glutPostRedisplay();
	
}
void handleSpecialKeypress(int key, int x, int y) {
	switch ( key ) {

	case GLUT_KEY_UP:									
		yPosicion=yPosicion+10.0;		
		
		break;
	case GLUT_KEY_DOWN:											
		
		yPosicion=yPosicion-10.0;
		break;
	case GLUT_KEY_RIGHT:									
		xPosicion=xPosicion+10.0;
		
		break;
	case GLUT_KEY_LEFT:									
		xPosicion=xPosicion-10.0;
		
		break;
	default:									
		break;

	}
	glutPostRedisplay();
}


int main( int argc, char** argv )
{
	glutInit(&argc,argv);

	// The image is not animated so single buffering is OK. 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );

	// Window position (from top corner), and size (width and hieght)
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( ancho_plano,alto_plano );
	glutCreateWindow( "Proyecto 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleSpecialKeypress);
	//glutMouseFunc(mouse);
	glutMainLoop();

	return 0;	
}
