#include <iostream>
using namespace std;
class Time
{
    int hour, minu, sec;

public:
    Time();

    void setTime();
    void display()
    {
        cout << hour << ":" << minu << ":" << sec;
    }

    Time operator+(Time);
};
Time::Time()
{
    hour = 0, minu = 0;
    sec = 0;
}
Time Time::operator+(Time t1)
{
    Time t;
    int temp1, temp2;
    temp1 = sec + t1.sec;
    t.sec = temp1 % 60;
    temp2 = (temp1 / 60) + minu + t1.minu;
    t.minu = temp2 % 60;
    t.hour = (temp2 / 60) + hour + t1.hour;
    t.hour = t.hour % 12;
    return t;
}

void Time::setTime()
{
    cout << endl
         << " Enter the hour ";
    cin >> hour;
    cout
        << " Enter the minute ";
    cin >> minu;
    cout
        << " Enter the second ";
    cin >> sec;
}

int main()
{
    Time t1, t2, t3;

    cout << "\n Enter the first time in 12 hr format ";
    t1.setTime();
    cout << "\n Enter the second time in 12 hr format ";
    t2.setTime();
    t3 = t1 + t2;
    cout << "\n First time in 12 hr format ";
    t1.display();
    cout << "\n Second time in 12 hr format ";
    t2.display();
    cout << "\n Sum of times in 12 hr format ";
    t3.display();
}