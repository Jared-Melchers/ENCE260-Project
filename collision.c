/**@file    collision.c
 * @author  Jared Melchers
 * @date    13/10/2022
 * @brief   collision detection
 */

#include "collision.h"
#include "ball.h"

/** Handles wall collisions
    @param location the location of the ball
    @param speed the speed of the ball*/
void wallCollision(Vector_t* location, Vector_t* speed)
{
    // Checks if the ball is colliding with the wall and if it is, reverse the direction
    if (location->x == BALL_MAX_X) {
        speed->x = NEGATIVE_DIR;
    } else if (location->x == BALL_MIN_X) {
        speed->x = POSITIVE_DIR;
    }
}

/** Returns the location of the left side of the platform
    @param platform the location of the platform
    @return the location of the right side of the platform*/
Vector_t leftPlatform(const Vector_t platform)
{
    Vector_t leftPlatformLocation;
    leftPlatformLocation.x = platform.x + PLATFORM_LEFT_SHIFT;
    return leftPlatformLocation;
}

/** Handles a collision with the left side of the platform
    @param speed the speed of the ball*/
void leftCollision(Vector_t* speed)
{
    // If the ball is coming from the left, bounce straight, otherwise bounce left
    if (speed->x == NEGATIVE_DIR) {
        speed->x = NO_DIR;
    } else {
        speed->x = POSITIVE_DIR;
    }
}

/** Handles a collision with the right side of the platform
    @param speed the speed of the ball*/
void rightCollision(Vector_t* speed)
{
    // If the ball is coming from the right, bounce straight, otherwis bounce right
    if (speed->x == POSITIVE_DIR) {
        speed->x = NO_DIR;
    } else {
        speed->x = NEGATIVE_DIR;
    }
}

/** Determines if the ball has hit a platform. If so it canges the direction of
   the ball depending on which side of theplatform the ball hit and if not
   teturns false
    @param location the location of the ball
    @param speed the speed of the ball
    @param platform the location of the platform
    @param oponentPlatform the location of the oponents platform
    @return Returns false when the ball is out of bounds and true otherwise*/
bool platformCollision(Vector_t* location, Vector_t* speed, const Vector_t platform, const Vector_t opponentPlatform)
{
    // If the ball hits the oponents platform bounce it back
    if (location->y == BALL_MIN_Y) {
        // change the direction depending on which sid eof the platform it hits and which direction it is going
        if (location->x == leftPlatform(opponentPlatform).x) {
            leftCollision(speed);
            speed->y = POSITIVE_DIR;
        } else if (location->x == opponentPlatform.x) {
            rightCollision(speed);
            speed->y = POSITIVE_DIR;
        }
    // If the ball hits the players platform bounce it back
    } else if (location->y == BALL_MAX_Y) {
        // change the direction depending on which sid eof the platform it hits and which direction it is going
        if (location->x == leftPlatform(platform).x) {
            leftCollision(speed);
            speed->y = NEGATIVE_DIR;
        } else if (location->x == platform.x) {
            rightCollision(speed);
            speed->y = NEGATIVE_DIR;
        }
    } else if (location->y > BALL_MAX_Y || location->y < BALL_MIN_Y) {
        // return false if ball is outside the bounds
        return false;
    }
    // if the ball is not at either end
    return true;
}