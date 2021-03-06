/*******************************************************************************
*	Name				: OOI CHOON HO
*	Student ID			: 4805604
*	Coursework Title	: CSCI336 Assignment 2
*	Objecttive			: Develop a simple 3D scene
*******************************************************************************/

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

// Hide the console window
#pragma comment (linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

// Constant variables
const int MAX_DISCO_LIGHT_COUNT = 4;
const float MIN_SWING_SPEED = 5.0f;
const float MAX_SWING_SPEED = 50.0f;
const float MIN_SPIN_SPEED = 10.0f;
const float MAX_SPIN_SPEED = 30.0f;
const float MIN_JUMP_SHAKE_SPEED = 15.0f;
const float MAX_JUMP_SHAKE_SPEED = 35.0f;
const float MAX_BRIGHTNESS = 2.0f;
const float MIN_BRIGHTNESS = 0.0f;

// Global variables
Camera camera;
Light light[2];
Spotlight spotlight;
Spotlight discoLight[MAX_DISCO_LIGHT_COUNT];
std::vector<Model*> staticModels;
std::vector<Model*> variableModels;
GLfloat globalBrightness = 0.7f;
GLfloat globalAmbient[4] = { globalBrightness, globalBrightness, globalBrightness, 1.0f };
bool isWireFrame = false;
bool isSmoothShading = true;
bool isLightLeftOn = false;
bool isLightRightOn = false;
bool isSpotlightOn = false;
bool isDiscoLightOn = false;
bool isOnScreenHelpOn = true;
float swingAngle = 0.0f;
float spinAngle[2] = { 0.0f };
float swingSpeed = MIN_SWING_SPEED;
float spinSpeed = MIN_SPIN_SPEED;
float jumpShakeSpeed = MIN_JUMP_SHAKE_SPEED;
float jumpHeight = 0.0;
float shakeAngle = 0.0;
int font = (int)GLUT_BITMAP_8_BY_13;

/*
	NOTE:
	- GL_COLOR_MATERIAL has been disabled fully in this program
	- However, color can still be set, just that the color effect will not be seen
*/

// Initialize the values (position, ambient, diffuse and specular) of lights
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
			pointSourcePtr = new GLfloat[4]{ -20.0f, 29.0f, 15.0f, 1.0f };
			ambientPtr = new GLfloat[4]{ 0.4f, 0.4f, 0.4f, 1.0f };
			diffusePtr = new GLfloat[4]{ 0.722f, 0.525f, 0.043f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
		}
		else
		{
			pointSourcePtr = new GLfloat[4]{ 20.0f, 29.0f, 15.0f, 1.0f };
			ambientPtr = new GLfloat[4]{ 0.6f, 0.6f, 0.6f, 1.0f };
			diffusePtr = new GLfloat[4]{ 0.729f, 0.333f, 0.827f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
		}

		light[i].setPointSource(pointSourcePtr);
		light[i].setAmbient(ambientPtr);
		light[i].setDiffuse(diffusePtr);
		light[i].setSpecular(specularPtr);

		delete[] pointSourcePtr;
		delete[] ambientPtr;
		delete[] diffusePtr;
		delete[] specularPtr;

		pointSourcePtr = NULL;
		ambientPtr = NULL;
		diffusePtr = NULL;
		specularPtr = NULL;
	}
}

