#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
class book
{

    char author[20];
    char title[20];
    char publisher[20];
    double price;
    int stock;

public:
    book();
    void enter();
    void show();
    int find(char[], char[]);
    void noc(int);
};
book::book()
{
    char *author = new char[50];
    char *title = new char[50];
    char *publisher = new char[50];
    price = 0;
    stock = 0;
}
void book::enter()
{
    cout << "Book: ";
    cin >> title;
    cout << "Author: ";
    cin >> author;
    cout << "Publisher: ";
    cin >> publisher;
    cout << "Price: ";
    cin >> price;
    cout << "Stock of book: ";
    cin >> stock;
}

void book::show()
{
    cout << "\n " << title << " " << author << " " << publisher << " " << price << " " << stock;
}
int book::find(char t[], char a[])
{
    if (strcmp(title, t) && (strcmp(author, a)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void book::noc(int num)
{
    if (stock >= num)
    {
        cout << "\n Title is avilable";
        cout << "\n Cost of" << num << "Books is Rs." << (price * num);
    }
    else
    {
        cout << "\n Required copies not in stock";
    }
}
int main()
{
    int n = 0, i, f = 0, c, key = 0;
    book b[100];
    char t[50], a[50];
    while (1)
    {
        int ch;
        cout
            << "\n Press 1 to Insert Details of book \n Press 2 to show \n Press 3 to find \n Press any num to exit";
        cout << "\n  Choice:";
        cin >> ch;
        if (ch == 1)
        {
            int no;
            cout << " no of  books  to enter";
            cin >> no;
            for (i = n; i < n + no; i++)
            {
                b[i].enter();
                n++;
            }
        }
        else if (ch == 2)
        {
            cout << "\n the books will be in order (title,author, publisher,price stock) respectively";
            for (i = 0; i < n; i++)
            {
                cout << "\n";
                b[i].show();
            }
        }

        else if (ch == 3)
        {
            cout << "\n title of book";
            cin >> t;
            cout << "\author of book";
            cin >> a;

            for (i = 0; i < n; i++)
            {
                if (b[i].find(t, a))
                {
                    f = 1;
                    cout << "\n the books will be in order (title,author, publisher,price stock) respectively";
                    b[i].show();
                    key = i;
                }
            }
            if (f == 1)
                cout << "\n Found";
            else
            {
                cout << "\n Not Found";
            }
            if (f == 1)
            {
                cout << "\n required number of copies of the book";
                cin >> c;
                b[key].noc(c);
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}