#include "Movable.h"
#include <iostream>

Movable::Movable()
{
	T = Eigen::Transform<float, 3, Eigen::Affine>::Identity();
}

Eigen::Matrix4f Movable::MakeTrans()
{
	return T.matrix();
}

Eigen::Transform<float, 3, Eigen::Affine> Movable::getTrans()
{
	return T;
}

void Movable::MyTranslate(Eigen::Vector3f amt, int axis)
{
	switch (axis) {
		//T = Translation x Rotation x Scale
	case CAMERA_AXIS: 
	{
		Eigen::Matrix4f prev_transformation = T.matrix();
		float tmp[] = { 0, 0, 0, 0,
						0, 0, 0, 0,
						0, 0, 0, 0,
						amt.x(), amt.y(), amt.z(), 0 };
		Eigen::Matrix4f translation_matrix = Eigen::Map<Eigen::Matrix4f>(tmp);
		T = translation_matrix + prev_transformation;

		break;
	}
	case OBJECT_AXIS:
		T.translate(amt);

		break;
	}
}
//angle in radians
void Movable::MyRotate(Eigen::Vector3f rotAxis, float angle)
{
	T.rotate(Eigen::AngleAxisf(angle, rotAxis));
}

void Movable::MyScale(Eigen::Vector3f amt)
{
	T.scale(amt);
}
