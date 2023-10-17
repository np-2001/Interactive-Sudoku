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
    long mTime = 0;

public:
    Timer();
    void OnDraw(std::shared_ptr<wxGraphicsContext> gc);
    void Update(double Time); //Called in Game
};

#endif //PROJECT1_335_SUDOKULIB_TIMER_H
