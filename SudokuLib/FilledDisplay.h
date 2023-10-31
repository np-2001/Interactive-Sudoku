/**
 * @file FilledDisplay.h
 * @author Samantha Wycoff
 *
 * Class that describes the pop up for when a tile space is already occupied.
 */

#ifndef PROJECT1_335_SUDOKULIB_FILLEDDISPLAY_H
#define PROJECT1_335_SUDOKULIB_FILLEDDISPLAY_H

#include "Item.h"

/**
 * Class that describes the pop up for when a tile space is already occupied.
 */
class FilledDisplay
{
private:
    /// pointer to the game being played.
    Game *mGame;

    /// width used for pop-up display
    int mPixelWidth;

    /// height used for pop-up display
    int mPixelHeight;

public:
    ///Constructor
    FilledDisplay();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Update(double time);
    FilledDisplay(Game *game,int PixelWidth, int PixelHeight);

    /**
     * Getter for pixel height
     * @return int pixel height
     */
    int GetPixelHeight () {
        return mPixelHeight;
    }
};

#endif //PROJECT1_335_SUDOKULIB_FILLEDDISPLAY_H
