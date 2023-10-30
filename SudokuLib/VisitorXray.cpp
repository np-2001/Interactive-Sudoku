/**
 * @file VisitorXray.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "VisitorXray.h"
#include "Xray.h"
#include "Game.h"

void VisitorXray::CallAdd(std::shared_ptr<Item> item)
{
    if(mXray != nullptr)
    {
        mXray->Add(item);
    }
}

void VisitorXray::CallThrowup(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mXray != nullptr)
    {
        mXray->GetGame()->Throwup(graphics, mXray);
    }
}

void VisitorXray::CallRemove(std::shared_ptr<Item> item)
{
    if(mXray != nullptr)
    {
        mXray->Remove(item);
    }
}

std::shared_ptr<Item> VisitorXray::CallGetMatch(int x)
{
    if(mXray != nullptr)
    {
        return mXray->GetMatch(x);
    }
}

bool VisitorXray::CallTimerStart() {
    return mXray->TimerStart();
}