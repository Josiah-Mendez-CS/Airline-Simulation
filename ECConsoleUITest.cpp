// Test code for console UI
#include "ECTextViewImp.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUITextLabel.h"
#include "ECConsoleUIListBox.h"
#include <iostream>

#include "ECAirport.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirlineSimulator.h"


#include <fstream>
#include <sstream>
#include <vector>

#include <string>
#include <iostream>
#include <cmath>
#include "ECConsoleUIButton.h"
using namespace std;



// construct a simple UI
int main(int argc, char *argv[])
{
    
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    
    ECTextViewImp wndTest;

    // add a status bar
    wndTest.AddStatusRow("Test", "For demo only", true);
    
    // Create a console UI view
    ECConsoleUIView viewUI(&wndTest);
    
     // create several labels
    ECConsoleUITextLabel *pl1 = new ECConsoleUITextLabel(25, 1, "CSE 3150 Airlines Flight System");
    pl1->SetHighlight(true);
    viewUI.AddUIItem(pl1);
    // ECConsoleUITextLabel *pl2 = new ECConsoleUITextLabel(25, 5, "Insructors");
    // viewTest.AddUIItem(pl2);
    // Create a border (well, not very pretty)
    string horizBar;
    for(int i=0; i<viewUI.GetColNumInView(); ++i)
    {
        horizBar += '-';
    }

  
    ECConsoleUITextLabel *pl4 = new ECConsoleUITextLabel(0, 0, horizBar);
    viewUI.AddUIItem(pl4);
    ECConsoleUITextLabel *pl5 = new ECConsoleUITextLabel(0, viewUI.GetRowNumInView()-1, horizBar);
    viewUI.AddUIItem(pl5);

    ECConsoleUITextLabel *pl6 = new ECConsoleUITextLabel(25, 3, "Origin");
    viewUI.AddUIItem(pl6);
    ECConsoleUIListBox *px2 = new ECConsoleUIListBox(25, 5, 35, 7 );

    //

     // Add a third list box
    ECConsoleUITextLabel *pl7 = new ECConsoleUITextLabel(45, 3, "Destination");
    viewUI.AddUIItem(pl7);
    ECConsoleUIListBox *px3 = new ECConsoleUIListBox(45, 5, 55, 7);

    ECAirlineSimulator sim;
    std::ifstream file(argv[1]); // Open the file for reading
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }

    std::string line;
    cout<<"here"<<endl;
    while (std::getline(file, line)) { // Read each line from the file
        if (line.empty() || line[0] == '#') {
            continue; // Ignore empty lines and comments
        }

        // Check if the line starts with a number
        if (line[0] == '1') {
            std::stringstream ss(line);
            std::vector<std::string> words;
            std::string word;
            while (ss >> word) {
                words.push_back(word);
                
            }
            
            // Output or process the words as needed
            // Adding four airport
            sim.AddAirport(words[2], words[1]);
            px2->AddChoice(words[1]);
            px3->AddChoice(words[1]);
            cout <<"word: "<< words[1];
            // if (words[1] == "EWR")
            // {
            //     px2->AddChoice(words[1]);
            //     px3->AddChoice(words[1]);
            // }
                
            
            // cout<<"words: "<<words[1]<<endl;
        }
       
        if (line[0] == '2') {
            std::stringstream ss(line);
            std::vector<std::string> words;
            std::string word;
            while (ss >> word) {
                words.push_back(word);
            }
            // Set distances
            sim.SetDistBtwAirports(words[1], words[2], stoi(words[3]));
        }

        if (line[0] == '3') {
            std::stringstream ss(line);
            std::vector<std::string> words;
            std::string word;
            while (ss >> word) {
                words.push_back(word);
            }
             // Add flights
            sim.AddFlight(words[1], words[2], stoi(words[3]), stoi(words[4]), stoi(words[5]));
        }
    }
    // px2->AddChoice("");
    // px3->AddChoice("");
    // px2->RemLast();
    // px3->RemLast();
    file.close(); // Close the file when done
//     px2->Dump();
//     cout<<endl;
//     px3->Dump();
//    exit(1);
    string buttName = "Search for flights";
    // ECConsoleUITextLabel *F = new ECConsoleUITextLabel(30, 12, "Flights");
    // viewUI.AddUIItem(F);
    ECConsoleUIListBox *flightListBox = new ECConsoleUIListBox(25, 15, 150,17);
    flightListBox->AddChoice("Flights");

    // ECConsoleUIListBox *flightListBox = new ECConsoleUIListBox(47, 7, 55, 9);
    vector<ECFlightItinerary> listItineraries;
    SearchFlights *SF = new SearchFlights(25, 10, 50, 10, buttName, sim, viewUI, *px2, *px3, *flightListBox, listItineraries); 
    // ECConsoleUIButton *SF = new ECConsoleUIButton(30, 15, 45, 17, buttName); 

    //add another function controls when listbox pops up
    //cost amount of segement flight time 
    
    // Add another list box
    viewUI.AddUIItem(px2);
    
    
    viewUI.AddUIItem(px3);

    viewUI.AddUIItem(SF);

    viewUI.AddUIItem(flightListBox);
    
    
    // Display it
    
    viewUI.Refresh();
    // cout<<"here10"<<endl;
    // exit(1);
    // Show the window
    try {
        wndTest.Show();
    }
    catch(std::string ex)
    {
        cout << "Exception: " << ex << endl;
    }
    return 0;
}
//new listboc of itineraries 
//dump itinearies in flight list boxes to the important information
//create in enter with new 
//if there is nothing just print no flights found 