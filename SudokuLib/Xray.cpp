/**
 * @file Xray.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Xray.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Xray::Xray(Game *game) : Container(game)
{

}

/**
 * Accepting visitor to Item
 * @param visitor visitor object
 */
void Xray::Accept(VisitorItem* visitor)
{

}

/**
 * Xrays do not have Eat functionality
 * @param item background item
 */
void Xray::Eat(Item *item)
{

}
