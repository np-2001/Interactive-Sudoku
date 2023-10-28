/**
 * @file FullPopUp.cpp
 * @author Samantha Wycoff
 */

#include "pch.h"
#include "FullPopUp.h"

FullPopUp::FullPopUp() {

}
FullPopUp::FullPopUp(wxString word) {
    mWord = word;
}
void FullPopUp::Draw(std::shared_ptr<wxGraphicsContext> graphics,int pixelHeight,int pixelWidth) {

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
        graphics->GetTextExtent(L"I'm Full!", &wid, &hit);
        graphics->DrawText(L"I'm Full!", pixelWidth/2 - wid/2, pixelHeight/2-rectangleHeight/2+80);
    }
}

void FullPopUp::Update(double time) {
    mTime = time;
}
