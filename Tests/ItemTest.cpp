/**
 * @file ItemTest.cpp
 * @author Finn Clark
 */

#include "pch.h"
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>
#include <filesystem>
#include <Digit.h>

using namespace std;
class Item;
// std::filesystem::current_path().generic_string() + L"/../../"
/// item image
const std::wstring itemFile = L"0b.png";
auto itemFilepath = std::filesystem::current_path().generic_string() + L"/images/" + itemFile;
auto image = std::make_shared<wxImage>(itemFilepath, wxBITMAP_TYPE_ANY);

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game, std::shared_ptr<wxImage> image) : Item(game, image) {}
    void Eat(Item *item) {};
    void Accept(VisitorItem* visitor) {};

};

TEST(ItemTest, Construct) {
    Game game;
//    std::shared_ptr<Item> item = std::make_shared<Digit>(game, image, 0);
}

TEST(ItemTest, HitTest) {
    // Create an item to test
    Game game;
    ItemMock item(&game, image);

    // Give it a location
    // Always make the numbers different, in case they are mixed up
    item.SetLocation(100, 200);

    // Center of the item should be a true
    ASSERT_TRUE(item.HitTest(100, 200));
//
//    // Left of the item
//    ASSERT_FALSE(item.HitTest(10, 200));
//
//    // Right of the item
//    ASSERT_FALSE(item.HitTest(200, 200));
//
//    // Above the item
//    ASSERT_FALSE(item.HitTest(100, 0));
//
//    // Below the item
//    ASSERT_FALSE(item.HitTest(100, 300));
//
//    // On a item transparent pixel
//    ASSERT_FALSE(item.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}