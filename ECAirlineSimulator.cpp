//
//  ECAirlineSimulator.cpp
//  
//
//  Created by Yufeng Wu on 5/17/23.
//

#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirport.h"
#include "ECFlight.h"
#include "ECFlightItinerary.h"

#include <iostream>
using namespace std;

//

void ECAirlineSimulator :: AddAirport(const std::string &name, const std::string &code)
{
    ECAirport newA(name, code);
    
    ECAirportInfo& AP = ECAirportInfo::Instance();
    
    AP.AddAirport(newA); 
    
    

}

void ECAirlineSimulator :: GetPassengerItineraries(vector<ECFlightItinerary>& PITS)
{
    PITS = pAirlineTicket->GetPassengerIts();
}

void ECAirlineSimulator :: Book()
{
    for(auto x: pAirlineTicket->GetPass())
    {
        SearchForFlights(x.GetSrcAirport(), x.GetDestAirport(), x.GetIts());
        x.Book(*pAirlineTicket);
    }
}
    
    // Setup distaince between airport; note distance is symmetric: the distance from dest to src is the same as from src to dest
void ECAirlineSimulator :: SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist)
{
    ECAirportInfo& AP = ECAirportInfo::Instance();

    AP.SetDistanceBtw(srcAirport, destAirport, dist);


}
// //0
// void ECAirlineSimulator:: PreferLowPrice()
// {
//     pAirlineTicket->GetPrefer().push_back(0);

// }

// //1
// void ECAirlineSimulator:: PreferEarlyArrival()
// {
//     pAirlineTicket->GetPrefer().push_back(1);

// }

// //2
// void ECAirlineSimulator:: PreferShortTime()
// {
//     pAirlineTicket->GetPrefer().push_back(2);

// }

// //3
// void ECAirlineSimulator::PreferSmallestSegments()
// {
//     pAirlineTicket->GetPrefer().push_back(3);
// }
    
    // Adding flights: src airport, dest airport, depart time, max number of passenger, operating cost
void ECAirlineSimulator :: AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate )
{
   
    
    pAirlineOp->AddFlight2(srcAirport, destAirport, tmDepart, maxPassengers);
    
}

void ECAirlineSimulator :: AddPassengerBudget(string s, string d, double x)
{
    ECPassengerBudget *newp =  new ECPassengerBudget(s, d, x);
    pAirlineTicket->AddToPass(*newp);

}
void ECAirlineSimulator :: AddPassengerBusiness(string s, string d, double x)
{
    ECPassengerBusiness *newp =  new ECPassengerBusiness(s, d, x);
    pAirlineTicket->AddToPass(*newp);
    
}
void ECAirlineSimulator :: AddPassengerComfort(string s, string d, double x, double y, int j)
{
    ECPassengerComfort *newp =  new ECPassengerComfort(s, d, x, y, j);
    pAirlineTicket->AddToPass(*newp);

}
    
    // Called to indicate no more flights to add
void ECAirlineSimulator :: DoneFlightAdding()
{

}
    

    // *****************************************************
    // Flight search
    
    // Searcch for flights; return all flights in listItineraries that go from src to dest

//account for when you travel back to an airport

void ECAirlineSimulator :: SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries ) const
{
    
    listItineraries.clear();
   
    listItineraries = pAirlineTicket->CreateIt(src, dest, pAirlineOp);

    
    pAirlineTicket->OrderItineraries(listItineraries);
    
    
}



void ECAirlineSimulator :: Init()
{
    pAirlineOp = new ECAirlineOperation;   
    pAirlineFin  = new ECAirlineFinancial ;
    pAirlineTicket  = new ECAirlineTicketing ;
}