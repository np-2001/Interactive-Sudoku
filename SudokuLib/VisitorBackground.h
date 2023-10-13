/**
 * @file VisitorBackground.h
 * @author Sania Sinha
 *
 * Checks if visited item is the background
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORBACKGROUND_H
#define PROJECT1_335_SUDOKULIB_VISITORBACKGROUND_H

#include "VisitorItem.h"

/**
 * Class detailing visitor that
 * Checks if visited item is the background
 */
class VisitorBackground: public VisitorItem
{
private:
    /// Flag checking if item is background
    bool mIsBackground = false;

public:
    /**
     * Getter for mIsBackground
     * @return returns true if item is Sparty
     */
    bool IsBackground() const { return mIsBackground; }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORBACKGROUND_H
