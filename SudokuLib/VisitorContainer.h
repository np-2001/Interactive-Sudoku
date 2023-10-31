/**
 * @file VisitorContainer.h
 * @author Sania Sinha
 *
 * Checks if visited item is a container
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORCONTAINER_H
#define PROJECT1_335_SUDOKULIB_VISITORCONTAINER_H

#include "VisitorItem.h"
#include "Container.h"

/**
 * Class detailing visitor that
 * Checks if visited item is a container
 */
class VisitorContainer: public VisitorItem
{
private:
    /// Flag checking if item is a container
    bool mIsContainer = false;

    /// Pointer to container
    Container *mContainer = nullptr;
public:
    /**
     * Getter for mIsContainer
     * @return returns true if item is a container
     */
    bool MatchContainer() const { return mIsContainer; }

    /**
     * Sets flag to true since we are visiting a container
     * @param container container being visited
     */
    void VisitContainer(Container *container) override
    {
        mIsContainer = true;
        mContainer = container;
    }

    /** Calls the DestroyContainer function on this container */
    void CallDestroyContainer(){ mContainer->DestroyContainer(); }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORCONTAINER_H
