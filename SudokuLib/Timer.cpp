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
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}
void Timer::OnDraw(wxGraphicsContext *dc) {
    auto newTime = mStopWatch.Time();
    newTime = newTime * 0.001;
    wxString TimeString= wxString::Format(wxT("%i"),newTime);
    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font,*wxBLACK);
    dc->DrawText(TimeString,ScoreboardTopLeft.x,ScoreboardTopLeft.y);
}