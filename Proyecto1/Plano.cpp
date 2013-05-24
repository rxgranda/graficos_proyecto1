
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

static GLfloat spin=0.0;
static GLfloat ancho_plano=500;
static GLfloat alto_plano=500;

void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ancho_plano/2,ancho_plano/2,-ancho_plano/2, ancho_plano/2, -1.0, 1.0);
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

	//glPopMatrix();
	glutSwapBuffers();
}

void init (void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
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
	//glutMouseFunc(mouse);
	glutMainLoop();

	return 0;	
}
