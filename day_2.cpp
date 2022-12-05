#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
using namespace std;
int rock_paper_scissors(char yours, char pc);

int main()
{

    std::ifstream t("input_2.txt");
    std::string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    char opponent_letter;
    char your_letter;
    long points = 0;
    int loops;

    for(std::string::size_type i = 0; i < input.size(); ++i) {
        if(i%4 == 0)
            opponent_letter = input[i];
        else if(i%4 == 2)
        {
            your_letter = input[i];

            cout << "opponent: " << opponent_letter << ", you: " << your_letter << ", points: " << rock_paper_scissors(your_letter, opponent_letter) << '\n';
            points += rock_paper_scissors(your_letter, opponent_letter);
            loops++;

        }

    }

    cout << "points: " << points << '\n';
    cout << loops;


}

int rock_paper_scissors(char yours, char pc)
{   
    int points = 0;

    if (     yours == 'X' && pc == 'A'){ points = 3; }
    else if (yours == 'X' && pc == 'B'){ points = 1; }
    else if (yours == 'X' && pc == 'C'){ points = 2; }

    else if (yours == 'Y' && pc == 'A'){ points = 4; }
    else if (yours == 'Y' && pc == 'B'){ points = 5; }
    else if (yours == 'Y' && pc == 'C'){ points = 6; }

    else if (yours == 'Z' && pc == 'A'){ points = 8; }
    else if (yours == 'Z' && pc == 'B'){ points = 9; }
    else if (yours == 'Z' && pc == 'C'){ points = 7; }
    
    
    //cout << points << '\n';
    return points;
}