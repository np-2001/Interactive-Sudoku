/**
 * @file FullDisplay.cpp
 * @author Samantha Wycoff
 */

#include "pch.h"
#include "FullDisplay.h"
#include "Game.h"

FullDisplay::FullDisplay() {

}

//FullDisplay::FullDisplay(wxString word) {
//    mWord = word;
//}

void FullDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth) {

    if (mTime*0.001 <= 3) {

        //outline the rectangle in black
        wxPen pen(wxColour(0, 0, 0), 3);
        graphics->SetPen(pen);

        // Draw a filled rectangle with white background
        wxBrush rectBrush(*wxWHITE);
        graphics->SetBrush(rectBrush);

        int rectangleWidth = 70;
        int rectangleHeight = 30;
        graphics->DrawRectangle(pixelWidth/2-rectangleWidth/2, pixelHeight/2-rectangleHeight/2, rectangleWidth, rectangleHeight);

        //may not need this as it might be specific to level
        //text box I'm making is the same for each level
//        wxFont bigFont(wxSize(0, 8),
//                       wxFONTFAMILY_SWISS,
//                       wxFONTSTYLE_NORMAL,
//                       wxFONTWEIGHT_BOLD);
//        graphics->SetFont(bigFont, wxColour(128, 0, 0));
        double wid, hit;
//        graphics->GetTextExtent(mWord, &wid, &hit);
//        graphics->DrawText(mWord, pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2);

        wxFont smallFont(wxSize(0, 40),
                         wxFONTFAMILY_SWISS,
                         wxFONTSTYLE_NORMAL,
                         wxFONTWEIGHT_BOLD);
        graphics->SetFont(smallFont, wxColour(128, 0, 0));
        graphics->GetTextExtent(L"I'm Full!", &wid, &hit);
        graphics->DrawText(L"I'm Full!", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+80);

    }
}

void FullDisplay::Update(double time) {
    mTime = time;
    //mGame->GetYPosition() = mGame->GetYPosition() - time * 3;
}