// Initialize the values(position, ambient, diffuse, specular, direction, cutoff, expoenent) of spotlight
void setUpSpotlight()
{
	GLfloat pointSource[4] = { 0.0f, 27.5f, 13.0f, 1.0f };
	GLfloat ambient[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat direction[3] = { 0.0f, -1.0f, 0.0f };
	GLfloat cutOff = 30.0f;
	GLfloat exponent = 40.0f;

	spotlight.setPointSource(pointSource);
	spotlight.setAmbient(ambient);
	spotlight.setDiffuse(diffuse);
	spotlight.setSpecular(specular);
	spotlight.setDirection(direction);
	spotlight.setCutOff(cutOff);
	spotlight.setExponent(exponent);
}

// Initialize the values(position, ambient, diffuse, specular, direction, cutoff, expoenent) of disco light
void setUpDiscoLight()
{
	GLfloat* pointSourcePtr = NULL;
	GLfloat* ambientPtr = NULL;
	GLfloat* diffusePtr = NULL;
	GLfloat* specularPtr = NULL;
	GLfloat* directionPtr = NULL;
	GLfloat cutOff = 5.0f;
	GLfloat exponent = 1.0f;

	for (int i = 0; i < MAX_DISCO_LIGHT_COUNT; i++)
	{
		switch (i)
		{
		case 0:
			pointSourcePtr = new GLfloat[4]{ -20.0f, 28.0f, 20.0f, 1.0f };
			ambientPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4]{ 1.0f, 0.0f, 0.0f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.8f, 0.0f, 0.0f, 1.0f };
			directionPtr = new GLfloat[4]{ 0.0f, 0.0f, -1.0f };
			break;
		case 1:
			pointSourcePtr = new GLfloat[4]{ -20.0f, 28.0f, 20.0f, 1.0f };
			ambientPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4]{ 0.0f, 1.0f, 0.0f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.0f, 0.8f, 0.0f, 1.0f };
			directionPtr = new GLfloat[4]{ 0.0f, 0.0f, -1.0f };
			break;
		case 2:
			pointSourcePtr = new GLfloat[4]{ -20.0f, 28.0f, 20.0f, 1.0f };
			ambientPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4]{ 0.0f, 0.0f, 1.0f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.8f, 1.0f };
			directionPtr = new GLfloat[4]{ 0.0f, 0.0f, -1.0f };
			break;
		case 3:
			pointSourcePtr = new GLfloat[4]{ -20.0f, 28.0f, 20.0f, 1.0f };
			ambientPtr = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4]{ 1.0f, 1.0f, 0.0f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.8f, 0.8f, 0.0f, 1.0f };
			directionPtr = new GLfloat[4]{ 0.0f, 0.0f, -1.0f };
			break;
		}

		discoLight[i].setPointSource(pointSourcePtr);
		discoLight[i].setAmbient(ambientPtr);
		discoLight[i].setDiffuse(diffusePtr);
		discoLight[i].setSpecular(specularPtr);
		discoLight[i].setDirection(directionPtr);
		discoLight[i].setCutOff(cutOff);
		discoLight[i].setExponent(exponent);

		delete[] pointSourcePtr;
		delete[] ambientPtr;
		delete[] diffusePtr;
		delete[] specularPtr;
		delete[] directionPtr;

		pointSourcePtr = NULL;
		ambientPtr = NULL;
		diffusePtr = NULL;
		specularPtr = NULL;
		directionPtr = NULL;
	}
}

// Draws the light bulbs and enable/disable the lights
void drawLightBulbs()
{
	// Variable declaration and initialization
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

	// Lights are wrapped with sphere to indicate its position
	// If the light is lit, sets the material emission 
	// Draw a sphere wrapping the light
	// Then enable the light if it is lit, disable it if it is not
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(light[0].getPointSource()[0], light[0].getPointSource()[1], light[0].getPointSource()[2]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lightBulbLeftMaterial[0]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lightBulbLeftMaterial[1]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lightBulbLeftMaterial[2]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0f);
	if (isLightLeftOn) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, lightBulbLeftMaterial[3]);
	}

	if (isWireFrame)
	{
		glutWireSphere(1.0f, 20, 20);
	}
	else
	{
		glutSolidSphere(1.0f, 20, 20);
	}
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
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0f);
	if (isLightRightOn) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, lightBulbRightMaterial[3]);
	}

	if (isWireFrame)
	{
		glutWireSphere(1.0f, 20, 20);
	}
	else
	{
		glutSolidSphere(1.0f, 20, 20);
	}
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

// Draw the spotlight and its holder and enable/disable the spotlight
void drawSpotlight()
{
	// Variable declaration and initialization
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

	// Draws the spotlight holder (a cone)
	// If the spotlight is lit, sets the material emission
	// Enable the spotlight if it is lit, disable it if it is not
	// Draw a sphere wrapping the spotlight
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(spotlight.getPointSource()[0], spotlight.getPointSource()[1] + 2.0f, spotlight.getPointSource()[2]);
	glRotatef(swingAngle, 0.0f, 0.0f, 1.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, spotlightHolderMaterial[0]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, spotlightHolderMaterial[1]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spotlightHolderMaterial[2]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, spotlightHolderMaterial[3]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0f);
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -2.0f);
	if (isWireFrame)
	{
		glutWireCone(1.0f, 2.0f, 20, 20);
	}
	else
	{
		glutSolidCone(1.0f, 2.0f, 20, 20);
	}
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, spotlightMaterial[0]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, spotlightMaterial[1]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spotlightMaterial[2]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0f);
	glTranslatef(0.0f, -2.0f, 0.0f);
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

	if (isWireFrame)
	{
		glutWireSphere(0.5f, 30, 30);
	}
	else
	{
		glutSolidSphere(0.5f, 30, 30);
	}
	glPopMatrix();

	glDisable(GL_BLEND);
}

