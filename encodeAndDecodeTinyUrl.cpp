#include <iostream>
#include <random>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, string> mp;
public:
    string generateRandomString(int i) {
        int n = 3;
        string chars = "1234567890qwertyuiopqasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
        string ans = "";
        ans.reserve(n);
        srand(i);
        while(n--) {
            ans += chars[rand() % chars.size()];
        }
        return "http://aayushmaticc.code/" + ans;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = generateRandomString(longUrl.size());
        this->mp[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};
