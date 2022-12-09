#include <iostream>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

int find_dupe(string sub1, string sub2, string sub3);



int main()
{
    std::ifstream t("input_3.txt");
    string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    int sum_prio = 0;
    int sub_prev = 0;
    int lines = 0;
    string sub_str_1;
    string sub_str_2;
    string sub_str_3;
    

    for (int i = 0; i < input.length(); i++)
    {
        if (input.at(i) == '\n')
        {
            string sub_str = input.substr(sub_prev, i-sub_prev);
            //string sub_str_1 = sub_str.substr(0, sub_str.length()/2 + 1);
            //string sub_str_2 = sub_str.substr(sub_str.length()/2 + 1, sub_str.length()/2);

            switch (lines%3)
            {
            case 0:
                sub_str_1 = sub_str;
                break;
            case 1:
                sub_str_2 = sub_str;
                break;
            case 2:
                sub_str_3 = sub_str;
                sum_prio += find_dupe(sub_str_1, sub_str_2, sub_str_3);
                //cout << sub_str_1 << ' ' << sub_str_2 << ' ' << sub_str_3 <<'\n';

                break;
            
            default:
                break;
            }
            
            //cout << sub_str << '\n';
            lines++;
            sub_prev = i;

        }
        
    }

    cout << sum_prio << '\n';

}

int find_dupe(string sub1, string sub2, string sub3)
{
    for(char x : sub1)
    {
        for(char y : sub2)
        {
            for(char z : sub3)
            {
                if(x == y && x==z && islower(x))
                {
                    //cout << x << ' ' << y << '\n';

                    return x - 96;
                }
                else if(x == y && x==z && isupper(x))
                {
                    //cout << x << ' ' <<  y << '\n';

                    return x - 38;
                }
            }
        }
    }

    return 0;

}
