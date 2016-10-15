#include "ModelCreator.h"
#include "Mesh.h"
#include "MeshCube.h"
#include "MeshSphere.h"

Model* createWall(int width, int height, Transform translate, Rotate rotate, Transform scale, ColorRGB3F color, Orientation orientation)
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

		MeshCube* meshCubeBack = new MeshCube;
		meshCubeBack->setSize(0.5);
		meshCubeBack->setColor(COLOR_DARK_BROWN);
		meshCubeBack->setTranslateY(height - 1);
		meshCubeBack->setTranslateX(w * 0.5);
		meshCubeBack->setTranslateZ(1);

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

		MeshCube* meshCubeRight = new MeshCube;
		meshCubeRight->setSize(0.5);
		meshCubeRight->setColor(COLOR_DARK_BROWN);
		meshCubeRight->setTranslateY(height - 1);
		meshCubeRight->setTranslateX(width - 2);
		meshCubeRight->setTranslateZ(d * 0.5);

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

			model->addMesh(meshCube);
		}
	}

	for (int w = 0; w < width; w++)
	{
		for (int h = (height - (height / 4)); h < height; h++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(COLOR_DARK_BROWN);
			meshCube->setTranslateY(h);
			meshCube->setTranslateX(w);

			model->addMesh(meshCube);
		}
	}

	for (int h = (height / 2); h < height; h++)
	{
		MeshCube* meshCubeLeft = new MeshCube;
		meshCubeLeft->setSize(1.0);
		meshCubeLeft->setColor(COLOR_SADDLE_BROWN);
		meshCubeLeft->setTranslateY(h);

		MeshCube* meshCubeRight = new MeshCube;
		meshCubeRight->setSize(1.0);
		meshCubeRight->setColor(COLOR_SADDLE_BROWN);
		meshCubeRight->setTranslateY(h);
		meshCubeRight->setTranslateX(width - 1);

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

	// Left leg meshes
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

		MeshSphere* knee = new MeshSphere();
		knee->setColor(COLOR_YELLOW);
		knee->setRadius(ROBOT_LEG_SIZE * 0.8);
		knee->setSliceCount(10);
		knee->setStackCount(10);
		knee->setTranslateY(ROBOT_LEG_SIZE * 2.3);
		knee->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));

		MeshCube* lowerLeg = new MeshCube();
		lowerLeg->setColor(COLOR_RED);
		lowerLeg->setSize(ROBOT_LEG_SIZE);
		lowerLeg->setTranslateY(ROBOT_LEG_SIZE * 1.5);
		lowerLeg->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));

		MeshSphere* ankle = new MeshSphere();
		ankle->setColor(COLOR_YELLOW);
		ankle->setSliceCount(10);
		ankle->setStackCount(10);
		ankle->setRadius(ROBOT_LEG_SIZE * 0.8);
		ankle->setTranslateY(ROBOT_LEG_SIZE * 0.5);
		ankle->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));

		MeshCube* frontFoot = new MeshCube();
		frontFoot->setColor(COLOR_RED);
		frontFoot->setSize(ROBOT_LEG_SIZE);
		frontFoot->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));

		MeshCube* backFoot = new MeshCube();
		backFoot->setColor(COLOR_RED);
		backFoot->setSize(ROBOT_LEG_SIZE);
		backFoot->setTranslateZ(ROBOT_LEG_SIZE);
		backFoot->setTranslateX(legOffsetX - (ROBOT_BODY_SIZE / 4));

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
		eye->setSize(0.5);
		eye->setTranslateX(eyeOffsetX - (ROBOT_HEAD_SIZE / 4));
		eye->setTranslateY(ROBOT_HEAD_SIZE * 5.4);
		eye->setTranslateZ(0.6);

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

		MeshCube* arm = new MeshCube();
		arm->setColor(COLOR_RED);
		arm->setSize(ROBOT_ARM_SIZE);
		arm->setTranslateY(ROBOT_ARM_SIZE * 5.0);
		arm->setTranslateX(armOffsetX - (ROBOT_BODY_SIZE / 2));
		arm->setScaleY(2);

		MeshCube* hand = new MeshCube();
		hand->setColor(COLOR_YELLOW);
		hand->setSize(ROBOT_ARM_SIZE);
		hand->setTranslateY(ROBOT_ARM_SIZE * 3.5);
		hand->setTranslateX(armOffsetX - (ROBOT_BODY_SIZE / 2));
		
		model->addMesh(shoulder);
		model->addMesh(arm);
		model->addMesh(hand);
	}

	MeshCube* head = new MeshCube();
	head->setColor(COLOR_YELLOW);
	head->setSize(ROBOT_HEAD_SIZE);
	head->setTranslateY(ROBOT_HEAD_SIZE * 5.3);

	MeshCube* body = new MeshCube();
	body->setColor(COLOR_RED);
	body->setSize(ROBOT_BODY_SIZE);
	body->setTranslateY(ROBOT_BODY_SIZE * 1.3);
	body->setScaleZ(0.5);

	model->addMesh(head);
	model->addMesh(body);

	return model;
}