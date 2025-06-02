//PROBLEM :

    Note: This is a companion problem to the System Design problem: Design TinyURL.
    TinyURL is a URL shortening service where you enter a URL such as https:
    //leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.
    
    There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
    
    Implement the Solution class:
    
    Solution() Initializes the object of the system.
    String encode(String longUrl) Returns a tiny URL for the given longUrl.
    String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.



//APPROACH : 
    you just have to change the name to shorten it 
    Why to do so if you can store the same name as its tiny URL?
    simple use the big URL as tiny URL
    is you dont want to do so assign numeric values to each URL


//CODE :
    class Solution {
    public:
        string encode(string longUrl) {
            return longUrl;
        }
        string decode(string shortUrl) {
            return shortUrl;
        }
    };
         
