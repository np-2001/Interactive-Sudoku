/**
 * @file Declaration.h
 * @author Sania Sinha
 *
 * Class describing declarations in a game
 */

#ifndef PROJECT1_335_SUDOKULIB_DECLARATION_H
#define PROJECT1_335_SUDOKULIB_DECLARATION_H

#include <map>

/**
 * Class describing declarations in a game
 */
class Declaration
{
private:
    /// Height of screen
    int mHeight;
    /// Width of screen
    int mWidth;

    /// Map of ids to images
    std::map<wxString, std::shared_ptr<wxImage>> mDeclarations;

public:
    /// Default constructor (disabled)
    Declaration() = delete;

    /// Copy constructor (disabled)
    Declaration(const Declaration &) = delete;

    /// Assignment operator
    void operator=(const Declaration &) = delete;

    Declaration(int hit, int wid);
    void Add(wxString id, const std::wstring &imageFile);

    /** Returns the ids to images of this level */
    std::map<wxString, std::shared_ptr<wxImage>> GetDeclarations() {return mDeclarations; }



};

#endif //PROJECT1_335_SUDOKULIB_DECLARATION_H
