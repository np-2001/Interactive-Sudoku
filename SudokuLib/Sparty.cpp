/**
 * @file Sparty.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include <cmath>
using namespace std;


/// Character speed in pixels per second
const double MaxSpeed = 3200;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;


/**
 * Constructor
 * @param game Game object associated with this item
 */
Sparty::Sparty(Game *game, std::shared_ptr<wxImage> image) : Item(game, image)
{
}

/**
 * Accepting visitor to Sparty
 * @param visitor visitor object
 */
void Sparty::Accept(VisitorItem* visitor)
{
    visitor->VisitSparty(this);
}

/**
 * Sparty eats and does not get eaten
 * @param item digit to be eaten
 */
void Sparty::Eat()
{

}

void Sparty::Regurgitate()
{

}

void Sparty::Update(double elapsed)
{
    double CurrLocationX = Item::GetX();
    double CurrLocationY = Item::GetY();
    //Boolean is moving to false when you set target to set it true and then set it to false in the else statement in line 73. Do the offset in mNewLocationX




    wxPoint2DDouble Vector(mNewLocationX-CurrLocationX,mNewLocationY-CurrLocationY);


    Game * mGame = Item::GetGame();

    if (mMoving == true && (Vector.m_x != 0 || Vector.m_y != 0)) {

        double Length = Vector.GetVectorLength();
        Vector.Normalize();

        Vector = (Vector*MaxSpeed);

        wxPoint2DDouble NewVector(Vector.m_x / mGame->GetWidth(),Vector.m_y/mGame->GetHeight());

        if (NewVector.GetVectorLength() * elapsed < Length) {
            Item::SetPixelLocation(NewVector.m_x*elapsed+CurrLocationX,NewVector.m_y*elapsed+CurrLocationY);
        } else {
            Item::SetPixelLocation(mNewLocationX,mNewLocationY);
            SetMoving(false);
        }

    }

    mMouthCurrAngle += (mMouthNewAngle-mMouthCurrAngle)*(elapsed*8);

    if (std::abs(mMouthCurrAngle-mMouthNewAngle) < 0.001) {
        mMouthCurrAngle = mMouthNewAngle;
        mMouthNewAngle = 0;
    }


    mHeadCurrAngle += (mHeadNewAngle-mHeadCurrAngle)*(elapsed*8);

    if (std::abs(mHeadCurrAngle-mHeadNewAngle) < 0.001) {
        mHeadCurrAngle = mHeadNewAngle;
        mHeadNewAngle = 0;
    }
}

/**
 * Constructor for sparty item
 * @param game Game this sparty belongs to
 * @param image1 sparty
 * @param image2 sparty chin
 * @param front draw order of sparty's different images
 * @param headAngle sparty pivot angle
 * @param headX sparty pivot x
 * @param headY sparty pivot y
 * @param mouthAngle sparty mouth angle pivot
 * @param mouthX sparty mouth pivot x
 * @param mouthY sparty mouth pivot y
 * @param targetX offset x for clicked location
 * @param targetY offset y for clicked location
 */
Sparty::Sparty(Game *game,
               std::shared_ptr<wxImage> image1,
               std::shared_ptr<wxImage> image2,
               int front,
               double headAngle,
               double headX,
               double headY,
               double mouthAngle,
               double mouthX,
               double mouthY,
               double targetX,
               double targetY) : Item(game, image1)
{
    // Just a bunch of initialisations
    mImage = image1;
    mImage2 = image2;
    mFront = front;
    mHeadAngle = headAngle;
    mHeadPivotX = headX;
    mHeadPivotY = headY;
    mMouthAngle = mouthAngle;
    mMouthPivotX = mouthX;
    mMouthPivotY = mouthY;
    mTarget = wxPoint2DDouble(targetX, targetY);

    //mChin = std::make_shared<SpartyChin>(game,mImage2,mFront,mHeadAngle,mHeadPivotX,mHeadPivotY,mMouthAngle,mMouthPivotX,mMouthPivotY,targetX,targetY);
}

