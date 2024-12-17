#include<iostream>
#include<conio.h>
using namespace std;
class publication
{
    private:
    string title;
    float price;

    public:
    void add()
    {
        cout << "Enter the publication information: " << endl;
        cout << "Enter title of the publication: " << endl;
        cin.ignore();
        getline(cin, title);

        cout << "Enter the price of the publication: " << endl;
        cin >> price;
    }

    void display()
    {
        cout << "\n--------------------------------------";
        cout << "\nTitle of Publication: " << title;
        cout << "\nPublication Price: " << price;
    }
};

class book:public publication //declaring class book which inherits class publication in public mode
{
    private:
    int page_count;

    public:
    void add_book()
    {
        try {
            add();
            cout << "Enter page count of book: ";
            cin >> page_count;
            if(page_count <= 0) throw page_count;
        }

        catch(...)
        {
            cout << "\nInvalid Page Count!!!";
            page_count = 0;
        }
    }

    void display_book()
    {
        display();
        cout << "\nPage Count: " << page_count;
        cout << "\n--------------------------------------\n";
    }
};

class tape:public publication // declaring class tape which inherits class publication in public mode
{
    private:
    float play_time;

    public:
    void add_tape()
    {
        try {
            add();
            cout << "\nEnter the play duration of tape: ";
            cin >> play_time;
            if(play_time <= 0) throw play_time;
        }

        catch(...) {
                cout << "\nInvalid Play Time";
                play_time = 0;
            }
    }

    void display_tape()
    {
        display();
        cout << "\nPlay Time: " << play_time << " min";
        cout << "\n------------------------------------\n";
    }
};

int main()
{
    book b1[10]; // object of class book
    tape t1[10]; // object of class tape
    int ch, b_count = 0, t_count = 0;
    do {
        cout << "\n*************** PUBLICATION DATABASE SYSTEM *********************";
        cout << "\n------------------MENU---------------------";
        cout << "\n1. Add Information to book ";
        cout << "\n2. Add Information to tape ";
        cout << "\n3. Display Book information ";
        cout << "\n4. Display Tape information ";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
            b1[b_count].add_book();
            b_count++;
            break;

            case 2:
            t1[t_count].add_tape();
            t_count++;
            break;
            
            case 3:
            cout << "\n************* BOOK PUBLICATION SYSTEM *************";
            for(int i=0; i<b_count; i++)
            {
                b1[i].display_book();
            }
            break;

            case 4:
            cout << "\n************* TAPE PUBLICATION SYSTEM *************";
            for(int i=0; i<t_count; i++)
            {
                t1[i].display_tape();
            }
            break;
            
            case 5:
            exit(0);
        }
    } while(ch != 5);
    return 0;
}