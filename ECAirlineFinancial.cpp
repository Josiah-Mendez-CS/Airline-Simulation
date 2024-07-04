//
//  ECAirlineFinancial.cpp
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#include "ECAirlineFinancial.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECFlight.h"

#include <string>
#include <iostream>
using namespace std;

double  ECAirlineFinancial::CalculatePrice( ECFlightItinerary& f)
{
    // double totalFtime = 0;
    // for( int i = 0; i < f.Getflights().size(); i++)
    // {
    //     totalFtime+= f.Getflights()[i].GetFlightTime();

    // }
    return f.GetFlightTime()*120;

   
}
