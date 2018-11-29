
#include "Assets\alpha.c"
#include "Assets\ancientevil.c"
#include "Assets\blankscreen.c"
#include "Assets\boba quest.h"
// #include "Assets\boba.h"
#include "Assets\border.c"
#include "Assets\chrisdialogue.c"
#include "Assets\congratulations.c"
#include "Assets\garland.c"
#include "Assets\healthbar.c"
#include "Assets\healthbarmap.c"
#include "Assets\jenny.c"
#include "Assets\jennydialogue.c"
#include "Assets\john.c"
#include "Assets\map_data.c"
#include "Assets\noc.c"
#include "Assets\noctext2.c"
#include "Assets\perish.c"
#include "Assets\pressstart.c"
#include "Assets\professorellis.h"
#include "Assets\profintro.c"
#include "Assets\profluck.c"
#include "Assets\question.c"
#include "Assets\sophiedialogue.c"
#include "Assets\starmap.c"
#include "Assets\starstiles.c"
#include "Assets\ticket.c"
#include "Assets\ticket2.c"
#include "Assets\tickets.c"
#include "Assets\trees2.c"
#include "Assets\vaporwave.h"
#include "Assets\window.c"
#include "Assets\coin.c"
#include <gb/gb.h>
#include <rand.h>
#include "frame0.h"
#include "frame00.h"
#include "frame01.h"
#include "frame02.h"
#include "frame03.h"

/*
MMMMMMMMMMMKkkl;;.       .;lKMMMMMMMMMMM
MMMMMMMMKkl.                .;;;lkKMMMMM
MMMMMKl;.                         .lKMMM
MMKkl.                              lMMM
MMMk.   ,:.  'c'                    .kMM
MMMl   :xxo:'.;do:.                  lMM
MMMl  'ddc:ldlloolc,..   .'  .,:;.   lMM
MMMKklcdll,.;oxkxoc:c.   ,o'.c::d;   lMM
MMMMMMXdodc..cxkkxxkko;';lo''o;,o,  ;KMM
MMMMMklxxdddlldxkkkkkxdxkko,:dc:,   lMMM
MMMMK,'dkkkkddxxkkkkkkkkkxcco:,.    lMMM
MMMMKkookkkkkkkkxxxxkkkkxdo;.       lMMM
MMMMMMNdokkkx:,,;odxkkkkdc;;,.      lMMM
MMMMMMMKxkkxko;;lxkxdo:,,';ddc.     lMMM
MMMMMMMMMMNXOxxool,..  .cc;c;.      lMMM
MMMMMMMMMMMMMMOldo;;::c,:olo;      ;lkMM
MMMMMMMMMMMNKkoll;;dkdlcodxkxl'    ;klkM
MMMMMMMMMKkxdxxol:cdxoldkkkkkkxl;'  lKKM
MMMMMMMMNdlooooooodxxdodkkkkkkkxxxc..kMM
MMMMMMMk:looododxxkkkxoodkkkxdxxxko. ;KM
MMMMMNkllxkdoxkkkkkkkxxxddxdoxkkkkx,  lM
MMMMKookkkkkooxxkkkkkkkkkooxxkkkkkk;  .k
MMMNl;xkkkkkoldxkkkkkkkkxooxxkkkkkk;   ,
MMOoddkkkkkkdodkkkkkkkkkxooxdxkkkkk;    
MKxdoooxkkkkkxdxkkkkkkkkkddkddkkkkk;    
Kxxxddddoloodxkkkkkkkkxddl;,,okkkkk:    
oxkkkkko;;ldoddoodddddddd:,;ldkkkkk:    
00kdxkd;,oxkkxd:cddxkkkkxoooxkkkkkk;    
MMNKXKl,;okkkocoxkkkkkkxdooxkkkkkkk;    
MMMMMMk::ldddolodddddxxololoxkkkkkk;    
MMMMMKkkxxxdddddddoodxxdloolc::;;,..    
MMMMM0xkkkkkkkkkkkxxkkkkxxoo;           


Holy include batman!
A lot tilemaps for dialogue are saved in seperate files, there is probably a better way to handle than hard coding
Tilemaps but for quick and easy way putting tiledata as const serves well without occupying too much memory
###########################################################
############### a lot of  defining ahead!! ################
###########################################################
*/
#define MapSizeX 64
#define SPR_HEIGHT 5
#define SPR_WIDTH 8
#define TOTAL_SPR SPR_WIDTH *SPR_HEIGHT
#define chrisPosX 15
#define chrisPosY 11
#define doorPosX 34
#define doorPosY 6
#define keyPosX 45
#define keyPosY 8
#define sophiePosX 30
#define sophiePosY 13

