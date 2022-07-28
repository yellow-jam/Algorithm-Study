#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // 공백 기준 문자열 자르기
    string s = "abc def ghi";
    
    stringstream ss(s);
    ss.str(s);

    string word;
    while(ss >> word) {
        cout << word << endl;
    }
 }   

// 출력 내용
//   abc
//   def
//   ghi