// Draw the disco light and its holder and enable/disable the disco light
void drawDiscoLight()
{
	// Vairable declaration and initialization
	GLfloat discoLightHolderMaterial[4][4] = {
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 0.9f, 0.9f, 0.9f, 1.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f }
	};

	GLfloat discoLightMaterial[4][4][4] = {
		{
			{ 0.3f, 0.0f, 0.0f, 0.8f },
			{ 0.5f, 0.0f, 0.0f, 0.8f },
			{ 0.7f, 0.0f, 0.0f, 0.8f },
			{ 1.0f, 0.0f, 0.0f, 1.0f }
		},
		{
			{ 0.0f, 0.3f, 0.0f, 0.8f },
			{ 0.0f, 0.5f, 0.0f, 0.8f },
			{ 0.0f, 0.7f, 0.0f, 0.8f },
			{ 0.0f, 1.0f, 0.0f, 1.0f }
		},
		{
			{ 0.0f, 0.0f, 0.3f, 0.8f },
			{ 0.0f, 0.0f, 0.5f, 0.8f },
			{ 0.0f, 0.0f, 0.7f, 0.8f },
			{ 0.0f, 0.0f, 1.0f, 1.0f }
		},
		{
			{ 0.3f, 0.3f, 0.0f, 0.8f },
			{ 0.5f, 0.5f, 0.0f, 0.8f },
			{ 0.7f, 0.7f, 0.0f, 0.8f },
			{ 1.0f, 1.0f, 0.0f, 1.0f }
		}
	};

	// This disco light is actually made up of 4 spotlights,
	// each with different color (red, green, blue, yellow)
	// First, draw the disco light holder (a cube and a sphere)
	// Enable each of the spotlights if it is lit, disable them if it is not
	// If the spotlights are lit, sets the material emission
	// Draw spheres wrapping the spotlights
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(discoLight[0].getPointSource()[0], discoLight[0].getPointSource()[1], discoLight[0].getPointSource()[2] + 0.75f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, discoLightHolderMaterial[0]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, discoLightHolderMaterial[1]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, discoLightHolderMaterial[2]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, discoLightHolderMaterial[3]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
	if (isWireFrame)
	{
		glPushMatrix();
		glTranslatef(0.0, 1.0, 0.0);
		glScalef(1.0, 5.0, 1.0);
		glutWireCube(0.5);
		glPopMatrix();
		glutWireSphere(1.0, 20, 20);
	}
	else
	{
		glPushMatrix();
		glTranslatef(0.0, 1.0, 0.0);
		glScalef(1.0, 5.0, 1.0);
		glutSolidCube(0.5);
		glPopMatrix();
		glutSolidSphere(1.0, 20, 20);
	}

	for (int i = 0; i < MAX_DISCO_LIGHT_COUNT; i++)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, discoLightMaterial[i][0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, discoLightMaterial[i][1]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, discoLightMaterial[i][2]);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0f);

		glPushMatrix();
		glRotatef(spinAngle[1], 0.0f, 0.0f, 1.0f);
		switch (i)
		{
		case 0:
			glRotatef(spinAngle[0], 0.0f, 1.0f, 0.0f);
			break;
		case 1:
			glRotatef(spinAngle[0] + 90.0f, 0.0f, 1.0f, 0.0f);
			break;
		case 2:
			glRotatef(spinAngle[0] + 180.0f, 0.0f, 1.0f, 0.0f);
			break;
		case 3:
			glRotatef(spinAngle[0] + 270.0f, 0.0f, 1.0f, 0.0f);
			break;
		}
		glTranslatef(0.0f, 0.0f, -0.75f);

		if (isDiscoLightOn)
		{
			glPushMatrix();
			glTranslatef(-discoLight[0].getPointSource()[0], -discoLight[0].getPointSource()[1], -(discoLight[0].getPointSource()[2] + 0.75f));
			switch (i)
			{
			case 0:
				glEnable(GL_LIGHT3);
				glLightfv(GL_LIGHT3, GL_POSITION, discoLight[0].getPointSource());
				glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, discoLight[0].getDirection());
				glLightfv(GL_LIGHT3, GL_AMBIENT, discoLight[0].getAmbient());
				glLightfv(GL_LIGHT3, GL_DIFFUSE, discoLight[0].getDiffuse());
				glLightfv(GL_LIGHT3, GL_SPECULAR, discoLight[0].getSpecular());
				glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, discoLight[0].getCutOff());
				glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, discoLight[0].getExponent());

				glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, discoLightMaterial[0][3]);
				break;
			case 1:
				glEnable(GL_LIGHT4);
				glLightfv(GL_LIGHT4, GL_POSITION, discoLight[1].getPointSource());
				glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, discoLight[1].getDirection());
				glLightfv(GL_LIGHT4, GL_AMBIENT, discoLight[1].getAmbient());
				glLightfv(GL_LIGHT4, GL_DIFFUSE, discoLight[1].getDiffuse());
				glLightfv(GL_LIGHT4, GL_SPECULAR, discoLight[1].getSpecular());
				glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, discoLight[1].getCutOff());
				glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, discoLight[1].getExponent());

				glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, discoLightMaterial[1][3]);
				break;
			case 2:
				glEnable(GL_LIGHT5);
				glLightfv(GL_LIGHT5, GL_POSITION, discoLight[2].getPointSource());
				glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, discoLight[2].getDirection());
				glLightfv(GL_LIGHT5, GL_AMBIENT, discoLight[2].getAmbient());
				glLightfv(GL_LIGHT5, GL_DIFFUSE, discoLight[2].getDiffuse());
				glLightfv(GL_LIGHT5, GL_SPECULAR, discoLight[2].getSpecular());
				glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, discoLight[2].getCutOff());
				glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, discoLight[2].getExponent());

				glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, discoLightMaterial[2][3]);
				break;
			case 3:
				glEnable(GL_LIGHT6);
				glLightfv(GL_LIGHT6, GL_POSITION, discoLight[3].getPointSource());
				glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, discoLight[3].getDirection());
				glLightfv(GL_LIGHT6, GL_AMBIENT, discoLight[3].getAmbient());
				glLightfv(GL_LIGHT6, GL_DIFFUSE, discoLight[3].getDiffuse());
				glLightfv(GL_LIGHT6, GL_SPECULAR, discoLight[3].getSpecular());
				glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, discoLight[3].getCutOff());
				glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, discoLight[3].getExponent());

				glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, discoLightMaterial[3][3]);
				break;
			}
			glPopMatrix();
		}
		else
		{
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
			glDisable(GL_LIGHT5);
			glDisable(GL_LIGHT6);
		}

		if (isWireFrame)
		{
			glutWireSphere(0.5f, 20, 20);
		}
		else
		{
			glutSolidSphere(0.5f, 20, 20);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glDisable(GL_BLEND);
}

