//
//  ECAirlineTicketing.cpp
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#include "ECAirlineTicketing.h"
#include "ECFlightItinerary.h"
#include "ECAirlineOperation.h"
#include "ECFlight.h"
#include <map>
#include <iostream>
using namespace std;

void ECAirlineTicketing :: MakeRes(ECFlightItinerary it) 
{
    for(int i = 0; i < it.Getflights().size(); i++) 
    {
        it.Getflights()[i];
    }
    
}
//adjaceny set 
//key will be airport and values will be an air port that it could go to 
// 

void ECAirlineTicketing :: AddToPass(ECPassenger P)
{
    pass.push_back(P);
}

vector<int>& ECAirlineTicketing ::  GetPrefer()
{
    return prefer;
}

void ECAirlineTicketing :: LowPriceTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties)
{
    
    for (int j =0 ; j< listItineraries.size(); j++)
    {
        for(int i =0 ; i< listItineraries.size(); i++)
        {
            if (j!= i)
            {
                if (listItineraries[i].GetPrice() == listItineraries[j].GetPrice())
                {
                    ties[j] = i;
                }

            }
            
        }
    }
    

}

void ECAirlineTicketing :: EarlyArriveTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties)
{
    
    for (int j =0 ; j< listItineraries.size(); j++)
    {
        for(int i =0 ; i< listItineraries.size(); i++)
        {
            if (j!= i)
            {
                if (listItineraries[i].GetArrivalTime() == listItineraries[j].GetArrivalTime())
                {
                    ties[j] = i;
                }

            }
            
        }
    }
    

}

void ECAirlineTicketing :: SegTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties)
{
    
    for (int j =0 ; j< listItineraries.size(); j++)
    {
        for(int i =0 ; i< listItineraries.size(); i++)
        {
            if (j!= i)
            {
                if (listItineraries[i].GetNumSegments() == listItineraries[j].GetNumSegments())
                {
                    ties[j] = i;
                }

            }
            
        }
    }
}

void ECAirlineTicketing :: ShortTimeTies(vector<ECFlightItinerary> &listItineraries, map<int, int>& ties)
{
    
    for (int j =0 ; j< listItineraries.size(); j++)
    {
        for(int i =0 ; i< listItineraries.size(); i++)
        {
            if (j!= i)
            {
                if (listItineraries[i].GetFlightTime() == listItineraries[j].GetFlightTime())
                {
                    ties[j] = i;
                }

            }
            
        }
    }
    

}

//preference class in Ticketing 
//other preferences inherit 
//preference has compare function 
//


//if there is a tie then you take into account the next preference
// void ECAirlineTicketing :: OrderItineraries(vector<ECFlightItinerary> &listItineraries)
// {
//     bool done = false;
//     bool same = false;
    
//     map<int, int >ties;
//     for(int i; i < prefer.size(); i++)
//     {
        
//         switch (prefer[i]) 
//         {
//             //low price
//             case 0:

//             // Only sorting the portion that is tied
//             if (same == true)
//             {
//                 for (auto x: ties)
//                 {
//                     sort(listItineraries.begin()+x.first,listItineraries.begin() +ties[x.first]+1, [](ECFlightItinerary x, ECFlightItinerary y){return x.GetPrice() < y.GetPrice();});
//                 }
//                 ties.clear();
//                 LowPriceTies(listItineraries, ties);
//                 if (ties.size() == 0)
//                 {
//                     done = true;
//                 }
//                 break;  
//             }

//             //sorting all the itineraries
//             sort(listItineraries.begin(),listItineraries.end(), [](ECFlightItinerary x, ECFlightItinerary y){return x.GetPrice() < y.GetPrice();});
//             LowPriceTies(listItineraries, ties); 
//             if (ties.size() == 0)
//             {
//                 done = true;
//             }
//             break;
                
//             //Early arrival
//             case 1:
//             if (same == true)
//             {
//                 for (auto x: ties)
//                 {
//                     sort(listItineraries.begin()+x.first,listItineraries.end()+ties[x.first]+1, [](ECFlightItinerary x, ECFlightItinerary y){return x.GetArrivalTime() < y.GetArrivalTime();});
//                 }
//                 ties.clear();
//                 EarlyArriveTies(listItineraries, ties);
//                 if (ties.size() == 0)
//                 {
//                     done = true;
//                 }
//                 break;  
//             }
            
//             sort(listItineraries.begin(),listItineraries.end(), [](ECFlightItinerary x, ECFlightItinerary y){return x.GetArrivalTime() < y.GetArrivalTime();});
//             EarlyArriveTies(listItineraries, ties); 
//             if (ties.size() == 0)
//             {
//                 done = true;
//             }
//             break;

//             //Short Time
//             case 2:
//             if (same == true)
//             {
//                 for (auto x: ties)
//                 {
//                     sort(listItineraries.begin()+x.first,listItineraries.end()+ties[x.first]+1, [](ECFlightItinerary x, ECFlightItinerary y){return x.GetFlightTime() < y.GetFlightTime();});
//                 }
//                 ties.clear();
//                 ShortTimeTies(listItineraries, ties);
//                 if (ties.size() == 0)
//                 {
//                     done = true;
//                 }
//                 break;  
//             }
            
