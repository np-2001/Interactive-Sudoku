/**
 * @file Level.h
 * @author Eliezer Amponsah, Finn Clark
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_LEVEL_H
#define PROJECT1_335_SUDOKULIB_LEVEL_H

#include "Declaration.h"
#include "LevelDisplay.h"
class Game;

class Level
{
private:
    /// Running Game to load this level on
    Game *mGame;
    wxString mLevelFileName;
    std::shared_ptr<Declaration> mDeclaration;

    /// Solution of the game
    int mSolution[9][9];

    void MakeDeclarations(wxXmlNode *node);
    void MakeItems(wxXmlNode *node);


public:

    /// Default constructor (disabled)
    Level() = delete;
    
    /// Copy constructor (disabled)
    Level(const Level &) = delete;
    
    /// Assignment operator
    void operator=(const Level &) = delete;

    Level(Game *game);

    void LoadLevel();

    /** Returns the fileName for the Current Level */
    wxString GetCurrentLevel() {return mLevelFileName; }

    /**
     *
     * @param filename
     */
    void SetLevel(wxString filename) {mLevelFileName = filename; }

    /** Gets the Declaration for this level*/
    const std::shared_ptr<Declaration> GetDeclaration()  const {return  mDeclaration; }

    void LoadSolve(wxXmlNode *node);
    void SolveLevel();

    //std::shared_ptr<LevelDisplay> GetPopUp() {return mPopup;}
    ///Test will be fixed
    std::shared_ptr<LevelDisplay> mPopup = nullptr;

    void AddContainerChilderen(wxXmlNode *node);
};

#endif //PROJECT1_335_SUDOKULIB_LEVEL_H
