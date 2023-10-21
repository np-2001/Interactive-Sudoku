/**
 * @file MainFrame.h
 * @authors Nitin Polavarapu, Eliezer Amponsah, Samantha Wycoff
 *
 * The top level (main) frame of the application
 */

#ifndef PROJECT1_SUDOKULIB_MAINFRAME_H
#define PROJECT1_SUDOKULIB_MAINFRAME_H

class GameView;

class MainFrame : public wxFrame
{
private:
    /// pointer to GameView class
    GameView* mGameView = nullptr;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnCredits(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

public:
    void Initialize();

};

#endif //PROJECT1_SUDOKULIB_MAINFRAME_H
