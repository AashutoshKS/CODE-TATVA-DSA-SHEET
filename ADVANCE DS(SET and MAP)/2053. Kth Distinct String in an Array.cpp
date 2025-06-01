//PROBLEM :

        A distinct string is a string that is present only once in an array.
        
        Given an array of strings arr, and an integer k, return the kth distinct string present in arr. 
          If there are fewer than k distinct strings, return an empty string "".
        
        Note that the strings are considered in the order in which they appear in the array.


//APPROACH : simple count and return kth string


//CODE :
        class Solution {
        public:
            string kthDistinct(vector<string>& arr, int k) {
                vector<string>ind;
                unordered_map<string,int>che;
                for(int i=0;i<arr.size();i++){
                    che[arr[i]]++;
                }
                for(int i=0;i<arr.size();i++){
                    if(che[arr[i]]==1){
                        ind.push_back(arr[i]);
                        if(ind.size() == k) break;
                    }
                }
                if(ind.size() < k){
                    return "";
                }
        
                return ind.back();
            }
        };          
