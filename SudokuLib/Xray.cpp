/**
 * @file Xray.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Xray.h"
#include "Game.h"
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
    visitor->VisitXray(this);
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
void Xray::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);

    int count = 0;
    int change = 1;

    // Draw Digits in Xray
    for (auto &elm : mItems)
    {
        auto itemImage = elm->GetImage();
        auto itemBitmap = elm->GetItemBitmap();

        if (itemImage != nullptr)
        {
            int wid = itemImage->GetWidth();
            int hit = itemImage->GetHeight();

            // Make these getters in Game, Level class
            int tileHeight = this->GetGame()->GetTileSize();

            graphics->DrawBitmap(itemBitmap, ((this->GetCol()*tileHeight) + count),
                                 (((this->GetRow()+1)*tileHeight) - hit*2) - (count/3)*change, wid/2, hit/2);

        }

        count += 20;
        change *= -1;

    }

}


