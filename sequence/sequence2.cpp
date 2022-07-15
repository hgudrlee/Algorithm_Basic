#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int input[100001];
    vector<char> sign;
    stack<int> seq;
    int num;
    int cnt = 0;
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) cin >> input[i];
    
    for (int i = 1; i <= num; i++)
    {
        seq.push(i);
        sign.push_back('+');

        while (!seq.empty() && seq.top() == input[cnt]) 
        {
            seq.pop();
            sign.push_back('-');
            cnt++;
        } 
    }

    if (seq.empty()) {
        for (int i = 0; i < sign.size(); i++) cout << sign[i] << endl;
    }
    else cout << "NO";
}