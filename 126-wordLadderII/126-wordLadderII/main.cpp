//
//  main.cpp
//  126-wordLadderII
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>

using namespace std;

class Solution{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList){
        unordered_set<string> tmpList = wordList;
        int dist = ladderLength(beginWord, endWord, tmpList);
        vector<vector<string>> res;
        vector<string> tmp;
        wordList.insert(endWord);
        map<string, bool> isVisited;
        for (auto word: wordList)
            isVisited[word] = false;
        tmp.push_back(beginWord);
        isVisited[beginWord] = true;
        helper(res, tmp, beginWord, endWord, wordList, isVisited, dist);
        return res;
    }
    
private:
    void helper(vector<vector<string>>& res, vector<string>& tmp, string beginWord, string endWord, unordered_set<string>& wordList, map<string, bool>& isVisited, int dist){
        if (tmp.size() == dist && tmp[dist-1] == endWord){
            res.push_back(tmp);
            return;
        }
        if (tmp.size() > dist){
            return;
        }
//        tmp.push_back(beginWord);
//        isVisited[beginWord] = true;
//        cout << wordList.size() << endl;
        for (int i=0; i<beginWord.size(); i++){
            char letter = beginWord[i];
            for (int j=0; j<26; j++){
                beginWord[i] = j+'a';
                if (wordList.find(beginWord) != wordList.end() && !isVisited[beginWord]){
                    isVisited[beginWord] = true;
                    tmp.push_back(beginWord);
                    
                    helper(res, tmp, beginWord, endWord, wordList, isVisited, dist);
                    tmp.pop_back();
                    isVisited[beginWord] = false;
                }
            }
            beginWord[i] = letter;
        }
    }
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList){
        wordList.insert(endWord);
        queue<string> toVisit;
        toVisit.push(beginWord);
        int dist = 1;
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
    
    void addChild(string word, unordered_set<string>& wordList, queue<string>& toVisit){
        wordList.erase(word);
        for (int i=0; i<word.size(); i++){
            char letter = word[i];
            for (int j=0; j<26; j++){
                word[i]= j+'a';
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
    vector<string> a = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordList;
    for(int i=0; i<a.size(); i++){
        wordList.insert(a[i]);
    }
    Solution st;
    vector<vector<string> > res = st.findLadders("hit", "cog", wordList);
//    cout << res.size() << endl;
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    //    std::cout << "Hello, World!\n";
    return 0;
}
