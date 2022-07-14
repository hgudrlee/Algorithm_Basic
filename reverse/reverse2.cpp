#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num;
    stack<char> word;
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++)
    {
        string str;
        getline(cin, str);
        for (char c : str) {
            if (c == ' ') {
                while (!word.empty()) {
                    cout << word.top();
                    word.pop();
                }
                cout << " ";
            }
            else {
                word.push(c);
            }
        }
        while (!word.empty()) {
            cout << word.top();
            word.pop();
        }
    }
}