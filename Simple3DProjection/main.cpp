#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#define DEG_TO_RAD 0.0174533

float eyeX = 0.0;
float eyeY = 0.0;
float eyeZ = 5;
float z = 5;
float angleX = 0.0;

void init(void)
{
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.78, 1.0, 50);
}

void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		glRotatef(45, 1, 0, 0);
		glColor3f(1.0, 0.0, 0.0);
		glutSolidCube(1.0);
			glPushMatrix();
				glColor3f(2.0, 1.0, 0.0);
				glTranslatef(1.0, 0, 0.0);
				glutSolidCube(0.5);
			glPopMatrix();
			glPushMatrix();
				glColor3f(1.0, 0.0, 1.0);
				glTranslatef(2.0, 0, 0);
				glutSolidCube(1.0);
			glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void MyKeyboard(int Key, int m, int n)
{
	switch (Key) {

	case GLUT_KEY_LEFT:
		angleX -= 1.0;
		eyeX = z * sin(DEG_TO_RAD * angleX);
		eyeZ = z * cos(DEG_TO_RAD * angleX);
		break;

	case GLUT_KEY_RIGHT:
		angleX += 1.0;
		eyeX = z * sin(DEG_TO_RAD * angleX);
		eyeZ = z * cos(DEG_TO_RAD * angleX);
		break;

	//	//Use F1 key to toggle between fullscreen and regular window
	//case GLUT_KEY_F1:
	//	fullscreen = !fullscreen;
	//	if (fullscreen)
	//		glutFullScreen();			//use full screen
	//	else
	//		glutReshapeWindow(960, 540);	//resize display window

	//	break;

	//	//Use F2 key to toggle between wireframe or solid rendering
	//case GLUT_KEY_F2:
	//	solid = !solid;
	//	break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(960, 540);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Simple 3D Projection");
	init();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}