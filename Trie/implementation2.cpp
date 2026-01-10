#include<iostream>
#include<unordered_map>
using namespace std;
/*
You need to implement a [Trie](/problems/trie_intro) class with the following methods:

[Trie](/problems/trie_intro)(): Constructor that initializes an empty trie object.

insert(word): Adds a string word to the trie. If the same word is inserted multiple times,
             the trie should keep track of how many times it has been inserted.

countWordsEqualTo(word): Returns the count of how many times the exact string word exists in the trie.
                         If the word has been inserted 3 times, this should return 3.

countWordsStartingWith(prefix): Returns the total count of all strings in the trie that 
                                begin with the given prefix. For example,
                                if the trie contains "apple" (inserted twice) and "application" (inserted once), then countWordsStartingWith("app") should return 3.

erase(word): Removes one instance of the string word from the trie. 
            This assumes the word exists in the trie before calling erase.

The key difference from a standard Trie implementation is that this version needs to:

Track multiple occurrences of the same word (a word can be inserted multiple times)
Count words with specific prefixes considering their multiplicity
Support deletion of words while maintaining accurate counts
*/

class Node {
    public : 
    char data;
    bool isTerminal;
    int countWordsStarting;
    int countWordsEndingHere;
    unordered_map<char, Node*> children;

    Node(char data) {
        this->data = data;
        this->isTerminal = false;
        this->countWordsStarting = this->countWordsEndingHere = 0;
    }

    void makeTerminal() {
        this->isTerminal = true;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
                curr->countWordsStarting++;
            }
            else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
                curr->countWordsStarting++;
            }
        }
        curr->countWordsEndingHere++;
        curr->makeTerminal();
    }

    int countWordsEqualTo(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            }
            else return 0;
        }
        return curr->countWordsEndingHere;
    }

    int countWordsStartingWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.length(); i++) {
            char ch = prefix[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            }
            else return 0;
        }
        return curr->countWordsStarting;
    }

    void erase(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            curr = curr->children[ch];
            curr->countWordsStarting--;
        }
        curr->countWordsEndingHere--;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            }
            else return false;
        }
        if(curr->isTerminal == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.length(); i++) {
            char ch = prefix[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            }
            else return false;
        }
        
        return true;
    }
};

int main() {
    

    return 0;
}