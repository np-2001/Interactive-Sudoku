/**
 * @file Background.cpp
 * @author Sania Sinha, Samantha Wycoff
 */

#include "pch.h"
#include "Background.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Background::Background(Game *game, std::shared_ptr<wxImage> image) : Item(game, image)
{

}

/**
 * Accepting visitor to Background
 * @param visitor visitor object
 */
void Background::Accept(VisitorItem* visitor)
{
    visitor->VisitBackground(this);
}

/**
 * Backgrounds do not have Eat functionality
 * @param item background item
 */
void Background::Eat()
{

}

void Background::Regurgitate()
{

}