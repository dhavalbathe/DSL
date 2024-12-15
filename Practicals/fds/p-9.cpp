#include<iostream>
using namespace std;
class slot {
    public:
    int appo, max, min, start, end;
    slot *next;
    int status;

    public:
    slot() {
        appo = 0;
        max = 0;
        min = 0;
        start = 0;
        end = 0;
        next = NULL;
        status = 0;
    }
};

class Hospital {
    public:
    slot *first = NULL;
    slot *last = NULL;
    int n;

    Hospital() {
        slot *ns = new slot();
        cout << "Enter the No of Appoinments for today: "<<endl;
        cin >> n;
        ns->appo = 1;
        ns->status = 0;
        cout << "\nEnter the Start time(hrs) of appoinment1: ";
        cin >> ns->start;
        cout << "Enter the end time (hrs) of appoinment1: ";
        cin >> ns->end;
        cout << "Enter the maximum duration(min) of appoinment1: ";
        cin >> ns->max;
        cout << "Enter the minimum duration(min) of appoinment: ";
        cin >> ns->min;

        first = last = ns;

        for(int i=2; i<=n; i++) {
            slot *t = new slot();
            t->appo = i;
            t->status = 0;
            cout << "\nEnter the Start time(hrs) of appoinment "<<i;
            cin >> t->start;
            cout << "Enter the end time (hrs) of appoinment "<<i;
            cin >> t->end;
            cout << "Enter the maximum duration(min) of appoinment "<<i;
            cin >> t->max;
            cout << "Enter the minimum duration(min) of appoinment "<<i;
            cin >> t->min; 
            last->next = t;
            last = t;
        }
    }

    void Display() {
        slot *t = first;
        cout << "----------------------------------"<<endl;
        cout << "Appoinment no\t Start-time\t End-time \t Max-duration \t Min-duration \t Status" << endl;
        cout << "-----------------------------------" <<endl;
        while(t) {
            cout <<t->appo<<"\t\t"<<t->start<<"\t\t"<<t->end<<"\t\t"<<t->max<<"\t\t"<<t->min<<"\t\t";

            if(t->status == 0) {
                cout << ">>>FREE<<<" << endl;
            } else if(t->status == 1) {
                cout << ">>>BOOKED<<<" <<endl;
            }

            t = t->next;
        }
    }

    void DisplayFree() {
        slot *temp = first;
        cout << "Appoinment no\t Start-time\t End-time \t Max-duration \t Min-duration \t Status" << endl;

        while(temp) {
            if(temp->status == 0) {
                cout <<temp->appo<<"\t\t"<<temp->start<<"\t\t"<<temp->end<<"\t\t"<<temp->max<<"\t\t"<<temp->min<<"\t\t"<<">>>FREE<<<";
            }
            temp = temp->next;
        }
    }

    void Book() {
        int st;
        cout << "Enter the time you want to Book appoinment" <<endl;
        cin >> st;
        slot *temp = first;
        bool flag = false;
        while(temp) {
            if(temp->start == st && temp->status == 0) {
                temp->status = 1;
                cout << "The Slot is Booked successfully"<<endl;
                flag = true;
                Display();
                break;
            } else if(temp->start == st && temp->status == 1) {
                cout << "The Slot is already Booked !" <<endl;
                flag = true;
            }
            temp = temp->next;
        }

        if(flag == false) {
            cout << "Their is no Slot at this Time to Book" <<endl;
        }
    }

    void Cancel() {
        int st;
        cout << "Enter the time you want to Cancel appoinment: " <<endl;
        cin >> st;
        slot *temp = first;
        bool flag = false;
        while(temp) {
            if(temp->start == st && temp->status == 1) {
                temp->status = 0;
                cout << "The Your appoinment is Canceled. "<< endl;
                flag = true;
                Display();
                break;
            }
            else if(temp->start == st && temp->status == 0) {
                cout << "The Slot is Not Booked Yet !" << endl;
                flag = true;
            }
            temp = temp->next;
        }

        if(flag == false) {
            cout << "Their is no Slot at this Time to Cancel. " << endl;
        }
    }

    void sortl() {
        slot *t = first;
        while(t) {
            slot *s = t->next;
            while(s) {
                if(t->start > s->start) {
                    swap(t->start, s->start);
                    swap(t->appo, s->appo);
                    swap(t->end, s->end);
                    swap(t->max, s->max);
                    swap(t->min, s->min);
                    swap(t->status, s->status);
                }

                s = s->next;
            }

            t = t->next;
        }
        Display();
    }
};
int main()
{
    cout << "Enter the Daily Information first." << endl;
    Hospital h1;
    h1.Display();
    cout <<"\n*************************MENU*************************"<<endl;
    cout <<"1. Display Free Slots. "<< endl;
    cout <<"2. Book a Appointment. " << endl;
    cout <<"3. Cancel a Appoinment. " <<endl;
    cout <<"4. Sort the list of appoinmenton basic of Start time. " << endl;
    cout << "5. Exit the Program." <<endl;

    int ch;
    do {
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1: 
            h1.DisplayFree();
            break;
            case 2: 
            h1.Book();
            break;
            case 3:
            h1.Cancel();
            break;
            default:
            break;
        }
    } while(ch != 5);
    return 0;
}