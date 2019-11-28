/*
	2019/11/26 
	���ģʽ---������תԭ��--
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankWorker{
public:
	void saveServic(){
		cout << "������..." << endl;
	}
	void payServic(){
		cout << "����֧��..." << endl;
	}
	void tranferServic(){
		cout << "����ת��..." << endl;
	}
}; 

//�в�ģ�� 
void doSaveBussiness(BankWorker* worker){
	worker->saveServic();
} 
void doPayBussiness(BankWorker* worker){
	worker->payServic();
} 
void doTranferBussiness(BankWorker* worker){
	worker->tranferServic();
} 

//ҵ��� 
void test01(){
	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker);	//������ҵ�� 
}

////////////////////////////////////////
/////////////////////////////////////////
//�¿�ʼ

//�����             ���ģ��������� 
class AbstractWorker{
public:
	virtual void doBussiness() = 0;	
}; 

//ר�Ÿ��������ҵ��Ĺ�����Ա
class SaveBankWorker : public AbstractWorker{
public:
	virtual void doBussiness(){
		cout << "������..." << endl;
	}
};

//ר�Ÿ������֧���Ĺ�����Ա
class PayBankWorker : public AbstractWorker{
public:
	virtual void doBussiness(){
		cout << "����֧��..." << endl;
	}
};

//ר�Ÿ������ת�˵Ĺ�����Ա
class TranferBankWorker : public AbstractWorker{
public:
	virtual void doBussiness(){
		cout << "����ת��..." << endl;
	}
};

//�в�ģ�� 
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
