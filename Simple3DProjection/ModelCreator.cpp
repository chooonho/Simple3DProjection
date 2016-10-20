/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "ModelCreator.h"
#include "Mesh.h"
#include "MeshCube.h"
#include "MeshSphere.h"
#include "MeshCone.h"
#include "MeshTeapot.h"
#include "MeshTorus.h"
#include "MeshRegular.h"

// Function that creates and return a model (name of model created are specified on the function name)
Model* createWall(int width, int height, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material, Orientation orientation)
{
	Model* model = new Model();
	model->setRotate(rotate);
	model->setTranslate(translate);
	model->setScale(scale);

	for (int w = 0; w < width; w++)
	{
		for (int h = 0; h < height; h++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(color);
			meshCube->setMaterial(material);

			meshCube->setTranslateX(w);
			if (orientation == horizontal)
			{
				meshCube->setTranslateZ(h);
			}
			else if (orientation == vertical)
			{
				meshCube->setTranslateY(h);
			}

			model->addMesh(meshCube);
		}
	}

	return model;
}

Model* createTable(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale)
{
	const int LEG_COUNT = 4;

	Model* model = new Model();
	model->setRotate(rotate);
	model->setTranslate(translate);
	model->setScale(scale);

	for (int w = 0; w < width; w++)
	{
		for (int d = 0; d < depth; d++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(COLOR_SADDLE_BROWN);
			meshCube->setTranslateY(height);
			meshCube->setTranslateX(w);
			meshCube->setTranslateZ(d);
			meshCube->setMaterial(createMaterial(BRASS));

			model->addMesh(meshCube);
		}
	}

	for (int w = 2; w < ((width - 2) * 2); w++)
	{
		MeshCube* meshCubeFront = new MeshCube;
		meshCubeFront->setSize(0.5);
		meshCubeFront->setColor(COLOR_DARK_BROWN);
		meshCubeFront->setTranslateY(height - 1);
		meshCubeFront->setTranslateX(w * 0.5);
		meshCubeFront->setTranslateZ(depth - 2);
		meshCubeFront->setMaterial(createMaterial(POLISHED_BRONZE));

		MeshCube* meshCubeBack = new MeshCube;
		meshCubeBack->setSize(0.5);
		meshCubeBack->setColor(COLOR_DARK_BROWN);
		meshCubeBack->setTranslateY(height - 1);
		meshCubeBack->setTranslateX(w * 0.5);
		meshCubeBack->setTranslateZ(1);
		meshCubeBack->setMaterial(createMaterial(POLISHED_BRONZE));

		model->addMesh(meshCubeFront);
		model->addMesh(meshCubeBack);
	}

	for (int d = 2; d < ((depth - 2) * 2); d++)
	{
		MeshCube* meshCubeLeft = new MeshCube;
		meshCubeLeft->setSize(0.5);
		meshCubeLeft->setColor(COLOR_DARK_BROWN);
		meshCubeLeft->setTranslateY(height - 1);
		meshCubeLeft->setTranslateX(1.0);
		meshCubeLeft->setTranslateZ(d * 0.5);
		meshCubeLeft->setMaterial(createMaterial(POLISHED_BRONZE));

		MeshCube* meshCubeRight = new MeshCube;
		meshCubeRight->setSize(0.5);
		meshCubeRight->setColor(COLOR_DARK_BROWN);
		meshCubeRight->setTranslateY(height - 1);
		meshCubeRight->setTranslateX(width - 2);
		meshCubeRight->setTranslateZ(d * 0.5);
		meshCubeRight->setMaterial(createMaterial(POLISHED_BRONZE));

		model->addMesh(meshCubeLeft);
		model->addMesh(meshCubeRight);
	}

	for (int i = 0; i < LEG_COUNT; i++)
	{
		for (int h = 0; h < height; h++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(COLOR_SADDLE_BROWN);
			meshCube->setMaterial(createMaterial(BRASS));
			
			meshCube->setTranslateY(h);
			switch (i)
			{
				case 0:
					meshCube->setTranslateX(1.0);
					meshCube->setTranslateZ(1.0);
					break;
				case 1:
					meshCube->setTranslateX(width - 2);
					meshCube->setTranslateZ(1.0);
					break;
				case 2:
					meshCube->setTranslateX(width - 2);
					meshCube->setTranslateZ(depth - 2);
					break;
				case 3:
					meshCube->setTranslateX(1.0);
					meshCube->setTranslateZ(depth - 2);
					break;
			}

			model->addMesh(meshCube);
		}
	}

	return model;
}

