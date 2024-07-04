//
//  ECAirlineOperation.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//  About operation of an airline: especially flights management

#ifndef ECAirlineOperation_h
#define ECAirlineOperation_h
#include <vector> 
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"
#include "ECFlight.h"
#include <map>

// put your code about airline operation here...
class ECAirlineOperation 
{
public:
    ECAirlineOperation()
    {
    }
    virtual ~ECAirlineOperation()
    {
    }
   
   void AddFlight2(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers);

   void Dump();

  vector <ECFlight>& listOfFlights();
  map <string, vector<ECFlight> >& AJSet();

private:
    // your code
    map <string, vector<ECFlight> > AdjFlights;
    vector <ECFlight> Sflights;
    
 
    //list of flights scheduled to occur beased on what has been booked


};



#endif
 