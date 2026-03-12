// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2025-07-23

#include <bits/stdc++.h>
// #include <debug.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
public:
    
};

void maruf(int t){
    string s = "Hello";

    // 1. length() or size()
    cout << "Length: " << s.length() << endl;

    // 2. at(index)
    cout << "Char at index 1: " << s.at(1) << endl;

    // 3. front() and back()
    cout << "Front: " << s.front() << endl;
    cout << "Back: " << s.back() << endl;

    // 4. append() or +=
    s.append(" World");
    cout << "After append: " << s << endl;

    s += "!";
    cout << "After +=: " << s << endl;

    // 5. push_back() and pop_back()
    s.push_back('?');
    cout << "After push_back: " << s << endl;

    s.pop_back();
    cout << "After pop_back: " << s << endl;

    // 6. substr(pos, len)
    string sub = s.substr(6, 5); // "World"
    cout << "Substring: " << sub << endl;

    // 7. insert(pos, str)
    s.insert(5, ",");
    cout << "After insert: " << s << endl;

    // 8. erase(pos, len)
    s.erase(5, 1);
    cout << "After erase: " << s << endl;

    // 9. find(str)
    size_t pos = s.find("World");
    if (pos != string::npos)
        cout << "'World' found at: " << pos << endl;

    // 10. rfind(str)
    cout << "Last occurrence of 'l': " << s.rfind("l") << endl;

    // 11. replace(pos, len, str)
    s.replace(6, 5, "Universe");
    cout << "After replace: " << s << endl;

    // 12. compare(str)
    cout << "Compare with 'Hello': " << s.compare("Hello") << endl;

    // 13. clear()
    string temp = "temporary";
    temp.clear();
    cout << "After clear: '" << temp << "' Length: " << temp.length() << endl;

    // 14. empty()
    cout << "Is empty? " << temp.empty() << endl;

    // 15. c_str()
    const char* cstr = s.c_str();
    cout << "C-style string: " << cstr << endl;

    // 16. resize()
    s.resize(5);
    cout << "After resize to 5: " << s << endl;

    s.resize(10, '*');
    cout << "After resize to 10 with '*': " << s << endl;

    // 17. swap()
    string a = "abc", b = "xyz";
    a.swap(b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // 18. copy() [copies characters to a char array]
    char buf[6];
    string ex = "Example";
    ex.copy(buf, 5, 0); // copy 5 chars from index 0
    buf[5] = '\0';
    cout << "Copied: " << buf << endl;

    // 19. getline() - input from user
    // string userInput;
    // cout << "Enter a line: ";
    // getline(cin, userInput);
    // cout << "You entered: " << userInput << endl;
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}