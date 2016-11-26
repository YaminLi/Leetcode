//
//  main.cpp
//  208-impletmentTrie
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class TrieNode{
public:
    bool isKey;
    TrieNode* children[26];
    
    TrieNode(){
        isKey = false;
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
private:
    TrieNode* root;
    
public:
    Trie(){
        root = new TrieNode;
    }
    
    void insert(string word){
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++){
            if (node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->isKey = true;
    }
    
    bool search(string word){
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++){
            if (node->children[word[i]-'a'] == NULL)
                return false;
            else {
                node = node->children[word[i]-'a'];
            }
        }
        return node->isKey;
    }
    
    bool startWith(string prefix){
        TrieNode* node = root;
        for (int i=0; i<prefix.size(); i++){
            if (node->children[prefix[i]-'a'] == NULL)
                return false;
            else {
                node = node->children[prefix[i]-'a'];
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Trie trie;
    trie.insert("somestring");
    if (trie.search("somestring"))
        std::cout << "Hello, World!\n";
    return 0;
}
