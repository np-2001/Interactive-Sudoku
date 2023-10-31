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

    ///Time that has elapsed since pop up has appeared
    double mTime = 0;

    ///Word of corresponding level for pop up
    wxString mWord;

    ///Integer corresponding to level
    int mLevel;
public:
    /**
     * Constructor
     * @param word level to be displayed on pop up
     * @param level level referenced
     */
    LevelDisplay(wxString word,int level);
    LevelDisplay();

    /**
     * Draws popup of levelDisplay
     * @param graphics Graphics device to draw on
     * @param pixelHeight Height of the window
     * @param pixelWidth Width of the window
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth);
    /**
     * Updates location
     * @param time Elapsed time
     */
    void Update(double time);
};

#endif //PROJECT1_335_SUDOKULIB_LEVELDISPLAY_H
