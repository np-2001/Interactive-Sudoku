/**
 * @file PlayAreaTest.cpp
 * @author Eliezer Amponsah
 */
#include <pch.h>
#include <regex>
#include "gtest/gtest.h"
#include <Game.h>
#include <PlayingArea.h>


class PlayAreaTest : public ::testing::Test
{
public:
    void TestStartingLocation(int xmlX, int xmlY, std::shared_ptr<PlayingArea> playArea)
    {
        // Left of TopLeft
        ASSERT_FALSE(playArea->IsInPlayArea(xmlX-1, xmlY, false));
        // Above TopLeft
        ASSERT_FALSE(playArea->IsInPlayArea(xmlX, xmlY-1, false));
        // Test At TopLeft
        ASSERT_TRUE(playArea->IsInPlayArea(xmlX, xmlY, false));
    }

    void TestBoardLocations(int xmlX, int xmlY, std::shared_ptr<PlayingArea> playArea)
    {
        // For every row
        for (int i = 0; i < 9; ++i)
        {
            // For every column in that row
            for (int j = 0; j < 9; ++j)
            {
                // Is that location in the play Area
                ASSERT_TRUE(playArea->IsInPlayArea(xmlX+j, xmlY+i, false))
                << "Failed on (col,row): " << xmlX+j << ',' << xmlY+i;
            }

        }
    }
};

TEST_F(PlayAreaTest, BoardLocation)
{
    Game game;
    wxString dirName = L"Levels/";
    auto level = game.GetLevel();
    auto playArea = game.GetPlayingArea();


    // Load Level 0
    level->SetLevel(dirName + L"level0.xml");
    level->LoadLevel();
    int levelStartX = 6, levelStartY = 3;
    // Test level 0 valid board locations
    TestStartingLocation(levelStartX, levelStartY, playArea);
    TestBoardLocations(levelStartX, levelStartY, playArea);

    // Load Level 1
    level->SetLevel(dirName + L"level1.xml");
    level->LoadLevel();
    levelStartX = 4; levelStartY = 3;
    // Test level 1 valid board locations
    TestStartingLocation(levelStartX, levelStartY, playArea);
    TestBoardLocations(levelStartX, levelStartY, playArea);

    // Load Level 2
    level->SetLevel(dirName + L"level2.xml");
    level->LoadLevel();
    playArea = game.GetPlayingArea();
    // Wrong location Should be false
    levelStartX = 4; levelStartY = 3;
    ASSERT_FALSE(playArea->IsInPlayArea(levelStartX, levelStartY, false));
    // Test level 1 valid board locations
    levelStartX = 5; levelStartY = 1;
    TestStartingLocation(levelStartX, levelStartY, playArea);
    TestBoardLocations(levelStartX, levelStartY, playArea);
}
