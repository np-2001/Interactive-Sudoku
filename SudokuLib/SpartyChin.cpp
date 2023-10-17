/**
 * @file SpartyChin.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "SpartyChin.h"
using namespace std;




/// Character speed in pixels per second
const double MaxSpeed = 400;

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

    if (Vector.m_x != 0 || Vector.m_y != 0) {
        Vector.Normalize();
        Item::SetPixelLocation((Vector.m_x* elapsed * MaxSpeed)+ CurrLocationX,(Vector.m_y*elapsed*MaxSpeed)+CurrLocationY);
        if (std::abs(Item::GetX()-mNewLocationX) < 20) {
            Item::SetPixelLocation(mNewLocationX,Item::GetY());
        }
        if (std::abs(Item::GetY()-mNewLocationY) < 20) {
            Item::SetPixelLocation(Item::GetX(),mNewLocationY);
        }

    }

}
