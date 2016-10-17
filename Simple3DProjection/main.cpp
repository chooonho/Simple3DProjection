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
bool isLightLeftOn = false;
bool isLightRightOn = false;
float eyeX = 0.0;
float eyeY = 8.0;
float eyeZ = 50;
float z = 50;
float angleX = 0.0;
Light light[2];
GLfloat globalAmbient[4] = {0.7, 0.7, 0.7, 1.0};
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
	models.push_back(createCone(2.0, 4.0, translate, rotate, scale, COLOR_CYAN, createMaterial(CYAN_PLASTIC)));

	rotate = Rotate(0.0, 1.0, 0.0, 0.0);
	translate = Transform(-2.0, 9.0, 15.0);
	models.push_back(createTeapot(2.0, translate, rotate, scale, COLOR_SILVER, createMaterial(SILVER)));

	rotate = Rotate(30.0, 0.0, 1.0, 0.0);
	translate = Transform(4.0, 9.0, 14.0);
	models.push_back(createTorus(0.5, 1.0, translate, rotate, scale, COLOR_GREEN, createMaterial(EMERALD)));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(12.0, 10.0, 15.0);
	scale = Transform(1.5, 2.5, 1.5);
	models.push_back(createRegular(OCTAHEDRON, translate, rotate, scale, COLOR_ORANGE, createMaterial(BRASS)));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(2.0, 9.0, 10.0);
	scale = Transform(1.0, 1.0, 1.0);
	models.push_back(createRegular(DODECAHEDRON, translate, rotate, scale, COLOR_BLACK, createMaterial(OBSIDIAN)));

	rotate = Rotate(-20.0, 0.0, 0.0, 1.0);
	translate = Transform(7.0, 8.2, 13.0);
	scale = Transform(2.0, 2.0, 2.0);
	models.push_back(createRegular(TETRAHEDRON, translate, rotate, scale, COLOR_YELLOW, createMaterial(YELLOW_RUBBER)));

	rotate = Rotate(0.0, 1.0, 0.0, 0.0);
	translate = Transform(10.0, 9.2, 11.0);
	scale = Transform(2.0, 2.0, 2.0);
	models.push_back(createRegular(ICOSAHEDRON, translate, rotate, scale, COLOR_RED, createMaterial(RED_PLASTIC)));
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
			pointSource[0] = -20.0f;
			pointSource[1] = 29.0f;
			pointSource[2] = 15.0f;
			pointSource[3] = 1.0f;

			ambient[0] = 0.4f;
			ambient[1] = 0.4f;
			ambient[2] = 0.4f;
			ambient[3] = 1.0f;

			diffuse[0] = 0.722f;
			diffuse[1] = 0.525f;
			diffuse[2] = 0.043f;
			diffuse[3] = 1.0f;

			specular[0] = 0.0f;
			specular[1] = 0.0f;
			specular[2] = 0.0f;
			specular[3] = 1.0f;
		}
		else
		{
			pointSource[0] = 20.0f;
			pointSource[1] = 29.0f;
			pointSource[2] = 15.0f;
			pointSource[3] = 1.0f;

			ambient[0] = 0.6f;
			ambient[1] = 0.6f;
			ambient[2] = 0.6f;
			ambient[3] = 1.0f;

			diffuse[0] = 0.729f;
			diffuse[1] = 0.333f;
			diffuse[2] = 0.827f;
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

void drawLightBulbs()
{
	GLfloat lightBulbLeftMaterial[4][4] = {
		{ 0.822f, 0.625f, 0.143f, 0.8f },
		{ 0.722f, 0.525f, 0.043f, 0.8f },
		{ 0.9f, 0.9f, 0.9f, 0.8f },
		{ 0.722f, 0.525f, 0.043f, 1.0f }
	};

	GLfloat lightBulbRightMaterial[4][4] = {
		{ 0.829f, 0.433f, 0.927f, 0.8f },
		{ 0.729f, 0.333f, 0.827f, 0.8f },
		{ 0.9f, 0.9f, 0.9f, 0.8f },
		{ 0.729f, 0.333f, 0.827f, 1.0f }
	};

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glTranslatef(light[0].getPointSource()[0], light[0].getPointSource()[1], light[0].getPointSource()[2]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lightBulbLeftMaterial[0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lightBulbLeftMaterial[1]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lightBulbLeftMaterial[2]);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
		if (isLightLeftOn) {
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, lightBulbLeftMaterial[3]);
		}
		glutSolidSphere(1.0, 30, 30);
	glPopMatrix();

	if (isLightLeftOn)
	{
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, light[0].getPointSource());
		glLightfv(GL_LIGHT0, GL_AMBIENT, light[0].getAmbient());
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light[0].getDiffuse());
		glLightfv(GL_LIGHT0, GL_SPECULAR, light[0].getSpecular());
	}
	else {
		glDisable(GL_LIGHT0);
	}

	glPushMatrix();
		glTranslatef(light[1].getPointSource()[0], light[1].getPointSource()[1], light[1].getPointSource()[2]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lightBulbRightMaterial[0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lightBulbRightMaterial[1]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lightBulbRightMaterial[2]);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
		if (isLightRightOn) {
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, lightBulbRightMaterial[3]);
		}
		glutSolidSphere(1.0, 30, 30);
	glPopMatrix();

	if (isLightRightOn)
	{
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_POSITION, light[1].getPointSource());
		glLightfv(GL_LIGHT1, GL_AMBIENT, light[1].getAmbient());
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light[1].getDiffuse());
		glLightfv(GL_LIGHT1, GL_SPECULAR, light[1].getSpecular());
	}
	else {
		glDisable(GL_LIGHT1);
	}

	glDisable(GL_BLEND);
}

void disposeModels()
{
	while (!models.empty())
	{
		delete models.back();
		models.pop_back();
	}
}

void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 15.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawLightBulbs();
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
			isLightLeftOn = !isLightLeftOn;
			break;
		case GLUT_KEY_F3:
			isLightRightOn = !isLightRightOn;
			break;
		case GLUT_KEY_END:
			disposeModels();
			exit(0);
			break;
		case GLUT_KEY_PAGE_UP:
			if (eyeZ > 0)
			{
				eyeZ -= 5;
				z -= 5;
			}
			break;
		case GLUT_KEY_PAGE_DOWN:
			if (eyeZ < 100)
			{
				eyeZ += 5;
				z += 5;
			}
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
	//glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
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

	disposeModels();

	return 0;
}