/**
 * @file Timer.h
 * @author Nitin Polavarapu
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_TIMER_H
#define PROJECT1_335_SUDOKULIB_TIMER_H

class Timer : public wxWindow
{
private:
    /// The timer that allows for animation
    wxTimer mTimer;
    long mTime = 0;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

public:
    Timer();
    void OnDraw(wxGraphicsContext *dc);
};

#endif //PROJECT1_335_SUDOKULIB_TIMER_H
