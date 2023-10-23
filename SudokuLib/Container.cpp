/**
 * @file Container.cpp
 * @author Sania Sinha
 */

#include "pch.h"
#include "Container.h"
#include "Game.h"
#include "Digit.h"

/**
 * Constructor
 * @param game Game object associated with this item
 */
Container::Container(Game *game, std::shared_ptr<wxImage> image) :
    Item(game, image)
{
}

/**
 * Accepting visitor to Container
 * @param visitor visitor object
 */
void Container::Accept(VisitorItem* visitor)
{
    visitor->VisitContainer(this);
}

/**
 * Containers do not have Eat functionality
 * @param item background item
 */
void Container::Eat()
{

}


/**
 * Adds all the digit children to the container
 * @param node
 */
void Container::AddContainerChildren(wxXmlNode* node)
{
    auto game = Item::GetGame();
    std::shared_ptr<Digit> digit;
    auto declarations = game->GetLevel()->GetDeclaration();
    int value;
    double row;
    double col;

    for (; node; node = node->GetNext())
    {
        wxString id = node->GetAttribute("id");
        node->GetAttribute("col").ToDouble(&col);
        node->GetAttribute("row").ToDouble(&row);


        auto image = declarations->GetImage(id);
        declarations->GetDeclaration(id)->GetAttribute("value").ToInt(&value);


        digit = std::make_shared<Digit>(game, image, value);

        mContainerItems.push_back(digit);
    }
}
