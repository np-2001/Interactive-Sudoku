/**
 * @file Digit.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Digit.h"
#include "Xray.h"

/**
 * Constructor
 * @param game Game object associated with this item
 * @param image Image object associated with this item
 * @param value associated with this item
 */
Digit::Digit(Game *game, std::shared_ptr<wxImage> image, int value) : Item(game, image),mValue(value)
{
}

/**
 * Accepting visitor to Digit
 * @param visitor visitor object
 */
void Digit::Accept(VisitorItem* visitor)
{
    visitor->VisitDigit(this);
}

/**
 * Digit by default gets eaten if
 * calling object is Sparty
 */
void Digit::Eat()
{

}

/**
 * Digit by default gets regurgitated.
 */
void Digit::Regurgitate()
{

}