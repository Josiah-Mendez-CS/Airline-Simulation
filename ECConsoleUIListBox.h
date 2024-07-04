//
//  ECConsoleUIListBox.h
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#ifndef ECConsoleUIListBox_h
#define ECConsoleUIListBox_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"
#include <vector>
using namespace std;

//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUIListBox : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this list box
    ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR ) : ECConsoleUIItem(xUL, yUL, xLR, yLR){}
    
    // Add a choice item
    void AddChoice(const std::string &text);
    
    // Choose an item
    void Choose(int rIndex);
    
    // Get the chosen one
    int GetChoice() const {return ChoiceIdx;}
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight)const;

    void SetHighlight(bool f) { fHighlight = f; }
    
    virtual bool IsHandlingKeys() const { return true; }

    string GetHiglightedItem();

    void SetItems(vector<string> newItems);

    // Are there any other function you might need to override?

     // Handle up key
    virtual void HdlKeyUp();
    // Handle down key
    virtual void HdlKeyDown();
   
   void clear();
    
    
private:
vector<string> items;
vector<string> window;
string Choice;
int ChoiceIdx;
bool fHighlight;
int indexStart = 0;
int CursorPos = 0;
int indexEnd = 2;
int highlightPos = 0;
int depth = 0;
// string CurItem;
};

#endif /* ECConsoleUIListBox_h */