Model* createChair(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale)
{
	const int LEG_COUNT = 4;

	Model* model = new Model();
	model->setRotate(rotate);
	model->setTranslate(translate);
	model->setScale(scale);

	for (int w = 0; w < width; w++)
	{
		for (int d = 0; d < depth; d++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(COLOR_DARK_BROWN);
			meshCube->setTranslateY(height / 2);
			meshCube->setTranslateX(w);
			meshCube->setTranslateZ(d);
			meshCube->setMaterial(createMaterial(POLISHED_BRONZE));

			model->addMesh(meshCube);
		}
	}

	for (int w = 0; w < width; w++)
	{
		for (int h = (height - (height / 3)); h < (height + 1); h++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(COLOR_DARK_BROWN);
			meshCube->setTranslateY(h);
			meshCube->setTranslateX(w);
			meshCube->setMaterial(createMaterial(POLISHED_BRONZE));

			model->addMesh(meshCube);
		}
	}

	for (int h = ((height / 2) + 1); h < (height + 1); h++)
	{
		MeshCube* meshCubeLeft = new MeshCube;
		meshCubeLeft->setSize(1.0);
		meshCubeLeft->setColor(COLOR_SADDLE_BROWN);
		meshCubeLeft->setTranslateY(h);
		meshCubeLeft->setMaterial(createMaterial(BRASS));

		MeshCube* meshCubeRight = new MeshCube;
		meshCubeRight->setSize(1.0);
		meshCubeRight->setColor(COLOR_SADDLE_BROWN);
		meshCubeRight->setTranslateY(h);
		meshCubeRight->setTranslateX(width - 1);
		meshCubeRight->setMaterial(createMaterial(BRASS));

		model->addMesh(meshCubeLeft);
		model->addMesh(meshCubeRight);
	}

	for (int i = 0; i < LEG_COUNT; i++)
	{
		for (int h = 0; h < (height / 2); h++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(COLOR_SADDLE_BROWN);
			meshCube->setMaterial(createMaterial(BRASS));

			meshCube->setTranslateY(h);
			switch (i)
			{
				case 0:
					meshCube->setTranslateX(0.0);
					meshCube->setTranslateZ(0.0);
					break;
				case 1:
					meshCube->setTranslateX(width - 1.0);
					meshCube->setTranslateZ(0.0);
					break;
				case 2:
					meshCube->setTranslateX(width - 1.0);
					meshCube->setTranslateZ(depth - 1.0);
					break;
				case 3:
					meshCube->setTranslateX(0.0);
					meshCube->setTranslateZ(depth - 1.0);
					break;
			}

			model->addMesh(meshCube);
		}
	}

	return model;
}

