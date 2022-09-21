#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
    string line;
    ifstream myfile("StudentData.txt");
    vector<STUDENT_DATA> names;
    STUDENT_DATA SD;


    if (myfile.is_open())
    {
        while (getline(myfile, line, '\n'))
        {
            stringstream ss(line);
            string first;
            getline(ss, first, ',');
            SD.firstName = first;

            string last;
            getline(ss, last, ',');
            SD.lastName = last;
           
            names.push_back(SD);
        }
        myfile.close();
    }
    else
    {
        cout << "Problem opening file" << endl;
    }

    return 0;
}