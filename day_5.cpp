#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;



vector<string> split_string(string text, char delim)
{
    vector<string> temp_vec;
    string temp_string = "";
    for(char x : text)
    {
        if (x != delim && x != '\n')
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


int main()
{
    std::ifstream t("input_5.txt");
    string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    vector<vector<char>> vect(9);    


    int row = 0;
    int col = 0;
    int letters = 0;
    int lines = 0;
    char crates[8][9];

    int box_count = 0;
    //int box_per_row[9] = {0,0,0,0,0,0,0,0,0};
    //char boxes_to_be_moved[9] = {0,0,0,0,0,0,0,0,0};
    vector<char> boxes_to_be_moved;

    int col_from;
    int col_to;


    for (int i = 0; i < input.length(); i++)
    {
        letters++;
        if (letters%4 == 2 && lines < 8)
        {
            row = lines;
            //crates[row][col] = input.at(i);
            if(input.at(i) != ' ')
            {
                //box_per_row[col]++;
                vect[col].insert(vect[col].begin(), input.at(i));
            }
            col++;

        }
        

        if(input.at(i) == '\n')
        {
            lines++;
            letters = 0;
            col = 0;
        }

    }

    size_t pos = input.find("move");
    string sub_input = input.substr(pos);

    vector<string> split_input = split_string(sub_input, ' ');


    for(int i = 0; i < split_input.size(); i++)
    {

        switch (i%6)
        {
        case 1:
            //cout << split_input.at(i) << '\n';
            box_count = stoi( split_input.at(i) );
            break;
        case 3:
            //cout << split_input.at(i) << '\n';
            col_from = stoi( split_input.at(i) ) - 1;

            break;
        case 5:
            //cout << split_input.at(i) << '\n';
            col_to = stoi( split_input.at(i) ) - 1;

            for (int i = 0; i < box_count; i++)
            {
                boxes_to_be_moved.push_back(vect[col_from].back());
                vect[col_from].pop_back();
            }

            for (int i = 0; i < box_count; i++) //change [i] to back() and pop it!
            {
                vect[col_to].push_back(boxes_to_be_moved.back());
                boxes_to_be_moved.pop_back();
            }
            boxes_to_be_moved.clear();
            
            break;
        default:
            break;
        }

        //cout << split_input.at(i) << ' ';
        //cout << is_moves;

    }



    for (int i = 0; i < vect.size(); i++)
    {
        cout << i + 1 << ' ';
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }

    cout << '\n';

    for(int i = 0; i < vect.size(); i++)
    {
        cout << vect[i].back();
    }
  

}