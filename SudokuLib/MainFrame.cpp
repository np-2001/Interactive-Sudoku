/**
 * @file MainFrame.cpp
 * @authors Nitin Polavarapu, Eliezer Amponsah
 */

#include "pch.h"
#include "MainFrame.h"
#include "ids.h"

/**
 * Initialize the MainFrame window
 */
void MainFrame::Initialize()
{
    // We need to modify the size of the window
    Create(nullptr, wxID_ANY, L"Action Sudoku",
           wxDefaultPosition, wxSize(1000, 800));


    // Main Menu Bar container
    auto menuBar = new wxMenuBar();

    // Main Menu options
    auto levelMenu = new wxMenu();
    auto solveMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    menuBar->Append(levelMenu, L"&Level");
    menuBar->Append(helpMenu, L"&Help");

    // Sub Level Options
    auto level1 = new wxMenu();
    auto level2 = new wxMenu();
    auto level3 = new wxMenu();

    levelMenu->Append(IDM_LEVEL1, L"&Level 1", "Load level 1");
    levelMenu->Append(IDM_LEVEL_2, L"&Level 2", "Load level 2");
    levelMenu->Append(IDM_LEVEL_3, L"&Level 3", "Load level 3");
    levelMenu->AppendSeparator();
    levelMenu->Append(IDM_SOLVE_LEVEL, L"&Solve Level", "Solve Current Level");

    SetMenuBar(menuBar);
    CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

}

