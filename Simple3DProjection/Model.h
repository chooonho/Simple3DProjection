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
		Transform mRotate;
		Transform mScale;
		std::vector<Mesh*> mMeshes;
	public:
		Model();
		Model(Transform, Transform, Transform, std::vector<Mesh*>);
		~Model();
		Transform getTranslate();
		double getTranslateX();
		double getTranslateY();
		double getTranslateZ();
		Transform getRotate();
		double getRotateX();
		double getRotateY();
		double getRotateZ();
		Transform getScale();
		double getScaleX();
		double getScaleY();
		double getScaleZ();
		void setTranslate(Transform);
		void setTranslateX(double);
		void setTranslateY(double);
		void setTranslateZ(double);
		void setRotate(Transform);
		void setRotateX(double);
		void setRotateY(double);
		void setRotateZ(double);
		void setScale(Transform);
		void setSclaeX(double);
		void setScaleY(double);
		void setScaleZ(double);
		void setMeshes(std::vector<Mesh*> meshes);
		void addMesh(Mesh*);
		void clearMesh();
		void draw();
};

#endif