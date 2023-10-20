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

public:

    /**
     * Tests the declaration map to make sure each field is filled with an xmlNode
     * @param declarations declaration to observe
     * @param startingId starting number version of the index in the xml i.e. if
     * id = i579, then put 579
     * @param length Length of the declaration list
     */
    void TestDeclarations(std::shared_ptr<Declaration>& declarations, int startingId, int length)
    {
        ASSERT_EQ(length, declarations->GetDeclarationSize());

        for (int i = 0; i < length; ++i)
        {
            // Convert to string id i.e. i579
            auto id = wxString::Format(wxT("i%i"), startingId);

            // Confirm there's an xmlNode there
            ASSERT_NE(nullptr, declarations->GetDeclaration(id));
            ++startingId;
        }
    }
};

TEST_F(LevelTest, ReadXml)
{
    // A lot of errors because Game does not have any valid info
    // I don't know what to do about it
    Game game;

    auto level = game.GetLevel();
    level->LoadLevel();
    auto declarations = level->GetDeclaration();

    // Empty Level should have no items
    ASSERT_EQ(L"", level->GetCurrentLevel());
    ASSERT_EQ(0, declarations->GetDeclarationSize());

    // Level 1 Testing
    auto level1 = L"Levels/level1.xml";
    level->SetLevel(level1);
    level->LoadLevel();
    declarations = level->GetDeclaration();

    // Test Level1. Level 1 has 21 declarations
    ASSERT_EQ(level1, level->GetCurrentLevel());
    ASSERT_EQ(21, declarations->GetDeclarationSize());

    // Test Game Attributes
    ASSERT_EQ(game.GetWidth(), 20);
    ASSERT_EQ(game.GetHeight(), 15);
    ASSERT_EQ(game.GetTileSize(), 48);

    // <given id="i579" width="48" height="48" image="0b.png" value="0" />
    // Test individual attribute for correct attributes
    //wxString id = L"579";
    int index(579);
    /// Values that are not in the level xml
    std::vector<int> skip{596, 597};

    //TestDeclarations(declarations, index, 21);
    for (int i = 0; i < 21; ++i)
    {
        // Convert to string id i.e. i579
        auto id = L"i" + std::to_wstring(index);
        //auto id = wxString::Format(wxT("i%i"), index);

        // We should not fail that there's an xmlNode
        // If id is not part of our skip indices
        if (std::find(skip.begin(), skip.end(),index) == skip.end())
        {
            ASSERT_NO_THROW(declarations->GetDeclaration(id)) << "Failed at index i" << index;
        }
        ++index;
    }

}