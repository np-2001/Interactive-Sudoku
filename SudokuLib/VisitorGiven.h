/**
 * @file VisitorGiven.h
 * @author Sania Sinha
 *
 * Checks if visited item is a given
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORGIVEN_H
#define PROJECT1_335_SUDOKULIB_VISITORGIVEN_H

#include "VisitorItem.h"
#include "Given.h"

class VisitorGiven: public VisitorItem
{
private:
    /// Flag checking if item is a given
    bool mIsGiven = false;

public:
    /**
     * Getter for mIsGiven
     * @return returns true if item is a given
     */
    bool MatchGiven() const { return mIsGiven; }

    /**
     * Sets flag to true since we are visiting a given
     * @param given item being visited
     */
    void VisitGiven(Given *given) override
    {
        mIsGiven = true;
    }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORGIVEN_H
