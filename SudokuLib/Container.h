/**
 * @file Container.h
 * @author Sania Sinha
 *
 * Class outlining functinality of
 * containers like the pumpkins etc
 */

#ifndef PROJECT1_335_SUDOKULIB_CONTAINER_H
#define PROJECT1_335_SUDOKULIB_CONTAINER_H

#include "Item.h"

/**
 * Class outlining functinality of
 * containers like the pumpkins etc
 */
class Container: public Item
{
private:
    std::shared_ptr<wxImage> mFront_Image;

public:
    Container(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxImage> front);
    ///  Default constructor (disabled)
    Container() = delete;

    ///  Copy constructor (disabled)
    Container(const Container &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;

};

#endif //PROJECT1_335_SUDOKULIB_CONTAINER_H
