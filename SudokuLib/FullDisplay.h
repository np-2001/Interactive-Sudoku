/**
 * @file FullDisplay.h
 * @author Samantha Wycoff
 *
 * Class that describes the pop up for when Sparty is full.
 */

#ifndef PROJECT1_335_SUDOKULIB_FULLDISPLAY_H
#define PROJECT1_335_SUDOKULIB_FULLDISPLAY_H

#include "Item.h"

/**
 * Class that describes the pop up for when Sparty is full.
 */
class FullDisplay
{
private:
    double mTime = 0;
    //wxString mWord;

//    /// pointer to the game being played.
//    std::shared_ptr<Game> mGame;

public:
    FullDisplay(wxString word);
    FullDisplay();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth);
    void Update(double time);

};

#endif //PROJECT1_335_SUDOKULIB_FULLDISPLAY_H
