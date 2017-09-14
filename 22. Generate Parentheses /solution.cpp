class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp;
        gPhelper(n, n, result, tmp);
        return result;
    }
    
    void gPhelper(int left, int right, vector<string> &result, string tmp){
        if ((left == 0) && (right == 0)) {
           // cout<<tmp<<endl;
            result.push_back(tmp);
            return;
        }
        if (left > right) return;
        if (left > 0) {
            gPhelper(left - 1, right, result, tmp + "(");
        }
        if (right > 0) {
            gPhelper(left, right - 1, result, tmp + ")");
        }
        
    }
};