#pragma once

#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include "Transform.h"
#include "Rotate.h"
#include "Model.h"

enum Orientation
{
	horizontal,
	vertical,
}; 

const ColorRGB3D COLOR_SADDLE_BROWN = { 0.545, 0.271, 0.075 };
const ColorRGB3D COLOR_DARK_BROWN = { 0.2, 0.09, 0.0 };
const ColorRGB3D COLOR_YELLOW = { 1.0,1.0,0.0 };
const ColorRGB3D COLOR_RED = { 1.0, 0.0, 0.0 };
const ColorRGB3D COLOR_GREEN = { 0.0, 1.0, 0.0 };

Model* createWall(int width, int height, Transform translate, Rotate rotate, Transform scale, ColorRGB3D color, Orientation orientation);
Model* createTable(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale);
Model* createChair(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale);
Model* createRobot(Transform translate, Rotate rotate, Transform scale);
Model* createTree(Transform translate, Rotate rotate, Transform scale);

#endif