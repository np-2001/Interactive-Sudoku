/**
* @file PlayingArea.h
* @author Finn Clark
*
*
*/


#ifndef PROJECT1_335_SUDOKULIB_PLAYINGAREA_H
#define PROJECT1_335_SUDOKULIB_PLAYINGAREA_H

#include "Item.h"
#include <array>

class Game;


/**
* Class responsible for holding the positions of the tiles on the board
* and what they contain
*/
class PlayingArea
{
private:
/// Game this item is contained in
    Game *mGame;


    /// TopLeft position
    int mTopLeftCol;
    int mTopLeftRow;

    /// The current state of the board
    std::array<std::array<int, 9>, 9> mBoard;

    /// The solution of the board
    std::array<std::array<int, 9>, 9> mSolution;
    int mFill = 0;


public:
    PlayingArea(Game *game);
    int GetTopLeftRow() const;
    void SetTopLeftRow(int row);
    int GetTopLeftCol() const;
    void SetTopLeftCol(int col);

    std::array<std::array<int, 9>, 9> GetSolution();
    void SetSolution(std::array<std::array<int, 9>, 9> solution);


    bool IsInPlayArea(int x, int y, bool xy);

    bool AddToBoard(int col, int row, std::shared_ptr<Item>digit);

    bool RemoveFromBoard(int col, int row, std::shared_ptr<Item>digit);

    void DisplayBoard();

    bool CheckSolution();

    int GetFill() {
        return mFill;
    }

    void SetFill () {
        mFill = 0;
    }
};


#endif //PROJECT1_335_SUDOKULIB_PLAYINGAREA_H