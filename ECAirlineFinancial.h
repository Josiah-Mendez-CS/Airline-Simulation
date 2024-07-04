//
//  ECAirlineFinancial.h
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#ifndef ECAirlineFinancial_h
#define ECAirlineFinancial_h

#include "ECAirlineFinancial.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include "ECPassenger.h"


// ****************************************************************************
// Airline finanical: budgetting, pricing and money bookkeeping

class ECAirlineOperation;
class ECAirlineFinancial
{
public:
ECAirlineFinancial(ECAirlineOperation *pOperateIn){};
    ECAirlineFinancial()
    {
    }
    virtual ~ECAirlineFinancial()
    {
    }
   
   double  CalculatePrice(ECFlightItinerary& f);

   // Register a passenger
    // this is useful for things like flight updates
    // for the moment, you just need to maintain a list of passengers 
    void RegisterPassenger(ECPassenger *pPassenger){};

    // Get the number of registered passingers
    int GetNumPassengers() const { return listPassengers.size(); }

     // Get the passenger that is added in the k-th position
    ECPassenger *GetPassenger(int k) const { return listPassengers[k]; }

     // pricing the itinerary 
    double Quote(const ECFlightItinerary &itin) const {};

    // get revenue
    double GetRevenue() const { return balance; }

    // Balance query = revnue - cost
    double GetBalance() const {};

    // Paid by $amt
    void Paid(double amt) {};

    // Charged by $amt
    void Charged(double amt) {};

     // Dump out
    void Dump() const {};

  

private:
    // Operating
    ECAirlineOperation *pOperate;
    
    // balance: how much money the airline has?
    double balance;
    
    // list of registered passengers
    std::vector<ECPassenger *> listPassengers;
};



#endif
