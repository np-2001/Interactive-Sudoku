/**
 * @file VisitorItem.h
 * @author Sania Sinha, Samantha Wycoff
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
class Background;
class Xray;

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
     * Visit xray
     * @param xray item we are visiting
     */
    virtual void VisitXray(Xray *xray) {}

    /**
     * Visit Sparty
     * @param sparty item we are visiting
     */
    virtual void VisitSparty(Sparty *sparty) {}

    /**
    * Visit Background
    * @param background item we are visiting
    */
    virtual void VisitBackground(Background *background) {}

};

#endif //PROJECT1_335_SUDOKULIB_VISITORITEM_H
