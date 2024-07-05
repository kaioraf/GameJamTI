//global includes for entire project
#pragma once    
#include <ti/getcsc.h>
#include <graphx.h>
#include <time.h>
#include <keypadc.h>
#include <math.h>
#include <debug.h>
#include <ti/screen.h>
/* Include the converted graphics file */
#include "gfx/gfx.h"
#include "compression.h"

/* Include the external tilemap data */
extern unsigned char dungeonmap[];
// extern unsigned char snowLevel_2_map[];
// extern unsigned char mainMenu_map[];
// extern unsigned char sword_map[];
// extern unsigned char sword_2_map[];

/* Holds the decompressed tile pointers */
// gfx_sprite_t *snowSet1_tiles[140];
// gfx_sprite_t *GUI_tiles[15];
// gfx_sprite_t *SwordMap_tiles[12];
// gfx_sprite_t *SwordSet2_tiles[14];


/*Tilemap defines*/
#define TILE_WIDTH 32
#define TILE_HEIGHT 32

#define dungeonmap_WIDTH 18
#define dungeonmap_HEIGHT 8
// #define snowLevel2_WIDTH 30
// #define snowLevel2_HEIGHT 20

// #define mainMenu_WIDTH 7
// #define mainMenu_HEIGHT 9

#define dungeonmap_DRAW_WIDTH 11
#define dungeonmap_DRAW_HEIGHT 8
// #define snowLevel2_DRAW_WIDTH 21
// #define snowLevel2_DRAW_HEIGHT 15

// #define mainMenu_DRAW_WIDTH 7
// #define mainMenu_DRAW_HEIGHT 9


#define dungeonmap_Y_OFFSET 16
#define dungeonmap_X_OFFSET 0
// #define snowLevel2_Y_OFFSET 16
// #define snowLevel2_X_OFFSET 0

// #define mainMenu_Y_OFFSET 32
// #define mainMenu_X_OFFSET 0

// #define optionsMenu_Y_OFFSET 32
// #define optionsMenu_X_OFFSET (GFX_LCD_HEIGHT - mainMenu_WIDTH) / 2

// #define mainMenuItemCount 3

#define PLAYER_START_X GFX_LCD_WIDTH  / 2
#define PLAYER_START_Y (GFX_LCD_HEIGHT - PlayerSprite_height) / 2

// #define snowLevel1ChestLocationX 7 * TILE_WIDTH
// #define snowLevel1ChestLocationY 6 * TILE_HEIGHT
// #define snowLevel2ChestLocationX 6 * TILE_WIDTH
// #define snowLevel2ChestLocationY 12 * TILE_HEIGHT

