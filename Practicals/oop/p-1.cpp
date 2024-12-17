#include<iostream>
using namespace std;
class Complex
{
    public:
    double real, img;

    public:
    Complex() {
        real = 0;
        img = 0;
    }

    friend istream& operator>>(istream &input, Complex &c) {
        input >> c.real >> c.img;
    }

    friend ostream& operator<<(ostream &output, Complex &c) {
        output << c.real << "+" << c.img << "i" << endl;
    }

    Complex operator+(Complex &c2) {
        Complex ans;
        ans.real = real + c2.real;
        ans.img = img + c2.img;
        return ans;
    }

    Complex operator*(Complex &c2) {
        Complex ans;
        ans.real = real * c2.real;
        ans.img = img * c2.img;
        return ans;
    }
};
int main()
{
    Complex c1, c2, c3, c4;
    int flag = 1;
    char b;
    while(flag == 1)
    {
        cout << "Enter Real and imaginary part of the Complex Number 1: \n";
        cin >> c1;
        cout << "Enter Real and imaginary part of the Complex Number 2: \n";
        cin >> c2;
        int f = 1;
        while(f == 1)
        {
            cout << "Complex Number 1: " << c1 << endl;
            cout << "Complex Number 2: " << c2 << endl;
            cout << "******************** MENU ***********************" << endl;
            cout << "1. Addition of Complex Numbers" << endl;
            cout << "2. Multiplication of Complex Numbers " << endl;
            cout << "3. Exit" << endl;

            int a;
            cout << "Enter your choice from above MENU (1 to 3) ";
            cin >> a;
            if(a == 1)
            {
                c3 = c1 + c2;
                cout << "Addition: " << c3 << endl;
                cout << "Do you want to perform another operation (y/n): ";
                cin >> b;
                if(b == 'Y' || b == 'y') f = 1;
                else {
                    cout << "Thanks for using this program ";
                    flag = 0;
                    f = 0;
                }
            }
            else if(a == 2) 
            {
                c4 = c1 * c2;
                cout << "Multiplication: " << c4 << endl;
                cout << "Do you want to perform another operation (y/n): ";
                cin >> b;
                if(b == 'Y' || b == 'y') f = 1;
                else {
                    cout << "Thanks for using this program ";
                    flag = 0;
                    f = 0;
                }
            }
            else
            {
                cout << "Thanks for using this program" << endl;
                flag = 0;
                f = 0;
            }
        }
    }
    return 0;
}