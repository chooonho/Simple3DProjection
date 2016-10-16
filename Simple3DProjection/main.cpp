#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include "Model.h"
#include "ModelCreator.h"
#include "Light.h"

#define DEG_TO_RAD 0.0174533

bool isWireFrame = false;
bool isLightOn = false;
float eyeX = 0.0;
float eyeY = 8.0;
float eyeZ = 50;
float z = 50;
float angleX = 0.0;
Light light[2];
std::vector<Model*> models;

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
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, horizontal));

	translate = Transform(-((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, COLOR_GRAY, vertical));

	translate = Transform(-(roomWidth / 2), (roomHeight - 1), 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, horizontal));

	translate = Transform(((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, COLOR_GRAY, vertical));

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, vertical));
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

	rotate = Rotate(270.0, 1.0, 0.0, 0.0);
	translate = Transform(-6.0, 7.5, 10.0);
	models.push_back(createCone(2.0, 4.0, translate, rotate, scale, COLOR_BLUE));

	rotate = Rotate(0.0, 1.0, 0.0, 0.0);
	translate = Transform(-2.0, 9.0, 15.0);
	models.push_back(createTeapot(2.0, translate, rotate, scale, COLOR_SILVER));

	rotate = Rotate(30.0, 0.0, 1.0, 0.0);
	translate = Transform(4.0, 9.0, 14.0);
	models.push_back(createTorus(0.5, 1.0, translate, rotate, scale, COLOR_GREEN));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(12.0, 10.0, 15.0);
	scale = Transform(1.5, 2.5, 1.5);
	models.push_back(createRegular(OCTAHEDRON, translate, rotate, scale, COLOR_ORANGE));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(2.0, 9.0, 10.0);
	scale = Transform(1.0, 1.0, 1.0);
	models.push_back(createRegular(DODECAHEDRON, translate, rotate, scale, COLOR_PURPLE));

	rotate = Rotate(-20.0, 0.0, 0.0, 1.0);
	translate = Transform(7.0, 8.2, 13.0);
	scale = Transform(2.0, 2.0, 2.0);
	models.push_back(createRegular(TETRAHEDRON, translate, rotate, scale, COLOR_YELLOW));

	rotate = Rotate(0.0, 1.0, 0.0, 0.0);
	translate = Transform(10.0, 9.2, 11.0);
	scale = Transform(2.0, 2.0, 2.0);
	models.push_back(createRegular(ICOSAHEDRON, translate, rotate, scale, COLOR_KHAKI));
}

void setupLight()
{
	GLfloat pointSource[4] = { 0.0f };
	GLfloat ambient[4] = { 0.0f };
	GLfloat diffuse[4] = { 0.0f };
	GLfloat specular[4] = { 0.0f };

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			pointSource[0] = 20.0f;
			pointSource[1] = 20.0f;
			pointSource[2] = 15.0f;
			pointSource[3] = 1.0f;

			ambient[0] = 0.4f;
			ambient[1] = 0.4f;
			ambient[2] = 0.4f;
			ambient[3] = 1.0f;

			diffuse[0] = 0.741f;
			diffuse[1] = 0.718f;
			diffuse[2] = 0.420f;
			diffuse[3] = 1.0f;

			specular[0] = 0.0f;
			specular[1] = 0.0f;
			specular[2] = 0.0f;
			specular[3] = 1.0f;
		}
		else
		{
			pointSource[0] = -20.0f;
			pointSource[1] = 20.0f;
			pointSource[2] = 15.0f;
			pointSource[3] = 1.0f;

			ambient[0] = 0.1f;
			ambient[1] = 0.1f;
			ambient[2] = 0.1f;
			ambient[3] = 1.0f;
			
			diffuse[0] = 0.098f;
			diffuse[1] = 0.098;
			diffuse[2] = 0.439f;
			diffuse[3] = 1.0f;

			specular[0] = 0.0f;
			specular[1] = 0.0f;
			specular[2] = 0.0f;
			specular[3] = 1.0f;
		}

		light[i].setPointSource(pointSource);
		light[i].setAmbient(ambient);
		light[i].setDiffuse(diffuse);
		light[i].setSpecular(specular);
	}
}

void switchLight()
{
	if (isLightOn)
	{
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, light[0].getPointSource());
		glLightfv(GL_LIGHT0, GL_AMBIENT, light[0].getAmbient());
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light[0].getDiffuse());
		glLightfv(GL_LIGHT0, GL_SPECULAR, light[0].getSpecular());

		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_POSITION, light[1].getPointSource());
		glLightfv(GL_LIGHT1, GL_AMBIENT, light[1].getAmbient());
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light[1].getDiffuse());
		glLightfv(GL_LIGHT1, GL_SPECULAR, light[1].getSpecular());
	}
	else
	{
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
	}
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
			models[i]->setIsWireFrame(isWireFrame);
			models[i]->draw();
		}
	glPopMatrix();

	glutSwapBuffers();
}

void MyKeyboard(int Key, int m, int n)
{
	switch (Key)
	{
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
		case GLUT_KEY_F1:
			isWireFrame = !isWireFrame;
			break;
		case GLUT_KEY_F2:
			isLightOn = !isLightOn;
			switchLight();
			break;
		case GLUT_KEY_END:
			exit(0);
			break;
	}
}

void init(void)
{
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLoadIdentity();
	gluPerspective(60, 1.78, 1.0, 100);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(960, 540);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Simple 3D Projection");
	setupLight();
	init();

	createRoom();
	createProps();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}