// Calculates the swinging angle for the spotlight
void swingSpotlight(int value)
{
	// Variable declaration and initialization
	// Static variable is used here to keep the value from resetting
	static float radian = 0.0f;

	// Swing angle is calculated using sin, adjusted by a constant value,
	// in this case is 25.0f
	// To make the swing goes left and right (e.g. -1 to 1), the radian (angle in radian)
	// has to go one whole round (using the nature of sin),
	// which is why the MATH_PI is multiplied by 2
	swingAngle = 25.0f * sin(radian);

	radian = radian + ((MATH_PI * 2.0f) / 135.0f) * swingSpeed;

	if (radian > (MATH_PI * 2.0f))
	{
		radian = radian - (MATH_PI * 2.0f);
	}

	if (isSpotlightOn)
	{
		glutTimerFunc(10, swingSpotlight, 0);
	}

	glutPostRedisplay();
}

// Calculates the spinning angle for the discolight
void spinDiscoLight(int value)
{
	// Variable declaration and initialization
	// Static variable is used here to keep the value from resetting
	static float radian = 0.0f;

	// Two spinning angles are used to make the disco light spin in different directions
	// First spin angle is adjusted by constant value
	// Second spin angle is calculated using sin, adjusted by a constant value,
	// in this case is 140.0f
	// To make the spin goes left and right (e.g. -1 to 1), the radian (angle in radian)
	// has to go one whole round (using the nature of sin),
	// which is why the MATH_PI is multiplied by 2
	spinAngle[0] += spinSpeed;
	spinAngle[1] = 140.0f * sin(radian);

	if (spinAngle[0] > 360.0f)
	{
		spinAngle[0] -= 360.0f;
	}

	radian = radian + ((MATH_PI * 2.0f) / 135.0f) * (spinSpeed / 2.0f);

	if (radian > (MATH_PI * 2.0f))
	{
		radian = radian - (MATH_PI * 2.0f);
	}

	if(isDiscoLightOn)
	{
		glutTimerFunc(10, spinDiscoLight, 0);
	}

	glutPostRedisplay();
}

