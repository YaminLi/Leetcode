//
//  main.cpp
//  68-textJustification
//
//  Created by Michael on 10/20/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> res;
        for (int i=0; i<words.size();) {
            vector<string> tmp;
            int count = 0;
            int width = 0;
            while (i<words.size() && width+words[i].size()+count <= maxWidth) {
                tmp.push_back(words[i]);
                width += words[i].size();
                count++;
                i++;
            }
            string s = tmp[0];
            for (int j=1; j<count; j++) {
                if (i >= words.size()) {
                    s += " ";
                }
                else if (j <= (maxWidth-width)%(count-1))
                    s += string((maxWidth-width)/(count-1)+1, ' ');
                else
                    s += string((maxWidth-width)/(count-1), ' ');
                s += tmp[j];
            }
            s += string(maxWidth-s.size(), ' ');
            res.push_back(s);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<string> a = {"This", "is", "an", "example", "of", "text","justification"};
    vector<string> res = st.fullJustify(a, 16);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
