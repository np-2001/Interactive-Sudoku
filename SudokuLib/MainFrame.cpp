/**
 * @file MainFrame.cpp
 * @authors Nitin Polavarapu, Eliezer Amponsah, Samantha Wycoff, Finn Clark
 */

#include "pch.h"
#include "MainFrame.h"
#include "ids.h"
#include "GameView.h"

/**
 * Initialize the MainFrame window
 */
void MainFrame::Initialize()
{
    // We need to modify the size of the window
    Create(nullptr, wxID_ANY, L"Action Sudoku",
           wxDefaultPosition, wxSize(1000, 800));


    mGameView = new GameView();
    mGameView->Initialize(this);

    // Main Menu Bar container
    auto menuBar = new wxMenuBar();

    // Main Menu options
    auto levelMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    menuBar->Append(levelMenu, L"&Level");
    menuBar->Append(helpMenu, L"&Help");

    // Level Submenu
    levelMenu->Append(IDM_LEVEL_0, L"&Level 0", "Load level 0");
    levelMenu->Append(IDM_LEVEL_1, L"&Level 1", "Load level 1");
    levelMenu->Append(IDM_LEVEL_2, L"&Level 2", "Load level 2");
    levelMenu->Append(IDM_LEVEL_3, L"&Level 3", "Load level 3");
    levelMenu->AppendSeparator();
    levelMenu->Append(IDM_SOLVE_LEVEL, L"&Solve Level", "Solve Current Level");
    levelMenu->AppendSeparator();
    levelMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");

    // Help Submenu
    helpMenu->Append(wxID_ABOUT, "&Instructions\tF1", L"How to play");
    helpMenu->Append(IDM_CREDITS, L"&Credits");

    SetMenuBar(menuBar);
    CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

    // Bindings
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnCredits, this, IDM_CREDITS);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

}

/**
 * Exit menu option handlers
 * @param event Event being received
 */
void MainFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

/**
 * Brings a pop up about the program and how to play the game
 * @param event Event being received
 */
void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(L"Lorem Ipsum! (Replace this text with tutorial probably)",
                 L"About Aquarium",
                 wxOK,
                 this);
}

/**
 * Brings up a menu for the creators (It's a nice touch...)
 * @param event Event being received
 */
void MainFrame::OnCredits(wxCommandEvent &event)
{
    wxMessageBox(L"CREDITS:\n\n\tFinn Clark\n\tSanya Sinha\n\tSam Wycoff\n"
                 "\tNitin Polavarapu\n\tEliezer Amponsah",
                 L"Credits",
                 wxOK,
                 this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}
