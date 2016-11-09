//
//  main.cpp
//  127-wordLadder
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList){
        wordList.insert(endWord);
        queue<string> toVisit;
        int dist = 1;
        toVisit.push(beginWord);
        while (!toVisit.empty()){
            int len = toVisit.size();
            for (int i=0; i<len; i++){
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addChild(word, wordList, toVisit);
            }
            dist++;
        }
        return 0;
    }
   
private:
    void addChild(string word, unordered_set<string>& wordList, queue<string>& toVisit){
        wordList.erase(word);
        for (int i=0; i<word.size(); i++){
            char letter = word[i];
            for (int j=0; j<26; j++){
                word[i] = 'a'+j;
                if (wordList.find(word) != wordList.end()){
                    toVisit.push(word);
                    wordList.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    unordered_set<string> wordList;
    vector<string> a = {"hot","dot","dog","lot","log"};
    for (int i=0; i<a.size(); i++){
        wordList.insert(a[i]);
    }
    Solution st;
    cout << st.ladderLength("hit", "cog", wordList);
//    std::cout << "Hello, World!\n";
    return 0;
}
