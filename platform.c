/**@file    platform.c
 * @author  Jayden Pope
 * @date    13/10/2022
 * @brief   Platform to hit the ball
 */

#include "system.h"
#include "platform.h"
#include "vector.h"

/** Move the position of the platform up one, if out of bounds set to the edge
    @param platform reference to the platform moving up*/
void platformUp(Vector_t* platform)
{
    platform->x ++;
    if (platform->x > MAX_PLATFORM_POSITION) {
        platform->x = MAX_PLATFORM_POSITION;
    }
}

/** Move the position of the platform down one, if out of bounds set to the edge
    @param platform reference to the platform moving down*/
void platformDown(Vector_t* platform)
{
    platform->x--;
    if (platform->x < MIN_PLATFORM_POSITION || platform->x > MAX_PLATFORM_POSITION) {
        platform->x = MIN_PLATFORM_POSITION;
    }
}

/** Set x to the position of the platform, if out of bounds set to the edge
    @param platform reference to the platform of which the position will be set
    @param newXPos the new x position to set the platform to*/
void setXPlatformPosition(Vector_t* platform, int8_t newXPos)
{
    if (newXPos <= MAX_PLATFORM_POSITION && newXPos >= MIN_PLATFORM_POSITION) {
        platform->x = newXPos;
    } else if (newXPos > MAX_PLATFORM_POSITION) {
        platform->x = MAX_PLATFORM_POSITION;
    } else if (newXPos < MIN_PLATFORM_POSITION) {
        platform->x = MIN_PLATFORM_POSITION;
    }
}

/** Places the platforms positions onto the bitmap
    @param platform the players platform position
    @param opponentPlatform the opponents platform position
    @param bitmap pointer to the bitmap*/
void displayPlatforms(const Vector_t platform, const Vector_t opponentPlatform, uint8_t* bitmap)
{
    (bitmap)[platform.y] = (3 << platform.x);
    (bitmap)[opponentPlatform.y] = (3 << opponentPlatform.x);
}