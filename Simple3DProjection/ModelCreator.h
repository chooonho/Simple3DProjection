/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#define DEG_TO_RAD 0.0174533
#define MATH_PI 3.14159265359

#include "Transform.h"
#include "Rotate.h"
#include "Model.h"
#include "MeshRegular.h"
#include "Material.h"

// Enumeration that specifies the orientation
enum Orientation
{
	horizontal,
	vertical,
};

// Enumeration that specifies the material types available
enum MaterialType
{
	SILVER,
	RUBY,
	CYAN_PLASTIC,
	GOLD,
	YELLOW_RUBBER,
	EMERALD,
	GREEN_PLASTIC,
	BRASS,
	PERL,
	POLISHED_BRONZE,
	RED_PLASTIC,
	OBSIDIAN,
	POLISHED_SILVER
};

// Constant variable storing colors
const ColorRGBA4D COLOR_BLACK = { 0.0, 0.0, 0.0, 1.0 };
const ColorRGBA4D COLOR_GRAY = { 0.5, 0.5, 0.5, 1.0 };
const ColorRGBA4D COLOR_SLATE_BLUE = { 0.416, 0.353, 0.804, 1.0 };
const ColorRGBA4D COLOR_WHITE = { 1.0, 1.0, 1.0, 1.0 };
const ColorRGBA4D COLOR_SADDLE_BROWN = { 0.545, 0.271, 0.075, 1.0 };
const ColorRGBA4D COLOR_DARK_BROWN = { 0.2, 0.09, 0.0, 1.0 };
const ColorRGBA4D COLOR_YELLOW = { 1.0,1.0, 0.0, 1.0 };
const ColorRGBA4D COLOR_RED = { 1.0, 0.0, 0.0, 1.0 };
const ColorRGBA4D COLOR_GREEN = { 0.0, 1.0, 0.0, 1.0 };
const ColorRGBA4D COLOR_BLUE = { 0.0, 0.0, 1.0, 1.0 };
const ColorRGBA4D COLOR_SILVER = { 0.753, 0.753, 0.753, 1.0 };
const ColorRGBA4D COLOR_ORANGE = { 1.000, 0.549, 0.000, 1.0 };
const ColorRGBA4D COLOR_PURPLE = { 0.502, 0.000, 0.502, 1.0 };
const ColorRGBA4D COLOR_KHAKI = { 0.741, 0.718, 0.420, 1.0 };
const ColorRGBA4D COLOR_CYAN = { 0.000, 1.000, 1.000, 1.0 };

// Function that creates and return a model (name of model created are specified on the function name)
Model* createWall(int width, int height, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material, Orientation orientation);
Model* createTable(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale);
Model* createChair(int width, int depth, int height, Transform translate, Rotate rotate, Transform scale);
Model* createRobot(Transform translate, Rotate rotate, Transform scale);
Model* createTree(Transform translate, Rotate rotate, Transform scale);
Model* createCone(double base, double height, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material);
Model* createTeapot(double size, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material);
Model* createTorus(double innerRadius, double outerRadius, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material);
Model* createRegular(RegularType regularType, Transform translate, Rotate rotate, Transform scale, ColorRGBA4D color, Material material);
// Function that creates material based on the material types specified in parameter
Material createMaterial(MaterialType materialType);

#endif