/**
* @file PlayingArea.h
* @author Finn Clark
*
*
*/


#ifndef PROJECT1_335_SUDOKULIB_PLAYINGAREA_H
#define PROJECT1_335_SUDOKULIB_PLAYINGAREA_H

#include "Item.h"

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
    int mBoard[9][9];


public:
    PlayingArea(Game *game);
    int GetTopLeftRow() const;
    void SetTopLeftRow(int row);
    int GetTopLeftCol() const;
    void SetTopLeftCol(int col);


    bool IsInPlayArea(int x, int y, bool xy);

    bool AddToBoard(int col, int row, std::shared_ptr<Item>digit);

    void DisplayBoard();

};


#endif //PROJECT1_335_SUDOKULIB_PLAYINGAREA_H