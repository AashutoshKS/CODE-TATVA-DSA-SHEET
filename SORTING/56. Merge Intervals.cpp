//PROBLEM :
          Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
          and return an array of the non-overlapping intervals that cover all the intervals in the input.


//APPROACH :
            Sort the interval on the basis of the begin time
            check for the overlapping intervals 


//CODE :
            class Solution {
            public:
                vector<vector<int>> merge(vector<vector<int>>& intervals) {
                    sort(intervals.begin() , intervals.end());
                    vector<vector<int>>ans;
                    ans.push_back(intervals[0]);
                    int idx = 0; 
                    for(int i = 1; i < intervals.size(); i++) {
                        if(intervals[i][0] <= ans[idx][1]) {
                            if(intervals[i][1] > ans[idx][1]) {
                                ans[idx][1] = intervals[i][1];
                            }
                        } else {
                            ans.push_back(intervals[i]);
                            idx++ ;
                        }
                    }
                    return ans;
                }
            };
