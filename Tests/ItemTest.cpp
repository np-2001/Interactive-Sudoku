/**
 * @file ItemTest.cpp
 * @author Finn Clark
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Digit.h>
#include <memory>

///** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game, std::shared_ptr<wxImage> image) : Item(game, image) {}
    void Eat(Item *item) {};
    void Accept(VisitorItem* visitor) {};
    void Update(double elapsed){};
    void Eat() {};
    void Regurgitate() {};
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) {};
    //bool EatTest(double x, double y) {};
    void XmlLoad(wxXmlNode *node) {};


};

using namespace std;

TEST(ItemTest, Construct){
    Game game;
    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();
    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/1b.png", wxBITMAP_TYPE_ANY);
    ItemMock item(&game, image);
}

TEST(ItemTest, PixelLocation) {
    Game game;
    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();
    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/1b.png", wxBITMAP_TYPE_ANY);
    ItemMock item(&game, image);

    item.SetPixelLocation(100, 200);
    ASSERT_NEAR(item.GetX(), 100, 1);
    ASSERT_NEAR(item.GetY(), 200, 1);
}


TEST(ItemTest, HitTest){
    Game game;
    game.GetLevel()->SetLevel(L"Levels/level0.xml");
    game.GetLevel()->LoadLevel();
    std::shared_ptr<wxImage> image = std::make_shared<wxImage>(L"images/1b.png", wxBITMAP_TYPE_ANY);
    ItemMock item(&game, image);

    item.SetPixelLocation(100, 200);
    ASSERT_TRUE(item.HitTest(100, 200));


    // Left of the item
    ASSERT_FALSE(item.HitTest(10, 200));

    // Right of the item
    ASSERT_FALSE(item.HitTest(200, 200));

    // Above the item
    ASSERT_FALSE(item.HitTest(100, 0));

    // Below the item
    ASSERT_FALSE(item.HitTest(100, 300));

    // On a item transparent pixel
    ASSERT_FALSE(item.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}