#if 0 // [TODO]
#include "display/display.h"
#include "gameboy/gameboy.h"
#endif
#include <cstdint>
#include <cstdio>

#include "display/display.h"

/******************************************************************************
*
*      Summary: Emulator main entry point (main)
*               Starts and runs the emulator
*
*       INPUTS
*         Args: Usage: ./emulator /path/ROM [OPTIONS]
*               Options:
*                   -c /path/cfg - path to gameboy config file
*      Globals: None
*
*    ALGORITHM: Initialize a 'virtual' gameboy, load a ROM to it, then start
*               playing your game :D
*
*      OUTPUTS
*       Params: None
*      Globals: None
*       Return: None
*
*******************************************************************************/
int main(int argc, char **argv)
{
   printf("Welcome to Gameboy Emulator!\n");
   int width = 144;
   int height = 160;
   // uint32_t mpVidBuff[width * height];   // 160x144
   // char mpAudioBuff[256];

#if 0 // [TODO]
   Gameboy *gameboy = new Gameboy(mpVidBuff, mpAudioBuff);
   gameboy->load(ROM);
   gameboy->turn_on();
#endif

   Display *display = new Display(width, height);

   /* Emulator loop */
   while (display->isActive())
      {
         // [TODO] Gameboy.run();
         display->display();
      }

   return 0;
}
