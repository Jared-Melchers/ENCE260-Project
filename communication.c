/**@file    communication.c
 * @author  Jayden Pope
 * @date    13/10/2022
 * @brief   Communication between the boards
 */
#include "system.h"
#include "ir_uart.h"
#include "platform.h"
#include "communication.h"
#include <stdbool.h>
#include "button.h"
#include "ball.h"

/** Checks for message from the opponent, updates their platform position vector
    @param opponentPlatform reference to the opponent's platform position vector*/
void communicationReceiveUpdate(Vector_t* opponentPlatform)
{
    // Receive other platform position
    if (ir_uart_read_ready_p ()) {
        char opponentPlatformPosition;
        opponentPlatformPosition = ir_uart_getc();
        if (opponentPlatformPosition >= 'A' && opponentPlatformPosition <= 'F') {
            // Set opponent platform position
            setXPlatformPosition(opponentPlatform, (uint8_t)(opponentPlatformPosition - 'A'));
        }
    }
}

/** Transmits the player's platform position vector to the opponent
    @param platform the player's platform position*/
void communicationTransmitUpdate(const Vector_t platform)
{
    // Transmit the platform position over IR event
    if (ir_uart_write_ready_p()) {
        char platformPos = (char)platform.x + 'A';
        ir_uart_putc(platformPos);
    }
}

/** Ask for or reply to a game with another device.
    @param location ball location vector
    @param speed ball speed vector
    @return true if the game started false if still looking*/
bool gameStart(Vector_t* location, Vector_t* speed){
    if (ir_uart_read_ready_p ()) {
        char markoPolo;
        // check if oponent is calling for a game
        markoPolo = ir_uart_getc(); 
        if (markoPolo == 'M'){
            // send a reply
            if (ir_uart_write_ready_p()) {
                ir_uart_putc('P');
                location->x = INITIAL_BALL_X_POS;
                location->y = INITIAL_OPPONENT_BALL_Y_POS;
                speed->x = NO_DIR;
                speed->y = POSITIVE_DIR;
                return true;
            }
        // if a reply is recieved return true
        } else if (markoPolo == 'P'){
            location->x = INITIAL_BALL_X_POS;
            location->y = INITIAL_HOST_BALL_Y_POS;
            speed->x = NO_DIR;
            speed->y = NEGATIVE_DIR;
            return true;
        }
    // if button is pushed call for a game
    } else if(button_push_event_p(0)) { 
        ir_uart_putc('M');
    }
    // if no gme is called return false
    return false;
}