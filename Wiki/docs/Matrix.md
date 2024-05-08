This section contains all functions relating to CP_Matrix.

# Table Of Contents
* [CP_Matrix_Set](#cp_matrix_set)
* [CP_Matrix_Identity](#cp_matrix_identity)
* [CP_Matrix_FromVector](#cp_matrix_fromvector)
* [CP_Matrix_Scale](#cp_matrix_scale)
* [CP_Matrix_Translate](#cp_matrix_translate)
* [CP_Matrix_Rotate](#cp_matrix_rotate)
* [CP_Matrix_RotateRadians](#cp_matrix_rotateradians)
* [CP_Matrix_Transpose](#cp_matrix_transpose)
* [CP_Matrix_Inverse](#cp_matrix_inverse)
* [CP_Matrix_Multiply](#cp_matrix_multiply)

# CP_Matrix_Set
Creates a [CP_Matrix](Types.md#cp_matrix) from the given values.

## Function
```C
CP_Matrix CP_Matrix_Set(float m00, float m01, float m02,
                        float m10, float m11, float m12,
                        float m20, float m21, float m22);
```

### Parameters
* mXY (float) - The 'X' corresponds to the row, the 'Y' corresponds to the column.

Diagram:
[m00][m01][m02]
[m10][m11][m12]
[m20][m21][m22]

### Return
* [CP_Matrix](Types.md#cp_matrix) - The matrix created from the given inputs.

## Example
```C
void update()
{
    // Create transformation matrices
    CP_Matrix trans = CP_Matrix_Set(1.0f, 0,    CP_System_GetWindowWidth() / 2.0f,
                                    0,    1.0f, CP_System_GetWindowHeight() / 2.0f,
                                    0,    0,    1.0f);
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Matrix_Identity
Creates a [CP_Matrix](Types.md#cp_matrix) which is a 3x3 identity matrix.

## Function
```C
CP_Matrix CP_Matrix_Identity();
```

### Parameters
This function does not have any parameters

### Return
* [CP_Matrix](Types.md#cp_matrix) - A 3x3 identity matrix.

## Example
```C
void update()
{
    // Create transformation matrices
    CP_Matrix mat = CP_Matrix_Identity();
    mat = CP_Matrix_Multiply(mat, CP_Matrix_Rotate(25));
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Matrix_Multiply](#cp_matrix_multiply)
* [CP_Matrix_Rotate](#cp_matrix_rotate)

# CP_Matrix_FromVector
Creates a [CP_Matrix](Types.md#cp_matrix) by inputting each column of the matrix from the given [CP_Vector](Types.md#cp_vector) variables. The bottom row of the matrix will be set to (0, 0, 1).

## Function
```C
CP_Matrix CP_Matrix_FromVector(CP_Vector col0, CP_Vector col1, CP_Vector col2);
```

### Parameters
* col0 ([CP_Vector](Types.md#cp_vector)) - The first column in the matrix.
* col1 ([CP_Vector](Types.md#cp_vector)) - The second column in the matrix.
* col2 ([CP_Vector](Types.md#cp_vector)) - The third column in the matrix.

### Return
* [CP_Matrix](Types.md#cp_matrix) - A 3x3 [CP_Matrix](Types.md#cp_matrix) with the given columns.

## Example
```C
void update()
{
    CP_Vector col1 = CP_Vector_Set(0, 1);
    CP_Vector col2 = CP_Vector_Set(-1, 0);
    CP_Vector col3 = CP_Vector_Set(45, 20);

    // Create transformation matrices
    CP_Matrix mat = CP_Matrix_FromVector(col1, col2, col3);
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](Vector.md#cp_vector_set)

# CP_Matrix_Scale
Creates a [CP_Matrix](Types.md#cp_matrix) used for scaling from the given [CP_Vector](Types.md#cp_vector).

## Function
```C
CP_Matrix CP_Matrix_Scale(CP_Vector scale);
```

### Parameters
* scale ([CP_Vector](Types.md#cp_vector)) - The x and y scale that you want the matrix to hold.

### Return
* [CP_Matrix](Types.md#cp_matrix) - A matrix that can be used to scale other matrices/vectors by the given amounts.

## Example
```C
void update()
{
    CP_Matrix mat = CP_Matrix_Scale(CP_Vector_Set(5, 2));
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Vector_Set](Vector.md#cp_vector_set)

# CP_Matrix_Translate
Creates a translation [CP_Matrix](Types.md#cp_matrix) using the given [CP_Vector](Types.md#cp_vector).

## Function
```C
CP_Matrix CP_Matrix_Translate(CP_Vector translation);
```

### Parameters
* translation ([CP_Vector](Types.md#cp_vector)) - The x and y translation that you want the matrix to hold.

### Return
* [CP_Matrix](Types.md#cp_matrix) - A translation matrix using the given values.

## Example
```C
void update()
{
    CP_Matrix mat = CP_Matrix_Translate(CP_Vector_Set(20, 45));
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Vector_Set](Vector.md#cp_vector_set)

# CP_Matrix_Rotate
Creates a rotation [CP_Matrix](Types.md#cp_matrix) using the given angle in degrees.

## Function
```C
CP_Matrix CP_Matrix_Rotate(float degrees);
```

### Parameters
* degrees (float) - The number of degrees of rotation you want to matrix to apply.

### Return
* [CP_Matrix](Types.md#cp_matrix) - A rotation matrix using the given angle.

## Example
```C
void update()
{
    CP_Matrix mat = CP_Matrix_Rotate(45);
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)

# CP_Matrix_RotateRadians
Creates a rotation [CP_Matrix](Types.md#cp_matrix) using the given angle in radians.

## Function
```C
CP_Matrix CP_Matrix_RotateRadians(float radians);
```

### Parameters
* radians (float) - The rotation angle in radians you want to matrix to apply.

### Return
* [CP_Matrix](Types.md#cp_matrix) - A rotation matrix using the given angle.

## Example
```C
void update()
{
    CP_Matrix mat = CP_Matrix_RotateRadians((float)M_PI / 2);
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)

# CP_Matrix_Transpose
Creates a [CP_Matrix](Types.md#cp_matrix) that is the transposition of the given [CP_Matrix](Types.md#cp_matrix).

## Function
```C
CP_Matrix CP_Matrix_Transpose(CP_Matrix matrix);
```

### Parameters
* matrix ([CP_Matrix](Types.md#cp_matrix)) - The matrix you want to transpose.

### Return
* [CP_Matrix](Types.md#cp_matrix) - The transposition of the given matrix.

## Example
```C
void update()
{
    CP_Matrix mat1 = CP_Matrix_Set(0, -1, 20, 1, 0, 10, 0, 0, 1);
    CP_Matrix transposed = CP_Matrix_Transpose(mat1);
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Matrix_Set](#cp_matrix_set)

# CP_Matrix_Inverse
Creates a [CP_Matrix](Types.md#cp_matrix) that is the inverse of the given [CP_Matrix](Types.md#cp_matrix).

## Function
```C
CP_Matrix CP_Matrix_Inverse(CP_Matrix matrix);
```

### Parameters
* matrix ([CP_Matrix](Types.md#cp_matrix)) - The matrix you want to inverse.

### Return
* [CP_Matrix](Types.md#cp_matrix) - The inverse of the given matrix.

## Example
```C
void update()
{
    CP_Matrix mat1 = CP_Matrix_Set(0, -1, 20, 1, 0, 10, 0, 0, 1);
    CP_Matrix inveresed = CP_Matrix_Inverse(mat1);
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Matrix_Set](#cp_matrix_set)

# CP_Matrix_Multiply
Creates a new [CP_Matrix](Types.md#cp_matrix) that is the result of multiplying the given matrices.

## Function
```C
CP_Matrix CP_Matrix_Multiply(CP_Matrix mat1, CP_Matrix mat2);
```

### Parameters
* mat1 ([CP_Matrix](Types.md#cp_matrix)) - The matrix on the left of the multiplication.
* mat2 ([CP_Matrix](Types.md#cp_matrix)) - The matrix on the right side of the multiplication.

### Return
* [CP_Matrix](Types.md#cp_matrix) - The result of mat1 * mat2.

## Example
```C
void update()
{
    CP_Matrix mat1 = CP_Matrix_Set(0, -1, 20, 1, 0, 10, 0, 0, 1);
    CP_Matrix inversed = CP_Matrix_Inverse(mat1);
    CP_Matrix multiply = CP_Matrix_Multiply(mat1, inversed); // Gives identity matrix
}
```

## Related
* [CP_Matrix](Types.md#cp_matrix)
* [CP_Matrix_Set](#cp_matrix_set)
* [CP_Matrix_Inverse](#cp_matrix_inverse)
