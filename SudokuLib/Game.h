/**
 * @file Game.h
 * @author Nitin Polavarapu, Samantha Wycoff, Sania Sinha
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_GAME_H
#define PROJECT1_335_SUDOKULIB_GAME_H

#include "Item.h"
#include <memory>
#include "Timer.h"
class Game
{
private:
    /// scaling member variable
    double mScale;

    ///offset variable for X
    double mXOffset;

    ///offset variable for Y
    double mYOffset;

    /// List of all items in the game
    std::vector<std::shared_ptr<Item>> mItems;

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use (hardcoded for now)


public:
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    virtual void OnLeftDown(int x, int y);

    /// The display timer (scoreboard)
    Timer mTimeDisplay;

    void Update(double time);
};

#endif //PROJECT1_335_SUDOKULIB_GAME_H
