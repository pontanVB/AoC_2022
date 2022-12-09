#include <fstream>
#include <iostream>
#include <set>
using namespace std;

bool has_dupes(string s)
{
    set<char> char_set;

    for(char x : s)
    {
        if(!char_set.insert(x).second)
            return true;
    }
    return false;

}


int main()
{
    std::ifstream t("input_6.txt");
    string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());    

    string marker = "";
    int distinct_char = 14;

    int chars_needed = 0;

    for (size_t i = 0; i < input.length() - distinct_char; i++)
    {
        marker = input.substr(i, distinct_char);
        if (!has_dupes(marker))
        {
            chars_needed += i;
            break;
        }
    }
        
    cout << '\n' << chars_needed + distinct_char;
}