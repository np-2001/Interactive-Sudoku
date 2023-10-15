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
Digit::Digit(Game *game, const std::wstring &filename) : Item(game, filename)
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