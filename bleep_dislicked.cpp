#include "std_lib_facilities.h"

string bleep(const string &temp){
    string disliked = "broccoli";
    string bleeped = "BLEEP";
    if (temp != disliked)
        return temp;
    else
        return bleeped;
}

int main()
{
    vector<string> words;
    for (string temp; cin >> temp;){
        if (temp == "|")
            break;
        else
        words.push_back(bleep(temp));
    }
    for (string s : words){
        cout << s << "\n";
    }
    return 0;
}
