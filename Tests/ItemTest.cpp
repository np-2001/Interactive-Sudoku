/**
 * @file ItemTest.cpp
 * @author Finn Clark
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>

using namespace std;
class Item;

/// item image
const std::wstring ItemImageName = L"images/0b.png";
const std::shared_ptr<wxImage> image = make_unique<wxImage>(ItemImageName, wxBITMAP_TYPE_ANY);

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game) : Item(game, image) {}
    void Eat(Item *item) {};
    void Accept(VisitorItem* visitor) {};

};

TEST(ItemTest, Construct) {
    Game game;
    ItemMock item(&game);
}

TEST(ItemTest, HitTest) {
    // Create an item to test
    Game game;
    ItemMock item(&game);

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