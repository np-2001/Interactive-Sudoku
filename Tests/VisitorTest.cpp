/**
 * @file VisitorTest.cpp
 * @author Sania Sinha
 */

#include <pch.h>
#include <regex>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Digit.h>
#include <Given.h>
#include <VisitorGiven.h>
#include <VisitorDigit.h>
#include <VisitorSparty.h>

TEST(VisitorTest, CheckType)
{
    Game game;

    // Make a digit 0
    std::shared_ptr<Item> item;
    auto image1 = std::make_shared<wxImage>(L"images/0r.png");
    item = std::make_shared<Digit>(&game, image1, 0);
    game.Add(item);

    VisitorDigit visitor;
    item->Accept(&visitor);

    // Check if visitor can accurately tell that the item is a Digit
    ASSERT_EQ(true, visitor.MatchDigit());
    // Visitor gets the correct value
    ASSERT_EQ(0, visitor.GetValue());

    // Make a given 3
    std::shared_ptr<Item> item2;
    auto image2 = std::make_shared<wxImage>(L"images/3b.png");
    item2 = std::make_shared<Given>(&game, image2, 3);
    game.Add(item2);

    VisitorGiven visitor2;
    item2->Accept(&visitor2);

    // Item is a given
    ASSERT_EQ(true, visitor2.MatchGiven());

    // Make Sparty
    std::shared_ptr<Item> sparty;
    auto sparty_image = std::make_shared<wxImage>(L"images/sparty-1.png");
    auto sparty_image2 = std::make_shared<wxImage>(L"images/sparty-2.png");
    sparty = std::make_shared<Sparty>(&game, sparty_image, sparty_image2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    game.Add(sparty);

    VisitorSparty visitor3;
    sparty->Accept(&visitor3);

    VisitorGiven visitor4;
    sparty->Accept(&visitor4);

    // Item is a given
    ASSERT_EQ(true, visitor3.MatchSparty());
    // Check others aren't returning false positives
    ASSERT_EQ(false, visitor4.MatchGiven());

}
