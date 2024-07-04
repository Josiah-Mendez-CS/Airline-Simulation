//
//  ECAirlineOperation.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//
 
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"
#include "ECFlight.h"

#include <iostream>  
#include <string>
using namespace std;

void ECAirlineOperation :: AddFlight2(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers)
{
    ECFlight newf(srcAirport, destAirport, tmDepart, maxPassengers);
    
    AdjFlights[srcAirport].push_back(newf);
    Sflights.push_back(newf);
  
} 

map <string, vector<ECFlight> >& ECAirlineOperation :: AJSet()
{
    return AdjFlights;
}


vector <ECFlight>& ECAirlineOperation :: listOfFlights()
{
    return Sflights;
}

void ECAirlineOperation :: Dump()
{
    for(auto x : AdjFlights)
    {
        cout<<"flights from"<< x.first<<" to:" <<endl;
        for (auto y : x.second)
        {
            cout<< y.GetDest()<<endl;
        }

    }
}


