/**
* @file PlayingArea.h
* @author Finn Clark
*
*
*/


#ifndef PROJECT1_335_SUDOKULIB_PLAYINGAREA_H
#define PROJECT1_335_SUDOKULIB_PLAYINGAREA_H


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
    int mTopLeftRow;
    int mTopLeftCol;


public:
    PlayingArea(Game *game);
    int GetTopLeftRow() const;
    void SetTopLeftRow(int row);
    int GetTopLeftCol() const;
    void SetTopLeftCol(int col);


    bool IsInPlayArea(int x, int y);


};


#endif //PROJECT1_335_SUDOKULIB_PLAYINGAREA_H