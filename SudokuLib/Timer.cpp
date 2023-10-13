/**
 * @file Timer.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "Timer.h"

/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

/// Top left corner of the scoreboard in virtual pixels
const wxPoint ScoreboardTopLeft(10, 10);

const int FrameDuration = 30;

/*
 * Timer Constructor
 */
Timer::Timer() {
}

void Timer::OnDraw(std::shared_ptr<wxGraphicsContext> graphics) {

    int newTime = mTime * 0.001;

    wxString TimeString= wxString::Format(wxT("%i"),newTime);
    wxFont bigFont(wxSize(0, 50),
                   wxFONTFAMILY_SWISS,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_BOLD);
    graphics->SetFont(bigFont, wxColour(255, 0, 255));
    graphics->DrawText(TimeString,ScoreboardTopLeft.x,ScoreboardTopLeft.y);
}

void Timer::Update(double Time) {
    mTime = Time;
}