#ifndef RIDE_H
#define RIDE_H
#include<iostream>

using namespace std;

class Ride{
    protected:
        int numTickets;
        string name;
        bool heightRestricted;
    
    public:
        Ride();
        Ride(int, string, bool);
        Ride(const Ride&);
        
        int getNumTicketsNecessary();
        void setNumTicketsNecessary(int);
        
        string getRideName();
        void setRideName(string);
        
        bool getHeightRestricted();
        void setHeightRestricted(bool);

        
};
#endif