/**
 * @file Sparty.cpp
 * @author Sania Sinha,Nitin Polavarapu
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

}

/**
 * Sparty eats and does not get eaten
 * @param item digit to be eaten
 */
void Sparty::Eat(Item *item)
{

}

void Sparty::Update(double elapsed)
{
    double CurrLocationX = Item::GetX();
    double CurrLocationY = Item::GetY();

    wxPoint2DDouble Vector(mNewLocationX-CurrLocationX,mNewLocationY-CurrLocationY);
    Game * mGame = Item::GetGame();
    if (Vector.m_x != 0 || Vector.m_y != 0) {
        double Length = Vector.GetVectorLength();
        Vector.Normalize();

        Vector = (Vector*MaxSpeed);

        wxPoint2DDouble NewVector(Vector.m_x / mGame->GetWidth(),Vector.m_y/mGame->GetHeight());

        if (NewVector.GetVectorLength() * elapsed < Length) {
            Item::SetPixelLocation(NewVector.m_x*elapsed+CurrLocationX,NewVector.m_y*elapsed+CurrLocationY);
        } else {
            Item::SetPixelLocation(mNewLocationX,mNewLocationY);
        }

//        Item::SetPixelLocation((Vector.m_x* elapsed * MaxSpeed)+ CurrLocationX,(Vector.m_y*elapsed*MaxSpeed)+CurrLocationY);
//        if (std::abs(Item::GetX()-mNewLocationX) < 20) {
//            Item::SetPixelLocation(mNewLocationX,Item::GetY());
//        }
//
//        if (std::abs(Item::GetY()-mNewLocationY) < 20) {
//            Item::SetPixelLocation(Item::GetX(),mNewLocationY);
//        }

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
    mTargetOffset = wxPoint2DDouble(targetX, targetY);

    //mChin = std::make_shared<SpartyChin>(game,mImage2,mFront,mHeadAngle,mHeadPivotX,mHeadPivotY,mMouthAngle,mMouthPivotX,mMouthPivotY,targetX,targetY);
}

void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    if (mFront == 2) {
        Sparty::HeadDraw(graphics);
        //Item::Draw(graphics);
        Sparty::ChinDraw(graphics);

    } else {
        Sparty::ChinDraw(graphics);
        //Item::Draw(graphics);
        Sparty::HeadDraw(graphics);
    }
}


void Sparty::ChinDraw(std::shared_ptr<wxGraphicsContext> graphics) {
    // Load in BitMap only once
    int wid = mImage2->GetWidth();
    int hit = mImage2->GetHeight();
    // Make these getters in Game, Level class
    int tileHeight = Item::GetGame()->GetTileSize();
    auto x = ((Item::GetCol()*tileHeight));
    auto y = (((Item::GetRow()+1)*tileHeight) - hit);

    if(mChinBitmap.IsNull())
    {
        mChinBitmap = graphics->CreateBitmapFromImage(*mImage2);
    }

    if (mImage2 != nullptr && rotate == false)
    {

        auto x = ((Item::GetCol()*tileHeight));
        auto y = (((Item::GetRow()+1)*tileHeight) - hit);


        graphics->DrawBitmap(mChinBitmap, ((Item::GetCol()*tileHeight)),
                             (((Item::GetRow()+1)*tileHeight) - hit), wid, hit);

    } else {

        graphics->PushState();

        x = ((Item::GetCol()*tileHeight));
        y = (((Item::GetRow()+1)*tileHeight) - hit);

        graphics->Translate(x,y);

        graphics->Translate(mHeadPivotX, mHeadPivotY);

        graphics->Rotate(0);
        graphics->Translate(-mHeadPivotX, -mHeadPivotY);


        graphics->Translate(mMouthPivotX, mMouthPivotY);
        graphics->Rotate(mMouthAngle);
        graphics->Translate(-mMouthPivotX, -mMouthPivotY);


        wid = mImage2->GetWidth();
        hit = mImage2->GetHeight();

        graphics->DrawBitmap(mChinBitmap, 0,0, wid, hit);

        graphics->PopState();

        //rotate = false;

    }
}

void Sparty::HeadDraw(std::shared_ptr<wxGraphicsContext> graphics) {
    // Load in BitMap only once
    int wid = mImage->GetWidth();
    int hit = mImage->GetHeight();
    // Make these getters in Game, Level class
    int tileHeight = Item::GetGame()->GetTileSize();
    auto x = ((Item::GetCol()*tileHeight));
    auto y = (((Item::GetRow()+1)*tileHeight) - hit);

    if(mHeadBitmap.IsNull())
    {
        mHeadBitmap = graphics->CreateBitmapFromImage(*mImage);
    }

    if (mImage != nullptr && headButt == false)
    {

        auto x = ((Item::GetCol()*tileHeight));
        auto y = (((Item::GetRow()+1)*tileHeight) - hit);


        graphics->DrawBitmap(mHeadBitmap, ((Item::GetCol()*tileHeight)),
                             (((Item::GetRow()+1)*tileHeight) - hit), wid, hit);

    } else {

        graphics->PushState();

        x = ((Item::GetCol()*tileHeight));
        y = (((Item::GetRow()+1)*tileHeight) - hit);

        graphics->Translate(x,y);

        graphics->Translate(mMouthPivotX, mMouthPivotY);
        graphics->Rotate(0);
        graphics->Translate(-mMouthPivotX, -mMouthPivotY);

        graphics->Translate(mHeadPivotX, mHeadPivotY);
        graphics->Rotate(mHeadAngle);
        graphics->Translate(-mHeadPivotX, -mHeadPivotY);

        wid = mImage->GetWidth();
        hit = mImage->GetHeight();

        graphics->DrawBitmap(mHeadBitmap, 0,0, wid, hit);

        graphics->PopState();
    }
}