// Simple X,Y coordinates of various objects on the map
UBYTE johnTopX = 140;
UBYTE johnBottomX = 148;
UBYTE johnTopY = 75;
UBYTE johnBottomY = 91;
UBYTE spawned = 0;
BYTE introplayed = 0;
BYTE moveBoss = 1;
BYTE playsound = 6;
UBYTE badguy2_x, badguy2_y, badguy2_z, badguy2_offset;
UBYTE badguy_x, badguy_y, badguy_z, badguy_offset;
UBYTE n = 0;
UBYTE player_shot_x, player_shot_y, player_shot_z;
UINT8 collision(int x, int y);
UINT8 randomBkgTiles[20];
UINT8 sprite_index;

int bossfight = 0; // Has the boss fight started?
int counter = 0;
int credits = 0;       // Has player reached credits?
int currentFrame;      // Frametime check
int dialogue = 0;      // Is player in a dialogue?
int framecounter;      // Count frames
int garlandTalked = 0; // Has player talked to Chris about Garland?
int havenockey = 0;    //Has the player unlocked boss fight?
int haveticket = 0;    //Has the player talked to Sophie
int i = 0;
int isMoving = 0; //Is player moving?
int j;
int jennytalked = 0;
int l = 0;
int loadedjohn = 0;   //Init for boss
int movedsprites = 1; //Clear sprites
int scrollX = 0;
int shotsfired = 0;   //Health of boss
int sophietalked = 0; //Has Sophie displayed her dialogue?
int startedgame = 0;
int talking = 0; //Is player talking?
int tileCounter = 0;
int tileposX = 0;
int tileposY = 0;
int x = 75; // Player X position
int y = 75; // Player Y position
int removesound = -1;
int inputX = 0;
int inputY = 0;
// UINT8 nextX;
// UINT8 nextY;
int drawX;

// linker not being very smart we've got to pre-define these
void GotoBossFight();
void checkcollisions();
void checkinputboss();
void displayDialogue();
void init();
void render_huge_sprite();
void resetgame();
void updateBkg();
void updateCharacter();
void updateboss();
void playintro();
void creditsrender();
void openingcutscene();
void memoryoffsettilemap();

const UBYTE badguy_ai[] = {
    32, 32, 33, 34, 35, 35, 36, 37,
    38, 38, 39, 40, 41, 41, 42, 43,
    44, 44, 45, 46, 46, 47, 48, 48,
    49, 50, 50, 51, 51, 52, 53, 53,
    54, 54, 55, 55, 56, 56, 57, 57,
    58, 58, 58, 59, 59, 60, 60, 60,
    61, 61, 61, 61, 62, 62, 62, 62,
    62, 63, 63, 63, 63, 63, 63, 63,
    63, 63, 63, 63, 63, 63, 63, 63,
    62, 62, 62, 62, 62, 61, 61, 61,
    61, 60, 60, 60, 59, 59, 59, 58, //***                                ***
    58, 57, 57, 56, 56, 55, 55, 54, //   ***                          ***
    54, 53, 53, 52, 52, 51, 50, 50, //      **                      **
    49, 49, 48, 47, 47, 46, 45, 44, //        *                    *
    44, 43, 42, 42, 41, 40, 39, 39, //         *                  *
    38, 37, 36, 36, 35, 34, 33, 33, //         *                  *
    32, 31, 30, 29, 29, 28, 27, 26, //          *                *
    26, 25, 24, 23, 23, 22, 21, 20, //           **            **
    20, 19, 18, 18, 17, 16, 16, 15, //             ***      ***
    14, 14, 13, 12, 12, 11, 11, 10, //                ******
    9, 9, 8, 8, 7, 7, 6, 6,         //// Sine wave array
    6, 5, 5, 4, 4, 4, 3, 3,
    3, 2, 2, 2, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 2, 2,
    2, 3, 3, 3, 4, 4, 4, 5,
    5, 5, 6, 6, 7, 7, 8, 8,
    9, 9, 10, 11, 11, 12, 12, 13,
    14, 14, 15, 16, 16, 17, 18, 18,
    19, 20, 20, 21, 22, 23, 23, 24,
    25, 26, 26, 27, 28, 29, 29, 30};

