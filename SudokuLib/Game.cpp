/**
 * @file Game.cpp
 * @author Nitin Polavarapu, Samantha Wycoff
 */

#include "pch.h"
#include "Game.h"

/**
 * Game Constructor
 */
Game::Game()
{

}

/**
* Draw the game
* @param graphics Graphics device to draw on
* @param width Width of the window
* @param height Height of the window
*/
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Determine the size of the playing area in pixels
    // This is up to you...

    //These cannot remain constants, they are constants for testing purposes!!
    int pixelWidth = 48;
    int pixelHeight = 48;

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE


    graphics->PopState();

}

/**
* Handle a mouse click
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnLeftDown(int x, int y)
{
    double virtualX = (x - mXOffset) / mScale;
    double virtualY = (y - mYOffset) / mScale;
}

