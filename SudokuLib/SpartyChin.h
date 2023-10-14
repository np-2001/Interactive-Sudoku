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
    SpartyChin(Game *game);

    ///  Default constructor (disabled)
    SpartyChin() = delete;

    ///  Copy constructor (disabled)
    SpartyChin(const SpartyChin &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat(Item *item) override;

public:

};

#endif //PROJECT1_335_SUDOKULIB_SPARTYCHIN_H
