/**
* @file PlayingArea.cpp
* @author Finn Clark
*/


#include "pch.h"
#include <sstream>
#include "PlayingArea.h"
#include "Game.h"
#include "VisitorDigit.h"
#include "VisitorGiven.h"
#include <algorithm>


/**
* Constructor
* @param game Game object associated with this tile
*/
PlayingArea::PlayingArea(Game *game): mGame(game)
{
    // Initialize board to -1 (This lets us know that spot is not filled
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            mBoard[i][j] = -1;
        }
    }
}




int PlayingArea::GetTopLeftRow() const
{
    return mTopLeftRow;
}
void PlayingArea::SetTopLeftRow(int row)
{
    mTopLeftRow = row;
}
int PlayingArea::GetTopLeftCol() const
{
    return mTopLeftCol;
}
void PlayingArea::SetTopLeftCol(int col)
{
    mTopLeftCol = col;
}

/**
 * Checks to see if the location x,y is on the board. if bool xy is true,
 * Checks by pixel values. If bool xy is false, treats x,y as col,row
 * @param x Location x to check (col if xy is false)
 * @param y Location y to check (row if xy is false)
 * @param xy If false, treats x,y as (col,row). If true, treats x,y as (x,y) pixels
 * @return True if the area is in the Sudoku Grid
 */
bool PlayingArea::IsInPlayArea(int x, int y, bool xy = false) {

    if (xy)
    {
        // Process as (x,y) pixel location
        auto width = mGame->GetTileSize();
        if(x < mTopLeftCol * width || y < mTopLeftRow * width || x > mTopLeftCol * 9 * width
            || y > mTopLeftRow * 9 * width)
        {
            return false;
        }
    }
    else
    {
        // Process as (col, row) location
        if (x < mTopLeftCol || y < mTopLeftRow || x > mTopLeftCol * 9 || y > mTopLeftRow * 9)
        {
            return false;
        }
    }

    return true;
}

/**
 * Adds the digit to the board
 * @param row Row where we are trying to add to board
 * @param col Column on the grid where we are trying to add to board
 * @param digit Digit to insert
 * @return True if insertion into the board was successful. False otherwise
 */
bool PlayingArea::AddToBoard(int col, int row, std::shared_ptr<Item> digit)
{
    // If in playing area and there's nothing there
    if (IsInPlayArea(col,row) && !mGame->HitTest(row, col))
    {
        VisitorGiven visitor;
        digit->Accept(&visitor);
        int value = visitor.GetValue();

        mBoard[row - mTopLeftRow][col - mTopLeftCol] = value;
        return true;
    }

    return false;
}

/**
 * Displays the current board in a message window
 */
void PlayingArea::DisplayBoard()
{
    std::stringstream iss;

    for (int i = 0; i < 9; ++i)
    {
        iss << '|';
        for (int j = 0; j < 9; ++j)
        {
            iss << "  ";
            if (mBoard[i][j] != -1)
            {
                iss << mBoard[i][j];
            }
            else
                iss << "  ";

            iss << "  |";
        }
        iss << '\n';
    }

    wxMessageBox(iss.str(), L"Current Board");
}
