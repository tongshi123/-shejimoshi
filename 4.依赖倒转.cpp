/*
	2019/11/26 
	设计模式---依赖倒转原则--
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankWorker{
public:
	void saveServic(){
		cout << "办理存款..." << endl;
	}
	void payServic(){
		cout << "办理支付..." << endl;
	}
	void tranferServic(){
		cout << "办理转账..." << endl;
	}
}; 

//中层模块 
void doSaveBussiness(BankWorker* worker){
	worker->saveServic();
} 
void doPayBussiness(BankWorker* worker){
	worker->payServic();
} 
void doTranferBussiness(BankWorker* worker){
	worker->tranferServic();
} 

//业务层 
void test01(){
	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker);	//办理存款业务 
}

////////////////////////////////////////
/////////////////////////////////////////
//新开始

//抽象层             核心（被依赖） 
class AbstractWorker{
public:
	virtual void doBussiness() = 0;	
}; 

//专门负责办理存款业务的工作人员
class SaveBankWorker : public AbstractWorker{
public:
	virtual void doBussiness(){
		cout << "办理存款..." << endl;
	}
};

//专门负责办理支付的工作人员
class PayBankWorker : public AbstractWorker{
public:
	virtual void doBussiness(){
		cout << "办理支付..." << endl;
	}
};

//专门负责办理转账的工作人员
class TranferBankWorker : public AbstractWorker{
public:
	virtual void doBussiness(){
		cout << "办理转账..." << endl;
	}
};

//中层模块 
void doNewBussiness(AbstractWorker* worker){
	worker->doBussiness();
} 

void test02(){
	AbstractWorker* tranferworker = new TranferBankWorker;
	doNewBussiness(tranferworker);
	delete  tranferworker;
}
int main(){
	test02();
	return 0;
}
