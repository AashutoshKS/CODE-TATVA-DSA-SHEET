//PROBLEM :
              Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, 
                return the researcher's h-index.
              
              According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher 
              has published at least h papers that have each been cited at least h times



//APPROACH : 
            Sort and find the minimum value till nums is greater than i


//COMPLEXITY : 
            TIME COMPLEXITY : O(n.logn)
            SPACE COMPLEXITY : O(1)


//CODE :
            
            class Solution {
            public:
                int hIndex(vector<int>& cat) {
                    sort(cat.rbegin(), cat.rend());
                    int n = cat.size();
                    int i = 0;
                    while (i < n && i < cat[i]) {
                        i++;
                    }
                    return i;
                }
            };
