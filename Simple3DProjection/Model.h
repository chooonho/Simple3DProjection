#pragma once

#include <vector>
#include "Mesh.h"

struct Transform
{
	double x;
	double y;
	double z;
};

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
		void setTranslate(Transform translate);
		void setTranslateX(double translateX);
		void setTranslateY(double translateY);
		void setTranslateZ(double translateZ);
		void setRotate(Transform rotate);
		void setRotateX(double rotateX);
		void setRotateY(double rotateY);
		void setRotateZ(double rotateZ);
		void setScale(Transform scale);
		void setSclaeX(double scaleX);
		void setScaleY(double scaleY);
		void setScaleZ(double scaleZ);
		void setMeshes(std::vector<Mesh*> meshes);
		void addMesh(Mesh*);
		void clearMesh();
		void draw();
};