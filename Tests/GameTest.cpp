/**
 * @file GameTest.cpp
 * @author Samantha Wycoff
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Digit.h>
#include <Given.h>
#include <Sparty.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>
#include <memory>

using namespace std;

TEST(GameTest, Construct){
    Game game;
    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();
}


TEST(GameTest, HitTest){
    Game game;
    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/1b.png", wxBITMAP_TYPE_ANY);
    ASSERT_EQ(game.HitTest(200, 200), nullptr) << L"Testing Empty Game";

    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();

    shared_ptr<Digit> digit = make_shared<Digit>(&game,image,1);
    game.Add(digit);
    digit->SetPixelLocation(100, 200);
    ASSERT_EQ(game.HitTest(1000, 1000), nullptr);

    ASSERT_TRUE(game.HitTest(100, 200) == digit);

}

TEST(GameTest, Clear){
    Game game;

    //initialize an image for an item
    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/1b.png", wxBITMAP_TYPE_ANY);

    ASSERT_EQ(game.HitTest(100, 200), nullptr) <<
                                                    L"Testing empty game, no items in mItems.";

    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();

    //add digit to mItems
    shared_ptr<Digit> digit = make_shared<Digit>(&game,image,1);
    game.Add(digit);
    digit->SetPixelLocation(100, 200);

    //add given to mItems
    shared_ptr<Given> given = make_shared<Given>(&game,image,1);
    game.Add(given);
    given->SetPixelLocation(300, 400);


    ASSERT_TRUE(game.HitTest(100, 200) == digit) <<
                                               L"Testing digit was added to mItems";
    ASSERT_TRUE(game.HitTest(300, 400) == given) <<
                                               L"Testing given was added to mItems";

    // clear mItems of all items
    game.Clear();

    ASSERT_EQ(game.HitTest(100, 200), nullptr) <<
                                               L"Testing digit was removed from mItems.";
    ASSERT_EQ(game.HitTest(300, 400), nullptr) <<
                                               L"Testing given was removed from mItems.";

}

