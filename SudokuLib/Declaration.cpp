/**
 * @file Declaration.cpp
 * @author Eliezer Amponsah, Nitin Polavarapu, Samantha Wycoff, Sania Sinha, Finn Clark
 */

#include "pch.h"
#include "Declaration.h"

/**
 * Adds a pointer to the xml Node mapped to the id. Used to extract every attribute
 * @param id key
 * @param node xmlNode
 */
void Declaration::Add(wxString id, wxXmlNode *node)
{
    mDeclarations.insert({id, node});
}
