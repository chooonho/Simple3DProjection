#include "ModelCreator.h"
#include "Mesh.h"
#include "MeshCube.h"
#include "MeshSphere.h"

Model* createWall(double x, double y, int width, int height, Transform translate, Rotate rotate, Transform scale, ColorRGB3F color, Orientation orientation)
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

void createRobot()
{

}