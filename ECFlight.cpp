//
//  ECFlight.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlight.h"
#include "ECAirport.h"

#include <iostream>
using namespace std;

void ECFlight :: SetMaxNumPassengers(int m)
{
    MaxNumP = m;
}

double ECFlight :: GetArrivalTime()const
{
    ECAirportInfo& AInfo = ECAirportInfo::Instance();
    int dist = AInfo.ReturnDist(src, dest);
    return (GetDepartureTime() + (static_cast<double>(dist)/500));
}
//observe airports
void ECFlight :: AddRes()
{
    if (numOfRes == MaxNumP)
    {
        cout<<"flight full"<<endl;
        return; 
    }
    numOfRes++;
}

int ECFlight:: FlightDist()
{   
    ECAirportInfo& AInfo = ECAirportInfo::Instance();
    return AInfo.ReturnDist(src, dest);

}

bool ECFlight :: IsFull()
{
    if (numOfRes == MaxNumP)
    {
        return true;
    }
    return false;
}

int ECFlight :: GetFlightTime()
{
    return GetArrivalTime() - GetDepartureTime();
}