// Calculates the shake angle and the jumping height of the variable models
void modelDance(int value)
{
	// Variable declaration and initialization
	// Static variables are used here to keep the values from resetting
	static float radianHeight = 0.0f;
	static float radianAngle = 0.0f;

	// Both the jumping height and shake angle is calculated using sin,
	// but the adjustment values are different
	// Jumping height does not go below 0.0f,
	// thus it only use half a round (using nature of sin)
	// Shake angle has to shake left and right (e.g. -1 to 1),
	// thus it has to use one full round (using nature of sin)
	jumpHeight = 3.0f * sin(radianHeight);
	radianHeight = radianHeight + (MATH_PI / 60.0f) * jumpShakeSpeed;
	if (radianHeight > MATH_PI)
	{
		radianHeight = radianHeight - MATH_PI;
	}

	shakeAngle = 20.0f * sin(radianAngle);
	radianAngle = radianAngle + (MATH_PI * 2.0f / 135.0f) * jumpShakeSpeed;
	if (radianAngle > (MATH_PI * 2.0f))
	{
		radianAngle = radianAngle - (MATH_PI * 2.0f);
	}

	if (isDiscoLightOn)
	{
		glutTimerFunc(10, modelDance, 0);
	}
	else
	{
		radianHeight = 0.0f;
		radianAngle = 0.0f;
		jumpHeight = 0.0f;
		shakeAngle = 0.0f;
	}

	glutPostRedisplay();
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

	// Calls model creator functions to create the models
	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	staticModels.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), horizontal));

	translate = Transform(-((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	staticModels.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), vertical));

	translate = Transform(-(roomWidth / 2), (roomHeight - 1), 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	staticModels.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), horizontal));

	translate = Transform(((roomWidth / 2) + 1), 0.0, 0.0);
	rotate = Rotate(270.0, 0.0, 1.0, 0.0);
	staticModels.push_back(createWall(((roomWidth / 2) + 1), roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), vertical));

	translate = Transform(-(roomWidth / 2), 0.0, 0.0);
	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	staticModels.push_back(createWall(roomWidth, roomHeight, translate, rotate, scale, COLOR_GRAY, createMaterial(POLISHED_SILVER), vertical));
}

