//PROBLEM :
        You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
        
        Return the index of the peak element.
        
        Your task is to solve it in O(log(n)) time complexity.


//APPROACH : 
        Can search linearly in O(n)

//BINARY SEARCH :
        Use the property of increasing to decreasing 
        ie from 0 - idx number are sorted
        from i - n number are reverse sorted


//COMPLEXITY :
        TIME COMPLEXITY : O(logn)
        SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            int peakIndexInMountainArray(vector<int>& arr) {
                int start=0;
                int end=arr.size()-1;
                while(start < end){
                    int mid=(start+end)/2;
                    if(arr[mid]<arr[mid+1]){
                        start=mid+1;
                    }
                    else {
                        end=mid;
                    }
                }
                return start;
            }
        };
