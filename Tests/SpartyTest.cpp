/**
 * @file SpartyTest.cpp
 * @author Nitin Polavarapu
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

TEST(SpartyTest, Construct){
    Game game;
    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();
    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/sparty-1.png", wxBITMAP_TYPE_ANY);
    std::shared_ptr<wxImage> image2 = std::make_shared<wxImage>(L"images/sparty-2.png", wxBITMAP_TYPE_ANY);
    Sparty sparty(&game, image,image2,2, 0, 0, 0, 0,
        0, 0, 0, 0);

}

TEST(SpartyTest, GettersSetters){
    Game game;
    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();

    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/sparty-1.png", wxBITMAP_TYPE_ANY);
    std::shared_ptr<wxImage> image2 = std::make_shared<wxImage>(L"images/sparty-2.png", wxBITMAP_TYPE_ANY);
    Sparty sparty(&game, image,image2,2, 0, 0, 0, 0,
           0, 0, 0, 0);


    // Test initial values
    ASSERT_NEAR(48, sparty.GetX(), 0.0001);
    ASSERT_NEAR(0, sparty.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    sparty.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, sparty.GetRow(), 0.0001);
    ASSERT_NEAR(17.2, sparty.GetCol(), 0.0001);

    // Test a second with different values
    sparty.SetLocation(-72, -107);
    ASSERT_NEAR(-72, sparty.GetRow(), 0.0001);
    ASSERT_NEAR(-107, sparty.GetCol(), 0.0001);
}