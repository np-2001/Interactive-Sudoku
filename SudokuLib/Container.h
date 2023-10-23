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
    std::vector<std::shared_ptr<Digit>> mContainerItems;
public:
    Container(Game *game, std::shared_ptr<wxImage> image);
    ///  Default constructor (disabled)
    Container() = delete;

    ///  Copy constructor (disabled)
    Container(const Container &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;

    void AddContainerChildren(wxXmlNode *node);

    /**
     * Adds digit "item" to the container
     * @param item Digit to be added
     */
    void Add(std::shared_ptr<Digit> item) {mContainerItems.push_back(item); };


};

#endif //PROJECT1_335_SUDOKULIB_CONTAINER_H
