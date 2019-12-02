/*
	2019/12/01
	设计模式---命令模式 
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <windows.h>
using namespace std;

//协议处理类
class HandleClientProtocol{
public:
	//处理增加金币
	void AddMoney(){
		cout << "给玩家增加金币！"  << endl;
	} 
	
	//处理增加钻石 
	void AddDiamond(){
		cout << "给玩家增加钻石！"  << endl;
	} 
	
	//处理玩家升级 
	void Addlevel(){
		cout << "给玩家升级！"  << endl;
	} 
};

//协议命令接口 
class AbstractCommand{
public:
	virtual void handle() = 0;		//处理客户端请求的接口 
};


//处理增加金币请求 
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

//处理增加钻石请求 
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

//处理升级请求 
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



//服务器程序
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
 	
 	
 	//客户端增加金币的请求 
 	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
 	//客户端增加钻石的请求 
 	AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
 	//客户端升级的请求 
 	AbstractCommand* addlevel = new AddlevelCommand(protocol);
 	
 	Server* server = new Server;
 	
 	server->addRequest(addmoney);
 	server->addRequest(adddiamond);
 	server->addRequest(addlevel);
 	
 	//服务器开始处理请求 
 	server->startHandle();
 }
 
 int main(){
 	test01();
 	return 0;

 }
