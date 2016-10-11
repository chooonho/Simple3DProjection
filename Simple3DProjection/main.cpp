#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include "Model.h"
#include "ModelCreator.h"

#define DEG_TO_RAD 0.0174533

float eyeX = 0.0;
float eyeY = 10.0;
float eyeZ = 40;
float z = 40;
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
	gluPerspective(60, 1.78, 1.0, 100);
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

void createRoom()
{
	// Make sure that:
	// - roomWidth % 2 = 1
	// - roomHeight % 2 = 1
	int roomWidth = 41;
	int roomHeight = 21;
	Transform translate;
	Rotate rotate;
	Transform scale = Transform(1.0, 1.0, 1.0);

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(0.0, 0.0, roomWidth, roomHeight, translate, rotate, scale, ColorRGB3F{ 1.0, 1.0, 0.0 }, horizontal));

	translate = Transform(-((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(0.0, 0.0, ((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, ColorRGB3F{1.0, 0.0, 0.0}, vertical));

	translate = Transform(-(roomWidth / 2), (roomHeight - 1), 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(0.0, 0.0, roomWidth, roomHeight, translate, rotate, scale, ColorRGB3F{ 0.0, 0.0, 1.0 }, horizontal));

	translate = Transform(((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(0.0, 0.0, ((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, ColorRGB3F{ 0.0, 1.0, 0.0 }, vertical));

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(0.0, 0.0, roomWidth, roomHeight, translate, rotate, scale, ColorRGB3F{ 1.0, 0.0, 1.0 }, vertical));
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(960, 540);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Simple 3D Projection");
	init();

	createRoom();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}