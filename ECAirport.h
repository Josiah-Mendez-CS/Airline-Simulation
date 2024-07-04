//
//  ECAirport.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECAirport_h
#define ECAirport_h

#include <string>
#include <set>
#include <map>
using namespace std;


// ****************************************************************************
// Airport: start/end point of a flight

class ECAirport 
{ 
public:
    // by default, airport is operating (except in default constructor)
    ECAirport(){} 
    ECAirport(const std::string &nameAP, const std::string &codeIATA){}
    ECAirport(const ECAirport &rhs) : name(rhs.GetName()), code(rhs.GetCode()), Op(rhs.IsOperating()){}
    
    // Get the name of the airport
    std::string GetName()const {return name;}
    
    // Get IATA code
    std::string GetCode() const{return code;}
    
    // Operating status: is it operating normally?
    bool IsOperating()const{return Op;};
    
    // Set operating status
    void SetOperating(bool f);
    
private:
    // your code 
    string name;
    string code;
    bool Op;
    
};

// ****************************************************************************
// Airport info: access airport information
// Use singleton pattern

class ECAirportInfo
{
public:
    
    // Create a new airport in the system
    void CreateAirport(const std::string &name, const std::string &code);
    
    // Get airport by code
    // Throw exception (std::string) if there is no airport with the code
    ECAirport* GetAirport(const std::string &code);
    
    // Set distance (in miles) between airports
    void SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist);

    int GetTime(){return Time;}

    int ReturnDist(const std::string &ap1Code, const std::string &ap2Code);
    
    void SetTime(int newt);
    // more to add...
    static ECAirportInfo& Instance(); 

    void AddAirport(const ECAirport& A);
    
    
private:
   // your code
   //map in map
   map<string, ECAirport> Airports; 
   //map in map
   map<string, map<string, double> > distances; 
   int Time;
//    static ECAirportInfo& inst;
// };
};


#endif /* ECAirport_h */
