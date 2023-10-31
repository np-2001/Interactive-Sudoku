/**
 * @file FilledDisplay.cpp
 * @author saman
 */

#include "pch.h"
#include "FilledDisplay.h"
#include "Game.h"

FilledDisplay::FilledDisplay(Game *game, int PixelWidth, int PixelHeight) {
    mGame = game;
    mPixelWidth = PixelWidth;
    mPixelHeight = PixelHeight;
}

void FilledDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics) {

    //outline the rectangle in black
    wxPen pen(wxColour(0, 0, 0), 5);
    graphics->SetPen(pen);

    // Draw a filled rectangle with white background
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);

    int rectangleWidth = 180;
    int rectangleHeight = 70;
    const int RectangleOffset = 190;
    graphics->DrawRectangle(mPixelWidth/2-rectangleWidth/2, mPixelHeight/2-rectangleHeight/2+RectangleOffset, rectangleWidth, rectangleHeight);

    double wid, hit;

    wxFont smallFont(wxSize(0, 40),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(smallFont, wxColour(150, 0, 0));
    graphics->GetTextExtent(L"I'm Full!", &wid, &hit);

    const int textOffset = 200;
    graphics->DrawText(L"I'm Full!", mPixelWidth/2 - wid/2, mPixelHeight/2-rectangleHeight/2+textOffset);


}

void FilledDisplay::Update(double time) {

    mPixelHeight = mPixelHeight-((time*0.0005)*3);
}
