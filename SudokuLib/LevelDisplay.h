/**
 * @file LevelDisplay.h
 * @author Nitin Polavarapu
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H
#define PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H

#include "Item.h"

class LevelDisplay
{
private:
    double mTime = 0;
    wxString mWord;
public:
    LevelDisplay(wxString word);
    LevelDisplay();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Update(double time);
};

#endif //PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H
