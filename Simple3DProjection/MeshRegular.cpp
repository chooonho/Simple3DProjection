#include "MeshRegular.h"

MeshRegular::MeshRegular(RegularType regularType)
{
	mRegularType = regularType;
}

MeshRegular::MeshRegular(RegularType regularType, ColorRGBA4D color, bool isWireFrame)
{
	mRegularType = regularType;
	setColor(color);
	setIsWireFrame(isWireFrame);
}

RegularType MeshRegular::getRegularType()
{
	return mRegularType;
}

void MeshRegular::setRegularType(RegularType regularType)
{
	mRegularType = regularType;
}

void MeshRegular::draw()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, getMaterial().getAmbient());
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, getMaterial().getDiffuse());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, getMaterial().getSpecular());
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, getMaterial().getShine());
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, getMaterial().getEmission());

	glPushMatrix();
		glColor4d(getColor().red, getColor().green, getColor().blue, getColor().alpha);
		glTranslated(getTranslateX(), getTranslateY(), getTranslateZ());
		glRotated(getRotateAngle(), getRotateX(), getRotateY(), getRotateZ());
		glScaled(getScaleX(), getScaleY(), getScaleZ());

		if (getIsWireFrame())
		{
			switch (mRegularType)
			{
				case DODECAHEDRON:
					glutWireDodecahedron();
					break;
				case OCTAHEDRON:
					glutWireOctahedron();
					break;
				case TETRAHEDRON:
					glutWireTetrahedron();
					break;
				case ICOSAHEDRON:
					glutWireIcosahedron();
					break;
			}
		}
		else
		{
			switch (mRegularType)
			{
				case DODECAHEDRON:
					glutSolidDodecahedron();
					break;
				case OCTAHEDRON:
					glutSolidOctahedron();
					break;
				case TETRAHEDRON:
					glutSolidTetrahedron();
					break;
				case ICOSAHEDRON:
					glutSolidIcosahedron();
					break;
			}
		}
	glPopMatrix();
}

