#pragma once

#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include "Transform.h"
#include "Rotate.h"
#include "Model.h"
#include "MeshRegular.h"

enum Orientation
{
	horizontal,
	vertical,
};

const ColorRGB3D COLOR_GRAY = { 0.5, 0.5, 0.5 };
const ColorRGB3D COLOR_SLATE_BLUE = { 0.416, 0.353, 0.804 };
const ColorRGB3D COLOR_WHITE = { 1.0, 1.0, 1.0 };
const ColorRGB3D COLOR_SADDLE_BROWN = { 0.545, 0.271, 0.075 };
const ColorRGB3D COLOR_DARK_BROWN = { 0.2, 0.09, 0.0 };
const ColorRGB3D COLOR_YELLOW = { 1.0,1.0,0.0 };
const ColorRGB3D COLOR_RED = { 1.0, 0.0, 0.0 };
const ColorRGB3D COLOR_GREEN = { 0.0, 1.0, 0.0 };
const ColorRGB3D COLOR_BLUE = { 0.0, 0.0, 1.0 };
const ColorRGB3D COLOR_SILVER = { 0.753, 0.753, 0.753 };
const ColorRGB3D COLOR_ORANGE = { 1.000, 0.549, 0.000 };
const ColorRGB3D COLOR_PURPLE = { 0.502, 0.000, 0.502 };
const ColorRGB3D COLOR_KHAKI = { 0.741, 0.718, 0.420 };

Model* createWall(int width, int height, Transform translate, Rotate rotate, Transform scale, ColorRGB3D color, Orientation orientation);
Model* createTable(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale);
Model* createChair(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale);
Model* createRobot(Transform translate, Rotate rotate, Transform scale);
Model* createTree(Transform translate, Rotate rotate, Transform scale);
Model* createCone(double base, double height, Transform translate, Rotate rotate, Transform scale, ColorRGB3D color);
Model* createTeapot(double size, Transform translate, Rotate rotate, Transform scale, ColorRGB3D color);
Model* createTorus(double innerRadius, double outerRadius, Transform translate, Rotate rotate, Transform scale, ColorRGB3D color);
Model* createRegular(RegularType regularType, Transform translate, Rotate rotate, Transform scale, ColorRGB3D color);

#endif