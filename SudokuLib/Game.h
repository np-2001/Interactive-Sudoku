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
#include "SpartyChin.h"
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

    /// Current Level
    std::shared_ptr<Level> mLevel;

    std::shared_ptr<Sparty> mSparty = nullptr; /// Temp pointer to sparty to be replaced with visitor
    std::shared_ptr<SpartyChin> mSpartyChin = nullptr; /// Temp pointer to spartyChin to be replaced with visitor


public:
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    virtual void OnLeftDown(int x, int y);

    /// The display timer (scoreboard)
    Timer mTimeDisplay;



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
    void OnKeyDown(wxKeyEvent &event);


    /// Level related Operations
    std::shared_ptr<Level> GetLevel() {return mLevel; }

    /// Setter for Sparty
    void SetSparty(std::shared_ptr<Sparty> sparty) {
        mSparty = sparty;
    }

    void SetChin(std::shared_ptr<SpartyChin> chin) {
        mSpartyChin = chin;
    }

};

#endif //PROJECT1_335_SUDOKULIB_GAME_H
