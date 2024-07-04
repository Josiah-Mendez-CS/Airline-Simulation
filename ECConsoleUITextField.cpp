//
//  ECConsoleUITextField.cpp
//  
//
//  Created by Yufeng Wu on 5/24/23.
//

#include "ECConsoleUITextField.h"
#include "ECTextViewImp.h"
#include <string>

using namespace std;

std::string ECConsoleUITextField :: GetTextAtRow(int r) const
{
     if( r < GetYUL() || r > GetYLR())
        {
            return "";
        }
        //check if the text is within return substring

        if((text.size() < GetWidth()) && (r-GetYUL() >= 0))
        {
            //chek if item is graeter than width
            return text;
        }

        if((text.size() > GetWidth()) && (r-GetYUL() >= 0))
        {
            //chek if item is graeter than width
            return text.substr(0, GetWidth());
        }
        else
        {
            return "Name is too long";
        }
}
    
// Get highlighted part (if any); return the row with highlight
// if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
// Assume: at most a single row with highlighted part
int ECConsoleUITextField :: GetHighlightPosition(int &xLeft, int &xRight) const
{
     if(text.size() == 0)
       {
        return -1;
       }
        xLeft = 0;
        xRight = GetWidth()-1;
        
        return y;
        

}

void ECConsoleUITextField :: HdlOtherKey() 
{
    int key = view->GetPressedKey();
    if (edit == true)
    {
        if(key == 3)
        {
            edit == false;
        }
        else if (key ==  127 || key ==  DEL_KEY)
        {
            if (text.size() != 0)
                text.pop_back();
        }
        else
        {
            if (text.size() < GetWidth())
                text += key;
        }
    }

}
// Are there any other function you might need to override?
// Handle enter key
void ECConsoleUITextField :: HdlKeyEnter()
{
    edit = true;
}