#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <vector>
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
    map<string, Folder> sub_folders;
    list<File> files;
    long get_total_value();
    Folder*parent_folder;
    
};

long Folder::get_total_value()
{
    long total_val = 0;
    for(File f : files)
        total_val += f.size;

    for (auto const& x : sub_folders)
    {
        Folder tmp_folder = x.second;
        total_val += tmp_folder.get_total_value();
    }

    //cout << Name << ", value:" << total_val << '\n';

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

vector<Folder> get_all_sub_folders(Folder f)
{
    vector<Folder> all_sub_folders;

    all_sub_folders.push_back(f);

    for (auto const& x : f.sub_folders)
    {
        vector<Folder> sub_folders = get_all_sub_folders(x.second);
        all_sub_folders.insert(all_sub_folders.end(), sub_folders.begin(), sub_folders.end());
    }
    
    return all_sub_folders;
}


int main()
{
    std::ifstream t("input_7.txt");
    string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>()); 

    list<string> inputs = split_string(input, ' ');

    Folder start_folder;
    start_folder.Name = "/";


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
                    tmp_folder.parent_folder = curr_folder;
                    inputs.pop_front();
                    curr_folder->sub_folders[tmp_folder.Name] = tmp_folder;

                    //cout << curr_folder->sub_folders[tmp_folder.Name].Name 
                    //     << " parent folder : " << tmp_folder.parent_folder->Name << '\n';
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

            if (inputs.front() == "/")
                curr_folder = &start_folder;
            else if (inputs.front() != "..")
            {
                //cout << curr_folder->sub_folders[inputs.front()].Name << '\n';
                curr_folder = &curr_folder->sub_folders[inputs.front()];
            }
            else
                curr_folder = curr_folder->parent_folder;

            inputs.pop_front();
        }
        else
            inputs.pop_front(); 

    }

    int sum = 0;
    int unused_space = 70000000 - start_folder.get_total_value();
    int needed_space = 30000000;
    int smallest_dir_size = 70000000;
    
    //cout << start_folder.Name << ' ' << start_folder.get_total_value() << '\n';
    for (Folder f : get_all_sub_folders(start_folder))
    {
        //cout << f.Name << ", Value: " << f.get_total_value() << '\n';
        int x = f.get_total_value();
        if(unused_space + x > needed_space && x < smallest_dir_size)
        {
            smallest_dir_size = x;
        }
    }

    cout << smallest_dir_size;
    
    

}