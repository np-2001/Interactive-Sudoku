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



public:
    Sparty(Game *game, std::shared_ptr<wxImage> image);
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

};

#endif //PROJECT1_335_SUDOKULIB_SPARTY_H
