/**
 * @file LevelDisplay.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "LevelDisplay.h"
LevelDisplay::LevelDisplay() {

}
LevelDisplay::LevelDisplay(wxString word) {
    mWord = word;
}
void LevelDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth) {

    if (mTime*0.001 <= 3) {

        //
        // Draw a filled rectangle
        //
        wxBrush rectBrush(*wxWHITE);
        graphics->SetBrush(rectBrush);
        graphics->SetPen(*wxTRANSPARENT_PEN);

        int rectangleWidth = 700;
        int rectangleHeight = 300;
        graphics->DrawRectangle(pixelWidth/2-rectangleWidth/2, pixelHeight/2-rectangleHeight/2, rectangleWidth, rectangleHeight);


        wxFont bigFont(wxSize(0, 80),
                       wxFONTFAMILY_SWISS,
                       wxFONTSTYLE_NORMAL,
                       wxFONTWEIGHT_BOLD);
        graphics->SetFont(bigFont, wxColour(0, 128, 0));
        double wid, hit;
        graphics->GetTextExtent(mWord, &wid, &hit);
        graphics->DrawText(mWord, pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2);

        wxFont smallFont(wxSize(0, 40),
                       wxFONTFAMILY_SWISS,
                       wxFONTSTYLE_NORMAL,
                       wxFONTWEIGHT_BOLD);
        graphics->SetFont(smallFont, *wxBLACK);
        graphics->GetTextExtent(L"Space: Eat", &wid, &hit);
        graphics->DrawText(L"Space: Eat", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+80);

        graphics->GetTextExtent(L"0-8: regurgitate", &wid, &hit);
        graphics->DrawText(L"0-8: regurgitate", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+130);


        graphics->GetTextExtent(L"B Headbutt", &wid, &hit);
        graphics->DrawText(L"B Headbutt", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+180);
    }
}

void LevelDisplay::Update(double time) {
    mTime = time;
}