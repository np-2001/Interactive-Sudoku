/**
 * @file Given.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Given.h"

/**
 * Constructor
 * @param game Game object associated with this item
 * @param image Image of given
 * @param value Value of given
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
 */
void Given::Eat()
{

}
/**
 * Givens do not Regurgitate
 */
void Given::Regurgitate()
{

}
