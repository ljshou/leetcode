class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        dfs(0, 0, path, s, res);
        return res;
    }
private:
    void dfs(int cur, int n, string &path, string &s, vector<string> &res) {
        if(cur == s.size() && n == 4) {
            res.push_back(path.substr(0, path.size()-1));
            return;
        }
        //剪枝
        if((4-n)*3 + cur < s.size()) return;
        if((4-n) + cur > s.size()) return;
        for(int i=1; i<=3 && i+cur<=s.size(); ++i) {
            if(isValid(s.substr(cur, i))) {
                path += s.substr(cur, i) + '.';
                dfs(cur+i, n+1, path, s, res);
                path.resize(path.size()-i-1);
            }
        }
    }
    bool isValid(const string &str) {
        if(str.size() > 1 && str[0] == '0') return false;
        int num = atoi(str.c_str());
        return num >= 0 && num <= 255;
    }
};
