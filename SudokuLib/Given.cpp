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
Given::Given(Game *game, std::shared_ptr<wxImage> image, int value) : Digit(game, image, value)
{

}

/**
 * Accepting visitor to Given
 * @param visitor visitor object
 */
void Given::Accept(VisitorItem* visitor)
{
    // Have not added upcall
    visitor->VisitGiven(this);
}

/**
 * Givens do not get eaten
 * @param item digit to be eaten
 */
void Given::Eat()
{

}

void Given::Regurgitate()
{

}