void createProps()
{
	// Variable declaration and intialization
	Transform translate;
	Rotate rotate;
	Transform scale = Transform(1.0, 1.0, 1.0);

	// Calls model creator functions to create the models
	translate = Transform(-10.0, 1.0, 5.0);
	staticModels.push_back(createTable(25, 15, 6, translate, rotate, scale));

	rotate = Rotate(45.0, 0.0, 1.0, 0.0);
	translate = Transform(-20.0, 1.0, 12.0);
	staticModels.push_back(createChair(5, 5, 7, translate, rotate, scale));

	rotate = Rotate(270.0, 1.0, 0.0, 0.0);
	translate = Transform(-25.0, 1.0, 5.0);
	staticModels.push_back(createTree(translate, rotate, scale));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(22.0, 1.0, 15.0);
	variableModels.push_back(createRobot(translate, rotate, scale));

	rotate = Rotate(270.0, 1.0, 0.0, 0.0);
	translate = Transform(-6.0, 7.5, 10.0);
	variableModels.push_back(createCone(2.0, 4.0, translate, rotate, scale, COLOR_CYAN, createMaterial(CYAN_PLASTIC)));

	rotate = Rotate(0.0, 1.0, 0.0, 0.0);
	translate = Transform(-2.0, 9.0, 15.0);
	variableModels.push_back(createTeapot(2.0, translate, rotate, scale, COLOR_SILVER, createMaterial(SILVER)));

	rotate = Rotate(30.0, 0.0, 1.0, 0.0);
	translate = Transform(4.0, 9.0, 14.0);
	variableModels.push_back(createTorus(0.5, 1.0, translate, rotate, scale, COLOR_GREEN, createMaterial(GREEN_PLASTIC)));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(12.0, 10.0, 15.0);
	scale = Transform(1.5, 2.5, 1.5);
	variableModels.push_back(createRegular(OCTAHEDRON, translate, rotate, scale, COLOR_ORANGE, createMaterial(PERL)));

	rotate = Rotate(0.0, 0.0, 0.0, 0.0);
	translate = Transform(2.0, 9.0, 10.0);
	scale = Transform(1.0, 1.0, 1.0);
	variableModels.push_back(createRegular(DODECAHEDRON, translate, rotate, scale, COLOR_BLACK, createMaterial(OBSIDIAN)));

	rotate = Rotate(-20.0, 0.0, 0.0, 1.0);
	translate = Transform(7.0, 8.2, 13.0);
	scale = Transform(2.0, 2.0, 2.0);
	variableModels.push_back(createRegular(TETRAHEDRON, translate, rotate, scale, COLOR_YELLOW, createMaterial(YELLOW_RUBBER)));

	rotate = Rotate(0.0, 1.0, 0.0, 0.0);
	translate = Transform(10.0, 9.2, 11.0);
	scale = Transform(2.0, 2.0, 2.0);
	variableModels.push_back(createRegular(ICOSAHEDRON, translate, rotate, scale, COLOR_RED, createMaterial(RED_PLASTIC)));
}

// Renders a string onto the screen
void renderBitmapCharacter(int x, int y, void *font, char *string)
{
	char* characterPtr;

	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, 960, 0, 540);
		glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
			glColor3f(1.0, 1.0, 1.0);
			glRasterPos2d(x, y);
			for (characterPtr = string; *characterPtr != '\0'; characterPtr++) {
				glutBitmapCharacter(font, *characterPtr);
			}
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
}

// Displays on screen help to assist users
void printOnScreenHelp()
{
	// Lights has to be disabled before rendering the texts to prevent it
	// from blending the color of the texts
	// Lights shall be re-enabled after the texts are rendered
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);

	renderBitmapCharacter(10, 520, (void *)font, "On-Screen Help");
	renderBitmapCharacter(10, 510, (void *)font, "------------------------------");
	renderBitmapCharacter(10, 500, (void *)font, "0 - Toggle on-screen help on/off");
	if (isOnScreenHelpOn)
	{
		renderBitmapCharacter(10, 480, (void *)font, "Camera Control");
		renderBitmapCharacter(10, 470, (void *)font, "------------------------------");
		renderBitmapCharacter(10, 460, (void *)font, "Left Arrow     - Rotate camera left");
		renderBitmapCharacter(10, 445, (void *)font, "Right Arrow    - Rotate camera right");
		renderBitmapCharacter(10, 430, (void *)font, "Up Arrow       - Rotate camera up");
		renderBitmapCharacter(10, 415, (void *)font, "Down Arrow     - Rotate camera down");
		renderBitmapCharacter(10, 400, (void *)font, "Pg Up          - Zoom camera in");
		renderBitmapCharacter(10, 385, (void *)font, "Pg Dn          - Zoom camera out");
		renderBitmapCharacter(10, 370, (void *)font, "Home           - Reset camera position");

		renderBitmapCharacter(10, 350, (void *)font, "Mode and Shading Control");
		renderBitmapCharacter(10, 340, (void *)font, "------------------------------");
		renderBitmapCharacter(10, 330, (void *)font, "F1     - Toggle between wireframe/solid mode");
		renderBitmapCharacter(10, 315, (void *)font, "F2     - Toggle between smooth/flat shading");

		renderBitmapCharacter(10, 295, (void *)font, "Lighting Control");
		renderBitmapCharacter(10, 285, (void *)font, "------------------------------");
		renderBitmapCharacter(10, 275, (void *)font, "1     - Increase global ambient lighting");
		renderBitmapCharacter(10, 260, (void *)font, "2     - Decrease global ambient lighting");
		renderBitmapCharacter(10, 245, (void *)font, "3     - Turn on light on left");
		renderBitmapCharacter(10, 230, (void *)font, "4     - Turn on light on right");
		renderBitmapCharacter(10, 215, (void *)font, "5     - Turn on spotlight");
		renderBitmapCharacter(10, 200, (void *)font, "+     - Increase spotlight swing speed");
		renderBitmapCharacter(10, 185, (void *)font, "-     - Decrease spotlight swing speed");

		renderBitmapCharacter(10, 165, (void *)font, "Disco Control");
		renderBitmapCharacter(10, 155, (void *)font, "------------------------------");
		renderBitmapCharacter(10, 145, (void *)font, "6     - Toggle disco mode on/off");
		renderBitmapCharacter(10, 130, (void *)font, "+     - Increase disco light spin speed | model movement speed");
		renderBitmapCharacter(10, 115, (void *)font, "-     - Decrease disco light spin speed | model movement speed");

		renderBitmapCharacter(10, 30, (void *)font, "Extras");
		renderBitmapCharacter(10, 20, (void *)font, "------------------------------");
		renderBitmapCharacter(10, 10, (void *)font, "End    -  Quit");
	}

	glEnable(GL_LIGHTING);

	if (isLightLeftOn)
	{
		glEnable(GL_LIGHT0);
	}

	if (isLightRightOn)
	{
		glEnable(GL_LIGHT1);
	}
}

