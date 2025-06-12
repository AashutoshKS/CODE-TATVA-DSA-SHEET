//PROBLEM :
      
      Implement the MyHashMap class:
      
      MyHashMap() initializes the object with an empty map.
      void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
      int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
      void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.


//CODE :
      class MyHashMap {
      public:
          map<int,int>mp;    
          void put(int key, int value) {
              mp[key] = value + 1;
          }
          
          int get(int key) {
              if(mp[key] == 0) return -1;
              return mp[key] - 1;
          }
          void remove(int key) {
              mp[key] = 0;
          }
      };
