//
//  ECFlightItinerary.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <set>
using namespace std; 

//get initial time and find the difference between that and final arrival time 
// Get flight time: from departure to arrival
double ECFlightItinerary :: GetFlightTime() const
{
    
    double res = 0;
    for( auto x: flights)
    {
         
        res+= (x.GetArrivalTime() - x.GetDepartureTime());

    }
    
    return res;
    
    

}

void ECFlightItinerary :: Setflights(vector<ECFlight>& newFs)
{
    flights = newFs;

}

void ECFlightItinerary :: Addflights(const ECFlight& f) 
{
    flights.push_back(f);

}

void ECFlightItinerary :: RemLastF() 
{
    flights.pop_back();

}
    
// Get segment time: add the time of all segments
double  ECFlightItinerary :: GetTimeAllSegments() const
{
    double res = 0;
    if (!flights.empty()) { // Check if flights vector is not empty
        ECFlight firstFlight = flights[0];
        ECFlight lastFlight = flights[flights.size() - 1];
        res = lastFlight.GetDepartureTime() - firstFlight.GetDepartureTime();
        }
    
    return res;
    
}

string ECFlightItinerary :: Dump()const
{
    string info; 
    info = "Src: "+src+" Dest: "+dest+" DepartT: "+to_string(GetDepartTime())+" ArrivalT: "+to_string(GetArrivalTime()) +" Cost:"+to_string(GetPrice())+ " Segments:"+to_string(GetNumSegments())+ " Flight Time:"+to_string(GetFlightTime()); 
    // for( int i = 0; i < flights.size(); i++)
    // {
    //     info += "  "+flights[i].GetSource()+" Dest of flight: "+flights[i].GetDest()+" dep time "+to_string(flights[i].GetDepartureTime())+"-> ";
    //     // cout<<"Src of flight "<<flights[i].GetSource()<<" Dest of flight: "<<flights[i].GetDest()<<" dep time "<< flights[i].GetDepartureTime()<<endl;
    // }
    // cout<<endl<<"done"<<endl;
    return info;
}
    
// Get departure time
double ECFlightItinerary :: GetDepartTime() const
{ 
        return flights[0].GetDepartureTime();
}

// Get arrival time
double ECFlightItinerary :: GetArrivalTime() const
{
     
    return flights[flights.size()-1].GetArrivalTime();
}

// Price 
double ECFlightItinerary :: GetPrice() const
{
   return GetFlightTime()*120;

}