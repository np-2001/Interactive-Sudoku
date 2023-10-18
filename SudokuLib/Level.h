/**
 * @file Level.h
 * @author Eliezer Amponsah
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_LEVEL_H
#define PROJECT1_335_SUDOKULIB_LEVEL_H

#include "Declaration.h"
class Game;

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

    Level(Game *game, wxString level);

    void LoadLevel();


    /**
     *
     * @param filename
     */
    void SetLevel(wxString filename) {mLevelFileName = filename; }


};

#endif //PROJECT1_335_SUDOKULIB_LEVEL_H
