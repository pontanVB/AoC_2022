#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <list>
using namespace std;


int main()
{

    list<int> nubers;

    std::ifstream t("input_1.txt");
    std::string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());


    int maxium;
    int second_most;
    int third_most;

    int dwarf_nr;
    int max_dwarf;
    string number = "0";


    for(char num : input)
    {
        int sum;

        if(num != '\n')
        {
            number += num;

        }
        else if (num == '\n')
        {
            if(number != "")
            {
                sum += stoi(number);
                number = "";

            }
            else
            {  
                sum = 0;
                dwarf_nr += 1;

            }

        }


        if(sum > maxium)
        {
            third_most = second_most;
            second_most = maxium;
            maxium = sum;
        }
        else if (sum > second_most)
        {
            third_most = second_most;
            second_most = sum;
        }
        else if (sum > third_most)
        {
            third_most = sum;
        }

    }

    cout << maxium + second_most + third_most;

}

