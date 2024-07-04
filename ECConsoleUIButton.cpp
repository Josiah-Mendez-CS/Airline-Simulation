//
//  ECConsoleUIButton.cpp
//  
//
//  Created by Yufeng Wu on 3/6/24.
//

#include "ECConsoleUIButton.h"
#include "ECConsoleUIListBox.h"
#include "ECAirport.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirlineSimulator.h"

//*****************************************************************************
// Console UI button: 

// specifiy the portion of the view for this list box
ECConsoleUIButton :: ECConsoleUIButton(int xUL, int yUL, int xLR, int yLR, const std::string &strButIn ) : ECConsoleUIItem(xUL, yUL, xLR, yLR), strButton(strButIn)
{
}

// Get displayed text at a specific row
// Text is relative to the item portion (i.e., relative to (xLR, yLR))
std::string ECConsoleUIButton :: GetTextAtRow(int r) const
{
    // there is only one line
    std::string str;
    int rconv = r - GetYUL();

    if( rconv <0 || /*rconv >= 1 ||*/ rconv >= GetHeight() )
    {
        return str;
    }

    // add a row of '----' right above/below
    if( rconv == 0 || rconv == GetHeight()-1 )
    {
        str += '+';
        for( int i=1 ; i<GetWidth() - 1; ++i)
        {
            str += '-';
        }
        str += '+';
    }
    else
    {
        // begin with a '|'
        //str += '|';

        // align to the center
        if( strButton.size() < GetWidth())
        {
            str += '|';
            for(int i=1; i < (GetWidth()- strButton.size())/2; ++i )
            {
                str += ' ';
            }
        }

        str += strButton;
        for(int i=1; i < (GetWidth()- strButton.size())/2; ++i )
            {
                str += ' ';
            }
            str += '|';

        // end with a '|'
        //str += '|';
    }

    // ensure the str is not too long
    str = str.substr(0, GetWidth());
    return str;
}

// Get highlighted part (if any); return the row with highlight
// if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
// Assume: at most a single row with highlighted part
int ECConsoleUIButton :: GetHighlightPosition(int &xLeft, int &xRight) const
{
    return -1;
}

// Handle enter key
void ECConsoleUIButton :: HdlKeyEnter()
{
    // do nohting for now
}

void SearchFlights :: HdlKeyEnter()
{
    Flights.clear();
    Flights.AddChoice("-----------");
    vector<string> info;
    bool found = false;
    // info.push_back("Flights: ");
    info.push_back("");
    itins.clear();
     for (auto x : sim.GetAirlineOp()->AJSet()[srcs.GetHiglightedItem()])
     {
        if (x.GetDest() == dests.GetHiglightedItem())
        {
            found == true;
            break;
        }
     }
    
    if (found == false)
    {
       
        Flights.AddChoice("There are no flights");
        Flights.AddChoice("Sorry");
        
    }
    Flights.clear(); 
    sim.SearchForFlights(srcs.GetHiglightedItem(), dests.GetHiglightedItem(), itins);
    if (itins.size() >0)
    {
        for(ECFlightItinerary x: itins)
        {
            
            // if (x.GetNumSegments() == 0)
            // {

            //     Flights.AddChoice("Hi");
            //     continue;
            // }

            info.push_back(x.Dump());
            // Flights.AddChoice(x.Dump());
            
        
        }
        // Flights.AddChoice(to_string(itins.size()));
    }
    Flights.SetItems(info);
    //flightListBox->AddChoice("hi");

    view.Refresh();


}


