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
void LevelDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics) {

    if (mTime*0.001 <= 3) {
        wxFont bigFont(wxSize(0, 50),
                       wxFONTFAMILY_SWISS,
                       wxFONTSTYLE_NORMAL,
                       wxFONTWEIGHT_BOLD);
        graphics->SetFont(bigFont, *wxBLACK);
        graphics->DrawText(mWord,200,200);
    }
}

void LevelDisplay::Update(double elapsed) {
    mTime = mTime + (elapsed*1000);
}