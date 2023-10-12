/**
 * @file Item.h
 * @author Sania Sinha
 *
 * Class handling all items in our game
 */

#ifndef PROJECT1_335__ITEM_H
#define PROJECT1_335__ITEM_H

#include <string>
#include <memory>
#include <wx/graphics.h>
#include <wx/xml/xml.h>
#include "VisitorItem.h"

class Game;

/**
 * Class handling all items in our game
 */
class Item
{
private:
//    /// Game this item is contained in
//    Game mGame;

    /// Row of item
    double mRow = 0;
    /// Col of item
    double mCol = 0;

    /// The image for this item
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap for this item
    wxGraphicsBitmap mItemBitmap;

    /// The file for this item
    std::wstring mFile;

protected:
    // Implement when game class is made
//    /// Constructor
//    Item(Game *game);

public:
    ///  Default constructor (disabled)
    Item() = delete;

    ///  Copy constructor (disabled)
    Item(const Item &) = delete;

    /**
     * Get the file name for this item image
     * @return Filename or blank if none
     *
     */
    std::wstring GetFile() { return mFile; }

    /**
      * The Row of the item
      * @return X location in pixels
      */
    double GetX() const { return mRow; }

    /**
     * The Column of the item
     * @return Y location in pixels
     */
    double GetY() const { return mCol; }

    /**
     * Set the item row and column
     * @param x row location
     * @param y col location
     */
    void SetLocation(double x, double y) { mRow = x; mCol = y; }

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed){}

    /**
      * Accept a visitor
      * @param visitor The visitor we accept
      */
    virtual void Accept(VisitorItem* visitor) = 0;

    virtual ~Item();
    virtual void SetImage(const std::wstring &file);
    virtual void Draw(wxGraphicsContext *graphics);
    virtual bool HitTest(double x, double y);
    virtual void XmlLoad(wxXmlNode *node);

};

#endif //PROJECT1_335__ITEM_H
