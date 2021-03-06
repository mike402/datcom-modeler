#include "matrix.h"


void matrix4_translate(Matrix4* matrix, double dx, double dy, double dz)
{
	matrix4_identity(matrix);
	matrix->element[0][3] = dx;
	matrix->element[1][3] = dy;
	matrix->element[2][3] = dz;
}

void matrix4_rotateXYZ(Matrix4* matrix, double rx, double ry, double rz)
{
	Matrix4 mx, my, mz, ma;

	matrix4_identity(&ma);
	matrix4_identity(&mx);
	matrix4_identity(&my);
	matrix4_identity(&mz);

	mz.element[0][0] =  cos(rz);
	mz.element[0][1] = -sin(rz);
	mz.element[1][0] =  sin(rz);
	mz.element[1][1] =  cos(rz);

	mx.element[1][1] =  cos(rx);
	mx.element[1][2] = -sin(rx);
	mx.element[2][1] =  sin(rx);
	mx.element[2][2] =  cos(rx);

	my.element[0][0] =  cos(ry);
	my.element[0][2] = -sin(ry);
	my.element[2][0] =  sin(ry);
	my.element[2][2] =  cos(ry);

	matrix4_multiply(&mx, &my, &ma);
	matrix4_multiply(&ma, &mz, matrix);

}

void matrix4_rotateZ(Matrix4* matrix, double rz)
{
	matrix4_identity(matrix);

	matrix->element[0][0] =  cos(rz);
	matrix->element[0][1] = -sin(rz);
	matrix->element[1][0] =  sin(rz);
	matrix->element[1][1] =  cos(rz);

}

void matrix4_rotateX(Matrix4* matrix, double rx)
{
	matrix4_identity(matrix);

	matrix->element[1][1] =  cos(rx);
	matrix->element[1][2] = -sin(rx);
	matrix->element[2][1] =  sin(rx);
	matrix->element[2][2] =  cos(rx);

}

void matrix4_rotateY(Matrix4* matrix, double ry)
{
	matrix4_identity(matrix);

	matrix->element[0][0] =  cos(ry);
	matrix->element[0][2] = -sin(ry);
	matrix->element[2][0] =  sin(ry);
	matrix->element[2][2] =  cos(ry);

}

void matrix4_identity(Matrix4* matrix)
{
	matrix->element[0][0] = 1;
	matrix->element[0][1] = 0;
	matrix->element[0][2] = 0;
	matrix->element[0][3] = 0;
	matrix->element[1][0] = 0;
	matrix->element[1][1] = 1;
	matrix->element[1][2] = 0;
	matrix->element[1][3] = 0;
	matrix->element[2][0] = 0;
	matrix->element[2][1] = 0;
	matrix->element[2][2] = 1;
	matrix->element[2][3] = 0;
	matrix->element[3][0] = 0;
	matrix->element[3][1] = 0;
	matrix->element[3][2] = 0;
	matrix->element[3][3] = 1;
}

void matrix4_multiply(Matrix4 *a, Matrix4 *b, Matrix4 *result)
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			result->element[i][j] = 0.0;
			for(k=0;k<4;k++)
			{
				result->element[i][j] += b->element[i][k] * a->element[k][j];
			}
		}
	}
}

void vector_multiply(Matrix4 *a, Vector4 *b, Vector4 *result)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		result->element[i] = 0.0;
		for(j=0;j<4;j++)
		{
			result->element[i] += a->element[i][j] * b->element[j];
		}
	}
}


void matrix4_add(Matrix4 *a, Matrix4 *b, Matrix4 *result)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			result->element[i][j] += a->element[i][j] + b->element[i][j];
		}
	}
}

void matrix3_print(Matrix3 *matrix)
{
	int i;
	for(i=0;i<3;i++)
	{
		printf("% 0.4f, % 0.4f, % 0.4f\n", matrix->element[i][0], matrix->element[i][1], matrix->element[i][2]);
	}

}

void matrix3_fprint(FILE *fp, Matrix3 *matrix)
{
        int i;
        for(i=0;i<3;i++)
        {
                fprintf(fp, "% 0.4f, % 0.4f, % 0.4f\n", matrix->element[i][0], matrix->element[i][1], matrix->element[i][2]);
        }

}

void matrix4_print(Matrix4 *matrix)
{
	int i;
	for(i=0;i<4;i++)
	{
		printf("% 0.4f, % 0.4f, % 0.4f, % 0.4f\n", matrix->element[i][0], matrix->element[i][1], matrix->element[i][2], matrix->element[i][3]);
	}

}

void matrix4_fprint(FILE *fp, Matrix4 *matrix)
{
        int i;
        for(i=0;i<4;i++)
        {
                fprintf(fp, "% 0.4f, % 0.4f, % 0.4f, % 0.4f\n", matrix->element[i][0], matrix->element[i][1], matrix->element[i][2], matrix->element[i][3]);
        }

}

void vector3_print(Vector3 *vector)
{
	printf("(% 0.4f, % 0.4f, % 0.4f)\n", vector->element[0], vector->element[1], vector->element[2]);
}

void vector3_fprint(FILE *fp, Vector3 *vector)
{
	fprintf(fp, "(% 0.4f, % 0.4f, % 0.4f)\n", vector->element[0], vector->element[1], vector->element[2]);
}


void vector4_print(Vector4 *vector)
{
	printf("(% 0.4f, % 0.4f, % 0.4f, % 0.4f)\n", vector->element[0], vector->element[1], vector->element[2], vector->element[3]);
}

void vector4_fprint(FILE *fp, Vector4 *vector)
{
	fprintf(fp, "(% 0.4f, % 0.4f, % 0.4f, % 0.4f)\n", vector->element[0], vector->element[1], vector->element[2], vector->element[3]);
}

void vector3_subtract(Vector3 *A, Vector3 *B, Vector3 *result)
{
	int i;
	for(i=0;i<3;i++)
	{
		result->element[i] = A->element[i]-B->element[i];
	}
}

void vector4_subtract(Vector4 *A, Vector4 *B, Vector4 *result)
{
	int i;
	for(i=0;i<4;i++)
	{
		result->element[i] = A->element[i]-B->element[i];
	}
}

void vector3_cross(Vector3 *B, Vector3 *C, Vector3 *result)
{
/*  a_x = b_y c_z - b_z c_y  
    a_y = b_z c_x - b_x c_z  
    a_z = b_x c_y - b_y c_x */ 

	result->element[0]=B->element[1]*C->element[2] - B->element[2]*C->element[1];
	result->element[1]=B->element[2]*C->element[0] - B->element[0]*C->element[2];
	result->element[2]=B->element[0]*C->element[1] - B->element[1]*C->element[0];

}

double vector3_magnitude(Vector3 *A)
{
	double result;
	result  = A->element[0]*A->element[0];
	result += A->element[1]*A->element[1];
	result += A->element[2]*A->element[2];
	result = sqrt(result);

	return (result);
}

double vector4_magnitude(Vector4 *A)
{
	double result;
	result  = A->element[0]*A->element[0];
	result += A->element[1]*A->element[1];
	result += A->element[2]*A->element[2];
	result += A->element[3]*A->element[3];

	result = sqrt(result);

	return result;
}

