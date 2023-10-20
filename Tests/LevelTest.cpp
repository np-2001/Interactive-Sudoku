/**
 * @file LevelTest.cpp
 * @author Eliezer Amponsah
 */

#include <pch.h>
#include <regex>
#include "gtest/gtest.h"
#include <Game.h>

class LevelTest : public ::testing::Test
{

};

TEST_F(LevelTest, ReadXml)
{
    Game *game;
    auto level = game->GetLevel();

    // Load an invalid file
    level->SetLevel(L"");
    level->LoadLevel()


    auto declaration = level->GetDeclaration();

}