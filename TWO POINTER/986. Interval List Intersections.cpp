//PROBLEM :

                You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
                Each list of intervals is pairwise disjoint and in sorted order.
                
                Return the intersection of these two interval lists.
                
                A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
                
                The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, 
                the intersection of [1, 3] and [2, 4] is [2, 3].
 

            Example 1:
            
                Input: firstList = [[0,2],[5,10],[13,23],[24,25]], 
                secondList = [[1,5],[8,12],[15,24],[25,26]]
                Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]


//APPROACH : 
                  since the 2 given list are sorted check the one which overlaps the other 
                  iterate on the basis of the overlapping element

BRUTE FORCE : to make a list of pair of size 2, to store the 2 intervals each time, sort them and check the overlapping
              this reduces the complexity in thinking 3 different cases

//CODE :
            class Solution {
            public:
                vector<vector<int>> intervalIntersection(vector<vector<int>>& fir, vector<vector<int>>& sec) {
                    int i = 0,j = 0;
                    int n = fir.size();
                    int m = sec.size();
                    vector<vector<int>>ans;
                    while(i < n && j < m) {
                        vector<vector<int>>num;
                        num.push_back(fir[i]);
                        num.push_back(sec[j]);
                        sort(num.begin(),num.end());
                        if(num[1][0] <= num[0][1]) {
                            int x = num[1][0];
                            int y = min(num[1][1],num[0][1]); 
                            ans.push_back({x,y});
                        }
                        num.clear();
                        if(fir[i][1] <= sec[j][1]) i++;
                        else j++;
                    }
                    return ans;
                }
            };


//WITHOUT EXTRA SPACE:
          for this approach we will have to check both the cases ie. if first > sec or is sec > fir

//CODE :
            class Solution {
            public:
                vector<vector<int>> intervalIntersection(vector<vector<int>>& fir, vector<vector<int>>& sec) {
                    int i = 0,j = 0;
                    int n = fir.size();
                    int m = sec.size();
                    vector<vector<int>>ans;
                    while(i < n && j < m) {
                        if(fir[i] >= sec[j]) {
                            if(fir[i][0] <= sec[j][1]) {
                                int x = fir[i][0];
                                int y = min(fir[i][1],sec[j][1]);
                                ans.push_back({x,y});
                            }
                        } else {
                            if(sec[j][0] <= fir[i][1]) {
                                int x = sec[j][0];
                                int y = min(sec[j][1],fir[i][1]);
                                ans.push_back({x,y});
                            }
                        }
                        if(fir[i][1] <= sec[j][1]) i++;
                        else j++;
                    }
                    return ans;
                }
            };
                    
