/**
 * @file Declaration.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Declaration.h"

Declaration::Declaration(int hit, int wid) : mHeight(hit), mWidth(wid)
{
}

void Declaration::Add(wxString id, std::wstring imageFile)
{
    auto itemImage = std::make_shared<wxImage>(imageFile, wxBITMAP_TYPE_ANY);
    mDeclarations.insert({id, itemImage});

}
