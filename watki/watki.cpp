include <iostream>
#include <vector>
#include <thread>
using namespace std;
void pierwsze(int x) {
    int wynik;
    for (int i = 1; i < x; i++) {
        wynik = 0;
        if (i < 2) {
            wynik = 1;
        }
        int n = i;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                wynik = 1;
                break;
            }
        }
        if (wynik == 0)cout << n << " ";
    }
    cout << endl;
    cout << endl;
}
void fib(int x) {
    long long a = 0, b = 1;

    for (int i = 0; i < x; i++) {
        cout << b << " ";
        b += a;
        a = b - a;
    }
    cout << endl;
}
int main()
{
    vector <thread*> threads1;
    thread* watek = new thread(pierwsze, 800);
    threads1.push_back(watek);
    thread* watek2 = new thread(fib, 101);
    threads1.push_back(watek2);
    for (vector<thread*>::iterator it = threads1.begin(); it != threads1.end(); ++it) {
        (*it)->join();
        delete* it;
    }
    return 0;
}