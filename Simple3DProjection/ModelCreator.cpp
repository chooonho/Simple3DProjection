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

void createRobot()
{

}