/**
 * @file MainFrame.h
 * @authors Nitin Polavarapu, Eliezer Amponsah
 *
 * The top level (main) frame of the application
 */

#ifndef PROJECT1_SUDOKULIB_MAINFRAME_H
#define PROJECT1_SUDOKULIB_MAINFRAME_H

class MainFrame : public wxFrame
{
private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnCredits(wxCommandEvent& event);

public:
    void Initialize();

};

#endif //PROJECT1_SUDOKULIB_MAINFRAME_H
