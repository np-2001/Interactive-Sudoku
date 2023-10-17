/**
 * @file SpartyChin.h
 * @author Nitin Polavarapu
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_SPARTYCHIN_H
#define PROJECT1_335_SUDOKULIB_SPARTYCHIN_H

#include "Item.h"


class SpartyChin : public Item
{
private:
    /// Points to X location moving to. If not moving then equal to mCurrLocation
    double mNewLocationX = Item::GetX();


    /// Points to Y location moving to. If not moving then equal to mCurrLocation
    double mNewLocationY = Item::GetY();

public:
    SpartyChin(Game *game, std::shared_ptr<wxImage> image);

    ///  Default constructor (disabled)
    SpartyChin() = delete;

    ///  Copy constructor (disabled)
    SpartyChin(const SpartyChin &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;

    void Update(double elapsed) override;

    /// Setter for NewX and NewY
    void SetNewCoordinates(int NewX, int NewY) {
        mNewLocationX = NewX;
        mNewLocationY = NewY;
    }

};

#endif //PROJECT1_335_SUDOKULIB_SPARTYCHIN_H
