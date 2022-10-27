#include "patron.h"

Patron::Patron(){
    firstName = "NA";
    lastName = "NA";
    patronNumber = 0;
    numRides = 0;
    numTickets = 0;
}

Patron::Patron(string newFirstName, string newLastName, int newPatronNumber, int newNumRides, int newNumTickets, Ride newPatronRides[]){
    firstName = newFirstName;
    lastName = newLastName;
    patronNumber = newPatronNumber;
    numRides = newNumRides;
    numTickets = newNumTickets;
    for (int i = 0; i < 100; i++){
        patronRides[i] = newPatronRides[i];
    }
}

Patron::Patron(const Patron & rHs){
    firstName = rHs.firstName;
    lastName = rHs.lastName;
    patronNumber = rHs.patronNumber;
    numRides = rHs.numRides;
    numTickets = rHs.numTickets;
    for (int i = 0; i < 100; i++){
        patronRides[i] = rHs.patronRides[i];
    }
}

string Patron::getFirstName(){
    return firstName;
}

void Patron::setFirstName(string newFirstName){
    firstName = newFirstName;
}

string Patron::getLastName(){
    return lastName;;
}

void Patron::setLastName(string newLastName){
    lastName = newLastName;
}

int Patron::getPatronNumber(){
    return patronNumber;
}

void Patron::setPatronNumber(int newPatronNumber){
    patronNumber = newPatronNumber;
}

Ride* Patron::getPatronRides(){
    return patronRides;
}

void Patron::addPatronRide(Ride newerPatronRides){
    if(numRides < 100){
        patronRides[numRides] = newerPatronRides;
        numRides++;
    }
}

int Patron::getNumTickets(){
    return numTickets;

}

void Patron::setNumTickets(int newNumTickets){
    numTickets = newNumTickets;
    
}

void Patron::displayName(){
    cout << firstName << " " << lastName << endl;

}

void Patron::displayPatrons(){
    cout << firstName << " ";
    cout << lastName << " ";
    cout << patronNumber << " ";
    cout << numTickets << " " << endl;
    cout << "Has Admittance to: " << endl;
    for (int i = 0; i < numRides; i++){
        cout << patronRides[i].getRideName() << endl;
    }
}