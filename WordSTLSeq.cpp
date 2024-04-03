#include "WordSTLSeq.h"
#include <iostream>

// Parse input file into list
void WordSTLSeq::parseIntoList(std::ifstream &inf) {
    std::string word;
    while (inf >> word) {
        auto it = std::find_if(words.begin(), words.end(), [&word](const WordData& wd) { return wd.getWord() == word; });
        if (it != words.end()) {
            it->incCount();
        } else {
            words.emplace_back(word, 1);
            std::sort(words.begin(), words.end(), [](const WordData& a, const WordData& b) { return a.getWord() < b.getWord(); });
        }
    }
}

// Print the list iteratively
void WordSTLSeq::printIteratively() {
    for (const auto& wd : words) {
        std::cout << wd << std::endl;
    }
}

// Print the list recursively
void WordSTLSeq::printRecursively() {
    if (!words.empty()) {
        printRecursivelyHelper(0);
    }
}

// Helper for recursive print
void WordSTLSeq::printRecursivelyHelper(size_t index) {
    if (index < words.size()) {
        std::cout << words[index] << std::endl;
        printRecursivelyHelper(index + 1);
    }
}
