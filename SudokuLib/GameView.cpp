/**
 * @file GameView.cpp
 * @author Nitin Polavarapu, Samantha Wycoff, Finn Clark
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "GameView.h"
#include "Game.h"
#include "ids.h"
#include "Sparty.h"


using namespace std;

/// Starting Level for initialisation
wxString initLevel = L"Levels/level1.xml";

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Image for sparty's head
const wstring SpartyHeadImageName = L"images/sparty-1.png";

/// Image for sparty's chin
const wstring SpartyChinImageName = L"images/sparty-2.png";

/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame *parent) {

    Create(parent, wxID_ANY,
           wxDefaultPosition, wxDefaultSize,
           wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    Bind(wxEVT_TIMER,&GameView::OnTimer,this);

    // Level Bindings
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel0, this, IDM_LEVEL_0);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel1, this, IDM_LEVEL_1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel2, this, IDM_LEVEL_2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel3, this, IDM_LEVEL_3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnSolveLevel, this, IDM_SOLVE_LEVEL);

    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyDown, this);

//    std::shared_ptr<wxImage> mItemImage = std::make_shared<wxImage>(SpartyHeadImageName, wxBITMAP_TYPE_ANY);
//    std::shared_ptr<Sparty> sparty = std::make_shared<Sparty>(&mGame,mItemImage);
//    mGame.Add(sparty);
//    mGame.mSparty = sparty;
//
//    std::shared_ptr<wxImage> mItemChinImage = std::make_shared<wxImage>(SpartyChinImageName, wxBITMAP_TYPE_ANY);
//    std::shared_ptr<SpartyChin> spartyChin = std::make_shared<SpartyChin>(&mGame,mItemChinImage);
//    mGame.Add(sparty);
//    mGame.mSparty = sparty;
//
//    mGame.Add(spartyChin);
//    mGame.mSpartyChin = spartyChin;

    mGame.GetLevel()->SetLevel(initLevel);
    mGame.GetLevel()->LoadLevel();
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
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mGame.Update(elapsed);
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));


    // Tell the game class to draw
//    wxSize size = GetClientSize();
    wxRect size = GetRect();
    mGame.OnDraw(gc, size.GetWidth(), size.GetHeight());
    auto level = mGame.GetLevel()->GetCurrentLevel();
    if (mGame.GetNext() == true) {
        if (level == "Levels/level3.xml") {
            StartNewLevel(L"Levels/level3.xml");
        } else if (level == "Levels/level2.xml") {
            StartNewLevel(L"Levels/level3.xml");
        } else if (level == "Levels/level1.xml") {
            StartNewLevel(L"Levels/level2.xml");
        } else {
            StartNewLevel(L"Levels/level1.xml");
        }

        mGame.SetNext(false);
    } else if (mGame.GetCurrent() == true) {
        StartNewLevel(level);
        mGame.SetCurrent(false);
    }


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

/**
 * Handler to solve level on button click
 * @param event event to handle
 */
void GameView::OnSolveLevel(wxCommandEvent &event)
{
    mGame.GetLevel()->SolveLevel();
}

/**
 * Handler to load level 0 on button click
 * @param event event to handle
 */
void GameView::OnLoadLevel0(wxCommandEvent &event)
{
    StartNewLevel(L"Levels/level0.xml");
}


/**
 * Handler to load level 1 on button click
 * @param event event to handle
 */
void GameView::OnLoadLevel1(wxCommandEvent &event)
{
    StartNewLevel(L"Levels/level1.xml");
}

/**
 * Handler to load level 2 on button click
 * @param event event to handle
 */
void GameView::OnLoadLevel2(wxCommandEvent &event)
{
    StartNewLevel(L"Levels/level2.xml");
}

/**
 * Handler to load level 3 on button click
 * @param event event to handle
 */
void GameView::OnLoadLevel3(wxCommandEvent &event)
{
    StartNewLevel(L"Levels/level3.xml");
}

/**
 * Handle the key  down event.
 * @param event The key down event
 */
void GameView::OnKeyDown(wxKeyEvent &event)
{
   mGame.OnKeyDown(event);
   Refresh();
}

/**
 * Loads the level with the specified fileName
 * @param levelFile
 */
void GameView::StartNewLevel(wxString levelFile)
{
    // Clear Game's Items
    mGame.Clear();

    mGame.ResetTime();
    mTime = mStopWatch.Time();
    mTimer.Start();

    // Set and Start the new level
    mGame.GetLevel()->SetLevel(levelFile);
    mGame.GetLevel()->LoadLevel();
    // Reset Timer
    //mStopWatch.Start();


    //Refresh();
}
