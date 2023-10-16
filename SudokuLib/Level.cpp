/**
 * @file Level.cpp
 * @author Eliezer Amponsah, Sania Sinha
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "Level.h"
#include "Game.h"
#include "Declaration.h"
#include "Item.h"
#include "Given.h"
#include "Digit.h"
#include "Background.h"
#include "Container.h"
#include "Xray.h"
#include "Sparty.h"


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

    // Children of the xml: [declarations, games, items]
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        // Children for inner Node: [background, xray, container, given, item, sparty]
        auto innerNode = child->GetChildren();

        // Process Declaration tag
        if (name == L"declarations")
        {
            // Declarations should contain every usable object we are going to use
            for (; innerNode; innerNode = innerNode->GetNext())
            {
                // Call constructors/Visitors for each item
                auto innerName = innerNode->GetName();
                auto innerId = innerNode->GetAttribute(L"id");
                auto innerImage = innerNode->GetAttribute(L"image");

                if(name == "sparty")
                {
                    innerImage = innerNode->GetAttribute(L"image1");
                }
                declarations.Add(innerId, innerImage.ToStdWstring());
            }
        }

        // Process Game tag
        else if (name == L"game")
        {

        }

        // Process Items Tag
        else if (name == L"items")
        {
            // Item contains the instantiated objects
            for (; innerNode; innerNode = innerNode->GetNext())
            {
                auto name = innerNode->GetName();
                auto id = innerNode->GetAttribute(L"id");
                double col;
                innerNode->GetAttribute(L"col").ToDouble(&col);
                double row;
                innerNode->GetAttribute(L"row").ToDouble(&row);

                std::shared_ptr<Item> item;
                if (name == "given")
                {
                    item = std::make_shared<Given>(mGame, declarations.GetDeclarations().at(id));
                }
                else if (name == "digit")
                {
                    item = std::make_shared<Digit>(mGame, declarations.GetDeclarations().at(id));
                }
                else if (name == "background")
                {
                    item = std::make_shared<Background>(mGame, declarations.GetDeclarations().at(id));
                }
                else if (name == "xray")
                {
                    item = std::make_shared<Xray>(mGame, declarations.GetDeclarations().at(id));
                }
                else if (name == "container")
                {
                    item = std::make_shared<Container>(mGame, declarations.GetDeclarations().at(id));
                }
                else if(name == "sparty")
                {
                    item = std::make_shared<Sparty>(mGame, declarations.GetDeclarations().at(id));

                }

                // Set location of item
                item->SetLocation(row,col);
                // Add the item to our list
                mGame->Add(item);




            }

        }
    }


}
