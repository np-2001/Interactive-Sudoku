/**
 * @file Background.cpp
 * @author Sania Sinha, Samantha Wycoff
 */

#include "pch.h"
#include "Background.h"

/**
 * Constructor
 * @param game Game object associated with this item
 * @param image Image associated with item
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
 */
void Background::Eat()
{

}

/**
 * Backgrounds do not have Regurgitate functionality
 */
void Background::Regurgitate()
{

}