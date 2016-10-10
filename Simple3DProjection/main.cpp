#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include "Model.h"
#include "ModelCreator.h"

#define DEG_TO_RAD 0.0174533

float eyeX = 0.0;
float eyeY = 5.0;
float eyeZ = 25;
float z = 25;
float angleX = 0.0;
std::vector<Model*> models;

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
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 5.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		for (int i = 0; i < models.size(); i++)
		{
			models[i]->draw();
		}
		//glRotatef(45, 1, 0, 0);
		//glColor3f(1.0, 0.0, 0.0);
		//glutSolidCube(1.0);
		//	glPushMatrix();
		//		glColor3f(2.0, 1.0, 0.0);
		//		glTranslatef(1.0, 0, 0.0);
		//		glutSolidCube(1.0);
		//	glPopMatrix();
		//	glPushMatrix();
		//		glColor3f(1.0, 0.0, 1.0);
		//		glTranslatef(2.0, 0, 0);
		//		glutSolidCube(1.0);
		//	glPopMatrix();
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
	}
}

void createModels()
{
	models.push_back(createWall(0.0, 0.0, 11, 11, Transform(-6.0, 0.0, -10.0), Rotate(0.0, 0.0, 0.0, 0.0), Transform(1.0, 1.0, 1.0), ColorRGB3F{ 1.0, 1.0, 0.0 }, horizontal));
	models.push_back(createWall(0.0, 0.0, 11, 11, Transform(-7.0, 0.0, 0.0), Rotate(90.0, 0.0, 1.0, 0.0), Transform(1.0, 1.0, 1.0), ColorRGB3F{1.0, 0.0, 0.0}, vertical));
	models.push_back(createWall(0.0, 0.0, 11, 11, Transform(-6.0, 10.0, -10.0), Rotate(0.0, 0.0, 0.0, 0.0), Transform(1.0, 1.0, 1.0), ColorRGB3F{ 0.0, 0.0, 1.0 }, horizontal));
	models.push_back(createWall(0.0, 0.0, 11, 11, Transform(5.0, 0.0, 0.0), Rotate(90.0, 0.0, 1.0, 0.0), Transform(1.0, 1.0, 1.0), ColorRGB3F{ 0.0, 1.0, 0.0 }, vertical));
	models.push_back(createWall(0.0, 0.0, 11, 11, Transform(-6.0, 0.0, -10.0), Rotate(0.0, 0.0, 0.0, 0.0), Transform(1.0, 1.0, 1.0), ColorRGB3F{ 1.0, 0.0, 1.0 }, vertical));
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(960, 540);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Simple 3D Projection");
	init();

	createModels();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}