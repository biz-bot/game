#define _CRT_SECURE_NO_WARNINGS
#define  GL_GLEXT_PROTOTYPES
#include "include.h"
#include "includedll.h"
#include "light.h"
#include "file.h" 
#include "mouse.h"
#include "key.h"
#include "render.h"
#include "Camera.h"
//#include "texture.h"
//#include "include.h"
GLuint scena;

light lig;
WorldScena St1("scena/scena.ase");
KeyButton but;
Camera cam;
//WorldScena St1("scena/scena-1.ase");
int windowWidth, windowHeight;
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DITHER);
	glLoadIdentity();
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Улучшенные вычисления перспективы

	
	cam.lookCamera(but,mouse);
	
	
	glPushMatrix();
	
	glCallList(scena);
	
	glPopMatrix();


	glPushMatrix();
	
	glutSwapBuffers();
	

}
void SetupRC(void)
{
	
	PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 1, 0x04090409);
	lightSet S = { 2, 10, 2, 100, 255,255,255 };
	
	lig.lightLine(S, St1);



	glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
	
	scena = glGenLists(1);
	glNewList(scena, GL_COMPILE);
	St1.render();
	glEndList();

	
}

void ChangeSize(GLsizei w, GLsizei h)
{
	
	 windowHeight = h;
	 windowWidth = w;
	GLfloat aspect;
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(60.0f, aspect, 1.0, 400.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void time(int value) {
	Physics game;
	but.ytransf -= 0.2;
	but.keys();
	
	game.stop(St1);
	
	RenderScene();
	
	
	glutPostRedisplay();
	glutTimerFunc(10, time, 2);

}
int main(void)
{
	//glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("sim");
	SetupRC();

	

	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);

	glutSpecialFunc(SpecialKeysDown);
	glutSpecialUpFunc(SpecialKeysUp);

	glutMotionFunc(mouseactiv);
	glutPassiveMotionFunc(mousepassiv);

	
	glutSetCursor(GLUT_CURSOR_NONE);
	glutTimerFunc(10, time, 2);
	glutTimerFunc(2, timerfun, 1);
	
	//keys();
	
	//glutFullScreen();
	glutMainLoop();
	
	return 0;
} 