/*


 _____ _   _______   ___________  ______ ___________ _____ _   _ _____ _   _ _____ 
|  ___| \ | |  _  \ |  _  |  ___| |  _  \  ___|  ___|_   _| \ | |_   _| \ | |  __ \
| |__ |  \| | | | | | | | | |_    | | | | |__ | |_    | | |  \| | | | |  \| | |  \/
|  __|| . ` | | | | | | | |  _|   | | | |  __||  _|   | | | . ` | | | | . ` | | __ 
| |___| |\  | |/ /  \ \_/ / |     | |/ /| |___| |    _| |_| |\  |_| |_| |\  | |_\ \
\____/\_| \_/___/    \___/\_|     |___/ \____/\_|    \___/\_| \_/\___/\_| \_/\____/
                                                                                   
                                                                                   


*/

void main()
{
    /*
###########################################################
############### Moving tiles by offset in memory ##########
###########################################################
*/
    enable_interrupts();
    memoryoffsettilemap();

    // init();
    while (1)
    { // MAIN GAME LOOP
        {
            if (introplayed == 1) // check if we already played Intro
            {
                if (startedgame == 1 && spawned == 0) // check if we pressed start button but didn't spawn the character yet
                { //opening spiel by prof. ellis
                openingcutscene();
                }
                if (credits == 1) // check if we won the game
                { // end game screen
                creditsrender();
                }
                if (startedgame == 1) // check if we pressed start 
                { // main game
                    wait_vbl_done();
                    if (bossfight == 1)  // check if we started boss battle
                    {
                        SPRITES_8x16;
                        enable_interrupts();
                        updateboss();
                        checkinputboss();
                        checkcollisions();
                    }
                    if (talking == 0 && bossfight == 0) // main moving map
                    { // main graphics "renderer"
                        updateCharacter();
                        updateBkg();
                    }

                    displayDialogue(); // dialogue system
                }

                else
                {
                    render_huge_sprite(); // start screen
                }
            }
            else
            {
                playintro();
            }
        }
    }
}

void memoryoffsettilemap()
{
    for (i = 0; i < 40; i++)
    {
        vaporwave_tilemap[i] += 0x5F;
    }
    for (i = 0; i < 14; i++)
    {
        bobaquest_tilemap[i] += 0x88;
    }
    for (i = 0; i < 12; i++)
    {
        starttext[i] += 1;
    }
    for (i = 0; i < 32; i++)
    {
        sophie1[i] += 1;
    }
    for (i = 0; i < 32; i++)
    {
        jenny1[i] += 1;
    }
    for (i = 0; i < 1; i++)
    {
        chris1[i] - 1;
    }
    // for (i = 0; i < 19; i++)
    // {
    //     boba_tilemap[i] += 0xA8;
    // }
    for (i = 0; i < 32; i++)
    {
        professorellis_tilemap[i] += 0xBA;
    }
}
void openingcutscene()
{
    talking = 1;

    // set_bkg_tiles(0, 0, 20, 18, blankScreen); // load in blank tiles
    set_bkg_tiles(12, 8, 5, 8, professorellis_tilemap);
    SHOW_WIN;
    set_win_tiles(1, 1, profintroWidth, profintroHeight, profintro);
    delay(2500);
    set_win_tiles(1, 1, profintroWidth, profintroHeight, profluck);
    delay(3000);
    HIDE_WIN;
    talking = 0;
    set_bkg_tiles(0, 0, 20, 18, blankScreen); // load in blank tiles
    SHOW_SPRITES;
    startedgame = 1;
    set_bkg_tiles(0, 0, map_dataWidth, map_dataHeight, map_data);
    set_sprite_data(0, 14, jenny); // load in character

    spawned = 1;
}

void creditsrender()
{
    set_bkg_tiles(0, 0, 20, 18, congratulations);
    // set_bkg_tiles(0, 6, 3, 6, boba_tilemap);
    HIDE_SPRITES;
    HIDE_WIN;
    delay(25000);
    credits = 0;
    resetgame();
    shotsfired = 0;
}

