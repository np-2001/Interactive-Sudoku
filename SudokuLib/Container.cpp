/**
 * @file Container.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Container.h"
#include "Game.h"
#include "Digit.h"

/**
 * Constructor
 * @param game Game object associated with this item
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
 * @param item background item
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

    graphics->DrawBitmap(mFrontBitmap, ((GetCol()*tileHeight)),
                         (((GetRow()+1)*tileHeight) - hit), wid, hit);

}

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
