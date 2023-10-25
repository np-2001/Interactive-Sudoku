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
    Background(Game *game, std::shared_ptr<wxImage> image);
    ///  Default constructor (disabled)
    Background() = delete;

    ///  Copy constructor (disabled)
    Background(const Background &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;
    void Regurgitate() override;

};

#endif //PROJECT1_335_SUDOKULIB_BACKGROUND_H
