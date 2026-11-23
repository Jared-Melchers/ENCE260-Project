/**@file    vector.h
 * @author  Jayden Pope
 * @date    13/10/2022
 * @brief   Vector data type
 */
#ifndef VECTOR_H
#define VECTOR_H
#include "system.h"

typedef struct {
    int8_t x;
    int8_t y;
} Vector_t;

Vector_t vector_init(int8_t x, int8_t y);

#endif /* VECTOR_H */