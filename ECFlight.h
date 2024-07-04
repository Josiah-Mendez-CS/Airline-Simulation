//
//  ECFlight.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlight_h
#define ECFlight_h

#include <string>
using namespace std;


// ****************************************************************************
// Flight: service between two airports at a specific time;

class ECFlight 
{
public:
    ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn) : DepartT(tmDepartIn), MaxNumP(maxPassengersIn), src(srcIn), dest(destIn) 
    {
    }
    virtual ~ECFlight()
    {
    }
    
    // Get departure time
    double GetDepartureTime() const {return DepartT;} ;
    
    // Get arrival time
    double GetArrivalTime()const;
    
    // Set max passenger for this flight
    void SetMaxNumPassengers(int m);
    
    // Get src airport code
    std::string GetSource() const {return src;}
    
    // Get destination code
    std::string GetDest() const {return dest;}

    void AddRes();

    bool IsFull();

    int FlightDist();

    int GetFlightTime();

    // more to add...    

private:
    // your code
    int numOfRes = 0;
    double DepartT;
    int MaxNumP;
    string src;
    string dest;

};

#endif /* ECFlight_h */
