/*
	2019/11/28
	���ģʽ---����ģʽԭ��--ͨ������ȥ����ϵͳ 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�ṩһ�ִ��������ƶ���������ķ���
//Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�����ʵ����ҵ��ͺ��Ĺ��ܷ��롣
class AbstractCommonInterface{
public:
	virtual void run() = 0;
}; 

//���Ѿ�д�õ�ϵͳ 
class MySystem : public AbstractCommonInterface{
public:
	virtual void run(){
		cout << "ϵͳ����" << endl;
	}
};

//������ҪȨ����֤, ���������˶������������ҵ�ϵͳ�� ����Ҫ�ṩ�û��������� 
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
			cout << "�û���������ȷ�� ��֤ͨ��������" << endl;
			pSystem->run();
		}
		else{
			cout << "�û�������������� Ȩ�޲��㡣����" << endl;
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
