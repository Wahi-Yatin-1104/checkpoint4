![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# ProgrammingAssignment1

## Project Goals
The goal of this project is to show proficiency with:
1.	Creating **makefiles** and using g++ to compile;
2.  **Class** building skills;
3.  **Class aggregation**;
4.  **Inheritance**;
5.  **Creating arrays of objects**;
6.  **Returning pointers to objects**.
### Important Notes:
1.	**Formatting**: Make sure that you follow the precise recommendations for the output content and formatting- you will need to run the provided executable to see what output should look like. For your testing purposes, the autograder will be comparing your output to that of the example executable.
2.	**Comments**: Header comments are required on all files and recommended for the rest of the program. Points will be deducted if no header comments are included.
3.  **Code Reuse**: Each programming assignment checkpoint with your TA requires your code to be improved upon. Descriptions of checkpoint must haves are included in this document. You are free to reuse your code from previous check points, and you will likely have to modify it in some way to implement the added methodology.
4.  **Grading**: Each checkpoint lists the new files that should be included (in addition to previous code checkpoints). These checkpoint requirements are the _bare minimum_ to satisfy the requirements for grading in lab. On lab days with checkpoints, you will demonstrate your code to your TA/TF, show that it compiles and runs, and show them the code that you have added. This will constitute your grade for that checkpoint. The 4th check point will be when the entire program (in running condition) is due so that your TA can grade it more thoroughly.


## Program
When complete, your project should include the following files:
- driver.cpp
- patron.cpp
- patron.h
- ride.cpp
- ride.h
- magicCarpet.cpp
- magicCarpet.h
- teacups.cpp
- teacups.h
- worldTour.cpp
- worldTour.h
- makefile  

Your executable should be named ```carnival```
## Programming Problem
Write a program that loads existing patron data (see supplied patronList.txt for format) by providing the filename on the command line when running (./carnival patronList.txt FOR EXAMPLE) If a filename is not provided, an error message should be displayed to the user. If the file cannot be opened for reading, an error message should be displayed to the user.

If the file can be opened for reading, each patron should be read from the patron file. The program should display the menu to the screen. Further documentation can be found [here](./html/files.html). Please note that the documentation for driver.cpp is found under files (not classes), once you open the html link by double clicking on it.

### The example executable:
An example executable is provided in this repository. You should be able to run it from your project folder.
If you encounter a “permission denied” error when attempting to run the executable, type ```chmod u+x amusementPark``` into the terminal and try running the executable again by doing ```./amusementPark filemame```
## Checkpoint Requirements

# The following must be completed by lab 9/15/2022 
This portion is focused on file IO, various other C++ syntax, and makefiles. As such, you should have the following files created. Required methods/objects are listed after.
```
driver.cpp

```
*main()*: only main menu loop, if/switch for cases 0-4 (see documentation), menu call to getMenuOption, and user input should be visible for that method. You will not be able to see the output from printFileNotFound, displayModOptions, displayRideMenu, or getModOption _yet_. However, when you are checking your work, you can absolutely make direct calls to each of these methods to make sure that they work (just be sure to comment them out before your demo).  
*getMenuOption()*  
*displayMenuOption()*  
*printFileNotFound()*  
*displayModOptions()*  
*displayRideMenu()*  
*getModOption()*  

```
makefile
```
driver.o  
carnival  
**NOTE:** Compilation of this makefile and runniing the carnival object should result in seeing the main menu, modification menu, and associated prompts for user input. User input should work. See [video1](./videos/paVid1.mp4) for a demonstration of what you should have implemented.


# The following must be completed by lab 9/29/2022 (in addition to previous checkpoint)
This portion is focused on class building and aggregation.
```
driver.cpp

```
*main()*: add check to make sure user enters 2 command line arguments. Read information from the commandline argument named file into a Patron array using readExistingPatrons. Add approrpiate calls to methods after getting user choice (for example, if the user selects 1, createNewPatron() should be called, then addPatron, then overwriteFile). Case 4 only needs to cout for user option, call getPatronOption, and check if a valid user entry was provided. If it is, do nothing _yet_. Otherwise, output Invalid Output.  
*addPatron()*  
*readExistingPatrons()*  
*createNewPatron()*: Does not need to be able to add a ride to the ride array yet- you can pass in an empty rideArray for each created patron.  
*overwriteFile()*  
*modifyPatron()*: Cases 1, 3, 0, and default should all be operational. Case 2 should be displayed from the menu, but it doesn't have to do anything yet.  
*addTickets()*  
*editName()*  
*removePatron()*  

```
Patron
```
The entire .h and .cpp files, excluding addPatronRide() and displayPatronData.
```
Ride
```
Just the Ride properties and constructors (though you can do the entirety if you want; it just won't be checked until next checkpoint)

```
makefile
```
driver.o  
patron.o  
ride.o  
carnival  
**NOTE:** Compilation of this makefile and runniing the carnival object should result in the user being able to add a patron to the patron array, modify a patron (and all associated functionality), or view a patron (you do not need to display rides in the patron's ride list until the last checkpoint.) See [video2](./videos/vid2PA.mp4) for example.


# The following must be completed by lab 10/13/2022 (in addition to previous checkpoint)
This portion is focused on inheritance and object returns and storage.
```
driver.cpp

```
*main()*: Modify case 4 so that it makes the appropriate calls  
*modifyPatron()*: modify this method so that you can add a ride when case 2 is called  
*createNewPatron()*: modify this method so that the user can be prompted repeatedly (until they input n or N) asking if they want o purchase ride admittance and then add that ride using an addRide call.  
*displayPatrons()*  
*addRide()*  

```
Patron
```
Add addPatronRide and displayPatronData

```
Ride
````
Add getters and setters for inheritance into child classes below. 
```
Teacups
```
The entire .h and .cpp files.
```
MagicCarpet
```
The entire .h and .cpp files.

```
WorldTour

```
The entire .h and .cpp files
makefile
```
driver.o  
patron.o  
ride.o  
teacups.o  
worldTour.o  
magicCarpet.o  
carnival  
**NOTE:** Compilation of this makefile and runniing the carnival object should result in the user having access to all functionality. You will need to make changes to patron, ride, and the driver to accomodate adding specific ride types to the ride array for each person. See [video3](./videos/vid3PA.mp4) for example.


# The following must be completed by lab 10/27/2022 (in addition to previous checkpoint)

This portion is focused on making sure your code is operational and follows all of the guidelines in the html doc. **Make sure your output matches the executable exactly, and that your documentation is good to go**. You will be submitting your final programming assignment product- remember, that means that this final product is worth more than past checkpoints! Make sure your product is polished and good to go! See provided executable.


## Submission details
Each checkpoint requires you to submit your code through github using the associated github link in webcampus. Make sure you do it by the checkpoint assignment due date! To submit your project, you will have to use git on your VirtualBox installation:
1.	After accepting the assignment invitation, copy the clone URL
2.	Type 
```git clone clone URL```
3.	cd into your new assignment directory
4.	After working on your files
5.	When you’re ready, type the following commands: 
```
git add .
git commit -m “a descriptive message!”
git push
```
## Academic Honesty
Academic dishonesty is against university as well as the system community standards. Academic dishonesty includes, but is not limited to, the following:
Plagiarism: defined as submitting the language, ideas, thoughts or work of another as one's own; or assisting in the act of plagiarism by allowing one's work to be used in this fashion.
Cheating: defined as (1) obtaining or providing unauthorized information during an examination through verbal, visual or unauthorized use of books, notes, text and other materials; (2) obtaining or providing information concerning all or part of an examination prior to that examination; (3) taking an examination for another student, or arranging for another person to take an exam in one's place; (4) altering or changing test answers after submittal for grading, grades after grades have been awarded, or other academic records once these are official.
Cheating, plagiarism or otherwise obtaining grades under false pretenses constitute academic
dishonesty according to the code of this university. Academic dishonesty will not be tolerated and
penalties can include cancelling a student’s enrolment without a grade, giving an F for the course, or for the assignment. For more details, see the University of Nevada, Reno General Catalog.
#   c h e c k p o i n t 4  
 