// Takes care of releasing the pointers assigned to models
void disposeModels()
{
	while (!staticModels.empty())
	{
		delete staticModels.back();
		staticModels.pop_back();
	}

	while (!variableModels.empty())
	{
		delete variableModels.back();
		variableModels.pop_back();
	}
}

// Initializes the position, lookat and angle of the camera
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

// Callback function for display
void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.getPositionX(), camera.getPositionY(), camera.getPositionZ(),
				camera.getLookAtX(), camera.getLookAtY(), camera.getLookAtZ(), 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Determine the shade model used
	// Draw the lights
	// Draw the models
	// Print on screen help
	if (isSmoothShading)
	{
		glShadeModel(GL_SMOOTH);
	}
	else
	{
		glShadeModel(GL_FLAT);
	}

	drawLightBulbs();
	drawSpotlight();
	drawDiscoLight();
	glPushMatrix();
		for (unsigned int i = 0; i < staticModels.size(); i++)
		{
				staticModels[i]->setIsWireFrame(isWireFrame);
				staticModels[i]->draw();
		}

		glTranslatef(0.0, jumpHeight, 0.0);
		for (unsigned int i = 0; i < variableModels.size(); i++)
		{
			variableModels[i]->setAnimateRotateAngle(shakeAngle);
			variableModels[i]->setAnimateRotateZ(1.0);
			variableModels[i]->setIsWireFrame(isWireFrame);
			variableModels[i]->draw();
		}
	glPopMatrix();
	printOnScreenHelp();

	glutSwapBuffers();
}

// Special key callback function
void processSpecialKey(int key, int m, int n)
{
	/*
		LIMITS:
		-	Camera rotation angle:
		--	Max and min is set to be 0.0 +- 45.0 (refer to Camera.h and Camera.cpp)
		-	Camera zoom in and out:
		--	Max and min is set to be 1.0 +- 0.5 (refer to Camera.h and Camera.cpp)
	*/

	/*
	*	Instructions are as below:
	*	F1 - Toggle between wireframe/solid
	*	F2 - Toggle between smooth/flat shading
	*	Home - Reset camera position
	*	Left - Rotate camera left
	*	Right - Rotate camera right
	*	Up - Rotate camera up
	*	Down - Rotate camera down
	*	Pg up - Zoom in camera
	*	Pg dn - Zoom out camera
	*	End - Quit program
	*/
	switch (key)
	{
		case GLUT_KEY_F1:
			isWireFrame = !isWireFrame;
			break;
		case GLUT_KEY_F2:
			isSmoothShading = !isSmoothShading;
			break;
		case GLUT_KEY_HOME:
			camera.resetToInitialPosition();
			break;
		case GLUT_KEY_LEFT:
			camera.rotateX(camera.getAngleX() - 2.0);
			break;
		case GLUT_KEY_RIGHT:
			camera.rotateX(camera.getAngleX() + 2.0);
			break;
		case GLUT_KEY_UP:
			camera.rotateY(camera.getAngleY() + 2.0);
			break;
		case GLUT_KEY_DOWN:
			camera.rotateY(camera.getAngleY() - 2.0);
			break;
		case GLUT_KEY_PAGE_UP:
			camera.zoomIn();
			break;
		case GLUT_KEY_PAGE_DOWN:
			camera.zoomOut();
			break;
		case GLUT_KEY_END:
			disposeModels();
			exit(0);
			break;
	}
}

