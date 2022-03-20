#include "bits/stdc++.h"
using namespace std;

bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}

int canBePalindrome(int n, string s) {
    // Write your code here.
    string S = s;
    // Stores the unique characters in
    // the string
    set<char> st;
 
    for (int i = 0; i < n; i++) {
        st.insert(S[i]);
    }
 
    // Check if valid palindrome is
    // possible or not
    bool check = false;
 
    // Iterating over unique characters
    // of the string
    for (auto ele : st) {
 
        // Pointers to check the condition
        int low = 0, high = n - 1;
        bool flag = true;
 
        // Iterating over the string
        for (int i = 0; i < n; i++) {
            if (S[low] == S[high]) {
 
                // Updating low and high
                low++;
                high--;
            }
 
            else {
                if (S[low] == ele) {
 
                    // Updating low
                    low++;
                }
                else if (S[high] == ele) {
 
                    // Updating high
                    high--;
                }
                else {
 
                    // It is impossible
                    // to make palindrome
                    // by removing
                    // occurrences of char
                    flag = false;
                    break;
                }
            }
        }
 
        // If palindrome is formed
        // break the loop
        if (flag == true) {
            check = true;
            break;
        }
    }
 
    if (check)
        return true;
    else
        return false;
}



int minimumCost(int n, vector<int> &a, vector<string> &s) {
    // Write your code here.
}

int main(int argc, char const *argv[])
{
    cout << canBePalindrome(8, "odrcrdqo");
    return 0;
}