void playintro()
{
    //riot logo intro
    DISPLAY_ON;      // Turn on the display
    NR52_REG = 0x8F; // Turn on the sound
    NR51_REG = 0x11; // Enable the sound channels
    NR50_REG = 0x77;
    SHOW_BKG;
    set_bkg_tiles(0, 0, 20, 18, blankScreen); // load in blank tiles
    set_bkg_data(0, 26, frametiledata);
    set_bkg_tiles(8, 6, 5, 5, frametilemap);
    delay(600);

    set_bkg_data(0, 37, frame01_tiledata);
    set_bkg_tiles(7, 6, 6, 6, frame01_tilemap);
    delay(500);

    set_bkg_tiles(0, 0, 20, 18, blankScreen); // load in blank tiles
    set_bkg_data(0, 137, frame00_tiledata);
    set_bkg_tiles(2, 4, 17, 8, frame00_tilemap);
    delay(400);

    set_bkg_tiles(0, 0, 20, 18, blankScreen); // load in blank tiles
    set_bkg_data(0, 49, frame03_tiledata);
    set_bkg_tiles(6, 6, 8, 6, frame03_tilemap);
    delay(5000);
    introplayed = 1;
    HIDE_BKG;
    init();
}

void checkcollisions()
{
    if ((x > (badguy_x - 9) && x < (badguy_x + 9)) &&
        ((y > (badguy_y - 10) && y < (badguy_y + 10)) ||
         (y > ((badguy_y - 40) - 9) && y < ((badguy_y - 40) + 9)) ||
         (y > ((badguy_y + 40) - 9) && y < ((badguy_y + 40) + 9)) ||
         (y > ((badguy_y + 80) - 9) && y < ((badguy_y + 80) + 9))))
    {
        resetgame();
        scroll_bkg(0, 0);
        move_bkg(0, 0);
    }
    if ((player_shot_x > (johnTopX - 16) && player_shot_x < (johnTopX + 20)) &&
        ((player_shot_y > ((johnTopY + 16) - 10) && player_shot_y < ((johnTopY + 16) + 10))))
    {
        shotsfired++;
        NR52_REG = 0x80;
        NR51_REG = 0x11;
        NR50_REG = 0x77;

        NR10_REG = 0x1E;
        NR11_REG = 0x10;
        NR12_REG = 0xF3;
        NR13_REG = 0x00;
        NR14_REG = 0x87;
        for (i = 0; i < 12; i++)
        {
            NR52_REG = NR52_REG - 1;
            NR51_REG = NR51_REG - 1;
            NR50_REG = NR50_REG - 1;

            NR10_REG = NR10_REG - 10;
            NR11_REG = NR11_REG - 10;
            NR12_REG = NR12_REG - 10;
            NR13_REG = NR13_REG - 10;
            NR14_REG = NR14_REG - 10;
        }
        set_win_tiles(8 - shotsfired, 1, 1, 1, 0x2F); //0x2F
        player_shot_z = 0;
        player_shot_x = 250;
        player_shot_y = 250;
        for (i = 0; i < 4; i++)
        {
            wait_vbl_done();
            move_sprite(11, johnTopX + 1, johnTopY + 1);
            move_sprite(12, johnBottomX + 1, johnTopY + 1);
            move_sprite(13, johnTopX + 1, johnBottomY + 1);
            move_sprite(14, johnBottomX + 1, johnBottomY + 1);
            delay(40);
            move_sprite(11, johnTopX - 1, johnTopY - 1);
            move_sprite(12, johnBottomX - 1, johnTopY - 1);
            move_sprite(13, johnTopX - 1, johnBottomY - 1);
            move_sprite(14, johnBottomX - 1, johnBottomY - 1);
            move_sprite(15, johnTopX - 2, johnTopY);
            move_sprite(16, johnTopX - 4, johnTopY - 3);
            move_sprite(15, johnTopX - 4, johnTopY + 3);
            l = 1;
            n = rand() / 25;
            for (i = 0; i < 9; i++)
            {
                delay(16);
                l++;
                move_sprite(15, johnTopX - (n * l), johnTopY + (n * l));
                move_sprite(16, johnTopX - (n * l), johnTopY - (n * l));
                move_sprite(17, johnTopX - (n * l), johnTopY + (n * l) - 5);
                move_sprite(18, johnTopX - (n * l), johnTopY - (n * l) - 5);
                // move_sprite(15,johnTopX-2,johnTopY+2);
                // move_sprite(16,johnTopX-4,johnTopY-5);
                // move_sprite(15,johnTopX-4,johnTopY+5);
            }
            move_sprite(15, 0, 0);
            move_sprite(16, 0, 0);
            move_sprite(17, 0, 0);
            move_sprite(18, 0, 0);

            move_sprite(15, 0, 0);
        }
    }
}

