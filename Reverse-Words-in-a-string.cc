class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        string res, word;
        for(auto x : s) {
            if(x == ' ') {
                if(!word.empty()) {
                    reverse(word.begin(), word.end());
                    res += word + ' ';
                    word.clear();
                }
                continue;
            }
            word.push_back(x);
        }
        if(!word.empty()) { //do not forget
          reverse(word.begin(), word.end());
          res += word + ' ';
        }
        if(!res.empty()) res.pop_back();
        reverse(res.begin(), res.end());
        res.swap(s);
    }
};
