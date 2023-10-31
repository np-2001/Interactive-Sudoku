/**
 * @file FullDisplay.cpp
 * @author Samantha Wycoff
 */

#include "pch.h"
#include "FullDisplay.h"
#include "Game.h"

FullDisplay::FullDisplay(Game *game, int PixelWidth, int PixelHeight) {
    mGame = game;
    mPixelWidth = PixelWidth;
    mPixelHeight = PixelHeight;
}

//FullDisplay::FullDisplay(wxString word) {
//    mWord = word;
//}

void FullDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics) {

    //outline the rectangle in black
    wxPen pen(wxColour(0, 0, 0), 3);
    graphics->SetPen(pen);

    // Draw a filled rectangle with white background
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);

    int rectangleWidth = 180;
    int rectangleHeight = 90;
    const int RectangleOffset = 160;
    graphics->DrawRectangle(mPixelWidth/2-rectangleWidth/2, mPixelHeight/2-rectangleHeight/2+RectangleOffset, rectangleWidth, rectangleHeight);


    double wid, hit;



    wxFont smallFont(wxSize(0, 40),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(smallFont, wxColour(128, 0, 0));
    graphics->GetTextExtent(L"I'm Full!", &wid, &hit);

    const int textOffset = 200;
    graphics->DrawText(L"I'm Full!", mPixelWidth/2 - wid/2, mPixelHeight/2-rectangleHeight/2+textOffset);


}

void FullDisplay::Update(double time) {

    mPixelHeight = mPixelHeight-((time*0.0005)*1);
}
