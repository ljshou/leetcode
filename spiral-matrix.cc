class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty() || matrix.front().empty()) return res;
        int m = matrix.size(), n = matrix.front().size();
        int start = 0;
        while(m > 1 && n > 1) {
            for(int i=start; i<start+n-1; ++i)
                res.push_back(matrix[start][i]);
                
            for(int i=start; i<start+m-1; ++i)
                res.push_back(matrix[i][start+n-1]);
            
            for(int i=start+n-1; i>start; --i)
                res.push_back(matrix[start+m-1][i]);
                
            for(int i=start+m-1; i>start; --i)
                res.push_back(matrix[i][start]);
            
            ++start;
            m -= 2;
            n -= 2;
        }
        
        if(m == 0 || n == 0) return res;
        
        if(m == 1) {
           for(int i=start; i<=start+n-1; ++i)
                res.push_back(matrix[start][i]); 
        }
        else if(n == 1) {
            for(int i=start; i<=start+m-1; ++i)
                res.push_back(matrix[i][start+n-1]);
        }
        return res;
    }
};
