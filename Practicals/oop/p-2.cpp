#include<iostream>
#include<string>
using namespace std;

class StudData; // Forward declaration

class Student
{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count; // Static member to keep track of student count

public:
    Student()
    {
        name = "";
        roll_no = 0;
        cls = "";
        division = new char[10];
        dob = "dd/mm/yyyy";
        bloodgroup = new char[4];
        count++; // Increment the count when a Student object is created
    }

    ~Student()
    {
        delete[] division; // Corrected: Use delete[] for dynamically allocated arrays
        delete[] bloodgroup;
        count--; // Decrement the count when a Student object is deleted
    }

    static int getCount()
    {
        return count;
    }

    void getData(StudData*);
    void dispData(StudData*);
};

class StudData
{
    string caddress;
    long int* telno;
    long int* dlno;
    friend class Student;

public:
    StudData()
    {
        caddress = "";
        telno = new long(0);
        dlno = new long(0);
    }

    ~StudData()
    {
        delete telno;
        delete dlno;
    }

    void getStudData()
    {
        cout << "Enter Contact Address: ";
        cin.ignore(); // Corrected: Ensure input buffer is cleared before getline
        getline(cin, caddress);
        cout << "Enter Telephone Number: ";
        cin >> *telno;
        cout << "Enter Driving Licence Number: ";
        cin >> *dlno;
    }

    void dispStudData()
    {
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << *telno << endl;
        cout << "Driving Licence Number: " << *dlno << endl;
    }
};

inline void Student::getData(StudData* st)
{
    cout << "Enter Student Name: ";
    cin.ignore(); // Corrected: Ensure input buffer is cleared before getline
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cout << "Enter Class: ";
    cin.ignore(); // Corrected: Clear input buffer before getline
    getline(cin, cls);
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Date of Birth: ";
    cin.ignore(); // Corrected: Clear input buffer before getline
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    cin >> bloodgroup;
    st->getStudData();
}

inline void Student::dispData(StudData* st1)
{
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st1->dispStudData();
}

int Student::count = 0; // Initialize the static member outside the class

int main()
{
    Student* stud1[100];
    StudData* stud2[100];
    int n = 0;
    char ch;
    do
    {
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++)
    {
        cout << "--------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}
