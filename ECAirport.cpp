//
//  ECAirport.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirport.h"
#include <iostream>
using namespace std;
void ECAirport :: SetOperating(bool f)
{
    Op = f;
}

void ECAirportInfo :: AddAirport(const ECAirport& A)
{
    
    Airports[A.GetCode()] = A;
} 

ECAirportInfo& ECAirportInfo :: Instance()
{
    static ECAirportInfo instance; 
    return instance;
}
 
int ECAirportInfo:: ReturnDist(const std::string &ap1Code, const std::string &ap2Code)
{
   return distances[ap1Code][ap2Code];

}
 
void ECAirportInfo :: CreateAirport(const std::string &name, const std::string &code)
{

}
 
void ECAirportInfo :: SetTime(int newt)
{
    Time = newt;
}
    
    // Get airport by code
    // Throw exception (std::string) if there is no airport with the code
ECAirport* ECAirportInfo :: GetAirport(const std::string &code)
{
    auto it = Airports.find(code);
    if (it == Airports.end()) {
        // Airport with the given code not found, return nullptr
        return nullptr;
    }
    // Return a pointer to the found airport object
    return &(it->second);
}
    
    // Set distance (in miles) between airports
void ECAirportInfo :: SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist)
{
    distances[ap1Code][ap2Code] = dist;
    distances[ap2Code][ap1Code] = dist;

}

