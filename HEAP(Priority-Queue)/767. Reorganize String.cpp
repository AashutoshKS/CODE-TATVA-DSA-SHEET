//PROBELM :

      Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

      Return any possible rearrangement of s or return "" if not possible.


//APPROACH :
      
      Since no adj char can be equal find frequencies of each charector
      -> if the maximum frequency charector is > n/2 return "" since it is not possible to arrange such string
      -> else arrange then in alternate order.


//COMPLEXITY :
        TIME COMPLEXITY : O(2)
        SPACE COMPLEXITY : O(26) = O(1)

        
        
//CODE :
        class Solution {
        public:
            string reorganizeString(string s) {
          	vector<int> nums(26);
          	int max = 0, i = 0;
          
          	for(int i = 0;i < s.size(); i++) {
                  nums[s[i] - 'a']++;
                  if(nums[s[i] - 'a'] > nums[max]) max = s[i] - 'a';
              }
          	if((2 * nums[max] - 1) > s.size()) return "";
          	while(nums[max]) {
          		s[i] = ('a' + max);
          		i += 2;
          		nums[max]--;
          	}
          	for(int j = 0; j < 26; j++) {
          		while(nums[j]) {
          			if(i >= s.size()) 
                          i = 1;
          			s[i] = ('a' + j);
          			nums[j]--;
          			i += 2;
          		}
          	}
          	return s;
              }
          };
