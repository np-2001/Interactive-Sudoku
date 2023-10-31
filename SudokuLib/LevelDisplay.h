/**
 * @file LevelDisplay.h
 * @author Nitin Polavarapu
 *
 * Class describing the display of the level pop-ups
 */

#ifndef PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H
#define PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H

#include "Item.h"
/**
 * Class describing the display of the level pop-ups
 */
class LevelDisplay
{
private:
    double mTime = 0;
    wxString mWord;
public:
    LevelDisplay(wxString word);
    LevelDisplay();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth);
    void Update(double time);
};

#endif //PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H
