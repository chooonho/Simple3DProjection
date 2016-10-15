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

			meshCube->setTranslateX(1.0 * w);
			if (orientation == horizontal)
			{
				meshCube->setTranslateZ(1.0 * h );
			}
			else if (orientation == vertical)
			{
				meshCube->setTranslateY(1.0 * h);
			}

			model->addMesh(meshCube);
		}
	}

	return model;
}

Model* createTable(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale)
{
	const ColorRGB3F colorSaddleBrown = { 0.545, 0.271, 0.075 };
	const ColorRGB3F colorDarkBrown = { 0.2, 0.09, 0.0 };
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
			meshCube->setColor(colorSaddleBrown);
			meshCube->setTranslateY(height);
			meshCube->setTranslateX(1.0 * w);
			meshCube->setTranslateZ(1.0 * d);

			model->addMesh(meshCube);
		}
	}

	for (int w = 2; w < ((width - 2) * 2); w++)
	{
		MeshCube* meshCube = new MeshCube;
		meshCube->setSize(0.5);
		meshCube->setColor(colorDarkBrown);
		meshCube->setTranslateY(height - 1);
		meshCube->setTranslateX(0.5 * w);
		meshCube->setTranslateZ(depth - 2);

		model->addMesh(meshCube);
	}

	for (int w = 2; w < ((width - 2) * 2); w++)
	{
		MeshCube* meshCube = new MeshCube;
		meshCube->setSize(0.5);
		meshCube->setColor(colorDarkBrown);
		meshCube->setTranslateY(height - 1);
		meshCube->setTranslateX(0.5 * w);
		meshCube->setTranslateZ(1);

		model->addMesh(meshCube);
	}

	for (int d = 2; d < ((depth - 2) * 2); d++)
	{
		MeshCube* meshCube = new MeshCube;
		meshCube->setSize(0.5);
		meshCube->setColor(colorDarkBrown);
		meshCube->setTranslateY(height - 1);
		meshCube->setTranslateX(1.0);
		meshCube->setTranslateZ(0.5 * d);

		model->addMesh(meshCube);
	}

	for (int d = 2; d < ((depth - 2) * 2); d++)
	{
		MeshCube* meshCube = new MeshCube;
		meshCube->setSize(0.5);
		meshCube->setColor(colorDarkBrown);
		meshCube->setTranslateY(height - 1);
		meshCube->setTranslateX(width - 2);
		meshCube->setTranslateZ(0.5 * d);

		model->addMesh(meshCube);
	}

	for (int i = 0; i < LEG_COUNT; i++)
	{
		for (int h = 0; h < height; h++)
		{
			MeshCube* meshCube = new MeshCube;
			meshCube->setSize(1.0);
			meshCube->setColor(colorSaddleBrown);
			
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

void createRobot()
{

}