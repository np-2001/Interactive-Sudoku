/**
 * @file VisitorXray.h
 * @author Sania Sinha
 *
 * Checks if visited item is the xray
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORXRAY_H
#define PROJECT1_335_SUDOKULIB_VISITORXRAY_H

#include "VisitorItem.h"
#include "Item.h"

/**
 * Checks if visited item is the xray
 */
class VisitorXray: public VisitorItem
{
private:
    /// Flag checking if item is a xray
    bool mIsXray = false;

    /// Stores the xray visited
    Xray *mXray = nullptr;

public:
    /**
     * Getter for mIsXray
     * @return returns true if item is a xray
     */
    bool MatchXray() const { return mIsXray; }

    /**
     * Sets flag to true since we are visiting a container
     * @param given item being visited
     */
    void VisitXray(Xray *xray) override
    {
        mIsXray = true;
        mXray = xray;
    }

    void CallAdd(std::shared_ptr<Item> item);

};

#endif //PROJECT1_335_SUDOKULIB_VISITORXRAY_H
