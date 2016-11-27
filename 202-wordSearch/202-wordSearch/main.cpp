//
//  main.cpp
//  202-wordSearch
//
//  Created by Michael on 11/26/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

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
public:
    Trie(){
        root = new TrieNode();
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
            node = node->children[word[i]-'a'];
        }
        return node->isKey;
    }
    
    bool startWith(string prefix){
        TrieNode* node = root;
        for (int i=0; i<prefix.size(); i++){
            if (node->children[prefix[i]-'a'] == NULL)
                return false;
            node = node->children[prefix[i]-'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

class Solution{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty()) return res;
        Trie trie;
        for (string word:words){
            trie.insert(word);
        }
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_set<string> set;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                helper(set, "", board, i, j, visited, trie);
            }
        }
        for (auto s:set)
            res.push_back(s);
        return res;
    }
    
private:
    void helper(unordered_set<string>& set, string s, vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, Trie trie){
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]) return;
        s += board[i][j];
        if (!trie.startWith(s)) return;
        if (trie.search(s))
            if (!set.count(s))
                set.insert(s);
        visited[i][j] = true;
        helper(set, s, board, i+1, j, visited, trie);
        helper(set, s, board, i-1, j, visited, trie);
        helper(set, s, board, i, j+1, visited, trie);
        helper(set, s, board, i, j-1, visited, trie);
        visited[i][j] = false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> board = {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
        };
    vector<string> words = {"oath","pea","eat","rain"};
    Solution st;
    vector<string> res = st.findWords(board, words);
    for (auto s:res)
        cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
