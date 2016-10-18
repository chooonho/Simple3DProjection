#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include "Camera.h"
#include "Model.h"
#include "ModelCreator.h"
#include "Light.h"
#include "Spotlight.h"
#include <iostream>

Camera camera;
Light light[2];
Spotlight spotlight;
std::vector<Model*> models;
GLfloat globalAmbient[4] = { 0.7, 0.7, 0.7, 1.0 };
bool isWireFrame = false;
bool isLightLeftOn = false;
bool isLightRightOn = false;
bool isSpotlightOn = false;
float swingAngle = 0.0;
float swingSpeed = 5.0;

/*
	NOTE:
	- GL_COLOR_MATERIAL has been disabled fully in this program
	- However, color can still be set, just that the color effect will not be seen
*/

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
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), horizontal));

	translate = Transform(-((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), vertical));

	translate = Transform(-(roomWidth / 2), (roomHeight - 1), 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), horizontal));

	translate = Transform(((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	models.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), vertical));

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	models.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), vertical));
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
	models.push_back(createTorus(0.5, 1.0, translate, rotate, scale, COLOR_GREEN, createMaterial(GREEN_PLASTIC)));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(12.0, 10.0, 15.0);
	scale = Transform(1.5, 2.5, 1.5);
	models.push_back(createRegular(OCTAHEDRON, translate, rotate, scale, COLOR_ORANGE, createMaterial(PERL)));

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

void setUpLight()
{
	GLfloat* pointSourcePtr = NULL;
	GLfloat* ambientPtr = NULL;
	GLfloat* diffusePtr = NULL;
	GLfloat* specularPtr = NULL;

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			pointSourcePtr = new GLfloat[4] { -20.0f, 29.0f, 15.0f, 1.0f };
			ambientPtr = new GLfloat[4] { 0.4f, 0.4f, 0.4f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.722f, 0.525f, 0.043f, 1.0f };
			specularPtr = new GLfloat[4] { 0.0f, 0.0f, 0.0f, 1.0f };
		}
		else
		{
			pointSourcePtr = new GLfloat[4] { 20.0f, 29.0f, 15.0f, 1.0f };
			ambientPtr = new GLfloat[4] { 0.6f, 0.6f, 0.6f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.729f, 0.333f, 0.827f, 1.0f };
			specularPtr = new GLfloat[4] { 0.0f, 0.0f, 0.0f, 1.0f };
		}

		light[i].setPointSource(pointSourcePtr);
		light[i].setAmbient(ambientPtr);
		light[i].setDiffuse(diffusePtr);
		light[i].setSpecular(specularPtr);
	}

	delete[] pointSourcePtr;
	delete[] ambientPtr;
	delete[] diffusePtr;
	delete[] specularPtr;

	pointSourcePtr = NULL;
	ambientPtr = NULL;
	diffusePtr = NULL;
	specularPtr = NULL;
}

