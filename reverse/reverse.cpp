#include <iostream>
#include <vector>
#include <string>
#include "string.h"

using namespace std;

/*
문제:
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 
단어는 영어 알파벳으로만 이루어져 있다.

입력:
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 
단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

출력:
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.

2
I am happy today
We want to win the first prize

I ma yppah yadot
eW tnaw ot niw eht tsrif ezirp
*/

void printStr(vector<string> words)
{
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i == words.size() - 1) cout << endl;
        else cout << " ";
    }
}

void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int main() 
{
    vector<vector<string>> words;
    int num;
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) 
    {
        string str;
        getline(cin, str);
        char *str_buff = new char[1000];
        strcpy(str_buff, str.c_str());
        char *tok = strtok(str_buff, " ");

        while (1) {
            string s;
            if (tok == nullptr) break;
            s = string(tok);
            reverseStr(s);
            words.push_back(vector<string>());
            words[i].push_back(s);
            tok = strtok(nullptr, " ");
        }

        printStr(words[i]);
    }

    return 0;
}