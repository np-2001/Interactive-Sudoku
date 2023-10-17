/**
 * @file Game.cpp
 * @author Nitin Polavarapu, Samantha Wycoff, Sania Sinha
 */

#include "pch.h"
#include "Game.h"
#include "Digit.h"
#include "Item.h"
//using namespace std;
using std::make_unique;

/**
 * Game Constructor
 */
Game::Game() : mLevel(this)
{
    mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);
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
    int pixelWidth = mWidth*mTileSize;
    int pixelHeight = mHeight*mTileSize;

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

    //Displays the background and the grid
//    graphics->DrawBitmap(*mBackground, 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

    //Iterate over list of items
    //Draw each item in the list
    for(auto item : mItems)
    {
         //Sparty is hardcoded for now
        if(item == mItems.back())
        {
            break;
        }

        item->Draw(graphics);
    }
    mSparty->Draw(graphics);
    mSpartyChin->Draw(graphics);

    mTimeDisplay.OnDraw(graphics);


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

    //Should be a visitor to set New Coordinates instead of pointer to Sparty and Sparty Chin
    mSparty->SetNewCoordinates(virtualX,virtualY);
    mSpartyChin->SetNewCoordinates(virtualX,virtualY);

}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double time)
{
    mTimeDisplay.Update(time);

    if (mSparty != nullptr) {



        mSparty->Update(time);
        mSpartyChin->Update(time);
    }

}

/**
 * Add an item to our collection
 * @param item item to be added
 */
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Clear all items
 */
void Game::Clear()
{
    mItems.clear();
}