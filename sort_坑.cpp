
#include<vector>     
#include<algorithm>    
#include  <iostream>
using namespace std;
struct stu {
	int score;
	bool operator<(const stu &s) const {
		//return score <= s.score; //��δ��������ڴ�Խ�磬Ӧ������stl sortһ�����ײȵ��Ŀ�
		return score > s.score;

	}
};

//��δ��������ڴ�Խ�磬Ӧ������stl sortһ�����ײȵ��Ŀ�
//http://www.zhihu.com/question/26901409
int main(int argvc, char **argv) {
	vector<stu> v;
	
	for (unsigned int i = 0; i < 17; i++) {
		stu s;
		s.score = i+1;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (unsigned int i = 0; i < 17; i++) {
		cout << v[i].score <<" ";
	}
	cout << endl;
	return 0;
}
