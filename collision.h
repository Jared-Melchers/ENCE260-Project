/**@file    collision.h
 * @author  Jared Melchers
 * @date    13/10/2022
 * @brief   collision detection
 */

#ifndef COLLISION_H
#define COLLISION_H

#include "platform.h"
#include "vector.h"
#include <stdbool.h>
#include <stdint.h>

#define BALL_MAX_X          6
#define BALL_MIN_X          0
#define BALL_MAX_Y          4
#define BALL_MIN_Y          0
#define PLATFORM_LEFT_SHIFT 1

/** Handles wall collisions
    @param location the location of the ball
    @param speed the speed of the ball*/
void wallCollision(Vector_t* location, Vector_t* speed);

/** Returns the location of the left side of the platform
    @param platform the location of the platform
    @return the location of the right side of the platform*/
Vector_t leftPlatform(Vector_t platform);

/** Handles a collision with the left side of the platform
    @param speed the speed of the ball*/
void leftCollision(Vector_t* speed);

/** Handles a collision with the right side of the platform
    @param speed the speed of the ball*/
void rightCollision(Vector_t* speed);

/** Determines if the ball has hit a platform. If so it canges the direction of
   the ball depending on which side of theplatform the ball hit and if not
   teturns false
    @param location the location of the ball
    @param speed the speed of the ball
    @param platform the location of the platform
    @param oponentPlatform the location of the oponents platform
    @return Returns false when the ball is out of bounds and true otherwise*/
bool platformCollision(Vector_t*      location,
                       Vector_t*      speed,
                       const Vector_t platform,
                       const Vector_t opponentPlatform);

#endif /*COLLISION_H*/