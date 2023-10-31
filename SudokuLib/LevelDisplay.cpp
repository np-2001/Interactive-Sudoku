/**
 * @file LevelDisplay.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "LevelDisplay.h"
LevelDisplay::LevelDisplay() {

}
LevelDisplay::LevelDisplay(wxString word, int level) {
    mWord = word;
    mLevel = level;
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
        graphics->GetTextExtent(L"space: Eat", &wid, &hit);
        graphics->DrawText(L"space: Eat", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+80);

        graphics->GetTextExtent(L"0-8: Regurgitate", &wid, &hit);
        graphics->DrawText(L"0-8: Regurgitate", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+130);


        graphics->GetTextExtent(L"B: Headbutt", &wid, &hit);
        graphics->DrawText(L"B: Headbutt", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+180);

        if (mLevel == 3) {
            wxFont smallerFont(wxSize(0, 20),
                             wxFONTFAMILY_SWISS,
                             wxFONTSTYLE_NORMAL,
                             wxFONTWEIGHT_BOLD);
            graphics->SetFont(smallerFont, *wxBLACK);
            graphics->GetTextExtent(L"Level 3 Feature: Throwup every 15 seconds after eating", &wid, &hit);
            graphics->DrawText(L"Level 3 Feature: Throwup every 15 seconds after eating", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+230);
        }
    }
}

void LevelDisplay::Update(double time) {
    mTime = time;
}