void setUpSpotlight()
{
	GLfloat pointSource[4] = { 0.0f, 27.5f, 13.0f, 1.0f };
	GLfloat ambient[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat direction[3] = { 0.0f, -1.0f, 0.0f };
	GLfloat cutOff = 30;
	GLfloat exponent = 40;

	spotlight.setPointSource(pointSource);
	spotlight.setAmbient(ambient);
	spotlight.setDiffuse(diffuse);
	spotlight.setSpecular(specular);
	spotlight.setDirection(direction);
	spotlight.setCutOff(cutOff);
	spotlight.setExponent(exponent);
}

void swingSpotlight(int value)
{
	static float radian = 0.0;
	swingAngle = 25.0 * sin(radian);

	radian = radian + ((MATH_PI * 2.0) / 135.0) * swingSpeed;

	if (radian > (MATH_PI * 2.0))
	{
		radian = radian - (MATH_PI * 2.0);
	}

	if (isSpotlightOn)
	{
		glutTimerFunc(10, swingSpotlight, 0);
	}

	glutPostRedisplay();
}

void drawSpotlight()
{
	GLfloat spotlightHolderMaterial[4][4] = {
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 0.9f, 0.9f, 0.9f, 1.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f }
	};

	GLfloat spotlightMaterial[4][4] = {
		{ 0.5f, 0.5f, 0.5f, 0.8f },
		{ 0.7f, 0.7f, 0.7f, 0.8f },
		{ 0.9f, 0.9f, 0.9f, 0.8f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	};

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glTranslatef(spotlight.getPointSource()[0], spotlight.getPointSource()[1] + 3.5, spotlight.getPointSource()[2]);
		glRotatef(swingAngle, 0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, spotlightHolderMaterial[0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, spotlightHolderMaterial[1]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spotlightHolderMaterial[2]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, spotlightHolderMaterial[3]);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			glTranslatef(0.0, 0.0, -3.5);
			glutSolidCone(1.0, 2.0, 30, 30);
		glPopMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, spotlightMaterial[0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, spotlightMaterial[1]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spotlightMaterial[2]);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
		glTranslatef(0.0, -3.5, 0.0);
		if (isSpotlightOn) {
			glPushMatrix();
				glTranslatef(-spotlight.getPointSource()[0], -spotlight.getPointSource()[1], -spotlight.getPointSource()[2]);
				glEnable(GL_LIGHT2);
				glLightfv(GL_LIGHT2, GL_POSITION, spotlight.getPointSource());
				glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotlight.getDirection());
				glLightfv(GL_LIGHT2, GL_AMBIENT, spotlight.getAmbient());
				glLightfv(GL_LIGHT2, GL_DIFFUSE, spotlight.getDiffuse());
				glLightfv(GL_LIGHT2, GL_SPECULAR, spotlight.getSpecular());
				glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spotlight.getCutOff());
				glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spotlight.getExponent());
			glPopMatrix();

			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, spotlightMaterial[3]);
		}
		else {
			glDisable(GL_LIGHT2);
		}
		glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glDisable(GL_BLEND);
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
	gluLookAt(camera.getPositionX(), camera.getPositionY(), camera.getPositionZ(),
				camera.getLookAtX(), camera.getLookAtY(), camera.getLookAtZ(), 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawLightBulbs();
	drawSpotlight();
	glPushMatrix();
		for (unsigned int i = 0; i < models.size(); i++)
		{
			models[i]->setIsWireFrame(isWireFrame);
			models[i]->draw();
		}
	glPopMatrix();

	glutSwapBuffers();
}

void processSpecialKey(int key, int m, int n)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			if (camera.getAngleX() > -(MIN_MAX_ROTATE_ANGLE))
			{
				camera.rotateX(camera.getAngleX() - 1.0);
			}

			break;
		case GLUT_KEY_RIGHT:
			if (camera.getAngleX() < MIN_MAX_ROTATE_ANGLE)
			{
				camera.rotateX(camera.getAngleX() + 1.0);
			}

			break;
		case GLUT_KEY_UP:
			if (camera.getAngleY() < MIN_MAX_ROTATE_ANGLE)
			{
				camera.rotateY(camera.getAngleY() + 1.0);
			}

			break;
		case GLUT_KEY_DOWN:
			if (camera.getAngleY() > -(MIN_MAX_ROTATE_ANGLE))
			{
				camera.rotateY(camera.getAngleY() - 1.0);
			}

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
		case GLUT_KEY_F4:
			isSpotlightOn = !isSpotlightOn;
			if (isSpotlightOn)
			{
				glutTimerFunc(10, swingSpotlight, 0);
			}
			break;
		case GLUT_KEY_END:
			disposeModels();
			exit(0);
			break;
		case GLUT_KEY_PAGE_UP:
			if (camera.getPositionZ() > 0)
			{
				camera.setPositionZ(camera.getPositionZ() - 5);
			}

			break;
		case GLUT_KEY_PAGE_DOWN:
			if (camera.getPositionZ() < 50)
			{
				camera.setPositionZ(camera.getPositionZ() + 5);
			}

			break;
	}
}

void processNormalKey(unsigned char key, int x, int y)
{
	switch (key)
	{
		case '+':
			if (isSpotlightOn && swingSpeed < 25.0)
			{
				swingSpeed += 1.0;
			}
			break;
		case '-':
			if (isSpotlightOn && swingSpeed > 5.0)
			{
				swingSpeed -= 1.0;
			}
			break;
	}
}

void setUpCamera()
{
	Point3D position = { 0.0, 15.0, 50 };
	Point3D lookAt = { 0.0, 15.0, 0.0 };
	Point3D angle = { 0.0, 0.0, 0.0 };

	camera.setPosition(position);
	camera.setInitialPosition(position);
	camera.setLookAt(lookAt);
	camera.setAngle(angle);
}

void init(void)
{
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_PROJECTION);
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
	init();

	setUpCamera();
	setUpLight();
	setUpSpotlight();
	createRoom();
	createProps();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(processNormalKey);
	glutSpecialFunc(processSpecialKey);
	glutMainLoop();

	disposeModels();

	return 0;
}