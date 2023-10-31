/**
 * @file Xray.h
 * @author Sania Sinha, Samantha Wycoff
 *
 * Class outlining xray that
 * Shows digits in Sparty's stomach
 */

#ifndef PROJECT1_335_SUDOKULIB_XRAY_H
#define PROJECT1_335_SUDOKULIB_XRAY_H

#include "Item.h"
#include "Container.h"
/**
 * Class outlining xray that
 * Shows digits in Sparty's stomach
 */
class Xray: public Item
{
private:
    /// Capacity of the xray container
    int mCapacity;

    /// Items inside the xray
    std::vector<std::shared_ptr<Item>> mItems;

public:
    Xray(Game *game, std::shared_ptr<wxImage> image, int capacity);
    ///  Default constructor (disabled)
    Xray() = delete;

    ///  Copy constructor (disabled)
    Xray(const Xray &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;
    void Regurgitate() override;

    void Add(std::shared_ptr<Item> item);
    void Remove(std::shared_ptr<Item> item);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    std::shared_ptr<Item> GetMatch(int x);
    bool Full();

    /**
     * Getter for capacity for xray
     * @return int capacity for xray
     */
    int GetCapacity() const {return mCapacity;};

    /**
     * Getter for number of items in xray
     * @return integer representing number of items in xray
     */
    int GetItemCount () {
        return mItems.size();
    }

    void Empty();
    bool TimerStart();
};

#endif //PROJECT1_335_SUDOKULIB_XRAY_H
