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
#include "VisitorXray.h"
#include "VisitorGiven.h"
#include "VisitorSparty.h"
#include "VisitorBackground.h"
#include "VisitorXray.h"
#include "VisitorContainer.h"
#include "Background.h"
#include "Sparty.h"
#include "Xray.h"
//using namespace std;
using std::make_unique;


/**
 * Game Constructor
 */
Game::Game()
{
    mLevel = std::make_shared<Level>(this);
    mPlayingArea = std::make_shared<PlayingArea>(this);
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
    int pixelWidth = mWidth * mTileSize;
    int pixelHeight = mHeight * mTileSize;

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if(height > pixelHeight * mScale)
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
    if(mLevel->mPopup != nullptr && mTime * 0.001 < 3)
    {
        mLevel->mPopup->Draw(graphics, pixelHeight, pixelWidth);
    }
    else
    {
        mTimeDisplay.OnDraw(graphics);

        auto level = GetLevel();

        /// Level 3 Feature
        if(level->GetCurrentLevel() == L"Levels/level3.xml")
        {
            auto xray = GetXray();
            VisitorXray xray_visitor;
            xray->Accept(&xray_visitor);

            xray_visitor.CallThrowup(graphics);
            //Throwup(graphics,xRay);

        }

        graphics->PopState();
    }
}

void Game::Throwup(std::shared_ptr<wxGraphicsContext> graphics, Xray* xRay) {
    int pixelWidth = mWidth * mTileSize;
    int pixelHeight = mHeight * mTileSize;
    if(((mTime / 1000) % 60) % 10 == 0 && xRay->GetItemCount() > 0)
    {
        wxFont bigFont(wxSize(0, 50),
                       wxFONTFAMILY_SWISS,
                       wxFONTSTYLE_NORMAL,
                       wxFONTWEIGHT_BOLD);
        graphics->SetFont(bigFont, *wxGREEN);

        double wid, hit;
        graphics->GetTextExtent(L"THROW UP!!!!!", &wid, &hit);
        graphics->DrawText(L"THROW UP!!!!!", pixelWidth / 2 - wid / 2, pixelHeight / 2 - hit / 2);
        mSparty->SetNewAngleMouth();

        ///Code here to move items from x-ray mItems back to mItems of game, then set location


    }
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
        int virtualX = (x - mXOffset) / mScale;
        int virtualY = (y - mYOffset) / mScale;

        //Sparty does not move when the left click is outside the background

        if(virtualX >= 0 && virtualX < mWidth*mTileSize && virtualY >= 0 && virtualY < mHeight*mTileSize)
        {
            //Should be a visitor to set New Coordinates instead of pointer to Sparty and Sparty Chin
            mSparty->SetMoving(true);
            mSparty->SetNewCoordinates(virtualX, virtualY);
        }
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

        if(!visitor.MatchSparty())
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
 * Test an x,y location to see if it was hit
 * @param x x pixel location of the item
 * @param y y pixel location of the item
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
    for (auto i = mItems.begin(); i != mItems.end();  i++)
    {
        VisitorBackground backgroundVisitor;
        VisitorSparty spartyVisitor;
        VisitorXray xrayVisitor;

        (*i)->Accept(&backgroundVisitor);
        (*i)->Accept(&spartyVisitor);
        (*i)->Accept(&xrayVisitor);


        if ((*i)->HitTest(x, y) && !backgroundVisitor.MatchBackground() &&
            !spartyVisitor.MatchSparty() && !xrayVisitor.MatchXray())
        {
            return *i;
        }
    }

    return  nullptr;
}

/**
* Finds a pointer to a specific digit on the board if one exists
* otherwise returns nullptr
* @param num digit value we are looking for
* @return pointer to an item or nullptr
*/
std::shared_ptr<Item> Game::FindNumber(int num) {

    for (auto i = mItems.begin(); i != mItems.end();  i++)
    {
        //TODO: check every item to see if its the correct digit we need if so return it
        VisitorDigit visitor;
        (*i)->Accept(&visitor);

        if(visitor.GetValue() == num) {
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
    int count = 0;

    if (mLevel->mPopup == nullptr)
    {
        if(event.GetKeyCode() == WXK_SPACE && !(mSparty->GetMoving()) && mSparty->GetAngleMouth() == 0
            && mSparty->GetAngleHead() == 0)
        {
            mSparty->SetNewAngleMouth();

            int x = (int)(mSparty->GetX());
            int y = (int)(mSparty->GetY());

            auto item = EatTest(x, y);

            if(item != nullptr)
            {
                //Check if we clicked on a Digit that is not a Given
                VisitorDigit visitor;
                item->Accept(&visitor);

                if(visitor.MatchDigit())
                {
                    // We are next to a Digit
                    VisitorGiven visitor2;
                    item->Accept(&visitor2);

                    if(!visitor2.MatchGiven())
                    {
                        // It is not a Given
                        item->SetEatenLocation(item->GetRow(),item->GetCol());
                        mItems.erase(std::remove(mItems.begin(), mItems.end(), item), mItems.end());
                        item->Eat();
                        VisitorXray xray_visitor;
                        auto xray = GetXray();
                        xray->Accept(&xray_visitor);
                        xray_visitor.CallAdd(item);
                        count += 1;
                    }
                    else
                    {
                        // We are next to a Given
                        item->Regurgitate();
                        count -= 1;
                    }
                }
            }
        }
        // event key code 66 is the key for b
        auto oldx = int(mSparty->GetX());
        auto oldy = int(mSparty->GetNewY());
        auto newx = int(mSparty->GetNewX());
        auto newy = int(mSparty->GetNewY());
        auto currangle = int(mSparty->GetAngleMouth());
        if(event.GetKeyCode() == 66 && !(mSparty->GetMoving()) && mSparty->GetAngleMouth() == 0)
        {
            mSparty->SetNewAngleHead();

            int x = (int)(mSparty->GetX());
            int y = (int)(mSparty->GetY());

            // HitTest For Container
            auto item = HitTest(x+50,y);
            if (item != nullptr)
            {
                VisitorContainer visitor;
                item->Accept(&visitor);

                if (visitor.MatchContainer())
                {
                    wxMessageBox(L"This is a container");

                }

            }
            //        Should not be here
            //        auto item = EatTest(x, y);
            //
            //        if(item != nullptr)
            //        {
            //            //Check if we clicked on a Digit that is not a Given
            //            VisitorDigit visitor;
            //            item->Accept(&visitor);
            //
            //            if(visitor.MatchDigit())
            //            {
            //                // We are next to a Digit
            //                VisitorGiven visitor2;
            //                item->Accept(&visitor2);
            //
            //                if(! visitor2.MatchGiven())
            //                {
            //                    // It is not a Given
            //                    item->Eat();
            //                }
            //            }
            //        }
        }
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

std::shared_ptr<Item> Game::GetXray()
{
    for(auto item: mItems)
    {
        VisitorXray visitor;
        item->Accept(&visitor);

        if(visitor.MatchXray())
        {
            return item;
        }
    }

    return nullptr;
}
