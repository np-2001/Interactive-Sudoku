/**
 * @file GameView.cpp
 * @author Nitin Polavarapu, Samantha Wycoff
 */

#include "pch.h"
#include "GameView.h"
#include "Game.h"
#include "ids.h"
#include <wx/dcbuffer.h>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;


/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame *parent) {

    Create(parent, wxID_ANY,
           wxDefaultPosition, wxDefaultSize,
           wxFULL_REPAINT_ON_RESIZE);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc =
        std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}


/**
 * Timer event, refreshes the window
 * @param event Timer event object
 */

void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}

/**
 * Handle the left mouse button down event
 * @param event The mouse click event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
    mGame.OnLeftDown(event.GetX(), event.GetY());
}
