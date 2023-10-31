/**
 * @file Level.h
 * @author Eliezer Amponsah, Finn Clark
 *
 * Class describing an individual level.
 */

#ifndef PROJECT1_335_SUDOKULIB_LEVEL_H
#define PROJECT1_335_SUDOKULIB_LEVEL_H

#include "Declaration.h"
#include "LevelDisplay.h"
#include <array>
class Game;
/**
 * Class describing an individual level.
 */
class Level
{
private:
    /// Running Game to load this level on
    Game *mGame;
    wxString mLevelFileName;
    std::shared_ptr<Declaration> mDeclaration;

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

    ///Test will be fixed
    std::shared_ptr<LevelDisplay> mPopup = nullptr;
};

#endif //PROJECT1_335_SUDOKULIB_LEVEL_H
