/**
 * @file GameView.cpp
 * @author Nitin Polavarapu
 */

#include "pch.h"
#include "GameView.h"

/// Frame duration in milliseconds
const int FrameDuration = 30;


/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame *parent) {


    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}


/**
 * Timer event, refreshes the window
 * @param event Timer event object
 */

void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}
