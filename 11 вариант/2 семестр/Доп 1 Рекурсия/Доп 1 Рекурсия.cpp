#include <iostream>
#include <cmath>
using namespace std;

int i, c, b = 0;

int func(int smth, int max, int* array) {
    if (!b) {
        while (i < max) {
            i++;
            b++;
        }
    }
    if (i <= smth) {
        array[c] = i;
        ++i;
        c++;
        func(smth, max, array);
    }
    else {
        return c;
    }
}

int main(int argc, char* argv[])
{
    int a = 0;
    cout << "Enter A" << endl;
    cin >> a;
    int arr[40];

    int counter = 1;
    while (counter < a) {
        counter = counter * 10;
        cout << "count : " << counter << endl;
    }
    counter = counter / 10;
    cout << "after / " << counter << endl;
    int count = func(a, counter, arr);

    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}