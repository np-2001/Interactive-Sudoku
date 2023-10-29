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
    /// Digits that are in the container
    std::vector<std::shared_ptr<Digit>> mContainerItems;

    /// Container image
    std::shared_ptr<wxImage> mContainerImage;
    /// Container front image
    std::shared_ptr<wxImage> mFrontImage;

    /// Container bitmap
    wxGraphicsBitmap mContainerBitmap;
    /// Container front image bitmap
    wxGraphicsBitmap mFrontBitmap;

    /// Is container destroyed
    bool mIsDestroyed = false;


public:
    Container(Game *game, std::shared_ptr<wxImage> image);

    Container(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxImage> front);

    ///  Default constructor (disabled)
    Container() = delete;

    ///  Copy constructor (disabled)
    Container(const Container &) = delete;

    void Accept(VisitorItem* visitor) override;
    void Eat() override;
    void Regurgitate() override;
    void AddContainerChildren(wxXmlNode *node);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Adds digit "item" to the container
     * @param item Digit to be added
     */
    void Add(std::shared_ptr<Digit> item) {mContainerItems.push_back(item); };
    void DestroyContainer();


};

#endif //PROJECT1_335_SUDOKULIB_CONTAINER_H
