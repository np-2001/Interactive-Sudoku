/**
 * @file VisitorXray.cpp
 * @author Sania Sinha
 */

#include "VisitorXray.h"
#include "Xray.h"

void VisitorXray::CallAdd(std::shared_ptr<Item> item)
{
    if(mXray != nullptr)
    {
        mXray->Add(item);
    }
}
