/****************************************************************/
/*   Author:         Dr. Spiegel                                */
/*   Course:         CIS237                                     */
/*   Filename:       app.cpp                                    */
/*   Purpose:        This Example inputs a string and demon-    */
/*                   strates how to store it using a subclass   */
/*                   of an abstract base class that incorporates*/
/*                   virtual functions to enable polymorphism   */
/*                   If a file name is                          */
/*                   input through the command line all of the  */
/*                   options will be done automatically for the */
/*                   first line of the file                     */
/****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "WordList.h"
#include "WordDataList.h"
#include "WordSTLSeq.h"
#include "WordCList.h"
// #include "WordData.h"        app only knows about the lists!

using namespace std;

void displayMenu();
/*********************************************************************/
/*   Function Name: displayMenu()                                    */
/*                                                                   */
/*   Description: Displays the menu on the screen.                   */
/*********************************************************************/

void printEverything(ifstream &inf,WordList *&TheList);
/*********************************************************************/
/*                                                                   */
/*   Function Name: printEverything                                  */
/*                                                                   */
/*   Description: Takes in a sentence and sends it through every     */
/*                parsing and printing function                      */
/*                                                                   */
/*   Parameters:  string sentence - sent to every function           */
/*                WordDataList TheList - The array of object         */
/*********************************************************************/


int main(int argc, char *argv[]) {
    ifstream inf;
    WordList *TheList = nullptr;

    // Check if a file name was provided as a command line argument
    if (argc > 1) {
        inf.open(argv[1]);
        if (inf.fail()) {
            cout << "Sorry, the file \"" << argv[1] << "\" failed to open." << endl;
            return 1;
        }
        // Process the file with a default WordList object
        TheList = new WordDataList(); // Default choice for command line argument case
        processFile(inf, TheList);    // Process the file
        delete TheList;               // Clean up
        inf.close();                  // Close the file
        return 0;                     // Exit after processing the file
    }

    // No command line argument provided, enter interactive mode
    string fileName;
    cout << "Please enter a file name: ";
    getline(cin, fileName);
    inf.open(fileName.c_str());

    if (inf.fail()) {
        cout << "Failed to open the file: " << fileName << endl;
        return 1;
    }

    char selection = '0'; // Initialize selection
    while (selection != '8') { // '8' is the exit option
        displayMenu();
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the buffer

        // Clean up any previously used WordList
        if (TheList != nullptr) {
            delete TheList;
            TheList = nullptr;
        }

        switch (selection) {
            case '1':
            case '2':
            case '3':
                TheList = new WordDataList();
                break;
            case '4':
            case '5':
                TheList = new WordCList();
                break;
            case '6':
            case '7':
                TheList = new WordSTLSeq();
                break;
            case '8': // Exit option
                cout << "Exiting the program." << endl;
                continue; // Skip the rest of the loop and proceed to cleanup
            default:
                cout << "Invalid selection, please try again." << endl;
                continue; // Prompt menu again
        }

        // Common processing for non-exit selections
        inf.clear(); // Clear any error flags
        inf.seekg(0, ios::beg); // Rewind file
        processFile(inf, TheList); // Process the file according to the selected option
    }

    if (TheList != nullptr) {
        delete TheList; // Final cleanup
    }
    inf.close(); // Ensure the file is closed before exiting

    return 0;
}

void processFile(ifstream &inf, WordList* &TheList) {
    TheList->parseIntoList(inf);
    // additional logic here for different print options // tbd
}

void displayMenu() {
    cout << "\nSelect an operation:" << endl;
    cout << "1: Object Array Iterative" << endl;
    cout << "2: Object Array Recursive" << endl;
    cout << "3: Object Array Pointer Only" << endl;
    cout << "4: Circular List Iterator" << endl;
    cout << "5: Circular List Iterator Recursive" << endl;
    cout << "6: STL Vector Iterative" << endl;
    cout << "7: STL Vector Recursive" << endl;
    cout << "8: Exit" << endl;
}

void printEverything(ifstream &inf, WordList *&TheList) {
    TheList->parseIntoList(inf);
    TheList->printIteratively();
    TheList->printRecursively();
    TheList->printPtr();
    // Check if TheList supports printPtr before attempting to call it
}