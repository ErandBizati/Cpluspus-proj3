#include "WordCList.h"
#include <iostream>

// Parse input file into list
void WordCList::parseIntoList(std::ifstream &inf) {
    std::string word;
    while (inf >> word) {
        // Since CLinkedList doesn't directly support search before insertion,
        // consider a design where you either extend CLinkedList to include this functionality,
        // or handle it externally before calling insert.
        // This might involve traversing the list to check for existence and only inserting if the word is new.

        // Example insertion, actual logic for checking duplicates needs to be implemented
        words.insert(WordData(word)); // Adjust according to CLinkedList's insert method
    }
}

// Print the list iteratively
void WordCList::printIteratively() {
    // Leveraging CLinkedList's circular nature for iteration
    words.printForward(); // Assuming printForward() method exists
}

// Print the list recursively
void WordCList::printRecursively() {
    // Implement recursive print logic. This could involve creating a wrapper around CLinkedList
    // methods or enhancing CLinkedList with recursive print capabilities.
}

