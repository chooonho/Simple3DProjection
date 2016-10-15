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

Model* createWall(int, int, Transform, Rotate, Transform, ColorRGB3F, Orientation);
Model* createTable(int, int, int, Transform, Rotate, Transform);
void createRobot();

#endif