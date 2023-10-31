/**
 * @file Timer.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "Timer.h"

/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

/**
 * Top left corner of the scoreboard in virtual pixels
 * @return wxPoint point of scoreboard
 */
const wxPoint ScoreboardTopLeft(10, 10);

/// constant for the duration of the frame
const int FrameDuration = 30;

/*
 * Timer Constructor
 */
Timer::Timer()
{

}

void Timer::OnDraw(std::shared_ptr<wxGraphicsContext> graphics) {

    int seconds = mTime * 0.001;
    int minutes = seconds / 60;
    seconds = seconds % 60;
    wxString TimeString= wxString::Format(wxT("%02i:%02i"),minutes,seconds);
    wxFont bigFont(wxSize(0, 50),
                   wxFONTFAMILY_SWISS,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_BOLD);
    graphics->SetFont(bigFont, *wxWHITE);
    graphics->DrawText(TimeString,ScoreboardTopLeft.x,ScoreboardTopLeft.y);
}

void Timer::Update(double Time) {
    mTime = Time;
}


