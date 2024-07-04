//
//  ECPassenger.cpp
//  
//
//  Created by Yufeng Wu on 5/15/23.
//

#include "ECPassenger.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlight.h"

#include <vector>
#include <iostream>
using namespace std; 

bool ECPassenger :: Book(ECAirlineTicketing &airlineTicketing)
{
    int ind;
    bool found = false;
    
    for (int i = 0; i < PossIts.size(); i++)
    {
        for(int j = 0; j < PossIts[i].Getflights().size(); j++)
        {
            if(PossIts[i].Getflights()[j].IsFull() == false)
            {
                break;
            }
            if(j == PossIts[i].Getflights().size()-1)
            {
                found = true;
            }
        }
        if (found = true)
        {
            ind = i;
            break;
        }
    }
    if (found == true)
    {
        itin.Setflights(PossIts[ind].Getflights());

        for(int k = 0; k < PossIts[ind].Getflights().size(); k++)
        {
            itin.Getflights()[k].AddRes();
        }

        status = EC_PASSENGER_BOOKED;
        return true;    
    }
    return false;
}

void ECPassenger :: SetStatus(EC_PASSENGER_STATUS newS)
{
    status = newS;
    
}

bool ECPassengerBudget :: Book(ECAirlineTicketing &airlineTicketing)
{
    int ind;
    bool found = false;
    for (int i = 0; i < GetIts().size(); i++)
    {
        if (GetIts()[i].GetPrice() > budget)
        {
            continue;
        }
        for(int j = 0; j < GetIts()[i].Getflights().size(); j++)
        {
            if(GetIts()[i].Getflights()[j].IsFull() == false)
            {
                break;
            }
            if(j == GetIts()[i].Getflights().size()-1)
            {
                found = true;
            }
        }
        if (found = true)
        {
            ind = i;
            break;
        }
    }
    if (found == true)
    {
        GetItin().Setflights(GetIts()[ind].Getflights());

        for(int k = 0; k < GetIts()[ind].Getflights().size(); k++)
        {
            GetItin().Getflights()[k].AddRes();
        }

        SetStatus(EC_PASSENGER_BOOKED);
        return true;    
    }
    return false;
}

bool ECPassengerBusiness :: Book(ECAirlineTicketing &airlineTicketing)
{
     int ind;
    bool found = false;
    for (int i = 0; i < GetIts().size(); i++)
    {
        if (GetIts()[i].GetArrivalTime() > ArriveLatest)
        {
            continue;
        }
        for(int j = 0; j < GetIts()[i].Getflights().size(); j++)
        {
            if(GetIts()[i].Getflights()[j].IsFull() == false)
            {
                break;
            }
            if(j == GetIts()[i].Getflights().size()-1)
            {
                found = true;
            }
        }
        if (found = true)
        {
            ind = i;
            break;
        }
    }
    if (found == true)
    {
        GetItin().Setflights(GetIts()[ind].Getflights());

        for(int k = 0; k < GetIts()[ind].Getflights().size(); k++)
        {
            GetItin().Getflights()[k].AddRes();
        }

        SetStatus(EC_PASSENGER_BOOKED);
        return true;    
    }
    return false;

}

bool ECPassengerComfort :: Book(ECAirlineTicketing &airlineTicketing)
{
    int ind;
    bool found = false;
    for (int i = 0; i < GetIts().size(); i++)
    {
        if ((GetIts()[i].GetDepartTime() < EarliestDepart) || (GetIts()[i].GetFlightTime() > MaxFlightTime) || (GetIts()[i].GetNumSegments() > MaxSegements))
        {
            continue;
        }
        for(int j = 0; j < GetIts()[i].Getflights().size(); j++)
        {
            if(GetIts()[i].Getflights()[j].IsFull() == false)
            {
                break;
            }
            if(j == GetIts()[i].Getflights().size()-1)
            {
                found = true;
            }
        }
        if (found = true)
        {
            ind = i;
            break;
        }
    }
    if (found == true)
    {
        GetItin().Setflights(GetIts()[ind].Getflights());

        for(int k = 0; k < GetIts()[ind].Getflights().size(); k++)
        {
            GetItin().Getflights()[k].AddRes();
        }

        SetStatus(EC_PASSENGER_BOOKED);
        return true;    
    }
    return false;
}



 