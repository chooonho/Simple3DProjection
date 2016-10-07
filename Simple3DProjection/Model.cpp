#include "Model.h"

Model::Model()
{
	mTranslate = { 0.0, 0.0, 0.0 };
	mRotate = { 0.0, 0.0, 0.0 };
	mScale = { 0.0, 0.0, 0.0 };
}

Model::Model(Transform translate, Transform rotate, Transform scale, std::vector<Mesh*> meshes)
{
	mTranslate = translate;
	mRotate = rotate;
	mScale = scale;
	mMeshes = meshes;
}

Model::~Model()
{
	while (!mMeshes.empty())
	{
		delete mMeshes.back();
		mMeshes.pop_back();
	}
}

Transform Model::getTranslate()
{
	return mTranslate;
}

double Model::getTranslateX()
{
	return mTranslate.getX();
}

double Model::getTranslateY()
{
	return mTranslate.getY();
}

double Model::getTranslateZ()
{
	return mTranslate.getZ();
}

Transform Model::getRotate()
{
	return mRotate;
}

double Model::getRotateX()
{
	return mRotate.getX();
}

double Model::getRotateY()
{
	return mRotate.getY();
}

double Model::getRotateZ()
{
	return mRotate.getZ();
}

Transform Model::getScale()
{
	return mScale;
}

double Model::getScaleX()
{
	return mScale.getX();
}
double Model::getScaleY()
{
	return mScale.getY();
}

double Model::getScaleZ()
{
	return mScale.getZ();
}

void Model::setTranslate(Transform translate)
{
	mTranslate = translate;
}

void Model::setTranslateX(double translateX)
{
	mTranslate.setX(translateX);
}

void Model::setTranslateY(double translateY)
{
	mTranslate.setY(translateY);
}

void Model::setTranslateZ(double translateZ)
{
	mTranslate.setZ(translateZ);
}

void Model::setRotate(Transform rotate)
{
	mRotate = rotate;
}

void Model::setRotateX(double rotateX)
{
	mRotate.setX(rotateX);
}

void Model::setRotateY(double rotateY)
{
	mRotate.setY(rotateY);
}

void Model::setRotateZ(double rotateZ)
{
	mRotate.setZ(rotateZ);
}

void Model::setScale(Transform scale)
{
	mScale = scale;
}

void Model::setSclaeX(double scaleX)
{
	mScale.setX(scaleX);
}

void Model::setScaleY(double scaleY)
{
	mScale.setY(scaleY);
}

void Model::setScaleZ(double scaleZ)
{
	mScale.setY(scaleZ);
}

void Model::setMeshes(std::vector<Mesh*> meshes)
{
	mMeshes = meshes;
}

void Model::addMesh(Mesh* mesh)
{
	mMeshes.push_back(mesh);
}

void Model::clearMesh()
{
	mMeshes.clear();
}

void Model::draw()
{
	for (int i = 0; i < mMeshes.size(); i++)
	{
		mMeshes[i]->draw();
	}
}