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

    /// File name of curent level
    wxString mLevelFileName;

    /// Pointer to declaration class
    std::shared_ptr<Declaration> mDeclaration;

    void MakeDeclarations(wxXmlNode *node);
    void MakeItems(wxXmlNode *node);

    /// Int corresponding to current level
    int mLevelNumber;

public:

    /// Default constructor (disabled)
    Level() = delete;
    
    /// Copy constructor (disabled)
    Level(const Level &) = delete;
    
    /// Assignment operator
    void operator=(const Level &) = delete;

    Level(Game *game);

    void LoadLevel();

    /**
     * Getter for LevelFileName
     * @return mLevelFileName the file name of current level
     */
    wxString GetCurrentLevel() {return mLevelFileName; }

    /**
     *
     * @param filename The filename of the current level
     */
    void SetLevel(wxString filename) {mLevelFileName = filename; }

    /**
     * Getter for pointer to Declaration
     * @return mDeclaration pointer to declaration
     */
    const std::shared_ptr<Declaration> GetDeclaration()  const {return  mDeclaration; }

    void LoadSolve(wxXmlNode *node);
    void SolveLevel();

    ///Test will be fixed
    std::shared_ptr<LevelDisplay> mPopup = nullptr;

    /**
     * Getter for Level Number
     * @return
     */
    int GetLevelNumber () {
        return mLevelNumber;
    }
};

#endif //PROJECT1_335_SUDOKULIB_LEVEL_H
