/**
 * @file Sparty.h
 * @author Sania Sinha, Samantha Wycoff
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
    int mNewLocationX = Item::GetX();


    /// Points to Y location moving to. If not moving then equal to mCurrLocation
    int mNewLocationY = Item::GetY();



    /// Dictates which image (image 1 or 2) is drawn in the front
    int mFront;

    /// Pivot angle of the head
    double mHeadAngle;

    /// Pivot x of head
    double mHeadPivotX;

    /// Pivot y of head
    double mHeadPivotY;

    ///Old angle of head
    double mHeadCurrAngle = 0;

    ///New angle of head
    double mHeadNewAngle = 0;

    /// Pivot angle of the chin
    double mMouthAngle;

    /// Pivot x of mouth
    double mMouthPivotX;

    /// Pivot y of mouth
    double mMouthPivotY;

    ///Old angle of mouth
    double mMouthCurrAngle = 0;

    ///New angle of mouth
    double mMouthNewAngle = 0;

    /// Target location offset as a vector(x,y)
    wxPoint2DDouble mTarget;

    ///Chin Bitmap
    wxGraphicsBitmap mChinBitmap;

    ///Head Bitmap
    wxGraphicsBitmap mHeadBitmap;

    ///Represents moving
    bool mMoving = false;


    /// Sparty's head
    std::shared_ptr<wxImage> mImage;

    /// Sparty's chin
    std::shared_ptr<wxImage> mImage2;

    ///Sparty is throwing up
    bool mThrowUp = false;
public:


    Sparty(Game *game, std::shared_ptr<wxImage> image1, std::shared_ptr<wxImage> image2,
           int front, double headAngle, double headX, double headY, double mouthAngle,
           double mouthX, double mouthY, double targetX, double targetY);

    ///  Default constructor (disabled)
    Sparty() = delete;

    ///  Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;


    void Regurgitate() override;
    void Update(double elapsed) override;

    void SetNewCoordinates(int NewX, int NewY);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void ChinDraw(std::shared_ptr<wxGraphicsContext> graphics);
    void HeadDraw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Getter for sparty offset
     * @return mTarget the offset of sparty
     */
    wxPoint2DDouble GetOffset() { return mTarget;}

    ///Setter for new rotate angle
    void SetNewAngleMouth() {
        mMouthNewAngle = mMouthAngle;
    }

    ///Setter for new headbutt angle
    void SetNewAngleHead() {
        mHeadNewAngle = mHeadAngle;
    }

    /**
     * Getter for new X position
     * @return The new X location sparty is moving to
     */
    double GetNewX() {
        return mNewLocationX;
    }

    /**
     * Getter for new Y position
     * @return The new Y location sparty is moving to
     */
    double GetNewY() {
        return mNewLocationY;
    }

    /**
     * Getter for current mouth angle
     * @return mMouthCurrAngle the current angle of the mouth
     */
    double GetAngleMouth() {
        return mMouthCurrAngle;
    }

    /**
    * Getter for current head angle
    * @return mHeadCurrAngle the current head of the mouth
    */
    double GetAngleHead() {
        return mHeadCurrAngle;
    }

    /**
     * Setter for mMoving
     * @param moving Bool representing if sparty is moving
     */
    void SetMoving(bool moving) {
        mMoving = moving;
    }

    /**
     * Getter for moving
     * @return Bool representing if sparty is moving
     */
    bool GetMoving() {
        return mMoving;
    }

    /**
     * Getter for width of sparty
     * @return sparty width in pixels
     */
    int GetSpartyWidth() const {return mImage->GetWidth();}

    /**
     * Getter for height of sparty
     * @return sparty height in pixels
     */
    int GetSpartyHeight() const {return mImage->GetHeight();}

    /**
     * Getter for mThrowUp
     * @return bool representing if sparty is going to throw up
     */
    bool GetThrowUp () { return mThrowUp;}

    /**
     * Setter for mThrowUp
     * @param throwup Bool repsenting if sparty is going to throw up
     */
    void SetThrowUp (bool throwup) {
        mThrowUp = throwup;
    }
};

#endif //PROJECT1_335_SUDOKULIB_SPARTY_H
