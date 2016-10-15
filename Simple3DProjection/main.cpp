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
float eyeZ = 50;
float z = 50;
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
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 15.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		for (unsigned int i = 0; i < models.size(); i++)
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
	int roomWidth = 61;
	int roomHeight = 31;
	Transform translate;
	Rotate rotate;
	Transform scale = Transform(1.0, 1.0, 1.0);

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, ColorRGB3D{ 1.0, 1.0, 1.0 }, horizontal));

	translate = Transform(-((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, ColorRGB3D{0.6, 0.6, 0.6}, vertical));

	translate = Transform(-(roomWidth / 2), (roomHeight - 1), 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, ColorRGB3D{ 1.0, 1.0, 1.0 }, horizontal));

	translate = Transform(((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, ColorRGB3D{ 0.6, 0.6, 0.6 }, vertical));

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, ColorRGB3D{ 0.8, 0.8, 0.8 }, vertical));
}

void createProps()
{
	Transform translate;
	Rotate rotate;
	Transform scale = Transform(1.0, 1.0, 1.0);

	translate = Transform(-10.0, 1.0, 5.0);
	models.push_back(createTable(25, 15, 6, translate, rotate, scale));

	rotate = Rotate(45.0, 0.0, 1.0, 0.0);
	translate = Transform(-20.0, 1.0, 12.0);
	models.push_back(createChair(5, 5, 7, translate, rotate, scale));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(22.0, 1.0, 15.0);
	models.push_back(createRobot(translate, rotate, scale));

	rotate = Rotate(270.0, 1.0, 0.0, 0.0);
	translate = Transform(-25.0, 1.0, 5.0);
	models.push_back(createTree(translate, rotate, scale));
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
	createProps();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}