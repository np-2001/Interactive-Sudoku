/**
 * @file Level.cpp
 * @author Eliezer Amponsah, Sania Sinha
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "Level.h"
#include "Game.h"
#include "Item.h"
#include "Given.h"
#include "Digit.h"
#include "Background.h"
#include "Container.h"
#include "Xray.h"
#include "Sparty.h"

Level::Level(Game *game, wxString level) : mGame(game), mLevelFileName(level)
{
}


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

    //Redefined. Declaration is now accessible for the duration of the game
    mDeclaration = std::make_shared<Declaration>(width, height);

    // Children of the xml: [declaration, game, items]
    auto tag = root->GetChildren(); ///< tag = [declaration, game, items]
    for( ; tag; tag = tag->GetNext())
    {
        wxString tagName = tag->GetName();

        // Process Declaration tag
        if(tagName == L"declarations")
        {
            // Children for Declaration tag: [background, xray, container, given, item, sparty]
            // Make Declarations
            MakeDeclarations(tag->GetChildren());

        }

        // Process Game tag
        else if (tagName == L"game")
        {
            std::cout << "at game..." << std::endl;
        }

        // Process Items Tag
        else if (tagName == L"items")
        {
            MakeItems(tag->GetChildren());


            /*
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
                    item = std::make_shared<Given>(mGame, mDeclaration.GetDeclarations().at(id));
                }
                else if (name == "digit")
                {
                    item = std::make_shared<Digit>(mGame, mDeclaration.GetDeclarations().at(id));
                }
                else if (name == "background")
                {
                    item = std::make_shared<Background>(mGame, mDeclaration.GetDeclarations().at(id));
                }
                else if (name == "xray")
                {
                    item = std::make_shared<Xray>(mGame, mDeclaration.GetDeclarations().at(id));
                }
                else if (name == "container")
                {
                    item = std::make_shared<Container>(mGame, mDeclaration.GetDeclarations().at(id));
                }
                else if(name == "sparty")
                {
                    item = std::make_shared<Sparty>(mGame, mDeclaration.GetDeclarations().at(id));

                }


                // Set location of item
                item->SetLocation(row,col);
                // Add the item to our list
                mGame->Add(item);
            }
             */

        }
    }


}


/**
 * Creates the declarations for the objects that will be used in this level
 * @param node Starting node for the declarations
 */
void Level::MakeDeclarations(wxXmlNode* node)
{

    // node = [background, xray, container, given, item, sparty]
    // Declarations should contain every usable object we are going to use
    for(; node; node = node->GetNext())
    {
        auto name = node->GetName();
        auto id = node->GetAttribute(L"id");
        // Map id to the xmlNode * ex: {id : xmlNode for Sparty}
        mDeclaration->Add(id, node);

        // imageFile = Attribute(image) if name != sparty
        // Otherwise, imageFile = Attribute(image1)

        auto imageFile = (name != L"sparty") ?
            node->GetAttribute("image")  : node->GetAttribute("image1");

        // Create image and add it to declarationImages
        std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/" + imageFile);
        mDeclaration->AddImage(id,image);

        if (name == L"container")
        {
            // Add front image under mapping: id+b. ex: id = i247,
            // mapping = {i247 : image, i247b : front_image, i248 : image ...}
            auto front = L"images/" + node->GetAttribute(L"front");
            image = std::make_shared<wxImage>(front);
            mDeclaration->AddImage(id + L"b", image);
        }

        else if (name == L"sparty")
        {
            // Add chin image under mapping: id+b. ex: id = i247,
            // mapping = {i247 : image1, i247b : chin_image, i248 :image, ...}
            auto image2File = L"images/" + node->GetAttribute(L"image2");
            image = std::make_shared<wxImage>(image2File);
            mDeclaration->AddImage(id + L"b", image);
        }


    }
}

/**
 * Creates the items that are going to be rendered in game and add it to mItems in Game
 * @param node Starting node for the items
 */
void Level::MakeItems(wxXmlNode* node)
{
    // node contains all the items we will have in our scene
    for (; node; node = node->GetNext())
    {
        std::shared_ptr<Item> item;
        auto name = node->GetName();
        auto id = node->GetAttribute(L"id");

        // id mapping
        auto obj = mDeclaration->GetDeclaration(id);

        // Individual Instantiation
        if (name == "digit")
        {
            int value;
            obj->GetAttribute("value").ToInt(&value);
            item = std::make_shared<Digit>(mGame, mDeclaration->GetImage(id), value);
        }
        else if (name == "given")
        {
            int value;
            obj->GetAttribute("value").ToInt(&value);
            item = std::make_shared<Given>(mGame, mDeclaration->GetImage(id), value);
        }
        else if (name == "background")
        {
            item = std::make_shared<Background>(mGame, mDeclaration->GetImage(id));
        }
        else if (name == "xray")
        {
            int capacity;
            obj->GetAttribute("capacity").ToInt(&capacity);
            item = std::make_unique<Xray>(mGame, mDeclaration->GetImage(id), capacity);
        }
        else if (name == "container")
        {
            // Load back image, Load every digit, then load front image
        }
        else if (name == "sparty")
        {
            // Initialise all variables for Sparty Constructor
            double headAngle, mouthAngle, targetX, targetY;
            int front, headX, headY, mouthX, mouthY;

            // Collect all
            obj->GetAttribute(L"front").ToInt(&front);
            obj->GetAttribute(L"head-pivot-angle").ToDouble(&headAngle);
            obj->GetAttribute(L"head-pivot-x").ToInt(&headX);
            obj->GetAttribute(L"head-pivot-y").ToInt(&headY);
            obj->GetAttribute(L"mouth-pivot-angle").ToDouble(&mouthAngle);
            obj->GetAttribute(L"mouth-pivot-x").ToInt(&mouthX);
            obj->GetAttribute(L"mouth-pivot-y").ToInt(&mouthY);
            obj->GetAttribute(L"target-x").ToDouble(&targetX);
            obj->GetAttribute(L"target-y").ToDouble(&targetY);

            item = std::make_shared<Sparty>(mGame,
                                            mDeclaration->GetImage(id),
                                            mDeclaration->GetImage(id + L"b"),
                                            front,
                                            headAngle,
                                            headX,
                                            headY,
                                            mouthAngle,
                                            mouthX,
                                            mouthY,
                                            targetX,
                                            targetY);

        }

        double row;
        double col;
        node->GetAttribute("col").ToDouble(&col);
        node->GetAttribute("row").ToDouble(&row);

        // Set the location
        item->SetLocation(row, col);
        // Add to mItems
        mGame->Add(item);

    }
}