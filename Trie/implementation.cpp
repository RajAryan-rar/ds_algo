#include<iostream>
#include<unordered_map>
using namespace std;
//Leetcode 208
class Node {
    public : 
    char data;
    bool isTerminal;
    unordered_map<char, Node*> children;

    Node(char data) {
        this->data = data;
        this->isTerminal = false;
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
            }
            else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }
        curr->makeTerminal();
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* T = new Trie();
    T->insert("sam");
    T->insert("sanket");

    bool test1 = T->search("sanket");
    if(test1) cout<<"true"<<endl;
    else cout<<"false";

    bool test2 = T->startsWith("sa");
    if(test2) cout<<"true"<<endl;
    else cout<<"false";

    return 0;
}