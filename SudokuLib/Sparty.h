/**
 * @file Sparty.h
 * @author Sania Sinha
 *
 * Sparty
 */

#ifndef PROJECT1_335_SUDOKULIB_SPARTY_H
#define PROJECT1_335_SUDOKULIB_SPARTY_H

#include "Item.h"

/**
 * Class detailing Sparty
 */
class Sparty: public Item
{
private:
    /// Points to X location moving to. If not moving then equal to mCurrLocation
    double mNewLocationX = Item::GetX();


    /// Points to Y location moving to. If not moving then equal to mCurrLocation
    double mNewLocationY = Item::GetY();



    /// Dictates which image (image 1 or 2) is drawn in the front
    int mFront;

    /// Pivot angle of the head
    double mHeadAngle;

    /// Pivot x of head
    double mHeadPivotX;

    /// Pivot y of head
    double mHeadPivotY;

    /// Pivot angle of the chin
    double mMouthAngle;

    /// Pivot x of mouth
    double mMouthPivotX;

    /// Pivot y of mouth
    double mMouthPivotY;

    /// Target location offset as a vector(x,y)
    wxPoint2DDouble mTargetOffset;

    //std::shared_ptr<SpartyChin> mChin;

    ///Chin Bitmap
    wxGraphicsBitmap mChinBitmap;


public:
    Sparty(Game *game, std::shared_ptr<wxImage> image);

    // This should be the proper constructor
    Sparty(Game *game, std::shared_ptr<wxImage> image1, std::shared_ptr<wxImage> image2,
           int front, double headAngle, double headX, double headY, double mouthAngle,
           double mouthX, double mouthY, double targetX, double targetY);

    ///  Default constructor (disabled)
    Sparty() = delete;

    ///  Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;
    void Update(double elapsed) override;

    /// Setter for NewX and NewY
    void SetNewCoordinates(int NewX, int NewY) {
        mNewLocationX = NewX;
        mNewLocationY = NewY;
    }

    /// Sparty's chin
    std::shared_ptr<wxImage> mImage2;

    ///Getter for sparty chin object
    ///std::shared_ptr<SpartyChin> GetChin() { return mChin;}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void ChinDraw(std::shared_ptr<wxGraphicsContext> graphics);
    //void HeadDraw(std::shared_ptr<wxGraphicsContext> graphics);

    bool rotate = false;
};

#endif //PROJECT1_335_SUDOKULIB_SPARTY_H
