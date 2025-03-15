//PROBLEM : 
        You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves 
        to indices[i] in the shuffled string.

          
//COMPLEXITY: 
          TIME COMPLEXITY : O(n)
          SPACE COMPLEXITY : O(n)


//CODE : 
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(),' ');
        for(int i=0;i<s.size();i++){
            ans[indices[i]]=s[i];
        }
        return ans;
    }
};
