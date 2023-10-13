/**
 * @file Sparty.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Sparty.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Sparty::Sparty(Game *game) : Item(game)
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
