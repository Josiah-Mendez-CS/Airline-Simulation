//
//  ECAirlineSimulator.hpp
//  
//
//  Created by Yufeng Wu on 5/17/23.
//  Simulate airline activities: booking, flights, etc

#ifndef ECAirlineSimulator_h
#define ECAirlineSimulator_h
#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirport.h"
#include "ECFlight.h"
#include "ECFlightItinerary.h"

#include <string>
#include <set>
#include<map>
using namespace std;
class ECAirlineOperation;
class ECAirlineTicketing;
class ECAirlineFinancial;
class ECFlightItinerary;

//****************************************************************************
// Airline simulator

class ECAirlineSimulator
{
public:
    ECAirlineSimulator(){Init();}

    //delete all pointers that were allocated on the heap 
    virtual ~ECAirlineSimulator(){}
    
    // *****************************************************
    // Configuration 
    
    // Adding airport with name and IATA code
    void AddAirport(const std::string &name, const std::string &code);

     // Search preference: if no preference (this is the default), then all itineraries treated equivalent; if
    // Clear preference (i.e., no preference)
    // void ClearPreference();
    

    // // get all airport codes in record
    // void GetAllAirportCode(std::set<std::string> &setAirports) const;

//     //0
//     // Add preference by invoking the following functions
//     // Note: you can add multiple preference; the first added preference is used first; the later added preference as tie-breakers (the preference added earlier has precedence)
//     // Prefer low price
//     void PreferLowPrice();

//     //1
//    // Prefer early arrival
//     void PreferEarlyArrival();

//     //2
//     // Prefer flights with smaller flight time
//     void PreferShortTime();

//     //3
//     // Prefer flights with smaller number of segments
//     void PreferSmallestSegments();

    void AddPassengerBudget(string s, string d, double  x);
    void AddPassengerBusiness(string s, string d, double x);
    void AddPassengerComfort(string s, string d, double x, double y, int j);

    
    // Setup distaince between airport; note distance is symmetric: the distance from dest to src is the same as from src to dest
    void SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist);
    
    // Adding flights: src airport, dest airport, depart time, max number of passenger, operating cost
    void AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate );
    
    // Called to indicate no more flights to add
    void DoneFlightAdding();

    void GetPassengerItineraries(vector<ECFlightItinerary>& PITS);
    
    // *****************************************************
    // Flight booking and optimization
    // Book flights for all unbooked passengers
    // In the order of passenger adding. That is, the first added passenger is to be booked the first
    void Book();

    // *****************************************************
    // Flight search
    
    // Searcch for flights; return all flights in listItineraries that go from src to dest
    void SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries ) const;
    
    // Access airlines
    //ECAirlineFinancial *GetAirlineFin() { return pAirlineFin; }
    ECAirlineOperation *GetAirlineOp() { return pAirlineOp; }
    ECAirlineTicketing *GetAirlineTicketing() { return pAirlineTicket; }
    ECAirlineFinancial *GetAirlineFin() { return pAirlineFin; }
    
    
private:
    // initialize
    void Init();
    
    // key data member

    ECAirlineOperation *pAirlineOp;
    ECAirlineFinancial *pAirlineFin;
    ECAirlineTicketing *pAirlineTicket;
};


#endif /* ECAirlineSimulator_h */
