/**@file    game.c
 * @author  Jayden Pope & Jared Melchers
 * @date    12/10/2022
 * @brief   The main game loop for the game Pong
 */
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "displayscreen.h"
#include "platform.h"
#include "communication.h"
#include "ir_uart.h"
#include "ball.h"
#include "collision.h"
#include "button.h"
#include "led.h"

#define GAME_PACE 500
#define BALL_PACE 2

int main (void)
{
    system_init ();
    pacer_init (GAME_PACE);
    ir_uart_init();
    button_init();
    displayscreen_init();
    navswitch_init();
    led_init ();

    while (1) {
        bool gameActive = true;

        // Initilise vectors for platforms
        Vector_t platform = {3, 4};
        Vector_t opponentPlatform = {3, 0};

        // Initilise vectors for the ball
        Vector_t ballPos = {3, 2};
        Vector_t ballSpeed = {0, 0};

        // Initial bitmap
        uint8_t bitmap[] =
        {
            0x00, 0x00, 0x00, 0x00, 0x00
        };
        displayscreen_tick(bitmap);

        // Matchmaking
        while (!gameStart(&ballPos, &ballSpeed))
        {
            pacer_wait();
            button_update();
        }

        // Reset led
        led_set(LED1, 0);

        uint16_t ballCount = 0;

        // Main game loop
        while (gameActive)
        {
            pacer_wait();
            displayscreen_tick(bitmap);
            displayPlatforms(platform, opponentPlatform, bitmap);
            navswitch_update();
            // Display ball position
            bitmap[ballPos.y] |= (1 << ballPos.x);

            // Receive communications
            communicationReceiveUpdate(&opponentPlatform);

            // Input from navswitch
            if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
                platformUp(&platform);
                communicationTransmitUpdate(platform);
            }
            if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
                platformDown(&platform);
                communicationTransmitUpdate(platform);
            }

            // Ball update
            ballCount++;
            if (ballCount >= GAME_PACE/BALL_PACE) {
                // Remove old ball position
                bitmap[ballPos.y] = !(1 << ballPos.x);
                ballMove(&ballPos, &ballSpeed);
                // Collision checks
                wallCollision(&ballPos, &ballSpeed);
                if (!platformCollision(&ballPos, &ballSpeed, platform, opponentPlatform)) {
                    // Game end
                    gameActive = false;
                    if (ballPos.y <= 0) {
                        led_set(LED1, 1);
                    }
                }
                ballCount = 0;
            }
        }
    }
}
