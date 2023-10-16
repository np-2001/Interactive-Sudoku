/**
 * @file Level.cpp
 * @author Eliezer Amponsah
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "Level.h"
#include "Game.h"


/**
 * Loads the Given Level
 * @param fileName level to load
 */
void Level::LoadLevel(std::shared_ptr<wxGraphicsContext> gc)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(mLevel)) // Error check
    {
        wxMessageBox(L"Unable to load Level file");
        return;
    }

    auto root = xmlDoc.GetRoot();
    double width;
    double height;
    root->GetAttribute(L"width").ToDouble(&width);
    root->GetAttribute(L"height").ToDouble(&height);

    mGame->OnDraw(gc, width, height);

    // Children of the xml: [declarations, items,
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        auto innerNode = child->GetChildren();
        if (name == L"declarations")
        {
            // Declarations should contain every usable object we are going to use
            for (; innerNode; innerNode++)
            {
                // Call constructors/Visitors for each item
                auto innerName = innerNode->GetName();
                if (innerName == L"given")
                    wxMessageBox(L"Given Object");

                else if (innerName == L"digit")
                    wxMessageBox(L"Digit Object");

                else if (innerName == L"sparty")
                    wxMessageBox(L"Sparty Object");

                else if (innerName == L"xray")
                    wxMessageBox("xRay Object");

                else if (innerName == L"background")
                    wxMessageBox(L"Background Object");
            }
        }

        else if (name == L"items")
        {
            wxMessageBox(L"We are now on the items");
        }
    }


}
