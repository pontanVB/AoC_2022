#include <fstream>
#include <iostream>
#include <list>
#include <map>
using namespace std;

int strcmp ( const char * str1, const char * str2 );


class File {
    public:
    int size;
    string name;

};

class Folder {    // The class
  public:         // Access specifier
    string Name;  // Attribute (string variable)
    list<Folder> sub_folders;
    list<File> files;
    long get_total_value();
    
};

long Folder::get_total_value()
{
    long total_val = 0;
    for(File f : files)
        total_val += f.size;

    for(Folder f : sub_folders)
        total_val += f.get_total_value();

    return total_val;
}



list<string> split_string(string text, char delim)
{
    list<string> temp_vec;
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
    std::ifstream t("input_7.txt");
    string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>()); 

    list<string> inputs = split_string(input, ' ');

    Folder start_folder;
    start_folder.Name = "/";

    map<string, Folder> all_folders = {{"/", start_folder}};

    string s = "";


    Folder*curr_folder = &start_folder;

    while(inputs.size())
    {
        string curr_s = inputs.front();


        //cout << curr_s;
        //cout << curr_folder->Name;
        if(curr_s == "ls")
        {
        inputs.pop_front();
            while (inputs.size())
            {
                if (inputs.front() == "dir")
                {
                    inputs.pop_front();
                    Folder tmp_folder;
                    tmp_folder.Name = inputs.front();
                    inputs.pop_front();
                    all_folders[tmp_folder.Name] = tmp_folder;
                    curr_folder->sub_folders.push_front(tmp_folder);
                }
                else if(inputs.front() == "$")
                {
                    inputs.pop_front();
                    break;
                }
                else
                {
                    File tmpfile;
                    tmpfile.size = stoi(inputs.front());
                    inputs.pop_front();
                    tmpfile.name = inputs.front();
                    inputs.pop_front();
                    curr_folder->files.push_front(tmpfile);
                }
            }
        }
        else if(curr_s == "cd")
        {
            inputs.pop_front();
            //cout << inputs.front() << ' ';

            if (inputs.front() != "..")
               curr_folder = &all_folders[inputs.front()];

            inputs.pop_front();
        }
        else
            inputs.pop_front(); 

    }
    
    int sum = 0;
    for (auto const& x : all_folders)
    {
        int tmp_int = 0;
        Folder tmp_folder = x.second;
        tmp_int = tmp_folder.get_total_value();

        if (tmp_int <= 100000)
            sum += tmp_int;
        
    }
    cout << sum;
    

}