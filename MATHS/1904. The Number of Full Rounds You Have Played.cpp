//PROBLEM :

        You are participating in an online chess tournament. There is a chess round that starts every 15 minutes. The first round of the day starts at 00:00, and after every 15 minutes, a new round starts.
        
        For example, the second round starts at 00:15, the fourth round starts at 00:45, and the seventh round starts at 01:30.
        You are given two strings loginTime and logoutTime where:
        
        loginTime is the time you will login to the game, and
        logoutTime is the time you will logout from the game.
        If logoutTime is earlier than loginTime, this means you have played from loginTime to midnight and from midnight to logoutTime.
        
        Return the number of full chess rounds you have played in the tournament.
        
        Note: All the given times follow the 24-hour clock. That means the first round of the day starts at 00:00 and the last round of the day starts at 23:45.



//APPROACH :
          compute the total minutes in start and end time
          check if end time is less than start time that means that we have got a cycle
              ie a new day....




//CODE :
        class Solution {
        public:
            int numberOfRounds(string t1, string t2) {
        
                int start = stoi(t1.substr(0, 2)) * 60 + stoi(t1.substr(3, 2));
                int end   = stoi(t2.substr(0, 2)) * 60 + stoi(t2.substr(3, 2));
        
                if(end < start) end += 24*60;
                start = (start + 14) / 15 * 15;
                end = end / 15 * 15;
        
                if(end < start) return 0;
                return (end - start) / 15;
            }
        };
