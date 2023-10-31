/**
 * @file Container.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Container.h"
#include "Game.h"
#include "Digit.h"
#include <random>

/**
 * Constructor
 * @param game Game object associated with this item
 * @param image Image associated with this item
 */
Container::Container(Game *game, std::shared_ptr<wxImage> image) :
    Item(game, image)
{
}

/**
 * Accepting visitor to Container
 * @param visitor visitor object
 */
void Container::Accept(VisitorItem* visitor)
{
    visitor->VisitContainer(this);
}

/**
 * Containers do not have Eat functionality
 */
void Container::Eat()
{

}


/**
 * Adds all the digit children to the container
 * @param node
 */
void Container::AddContainerChildren(wxXmlNode* node)
{
    auto game = Item::GetGame();
    std::shared_ptr<Digit> digit;
    auto declarations = game->GetLevel()->GetDeclaration();
    int value;
    double row;
    double col;

    for (; node; node = node->GetNext())
    {
        wxString id = node->GetAttribute("id");
        node->GetAttribute("col").ToDouble(&col);
        node->GetAttribute("row").ToDouble(&row);


        auto image = declarations->GetImage(id);
        declarations->GetDeclaration(id)->GetAttribute("value").ToInt(&value);


        digit = std::make_shared<Digit>(game, image, value);

        digit->SetLocation(row, col);
        mContainerItems.push_back(digit);
    }
}

/**
 * Draws the container and its object
 * @param graphics graphics context to draw on
 */
void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Draw underlying image
    mContainerBitmap = graphics->CreateBitmapFromImage(*mContainerImage);

    int wid = mContainerImage->GetWidth();
    int hit = mContainerImage->GetHeight();
    int tileHeight = GetGame()->GetTileSize();

    graphics->DrawBitmap(mContainerBitmap, ((GetCol()*tileHeight)),
                         (((GetRow()+1)*tileHeight) - hit), wid, hit);

    // Draw Digits in container
    for (auto &elm : mContainerItems)
    {
        elm->Draw(graphics);
    }

    // Draw Front Image
    mFrontBitmap = graphics->CreateBitmapFromImage(*mFrontImage);
    wid = mContainerImage->GetWidth();
    hit = mContainerImage->GetHeight();
    tileHeight = GetGame()->GetTileSize();

    if (!mIsDestroyed)
        graphics->DrawBitmap(mFrontBitmap, ((GetCol()*tileHeight)),
                            (((GetRow()+1)*tileHeight) - hit), wid, hit);

}

/**
 * Container does not have regurgitate functionality
 */
void Container::Regurgitate()
{

}

/**
 * Constructor for Container
 * @param game Game this container belongs to
 * @param image Underlying image
 * @param front Cover image
 */
Container::Container(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxImage> front) :
 Item(game, image), mContainerImage(image), mFrontImage(front)
{
}

/**
 * Destroy the container.
 */
void Container::DestroyContainer()
{
    if (!mIsDestroyed)
    {
        std::vector<std::shared_ptr<Digit>> toBeDeleted;
        mIsDestroyed = true;

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distX(-2, 2);
        std::uniform_int_distribution<int> distY(3, 5);


        // Update the new location of the tiles to be destroyed
        for (auto digit : mContainerItems)
        {
            int offsetX = distX(generator);
            int offsetY = distY(generator);
            digit->SetLocation(digit->GetRow() - offsetY, digit->GetCol() + offsetX);

            // Add to the ToBeDeleted Array
            toBeDeleted.push_back(digit);
        }

        // Deletes the items from mContainerItems and then adds it to mItems
        for (auto digit : toBeDeleted)
        {
            GetGame()->MakeSpartyLast(digit);
            //std::remove(mContainerItems.begin(), mContainerItems.end(),digit);
        }
        mContainerItems.clear();


    }



}