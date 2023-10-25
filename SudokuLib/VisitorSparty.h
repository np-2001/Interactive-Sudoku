/**
 * @file VisitorSparty.h
 * @author Sania Sinha
 *
 * Checks if visited item is Sparty
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORSPARTY_H
#define PROJECT1_335_SUDOKULIB_VISITORSPARTY_H

#include "VisitorItem.h"

/**
 * Class detailing visitor that
 * Checks if visited item is Sparty
 */
class VisitorSparty: public VisitorItem
{
private:
    /// Flag checking if item is Sparty
    bool mIsSparty = false;

public:
    /**
     * Getter for mIsSparty
     * @return returns true if item is Sparty
     */
    bool MatchSparty() const { return mIsSparty; }

    /**
     * Checks if we are visiting Sparty
     * @param sparty item we are visiting
     */
    void VisitSparty(Sparty *sparty) override
    {
        mIsSparty = true;
    }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORSPARTY_H
