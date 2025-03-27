//PROBLEM :

                You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
                
                horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
                verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
                Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and 
                verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.


//APPROACH :
                Sort both the list 
                find the maximum gap between any 2 cuts in vecrticle and horizontal axis...
                return product of the gaps ie. Area


//COMPLEXITY :
                TIME COMPLEXITY : O(2*n.logn + 2*n) = O(n.logn)
                SPACE COMPLEXITY : O(1)


//CODE :
                class Solution {
                public:
                    int maxArea(int h1, int w, vector<int>& h, vector<int>& v) {
                        sort(h.begin(),h.end());
                        sort(v.begin(),v.end());
                        long long mod = 1000000007;
                        long long len = v[0] - 0;
                        long long height = h[0] - 0;
                        for(int i = 1;i < v.size();i++) {
                            long long c = (v[i] - v[i-1])%mod;
                            len = max(len,c);
                        }
                        for(int i = 1;i < h.size();i++) {
                            long long c = h[i] - h[i-1]%mod;
                            height = max(height,c);
                        }
                        long long c = (w - v.back())%mod;;
                        len = max(len, c);
                        long long c1 = (h1 - h.back())%mod;;
                        height = max(height, c1);
                        return (len*height)%mod;;
                    }
                };
