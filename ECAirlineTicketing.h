//
//  ECAirlineTicketing.h
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#ifndef ECAirlineTicketing_h
#define ECAirlineTicketing_h
#include "ECAirlineTicketing.h"
#include "ECFlightItinerary.h"
#include "ECAirlineOperation.h"
#include "ECFlight.h"
#include <map>
using namespace std;

// ****************************************************************************
// Airline ticketing: search for flights, issue tickets, etc

class ECAirlineTicketing 
{
public:
ECAirlineTicketing(){}
virtual ~ECAirlineTicketing(){}
   
void MakeRes(ECFlightItinerary it);

void DFS(ECAirlineOperation* AL, string src, string dest, ECFlightItinerary it,  std::vector<ECFlightItinerary> &listItineraries, map<string, bool>& visited, ECFlight lastF, bool first )const;
vector<ECFlightItinerary>CreateIt(const std::string &src, const std::string &dest, ECAirlineOperation* AL) const;

void OrderItineraries(vector<ECFlightItinerary> &listItineraries){};

vector<int>& GetPrefer();

vector<ECFlightItinerary>& GetPossIts(){return *PossIts;}

void LowPriceTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties);

void EarlyArriveTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties);

void ShortTimeTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties);

void SegTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties);

void setPossIts(vector<ECFlightItinerary> &listItineraries);

void AddToPass(ECPassenger P);

void AddToPassengerIts (ECFlightItinerary P);

vector<ECPassenger>& GetPass(){return pass;}

vector<ECFlightItinerary>& GetPassengerIts(){return PassengerIts;}
//0
    // Add preference by invoking the following functions
    // Note: you can add multiple preference; the first added preference is used first; the later added preference as tie-breakers (the preference added earlier has precedence)
    // Prefer low price
    void PreferLowPrice();

    //1
   // Prefer early arrival
    void PreferEarlyArrival();

    //2
    // Prefer flights with smaller flight time
    void PreferShortTime();

    //3
    // Prefer flights with smaller number of segments
    void PreferSmallestSegments();



private:
    // your code
    vector<int> prefer; 
    vector <ECFlight> Sflights;
    vector<ECFlightItinerary>* PossIts;
    vector<ECPassenger> pass;
    vector<ECFlightItinerary> PassengerIts;  
    
 
    //list of flights scheduled to occur beased on what has been booked


};

//within prefer
//prefer()

//intially null
//compare input two itneraries
//sort two times to determine false 
//there is a private variable preference intially set to null
//when preferences are called they create a new preference with prev as input
//prev = new (prev)
//sort(, , pref->compare()  )

//in compare check if null 
//check if equal by sort an then if they are equal call compare on the preferences inputted parameters

// class ECPreference
// {
//     ECPreference(){};
//     //takes in two it
//     virtual void Compare(vector<ECFlightItinerary> &listItineraries);

//     private:
//         ECPreference*  prev;

// }
// class ECLeastFigtPreference
// {
//     ECPreference(){};
//     void Compare(vector<ECFlightItinerary> &listItineraries);

// }


#endif /* ECAirlineTicketing_h */
