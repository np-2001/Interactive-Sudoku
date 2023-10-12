/**
 * @file Game.h
 * @author Nitin Polavarapu, Samantha Wycoff
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_GAME_H
#define PROJECT1_335_SUDOKULIB_GAME_H

#include "Item.h"
#include <memory>

class Game
{
private:
    /// scaling member variable
    double mScale;

    ///offset variable for X
    double mXOffset;

    ///offset variable for Y
    double mYOffset;
public:
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    virtual void OnLeftDown(int x, int y);
};

#endif //PROJECT1_335_SUDOKULIB_GAME_H
