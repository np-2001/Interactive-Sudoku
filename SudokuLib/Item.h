/**
 * @file Item.h
 * @author Sania Sinha, Finn Clark
 *
 * Class handling all items in our game
 */

#ifndef PROJECT1_335__ITEM_H
#define PROJECT1_335__ITEM_H

#include <string>
#include <memory>
#include <wx/xml/xml.h>
#include "VisitorItem.h"

class Game;

/**
 * Class handling all items in our game
 */
class Item
{
private:
    /// Game this item is contained in
    Game *mGame;

    /// Row of item
    double mRow = 0;
    /// Col of item
    double mCol = 0;

    /// The image for this item
    std::shared_ptr<wxImage> mItemImage = nullptr;

    /// The bitmap for this item
//    std::unique_ptr<wxGraphicsBitmap> mItemBitmap = nullptr;
    wxGraphicsBitmap mItemBitmap;

    /// The file for this item
    std::wstring mFile;

protected:
    Item(Game *game, std::shared_ptr<wxImage> image);

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
    double GetRow() const { return mRow; }

    /**
     * The Column of the item
     * @return Y location in pixels
     */
    double GetCol() const { return mCol; }

    double GetX() const;
    double GetY() const;

    void SetPixelLocation(double x, double y);

    /**
     * Set the item row and column
     * @param row row location
     * @param col col location
     */
    void SetLocation(double row, double col) { mRow = row; mCol = col; }

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

    /**
     * Function to eat or be eaten
     * this: object eating
     * @param item item to be eaten
     */
    virtual void Eat() = 0;

    /**
     * Regurgitate items onto board
     */
    virtual void Regurgitate() = 0;

    virtual ~Item();
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    virtual bool EatTest(double x, double y);
    bool HitTest(int x, int y);
    virtual void XmlLoad(wxXmlNode *node);

    Game * GetGame() { return mGame; }
    std::shared_ptr<wxImage> GetItemImage() {return mItemImage;}
    wxGraphicsBitmap GetItemBitmap() {return mItemBitmap;}

    /// Setter for newBitmap
    void SetNewBitmap(wxGraphicsBitmap newBitmap) {
        mItemBitmap = newBitmap;
    }

    /// Getter for mItem Image
    std::shared_ptr<wxImage> GetImage() {
        return mItemImage;
    }

};

#endif //PROJECT1_335__ITEM_H
