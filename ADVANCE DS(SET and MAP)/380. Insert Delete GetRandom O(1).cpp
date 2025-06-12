//PROBLEM :

      RandomizedSet() Initializes the RandomizedSet object.
      bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
      bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
      int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
        Each element must have the same probability of being returned.
      You must implement the functions of the class such that each function works in average O(1) time complexity.


//APPROACH :
      make buckets of specific range and use random function for random values


//CODE  :
      class RandomizedSet {
      public:
          unordered_map<int,int>mp;
          vector<int>nums;
          bool insert(int val) {
              if(mp[val] == 0) {
                  nums.push_back(val);
                  mp[val] = nums.size();
                  return true;
              }
              return false;
          }
          
          bool remove(int val) {
              if(mp[val] > 0) {
                  int l = nums.back();
                  mp[l] = mp[val];
                  nums[mp[val] - 1] = l;
                  nums.pop_back();
                  mp[val] = 0;
                  return true;
              }
              return false;
          }
          int getRandom() {
              return nums[rand() % nums.size()];
          }
      };
