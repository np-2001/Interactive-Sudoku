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

public:
    Digit(Game *game);
    ///  Default constructor (disabled)
    Digit() = delete;

    ///  Copy constructor (disabled)
    Digit(const Digit &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;

};

#endif //PROJECT1_335_SUDOKULIB_DIGIT_H
