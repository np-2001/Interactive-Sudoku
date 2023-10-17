/**
 * @file Item.cpp
 * @author Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game object associated with this item
 */
Item::Item(Game *game, std::shared_ptr<wxImage> image): mGame(game)
{
    mItemImage = image;
}

/**
 * Destructor
 */
Item::~Item()
{

}

double Item::GetX() const
{
    int tileHeight = 48;
    int width = mItemImage->GetWidth();
    return (mCol*tileHeight+ (width/2.0));
}

double Item::GetY() const
{
    int tileHeight = 48;
    int height = mItemImage->GetHeight();
    return ((mRow-1)*tileHeight + (height/2.0));
}

void Item::SetPixelLocation(double x, double y)
{
    int tileHeight = 48;
    int width = mItemImage->GetWidth();
    int height = mItemImage->GetHeight();

    mCol = (x - (width/2.0))/tileHeight;
    mRow = ((y - (height/2.0))/tileHeight) + 1;
}

/**
 * Draw the item
 * @param dc Device context to draw on
 */
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    // Load in BitMap only once
    if(mItemBitmap.IsNull())
    {
//        mItemBitmap = std::make_unique<wxGraphicsBitmap>(graphics->CreateBitmapFromImage(*mItemImage));
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    if (mItemImage != nullptr)
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();

        // Make these getters in Game, Level class
//        tileWidth = mGame->GetTileWidth();
//        tileHeight = mGame->GetTileHeight();

        // Hardcoded for now
        int tileHeight = 48;
        int height = 20;

        double virtualX = (mCol*tileHeight - mGame->GetOffsetX()) / mGame->GetScale();
        double virtualY = ((mRow-1)*tileHeight-height - mGame->GetOffsetY()) / mGame->GetScale();

//        graphics->DrawBitmap(mItemBitmap, mCol*tileHeight, (mRow-1)*tileHeight-height, wid, hit);
//        graphics->DrawBitmap(mItemBitmap, (mCol*tileHeight - mGame->GetOffsetX()) / mGame->GetScale(),
//                             ((mRow-1)*tileHeight-hit - mGame->GetOffsetY()) / mGame->GetScale(), wid, hit);

        graphics->DrawBitmap(mItemBitmap, ((mCol*tileHeight)),
                             (((mRow-1)*tileHeight) - hit + mGame->GetOffsetY()), wid, hit);

        // Uncomment the above and delete this once xml is configured
//        graphics->DrawBitmap(*mItemBitmap, 100, 100, wid, hit);
    }
}

/**
 * Return true if location "next to" an Item
 * @param x  X virtual pixel location
 * @param y  Y virtual pixel location
 * @return True if (x,y) location is "next to" an item (directly to the right)
 */
bool Item::HitTest(double x, double y)
{
    double wid = mItemBitmap.ConvertToImage().GetWidth();
    double hit = mItemBitmap.ConvertToImage().GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    // relevant to top right image corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;


    // Test to see if x, y are next to the image
    if (x < GetX()-50 || y < GetY() || x >= GetX() + wid || testY >= GetY() + hit)
    {
        // We are not next to the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mItemImage->IsTransparent((int)testX, (int)testY);
}

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