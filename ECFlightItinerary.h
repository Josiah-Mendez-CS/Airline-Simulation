//
//  ECFlightItinerary.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlightItinerary_h
#define ECFlightItinerary_h 

#include <vector>
#include <string>

class ECFlight;
class ECAirlineFinancial;
using namespace std;

// ****************************************************************************
// Flight itineary: consisting segments of flights so to go from one airport to another airport

class ECFlightItinerary
{
public:
    ECFlightItinerary(string start, string dest): src(start), dest(dest) {} 
    
    // access/edit segments
    // Return the number of segments of the itineary
    int GetNumSegments() const{return flights.size();}
    
    // Return a segment
    const ECFlight& GetSegment(int segIndex) const{return flights[segIndex];};
    
    // Get flight time: from departure to arrival
    double GetFlightTime() const;
    
    // Get segment time: add the time of all segments
    double GetTimeAllSegments() const;
    
    // Get departure time
    double GetDepartTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;
    
    // Price 
    double GetPrice()const;

    void Addflights(const ECFlight& f);

    void RemLastF();

    string Dump()const;

    vector<ECFlight>& Getflights(){return flights;}

    void Setflights(vector<ECFlight>& newFs);

    
    
private:
    // your code
    //how do I know the possible paths there are from one airport to anothger airport and what path should I prioritize when creating an itinerary
    vector<ECFlight> flights;
    string src;
    string dest;
};

#endif /* ECFlightItinerary_h */
