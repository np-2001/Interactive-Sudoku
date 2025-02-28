/**
 * @file Given.h
 * @author Sania Sinha
 *
 * Digits that are given on the playing area
 * and cannot be eaten
 */

#ifndef PROJECT1_335_SUDOKULIB_GIVEN_H
#define PROJECT1_335_SUDOKULIB_GIVEN_H

#include "Item.h"
#include "Digit.h"

/**
 * Digits that are given on the playing area
 * and cannot be eaten
 */
class Given: public Digit
{
private:

public:
    Given(Game *game, std::shared_ptr<wxImage> image, int value);
    ///  Default constructor (disabled)
    Given() = delete;

    ///  Copy constructor (disabled)
    Given(const Given &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;
    void Regurgitate() override;

};

#endif //PROJECT1_335_SUDOKULIB_GIVEN_H
