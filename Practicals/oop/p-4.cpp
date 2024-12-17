#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Employee
{
    string name;
    int ID;
    double salary;

    public:
    void accept()
    {
        cout << "\n Name: ";
        cin >> name;
        cout << "\n ID: ";
        cin >> ID;
        cout << "\n Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "\n Name: " << name;
        cout << "\n ID: " << ID;
        cout << "\n Salary: " << salary << endl;
    }
};

int main()
{
    Employee o[5];
    fstream f;
    int i, n;
    f.open("demo.txt", ios::out);
    cout << "\nEnter the number of employees you want to store: ";
    cin >> n;
    for(int i=0; i<n; i++) 
    {
        cout << "\n Enter the information of Employee " << i+1<< "\n";
        o[i].accept();
        f.write((char*)&o[i], sizeof o[i]);
        o[i].display();
    }

    f.close();
    return 0;
}