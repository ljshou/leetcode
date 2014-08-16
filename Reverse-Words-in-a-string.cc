class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        string res, word;
        for(auto x : s) {
            if(x == ' ') {
                if(!word.empty()) {
                    res = ' ' + word + res;
                    word.clear();
                }
                continue;
            }
            word.push_back(x);
        }
        if(!word.empty()) res = ' ' + word + res; // do not forget
        if(!res.empty()) res.erase(res.begin());
        res.swap(s);
    }
};
