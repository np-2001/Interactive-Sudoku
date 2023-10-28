/**
* @file PlayingArea.cpp
* @author Finn Clark
*/


#include "pch.h"
#include "PlayingArea.h"
#include "Game.h"




/**
* Constructor
* @param game Game object associated with this tile
*/
PlayingArea::PlayingArea(Game *game): mGame(game)
{
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


bool PlayingArea::IsInPlayArea(int x, int y) {
    auto width = mGame->GetTileSize();
    if (x < mTopLeftRow*width || y < mTopLeftCol*width || x > mTopLeftRow*9*width || y > mTopLeftCol*9*width) {
        return false;
    }
    return true;
}
