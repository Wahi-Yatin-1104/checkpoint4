// Author: Yatin Wahi, Juno Suwanduan
// Date: 9/15/2022
// Purpose: Creating a patron ticketing system
#include <iostream>
#include <fstream>
#include "patron.h"

using namespace std;
 
void displayMenuOption();
int getMenuOption(int);
void printFileNotFound();
void displayMenuOptions();
void displayRideMenu();
int getModOption(int);
void addPatron(Patron[], Patron, int*);
int readExistingPatrons(Patron[], string);
Patron createNewPatron();
void overwriteFile(Patron[], string, int);
void modifyPatron(Patron*);
void addTickets(Patron*);
void addRide (Patron* patron);
void displayPatrons(Patron[], int);
void editName(Patron*);
void removePatron(Patron[], int, int*);
int getPatronOption(Patron[], int);

 
int main(int argc, char* argv[]){
    
    int menuOption, menuChoice, patronLines, optPatron, numPatrons = 0, input;
    Patron newPatron;
    Patron patrons[100];
    string fname = argv[1];
    
    numPatrons = readExistingPatrons(patrons, fname);

    do{
        if(argc == 1)
        {
            printFileNotFound();
            return 0;
        }
        if(argc == 2){
            displayMenuOption();
            menuChoice = getMenuOption(menuOption);
            switch(menuChoice){
                case 0: 
                    cout << "Exit" << endl;
                    break;
                case 1:
                    newPatron = createNewPatron();
                    addPatron(patrons, newPatron, &numPatrons); 
                    overwriteFile(patrons, fname, numPatrons);
                    break;
                case 2:
                    displayPatrons(patrons, numPatrons);
                    removePatron(patrons, optPatron - 1, &numPatrons);
                    overwriteFile(patrons, fname, numPatrons);
                    break;
                case 3:
                    input = getPatronOption(patrons, numPatrons);
                    modifyPatron(&patrons[input - 1]);
                    overwriteFile(patrons, fname, numPatrons);

                    break;
                case 4: 
                    cout << "Enter the number of patron you'd like to view." << endl;
                    input = getPatronOption(patrons, numPatrons);

                    if(input <= numPatrons){
                        cout << "First Last ID Tickets" << endl;
                        patrons[input - 1].displayPatrons();
                    }
                    else{ 
                        cout << "Invalid Input" << endl;
                    }
                    break;
                default:
                    cout << "Please enter a valid option." << endl;
                    break;
            }
        }
    } while (menuChoice != 0);
}
 
void displayMenuOption(){
    cout << "1. Add Patron" << endl << "2. Remove Patron" << endl << "3. Modify Patron" << endl << "4. View Patron" << endl << "0. Exit" << endl;
}
 
int getMenuOption(int menuOption){
    cin >> menuOption;
    return menuOption;
}

void displayModOptions(){
    cout << "1. Add Tickets" << endl << "2. Purchase Admittance to ride" << endl << "3. Edit name" << endl << "0. Exit to main menu" << endl;
}
 
int getModOption(int userModChoice){
    cin >> userModChoice;
    return userModChoice;
}
 
void displayRideMenu(){
    cout << "Select the ride you'd like to add." << endl << "Ride (Ticket Cost)" << endl; 
    cout << "1. Teaccups (3 Tickets)" << endl << "2. Magic Carpet (2 Tickets)" << endl  << "3. World Tour (1 Ticket)" << endl << "0. Exit to main menu." << endl;
    cout << "User choice: " << endl;
}
 
void printFileNotFound(){
    cout << "Patron File Not Found. Run the program again with the file name on the command line." << endl;
}

Patron createNewPatron(){
    string firstName, lastName;
    int patronNumber, numRides, numTickets;
    Ride patronRides[100];
    char leave;
    
    cout << "Let's add a patron to the system!" << endl;
    cout << "Enter Patron first and last name (Sara Davis): " << endl;
    cin >> firstName >> lastName;
    cout << "Patron idNumber (last 4 digits of phone number):" << endl;
    cin >> patronNumber;
    cout << "How many tickets would they like to purchase?" << endl;
    cin >> numTickets;
    Patron newPatron(firstName, lastName, patronNumber, numRides, numTickets, patronRides);

    cout << "Would you like to purchase ride admittance now? (Y or N): " << endl;
    cin >> leave;
    while(leave == 'Y'){
        addRide(&newPatron);
        cout << "Would you like to purchase ride admittance now? (Y or N): " << endl;
        cin >> leave;

    }
    return newPatron;
}

void addPatron(Patron patrons[] , Patron newPatron, int* numPatrons){
    patrons[(*numPatrons)] = newPatron;
    (*numPatrons)++;
}

