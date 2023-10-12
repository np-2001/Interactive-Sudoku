/**
 * @file Item.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Set the image file to draw
 * @param file The image file
 */
void Item::SetImage(const std::wstring &file)
{
    // If file is not empty
    if (!file.empty())
    {
        std::wstring filename;
//        std::wstring filename = mGame->GetImagesDirectory() + L"/" + file;
        mItemImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
        mItemBitmap = std::make_unique<wxBitmap>(*mItemImage);
    }
    else
    {
        mItemImage.release();
        // How to delete bitmap
    }

    mFile = file;
}

/**
 * Draw the item
 * @param dc Device context to draw on
 */
void Item::Draw(wxGraphicsContext *graphics)
{
    // Load in BitMap only once
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    if (mItemImage != nullptr)
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();

        // Make these getters in Game, Level class
//        tileWidth = mGame->GetTileWidth();
//        tileHeight = mGame->GetTileHeight();

//        graphics->DrawBitmap(mItemBitmap, mCol*tileHeight, (mRow-1)*tileHeight-height, wid, hit);
    }
}

/**
 * Return true if clicked on Item
 * @param x Mouse X virtual pixel location
 * @param y Mouse Y virtual pixel location
 * @return True if mouse click location is within Item
 */
bool Item::HitTest(double x, double y)
{
    // Implement here: @Nitin
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