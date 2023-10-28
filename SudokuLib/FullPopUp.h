/**
 * @file FullPopUp.h
 * @author Samantha Wycoff
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_FULLPOPUP_H
#define PROJECT1_335_SUDOKULIB_FULLPOPUP_H

#include "Item.h"

class FullPopUp
{
private:
    double mTime = 0;
    wxString mWord;
public:
    FullPopUp(wxString word);
    FullPopUp();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth);
    void Update(double time);
};

#endif //PROJECT1_335_SUDOKULIB_FULLPOPUP_H
