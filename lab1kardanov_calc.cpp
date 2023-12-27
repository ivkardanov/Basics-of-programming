#include <iostream>
#include<conio.h>
#include<math.h>
#include<iomanip>

char op;
using namespace std;
void sum()
{

    int sum = 0;
    int number;
    int numberitems;
    cout << "Enter number of items: \n";
    cin >> numberitems;

    for (int i = 0; i < numberitems; i++)
    {
        cout << "Enter number " << i << ":\n\n";
        cin >> number;
        sum += number;
    }
    cout << "sum is: " << sum << endl << endl;

}
void difference()
{
    int diff;
    int n1, n2;
    cout << "enter two numbers to find their difference:\n\n";
    cout << "enter first number:";
    cin >> n1;
    cout << "\nenter second number:";
    cin >> n2;
    diff = n1 - n2;
    cout << "\ndifference is:" << diff << endl << endl;
}

void multiplication()

{
    int multiplication = 1;
    int n;
    int numberitems;
    cout << "enter number of items:\n";
    cin >> numberitems;
    for (int i = 0; i <= numberitems; i++)
    {
        cout << "\nenter item " << i << ":";
        cin >> n;
        multiplication *= n;
    }

    cout << "product is:" << multiplication << endl << endl;
}

void div()
{
    int div;
    int n1;
    int n2;
    cout << "enter 2 numbers to find their quotient\n\n";
    cout << "enter number 1:";
    cin >> n1;
    cout << "\nenter number 2:";
    cin >> n2;
    div = n1 / n2;
    cout << "\nquotient is:" << div << endl << endl;
}

void expo()
{
    long int p;
    int res = 1, n;
    cout << "enter number:";
    cin >> n;
    cout << "\nenter extent:";
    cin >> p;
    for (int i = 1; i <= p; i++)
    {
        res = n * res;
    }
    cout << n << "\n exponentiation " << p << " is :" << res << endl;
}

void sqrt()
{
    float s;
    int n;
    cout << "enter number to find its sqrt:";
    cin >> n;
    s = sqrt(n);
    cout << "\nsquare root of " << n << " is :" << s << endl;
}
void fact()
{
    long int f = 1;
    int c = 1, n;
    cout << "enter number to find its factorial:";
    cin >> n;
    while (c <= n)
    {
        f = f * c;
        c += 1;
    }
    cout << "\nfactorial of " << n << " is :" << f << endl;
}

int main()
{


    system("cls");

    do
    {

        system("pause");
        system("cls");
        cout << "***which operation you want to perform***\n";
        cout << "press 0 for exit\n";
        cout << "press 1 for sum \n";
        cout << "press 2 for subtraction\n";
        cout << "press 3 for multiplication\n";
        cout << "press 4 for division\n";
        cout << "press 5 for exponential calculation\n";
        cout << "press 6 for sqrt \n";
        cout << "press 7 for factorial\n";
        cout << "press option:";
        cin >> op;
        switch (op)
        {
        case '1':
            sum();
            break;
        case '2':
            difference();
            break;
        case '3':
            multiplication();
            break;
        case '4':
            div();
            break;
        case '5':
            expo();
            break;
        case '6':
            sqrt();
            break;
        case '7':
            fact();
            break;
        case '0':
            exit(0);
        default:
            cout << "invalid input";
            system("cls");
        }
    } while (true);

}