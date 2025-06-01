//PROBLEM :

      Design a HashSet without using any built-in hash table libraries.
      
      Implement MyHashSet class:
      
      void add(key) Inserts the value key into the HashSet.
      bool contains(key) Returns whether the value key exists in the HashSet or not.
      void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.


//CODE :
      class MyHashSet {
          vector<bool>set;
      public:
          MyHashSet() : set(1e6 + 1, false) {}
          
          void add(int key) {
              set[key] = true;
          }
          
          void remove(int key) {
              set[key] = false;
          }
          
          bool contains(int key) {
              return set[key] == true;
          }
      };
