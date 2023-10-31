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
    Game *mGame;

    int mPixelWidth;
    int mPixelHeight;

public:

    FullDisplay();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Update(double time);
    FullDisplay(Game *game,int PixelWidth, int PixelHeight);
    int GetPixelHeight () {
        return mPixelHeight;
    }
};

#endif //PROJECT1_335_SUDOKULIB_FULLDISPLAY_H
