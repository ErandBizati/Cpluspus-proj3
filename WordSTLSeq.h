#ifndef WORDSTLSEQ_H
#define WORDSTLSEQ_H

#include "WordList.h"
#include "WordData.h"
#include <vector>
#include <fstream>
#include <algorithm>

class WordSTLSeq : public WordList {
    std::vector<WordData> words;

public:
    virtual void parseIntoList(std::ifstream &inf) override;
    virtual void printIteratively() override;
    virtual void printRecursively() override;

private:
    void printRecursivelyHelper(size_t index);
};

#endif // WORDSTLSEQ_H
