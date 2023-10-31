/**
 * @file VisitorXray.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "VisitorXray.h"
#include "Xray.h"
#include "Game.h"

/**
 * Calls function that will add item to xray
 * @param item to be added to xray
 */
void VisitorXray::CallAdd(std::shared_ptr<Item> item)
{
    if(mXray != nullptr)
    {
        mXray->Add(item);
    }
}
/**
 * Calls throw up function
 * @param graphics Graphics device to draw on
 */
void VisitorXray::CallThrowup(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mXray != nullptr)
    {
        mXray->GetGame()->Throwup(graphics, mXray);
    }
}
/**
 * Calls remove function for xray
 * @param item Item that will be removed from xray
 */
void VisitorXray::CallRemove(std::shared_ptr<Item> item)
{
    if(mXray != nullptr)
    {
        mXray->Remove(item);
    }
}

/**
 * Calls GetMatch on xray
 * @param x Item to be checked for
 * @return Bool representing if Item is in Xray
 */
std::shared_ptr<Item> VisitorXray::CallGetMatch(int x)
{
    if(mXray != nullptr)
    {
        return mXray->GetMatch(x);
    }
    //return nullptr;
}

/**
 * Calls TimerStart on xray
 * @return Boolean representing if throw up timer can start
 */
bool VisitorXray::CallTimerStart() {
    return mXray->TimerStart();
}
/**
 * Calls CallFull on xray
 * @return Boolean representing if xray is full
 */
bool VisitorXray::CallFull() {
    return mXray->Full();
}