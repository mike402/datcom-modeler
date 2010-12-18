#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdio.h>

typedef struct Matrix4Struct {
	double element[4][4];
} Matrix4;

typedef struct Vector4Struct {
	double element[4];
} Vector4;

typedef struct Vector3Struct {
	double element[3];
} Vector3;


/* initialize a translation matrix */
void matrix_translate(Matrix4* matrix, double dx, double dy, double dz);

/* initialize a rotation matrix */
void matrix_rotateXYZ(Matrix4* matrix, double rx, double ry, double rz);

/* initialize an identity matrix */
void matrix_identity(Matrix4* matrix);

/* multiply matrix a by matrix b, result in matrix result */
void matrix_multiply(Matrix4 *a, Matrix4 *b, Matrix4 *result);

void vector_multiply(Matrix4 *a, Vector4 *b, Vector4 *result);

/* add matrix b to matrix a, result in matrix result */
void matrix_add(Matrix4 *a, Matrix4 *b, Matrix4 *result);

void vector3_subtract(Vector3 *A, Vector3 *B, Vector3 *result);
void vector4_subtract(Vector4 *A, Vector4 *B, Vector4 *result);

/* print */
void matrix_print(Matrix4 *matrix);
void matrix_fprint(FILE* fp, Matrix4 *matrix);

void vector3_print(Vector3 *vector);
void vector3_fprint(FILE *fp, Vector3 *vector);

void vector4_print(Vector4 *vector);
void vector4_fprint(FILE *fp, Vector4 *vector);



#endif /*defined MATRIX_H */