void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics) {

    int wid = mImage2->GetWidth();
    int hit = mImage2->GetHeight();
    // Make these getters in Game, Level class
    int tileHeight = Item::GetGame()->GetTileSize();
    auto x = ((Item::GetCol()*tileHeight));
    auto y = (((Item::GetRow()+1)*tileHeight) - hit);




    if (mFront == 2) {
        graphics->PushState();

        graphics->Translate(x,y);

        graphics->Translate(mHeadPivotX, mHeadPivotY);
        graphics->Rotate(mHeadCurrAngle);
        graphics->Translate(-mHeadPivotX, -mHeadPivotY);
        Sparty::HeadDraw(graphics);


//        graphics->Translate(mHeadPivotX, mHeadPivotY);
//
//        graphics->Rotate(0);
//        graphics->Translate(-mHeadPivotX, -mHeadPivotY);


        graphics->Translate(mMouthPivotX, mMouthPivotY);
        graphics->Rotate(mMouthCurrAngle);
        graphics->Translate(-mMouthPivotX, -mMouthPivotY);
        Sparty::ChinDraw(graphics);
        graphics->PopState();
    } else {
        graphics->PushState();

        graphics->Translate(x,y);

        graphics->Translate(mHeadPivotX, mHeadPivotY);
        graphics->Rotate(mHeadCurrAngle);
        graphics->Translate(-mHeadPivotX, -mHeadPivotY);

        graphics->Translate(mMouthPivotX, mMouthPivotY);
        graphics->Rotate(mMouthCurrAngle);
        graphics->Translate(-mMouthPivotX, -mMouthPivotY);
        Sparty::ChinDraw(graphics);
        graphics->PopState();

        graphics->PushState();
        graphics->Translate(x,y);
//        graphics->Translate(mMouthPivotX, mMouthPivotY);
//        graphics->Rotate(0);
//        graphics->Translate(-mMouthPivotX, -mMouthPivotY);


        graphics->Translate(mHeadPivotX, mHeadPivotY);
        graphics->Rotate(mHeadCurrAngle);
        graphics->Translate(-mHeadPivotX, -mHeadPivotY);
        Sparty::HeadDraw(graphics);
        graphics->PopState();




    }

}


void Sparty::ChinDraw(std::shared_ptr<wxGraphicsContext> graphics) {
    // Load in BitMap only once
    int wid = mImage2->GetWidth();
    int hit = mImage2->GetHeight();


    if(mChinBitmap.IsNull())
    {
        mChinBitmap = graphics->CreateBitmapFromImage(*mImage2);
    }

    if (mImage2 != nullptr)
    {
        wid = mImage2->GetWidth();
        hit = mImage2->GetHeight();

        graphics->DrawBitmap(mChinBitmap, 0,0, wid, hit);

    }
}

/**
 * Handle drawing Sparty head image and headbutt animation.
 * @param graphics Graphics device to draw with.
 */
void Sparty::HeadDraw(std::shared_ptr<wxGraphicsContext> graphics) {
    // Load in BitMap only once
    int wid = mImage->GetWidth();
    int hit = mImage->GetHeight();

    if(mHeadBitmap.IsNull())
    {
        mHeadBitmap = graphics->CreateBitmapFromImage(*mImage);
    }

    if (mImage != nullptr)
    {

        graphics->DrawBitmap(mHeadBitmap, 0,0, wid, hit);

    }
}

/// Setter for NewX and NewY
void Sparty::SetNewCoordinates(int NewX, int NewY) {
    Game * mGame = Item::GetGame();
    mNewLocationX = NewX-mTarget.m_x+mGame->GetTileSize();
    mNewLocationY = NewY-mTarget.m_y;

    // Handles left x bound of background
    if(mNewLocationX < mImage->GetWidth()/2)
    {
        mNewLocationX = mImage->GetWidth()/2;
    }
    // Handles upper y bound of background
    if(mNewLocationY < mImage->GetHeight()/6)
    {
        mNewLocationY = mImage->GetHeight()/6;
    }
    // Handles lower y bound of background
    if(mNewLocationY > (mGame->GetTileSize()*mGame->GetHeight() - (mImage->GetHeight()/2)))
    {
        mNewLocationY = ((mGame->GetTileSize()*mGame->GetHeight()) - (mImage->GetHeight()/2));
    }
}





