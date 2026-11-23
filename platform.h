/**@file    platform.h
 * @author  Jayden Pope
 * @date    13/10/2022
 * @brief   Platform to hit the ball
 */
#ifndef PLATFORM_H
#define PLATFORM_H
#include "system.h"
#include "vector.h"

#define MIN_PLATFORM_POSITION 0
#define MAX_PLATFORM_POSITION 5

/** Move the position of the platform up one, if out of bounds set to the edge
    @param platform reference to the platform moving up*/
void platformUp(Vector_t* platform);

/** Move the position of the platform down one, if out of bounds set to the edge
    @param platform reference to the platform moving down*/
void platformDown(Vector_t* platform);

/** Set x to the position of the platform, if out of bounds set to the edge
    @param platform reference to the platform of which the position will be set
    @param newXPos the new x position to set the platform to*/
void setXPlatformPosition(Vector_t* platform, int8_t newXPos);

/** Places the platforms positions onto the bitmap
    @param platform the players platform position
    @param opponentPlatform the opponents platform position
    @param bitmap pointer to the bitmap*/
void displayPlatforms(const Vector_t platform, const Vector_t opponentPlatform, uint8_t* bitmap);

#endif /* PLATFORM_H */