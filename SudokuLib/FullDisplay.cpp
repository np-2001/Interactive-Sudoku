/**
 * @file FullDisplay.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "FullDisplay.h"
#include "Game.h"
/**
 * Constructor
 * @param game Game object being used
 * @param PixelWidth width of pixels for pop-up
 * @param PixelHeight height of pixels for pop-up
 */
FullDisplay::FullDisplay(Game *game, int PixelWidth, int PixelHeight) {
    mGame = game;
    mPixelWidth = PixelWidth;
    mPixelHeight = PixelHeight;
}

/**
 * Draw the pop-up display for when sparty is full
 * @param graphics graphics device to draw on
 */
void FullDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics) {

    //outline the rectangle in black
    wxPen pen(wxColour(0, 0, 0), 5);
    graphics->SetPen(pen);

    // Draw a filled rectangle with white background
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);

    int rectangleWidth = 180;
    int rectangleHeight = 70;
    const int RectangleOffset = 290;
    graphics->DrawRectangle(mPixelWidth/2-rectangleWidth/2, mPixelHeight/2-rectangleHeight/2+RectangleOffset, rectangleWidth, rectangleHeight);

    double wid, hit;

    wxFont smallFont(wxSize(0, 40),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(smallFont, wxColour(150, 0, 0));
    graphics->GetTextExtent(L"I'm Full!", &wid, &hit);

    const int textOffset = 300;
    graphics->DrawText(L"I'm Full!", mPixelWidth/2 - wid/2, mPixelHeight/2-rectangleHeight/2+textOffset);


}

/**
 * Update the pop-up display so it can move up the screen.
 * @param time time the display moves at.
 */
void FullDisplay::Update(double time) {

    mPixelHeight = mPixelHeight-((time*0.0005)*5);
}
