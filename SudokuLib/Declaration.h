/**
 * @file Declaration.h
 * @author Sania Sinha
 *
 * Class describing declarations in a game
 */

#ifndef PROJECT1_335_SUDOKULIB_DECLARATION_H
#define PROJECT1_335_SUDOKULIB_DECLARATION_H

#include <map>
#include <wx/xml/xml.h>

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

    /// Map of ids to XmlNode for the declarations section
    std::map<wxString, wxXmlNode* > mDeclarations;

    /// Map of ids to images for each id
    std::map<wxString, std::shared_ptr<wxImage>> mImages;

public:
    /// Default constructor (disabled)
    Declaration() = delete;

    /// Copy constructor (disabled)
    Declaration(const Declaration &) = delete;

    /// Assignment operator
    void operator=(const Declaration &) = delete;

    Declaration(int hit, int wid);

    void Add(wxString id, wxXmlNode *node);

    /** Returns the ids to images of this level */
    wxXmlNode *GetDeclaration(const wxString& id) const {return mDeclarations.at(id); }

    /** Adds image to declarations so we don't have to load multiple
     *
     * @param id id to map to the image
     * @param image image to contain
     */
    void AddImage(const wxString& id, std::shared_ptr<wxImage> image) {mImages[id] = image; }

    /**
     * Gets the image associated with id (returns nullptr if None)
     * @param id id associated with this image
     * @return ptr to associated image
     */
    std::shared_ptr<wxImage> GetImage(const wxString& id) {return mImages[id]; }



};

#endif //PROJECT1_335_SUDOKULIB_DECLARATION_H
