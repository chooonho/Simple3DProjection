/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "Model.h"

// Constructor
Model::Model()
{ 
	mScale = Transform(1.0, 1.0, 1.0);
}

Model::Model(Transform translate, Rotate rotate, Transform scale, std::vector<Mesh*> meshes)
{
	mTranslate = translate;
	mRotate = rotate;
	mScale = scale;
	mMeshes = meshes;
}

// Destructor
Model::~Model()
{
	while (!mMeshes.empty())
	{
		delete mMeshes.back();
		mMeshes.pop_back();
	}
}

// Getter function
Transform Model::getTranslate()
{
	return mTranslate;
}

GLdouble Model::getTranslateX()
{
	return mTranslate.getX();
}

GLdouble Model::getTranslateY()
{
	return mTranslate.getY();
}

GLdouble Model::getTranslateZ()
{
	return mTranslate.getZ();
}

Rotate Model::getRotate()
{
	return mRotate;
}

GLdouble Model::getRotateAngle()
{
	return mRotate.getAngle();
}

GLdouble Model::getRotateX()
{
	return mRotate.getX();
}

GLdouble Model::getRotateY()
{
	return mRotate.getY();
}

GLdouble Model::getRotateZ()
{
	return mRotate.getZ();
}

Rotate Model::getAnimateRotate()
{
	return mAnimateRotate;
}

GLdouble Model::getAnimateRotateAngle()
{
	return mAnimateRotate.getAngle();
}

GLdouble Model::getAnimateRotateX()
{
	return mAnimateRotate.getX();
}

GLdouble Model::getAnimateRotateY()
{
	return mAnimateRotate.getY();
}

GLdouble Model::getAnimateRotateZ()
{
	return mAnimateRotate.getZ();
}

Transform Model::getScale()
{
	return mScale;
}

GLdouble Model::getScaleX()
{
	return mScale.getX();
}

GLdouble Model::getScaleY()
{
	return mScale.getY();
}

GLdouble Model::getScaleZ()
{
	return mScale.getZ();
}

// Setter function
void Model::setTranslate(Transform translate)
{
	mTranslate = translate;
}

void Model::setTranslateX(GLdouble translateX)
{
	mTranslate.setX(translateX);
}

void Model::setTranslateY(GLdouble translateY)
{
	mTranslate.setY(translateY);
}

void Model::setTranslateZ(GLdouble translateZ)
{
	mTranslate.setZ(translateZ);
}

void Model::setRotate(Rotate rotate)
{
	mRotate = rotate;
}

void Model::setRotateAngle(GLdouble angle)
{
	mRotate.setAngle(angle);
}

void Model::setRotateX(GLdouble rotateX)
{
	mRotate.setX(rotateX);
}

void Model::setRotateY(GLdouble rotateY)
{
	mRotate.setY(rotateY);
}

void Model::setRotateZ(GLdouble rotateZ)
{
	mRotate.setZ(rotateZ);
}

void Model::setAnimateRotate(Rotate rotate)
{
	mAnimateRotate = rotate;
}

void Model::setAnimateRotateAngle(GLdouble angle)
{
	mAnimateRotate.setAngle(angle);
}

void Model::setAnimateRotateX(GLdouble rotateX)
{
	mAnimateRotate.setX(rotateX);
}

void Model::setAnimateRotateY(GLdouble rotateY)
{
	mAnimateRotate.setY(rotateY);
}

void Model::setAnimateRotateZ(GLdouble rotateZ)
{
	mAnimateRotate.setZ(rotateZ);
}

void Model::setScale(Transform scale)
{
	mScale = scale;
}

void Model::setScaleX(GLdouble scaleX)
{
	mScale.setX(scaleX);
}

void Model::setScaleY(GLdouble scaleY)
{
	mScale.setY(scaleY);
}

void Model::setScaleZ(GLdouble scaleZ)
{
	mScale.setY(scaleZ);
}

void Model::setMeshes(std::vector<Mesh*> meshes)
{
	mMeshes = meshes;
}

void Model::setIsWireFrame(bool isWireFrame)
{
	for (unsigned int i = 0; i < mMeshes.size(); i++)
	{
		mMeshes[i]->setIsWireFrame(isWireFrame);
	}
}

// Function for adding mesh to the model
void Model::addMesh(Mesh* mesh)
{
	mMeshes.push_back(mesh);
}

// Function for clearing all the meshes in the model
void Model::clearMesh()
{
	mMeshes.clear();
}

// Function that draws the model
void Model::draw()
{
	// Loops through each mesh
	// Calls the mesh draw function to render the mesh
	glPushMatrix();
		glTranslated(getTranslateX(), getTranslateY(), getTranslateZ());
		glRotated(getRotateAngle(), getRotateX(), getRotateY(), getRotateZ());
		glRotated(getAnimateRotateAngle(), getAnimateRotateX(), getAnimateRotateY(), getAnimateRotateZ());
		glScaled(getScaleX(), getScaleY(), getScaleZ());

		for (unsigned int i = 0; i < mMeshes.size(); i++)
		{
			mMeshes[i]->draw();
		}
	glPopMatrix();
}