Model* createRobot(Transform translate, Rotate rotate, Transform scale)
{
	const int ARM_COUNT = 2;
	const int LEG_COUNT = 2;
	const int EYE_COUNT = 2;
	const double ROBOT_HEAD_SIZE = 1.5;
	const double ROBOT_BODY_SIZE = 4.0;
	const double ROBOT_LEG_SIZE = 1.0;
	const double ROBOT_ARM_SIZE = 1.0;

	Model* model = new Model;
	model->setTranslate(translate);
	model->setRotate(rotate);
	model->setScale(scale);

	for (int i = 0; i < LEG_COUNT; i++)
	{
		double legOffsetX;

		if (i == 0)
		{
			legOffsetX = 0.0;
		}
		else
		{
			legOffsetX = ROBOT_BODY_SIZE / 2.0;
		}

		MeshCube* upperLeg = new MeshCube();
		upperLeg->setColor(COLOR_RED);
		upperLeg->setSize(ROBOT_LEG_SIZE);
		upperLeg->setTranslateY(ROBOT_LEG_SIZE * 3.1);
		upperLeg->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));
		upperLeg->setMaterial(createMaterial(RUBY));

		MeshSphere* knee = new MeshSphere();
		knee->setColor(COLOR_YELLOW);
		knee->setRadius(ROBOT_LEG_SIZE * 0.8);
		knee->setSliceCount(10);
		knee->setStackCount(10);
		knee->setTranslateY(ROBOT_LEG_SIZE * 2.3);
		knee->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));
		knee->setMaterial(createMaterial(GOLD));

		MeshCube* lowerLeg = new MeshCube();
		lowerLeg->setColor(COLOR_RED);
		lowerLeg->setSize(ROBOT_LEG_SIZE);
		lowerLeg->setTranslateY(ROBOT_LEG_SIZE * 1.5);
		lowerLeg->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));
		lowerLeg->setMaterial(createMaterial(RUBY));

		MeshSphere* ankle = new MeshSphere();
		ankle->setColor(COLOR_YELLOW);
		ankle->setSliceCount(10);
		ankle->setStackCount(10);
		ankle->setRadius(ROBOT_LEG_SIZE * 0.8);
		ankle->setTranslateY(ROBOT_LEG_SIZE * 0.5);
		ankle->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));
		ankle->setMaterial(createMaterial(GOLD));

		MeshCube* frontFoot = new MeshCube();
		frontFoot->setColor(COLOR_RED);
		frontFoot->setSize(ROBOT_LEG_SIZE);
		frontFoot->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));
		frontFoot->setMaterial(createMaterial(RUBY));

		MeshCube* backFoot = new MeshCube();
		backFoot->setColor(COLOR_RED);
		backFoot->setSize(ROBOT_LEG_SIZE);
		backFoot->setTranslateZ(ROBOT_LEG_SIZE);
		backFoot->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));
		backFoot->setMaterial(createMaterial(RUBY));

		model->addMesh(upperLeg);
		model->addMesh(lowerLeg);
		model->addMesh(knee);
		model->addMesh(ankle);
		model->addMesh(backFoot);
		model->addMesh(frontFoot);
	}

	for (int i = 0; i < EYE_COUNT; i++)
	{
		double eyeOffsetX;

		if (i == 0)
		{
			eyeOffsetX = 0;
		}
		else
		{
			eyeOffsetX = ROBOT_HEAD_SIZE / 2.0;
		}

		MeshCube* eye = new MeshCube();
		eye->setColor(COLOR_RED);
		eye->setMaterial(createMaterial(RUBY));
		eye->setSize(0.5);
		eye->setTranslateX(eyeOffsetX - (ROBOT_HEAD_SIZE / 4));
		eye->setTranslateY(ROBOT_HEAD_SIZE * 5.75);
		eye->setTranslateZ(1);

		model->addMesh(eye);
	}

	for (int i = 0; i < ARM_COUNT; i++)
	{
		double armOffsetX;

		if (i == 0)
		{
			armOffsetX = 0 - 0.6;
		}
		else
		{
			armOffsetX = ROBOT_BODY_SIZE + 0.6;
		}

		MeshSphere* shoulder = new MeshSphere();
		shoulder->setColor(COLOR_YELLOW);
		shoulder->setRadius(ROBOT_ARM_SIZE * 0.85);
		shoulder->setSliceCount(10);
		shoulder->setStackCount(10);
		shoulder->setTranslateY(ROBOT_ARM_SIZE * 6.5);
		shoulder->setTranslateX(armOffsetX - (ROBOT_BODY_SIZE / 2));
		shoulder->setMaterial(createMaterial(GOLD));

		MeshCube* arm = new MeshCube();
		arm->setColor(COLOR_RED);
		arm->setMaterial(createMaterial(RUBY));
		arm->setSize(ROBOT_ARM_SIZE);
		arm->setTranslateY(ROBOT_ARM_SIZE * 5.0);
		arm->setTranslateX(armOffsetX - (ROBOT_BODY_SIZE / 2));
		arm->setScaleY(2);

		MeshCube* hand = new MeshCube();
		hand->setColor(COLOR_YELLOW);
		hand->setMaterial(createMaterial(GOLD));
		hand->setSize(ROBOT_ARM_SIZE);
		hand->setTranslateY(ROBOT_ARM_SIZE * 3.5);
		hand->setTranslateX(armOffsetX - (ROBOT_BODY_SIZE / 2));
		
		model->addMesh(shoulder);
		model->addMesh(arm);
		model->addMesh(hand);
	}

	for (int x = 0; x < ROBOT_HEAD_SIZE; x++)
	{
		for (int y = 0; y < ROBOT_HEAD_SIZE; y++)
		{
			for (int z = 0; z < ROBOT_HEAD_SIZE; z++)
			{
				MeshCube* head = new MeshCube();
				head->setColor(COLOR_YELLOW);
				head->setMaterial(createMaterial(GOLD));
				head->setSize(1.0);
				head->setTranslateX(x - 0.5);
				head->setTranslateY(y + 7.75);
				head->setTranslateZ(z - 0.5);

				model->addMesh(head);
			}
		}
	}

	for (int x = 0; x < ROBOT_BODY_SIZE; x++)
	{
		for (int y = 0; y < ROBOT_BODY_SIZE; y++)
		{
			for (int z = 0; z < (ROBOT_BODY_SIZE / 2); z++)
			{
				MeshCube* body = new MeshCube();
				body->setColor(COLOR_RED);
				body->setMaterial(createMaterial(RUBY));
				body->setSize(1.0);
				body->setTranslateX(x - 1.5);
				body->setTranslateY(y + ROBOT_BODY_SIZE - 0.25);
				body->setTranslateZ(z - 0.5);

				model->addMesh(body);
			}
		}
	}

	return model;
}

