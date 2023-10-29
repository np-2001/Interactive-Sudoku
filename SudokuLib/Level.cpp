/**
 * @file Level.cpp
 * @author Eliezer Amponsah, Sania Sinha, Finn Clark, Samantha Wycoff
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
#include "LevelDisplay.h"
#include "VisitorDigit.h"
/**
 * Constructor
 * @param game Game this level belongs to
 */
Level::Level(Game *game) : mGame(game)
{
}


/**
 * Loads the Given Level
 * @param fileName level to load
 */
void Level::LoadLevel()
{
    //Redefined. Declaration is now accessible for the duration of the game
    mDeclaration = std::make_shared<Declaration>();
    wxXmlDocument xmlDoc;

    if(!xmlDoc.Load(mLevelFileName)) // Error check
    {
        wxMessageBox(L"Unable to load Level file");
        return;
    }

    auto root = xmlDoc.GetRoot();
    int width;
    int height;
    int tileSize;
    root->GetAttribute(L"width").ToInt(&width);
    root->GetAttribute(L"height").ToInt(&height);
    root->GetAttribute(L"tilewidth").ToInt(&tileSize);

    // Set Game dimensions
    mGame->SetWidth(width);
    mGame->SetHeight(height);
    mGame->SetTileSize(tileSize);


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
            LoadSolve(tag);
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
 * Loads the solution for the level
 * @param Starting node for the solution
 */
 void Level::LoadSolve(wxXmlNode* node)
 {
     int j =0;
     // <game col="6" row="3">3 2 4 8 7 6 0 1 5 7 5 6 2 0 1 4 8 ... </game>
     int row;
     int col;
     node->GetAttribute(L"row").ToInt(&row);
     node->GetAttribute(L"col").ToInt(&col);

     mGame->GetPlayingArea()->SetTopLeftRow(row);
     mGame->GetPlayingArea()->SetTopLeftCol(col);

     auto content = node->GetChildren()->GetContent().ToStdString();

     for (int i = 0; i<content.length(); i++) {
         if (content[i] != ' ') {
             mSolution[j/9][j%9] = content[i]-48;
             j++;
         }
     }

 }

/**
* solve the level
*/
void Level::SolveLevel() {
    auto firstRow = mGame->GetPlayingArea()->GetTopLeftRow();
    auto firstCol = mGame->GetPlayingArea()->GetTopLeftCol();

    for(int row = firstRow; row < firstRow+9; row++) {
        for(int col = firstCol; col < firstCol+9; col++) {
            // i need to convert from row,col to x,y pixel location (center hopefully)
            int x = col*mGame->GetTileSize() + (mGame->GetTileSize()/2);
            int y = (row+1)*mGame->GetTileSize() - (mGame->GetTileSize()/2);


            // check to see if there is an item in the spot
            auto spot = mGame->HitTest(x, y);
            // if there is no item in the spot on the board find what number should go there
            if(spot == nullptr)
            {
                // else, reference solution to see what number goes there
                // find the number elsewhere on the board
                // and assign it there
                auto solution_value = mSolution[row-firstRow][col-firstCol];

                // find the "correct" number somewhere on the board
                auto correct = mGame->FindNumber(solution_value);

                if(correct == nullptr)
                {
                    continue;
                }

                // assign it to the current row and col values
                correct->SetLocation(row, col);
            }
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

        double row;
        double col;
        node->GetAttribute("col").ToDouble(&col);
        node->GetAttribute("row").ToDouble(&row);

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

            auto container = std::make_shared<Container>(mGame, mDeclaration->GetImage(id),
                                                         mDeclaration->GetImage(id + L"b"));
            container->SetLocation(row, col);
            mGame->Add(container);

            container->AddContainerChildren(node->GetChildren());

            //item = std::make_shared<Container>(mGame, mDeclaration->GetImage(id + "b"));
            continue;



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

            std::shared_ptr<Sparty> sparty = std::make_shared<Sparty>(mGame,
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
            /// Needs to be redone (draw chin in sparty.cpp)

            mGame->SetSparty(sparty);
            item = sparty;
            item->SetLocation(row, col);

            sparty->SetNewCoordinates(item->GetX(),item->GetY());

        }



        // Add to mItems
        mGame->Add(item);
        // Set the location
        item->SetLocation(row, col);

        if (mLevelFileName == L"Levels/level1.xml") {
            mPopup = std::make_shared<LevelDisplay>("Level 1 Begin");
        } else if (mLevelFileName == L"Levels/level2.xml") {
            mPopup = std::make_shared<LevelDisplay>("Level 2 Begin");
        } else if (mLevelFileName == L"Levels/level3.xml") {
            mPopup = std::make_shared<LevelDisplay>("Level 3 Begin");
        } else {
            mPopup = std::make_shared<LevelDisplay>("Level 0 Begin");
        }

    }
}
