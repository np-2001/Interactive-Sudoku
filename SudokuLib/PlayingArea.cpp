/**
 * @file PlayingArea.cpp
 * @author Finn Clark
 */

#include "pch.h"
#include "PlayingArea.h"


/**
 * Constructor
 * @param game Game object associated with this tile
 */
PlayingArea::PlayingArea(Game *game): mGame(game)
{
}


int PlayingArea::getTopLeftX() const
{
    return mTopLeftX;
}
void PlayingArea::setTopLeftX(int x)
{
    mTopLeftX = x;
}
int PlayingArea::getTopLeftY() const
{
    return mTopLeftY;
}
void PlayingArea::setTopLeftY(int y)
{
    mTopLeftY = y;
}
