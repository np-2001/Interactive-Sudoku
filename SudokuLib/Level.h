/**
 * @file Level.h
 * @author Eliezer Amponsah
 *
 *
 */

#ifndef PROJECT1_335_SUDOKULIB_LEVEL_H
#define PROJECT1_335_SUDOKULIB_LEVEL_H
class Game;

class Level
{
private:
    /// Running Game to load this level on
    Game *mGame;
    wxString mLevel;

public:

    /// Default constructor (disabled)
    Level() = delete;
    
    /// Copy constructor (disabled)
    Level(const Level &) = delete;
    
    /// Assignment operator
    void operator=(const Level &) = delete;
    

    Level(Game *game) : mGame(game) {}

    void LoadLevel(std::shared_ptr<wxGraphicsContext>);


    /**
     *
     * @param filename
     */
    void SetLevel(wxString filename) {mLevel = filename; }

};

#endif //PROJECT1_335_SUDOKULIB_LEVEL_H
