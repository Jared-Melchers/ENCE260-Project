/**@file    displayscreen.c
 * @author  Jayden Pope
 * @date    12/10/2022
 * @brief   Displaying bitmaps onto the LED matrix
 */
#include "system.h"
#include "pio.h"
#include "displayscreen.h"
#include "platform.h"
#include "ledmat.h"


/** Initilising the LED matrix pins for the screen*/
void displayscreen_init()
{
    current_column = 0;
    
    // Initialise LED matrix pins
    for (uint8_t i = 0; i < LEDMAT_ROWS_NUM; i++) {
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
    for (uint8_t i = 0; i < LEDMAT_COLS_NUM; i++) {
        pio_config_set(cols[i], PIO_OUTPUT_HIGH);
    }
}

/** Updating the LED matrix with the given bitmap
    @param bitmap the bitmap to display on the screen*/
void displayscreen_tick(uint8_t bitmap[])
{
    ledmat_display_column(bitmap[current_column], current_column);

    current_column++;

    if (current_column > (LEDMAT_COLS_NUM - 1))
    {
        current_column = 0;
    }           
}
