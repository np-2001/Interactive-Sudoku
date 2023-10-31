/**
 * @file Item.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game object associated with this item
 * @param image The image of the corresponding item
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

/**
 * Get X value
 * @return double X value
 */
double Item::GetX() const
{
    const int tileHeight = mGame->GetTileSize();
    const int width = mItemImage->GetWidth();
    return (mCol*tileHeight+ (width/2.0));
}

/**
 * Get Y value
 * @return double Y value
 */
double Item::GetY() const
{
    const int tileHeight = mGame->GetTileSize();
    const int height = mItemImage->GetHeight();
    return ((mRow+1)*tileHeight - (height/2.0));
}

/**
 * Setter for pixel location x and y
 * @param x location pixel x
 * @param y location pixel y
 */
void Item::SetPixelLocation(double x, double y)
{
    const int tileHeight = 48;
    const int width = mItemImage->GetWidth();
    const int height = mItemImage->GetHeight();

    mCol = (x - (width/2.0))/tileHeight;
    mRow = ((y + (height/2.0))/tileHeight) - 1;
}

/**
 * Draw the item
 * @param graphics Device context to draw on
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
        int tileHeight = mGame->GetTileSize();

        graphics->DrawBitmap(mItemBitmap, ((mCol*tileHeight)),
                             (((mRow+1)*tileHeight) - hit), wid, hit);

    }
}

/**
 * Return true if location "next to" an Item
 * @param x  X virtual pixel location
 * @param y  Y virtual pixel location
 * @return True if (x,y) location is "next to" an item (directly to the right)
 */
bool Item::EatTest(double x, double y)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    // relevant to top right image corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;


    // Test to see if x, y are next to the image
//    if (x < GetX()-50 || y < GetY()-50 || x >= GetX() + wid || testY >= GetY() + hit)
//    {
//        // We are not next to the image
//        return false;
//    }
    if (testX < -10 || testY < -25 || testX >= wid/2 + 5 || testY >= hit-25)
    {
        // We are not next to the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
//    return !mItemImage->IsTransparent((int)testX, (int)testY);
    return true;
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(int x, int y)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    return true;
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


