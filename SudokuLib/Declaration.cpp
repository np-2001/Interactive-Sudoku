/**
 * @file Declaration.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Declaration.h"

Declaration::Declaration(int hit, int wid) : mHeight(hit), mWidth(wid)
{
}

void Declaration::Add(wxString id, wxXmlNode *node)
{
    mDeclarations.insert({id, node});

}
