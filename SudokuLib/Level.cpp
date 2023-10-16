/**
 * @file Level.cpp
 * @author Eliezer Amponsah
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "Level.h"
#include "Game.h"
#include "Declaration.h"


/**
 * Loads the Given Level
 * @param fileName level to load
 */
void Level::LoadLevel()
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(mLevelFileName)) // Error check
    {
        wxMessageBox(L"Unable to load Level file");
        return;
    }

    auto root = xmlDoc.GetRoot();
    int width;
    int height;
    root->GetAttribute(L"width").ToInt(&width);
    root->GetAttribute(L"height").ToInt(&height);

    //TODO Worthy of review
    Declaration declarations(width, height);

    // Children of the xml: [declarations, items,
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        auto innerNode = child->GetChildren();
        if (name == L"declarations")
        {
            // Declarations should contain every usable object we are going to use
            for (; innerNode; innerNode=innerNode->GetNext())
            {
                // Call constructors/Visitors for each item
                auto innerId = innerNode->GetAttribute(L"id");
                auto innerImage = innerNode->GetAttribute(L"image");
                declarations.Add(innerId, innerImage.ToStdWstring());
            }
        }

        else if (name == L"items")
        {
            wxMessageBox(L"We are now on the items");
        }
    }


}
