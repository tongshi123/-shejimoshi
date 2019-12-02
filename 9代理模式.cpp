/*
	2019/11/28
	设计模式---代理模式原则--通过代理去启动系统 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//提供一种代理来控制对其他对象的访问
//为其他对象提供一种代理以控制对这个对象的访问。这样实现了业务和核心功能分离。
class AbstractCommonInterface{
public:
	virtual void run() = 0;
}; 

//我已经写好的系统 
class MySystem : public AbstractCommonInterface{
public:
	virtual void run(){
		cout << "系统启动" << endl;
	}
};

//必须有要权限验证, 不是所有人都可以来启动我的系统， 必须要提供用户名和密码 
class MySystemProxy : public AbstractCommonInterface{
public:
	MySystemProxy(string username, string password) : mUsername(username), mPassword(password){
		pSystem = new MySystem;
	}
	
	bool checkUserInfo(){
		if(mUsername == "admin" && mPassword == "123"){
			return true;
		}
		return false;
	}
	
	virtual void run(){
		if(checkUserInfo()){
			cout << "用户名密码正确， 验证通过。。。" << endl;
			pSystem->run();
		}
		else{
			cout << "用户名或者密码错误， 权限不足。。。" << endl;
		}
	}
	
	~MySystemProxy(){
		if(pSystem != NULL){
			delete pSystem;
		}
	}
public:
	MySystem* pSystem;
	string mUsername;
	string mPassword;
};

void test01(){
	MySystemProxy* proxy = new MySystemProxy("admin", "123");
	proxy->run();
} 
int main(){
	test01();
	return 0;
} 
