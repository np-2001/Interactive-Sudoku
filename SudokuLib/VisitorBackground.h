/**
 * @file VisitorBackground.h
 * @author Sania Sinha, Samantha Wycoff
 *
 * Checks if visited item is the background
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORBACKGROUND_H
#define PROJECT1_335_SUDOKULIB_VISITORBACKGROUND_H

#include "VisitorItem.h"

/**
 * Class detailing visitor that
 * Checks if visited item is Sparty
 */
class VisitorBackground: public VisitorItem
{
private:
    /// Flag checking if item is Sparty
    bool mIsBackground = false;

public:
    /**
     * Getter for mIsSparty
     * @return returns true if item is Sparty
     */
    bool IsBackground() const { return mIsBackground; }

    /**
     * Checks if we are visiting Sparty
     * @param background item we are visiting
     */
    void VisitBackground(Background *background) override
    {
        mIsBackground = true;
    }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORBACKGROUND_H
