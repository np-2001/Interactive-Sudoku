/**
 * @file Xray.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Xray.h"
#include "Game.h"
#include "VisitorDigit.h"
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

std::shared_ptr<Item> Xray::GetMatch(int x)
{
    for(auto item: mItems)
    {
        VisitorDigit visitor;
        item->Accept(&visitor);

        if(visitor.GetValue() == x)
        {
            return item;
        }
    }

    return nullptr;
}

void Xray::Empty() {
    std::vector<std::shared_ptr<Item>> toBeEmptied;
    for (auto digit : mItems)
    {

        digit->SetPixelLocation(digit->GetEatenLocationX(), digit->GetEatenLocationY());

        // Add to the ToBeDeleted Array
        toBeEmptied.push_back(digit);


    }

    for (auto digit : toBeEmptied)
    {
        GetGame()->MakeSpartyLast(digit);
        //std::remove(mContainerItems.begin(), mContainerItems.end(),digit);
    }
    mItems.clear();

}


bool Xray::TimerStart() {
    return (GetItemCount() > 0) && (GetGame()->GetEatTime() == 0);
}

bool Xray::Full(){
    if (!mItems.empty() && mItems.size() == mCapacity)
    {
        return true;
    }
    return false;
}
