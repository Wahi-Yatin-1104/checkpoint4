#include "ride.h"

Ride::Ride(){
    numTickets = 0;
    name = "";
    heightRestricted = true;

}

Ride::Ride(int newNumTickets, string newName, bool newHeightRestricted){
    numTickets= newNumTickets;
    name = newName;
    heightRestricted = newHeightRestricted;

}
        
Ride::Ride(const Ride& rHs){
    numTickets = rHs.numTickets;
    name = rHs.name;
    heightRestricted = rHs.heightRestricted;

}
        
int Ride::getNumTicketsNecessary(){
    return numTickets;
}
void Ride::setNumTicketsNecessary(int newNumTickets){
    numTickets = newNumTickets;
}
        
string Ride::getRideName(){
    return name;
}

void Ride::setRideName(string newName){
    name = newName;
}
        
bool Ride::getHeightRestricted(){
    return heightRestricted;
}

void Ride::setHeightRestricted(bool newHeightRestricted){
    heightRestricted = newHeightRestricted;
}
