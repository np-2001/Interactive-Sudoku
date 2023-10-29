/**
 * @file Game.h
 * @author Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
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
#include "PlayingArea.h"
#include "Xray.h"
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
    int mTileSize;

    /// Screen Width
    int mWidth;

    /// Screen Height
    int mHeight;

    /// List of all items in the game
    std::vector<std::shared_ptr<Item>> mItems;

   // std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use (hardcoded for now)

    /// Current Level
    std::shared_ptr<Level> mLevel;

    /// Playing Area
    std::shared_ptr<PlayingArea> mPlayingArea;

    /// pointer to sparty
    std::shared_ptr<Sparty> mSparty = nullptr;

    ///Current time
    long mTime = 0;

    ///Old Time
    long mOldTime;

    ///Eat Time
    long mEatTime = 0;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;


    ///Indicates timer has started for throw up
    bool mStarted = false;
public:
    Game();
    Game(wxString startingLevel);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    virtual void OnLeftDown(int x, int y);

    /// The display timer (scoreboard)
    Timer mTimeDisplay;

    Timer mTimeDisplay2;
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
    void Accept(VisitorItem *visitor);
    std::shared_ptr<Item> GetXray();


    /// Level related Operations
    std::shared_ptr<Level> GetLevel() {return mLevel; }

    /// Playing Area related Operations
    std::shared_ptr<PlayingArea> GetPlayingArea() {return mPlayingArea; }

    /// Setter for Sparty
    void SetSparty(std::shared_ptr<Sparty> sparty) {
        mSparty = sparty;
    }



    std::shared_ptr<Item> EatTest(int x, int y);
    std::shared_ptr<Item> HitTest(int row, int col);

    void ResetTime() {
        mTime = 0;
    }

    std::shared_ptr<Item> FindNumber(int num);
    void Throwup(std::shared_ptr<wxGraphicsContext> graphics, Xray* xRay);

    void MakeSpartyLast(std::shared_ptr<Item>);

    long GetEatTime() {
        return mEatTime;
    }

    void Finished(bool correct,std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //PROJECT1_335_SUDOKULIB_GAME_H
