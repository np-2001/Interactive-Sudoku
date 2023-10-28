/**
 * @file VisitorXray.cpp
 * @author Sania Sinha
 */

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
