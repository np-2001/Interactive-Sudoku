/**
 * @file Container.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Container.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Container::Container(Game *game) : Item(game)
{

}

/**
 * Accepting visitor to Container
 * @param visitor visitor object
 */
void Container::Accept(VisitorItem* visitor)
{

}

/**
 * Containers do not have Eat functionality
 * @param item background item
 */
void Container::Eat(Item *item)
{

}
