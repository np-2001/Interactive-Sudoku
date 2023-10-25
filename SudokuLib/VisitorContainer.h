/**
 * @file VisitorContainer.h
 * @author Sania Sinha
 *
 * Checks if visited item is a container
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORCONTAINER_H
#define PROJECT1_335_SUDOKULIB_VISITORCONTAINER_H

#include "VisitorItem.h"

/**
 * Class detailing visitor that
 * Checks if visited item is a container
 */
class VisitorContainer: public VisitorItem
{
private:
    /// Flag checking if item is a container
    bool mIsContainer = false;

public:
    /**
     * Getter for mIsContainer
     * @return returns true if item is a container
     */
    bool MatchContainer() const { return mIsContainer; }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORCONTAINER_H
