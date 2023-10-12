/**
 * @file VisitorItem.h
 * @author Sania Sinha
 *
 * Visitor base class
 */

#ifndef PROJECT1_335_SUDOKULIB_VISITORITEM_H
#define PROJECT1_335_SUDOKULIB_VISITORITEM_H

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

};

#endif //PROJECT1_335_SUDOKULIB_VISITORITEM_H
