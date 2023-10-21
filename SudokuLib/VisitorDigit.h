/**
 * @file VisitorDigit.h
 * @author Sania Sinha, Finn Clark
 *
 * Checks if visited item is a digit
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORDIGIT_H
#define PROJECT1_335_SUDOKULIB_VISITORDIGIT_H

#include "VisitorItem.h"
#include "Digit.h"

/**
 * Class detailing visitor that
 * Checks if visited item is a digit
 */
class VisitorDigit: public VisitorItem
{
private:
    /// Flag checking if item is a digit
    bool mIsDigit = false;
    int mValue = 9;

public:
    /**
     * Getter for mIsDigit
     * @return returns true if item is a digit
     */
    bool IsDigit() const { return mIsDigit; }

    /**
     * Getter for mValue
     * @returns the value of the digit
     */
     int GetValue() const { return mValue; }

     /**
      * Sets flag to true since we are visiting a digit
      * Stores the value of digit
      * @param digit item being visited
      */
     void VisitDigit(Digit *digit) override { mIsDigit = true; mValue = digit->GetValue();}

};

#endif //PROJECT1_335_SUDOKULIB_VISITORDIGIT_H
