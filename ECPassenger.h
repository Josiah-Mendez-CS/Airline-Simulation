//
//  ECPassenger.h
//  
//
//  Created by Yufeng Wu on 5/15/23.
//  Airline passenger of differen types

#ifndef ECPassenger_h
#define ECPassenger_h

#include <string>

#include "ECObserver.h"
#include "ECFlightItinerary.h"

class ECAirlineTicketing;

//****************************************************************************
typedef enum
{
    EC_PASSENGER_UNBOOKED = 0,
    EC_PASSENGER_BOOKED = 1
} EC_PASSENGER_STATUS;

//****************************************************************************
// Passenger: generic
class ECPassenger 
{
public:
    ECPassenger(const std::string &srcAirportIn, const std::string &destAirportIn): itin(srcAirportIn, destAirportIn), srcAirport(srcAirportIn), destAirport(destAirportIn){}
    virtual ~ECPassenger() {}
    
    // Book with the airline; return true if booked; false otherwise
    // Template method pattern
    virtual bool Book(ECAirlineTicketing &airlineTicketing);
    
    // Get current itinerary
    const ECFlightItinerary &GetItinerary() const { return this->itin; }
    
    // Get status
    EC_PASSENGER_STATUS GetStatus() const { return this->status; }
    
    // Dump out info
    virtual void Dump() const{};

    vector<ECFlightItinerary>& GetIts(){return PossIts;}
    std::string GetSrcAirport(){return srcAirport;};
    std::string GetDestAirport(){return destAirport;};
    
protected:
//information about itinerary
//get itin 
//get status 
ECFlightItinerary& GetItin(){return itin;}
EC_PASSENGER_STATUS GetStatus(){return status;}
void SetStatus(EC_PASSENGER_STATUS newS);


private:
    std::string srcAirport;
    std::string destAirport;
    ECFlightItinerary itin;
    EC_PASSENGER_STATUS status;
    vector<ECFlightItinerary> PossIts;
};

// Passenger: budget (with a fixed upper limit on budget)
class ECPassengerBudget : public ECPassenger
{
public:
    ECPassengerBudget(const std::string &srcAirportIn, const std::string &destAirportIn, double budgetIn) : ECPassenger(srcAirportIn, destAirportIn), budget(budgetIn){}
    bool Book(ECAirlineTicketing &airlineTicketing);

private:
   double budget;
};

// Passenger: business (with a deadline to arrive on time; i.e., must arrive by certain time)
class ECPassengerBusiness : public ECPassenger
{
public:
    ECPassengerBusiness(const std::string &srcAirportIn, const std::string &destAirportIn, double tmArrivalLatestIn) : ECPassenger(srcAirportIn, destAirportIn), ArriveLatest(tmArrivalLatestIn){}
    bool Book(ECAirlineTicketing &airlineTicketing);

private:
    double ArriveLatest;
};

// Passenger: comfort (with upper bounds on departure time, flight time and number of segments)
class ECPassengerComfort : public ECPassenger
{
public:
    ECPassengerComfort(const std::string &srcAirportIn, const std::string &destAirportIn, double tmEarliestDepartIn, double maxFlightTimeIn, int maxSegmentsIn) : ECPassenger(srcAirportIn, destAirportIn), EarliestDepart(tmEarliestDepartIn), MaxFlightTime(maxFlightTimeIn), MaxSegements( maxSegmentsIn){}
    bool Book(ECAirlineTicketing &airlineTicketing);

private:
    double EarliestDepart;
    double MaxFlightTime;
    int MaxSegements;
};

#endif /* ECPassenger_h */
