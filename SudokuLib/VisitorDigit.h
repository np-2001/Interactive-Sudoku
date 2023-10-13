/**
 * @file VisitorDigit.h
 * @author Sania Sinha
 *
 * Checks if visited item is a digit
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORDIGIT_H
#define PROJECT1_335_SUDOKULIB_VISITORDIGIT_H

#include "VisitorItem.h"

/**
 * Class detailing visitor that
 * Checks if visited item is a digit
 */
class VisitorDigit: public VisitorItem
{
private:
    /// Flag checking if item is a digit
    bool mIsDigit = false;

public:
    /**
     * Getter for mIsDigit
     * @return returns true if item is a digit
     */
    bool IsDigit() const { return mIsDigit; }

};

#endif //PROJECT1_335_SUDOKULIB_VISITORDIGIT_H
