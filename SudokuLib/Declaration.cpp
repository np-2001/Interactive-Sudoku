/**
 * @file Declaration.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Declaration.h"

Declaration::Declaration(int hit, int wid) : mHeight(hit), mWidth(wid)
{
}

void Declaration::Add(wxString id, const std::wstring &imageFile)
{
    auto image = L"images/" + imageFile;
    auto itemImage = std::make_shared<wxImage>(image, wxBITMAP_TYPE_ANY);
    mDeclarations.insert({id, itemImage});

}
