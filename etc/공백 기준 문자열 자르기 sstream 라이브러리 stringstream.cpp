#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // ���� ���� ���ڿ� �ڸ���
    string s = "abc def ghi";
    
    stringstream ss(s);
    ss.str(s);

    string word;
    while(ss >> word) {
        cout << word << endl;
    }
 }   

// ��� ����
//   abc
//   def
//   ghi
