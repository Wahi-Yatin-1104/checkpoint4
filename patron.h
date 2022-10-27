#ifndef PATRON_H
#define PATRON_H

#include "magicCarpet.h"
#include "teacups.h"
#include "worldTour.h"

class Patron{
    private:
        string firstName, lastName;
        int patronNumber, numRides, numTickets;
        Ride patronRides[100];

    public:
        Patron();
        Patron(string, string, int, int, int, Ride[]);
        Patron(const Patron &);

        string getFirstName();
        void setFirstName(string);

        string getLastName();
        void setLastName(string);

        int getPatronNumber();
        void setPatronNumber(int);

        Ride* getPatronRides();
        void addPatronRide(Ride);

        int getNumTickets();
        void setNumTickets(int);

        void displayName();
        void displayPatrons();

};
#endif