/**
 * @file Game.cpp
 * @author Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Game.h"
#include "Digit.h"
#include "Item.h"
#include "VisitorItem.h"
#include "VisitorDigit.h"
#include "VisitorGiven.h"
#include "VisitorSparty.h"
#include "Sparty.h"
//using namespace std;
using std::make_unique;


/**
 * Game Constructor
 */
Game::Game()
{
    mLevel = std::make_shared<Level>(this);
    //mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);
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
//        if(item == mItems.back())
//        {
//            break;
//        }

        item->Draw(graphics);
        // If Item is a Container
        // Visit Container and then Draw ContainerItems
    }
   // mSparty->Draw(graphics);
    //mSpartyChin->Draw(graphics);


    ///Make sures timer is not drawn when popup is not nullptr
    if (mLevel->mPopup != nullptr && mTime*0.001 < 3) {
        mLevel->mPopup->Draw(graphics,pixelHeight,pixelWidth);
    } else {
        mTimeDisplay.OnDraw(graphics);
    }

    graphics->PopState();
}

/**
* Handle a mouse click
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnLeftDown(int x, int y)
{
    ///Makes sure sparty does not move when popup is drawn
    if (mLevel->mPopup == nullptr)
    {
        auto xOffset = mSparty->GetOffset().m_x;
        auto yOffset = mSparty->GetOffset().m_y;
        //x = x - xOffset;
        //y = y + (((mSparty->GetItemImage())->GetHeight()) - yOffset);

        double virtualX = (x - mXOffset) / mScale;
        double virtualY = (y - mYOffset) / mScale;

        //Should be a visitor to set New Coordinates instead of pointer to Sparty and Sparty Chin

        mSparty->SetNewCoordinates(virtualX, virtualY);
    }

}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double time)
{
    mTime = mTime + (time*1000);

    mTimeDisplay.Update(mTime);

    if (mTime*0.001 > 3 &&  mLevel->mPopup != nullptr) {

        this->ResetTime();
        mLevel->mPopup = nullptr;
    }

    if (mLevel->mPopup != nullptr) {
        mLevel->mPopup->Update(mTime);
    }

//    if (mSparty != nullptr) {
//
//
//
//        mSparty->Update(time);
//
//    }
    for (auto item: mItems) {
        item->Update(time);
    }

}

/**
 * Test an x,y location to see if has been eaten
 * by sparty
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::EatTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        VisitorSparty visitor;
        (*i)->Accept(&visitor);

        if(!visitor.IsSparty())
        {
            if ((*i)->EatTest(x, y))
            {
                return *i;
            }
        }

    }

    return  nullptr;
}

/**
 * Test an row, col location to see if it was hit
 * @param row row of the item
 * @param col col of the item
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int row, int col)
{
    double x = (col*48+ (20/2.0)) + 24;
    double y = ((row+1)*48 - (25/2.0)) + 24;
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
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

/**
 * Handle the key  down event for either key B or space bar.
 * @param event The key down event
 */
void Game::OnKeyDown(wxKeyEvent &event)
{


    if (event.GetKeyCode() == WXK_SPACE && int(mSparty->GetX()) == int(mSparty->GetNewX())
        && int(mSparty->GetY()) == int(mSparty->GetNewY()) && mSparty->GetAngle() == 0)
    {
        mSparty->SetNewAngle();

        int x = (int) (mSparty->GetX());
        int y = (int) (mSparty->GetY());

        auto item = EatTest(x, y);

        if(item != nullptr)
        {
            //Check if we clicked on a Digit that is not a Given
            VisitorDigit visitor;
            item->Accept(&visitor);

            if(visitor.IsDigit())
            {
                // We are next to a Digit
                VisitorGiven visitor2;
                item->Accept(&visitor2);

                if(! visitor2.IsGiven())
                {
                    // It is not a Given
                    item->Eat();
                }
            }
        }
    }
    // event key code 66 is the key for b
    if(event.GetKeyCode() == 66)
    {
        mSparty->headButt = true;
    }
}

/**
 * Accepts visitors to the Game
 * @param visitor visitor being accepted
 */
void Game::Accept(VisitorItem *visitor)
{
    for(auto item: mItems)
    {
        item->Accept(visitor);
    }
}