//             sort(listItineraries.begin(),listItineraries.end(), [](ECFlightItinerary x, ECFlightItinerary y){return x.GetFlightTime() < y.GetFlightTime();});
//             ShortTimeTies(listItineraries, ties); 
//             if (ties.size() == 0)
//             {
//                 done = true;
//             }
//             break;

//             //less flights
//             case 3:
//             if (same == true)
//             {
//                 for (auto x: ties)
//                 {
//                     sort(listItineraries.begin()+x.first,listItineraries.end()+ties[x.first]+1, [](ECFlightItinerary x, ECFlightItinerary y){return x.GetNumSegments() < y.GetNumSegments();});
//                 }
//                 ties.clear();
//                 SegTies(listItineraries, ties);
//                 if (ties.size() == 0)
//                 {
//                     done = true;
//                 }
//                 break;  
//             }
            
//             sort(listItineraries.begin(),listItineraries.end(), [](ECFlightItinerary x, ECFlightItinerary y){return x.GetNumSegments() < y.GetNumSegments();});
//             SegTies(listItineraries, ties); 
//             if (ties.size() == 0)
//             {
//                 done = true;
//             }
//             break;

//                 break;

//         }
//         if (done == true)
//         {
//             break;
//         }
//         same = true; 

//     }
// }
void ECAirlineTicketing :: DFS(ECAirlineOperation* AL, string src, string dest, ECFlightItinerary it,  std::vector<ECFlightItinerary> &listItineraries, map<string, bool>& visited, ECFlight lastF, bool first)const
{ 
    if (src == dest)
    {
        // cout<< "add to It"<<endl;
        listItineraries.push_back(it);
        return;
    }
    visited[src] = true;
    
    
    //visited.erase(dest);
    for(auto z : AL->AJSet())
    {
        //&&   (visited.count(x.GetDest())==0)
        //(x.GetSource() == src)
        // cout<< "x's src "<<x.GetSource()<< "x's dest " <<x.GetDest()<< "x's dep time "<< x.GetDepartureTime()<< endl;
        // (x.IsFull()== false)
        if (z.first == src)
        {
            
            for (const auto& x : z.second)
            {
                // cout<<endl;
                // cout<< "x's src "<<x.GetSource()<< " x's dest " <<x.GetDest()<< " x's dep time "<< x.GetDepartureTime()<< endl;
                // cout<< "prev's src "<<lastF.GetSource()<< " prev's dest " <<lastF.GetDest()<< " prev's dep time "<< lastF.GetDepartureTime()<<" prev's arrival time " <<lastF.GetArrivalTime()<<endl;
                // cout<<endl;
               
                if((x.GetDepartureTime() >= lastF.GetArrivalTime())   && (!visited[x.GetDest()]))
                {
                    
                    // cout<< "in if"<<endl;
                    // cout<<"dept "<< x.GetDepartureTime()<<endl;
                    // if (!first)
                    // {
                    //     std::cout<<"hererer"<<endl;
                    //     it.Addflights(x);
                        
                    // }
                    
                    it.Addflights(x);
                    DFS(AL, x.GetDest(), dest, it, listItineraries, visited, x, false);
                    it.RemLastF();
                    
                }
            }
            
        }
      
    }
     visited[src] = false;
} 

//0
void ECAirlineTicketing:: PreferLowPrice()
{
    prefer.push_back(0);

}

void ECAirlineTicketing :: AddToPassengerIts (ECFlightItinerary P)
{
    PassengerIts.push_back(P);
}

//1
void ECAirlineTicketing:: PreferEarlyArrival()
{
    prefer.push_back(1);

}

//2
void ECAirlineTicketing:: PreferShortTime()
{
    prefer.push_back(2);

}

//3
void ECAirlineTicketing::PreferSmallestSegments()
{
    prefer.push_back(3);
}

void ECAirlineTicketing :: setPossIts(vector<ECFlightItinerary> &listItineraries )
{
    PossIts = &listItineraries;
}


    

vector<ECFlightItinerary> ECAirlineTicketing :: CreateIt(const std::string &src, const std::string &dest, ECAirlineOperation* AL) const
{
    
    vector<ECFlightItinerary> Its; 
    map<string, bool> visited;
    
    // for (auto x: AL->listOfFlights())
    // {
        
    //     if(x.GetSource() == src)
    //     {
            
            
    //         ECFlightItinerary newI(src, dest); 
    //         // Its.push_back(newI);
    //         newI.Addflights(x);
    //         firstflights.push_back(newI);     
    //     }      
    // }
    visited[src] = true;
    for(auto z : AL->AJSet())
    {
        
        if(z.first == src)
        {
            
            for (auto x : z.second)
            {
                ECFlightItinerary newI(src, dest); 
                // Its.push_back(newI);
                newI.Addflights(x);
                DFS(AL, x.GetDest(), dest, newI, Its, visited, x, true);
            }     
        }      
    }
    
   
    // std::cout<<"solutions"<<endl;
    // for (auto x: Its)
    // {
    //     // for(auto y: x.Getflights())
    //     // {
    //     //     cout<<"flight src"<<y.GetSource<< "flight dest"<<<<<<endl;
    //     // }
        
    //     x.Dump();
    // }
   
    
    return Its;

}

