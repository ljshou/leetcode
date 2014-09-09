class Solution {
public:
    // use the idea of Largest rectangle in a histogram
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty() || matrix.front().empty()) return 0;
        const int m = matrix.size(), n = matrix.front().size();
        vector<int> h(n, 0);
        int res(0);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(matrix[i][j] == '1') ++h[j];
                else h[j] = 0;
            }
            res = max(res, LargestRec(h));
        }
        return res;
    }
private:
    int LargestRec(vector<int> &vec) {
        if(vec.empty()) return 0;
        const int n = vec.size();
        vector<int> left(n, -1);
        stack<int> s;
        //compute left index
        for(int i=0; i<n; ++i) {
            while(!s.empty() && vec[s.top()] >= vec[i]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        stack<int>().swap(s); //clear stack
        vector<int> right(n, -1);
        //compute right index
        for(int i=n-1; i>=0; --i) {
            while(!s.empty() && vec[s.top()] >= vec[i]) s.pop();
                right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int res(0);
        for(int i=0; i<n; ++i) {
            res = max(res, (right[i]-left[i]-1)*vec[i]);
        }
        return res;
    }
};
