/**
 * @file Xray.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Xray.h"
#include <algorithm>

/**
 * Constructor
 * @param game Game object associated with this item
 * @param capacity Capacity of the xray
 */
Xray::Xray(Game *game, std::shared_ptr<wxImage> image, int capacity) : Item(game, image), mCapacity(capacity)
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
void Xray::Eat()
{

}

void Xray::Regurgitate()
{

}

/**
 * Add an item to the xray
 * @param item item to be added
 */
void Xray::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Remove an item from the xray
 * @param item to be deleted
 */
void Xray::Remove(std::shared_ptr<Item> item)
{
    mItems.erase(std::remove(mItems.begin(), mItems.end(), item), mItems.end());
}


