/**
 * @file SudokuApp.cpp
 * @author Eliezer Amponsah
 */

#include <pch.h>
#include "SudokuApp.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return Boolean representing sucessful initialization
 */
bool SudokuApp::OnInit()
{
#ifdef WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}