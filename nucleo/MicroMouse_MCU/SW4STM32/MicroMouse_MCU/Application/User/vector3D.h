/*
 * vector3D.h
 *
 *  Created on: 6 wrz 2017
 *      Author: Chupacabra
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

typedef struct vector3D{
	float x, y, z;
}vector3D;

inline vector3D vec_add(vector3D * a, vector3D * b){
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (*a);
}

inline vector3D vec_mmulti(vector3D * a, float scalar){
	a->x *= scalar;
	a->y *= scalar;
	a->z *= scalar;
	return (*a);
}

inline float vec_dotProduct(vector3D * a, vector3D * b){
	float dot = 0;
	dot = (a->x)*(b->x);
	dot += (a->y)*(b->y);
	dot += (a->z)*(b->z);
	return dot;
}

inline vector3D vec_crossProduct(vector3D * a, vector3D * b){
	vector3D cross;
	cross.x = (a->y)*(b->z) - (a->z)*(b->y);
	cross.y = (a->z)*(b->x) - (a->x)*(b->z);
	cross.z = (a->x)*(b->y) - (a->y)*(b->x);
	return cross;
}

#endif /* VECTOR3D_H_ */
