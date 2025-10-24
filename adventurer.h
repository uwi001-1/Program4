#include <iostream>

using namespace std;

inline string szBreakMessage = "*****************************\n";

/*********************************************************************
Class Name: Adventurer
Purpose:
    Each adventurer has specific attributes like their name, level, 
    and hit points. Provides accessor and mutator functions for each 
    attribute.
Notes:
    This is used for a Dungeon Master (DM) to create an adventurer. 
*********************************************************************/
class Adventurer
{
    private:
        string szName;          // Name of the adventurer
        string szClass;         // Class they are playing (Ex: Wizard)
        int iLevel;             // What level they are (1-20)
        int iHP;                // How much HP they have
    public:
        Adventurer();
        Adventurer(string szN, string szC, int iL, int iH);
        string getName();
        void setName(string szN);
        string getClass();
        void setClass(string szC);
        int getLevel();
        void setLevel(int iL);
        int getHP();
        void setHP(int iH);
        void displayAdventurer();
};


void displayMenu(string szMenuName, string szChoicesArr[], int iChoices);
void addAdventurer(Adventurer*& roster, int& iSize, int& iCapacity);
void viewAdventurers(Adventurer* roster, int iSize);
void selectionSortByHP(Adventurer* roster, int iSize);
void insertionSortByLevel(Adventurer* roster, int iSize);
int linearSearchByName(Adventurer* roster, int iSize, const string& szTargetName);
int binarySearchByHP(Adventurer* roster, int iSize, int iTargetHP);
void insertionSortByLevelWithStats(Adventurer* roster, int iSize, int& iComparisons, int& iSwaps);
