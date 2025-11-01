#include "adventurer.h"


/*********************************************************************
void displayMenu(string szMenuName, string szChoicesArr[], int iChoices)
Purpose:
    Function to display the menu choices of a provided menu
Parameters:
    I   string szMenuName       Title of the displayed menu
    I   string szChoicesArr     Menu choices to be displayed
    I   int iChoices            Number of menu choices    
Return Value:
    -
Notes:
    Menu options are displayed starting at 1
    The last menu option should always be displayed as -1
*********************************************************************/
void displayMenu(string szMenuName, string szChoicesArr[], int iChoices)
{
    cout << szMenuName << endl;
    cout << szBreakMessage << endl;
    for(int i =0; i <iChoices-1; i++)
    {
        cout << i+1 << ". ";
        cout << szChoicesArr[i] << endl;
    }
    cout << "-1. " << szChoicesArr[iChoices-1] << endl;
    cout << szBreakMessage << endl;
}

/*********************************************************************
void addAdventurer(Adventurer*& roster, int& iSize, int& iCapacity)
Purpose:
    Add an adventurer to the dynamic roster
Parameters:
    I/O Adventurer*& roster     Dynamic roster of adventurers
    I/O int& iSize              Current number of adventurers
    I/O int& iCapacity          Roster capacity    
Return Value:
    -
Notes:
    The function adds 10 to the capacity once it has been reached.
*********************************************************************/
void addAdventurer(Adventurer*& roster, int& iSize, int& iCapacity)
{
    string szName, szClass;
    int iLevel, iHP;

    if(iCapacity == iSize)
    {
        Adventurer* newArray = new Adventurer[iCapacity + 10];
        for(int i=0; i < iCapacity; i++)
        {
            newArray[i] = roster[i];
        }
        delete[] roster;

        roster = newArray;
        iCapacity += 10;
    }

    cout << "Enter adventurer's name: ";
    cin.ignore();
    getline(cin,szName);
    roster[iSize].setName(szName);

    cout << "Enter adventurer's class: ";
    getline(cin,szClass);
    roster[iSize].setClass(szClass);

    cout << "Enter adventurer's level: ";
    cin >> iLevel;
    roster[iSize].setLevel(iLevel);

    cout << "Enter adventurer's hit points: ";
    cin >> iHP;
    roster[iSize].setHP(iHP);

    // roster[iSize] = Adventurer(szName, szClass, iLevel, iHitPoints);

    cout << "Adventurer added successfully!" << endl;
    iSize++;
}

/*********************************************************************
void viewAdventurers(Adventurer* roster, int iSize)
Purpose:
    Display all adventurers in a roster.
Parameters:
    I   Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
Return Value:
    -
Notes:
    This function should call the displayAdventurer function. 
*********************************************************************/
void viewAdventurers(Adventurer* roster, int iSize)
{
    for(int i=0; i<iSize; i++)
    {
        roster[i].displayAdventurer();
    }

}

/*********************************************************************
void selectionSortByHP(Adventurer* roster, int iSize)
Purpose:
    Sorts the roster by hp using selection sort
Parameters:
    I/O Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
Return Value:
    -
Notes:
    This function CANNOT use pre-made sorting libraries
	Sort in descending order
*********************************************************************/
void selectionSortByHP(Adventurer* roster, int iSize)
{
    int iMaxIndex;
   for(int iStart = 0; iStart < iSize - 1; iStart++)
    {
        iMaxIndex = iStart;
      
        for(int iIndex = iStart; iIndex < iSize; iIndex++)
        {
            if(roster[iIndex].getHP() > roster[iMaxIndex].getHP())
            {
                iMaxIndex = iIndex;
            }
        }
        Adventurer temp = roster[iStart];
        roster[iStart] = roster[iMaxIndex];
        roster[iMaxIndex] = temp;     
    } 
}

