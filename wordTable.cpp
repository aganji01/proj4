/* wordTable.cpp
 * date: April 19th, 2024
 * Author: Alex Dai, Aarush Ganji
 * utlns: zdai03, aganji01
 * Project 4 - Gerp
 *
 * Description: This file contains implementations for the WordTable class
 */

#include "wordTable.h"
#include <cctype>  // For std::tolower

using namespace std;

// Helper function to convert a string to lowercase
string toLowerCase(const string& input) {
    string output;
    output.reserve(input.size());  // Reserve space to avoid reallocating
    for (char c : input) {
        output += tolower(static_cast<unsigned char>(c));  // Convert each character to lowercase
    }
    return output;
}

// Adds a word to the index along with its file path and line number
void WordTable::addWord(const string& word, const string& filePath, int lineNumber) {
    string lowerWord = toLowerCase(word);  // Convert the word to lowercase before indexing
    // Check if the word already exists in the map
    auto& occurrences = index[lowerWord];
    occurrences.addOccurrence(filePath, lineNumber);
}

// Searches for a word in the index; can specify whether the search should be case-sensitive
vector<string> WordTable::search(const string& word, bool caseSensitive) const {
    string searchKey = caseSensitive ? word : toLowerCase(word);  // Adjust the word based on case sensitivity
    vector<string> results;
    auto it = index.find(searchKey);
    if (it != index.end()) {
        const auto& occurrences = it->second;
        for (size_t i = 0; i < occurrences.filePaths.size(); ++i) {
            results.push_back("File: " + occurrences.filePaths[i] + ", Line: " + to_string(occurrences.lineNumbers[i]));
        }
    }
    return results;
}

