#include <iostream>
#include <vector>
#include <ctime>
#include "TBigNum.h"

using namespace std;

int main()
{
    //srand (time(nullptr));
    int n = 2;
    for (int i = 0; i < n; i++)
    {
        int a1 = rand() * rand() * rand(), b1 = rand();
        TBigNum a2, b2;
        a2.setNum(a1), b2.setNum(b1);
        cout << a1 << " + " << b1 << " = " << a1 + b1 << " // Calculated in int numbers" << endl;
        cout << a2.toDecimalString() << " + " << b2.toDecimalString() << " = " << (a2 + b2).toDecimalString()
             << " // Calculated in TBigNum objects" << endl;
        cout << endl;
        cout << a1 << " - " << b1 << " = " << a1 - b1 << " // Calculated in int numbers" << endl;
        cout << a2.toDecimalString() << " - " << b2.toDecimalString() << " = " << (a2 - b2).toDecimalString()
             << " // Calculated in TBigNum objects" << endl;
        cout << endl;
    }
    auto lv = (TBigNum)"123456789101112131415161718192021222324252627282930";
    auto rv = (TBigNum)"-987654321123456789";
    string res = "123456789101112131415161718192020234669931503826141"; // Calculated in Python
    lv += rv;
    cout << res << " // Calculated in Python" << endl;
    cout << lv.toDecimalString() << " // Calculated in TBigNum objects" << endl;
    return 0;
}