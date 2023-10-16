/**
 * @file Game.cpp
 * @author Nitin Polavarapu, Samantha Wycoff, Sania Sinha
 */

#include "pch.h"
#include "Game.h"
#include "Digit.h"
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
    int pixelWidth = 800;
    int pixelHeight = 800;

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

    graphics->DrawBitmap(*mBackground, 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

    // Delete, just for testing, this is how to create the items
//    auto item = make_shared<Digit>(this, L"images/0b.png");
//    item->SetLocation(10,10);
//    item->Draw(graphics);

    //
    // Drawing a rectangle that is the playing area size
    //
    //    wxBrush background(*wxRED);
    //
    //    graphics->SetBrush(background);
    //    graphics->DrawRectangle(100, 100, pixelWidth, pixelHeight);

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
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double time)
{
    mTimeDisplay.Update(time);
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