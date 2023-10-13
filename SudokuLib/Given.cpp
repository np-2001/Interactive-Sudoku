/**
 * @file Given.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Given.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Given::Given(Game *game) : Digit(game)
{

}

/**
 * Accepting visitor to Given
 * @param visitor visitor object
 */
void Given::Accept(VisitorItem* visitor)
{

}

/**
 * Givens do not get eaten
 * @param item digit to be eaten
 */
void Given::Eat(Item *item)
{

}