void updateboss()
{
    if (shotsfired == 6)
    {
        startedgame = 0;
        credits = 1;
        scroll_bkg(0, 0);
        move_bkg(0, 0);
    }
    // load in character
    if (loadedjohn == 0)
    {
        SHOW_WIN;
        move_bkg(0, 0);
        set_sprite_tile(11, 0x0E);
        set_sprite_tile(12, 0x10);
        move_sprite(11, johnTopX, johnTopY);
        move_sprite(12, johnBottomX, johnTopY);
        set_sprite_tile(13, 18);
        set_sprite_tile(14, 20);
        move_sprite(13, johnTopX, johnBottomY);
        move_sprite(14, johnBottomX, johnBottomY);
        set_bkg_tiles(0, 0, 20, 20, blankScreen); // load in blank tiles
        set_win_tiles(1, 1, perishWidth, perishHeight, perish);
        set_bkg_data(0xA1, 7, starstiles);

        set_bkg_tiles(0, 0, starmapWidth, starmapHeight, starmap);
        set_sprite_tile(15, 0xA4);
        set_sprite_tile(16, 0xA5);
        set_sprite_tile(17, 0xA6);
        set_sprite_tile(18, 0xA7);

        talking = 1;
        delay(1500);
        talking = 0;
        set_win_tiles(0, 0, 20, 20, blankScreen);
        set_win_data(0xB7, 3, healthbar);
        move_win(50, 130);
        SHOW_WIN;
        set_win_tiles(1, 1, healthbarmapWidth, healthbarmapHeight, healthbarmap); //0x2F

        loadedjohn = 1;
    }
    scroll_bkg(1, 0);

    // draw boss
    move_sprite(11, johnTopX, johnTopY);
    move_sprite(12, johnBottomX, johnTopY);
    move_sprite(13, johnTopX, johnBottomY);
    move_sprite(14, johnBottomX, johnBottomY);

    // move boss
    johnTopY = johnTopY + moveBoss;
    johnBottomY = johnBottomY + moveBoss;

    if (johnTopY >= 100)
    {
        moveBoss = -1;
        // johnTopY = 149;
        // johnBottomY = 149+16;
    }
    if (johnTopY <= 20)
    {
        moveBoss = 1;
        // johnTopY = 51;
        // johnBottomY = 51+16;
    }

    // mailicon
    // set_sprite_tile(6,0x20);
    // set_sprite_tile(7,0x22); computer
    // set_sprite_tile(8,0x24);

    // if ((x > (badguy_x - 10) && x < (badguy_x + 10) && y > (badguy_y - 10) && y < (badguy_y + 10)) ||
    //     (x > (badguy_x - 10) && x < (badguy_x + 10) && y > ((badguy_y - 40) - 10) && y < ((badguy_y - 40) + 10)) ||
    //     (x > (badguy_x - 10) && x < (badguy_x + 10) && y > ((badguy_y + 40) - 10) && y < ((badguy_y + 40) + 10)))

    // move drones
    move_sprite(4, badguy_x, badguy_y);
    move_sprite(5, badguy_x + 8, badguy_y);
    move_sprite(6, badguy_x, badguy_y - 40);
    move_sprite(7, badguy_x + 8, badguy_y - 40);
    move_sprite(8, badguy_x, badguy_y + 40);
    move_sprite(9, badguy_x + 8, badguy_y + 40);
    //  move_sprite(10,badguy_x,badguy_y+80);
    move_sprite(20, badguy_x, badguy_y + 80);
    move_sprite(19, badguy_x + 8, badguy_y + 80);

    badguy_x = badguy_x - 1;
    if (badguy_x > 240)
    {
        badguy_offset = rand();

        while (badguy_offset > 75)
        {
            badguy_offset = rand();
        }

        badguy_x = 239;
    }

    badguy_y = badguy_offset + badguy_ai[badguy_z];

    badguy_z++;

    move_sprite(1, x + 8, y);
    move_sprite(0, x, y);
    move_sprite(10, player_shot_x, player_shot_y);
    if (joypad() & J_A && player_shot_z == 0)
    {

        NR52_REG = 0x80;
        NR51_REG = 0x11;
        NR50_REG = 0x77;

        NR10_REG = 0x1E;
        NR11_REG = 0x10;
        NR12_REG = 0xF3;
        NR13_REG = 0x00;
        NR14_REG = 0x87;

        player_shot_z = 1;
        player_shot_x = x;
        player_shot_y = y;
        delay(20);
    }
    else
    {
        NR11_REG = 0x00; // NO A BUTTON - NO SOUND
        NR12_REG = 0x00;
        NR13_REG = 0x00;
        NR14_REG = 0x00;
    }
    if (player_shot_z == 1)
    {
        player_shot_x = player_shot_x + 3;
        if (player_shot_x > 240)
        {
            player_shot_x = 250;
            player_shot_y = 250;
            player_shot_z = 0;
        }
    }
}

