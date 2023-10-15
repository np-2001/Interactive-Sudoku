/**
 * @file SpartyChin.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "SpartyChin.h"
using namespace std;


const wstring SpartyChinImageName = L"images/sparty-2.png";


/**
 * Constructor
 * @param game Game object associated with this item
 */
SpartyChin::SpartyChin(Game *game, const std::wstring &filename) : Item(game, filename)
{

}

/**
 * Accepting visitor to Sparty
 * @param visitor visitor object
 */
void SpartyChin::Accept(VisitorItem* visitor)
{

}

/**
 * Sparty eats and does not get eaten
 * @param item digit to be eaten
 */
void SpartyChin::Eat(Item *item)
{

}
