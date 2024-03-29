// Bruno Fusieger Santana RA 112646

#include <math.h>
#include <stdio.h>

typedef struct
{
    int exp;
    float n;
    float ln;
} NiceNumber;

NiceNumber NICE[] = {{.exp = 8, .n = 257.0f, .ln = 5.549076080322265625},
                     {.exp = 7, .n = 129.0f, .ln = 4.859812259674072265625},
                     {.exp = 6, .n = 65.0f, .ln = 4.174387454986572265625},
                     {.exp = 5, .n = 33.0f, .ln = 3.4965076446533203125},
                     {.exp = 4, .n = 17.0f, .ln = 2.833213329315185546875},
                     {.exp = 3, .n = 9.0f, .ln = 2.19722461700439453125},
                     {.exp = 2, .n = 5.0f, .ln = 1.6094379425048828125},
                     {.exp = 1, .n = 3.0f, .ln = 1.098612308502197265625},
                     {.exp = 0, .n = 2.0f, .ln = 0.693147182464599609375},
                     {.exp = -1, .n = 1.5, .ln = 0.4054650962352752685546875},
                     {.exp = -2, .n = 1.25, .ln = 0.2231435477733612060546875},
                     {.exp = -3, .n = 1.125, .ln = 0.117783032357692718505859375},
                     {.exp = -4, .n = 1.0625, .ln = 0.060624621808528900146484375},
                     {.exp = -5, .n = 1.03125, .ln = 0.03077165782451629638671875},
                     {.exp = -6, .n = 1.015625, .ln = 0.01550418697297573089599609375},
                     {.exp = -7, .n = 1.0078125, .ln = 0.0077821402810513973236083984375},
                     {.exp = -8, .n = 1.00390625, .ln = 0.00389864039607346057891845703125},
                     {.exp = -9, .n = 1.001953125, .ln = 0.001951220096088945865631103515625},
                     {.exp = -10, .n = 1.0009765625, .ln = 0.0009760859538801014423370361328125},
                     {.exp = -11, .n = 1.00048828125, .ln = 0.00048816206981427967548370361328125},
                     {.exp = -12, .n = 1.000244140625, .ln = 0.0002441108226776123046875},
                     {.exp = -13, .n = 1.0001220703125, .ln = 0.000122062861919403076171875},
                     {.exp = -14, .n = 1.00006103515625, .ln = 0.00006103329360485076904296875},
                     {.exp = -15, .n = 1.000030517578125, .ln = 0.0000305171124637126922607421875},
                     {.exp = -16, .n = 1.0000152587890625, .ln = 0.000015258672647178173065185546},
                     {.exp = -17, .n = 1.00000762939453125, .ln = 0.00000762936542741954326629638},
                     {.exp = -18, .n = 1.000003814697265625, .ln = 0.0000038146899896673858165740},
                     {.exp = -19, .n = 1.0000019073486328125, .ln = 0.000001907346813823096454143},
                     {.exp = -20, .n = 1.00000095367431640625, .ln = 0.00000095367386165889911353},
                     {.exp = -21, .n = 1.000000476837158203125, .ln = 0.0000004768370445162872783},
                     {.exp = -22, .n = 1.0000002384185791015625, .ln = 0.000000238418550679853069},
                     {.exp = -23, .n = 1.00000011920928955078125, .ln = 0.00000011920928244535389}};

#define LINHAS 32

float multiplica(float a, int e)
{
    union {
        float f;
        unsigned int k;
    } val = {.f = a};

    unsigned char expoente = val.k >> 23;

    float aux = a;

    expoente += e;

    val.k = (val.k & ~(0xFF << 23)) | expoente << 23;

    val.f += aux;

    return val.f;
}

float ln_x(float a)
{
    unsigned int cursor = 0;
    NiceNumber atual = NICE[cursor];

    while (cursor < LINHAS - 1 && NICE[cursor + 1].n > a)
    {
        cursor += 1;
        atual = NICE[cursor];
    }

    float x = a / atual.n;
    float y = atual.ln;

    while (cursor < LINHAS - 1)
    {
        float mult = multiplica(x, atual.exp);

        while (cursor < LINHAS - 1 && mult >= 1)
        {
            cursor += 1;
            atual = NICE[cursor];
            mult = multiplica(x, atual.exp);
        }

        if (cursor < LINHAS - 1)
        {
            x = mult;
            y = y - atual.ln;
        }
    }

    return y - fabs(1 - x);
}

float libc_ln(float x)
{
    return logf(x);
}
