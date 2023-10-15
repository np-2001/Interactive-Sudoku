/**
 * @file Item.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game object associated with this item
 */
Item::Item(Game *game, const std::wstring &filename): mGame(game)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
}

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Draw the item
 * @param dc Device context to draw on
 */
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    // Load in BitMap only once
    if(mItemBitmap == nullptr)
    {
        mItemBitmap = std::make_unique<wxGraphicsBitmap>(graphics->CreateBitmapFromImage(*mItemImage));
    }

    if (mItemImage != nullptr)
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();

        // Make these getters in Game, Level class
//        tileWidth = mGame->GetTileWidth();
//        tileHeight = mGame->GetTileHeight();

        // Hardcoded for now
        int tileWidth = 48;
        int tileHeight = 48;
        int height = 20;

        graphics->DrawBitmap(*mItemBitmap, mCol*tileHeight, (mRow-1)*tileHeight-height, wid, hit);

        // Uncomment the above and delete this once xml is configured
//        graphics->DrawBitmap(*mItemBitmap, 100, 100, wid, hit);
    }
}

/**
 * Return true if clicked on Item
 * @param x Mouse X virtual pixel location
 * @param y Mouse Y virtual pixel location
 * @return True if mouse click location is within Item
 */
//bool Item::HitTest(double x, double y)
//{
    // Implement here: @Nitin
//}

/**
 * Load in XML data
 * @param node The Xml node we are loading the item from
 */
void Item::XmlLoad(wxXmlNode *node)
{
    double x, y;
    node->GetAttribute(L"x", L"0").ToDouble(&x);
    node->GetAttribute(L"y", L"0").ToDouble(&y);
    mRow = x;
    mCol = y;
}