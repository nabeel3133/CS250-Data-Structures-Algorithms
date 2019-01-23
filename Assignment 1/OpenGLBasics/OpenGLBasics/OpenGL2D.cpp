#include "glut.h"
#include <stdio.h>
#include <conio.h>

int g_Width=400;
int g_Height=400;

void init();
void myMouseFunction( int button, int state, int mouseX, int mouseY );
void myKeyboardFunction( unsigned char key, int mouseX, int mouseY );
void mySpecialKeysFunction(int key, int x, int y);
void myReshapeFunction( int width, int height );
void myTimerFunction( int val );
void myDisplayFunction();


int main(int argc, char** argv)
{
	glutInit( &argc, argv );

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowSize( g_Width, g_Height ); 
	glutInitWindowPosition( 250, 50 );
	glutCreateWindow( "My Second OpenGL Appliction" );

	init();

	glutMouseFunc( myMouseFunction );
	glutKeyboardFunc( myKeyboardFunction );
	glutSpecialFunc( mySpecialKeysFunction );

	glutReshapeFunc( myReshapeFunction );
	glutDisplayFunc( myDisplayFunction ); 
	glutTimerFunc( 33, myTimerFunction, 0 ); 	

//	glutFullScreen();
//	glutSetCursor( GLUT_CURSOR_NONE );

	glutMainLoop();

	return 0;
}

void init(void) 
{
	glClearColor( 0.0, 0.0, 0.0, 0.0 );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);
}

void myMouseFunction( int button, int state, int mouseX, int mouseY ) 
{
	//glVertex2f(mouseX,mouseY);
	printf("\nmouseX: %d mouseY: %d, State: %d",mouseX,mouseY);
}

void myKeyboardFunction( unsigned char key, int mouseX, int mouseY )
{
	if( key == 'a' ) // i.e. Esc key
		printf("a pressed");
}

void mySpecialKeysFunction(int key, int x, int y)
{
	switch( key )
	{
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_HOME:
		break;
	case GLUT_KEY_END:
		break;
	case GLUT_KEY_PAGE_UP:
		break;
	case GLUT_KEY_PAGE_DOWN:
		break;
	}
}

void myReshapeFunction( int width, int height )
{
	glClear(GL_COLOR_BUFFER_BIT);

	g_Width  = width; 
	g_Height = height;

	glViewport (0, 0, g_Width, g_Height);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);
}

void myTimerFunction( int val )
{
	glutTimerFunc( 33, myTimerFunction, 0 ); 	
	myDisplayFunction();
}
int i=0;
void myDisplayFunction()
{
	//glClear( GL_COLOR_BUFFER_BIT );

	glBegin( GL_POLYGON );
	glVertex2i( 50+i, 50+i );
	glVertex2i( 50+i, 100+i );
	glVertex2i( 100+i, 50+i );

	glEnd();

	glutSwapBuffers();
     i+=10;
	printf(".");
}
