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

public:
    Container(Game *game);
    ///  Default constructor (disabled)
    Container() = delete;

    ///  Copy constructor (disabled)
    Container(const Container &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;

};

#endif //PROJECT1_335_SUDOKULIB_CONTAINER_H
