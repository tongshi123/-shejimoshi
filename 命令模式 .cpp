/*
	2019/12/01
	���ģʽ---����ģʽ 
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <windows.h>
using namespace std;

//Э�鴦����
class HandleClientProtocol{
public:
	//�������ӽ��
	void AddMoney(){
		cout << "��������ӽ�ң�"  << endl;
	} 
	
	//����������ʯ 
	void AddDiamond(){
		cout << "�����������ʯ��"  << endl;
	} 
	
	//����������� 
	void Addlevel(){
		cout << "�����������"  << endl;
	} 
};

//Э������ӿ� 
class AbstractCommand{
public:
	virtual void handle() = 0;		//����ͻ�������Ľӿ� 
};


//�������ӽ������ 
class AddMoneyCommand : public AbstractCommand{
public:
	AddMoneyCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	
	virtual void handle(){
		pProtocol->AddMoney();
	}
	
public:
	HandleClientProtocol* pProtocol;
};

//����������ʯ���� 
class AddDiamondCommand : public AbstractCommand{
public:
	AddDiamondCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	
	virtual void handle(){
		pProtocol->AddDiamond();
	}
	
public:
	HandleClientProtocol* pProtocol;
};

//������������ 
class AddlevelCommand : public AbstractCommand{
public:
	AddlevelCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	
	virtual void handle(){
		pProtocol->Addlevel();
	}
	
public:
	HandleClientProtocol* pProtocol;
};



//����������
class Server{
public:
	void addRequest(AbstractCommand* command){
		mCommandsQueue.push(command);
	}
	void startHandle(){
		while(!mCommandsQueue.empty()){
			
			Sleep(2000);
			
			AbstractCommand* command = mCommandsQueue.front();
			command->handle();
			mCommandsQueue.pop();
			
		}
	}
	
public:
	queue<AbstractCommand*> mCommandsQueue;
};
 
 
 void test01(){
 	HandleClientProtocol* protocol = new HandleClientProtocol;
 	
 	
 	//�ͻ������ӽ�ҵ����� 
 	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
 	//�ͻ���������ʯ������ 
 	AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
 	//�ͻ������������� 
 	AbstractCommand* addlevel = new AddlevelCommand(protocol);
 	
 	Server* server = new Server;
 	
 	server->addRequest(addmoney);
 	server->addRequest(adddiamond);
 	server->addRequest(addlevel);
 	
 	//��������ʼ�������� 
 	server->startHandle();
 }
 
 int main(){
 	test01();
 	return 0;

 }
