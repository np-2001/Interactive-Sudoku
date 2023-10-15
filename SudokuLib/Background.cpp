/**
 * @file Background.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Background.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Background::Background(Game *game, const std::wstring &filename) : Item(game, filename)
{

}

/**
 * Accepting visitor to Background
 * @param visitor visitor object
 */
void Background::Accept(VisitorItem* visitor)
{

}

/**
 * Backgrounds do not have Eat functionality
 * @param item background item
 */
void Background::Eat(Item *item)
{

}