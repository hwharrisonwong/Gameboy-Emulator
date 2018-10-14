/******************************************************************************
*
*   [TODO]
*   - Create Display interface class
*      - Main thing is for abstracting away window, input, and audio library.
*      - Polymorphism for keyCallback() to tell what emulator fnctions should
*        be invoked when pressing a key.
*      - Define interface for mouse_callback too
*      - Create key mapping XML
*
*******************************************************************************/

#include "display/display.h"
#include <ctime>

char WINDOW_NAME[] = "Gameboy Emulator";      /* Window name */

/******************************************************************************
*
*   CLASS IMPLEMENTATIONS
*
*******************************************************************************/

/* Display */
std::string Display::CLASS_NAME = "Display";

/******************************************************************************
*
*      Summary: Display - Display Initializer
*
*       INPUTS
*       Params: mWidth      - number of pixels horizontal
*               mHeight     - number of pixels vertical
*      Globals: None
*
*    ALGORITHM: Initialize window, input, and audio context.
*               Initialize display's video buffer based on mWidth and mHeight,
*               and initialize audio buffer.
*
*      OUTPUTS
*       Params: None
*      Globals: None
*
*******************************************************************************/
Display::Display(int mWidth, int mHeight)
{
   /* Initialize display */
   mWidth = mWidth;
   mHeight = mHeight;
   mpVidBuff = new uint32_t[mWidth*mHeight];
   mpAudioBuff = new char[256]; // [TODO] size

   /* Initialize GLFW */
   if (!glfwInit())
   {
       printf("%s: Failed to initialize GLFW.\n", Display::CLASS_NAME.c_str());
       return;
   }

   /* Create a windowed mode window and its OpenGL context */
   mpWindow = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
   if (!mpWindow)
   {
       printf("%s: Failed to create window.\n", Display::CLASS_NAME.c_str());
       glfwTerminate();
       return;
   }

   glfwSetWindowTitle(mpWindow, "CS184");

   /* Set callback functions to respond to different events */
#if 0
   // [TODO] Implement
   glfwSetWindowSizeCallback(window, size_callback);
   // [TODO] Put in base interface
   glfwSetMouseCallback(window, mouse_callback);
   glfwSetCursorPos(window< cursor_callback);
#endif
   glfwSetKeyCallback(mpWindow, keyCallback);

   /* Make the window's context current */
   glfwMakeContextCurrent(mpWindow);
}

Display::~Display()
{
   // [TODO] Implement
   delete mpVidBuff;
   delete mpAudioBuff;
}

/******************************************************************************
*
*      Summary: display - Display visuals and audio
*
*       INPUTS
*       Params: None
*      Members: window
*      Globals: Video buffer [TODO] rename
*               Audio buffer [TODO] rename
*
*    ALGORITHM: Shows the next frame and outputs more from the audio buffer.
*               Also polls for user input and puts them into the input buffer.
*
*      OUTPUTS
*       Params: None
*      Members: None
*      Globals: Input buffer [TODO] rename
*
*******************************************************************************/
void Display::display()
{
   char FUNC_NAME[] = "display";

   /* Clear the buffer */
   glClear(GL_COLOR_BUFFER_BIT);

   time_t time = clock();

   // [DEBUG] start
   /* Colors in decimal */
   uint32_t red = 4278190080;
   uint32_t blue = 65280;
   uint32_t green = 16711680;
   int c = 0;
   c = rand() % 3;
   for (int i = 0; i < mWidth * mHeight; i++)
   {
      // c = rand() % 3;
      switch(c)
      {
         case 0:
            mpVidBuff[i] = red;
            break;
         case 1:
            mpVidBuff[i] = green;
            break;
         case 2:
            mpVidBuff[i] = blue;
            break;
         default:
            mpVidBuff[i] = 0;
            break;
      }
   }
   // [DEBUG] end

   /* Draw pixels from the video buffer, each 4byte contains RGBA info */
   glDrawPixels(mWidth, mHeight, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, (GLvoid*)mpVidBuff);

   /* Swap front and back buffers */
   glfwSwapBuffers(mpWindow);

   time = clock() - time;
   /* Update and display fps */
   // updateFpsStats(static_cast<int>(time));
   // displayFps();
}

/******************************************************************************
*
*      Summary: isActive - Display is active
*
*       INPUTS
*       Params: None
*      Members: window
*      Globals: None
*
*    ALGORITHM: Check if user hasn't closed the display window yet.
*
*      OUTPUTS
*       Params: None
*      Members: None
*      Globals: None
*
*******************************************************************************/
bool Display::isActive()
{
   // [TODO] Check audio?
   return !glfwWindowShouldClose(mpWindow);
}


void Display::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   // [TODO] Implement
   return;
}

void Display::draw()
{
   // [TODO] Implement
}

void Display::outputAudio()
{
   // [TODO] Implement
}
void Display::pollInput()
{
   // [TODO] Implement
}
void Display::setCallbacks()
{
   // [TODO] Implement
}

void Display::setWindowSize(int mWidth, int mHeight)
{
   // [TODO] Implement
}

/******************************************************************************
*
*      Summary: updateFpsStats - Updates fps stat
*
*       INPUTS
*       Params: drawTime         - Time taken to draw the last frame
*      Members: mImgCount
*               mAvgImgDrawTime
*      Globals: None
*
*    ALGORITHM: Increments the image count and recalculates the running
*               average time to draw a frame by doing mAvgImgDrawTime/mImgCount.
*
*      OUTPUTS
*       Params: None
*      Members: mImgCount
*               mAvgImgDrawTime
*      Globals: None
*
*******************************************************************************/
void Display::updateFpsStats(int drawTime)
{
   // [TODO] Implement
   printf("DRAW: %d\n", drawTime);
   /* Keep only running average of last ten frames */
   if (mImgCount >= 10)
   {
      mImgCount = 0;
      mAccImgDrawTime = 0;
      mAvgImgDrawTime = 0;
   }

   /* Update running average */
   mImgCount++;
   mAccImgDrawTime += drawTime;
   mAvgImgDrawTime = mAccImgDrawTime / mImgCount;
}

void Display::displayFps()
{
   printf("AVG: %d\n", mAvgImgDrawTime);
   // printf("FPS: %d\n", 1000 / mAvgImgDrawTime);
}