void resetgame()
{
    HIDE_SPRITES;
    HIDE_WIN;
    move_win(7, 112);
    shotsfired = 0;
    startedgame = 0;
    bossfight = 0;
    delay(1000);
    init();
    i = 0;
    x = 75;
    y = 75;
    tileposX = 0;
    tileposY = 0;
    isMoving = 0;
    startedgame = 0;
    l = 0;
    badguy_x = 0;
    badguy_y = 0;
    loadedjohn = 0;
    movedsprites = 0;

    scrollX = 0;
    tileCounter = 0;
    counter = 0;
}
void checkinputboss()
{

    if (joypad() & J_LEFT)
    {
        if (x > 8)
            x--;
    }
    if (joypad() & J_RIGHT)
    {
        if (x < 160)
            x++;
    }
    if (joypad() & J_UP)
    {
        if (y > 16)
            y--;
    }
    if (joypad() & J_DOWN)
    {
        if (y < 152)
            y++;
    }
}
void displayDialogue()
{

    if (tileposX > (sophiePosX - 3) && tileposX < (sophiePosX + 3) &&
        tileposY > (sophiePosY - 3) && tileposY < (sophiePosY + 3))
    {
        if (joypad() & J_A && haveticket == 0)
        {
            dialogue++;
            delay(100);

            switch (dialogue)
            {
            case 1:
                set_win_tiles(1, 1, sophie1Width, sophie1Height, sophie1);
                delay(500);
                SHOW_WIN;
                talking = 1;
                break;
            case 2:
                set_win_tiles(1, 1, jenny1Width, jenny1Height, jenny1);
                delay(500);
                talking = 1;
                break;

            case 3:
                set_win_tiles(1, 1, questionWidth, questionHeight, question);
                delay(500);
                talking = 1;
                break;

            case 4:
                set_win_tiles(1, 1, ticketWidth, ticketHeight, ticket);
                delay(500);
                talking = 1;

                break;
            case 5:
                dialogue = 0;
                HIDE_WIN;
                talking = 0;
                haveticket = 1;
                break;
            case 6:
                break; //this isnt used!
            }
        }
    }
    if (tileposX > (chrisPosX - 3) && tileposX < (chrisPosX + 3) &&
        tileposY > (chrisPosY - 3) && tileposY < (chrisPosY + 3))
    {
        if (joypad() & J_A)
        {
            dialogue++;
            delay(100);

            switch (dialogue)
            {
            case 1:
                if (haveticket == 0)
                {
                    set_win_tiles(1, 1, chris1Width, chris1Height, chris1);
                    delay(500);
                    SHOW_WIN;
                    talking = 1;
                }
                if (haveticket == 1)
                {
                    set_win_tiles(1, 1, ticket2Width, ticket2Height, ticket2);
                    delay(700);
                    SHOW_WIN;
                    talking = 1;
                }
                break;
            case 2:

                // if(haveticket=0){
                //     dialogue = 0;
                //     HIDE_WIN;
                //     talking = 0;}
                if (haveticket == 1)
                {
                    set_win_tiles(1, 1, ancientevilWidth, ancientevilHeight, ancientevil);
                    delay(500);
                    SHOW_WIN;
                    talking = 1;
                }
                break;

            case 3:
                if (haveticket == 1)
                {
                    set_win_tiles(1, 1, garlandWidth, garlandHeight, garland);
                    delay(500);
                    SHOW_WIN;
                    talking = 1;
                    garlandTalked = 1;
                }

                break;
            case 4:
                dialogue = 0;
                HIDE_WIN;
                talking = 0;
                break;
            case 5:
                break; //this isnt used!
            }
        }
    }
    if (tileposX > (keyPosX - 3) && tileposX < (keyPosX + 3) &&
        tileposY > (keyPosY - 3) && tileposY < (keyPosY + 3))
    {
        if (garlandTalked == 1 && havenockey == 0)
        {
            SHOW_WIN;
            set_win_tiles(1, 1, nocWidth, nocHeight, noc);
            delay(1000);
            HIDE_WIN;
            havenockey = 1;
        }
    }
    if (tileposX > (doorPosX - 3) && tileposX < (doorPosX + 3) &&
        tileposY > (doorPosY - 3) && tileposY < (doorPosY + 3))
    {
        if (garlandTalked == 1 && havenockey == 1)
        {
            bossfight = 1;
            x = 75;
            y = 75;
            havenockey = 0;
            talking = 0;
        }
    }
}
void render_huge_sprite()
{
    set_bkg_tiles(12, 9, 5, 8, vaporwave_tilemap);
    set_bkg_tiles(3, 4, 14, 1, bobaquest_tilemap);
    set_bkg_tiles(5, 7, 12, 1, starttext);
    HIDE_SPRITES;
    if (joypad() & J_START)
    {
        SHOW_SPRITES;
        startedgame = 1;
        set_bkg_tiles(0, 0, map_dataWidth, map_dataHeight, map_data);
        set_sprite_data(0, 14, jenny); // load in character
        SPRITES_8x16;
    }
}
void init()
{
    DISPLAY_ON;        // Turn on the display
    NR52_REG = 0x8F;   // Turn on the sound
    NR51_REG = 0x11;   // Enable the sound channels
    NR50_REG = 0x77;   // Increase the volume to its max
    initrand(DIV_REG); //initialize random

    SPRITES_8x8;
    set_bkg_data(0xBA, 41, professorellis_tiledata);
    // set_bkg_data(0xA8, 15, boba_tiledata);
    set_bkg_data(0x88, 15, bobaquest_tiledata);
    set_bkg_data(95, 41, vaporwave_tiledata);
    set_bkg_data(48, 47, alpha); //load in text data
    set_bkg_data(0, 47, tree);
    set_sprite_data(14, 14, john);
    set_sprite_data(0x1C, 11, tickets);
    set_sprite_tile(4, 0x16);
    set_sprite_tile(5, 0x18);
    set_sprite_tile(6, 0x16);
    set_sprite_tile(7, 0x18);
    set_sprite_tile(8, 0x16);
    set_sprite_tile(9, 0x18);
    set_sprite_tile(10, 0x26);
    set_sprite_tile(19, 0x18);
    set_sprite_tile(20, 0x16);

    //  set_bkg_tiles(0,4,10,2,noctext2); // load in text in noctext.c

    HIDE_WIN;
    set_win_data(152, 9, border);
    set_win_tiles(0, 0, 20, 4, window);
    move_win(7, 112);
    HIDE_WIN;

    set_bkg_tiles(0, 0, 20, 18, blankScreen); // load in blank tiles

    SHOW_BKG;
    SHOW_SPRITES;
}

