#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

/*
문제:

    정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

    명령은 총 다섯 가지이다.

    push X: 정수 X를 스택에 넣는 연산이다.
    pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 스택에 들어있는 정수의 개수를 출력한다.
    empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
    top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력:

    첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력:

    출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

    14
    push 1
    push 2
    top
    size
    empty
    pop
    pop
    pop
    size
    empty
    pop
    push 3
    empty
    top

    2
    2
    0
    2
    1
    -1
    0
    1
    -1
    0
    3
*/

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             
    string buffer;                      
    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);              
    }

    return result;
}

int main() 
{
    stack<int> s;
    int num;
    vector<string> cmds;
    vector<string> cmd;
    int result = 0;

    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) {
        string str;
        getline(cin, str);
        cmds.push_back(str);
    }

    for (int i = 0; i < cmds.size(); i++) {
        cmd = split(cmds[i], ' ');
        if (cmd[0].compare("push") == 0) {
            s.push(stoi(cmd[1]));
        }
        else if (cmd[0].compare("pop") == 0) {
            if (s.empty()) result = -1;
            else {
                result = s.top();
                s.pop();
            }
            cout << result << endl;
        }
        else if (cmd[0].compare("size") == 0) {
            result = s.size();
            cout << result << endl;
        }
        else if (cmd[0].compare("empty") == 0) {
            if (s.empty()) result = 1;
            else result = 0;
            cout << result << endl;
        }
        else if (cmd[0].compare("top") == 0) {
            if (s.empty()) result = -1;
            else {
                result = s.top();
            }
            cout << result << endl;
        }
    }

    return 0;
}