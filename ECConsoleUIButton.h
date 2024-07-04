//
//  ECConsoleUIButton.h
//  
//
//  Created by Yufeng Wu on 3/6/24.
//

#ifndef ECConsoleUIButton_h
#define ECConsoleUIButton_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"

#include "ECConsoleUIView.h"
#include "ECConsoleUIListBox.h"

#include "ECAirport.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirlineSimulator.h"
using namespace std;

//*****************************************************************************
// Console UI button: with a text and can be clicked

class ECConsoleUIButton : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this button and the text
    ECConsoleUIButton(int xUL, int yUL, int xLR, int yLR, const std::string &textButton );

    // Get position info
    virtual int GetYUL() const { return ECConsoleUIItem::GetYUL()-1; }
    virtual int GetYLR() const { return ECConsoleUIItem::GetYLR()+1; }
    virtual int GetHeight() const { return GetYLR()-GetYUL()+1; }

    // Get displayed text at a specific row (absolute row in the screen/view sense; not specific to the item)
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const;

    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const;
    
    // Handle up key
    // Is responding to keys? YES: button handles keys!
    virtual bool IsHandlingKeys() const { return true; }
    // Handle enter key
    virtual void HdlKeyEnter();
    
private:
    std::string strButton;
};

class SearchFlights : public ECConsoleUIButton
{
    
    public:
        SearchFlights(int xUL, int yUL, int xLR, int yLR, const std::string &textButton, ECAirlineSimulator &S, ECConsoleUIView &v, ECConsoleUIListBox &ss,  ECConsoleUIListBox &ds, ECConsoleUIListBox &Fs, vector<ECFlightItinerary> &LI): ECConsoleUIButton(xUL, yUL, xLR, yLR, textButton), sim(S), view(v), srcs(ss), dests(ds), Flights(Fs), itins(LI){}
        void HdlKeyEnter();
        

    private:
        ECAirlineSimulator sim;    
        ECConsoleUIView view;
        ECConsoleUIListBox &srcs;
        ECConsoleUIListBox &dests;
        ECConsoleUIListBox &Flights;
        vector<ECFlightItinerary> &itins;

};
#endif /* ECConsoleUIButton_h */
