/**@file    communication.h
 * @author  Jayden Pope
 * @date    13/10/2022
 * @brief   Communication between the boards
 */
#ifndef COMMUNICATION_H
#define COMMUNICATION_H

/** Checks for message from the opponent, updates their platform position vector
    @param opponentPlatform reference to the opponent's platform position vector*/
void communicationReceiveUpdate(Vector_t* opponentPlatform);

/** Transmits the player's platform position vector to the opponent
    @param platform the player's platform position*/
void communicationTransmitUpdate(const Vector_t platform);

/** ask for or reply to a game with another device.
    @param location ball location vector
    @param speed ball speed vector
    @return true if the game started false if still looking*/
bool gameStart(Vector_t* location, Vector_t* speed);

#endif /* COMMUNICATION_H */