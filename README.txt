Features Implemented
Use ctrl-A to navigate to different UI items
Scrolling - To scroll use the up and down arrows
Highlighting - whatever list box item that you currently have selected will be
Highlighted a different color than the rest
Highlight your origin and destination with the arrow keys
Highlight the itinerary that you want to select with the arrow keys
Press enter to Search on the Search Flights button

To build the test code:

g++ ECAirlineFinancial.cpp ECAirlineOperation.cpp ECAirlineSimulator.cpp ECAirlineTicketing.cpp ECAirport.cpp ECFlight.cpp ECFlightItinerary.cpp ECPassenger.cpp ECConsoleUITextLabel.cpp ECTextViewImp.cpp ECConsoleUIView.cpp  ECConsoleUITest.cpp ECConsoleUIListBox.cpp ECConsoleUIButton.cpp -o test


To run it:

./test sim.txt

