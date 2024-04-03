#ifndef WORDCLIST_H
#define WORDCLIST_H

#include "WordList.h"
#include "WordData.h"
#include "CLinkedList.h" // Include the circular linked list header
#include <fstream>

class WordCList : public WordList {
    CLinkedList<WordData> words;

public:
    virtual void parseIntoList(std::ifstream &inf) override;
    virtual void printIteratively() override;
    virtual void printRecursively() override;

private:
    // As CLinkedList is inherently circular and can naturally handle recursive behavior,
    // additional private methods may not be necessary. However, customization based on
    // CLinkedList's structure and specific needs can be added here.
};

#endif // WORDCLIST_H
