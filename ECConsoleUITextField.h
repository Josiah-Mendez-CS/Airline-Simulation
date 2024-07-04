//
//  ECConsoleUITextField.h
//  
//
//  Created by Yufeng Wu on 5/24/23.
//

#ifndef ECConsoleUITextField_h
#define ECConsoleUITextField_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"
#include "ECTextViewImp.h"
using namespace std;
class ECTextViewImp;


//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUITextField : public ECConsoleUIItem
{
public:
    // specifiy the starting point of the text field
    ECConsoleUITextField(ECTextViewImp *pTextView, int xpos, int ypos, int len): ECConsoleUIItem(xpos, ypos, xpos+len+1, ypos), x(xpos), y(ypos), width(len), view(pTextView){}
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    std::string GetTextAtRow(int r) const;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    int GetHighlightPosition(int &xLeft, int &xRight) const;

    // Are there any other function you might need to override?
     // Handle enter key
    void HdlKeyEnter();

    bool IsHandlingKeys() const {return true;}

    void HdlOtherKey();
    
private:
 ECTextViewImp *view;
 int x;
 int y;
 int width;
 string text;
 int highlightpos = y+1;
 bool edit = false;
};

#endif /* ECConsoleUITextField_h */
