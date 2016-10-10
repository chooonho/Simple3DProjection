#pragma once

#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "Transform.h"
#include "Mesh.h"

class Model
{
	private:
		Transform mTranslate;
		Rotate mRotate;
		Transform mScale;
		std::vector<Mesh*> mMeshes;
	public:
		Model();
		Model(Transform, Rotate, Transform, std::vector<Mesh*>);
		~Model();
		Transform getTranslate();
		GLdouble getTranslateX();
		GLdouble getTranslateY();
		GLdouble getTranslateZ();
		Rotate getRotate();
		GLdouble getRotateAngle();
		GLdouble getRotateX();
		GLdouble getRotateY();
		GLdouble getRotateZ();
		Transform getScale();
		GLdouble getScaleX();
		GLdouble getScaleY();
		GLdouble getScaleZ();
		void setTranslate(Transform);
		void setTranslateX(GLdouble);
		void setTranslateY(GLdouble);
		void setTranslateZ(GLdouble);
		void setRotate(Rotate);
		void setRotateAngle(GLdouble);
		void setRotateX(GLdouble);
		void setRotateY(GLdouble);
		void setRotateZ(GLdouble);
		void setScale(Transform);
		void setSclaeX(GLdouble);
		void setScaleY(GLdouble);
		void setScaleZ(GLdouble);
		void setMeshes(std::vector<Mesh*> meshes);
		void addMesh(Mesh*);
		void clearMesh();
		void draw();
};

#endif