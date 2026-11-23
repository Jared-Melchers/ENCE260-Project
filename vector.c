/**@file    vector.c
 * @author  Jayden Pope
 * @date    13/10/2022
 * @brief   Vector data type
 */
#include "system.h"
#include "vector.h"

Vector_t vector_init(int8_t x, int8_t y)
{
    Vector_t vec = {x, y};
    return vec;
}