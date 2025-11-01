#include "adventurer.h"


/*********************************************************************
File name: program4_driver.cpp
Author: Kripa Hayanju
Date: 10/30/2025

Purpose:
    Simulate DnD adventurer management.
Command Parameters:
    -
Input:
    Various menu options
Results:
    Manages a roster of adventurers for a DM
Notes:
    -
*********************************************************************/
int main()
{
    int iCapacity = 2;
    int iNumAdventurers = 0;

    string szDefaultMenuiChoicesArr[8] = 
	{
        "Add an adventurer",
        "View all adventurers",
        "Sort adventurers by level",
        "Sort adventurers by hit points",
        "Search for an adventurer by name",
        "Search for an adventurer by hit points",
        "Sort by level with statistics (Extra Credit)",
        "Exit"
    };

    // Dynamically allocate array for adventurers
    Adventurer* roster = new Adventurer[iCapacity]; 

    int iChoice;

    do 
    {
        displayMenu("\nMain Menu", szDefaultMenuiChoicesArr, 8);
		cout << "\nEnter choice: ";
		cin >> iChoice;

        switch (iChoice) 
        {
            case 1:
            {
                addAdventurer(roster, iNumAdventurers, iCapacity); 
                break;
            } 
            case 2: 
            {
                viewAdventurers(roster, iNumAdventurers); 
                break;
            }
            case 3: 
            {
                insertionSortByLevel(roster, iNumAdventurers); 
                viewAdventurers(roster, iNumAdventurers); 
                break;
            }
            case 4: 
            {
                selectionSortByHP(roster, iNumAdventurers); 
                viewAdventurers(roster, iNumAdventurers); 
                break;
            }
            case 5: 
            {
                string szSearchName;
                cout << "Enter adventurer's name: ";
                cin.ignore(); // Clear the newline character
                getline(cin, szSearchName);
                int iIndex = linearSearchByName(roster, iNumAdventurers, szSearchName);
                if (iIndex != -1)
                    roster[iIndex].displayAdventurer();
                else
                    cout << "Adventurer not found." << endl;
                break;
            }
            case 6: 
            {
                int iSearchLevel;
                cout << "Enter adventurer's HP: ";
                cin >> iSearchLevel;
                int iIndex = binarySearchByHP(roster, iNumAdventurers, iSearchLevel);
                if (iIndex != -1)
                    roster[iIndex].displayAdventurer();
                else
                    cout << "Adventurer not found." << endl;
                break;
            }
            case 7:
            {
                int iComparisons = 0;
                int iSwaps = 0;
                insertionSortByLevelWithStats(roster, iNumAdventurers, iComparisons, iSwaps);
                cout << "Sorting complete!" << endl;
                cout << "Comparisons: " << iComparisons << endl;
                cout << "Swaps: " << iSwaps << endl;
                viewAdventurers(roster, iNumAdventurers);
                break;
            }
            case -1: 
            {
                cout << "Exiting the program." << endl; 
                break;
            }
            default: 
            {
                cout << "Invalid iChoice. Try again." << endl;
            }
        }

    } while (iChoice != -1);

    // Free the dynamically allocated memory
    delete[] roster;
}