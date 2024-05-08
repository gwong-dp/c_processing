This section contains all Random functions.

# Table Of Contents
* [CP_Random_GetBool](#cp_random_getbool)
* [CP_Random_GetInt](#cp_random_getint)
* [CP_Random_RangeInt](#cp_random_rangeint)
* [CP_Random_GetFloat](#cp_random_getfloat)
* [CP_Random_RangeFloat](#cp_random_rangefloat)
* [CP_Random_Seed](#cp_random_seed)
* [CP_Random_Gaussian](#cp_random_gaussian)
* [CP_Random_Noise](#cp_random_noise)
* [CP_Random_NoiseSeed](#cp_random_noiseseed)

# CP_Random_GetBool
Returns a random TRUE or FALSE [CP_Bool](Types.md#cp_bool).

## Function
```C
CP_Bool CP_Random_GetBool();
```

### Parameters
This function has no parameters

### Return
* [CP_Bool](Types.md#cp_bool) - Will be randomly TRUE or FALSE.

## Example
```C
void update()
{
    CP_Bool bool = CP_Random_GetBool();
}
```

## Related
* [CP_Bool](Types.md#cp_bool)

# CP_Random_GetInt
Returns a random unsigned integer. The returned value will be between 0 and the maximum unsigned int value.

## Function
```C
unsigned int CP_Random_GetInt();
```

### Parameters
This function has no parameters

### Return
* unsigned int - The random value.

## Example
```C
void update()
{
    unsigned int random_int = CP_Random_GetInt();
}
```

## Related
* [CP_Random_RangeInt](#cp_random_rangeint)

# CP_Random_RangeInt
Returns a random integer equal to or between the two given values.

## Function
```C
int CP_Random_RangeInt(int lowerbound, int higherbound);
```

### Parameters
* lowerbound (unsigned int) - The minimum value of the random number.
* higherbound (unsigned int) - The maximum value of the random number.

### Return
* unsigned int - A randomly valued unsigned int equal to or between the given bounds.

## Example
```C
void update()
{
    unsigned int random_int = CP_Random_RangeInt(100, 200);
}
```

## Related
* [CP_Random_GetInt](#cp_random_getint)

# CP_Random_GetFloat
Returns a random float value from 0.0 to 1.0.

## Function
```C
float CP_Random_GetFloat();
```

### Parameters
This function has no parameters

### Return
* float - A randomly valued float between 0.0 and 1.0.

## Example
```C
void update()
{
    float random_float = CP_Random_GetFloat();
}
```

## Related
* [CP_Random_RangeFloat](#cp_random_rangefloat)


# CP_Random_RangeFloat
Returns a random float equal to or between the two given values.

## Function
```C
float CP_Random_RangeFloat(float lowerbound, float higherbound);
```

### Parameters
* lowerbound (float) - The minimum value of the random number.
* higherbound (float) - The maximum value of the random number

### Return
* float - A randomly valued float equal to or between the given bounds.

## Example
```C
void update()
{
    float random_float = CP_Random_RangeFloat(50.6f, 60);
}
```

## Related
* [CP_Random_GetFloat](#cp_random_getfloat)

# CP_Random_Seed
Set the seed used for generating random numbers.

## Function
```C
void CP_Random_Seed(int seed);
```

### Parameters
* seed (int) - The seed that you want to give to the random number generator.

### Return
This function does not return anything

## Example
```C
void update()
{
     CP_Random_Seed(5);
}
```

## Related


# CP_Random_Gaussian
Returns a normally distributed random value where the median is 0 and the standard deviation is 1.

## Function
```C
float CP_Random_Gaussian(void);
```

### Parameters
This function does not have any parameters

### Return
* float - The randomly distributed value.

## Example
```C
void update()
{
    float random_v = CP_Random_Gaussian();
}
```

## Related


# CP_Random_Noise
Returns a smooth random value from 0.0 to 1.0 based on a three dimensional coordinate.

## Function
```C
float CP_Random_Noise(float x, float y, float z);
```

### Parameters
* x (float) - The x coordinate of the value.
* y (float) - The y coordinate of the value.
* z (float) - The z coordinate of the value.

### Return
* float - The smoothly distributed value.

## Example
```C
void update()
{
    float random_noise = CP_Random_Noise(.3f, .4f, .5f);
}
```

## Related
* [CP_Random_NoiseSeed](#cp_random_noiseseed)


# CP_Random_NoiseSeed
Sets a seed value for the values returned by [CP_Random_Noise](#cp_random_noise).

## Function
```C
void CP_Random_NoiseSeed(int seed);
```

### Parameters
* seed (int) - The seed to use when distributing noise values.

### Return
This function does not return anything.

## Example
```C
void update()
{
    CP_Random_NoiseSeed(129);
}
```

## Related
* [CP_Random_Noise](#cp_random_noise)