void overwriteFile(Patron patrons[], string fname, int numPatrons){
    ofstream fileOpener;
    fileOpener.open(fname.c_str());

    string firstName, lastName;
    int patronNumber, numTickets;

    for(int i = 0; i < numPatrons; i++){
        fileOpener << patrons[i].getFirstName() << " " << patrons[i].getLastName() << " " << patrons[i].getPatronNumber() << " " << patrons[i].getNumTickets() << endl;
    }

    fileOpener.close();
}

int readExistingPatrons(Patron patrons[], string fname){
    ifstream fileOpener;
    fileOpener.open(fname.c_str());
    int numPatrons, idNumber, numTickets;
    string first, last;

    if(!fileOpener){
        std::cout << "Sorry, could not open" << fname << "for reading" << std::endl;
        exit(0);
    }
    else{
        numPatrons = 0;
        while(fileOpener >> first >> last >> idNumber >> numTickets){
            patrons[numPatrons].setFirstName(first);
            patrons[numPatrons].setLastName(last);
            patrons[numPatrons].setPatronNumber(idNumber);
            patrons[numPatrons].setNumTickets(numTickets);
            numPatrons++;
        }
    }
    fileOpener.close();
    return numPatrons;
}


void displayPatrons(Patron patrons[], int numPatrons){
    int num = 1;
    for(int i = 0; i <= numPatrons; i++){
        cout << num << ".";
        patrons[i].displayName();
        num++;
    }
}

void removePatron(Patron patrons[], int optPatron, int* numPatrons){

    cout << "Select Which Patron You Would Like to Remove: ";
    cin >> optPatron;
    for(int index = 0; index < *numPatrons; index++){
        if(index < optPatron){
            patrons[index] = patrons[index];
        }else if(index > optPatron){
            patrons[index-1] = patrons[index];
        }
    }
    *numPatrons--;
}

int getPatronOption(Patron patrons[], int numPatrons){
    int input;
    displayPatrons(patrons, numPatrons);
    cin >> input;
    
    return input;
}


void modifyPatron(Patron* patron){
    int modIndex;
                do{
                    displayModOptions();
                    modIndex = getModOption(modIndex);
                    switch(modIndex){
                        case 0:
                            cout << "exit" << endl;
                            break;
                        case 1:
                            addTickets(patron);
                            break;
                        case 2:
                            addRide(patron);
                            break;
                        case 3:
                            editName(patron);
                            break;
                        default:
                            cout << "Please enter a valid option" << endl;
                            break;
                    }
                }while(modIndex != 0);

}

void addTickets(Patron* patron){
    int ticketInput;
    cout << "How many tickets would you like to add?" << endl;
    cin >> ticketInput;
    patron->setNumTickets(ticketInput);
    
}

void addRide(Patron* patron){
    int rideInput, numTickets, userOption;
    numTickets = patron->getNumTickets();
    Teacups teacups;
    WorldTour worldtour;
    MagicCarpet magicCarpet;

    displayRideMenu();
    cin >> rideInput;
    if(cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        return ;
    }

    switch(rideInput){
        case 1:
            if(numTickets >= 3){
                patron->addPatronRide(teacups);
                patron->setNumTickets(numTickets - 3);
            }else{
                cout << "Patron does not have tickets. Do they want to purchase more tickets?" << endl;
                cout << "1. Yes" << endl << "2. No" << endl;
                cin >> userOption;
                if (userOption == 1){
                    addTickets(patron);
                }
            }
            break;
        case 2:
         if(numTickets >= 1){
                patron->addPatronRide(magicCarpet);
                patron->setNumTickets(numTickets - 2);
            }else{
                cout << "Patron does not have tickets. Do they want to purchase more tickets?" << endl;
                cout << "1. Yes" << endl << "2. No" << endl;
                cin >> userOption;
                if (userOption == 1){
                    addTickets(patron);
                }
            }
            break;
        case 3:
        if(numTickets >= 2){
                patron->addPatronRide(worldtour);
                patron->setNumTickets(numTickets - 1);
            }else{
                cout << "Patron does not have tickets. Do they want to purchase more tickets?" << endl;
                cout << "1. Yes" << endl << "2. No" << endl;
                cin >> userOption;
                if (userOption == 1){
                    addTickets(patron);
                }
            }
            break;
    }
    
}

void editName(Patron* patron){
    int input;
    string firstName, lastName;
    cout << "Would you like to edit the:" << endl;
    cout << "1. first" << endl;
    cout << "2. last" << endl;
    cout << "3. whole name" << endl;
    cin >> input;

    switch (input){
        case 1:
            cout << "Set the New First Name: ";
            cin >> firstName;
            patron->setFirstName(firstName);
            break;
        case 2:
            cout << "Set new last name: ";
            cin >> lastName;
            patron->setLastName(lastName);
            break;
        case 3:
            cout << "Set new first and last name: ";
            cin >> firstName;
            cin >> lastName;
            patron->setFirstName(firstName);
            patron->setLastName(lastName);
            break;
        default:
            cout << "Please enter valid option.";
            break;
    }
}

