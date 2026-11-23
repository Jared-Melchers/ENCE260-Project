/**@file    ball.c
 * @author  Jared Melchers
 * @date    13/10/2022
 * @brief   ball entity
 */

#include "ball.h"

/** Changes the balls location by its speed
    @param location the location of the ball
    @param speed the speed of the ball*/
void ballMove(Vector_t* location, Vector_t* speed)
{
    location->x += speed->x;
    location->y += speed->y;
}
