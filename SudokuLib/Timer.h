/**
 * @file Timer.h
 * @author Nitin Polavarapu
 *
 * Class describing the timer object.
 */

#ifndef PROJECT1_335_SUDOKULIB_TIMER_H
#define PROJECT1_335_SUDOKULIB_TIMER_H
/**
 * Class describing the timer object.
 */
class Timer : public wxWindow
{
private:
    ///Current time of timer
    long mTime = 0;

public:
    Timer();
    void OnDraw(std::shared_ptr<wxGraphicsContext> gc);
    void Update(double Time); //Called in Game

    /** Resets the timer*/
    void ResetTimer() {mTime = 0;}
};

#endif //PROJECT1_335_SUDOKULIB_TIMER_H