// Normal key callback function
void processNormalKey(unsigned char key, int x, int y)
{
	/*
	*	Instructions are as below:
	*	1 - Increase global ambient
	*	2 - Decrease global ambient
	*	3 - Toggle left light (yellow) on/off
	*	4 - Toggle right light (purple) on/off
	*	5 - Toggle spotlight on/off
	*	6 - Toggle disco mode on/off
	*	+ - Increase swing speed of spotlight (if on)
	*	  - Increase spin speed of disco light (if on)
	*	  - Increase shake speed of models (if on)
	*	- - Decrease swing speed of spotlight (if on)
	*	  - Decrease spin speed of disco light (if on)
	*	  - Decrease shake speed of models (if on)
	*/

	switch (key)
	{
		case '1':
			if (globalBrightness < MAX_BRIGHTNESS)
			{
				globalBrightness += 0.1f;
				globalAmbient[0] = globalBrightness;
				globalAmbient[1] = globalBrightness;
				globalAmbient[2] = globalBrightness;
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
			}
			break;
		case '2':
			if (globalBrightness > MIN_BRIGHTNESS)
			{
				globalBrightness -= 0.1f;
				globalAmbient[0] = globalBrightness;
				globalAmbient[1] = globalBrightness;
				globalAmbient[2] = globalBrightness;
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
			}
			break;
		case '3':
			isLightLeftOn = !isLightLeftOn;
			break;
		case '4':
			isLightRightOn = !isLightRightOn;
			break;
		case '5':
			isSpotlightOn = !isSpotlightOn;
			if (isSpotlightOn)
			{
				glutTimerFunc(10, swingSpotlight, 0);
			}
			break;
		case '6':
			isDiscoLightOn = !isDiscoLightOn;
			if (isDiscoLightOn)
			{
				glutTimerFunc(10, spinDiscoLight, 0);
				glutTimerFunc(10, modelDance, 0);
			}
			break;
		case '+':
			if (isSpotlightOn && swingSpeed < MAX_SWING_SPEED)
			{
				swingSpeed += 1.0f;
			}

			if (isDiscoLightOn)
			{
				if (spinSpeed < MAX_SPIN_SPEED)
				{
					spinSpeed += 1.0f;
				}
				
				if (jumpShakeSpeed < MAX_JUMP_SHAKE_SPEED)
				{
					jumpShakeSpeed += 1.0f;
				}
			}
			break;
		case '-':
			if (isSpotlightOn && swingSpeed > MIN_SWING_SPEED)
			{
				swingSpeed -= 1.0;
			}

			if (isDiscoLightOn)
			{
				if (spinSpeed > MIN_SPIN_SPEED)
				{
					spinSpeed -= 1.0f;
				}

				if (jumpShakeSpeed > MIN_JUMP_SHAKE_SPEED)
				{
					jumpShakeSpeed -= 1.0f;
				}
			}
			break;
		case '0':
			isOnScreenHelpOn = !isOnScreenHelpOn;
			break;
	}
}

// Initialization for glut
void init(void)
{
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
	glLoadIdentity();
	gluPerspective(60.0, 1.78, 1.0, 100.0);
}

int main(int argc, char** argv)
{
	// Creates a window and position it
	// Setup camera
	// Setup lights
	// Create room
	// Create prop models
	// Register callback functions
	// Release pointer if the program terminated
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(960, 540);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Simple 3D Projection");
	init();

	setUpCamera();
	setUpLight();
	setUpSpotlight();
	setUpDiscoLight();
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