/*********************************************************************
void insertionSortByLevel(Adventurer* roster, int iSize)
Purpose:
    Sorts the roster by level using insertion sort
Parameters:
    I/O Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
Return Value:
    -
Notes:
    This function CANNOT use pre-made sorting libraries
	Sort in ascending order
*********************************************************************/
void insertionSortByLevel(Adventurer* roster, int iSize)
{
    for(int i =1; i<iSize; i++)
    {
        Adventurer Key = roster[i];

        int iLastSorted = i -1;

        while(iLastSorted >= 0 && roster[iLastSorted].getLevel() > Key.getLevel())
        {
            roster[iLastSorted + 1] = roster[iLastSorted];
            iLastSorted--;
        }
        roster[iLastSorted + 1] = Key;
    } 
}

/*********************************************************************
int linearSearchByName(Adventurer* roster, int iSize, const string& szTargetName)
Purpose:
    Searches roster by name using a linear search
Parameters:
    I   Adventurer* roster              Dynamic roster of adventurers
    I   int iSize                       Current number of adventurers
    I   const string& szTargetName      Name of adventurer to find
Return Value:
    First index of adventurer with target name. Otherwise, -1.
Notes:
    This function CANNOT use pre-made searching libraries.
*********************************************************************/
int linearSearchByName(Adventurer* roster, int iSize, const string& szTargetName)
{
    for(int i=0; i<iSize; i++)
    {
        if(roster[i].getName() == szTargetName)
        {
            return i;
        }
    } 
    return -1;
}

/*********************************************************************
int binarySearchByHP(Adventurer* roster, int iSize, int iTargetHP)
Purpose:
    Sorts the roster by hp using insertion sort
Parameters:
    I   Adventurer* roster              Dynamic roster of adventurers
    I   int iSize                       Current number of adventurers
    I   int iTargetHP                	Level of adventurer to find
Return Value:
    First index of adventurer with target level. Otherwise, -1.
Notes:
    This function CANNOT use pre-made searching libraries.
*********************************************************************/
int binarySearchByHP(Adventurer* roster, int iSize, int iTargetHP)
{
    int iFirst, iLast, iMiddle;
    iFirst = 0;
    iLast = iSize - 1;
    while(iFirst < iLast)
    {
        iMiddle = (iFirst + iLast) / 2;
        if(roster[iMiddle].getHP() == iTargetHP)
        {
            return iMiddle;
        }
        else if(roster[iMiddle].getHP()< iTargetHP)
        {
            iFirst = iMiddle + 1;
        }
        else
        {
            iLast = iMiddle - 1;
        }
    }
    return -1;
}

// Extra credit (You must document yourself)
/*********************************************************************
void insertionSortByLevelWithStats(Adventurer* roster, int iSize, int& iComparisons, int& iSwaps)
Purpose:
    Sorts the roster by level using insertion sort and also tracks the number of comparisons and swaps performed during the sort.
Parameters:
    I/O Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
    I/O int& iComparisons      Count each time there is comparison between two adventurer levels
    I/O int& iSwaps            Count each time there is moving/assigning of an adventurer to a different position in the array
Return Value:
    -
Notes:
    This function CANNOT use pre-made sorting libraries
	Sort in ascending order
*********************************************************************/
void insertionSortByLevelWithStats(Adventurer* roster, int iSize, int& iComparisons, int& iSwaps)
{
	iComparisons = 0;
    iSwaps = 0;

    for(int i =1; i<iSize; i++)
    {
        //Storing an adventurer in a temporary variable - Key
        Adventurer Key = roster[i];
        iSwaps++;

        int iLastSorted = i -1;

        while(iLastSorted >= 0)
        {
            //Compare two adventure levels
            iComparisons++;
            if(roster[iLastSorted].getLevel() > Key.getLevel())
            {
                //Moving an adventurer to a new index
                roster[iLastSorted + 1] = roster[iLastSorted];
                iSwaps++;
                iLastSorted--;
            }
        }
        //Placing the temporary adventurer back into the array
        roster[iLastSorted + 1] = Key;
        iSwaps++;
    }
}