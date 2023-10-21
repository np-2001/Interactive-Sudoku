/**
 * @file Xray.h
 * @author Sania Sinha
 *
 * Class outlining xray that
 * Shows digits in Sparty's stomach
 */

#ifndef PROJECT1_335_SUDOKULIB_XRAY_H
#define PROJECT1_335_SUDOKULIB_XRAY_H

#include "Item.h"
#include "Container.h"

class Xray: public Item
{
private:
    /// Capacity of the xray container
    int mCapacity;
public:
    Xray(Game *game, std::shared_ptr<wxImage> image, int capacity);
    ///  Default constructor (disabled)
    Xray() = delete;

    ///  Copy constructor (disabled)
    Xray(const Xray &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;

};

#endif //PROJECT1_335_SUDOKULIB_XRAY_H