void SetAnimationFrame(int frame)
{
    switch (frame)
    {
    case 0:
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);
        break;
    case 1:
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 6);
        break;
    case 2:
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);
        break;
    case 3:
        set_sprite_tile(0, 8);
        set_sprite_tile(1, 10);
        break;
    case 4: // HACK NOTE: this isnt used!
        break;
    }
}

void updateCharacter()
{
    if (movedsprites == 0)
    {
        move_sprite(3, 0, 0);
        move_sprite(4, 0, 0);
        move_sprite(5, 0, 0);
        move_sprite(6, 0, 0);
        move_sprite(7, 0, 0);
        move_sprite(8, 0, 0);
        move_sprite(9, 0, 0);
        move_sprite(10, 0, 0);
        move_sprite(11, 0, 0);
        move_sprite(12, 0, 0);
        move_sprite(13, 0, 0);
        move_sprite(14, 0, 0);
        move_sprite(20, 0, 0 + 8);
        move_sprite(19, 0 + 8, 0 + 8);
        movedsprites = 1;
    }
    // Gather input
    inputX = inputY = 0;

    isMoving = 0;
    if (joypad() & J_RIGHT)
    {
        inputX = 1;
        isMoving = 1;
    }
    if (joypad() & J_LEFT)
    {
        inputX = -1;
        isMoving = 1;
    }

    if (joypad() & J_UP)
    {
        inputY = -1;
        isMoving = 1;
    }
    if (joypad() & J_DOWN)
    {
        inputY = 1;
        isMoving = 1;
    }

    if (joypad() & J_SELECT)
    {
        GotoBossFight(); // Debug purposes only
    }
    // if (joypad() & J_A){

    //     set_win_data(152, 9, border);
    //     set_win_tiles(0, 0, 20, 4, window);
    //     move_win(7, 112);

    //     SHOW_WIN;
    // }
    if (isMoving)
    {
        framecounter++;
        if (framecounter >= 4)
        {
            framecounter = 0;
            currentFrame++;

            // x += inputX;
            // y += inputY;
        }
    }
    else
    {
        framecounter = 0;
        currentFrame = 0;
    }

    SetAnimationFrame(currentFrame % 4);

    // intergrate input
    // nextX = x+inputX;
    // nextY = y+inputY;
    // tileposX = nextX/8;
    // tileposY = nextY/8;

    x = x + inputX;
    y = y + inputY;
    tileposX = x / 8;
    tileposY = y / 8;

    if (collision(tileposX, tileposY) == 1)
    {
        x = x - inputX;
        y = y - inputY;
        isMoving = 0;
    }

    if (x <= 0)
        x = 0;
    // TODO figure out max x pos
    if (y <= 15)
        y = 15;
    if (y >= 146)
        y = 146;

    if (x >= 75)
        drawX = 75;
    else
        drawX = x;

    move_sprite(0, drawX, y);
    move_sprite(1, drawX + 8, y);
}

