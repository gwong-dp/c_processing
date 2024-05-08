This section contains all functions relating to CP_Vector.

# Table Of Contents
* [CP_Vector_Set](#cp_vector_set)
* [CP_Vector_Zero](#cp_vector_zero)
* [CP_Vector_Negate](#cp_vector_negate)
* [CP_Vector_Add](#cp_vector_add)
* [CP_Vector_Subtract](#cp_vector_subtract)
* [CP_Vector_Scale](#cp_vector_scale)
* [CP_Vector_Normalize](#cp_vector_normalize)
* [CP_Vector_MatrixMultiply](#cp_vector_matrixmultiply)
* [CP_Vector_Length](#cp_vector_length)
* [CP_Vector_Distance](#cp_vector_distance)
* [CP_Vector_DotProduct](#cp_vector_dotproduct)
* [CP_Vector_CrossProduct](#cp_vector_crossproduct)
* [CP_Vector_Angle](#cp_vector_angle)
* [CP_Vector_AngleCW](#cp_vector_angle)
* [CP_Vector_AngleCCW](#cp_vector_angle)

# CP_Vector_Set
Manually create a [CP_Vector](Types.md#cp_vector) by inputting its two values.

## Function
```C
CP_Vector CP_Vector_Set(float x, float y);
```

### Parameters
* x (float) - The x value you want in the vector.
* y (float) - The y value you want in the vector.

### Return
* [CP_Vector](Types.md#cp_vector) - A vector with the given values.

## Example
```C
void update()
{
    CP_Vector random_v = CP_Vector_Set(CP_Random_RangeFloat(0, 50), CP_Random_RangeFloat(0, 50));
}
```

## Related
* [CP_Vector](Types.md#cp_vector)

# CP_Vector_Zero
Creates a [CP_Vector](Types.md#cp_vector) with both values being 0.

## Function
```C
CP_Vector CP_Vector_Zero();
```

### Parameters
This function has no parameters.

### Return
* [CP_Vector](Types.md#cp_vector) - A vector with the given values.

## Example
```C
void update()
{
  CP_Vector zero_v = CP_Vector_Zero();
}

```

## Related
* [CP_Vector](Types.md#cp_vector)

# CP_Vector_Negate
Returns a vector with the negated values of a given CP_Vector

## Function
```C
CP_Vector CP_Vector_Negate(CP_Vector v);
```

### Parameters
* v ([CP_Vector](Types.md#cp_vector)) - The vector to negate the value in.

### Return
* [CP_Vector](Types.md#cp_vector) - A vector with the negated values.

## Example
```C
void update()
{
    CP_Vector random_v = CP_Vector_Set(CP_Random_RangeFloat(0, 50), CP_Random_RangeFloat(0, 50));
    CP_Vector negated_v = CP_Vector_Negate(random_v);
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_Add
Adds together the values within two given [CP_Vectors](Types.md#cp_vector).

## Function
```C
CP_Vector CP_Vector_Add(CP_Vector a, CP_Vector b);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The first vector to add.
* b ([CP_Vector](Types.md#cp_vector)) - The second vector to add.

### Return
* [CP_Vector](Types.md#cp_vector) - The sum of the two vectors.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 1);
    CP_Vector vec_b = CP_Vector_Set(-1, 6);
    CP_Vector sum_v = CP_Vector_Add(vec_a, vec_b);  // Returns a vector with values (0, 7)
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_Subtract
Subtracts the values within two given [CP_Vectors](Types.md#cp_vector).

## Function
```C
CP_Vector CP_Vector_Subtract(CP_Vector a, CP_Vector b);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The vector that will subtract b.
* b ([CP_Vector](Types.md#cp_vector)) - The vector that will be subtracted from a.

### Return
* [CP_Vector](Types.md#cp_vector) - The difference of the two vectors.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 1);
    CP_Vector vec_b = CP_Vector_Set(-1, 6);
    CP_Vector sum_v = CP_Vector_Subtract(vec_a, vec_b);  // Returns a vector with values (2, -5)
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_Scale
Returns a new [CP_Vector](Types.md#cp_vector) that has the values of the given [CP_Vector](Types.md#cp_vector) scaled by the given scalar.

## Function
```C
CP_Vector CP_Vector_Scale(CP_Vector a, float scale);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The vector to scale.
* scale (float) - The value to scale the vector by.

### Return
* [CP_Vector](Types.md#cp_vector) - The scaled vector.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 1);
    CP_Vector sum_v = CP_Vector_Scale(vec_a, 4);  // Returns a vector with values (4, 4)
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_Normalize
Returns a new [CP_Vector](Types.md#cp_vector) that is the normalized version of the given [CP_Vector](Types.md#cp_vector).

## Function
```C
CP_Vector CP_Vector_Normalize(CP_Vector vec);
```

### Parameters
* vec ([CP_Vector](Types.md#cp_vector)) - The vector to normalize.

### Return
* [CP_Vector](Types.md#cp_vector) - The normalized vector.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(3, 4);
    CP_Vector norm_v = CP_Vector_Normalize(vec_a);  // Returns a vector with values (.6, .8)
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_MatrixMultiply
Creates a [CP_Vector](Types.md#cp_vector) by multiplying the given [CP_Vector](Types.md#cp_vector) by the given [CP_Matrix](Types.md#cp_matrix).

## Function
```C
CP_Vector CP_Vector_MatrixMultiply(CP_Matrix matrix, CP_Vector vec);
```

### Parameters
* matrix ([CP_Matrix](Types.md#cp_matrix)) - The matrix to use in the multiplication.
* vec ([CP_Vector](Types.md#cp_vector)) - The vector to use in the multiplication.

### Return
* [CP_Vector](Types.md#cp_vector) - The vector created by matrix * vec.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(3, 4);
    CP_Matrix matrix_a = CP_Matrix_Translate(CP_Vector_Set(10, 6));
    CP_Vector norm_v = CP_Vector_MatrixMultiply(matrix_a, vec_a);
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)
* [CP_Matrix_Translate](Matrix.md#cp_matrix_translate)

# CP_Vector_Length
Calculates the length of a given [CP_Vector](Types.md#cp_vector).

## Function
```C
float CP_Vector_Length(CP_Vector vec);
```

### Parameters
* vec ([CP_Vector](Types.md#cp_vector)) - The vector to find the length of.

### Return
* float - the length of the given vector.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(3, 4);
    float vec_length = CP_Vector_Length(vec_a); // returns 5
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_Distance
Calculates the distance between two given [CP_Vectors](Types.md#cp_vector).

## Function
```C
float CP_Vector_Distance(CP_Vector a, CP_Vector b);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The first point in the calculation.
* b ([CP_Vector](Types.md#cp_vector)) - The second point in the calculation.

### Return
* float - The distance between the two given points.

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(3, 4);
    CP_Vector vec_b = CP_Vector_Set(0, 0);
    float dist = CP_Vector_Distance(vec_a, vec_b); // returns 5
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_DotProduct
Calculates the dot product of two given [CP_Vectors](Types.md#cp_vector).

## Function
```C
float CP_Vector_DotProduct(CP_Vector a, CP_Vector b);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The first vector in the calculation.
* b ([CP_Vector](Types.md#cp_vector)) - The second vector in the calculation.

### Return
* float - The dot product of the two given [CP_Vectors](Types.md#cp_vector).

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 0);
    CP_Vector vec_b = CP_Vector_Set(0, 1);
    float dist = CP_Vector_DotProduct(vec_a, vec_b); // returns 0 since a and b are perpendicular
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_CrossProduct
Calculates the magnitude of the cross product of two given [CP_Vectors](Types.md#cp_vector).

## Function
```C
float CP_Vector_CrossProduct(CP_Vector a, CP_Vector b);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The first vector in the calculation.
* b ([CP_Vector](Types.md#cp_vector)) - The second vector in the calculation.

### Return
* float - The length of the cross product of the two given [CP_Vectors](Types.md#cp_vector).

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 0);
    CP_Vector vec_b = CP_Vector_Set(0, 1);
    float crossPLength = CP_Vector_CrossProduct(vec_a, vec_b); // returns 1 since a x b = (0, 0, 1)
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_Angle
Calculates the angle between two given [CP_Vectors](Types.md#cp_vector).

## Function
```C
float CP_Vector_Angle(CP_Vector a, CP_Vector b);
```

### Parameters
* a ([CP_Vector](Types.md#cp_vector)) - The first vector in the calculation.
* b ([CP_Vector](Types.md#cp_vector)) - The second vector in the calculation.

### Return
* float - The smaller angle between the given [CP_Vectors](Types.md#cp_vector).

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 0);
    CP_Vector vec_b = CP_Vector_Set(0, 1);
    float angleBetween = CP_Vector_Angle(vec_a, vec_b); // returns 90
    float biggerAngleBetween = 360.f - angleBeetwen ; // results in 270, which is the bigger angle between
}
```
## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_AngleCW
Calculates the clockwise angle between two given [CP_Vectors](Types.md#cp_vector).
Note that this takes into the account that in CProcessing, the x-axis points to the right and the y-axis points downwards.

## Function
```C
float CP_Vector_AngleCW(CP_Vector from, CP_Vector to);
```

### Parameters
* from ([CP_Vector](Types.md#cp_vector)) - The vector to calculate from.
* to ([CP_Vector](Types.md#cp_vector)) - The vector to calculate towards.

### Return
* float - The clockwise angle between the given [CP_Vectors](Types.md#cp_vector).

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 0);
    CP_Vector vec_b = CP_Vector_Set(0, 1);
    float angleBetweenAB = CP_Vector_AngleCW(vec_a, vec_b); // returns 90
    float angleBetweenBA = CP_Vector_AngleCW(vec_b, vec_a); // returns 270
}
```
## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)

# CP_Vector_AngleCCW
Calculates the counter-clockwise angle between two given [CP_Vectors](Types.md#cp_vector).
Note that this takes into the account that in CProcessing, the x-axis points to the right and the y-axis points downwards.

## Function
```C
float CP_Vector_AngleCCW(CP_Vector from, CP_Vector to);
```

### Parameters
* from ([CP_Vector](Types.md#cp_vector)) - The vector to calculate from.
* to ([CP_Vector](Types.md#cp_vector)) - The vector to calculate towards.

### Return
* float - The counter-clockwise angle between the given [CP_Vectors](Types.md#cp_vector).

## Example
```C
void update()
{
    CP_Vector vec_a = CP_Vector_Set(1, 0);
    CP_Vector vec_b = CP_Vector_Set(0, 1);
    float angleBetweenAB = CP_Vector_AngleCCW(vec_a, vec_b); // returns 270
    float angleBetweenBA = CP_Vector_AngleCCW(vec_b, vec_a); // returns 90
}
```

## Related
* [CP_Vector](Types.md#cp_vector)
* [CP_Vector_Set](#cp_vector_set)
