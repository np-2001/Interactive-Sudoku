/**
 * @file Background.h
 * @author Sania Sinha
 *
 * Class for bcakground of each level
 */

#ifndef PROJECT1_335_SUDOKULIB_BACKGROUND_H
#define PROJECT1_335_SUDOKULIB_BACKGROUND_H

#include "Item.h"

/**
 * Class for bcakground of each level
 */
class Background: public Item
{
private:

public:
    Background(Game *game);
    ///  Default constructor (disabled)
    Background() = delete;

    ///  Copy constructor (disabled)
    Background(const Background &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;

};

#endif //PROJECT1_335_SUDOKULIB_BACKGROUND_H
