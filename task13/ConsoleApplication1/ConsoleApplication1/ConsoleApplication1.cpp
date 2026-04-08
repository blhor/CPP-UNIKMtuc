#include <iostream>
#include <string>
using namespace std;


bool impl(bool a, bool b) { return !a || b; }       // a → b
bool equiv(bool a, bool b) { return a == b; }        // a ↔ b

//1
bool expr1(bool x) {
    bool part = impl(!x, x && x);  // (x̄ → x & x)
    bool right = x && part;         // x & (...)
    return equiv(x, right);         // x ↔ (...)
}
//2
bool expr2(bool x, bool y, bool z) {
    bool left = x && impl(z, y);   // x & (z → y)
    bool right = impl(x, z) && y;   // (x → z) & y
    return left || right;            // ... ∨ ...
}

void printBool(bool v) { cout << (v ? "1" : "0"); }

int main() {
    setlocale(LC_ALL, "ru");
    cout << "=== Выражение 1: x <-> x & (!x -> x & x) ===" << endl;
    cout << "| x | результат |" << endl;
    cout << "|---|-----------|" << endl;
    for (int x = 0; x <= 1; x++) {
        bool res = expr1(x);
        cout << "| " << x << " |     " << res << "     |" << endl;
    }

    cout << endl;

    cout << "=== Выражение 2: x & (z -> y) v (x -> z) & y ===" << endl;
    cout << "| x | y | z | результат |" << endl;
    cout << "|---|---|---|-----------|" << endl;
    for (int x = 0; x <= 1; x++)
        for (int y = 0; y <= 1; y++)
            for (int z = 0; z <= 1; z++) {
                bool res = expr2(x, y, z);
                cout << "| " << x << " | " << y << " | " << z
                    << " |     " << res << "     |" << endl;
            }

    return 0;
}