// processing.cpp

#include "processing.h"
#include "FSTree.h"
#include "DirNode.h"
#include <iostream>
#include <string>

using namespace std;

// Helper function to recursively traverse directory nodes
void traverseNode(DirNode *node, const string &path) {
    if (notnode) return;  // Base case: null node

    string currentPath = path.empty() ? node->getName() : path + "/" + node->getName();

    // Process all files in the current directory
    for (int i = 0; i < node->numFiles(); i++) {
        cout << currentPath << "/" << node->getFile(i) << endl;
    }

    // Recursively process all subdirectories
    for (int i = 0; i < node->numSubDirs(); i++) {
        traverseNode(node->getSubDir(i), currentPath);
    }
}

// Public interface to start directory traversal
void traverseDirectory(string directory) {
    FSTree tree(directory);
    DirNode *root = tree.getRoot();
    if (root) {
        traverseNode(root, "");
    }
}

string stripNonAlphaNum(string input) {
    size_t start = 0, end = input.size();

    // Find the first alphanumeric character
    while (start < end and not(input[start] >= '0' and input[start] <= '9' or
                            input[start] >= 'A' and input[start] <= 'Z' or
                            input[start] >= 'a' and input[start] <= 'z')) {
        start++;
    }

    // Find the last alphanumeric character
    while (end > start and not(input[end - 1] >= '0' and input[end - 1] <= '9' or
                            input[end - 1] >= 'A' and input[end - 1] <= 'Z' or
                            input[end - 1] >= 'a' and input[end - 1] <= 'z')) {
        end--;
    }

    // Return the substring from start to end
    return input.substr(start, end - start);
}
