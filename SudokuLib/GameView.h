/**
 * @file GameView.h
 * @author Nitin Polavarapu, Samantha Wycoff
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_GAMEVIEW_H
#define PROJECT1_335_SUDOKULIB_GAMEVIEW_H

#include "Game.h"
#include "Timer.h"


class GameView : public wxWindow
{
private:
    /// The timer that allows for animation
    wxTimer mTimer;
    void OnTimer(wxTimerEvent& event);

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    /// Object that describes the game
    Game mGame;


    void OnPaint(wxPaintEvent& event);
    void OnLeftDown(wxMouseEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnLoadLevel1(wxCommandEvent& event);
    void OnLoadLevel2(wxCommandEvent& event);
    void OnLoadLevel3(wxCommandEvent& event);

public:
    void Initialize(wxFrame* parent);

    void SetTime(long Time) { mTime = Time;}
    void StartNewLevel(wxString levelFile);
};

#endif //PROJECT1_335_SUDOKULIB_GAMEVIEW_H
