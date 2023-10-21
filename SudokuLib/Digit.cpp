/**
 * @file Digit.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Digit.h"

/**
 * Constructor
 * @param game Game object associated with this item
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

}

/**
 * Digit by default gets eaten if
 * calling object is Sparty
 * @param item digit to be eaten
 */
void Digit::Eat(Item *item)
{

}