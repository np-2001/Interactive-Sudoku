/**
 * @file Game.h
 * @author Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 *
 * Class describing the game overall.
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
#include "FullDisplay.h"
#include "FilledDisplay.h"
/**
 * Class describing the game overall.
 */
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

    /// Y position for pop ups
    int mYPosition;

    /// List of all items in the game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Current Level
    std::shared_ptr<Level> mLevel;

    /// Playing Area
    std::shared_ptr<PlayingArea> mPlayingArea;

    /// pointer to sparty
    std::shared_ptr<Sparty> mSparty = nullptr;

    ///pointer to Xray
    std::shared_ptr<Xray> mXray;

    ///vector of pop-ups to be drawn for if sparty is full
    std::vector<std::shared_ptr<FullDisplay>> mFullList;

    ///vector of pop-ups to be drawn for if a tile is filled
    std::vector<std::shared_ptr<FilledDisplay>> mFilledList;

    ///Current time
    long mTime = 0;

    ///Old Time
    long mOldTime;

    ///Old Time for game sequencing
    long mOldTime2;

    ///Eat Time
    long mEatTime = 0;

    /// The timer that allows for animation of level 3 feature
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time for level 3 feature
    wxStopWatch mStopWatch;

    /// Stopwatch used to measure elapsed time for game sequencing
    wxStopWatch mStopWatch2;

    ///Indicates timer has started for throw up
    bool mStarted = false;

    ///Indicates game has been completed
    bool mCompletion = false;

    ///Indicates loading next level
    bool mNext = false;

    ///Indicates staying on current level
    bool mCurrent = false;

    ///Indicates solution has been checked
    bool mCheck = false;

    /// The display timer (scoreboard)
    Timer mTimeDisplay;
public:
    ///Constructor
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    virtual void OnLeftDown(int x, int y);



    /**
     * Getter for X Offset
     * @return double X Offset
     */
    double GetOffsetX() const { return mXOffset;}

    /**
     * Getter for Y Offset
     * @return double Y Offset
     */
    double GetOffsetY() const { return mYOffset;}

    /**
     * Getter for scale
     * @return double scale value
     */
    double GetScale() const { return mScale;}

    /**
     * Setter for tile size
     * @param size size of tile
     */
    void SetTileSize(int size) { mTileSize = size;}

    /**
     * Setter for width of screen
     * @param wid screen width
     */
    void SetWidth(int wid) { mWidth = wid;}

    /**
     * Setter for height of screen
     * @param hit screen height
     */
    void SetHeight(int hit) { mHeight = hit;}

    /**
     * Getter for tile size
     * @return int size of tile
     */
    int GetTileSize() const { return mTileSize;}

    /**
     * Getter for screen width
     * @return int width of screen
     */
    int GetWidth() const { return mWidth;}

    /**
     * Getter for screen height
     * @return int height of screen
     */
    int GetHeight() const { return mHeight;}

    /**
     * Getter for Y position
     * @return int Y position
     */
    int GetYPosition() const {return mYPosition;}

    void Update(double time);
    void Add(std::shared_ptr<Item> item);
    void Clear();
    void OnKeyDown(wxKeyEvent &event);
    void Accept(VisitorItem *visitor);
    std::shared_ptr<Item> GetXray();
    void AddToFront(std::shared_ptr<Item> item);


    /**
     * Getter for specific level
     * @return level
     */
    std::shared_ptr<Level> GetLevel() {return mLevel; }

    /**
     * Getter for playing area object
     * @return playing area
     */
    std::shared_ptr<PlayingArea> GetPlayingArea() {return mPlayingArea; }

    /**
     * Setter for sparty
     * @param sparty sparty object
     */
    void SetSparty(std::shared_ptr<Sparty> sparty) {
        mSparty = sparty;
    }

    std::shared_ptr<Item> EatTest(int x, int y);
    std::shared_ptr<Item> HitTest(int row, int col);

    /**
     * Reset timer.
     */
    void ResetTime() {
        mTime = 0;
    }

    std::shared_ptr<Item> FindNumber(int num);
    void Throwup(std::shared_ptr<wxGraphicsContext> graphics, Xray* xRay);
    void MakeSpartyLast(std::shared_ptr<Item>);

    /**
     * Getter for eat time
     * @return long time to eat
     */
    long GetEatTime() {
        return mEatTime;
    }

    void Finished(bool correct,std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Setter for completion of game
     * @param completed true if game completed
     */
    void SetCompleted (bool completed) {
        mCompletion = completed;
    }

    /**
     * Getter for next game
     * @return bool
     */
    bool GetNext () {
        return mNext;
    }

    /**
     * Getter for current game
     * @return bool
     */
    bool GetCurrent () {
        return mCurrent;
    }

    /**
     * Setter for next game
     * @param next next game
     */
    void SetNext(bool next) {
        mNext = next;
    }

    /**
     * Setter for current game
     * @param current current game
     */
    void SetCurrent(bool current) {
        mCurrent = current;
    }

    /**
     * Setter for game solution check
     */
    void SetCheck(bool check) {
        mCheck = check;
    }

};

#endif //PROJECT1_335_SUDOKULIB_GAME_H
