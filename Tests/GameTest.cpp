/**
 * @file GameTest.cpp
 * @author Samantha Wycoff
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Digit.h>
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

