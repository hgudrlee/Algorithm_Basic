#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int i_seq[10000];
    vector<char> sign;
    stack<int> t_seq;
    int num;
    int target = 0;
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) cin >> i_seq[i];

    for (int i = 0; i < num; i++) {
    
        if (i_seq[i] > target) {
            for (int j = target; j < i_seq[i]; j++) 
            {
                t_seq.push(j+1);
                sign.push_back('+');
            }
            t_seq.pop();
            sign.push_back('-');
            target = i_seq[i];
        }
        else if (t_seq.top() == i_seq[i]) {
            t_seq.pop();
            sign.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for (char s : sign) cout << s << endl;

    return 0;
}