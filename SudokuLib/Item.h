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
    wxGraphicsBitmap mItemBitmap;

    /// The file for this item
    std::wstring mFile;

    /// X location item is eaten at
    double mEatenLocationX;

    /// Y location item is eaten at
    double mEatenLocationY;

protected:
    /// Constructor
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
     * Virtual Function to eat or be eaten
     */
    virtual void Eat() = 0;

    /**
     * Virtual Function for regurgitate
     */
    virtual void Regurgitate() = 0;

    virtual ~Item();
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    virtual bool EatTest(double x, double y);
    bool HitTest(int x, int y);
    virtual void XmlLoad(wxXmlNode *node);

    /**
     * Getter for game object.
     * @return game object
     */
    Game * GetGame() { return mGame; }

    /**
     * Getter for Item Image
     * @return Item Image
     */
    std::shared_ptr<wxImage> GetItemImage() {return mItemImage;}

    /**
     * Getter for item bitmap
     * @return Item Bitmap
     */
    wxGraphicsBitmap GetItemBitmap() {return mItemBitmap;}

    /**
     * Setter for the new bitmap
     * @param newBitmap
     */
    void SetNewBitmap(wxGraphicsBitmap newBitmap) {
        mItemBitmap = newBitmap;
    }

    /**
     * Getter for images of items
     * @return item image
     */
    std::shared_ptr<wxImage> GetImage() {
        return mItemImage;
    }

    /**
     * Setter for eaten location
     * @param X location X that is eaten
     * @param Y location Y that is eaten
     */
    void SetEatenLocation(double X, double Y) {
        mEatenLocationX = X;
        mEatenLocationY = Y;
    }

    /**
     * Getter for eaten location X
     * @return eaten location X
     */
    double GetEatenLocationX() {
        return mEatenLocationX;
    };

    /**
     * Getter for eaten location Y
     * @return eaten location Y
     */
    double GetEatenLocationY() {
        return mEatenLocationY;
    };

};

#endif //PROJECT1_335__ITEM_H
