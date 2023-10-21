/**
 * @file Digit.h
 * @author Sania Sinha
 *
 * Digits in the playing area
 * including givens
 */

#ifndef PROJECT1_335_SUDOKULIB_DIGIT_H
#define PROJECT1_335_SUDOKULIB_DIGIT_H

#include "Item.h"

/**
 * Digits in the playing area
 * including givens
 */
class Digit: public Item
{
private:
    int mValue;

public:
    Digit(Game *game, std::shared_ptr<wxImage> image, int value);

    ///  Default constructor (disabled)
    Digit() = delete;

    ///  Copy constructor (disabled)
    Digit(const Digit &) = delete;

    /**
     * Getter for value of digit
     * @return value of digit
     */
    int GetValue() const { return mValue;}

    void Accept(VisitorItem* visitor) override;
    void Eat() override;

};

#endif //PROJECT1_335_SUDOKULIB_DIGIT_H
