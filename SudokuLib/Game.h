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
#include "Level.h"
#include "Sparty.h"

class Game
{
private:
    /// scaling member variable
    double mScale;

    ///offset variable for X
    double mXOffset;

    ///offset variable for Y
    double mYOffset;

    /// Tile size
    int mTileSize = 48;

    /// Screen Width
    int mWidth = 20;

    /// Screen Height
    int mHeight = 15;

    /// List of all items in the game
    std::vector<std::shared_ptr<Item>> mItems;

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use (hardcoded for now)


public:
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    virtual void OnLeftDown(int x, int y);

    /// The display timer (scoreboard)
    Timer mTimeDisplay;

    /// Current Level
    Level mLevel;

    double GetOffsetX() const { return mXOffset;}
    double GetOffsetY() const { return mYOffset;}
    double GetScale() const { return mScale;}

    void SetTileSize(int size) { mTileSize = size;}
    void SetWidth(int wid) { mWidth = wid;}
    void SetHeight(int hit) { mHeight = hit;}

    int GetTileSize() const { return mTileSize;}
    int GetWidth() const { return mWidth;}
    int GetHeight() const { return mHeight;}

    void Update(double time);
    void Add(std::shared_ptr<Item> item);
    void Clear();
    std::shared_ptr<Sparty> mSparty = nullptr; /// pointer to sparty
};

#endif //PROJECT1_335_SUDOKULIB_GAME_H
