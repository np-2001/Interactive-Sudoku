/**
 * @file VisitorItem.h
 * @author Sania Sinha
 *
 * Visitor base class
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORITEM_H
#define PROJECT1_335_SUDOKULIB_VISITORITEM_H

// Forward references to the different item types
class Digit;
class Container;
class Given;
class Sparty;

/**
 * Visitor base class
 */
class VisitorItem
{
protected:
    /**
     * Constructor for abstract class
     */
    VisitorItem() {}

public:
    /// Destructor
    virtual ~VisitorItem(){}

    /**
     * Visit a digit
     * @param digit item we are visiting
     */
    virtual void VisitDigit(Digit *digit) {}

    /**
     * Visit a given
     * @param given item we are visiting
     */
    virtual void VisitGiven(Given *given) {}

    /**
     * Visit a container
     * @param container item we are visiting
     */
    virtual void VisitContainer(Container *container) {}

    /**
     * Visit Sparty
     * @param sparty item we are visiting
     */
    virtual void VisitSparty(Sparty *sparty) {}

};

#endif //PROJECT1_335_SUDOKULIB_VISITORITEM_H
