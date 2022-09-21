#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

#ifdef _DEBUG

#else

#endif

using namespace std;

struct STUDENT_DATA
{
#ifdef _DEBUG
    string firstName;
    string lastName;
#else
    string firstName;
    string lastName;
    string email;
#endif 

};

int main()
{
    string line;
    vector<STUDENT_DATA> names;
    STUDENT_DATA SD;
    
#ifdef _DEBUG
    ifstream myfile("StudentData.txt");
#else
    ifstream myfile("StudentData_Emails.txt");
#endif // _DEBUG

    
    
    if (myfile.is_open())
    {
        while (getline(myfile, line, '\n'))
        {
           
#ifdef _DEBUG
            stringstream ss(line);
            string first;
            getline(ss, first, ',');
            SD.firstName = first;

            string last;
            getline(ss, last, ',');
            SD.lastName = last;
#else
            stringstream ss(line);
            string first;
            getline(ss, first, ',');
            SD.firstName = first;

            string last;
            getline(ss, last, ',');
            SD.lastName = last;
            
            string email;
            getline(ss, email, ',');
            SD.email = email;

#endif // _DEBUG


            names.push_back(SD);
        }
        myfile.close();
    }
    else
    {
        cout << "Problem opening file" << endl;
    }
#ifdef _DEBUG
   
    cout << "Application us running Standard source code" << endl;
   

    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i).firstName << " " << names.at(i).lastName << endl;
    }
#else
    cout << "Application is running pre - Release source code" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i).firstName << " " << names.at(i).lastName << " " << names.at(i).email << endl;
    }
#endif // _DEBUG

    return 0;
}