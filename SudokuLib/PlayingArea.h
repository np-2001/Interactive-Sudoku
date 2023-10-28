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
    int mTopLeftX;
    int mTopLeftY;

public:
    PlayingArea(Game *game);
    int getTopLeftX() const;
    void setTopLeftX(int x);
    int getTopLeftY() const;
    void setTopLeftY(int y);

};

#endif //PROJECT1_335_SUDOKULIB_PLAYINGAREA_H