Model* createTree(Transform translate, Rotate rotate, Transform scale)
{
	const int TREE_UPPER_COUNT = 2;

	Model* model = new Model();
	model->setTranslate(translate);
	model->setRotate(rotate);
	model->setScale(scale);

	for (int i = 0; i < TREE_UPPER_COUNT; i++)
	{
		MeshCone* treeUpper = new MeshCone();
		treeUpper->setColor(COLOR_GREEN);
		treeUpper->setBase(4.0);
		treeUpper->setHeight(10.0);
		treeUpper->setSliceCount(10);
		treeUpper->setStackCount(10);
		treeUpper->setTranslateZ(5.0 * (i + 1));
		treeUpper->setMaterial(createMaterial(EMERALD));

		model->addMesh(treeUpper);
	}

	MeshCone* treeStem = new MeshCone();
	treeStem->setColor(COLOR_DARK_BROWN);
	treeStem->setBase(1.0);
	treeStem->setHeight(10.0);
	treeStem->setSliceCount(10);
	treeStem->setStackCount(10);
	treeStem->setMaterial(createMaterial(POLISHED_BRONZE));

	model->addMesh(treeStem);

	return model;
}

Model* createCone(double base, double height, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material)
{
	Model* model = new Model();
	model->setTranslate(translate);
	model->setRotate(rotate);
	model->setScale(scale);

	MeshCone* meshCone = new MeshCone();
	meshCone->setBase(base);
	meshCone->setHeight(height);
	meshCone->setColor(color);
	meshCone->setSliceCount(10);
	meshCone->setStackCount(10);
	meshCone->setMaterial(material);

	model->addMesh(meshCone);

	return model;
}

Model* createTeapot(double size, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material)
{
	Model* model = new Model();
	model->setTranslate(translate);
	model->setRotate(rotate);
	model->setScale(scale);

	MeshTeapot* meshTeapot = new MeshTeapot();
	meshTeapot->setSize(size);
	meshTeapot->setColor(color);
	meshTeapot->setMaterial(material);

	model->addMesh(meshTeapot);

	return model;
}

Model* createTorus(double innerRadius, double outerRadius, Transform translate, Rotate rotate,
					Transform scale, ColorRGBA4D color, Material material)
{
	Model* model = new Model();
	model->setTranslate(translate);
	model->setRotate(rotate);
	model->setScale(scale);

	MeshTorus* meshTorus = new MeshTorus();
	meshTorus->setInnerRadius(innerRadius);
	meshTorus->setOuterRadius(outerRadius);
	meshTorus->setNSideCount(10);
	meshTorus->setRingCount(10);
	meshTorus->setColor(color);
	meshTorus->setMaterial(material);

	model->addMesh(meshTorus);

	return model;
}

Model* createRegular(RegularType regularType, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material)
{
	Model* model = new Model();
	model->setTranslate(translate);
	model->setRotate(rotate);
	model->setScale(scale);

	MeshRegular* meshRegular = new MeshRegular(regularType);
	meshRegular->setColor(color);
	meshRegular->setMaterial(material);

	model->addMesh(meshRegular);

	return model;
}

