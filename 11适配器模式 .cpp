/*
	2019/11/28
	设计模式---适配器模式 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//这函数我已经写好 
struct MyPrint{
	void operator()(int v1, int v2){
		cout << v1 + v2 << endl;
	}
};

//定义目标接口 我要是适配 适配成什么样的
class Target{
public:
	virtual void operator()(int v) = 0;
}; 

//适配器
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
