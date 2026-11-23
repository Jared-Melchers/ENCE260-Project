/**@file    ball.c
 * @author  Jared Melchers
 * @date    13/10/2022
 * @brief   ball entity
 */

#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include "vector.h"

#define POSITIVE_DIR 1
#define NEGATIVE_DIR -1
#define NO_DIR 0

#define INITIAL_BALL_X_POS 3
#define INITIAL_HOST_BALL_Y_POS 3
#define INITIAL_OPPONENT_BALL_Y_POS 1

/** Changes the balls location by its speed
    @param location the location of the ball
    @param speed the speed of the ball*/
void ballMove(Vector_t* location, Vector_t* speed);

#endif /* BALL_H*/