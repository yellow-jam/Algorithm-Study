#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	// 생성자 
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수가 작은 순서'
	bool operator < (Student &student) {
		return this->score < student.score;
	} 
};

int main(void) {
	Student students[] = {
		Student("유영주", 90),
		Student("유수연", 97),
		Student("김혜수", 93),
		Student("황성민", 91),
	};
	sort(students, students + 4);
	for (int i=0; i<4; i++){
		cout << students[i].name<< ' ';
	}
	 
	return 0;
}
