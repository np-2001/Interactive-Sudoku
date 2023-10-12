/**
 * @file SudokuApp.h
 * @author laptop
 *
 *
 */

#ifndef PROJECT1_335__SUDOKUAPP_H
#define PROJECT1_335__SUDOKUAPP_H

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif

/**
 * Main application class
 */
class SudokuApp : public wxApp
{
private:

public:
    bool OnInit() override;

};

#endif //PROJECT1_335__SUDOKUAPP_H
