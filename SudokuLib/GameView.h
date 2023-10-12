/**
 * @file GameView.h
 * @author Nitin Polavarapu
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_GAMEVIEW_H
#define PROJECT1_335_SUDOKULIB_GAMEVIEW_H

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

public:
    void Initialize(wxFrame* parent);

};

#endif //PROJECT1_335_SUDOKULIB_GAMEVIEW_H
