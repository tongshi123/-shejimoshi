/*
	2019/11/28
	���ģʽ---������ģʽ 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//�⺯�����Ѿ�д�� 
struct MyPrint{
	void operator()(int v1, int v2){
		cout << v1 + v2 << endl;
	}
};

//����Ŀ��ӿ� ��Ҫ������ �����ʲô����
class Target{
public:
	virtual void operator()(int v) = 0;
}; 

//������
class Adapter : public Target{
public:
	Adapter(int param){
		m_param = param;
	}
	virtual void operator()(int v){
		print(v, m_param);
	}
public:
	MyPrint print;
	int m_param;
};
 
//MyBind2nd
Adapter MyBind2nd(int v){
	return Adapter(v);
}
 

int main(){
	vector<int> v;
	for(int i = 0; i < 10; ++ i){
		v.push_back(i);
	}
	//for_each(v.begin(), v.end(), Adapter());
	for_each(v.begin(), v.end(), MyBind2nd(10));
}
