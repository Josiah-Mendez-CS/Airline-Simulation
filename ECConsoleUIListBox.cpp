//
//  ECConsoleUIListBox.cpp
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#include "ECConsoleUIListBox.h"
#include <iostream>

using namespace std;

 // Add a choice item
    void ECConsoleUIListBox :: AddChoice(const std::string &text)
    {
        window.push_back(text);
        items.push_back(text);
    }

    string ECConsoleUIListBox :: GetHiglightedItem()
    {
        return window[indexStart+CursorPos];
    }
     
    // Choose an item
    void ECConsoleUIListBox :: Choose(int rIndex)
    {
        // CurItem = items[rIndex];
        ChoiceIdx = rIndex;
        Choice = window[rIndex];

    }

    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    string  ECConsoleUIListBox :: GetTextAtRow(int r) const
    {
        // string strOut;
        //see if in list choices 
        if( r < GetYUL() || r > GetYLR())
        {
            return "";
        }
        //check if the text is within return substring

        if((window[indexStart+(r-GetYUL())].size() < GetWidth()) && (r-GetYUL() >= 0))
        {
            //chek if item is graeter than width
            return window[indexStart+(r-GetYUL())];
        }

        if((window[indexStart+(r-GetYUL())].size() > GetWidth()) && (r-GetYUL() >= 0))
        {
            //chek if item is graeter than width
            return window[indexStart+(r-GetYUL())].substr(0, GetWidth());
        }
        else
        {
            return "";

        }
    }

void ECConsoleUIListBox::HdlKeyUp() {
    if (CursorPos == 0) {
        // GetHighlightPosition(int &xLeft, int &xRight);
        return;
    }
    
    // If the cursor is at the start of the window, scroll up
    // if (CursorPos == indexStart) {
    //     indexStart = std::max(indexStart - 1, 0); // Ensure indexStart doesn't go below 0
    //     highlightPos = 2;
    //     // Update the window with the new items
    //     window.pop_back();
    //     window.insert(window.begin(), items[indexStart]);
    //     window[1] = items[indexStart + 1]; // Update middle item
    //     window[2] = items[indexStart + 2]; // Update last item
    //     CursorPos = indexStart+2;
    //     return;
    // }

    // if (highlightPos != 0)
    // {
    //     highlightPos--;
    // }

    CursorPos--; // Move the cursor up
    depth--;
     if (CursorPos < indexStart) {
        
        indexStart--; 
    }
}

void ECConsoleUIListBox::clear()
{
    window.clear();
    items.clear();
    highlightPos = 0; // Reset highlight position
    CursorPos = 0; // Reset cursor position
    indexStart = 0; // Reset index start
    depth = 0;

}

void ECConsoleUIListBox::HdlKeyDown() {
    // if (CursorPos == items.size() - 1) {
    //     return;
    // }
     if (CursorPos == window.size() - 1) {
        return;
    }
    
    // If the cursor is at the end of the window, scroll down
    // if ((CursorPos == indexStart + 2) && (indexStart != (items.size()) - 3) && (CursorPos != items.size() - 3)) 
    // {
    //     indexStart++; // Ensure indexStart doesn't exceed the bounds
    //     highlightPos = 0;
        
    //     std::cout << "indexStart after scrolling down: " << indexStart << std::endl;
    //     // Update the window with the new items
    //     window.erase(window.begin());
    //     window.push_back(items[indexStart + 2]);
    //     window[1] = items[indexStart + 1]; // Update middle item
    //     window[0] = items[indexStart];     // Update first item
    //     CursorPos = indexStart;
    //     return;
    // }
    
    // if (CursorPos != items.size()-1)
    // {
    //      if (highlightPos != 2)
    //     {
    //         highlightPos++;
    //     }
    //     CursorPos++; // Move the cursor down
    // }
    if (depth < GetYLR()-GetYUL())
    {
        depth++;
        CursorPos++; // Move the cursor down
    }
    
    // Update the visible range if necessary
    if (CursorPos >= (indexStart+(GetYLR()-GetYUL()))) 
    {
        depth = 0;
        CursorPos =-indexStart;
        indexStart++;
    }
}

void ECConsoleUIListBox :: SetItems(vector<string> newItems)
{
    items = newItems;
    window = newItems;
}
   
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    //when the size is 0 check

    int  ECConsoleUIListBox :: GetHighlightPosition(int &xLeft, int &xRight) const
    {
       if(window.size() == 0)
       {
        return -1;
       }
        xLeft = 0;
        xRight = GetWidth()-1;
        // return highlightPos;
        return CursorPos;

    }
