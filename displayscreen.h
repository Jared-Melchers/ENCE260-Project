/**@file    displayscreen.h
 * @author  Jayden Pope
 * @date    12/10/2022
 * @brief   Displaying bitmaps onto the LED matrix
 */
#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H

#include "system.h"
#include "pio.h"

uint8_t current_column;

// Define PIO pins driving LED matrix rows
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};


// Define PIO pins driving LED matrix columns
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

/** Initilising the LED matrix pins for the screen*/
void displayscreen_init(void);

/** Updating the LED matrix with the given bitmap
    @param bitmap the bitmap to display on the screen*/
void displayscreen_tick(uint8_t bitmap[]);

#endif /* DISPLAYSCREEN_H */