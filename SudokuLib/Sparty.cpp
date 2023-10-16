/**
 * @file Sparty.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Sparty.h"
#include <cmath>

using namespace std;


/// Character speed in pixels per second
const double MaxSpeed = 400.00;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;

const wstring SpartyHeadImageName = L"images/sparty-1.png";

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
    const wxPoint Vector(mNewLocationX-CurrLocationX,mNewLocationY-CurrLocationY);
    double Magnitude = sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));
    const wxPoint NormalVector(Vector.x/Magnitude,Vector.y/Magnitude);
    Item::SetLocation((NormalVector.x*MaxSpeed)+CurrLocationX,(NormalVector.y*MaxSpeed)+CurrLocationY);
}
