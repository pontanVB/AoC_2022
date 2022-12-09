#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm> 
using namespace std;

vector<string> split_string(string text, char delim)
{
    vector<string> temp_vec;
    string temp_string = "";
    for(char x : text)
    {
        if (x != delim)
        {
            temp_string += x;
        }
        else
        {
            temp_vec.push_back(temp_string);
            temp_string = "";
        }
    }
    temp_vec.push_back(temp_string);
    return temp_vec;
}

vector<vector<int>> get_pair(string s)
{
    vector<vector<int>> temp_pair (2);
    string min_number = "";
    string max_number = "";
    string number = "";
    for(char c : s)
    {
        if (c == '-')
        {
            min_number = number;
            number = "";
        }
        else if (c == ',')
        {
            temp_pair[0].resize(stoi(number) - stoi(min_number) + 1);
            temp_pair[0][0] = stoi(min_number);
            number = "";

        }
        else
            number += c;

    }
    temp_pair[1].resize(stoi(number) - stoi(min_number) + 1);
    temp_pair[1][0] = stoi(min_number);

    for(int i = 0; i < temp_pair.size(); i++)
        std::iota(temp_pair[i].begin(), temp_pair[i].end(), temp_pair[i].front());


    return temp_pair;
}

int max(int x, int y) { if(x > y) return x; else return y; }
int min(int x, int y) { if(x < y) return x; else return y; }


int dupe_amount(int first1, int last1, int first2, int last2)
{
    int dupes = 0;
    if(first1 > last2 || first2 > last1)
        return 0;
    else if (first1 == last2 || first2 == last1)
        return 1;
    else
        return 1;
    

    return 0;
}

int main()
{
    int overlap = 0; 
    std::ifstream t("input_4.txt");
    string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    vector<string> string_split = split_string(input, '\n');


    vector<vector <int>> test = get_pair(string_split.front());

    vector<vector <int>> duplicates(2);

    for (string s : string_split)
    {
        test = get_pair(string_split.back());
        //cout << string_split.back() << '\n';
        string_split.pop_back();
        /*
        if (std::includes(test[0].begin(), test[0].end(), test[1].begin(), test[1].end()) || 
                std::includes(test[1].begin(), test[1].end(), test[0].begin(), test[0].end()))
        {
        }
        */
        overlap += dupe_amount(test[0].front(), test[0].back(), test[1].front(), test[1].back());

    }

    for(string s : string_split)
        cout << s << '\n';


    /*
    for (size_t i = 0; i < test.size(); i++)
    {
        for(int x : test[i])
            cout << x << ' ';
        cout << '\n';
    }
    */

   cout << overlap;
    

}