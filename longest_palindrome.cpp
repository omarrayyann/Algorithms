#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int longest_palindrome(string &s, int from, int to)
{
    if(from==to){
        return 1;
    }
    if (s[from] == s[to])
    {
        return longest_palindrome(s,from+1,to-1)
    }
}

int main()
{

    string s = "dasdasdomarramosd";
    cout << "Longest Palindrome: " << longest_palindrome(s, 0, s.length(), mem);
}