// Function that creates material based on the material types specified in parameter
Material createMaterial(MaterialType materialType)
{
	Material material;
	GLfloat* ambientPtr;
	GLfloat* diffusePtr;
	GLfloat* specularPtr;
	GLfloat shine;

	/*
	*	The values below are some sample materials obtained from an online open source
	*/
	switch (materialType)
	{
		case SILVER:
			ambientPtr = new GLfloat[4] { 0.19225f, 0.19225f, 0.19225f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.50754f, 0.50754f, 0.50754f, 1.0f };
			specularPtr = new GLfloat[4] { 0.508273f, 0.508273f, 0.508273f, 1.0f };
			shine = 51.2f;

			break;
		case RUBY:
			ambientPtr = new GLfloat[4] { 0.1745f, 0.01175f, 0.01175f, 0.55f };
			diffusePtr = new GLfloat[4] { 0.61424f, 0.04136f, 0.04136f, 0.55f };
			specularPtr = new GLfloat[4] { 0.727811f, 0.626959f, 0.626959f, 0.55f };
			shine = 76.8f;

			break;
		case CYAN_PLASTIC:
			ambientPtr = new GLfloat[4] { 0.0f, 0.1f, 0.06f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.0f, 0.50980392f, 0.50980392f, 1.0f };
			specularPtr = new GLfloat[4] { 0.50196078f, 0.50196078f, 0.50196078f, 1.0f };
			shine = 32.0f;

			break;
		case GOLD:
			ambientPtr = new GLfloat[4] { 0.24725f, 0.1995f, 0.0745f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.75164f, 0.60648f, 0.22648f, 1.0f };
			specularPtr = new GLfloat[4] { 0.628281f, 0.555802f, 0.366065f, 1.0f };
			shine = 51.2f;

			break;
		case YELLOW_RUBBER:
			ambientPtr = new GLfloat[4] { 0.05f, 0.05f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.5f, 0.5f, 0.4f, 1.0f };
			specularPtr = new GLfloat[4] { 0.7f, 0.7f, 0.04f, 1.0f };
			shine = 10.0f;

			break;
		case EMERALD:
			ambientPtr = new GLfloat[4] { 0.0215f, 0.1745f, 0.0215f, 0.55f };
			diffusePtr = new GLfloat[4] { 0.07568f, 0.61424f, 0.07568f, 0.55f };
			specularPtr = new GLfloat[4] { 0.633f, 0.727811f, 0.633f, 0.55f };
			shine = 76.8f;

			break;
		case GREEN_PLASTIC:
			ambientPtr = new GLfloat[4] { 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.1f, 0.35f, 0.1f, 1.0f };
			specularPtr = new GLfloat[4] { 0.45f, 0.55f, 0.45f, 1.0f };
			shine = 32.0f;

			break;
		case BRASS:
			ambientPtr = new GLfloat[4]{ 0.329412f, 0.223529f, 0.027451f, 1.0f };
			diffusePtr = new GLfloat[4]{ 0.780392f, 0.568627f, 0.113725f, 1.0f };
			specularPtr = new GLfloat[4]{ 0.992157f, 0.941176f, 0.807843f, 1.0f };
			shine = 27.8974f;

			break;
		case PERL:
			ambientPtr = new GLfloat[4] { 0.25f, 0.20725f, 0.20725f, 0.922f };
			diffusePtr = new GLfloat[4] { 1.0f, 0.829f, 0.829f, 0.922f };
			specularPtr = new GLfloat[4] { 0.296648f, 0.296648f, 0.296648f, 0.922f };
			shine = 11.264f;

			break;
		case POLISHED_BRONZE:
			ambientPtr = new GLfloat[4] { 0.25f, 0.148f, 0.06475f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.4f, 0.2368f, 0.1036f, 1.0f };
			specularPtr = new GLfloat[4] { 0.774597f, 0.458561f, 0.200621f, 1.0f };
			shine = 76.8f;

			break;
		case RED_PLASTIC:
			ambientPtr = new GLfloat[4] { 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.5f, 0.0f, 0.0f, 1.0f };
			specularPtr = new GLfloat[4] { 0.7f, 0.6f, 0.6f, 1.0f };
			shine = 32.0f;

			break;
		case OBSIDIAN:
			ambientPtr = new GLfloat[4] { 0.0f, 0.0f, 0.0f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.5f, 0.0f, 0.0f, 1.0f };
			specularPtr = new GLfloat[4] { 0.7f, 0.6f, 0.6f, 1.0f };
			shine = 32.0f;

			break;
		case POLISHED_SILVER:
			ambientPtr = new GLfloat[4] { 0.23125f, 0.23125f, 0.23125f, 1.0f };
			diffusePtr = new GLfloat[4] { 0.2775f, 0.2775f, 0.2775f, 1.0f };
			specularPtr = new GLfloat[4] { 0.773911f, 0.773911f, 0.773911f, 1.0f };
			shine = 89.6f;

			break;
		default:
			ambientPtr = new GLfloat[4] { 0.05375f, 0.05f, 0.06625f, 0.82f };
			diffusePtr = new GLfloat[4] { 0.18275f, 0.17f, 0.22525f, 0.82f };
			specularPtr = new GLfloat[4] { 0.332741f, 0.328634f, 0.346435f, 0.82f };
			shine = 38.4f;
	}

	material.setAmbient(ambientPtr);
	material.setDiffuse(diffusePtr);
	material.setSpecular(specularPtr);
	material.setShine(shine);

	delete[] ambientPtr;
	delete[] diffusePtr;
	delete[] specularPtr;

	ambientPtr = NULL;
	diffusePtr = NULL;
	specularPtr = NULL;

	return material;
}