UINT8 collision(int x, int y)
{
    // 46, 32, 8, 37
    int index = 0;
    y -= 1;
    index = (y * map_dataWidth) + x;
    if (map_data[index] == 46 || map_data[index] == 32 || map_data[index] == 8 || map_data[index] == 37 || map_data[index] == 47)
    {
        return 0;
    }
    return 1;
}

void updateBkg()
{
    if (isMoving == 0)
        return;
    if (x < 75)
        return;

    if ((joypad() & J_LEFT) && (scrollX != 0))
    {
        scroll_bkg(-1, 0);
        tileCounter--;
    }
    if ((joypad() & J_RIGHT) && (scrollX < map_dataWidth - 2))
    {
        scroll_bkg(1, 0);
        tileCounter++;
    }

    if (tileCounter == 8)
    {
        scrollX++;
        tileCounter = 0;
        counter = scrollX + 21;
        j = counter % 32;
        for (i = 0; i < map_dataHeight; i++)
        {
            set_bkg_tiles(j, i, 1, 1, &(map_data + counter));
            counter = counter + map_dataWidth;
        }
    }
    if (tileCounter == -8)
    {
        scrollX--;
        tileCounter = 0;
        counter = scrollX - 1;
        j = counter % 32;

        for (i = 0; i < map_dataHeight; i++)
        {
            set_bkg_tiles(j, i, 1, 1, &(map_data + counter));
            counter = counter + map_dataWidth;
        }
    }

    // if (tileCounter == 8)
    // {
    //     scrollX++;
    //     tileCounter = 0;
    //     counter = scrollX + 21;
    //     int tx = counter % 32;

    //     for (int ty = 0; ty != 18; ty++)
    //     {
    //         set_bkg_tiles(tx,ty,1,1, &(map_data+counter));
    //         counter = counter + map_dataWidth;
    //     }
    // }
}

void GotoBossFight()
{
    bossfight = 1;
    x = 75;
    y = 75;
}
