/**
 * @file GameTest.cpp
 * @author Samantha Wycoff
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>
#include <memory>

using namespace std;

TEST(GameTest, Construct){
    Game game;
}

// Determine if all items are being iterated over and drawn
TEST(GameTest, OnDraw){
    Game game;

    // Test that there are no items in the game
        //add code here

    //shared_ptr<Item> item = make_shared<Item>(&game)
    //game.Add(item);

}