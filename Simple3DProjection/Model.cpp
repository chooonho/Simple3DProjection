#include "Model.h"

Model::Model()
{
	mTranslate = { 0.0, 0.0, 0.0 };
	mRotate = { 0.0, 0.0, 0.0 };
	mScale = { 0.0, 0.0, 0.0 };
}

Model::Model(Transform translate, Transform rotate, Transform scale, std::vector<Mesh> meshes)
{
	mTranslate = translate;
	mRotate = rotate;
	mScale = scale;
	mMeshes = meshes;
}

Transform Model::getTranslate()
{
	return mTranslate;
}

double Model::getTranslateX()
{
	return mTranslate.x;
}

double Model::getTranslateY()
{
	return mTranslate.y;
}

double Model::getTranslateZ()
{
	return mTranslate.z;
}

Transform Model::getRotate()
{
	return mRotate;
}

double Model::getRotateX()
{
	return mRotate.x;
}

double Model::getRotateY()
{
	return mRotate.y;
}

double Model::getRotateZ()
{
	return mRotate.z;
}

Transform Model::getScale()
{
	return mScale;
}

double Model::getScaleX()
{
	return mScale.x;
}
double Model::getScaleY()
{
	return mScale.y;
}

double Model::getScaleZ()
{
	return mScale.z;
}

void Model::setTranslate(Transform translate)
{
	mTranslate = translate;
}

void Model::setTranslateX(double translateX)
{
	mTranslate.x = translateX;
}

void Model::setTranslateY(double translateY)
{
	mTranslate.y = translateY;
}

void Model::setTranslateZ(double translateZ)
{
	mTranslate.z = translateZ;
}

void Model::setRotate(Transform rotate)
{
	mRotate = rotate;
}

void Model::setRotateX(double rotateX)
{
	mRotate.x = rotateX;
}

void Model::setRotateY(double rotateY)
{
	mRotate.y = rotateY;
}

void Model::setRotateZ(double rotateZ)
{
	mRotate.z = rotateZ;
}

void Model::setScale(Transform scale)
{
	mScale = scale;
}

void Model::setSclaeX(double scaleX)
{
	mScale.x = scaleX;
}

void Model::setScaleY(double scaleY)
{
	mScale.y = scaleY;
}

void Model::setScaleZ(double scaleZ)
{
	mScale.z = scaleZ;
}

void Model::addMesh(Mesh* mesh)
{
	mMeshes.push_back(*(mesh));
}

void Model::clearMesh()
{
	mMeshes.clear();
}

void Model::draw()
{
	for (int i = 0; i < mMeshes.size(); i++)
	{
		mMeshes[i].draw();
	}
}