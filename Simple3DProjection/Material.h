#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include<GL/glut.h>

class Material
{
	private:
		GLfloat mAmbient[4];
		GLfloat mDiffuse[4];
		GLfloat	mSpecular[4];
		GLfloat mEmission[4];
		GLfloat mShine;
	public:
		Material();
		Material(GLfloat ambient[], GLfloat diffuse[], GLfloat specular[], GLfloat shine);
		const GLfloat* getAmbient();
		const GLfloat* getDiffuse();
		const GLfloat* getSpecular();
		const GLfloat* getEmission();
		GLfloat getShine();
		void setAmbient(GLfloat ambient[]);
		void setDiffuse(GLfloat diffuse[]);
		void setSpecular(GLfloat specular[]);
		void setEmission(GLfloat emission[]);
		void setShine(GLfloat shine);
		Material& operator=(const Material& rhMaterial);
};

#endif