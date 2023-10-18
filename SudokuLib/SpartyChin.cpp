/**
 * @file SpartyChin.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "SpartyChin.h"
#include "Game.h"
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
SpartyChin::SpartyChin(Game *game, std::shared_ptr<wxImage> image) : Item(game, image)
{

}

/**
 * Accepting visitor to Sparty
 * @param visitor visitor object
 */
void SpartyChin::Accept(VisitorItem* visitor)
{

}

/**
 * Sparty eats and does not get eaten
 * @param item digit to be eaten
 */
void SpartyChin::Eat(Item *item)
{

}

void SpartyChin::Update(double elapsed)
{
    double CurrLocationX = Item::GetX();
    double CurrLocationY = Item::GetY();

    wxPoint2DDouble Vector(mNewLocationX-CurrLocationX,mNewLocationY-CurrLocationY);
    Game * mGame = Item::GetGame();
    if (Vector.m_x != 0 || Vector.m_y != 0)
    {
        double Length = Vector.GetVectorLength();
        Vector.Normalize();

        Vector = (Vector * MaxSpeed);

        wxPoint2DDouble NewVector(Vector.m_x / mGame->GetWidth(), Vector.m_y / mGame->GetHeight());

        if(NewVector.GetVectorLength() * elapsed < Length)
        {
            Item::SetPixelLocation(NewVector.m_x * elapsed + CurrLocationX, NewVector.m_y * elapsed + CurrLocationY);
        }
        else
        {
            Item::SetPixelLocation(mNewLocationX, mNewLocationY);
        }
    }

}
