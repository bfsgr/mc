#include <stdio.h>
#include <math.h>

float approxSqrt(float x)
{
    union
    {
        float f;
        u_int32_t k;
    } val = {.f = x};

    val.k -= 1 << 23;
    val.k >>= 1;
    val.k += 1 << 29;

    return val.f;
}

float newtonRaphson(float a)
{
    union
    {
        float f;
        u_int32_t k;
    } val = {.f = approxSqrt(a)};

    val.f = (val.f + a / val.f);

    val.f = val.f / 2.0f;

    return 1.0f / val.f;
}

float invNewtonRaphson(float a)
{
    float a2 = a / 2.0f;

    float x = approxSqrt(1 / a);

    x = x * (1.5f - (a2 * x * x));

    return x;
}

float garyTarolli(float a)
{
    float a2 = a / 2.0f;

    union
    {
        unsigned int k;
        float x;
    } u = {.x = a};

    u.k = 0x5f375a86 - (u.k >> 1);

    u.x = u.x * (1.5f - a2 * u.x * u.x);

    return u.x;
}

float libc_invsqrt(float a)
{
    return 1.0f / sqrt(a);
}
