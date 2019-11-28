/*
	2019/11/26 
	���ģʽ---����ԭ��---������
*/

//������ 

#include <iostream>
using namespace std;

class AbstractCaculator{
public:
	virtual int getResylt() = 0;
	virtual void  setOperatorNumber(int, int) = 0;
 };
 
 //�ӷ�������
 class  PlusCaculator : public AbstractCaculator{
 public:
 	virtual void setOperatorNumber(int a, int b){
 		this->mA  = a;
 		this->mB  = b;
	 }
	
	virtual int getResylt(){
		return mA + mB;
	}
 public:
 	int mA;
 	int mB;
 };
 
 //����������
 class  MinuteCaculator : public AbstractCaculator{
 public:
 	virtual void setOperatorNumber(int a, int b){
 		this->mA  = a;
 		this->mB  = b;
	 }
	
	virtual int getResylt(){
		return mA - mB;
	}
 public:
 	int mA;
 	int mB;
 };
 
 //�˷�������
 class  MultiplyCaculator : public AbstractCaculator{
 public:
 	virtual void setOperatorNumber(int a, int b){
 		this->mA  = a;
 		this->mB  = b;
	 }
	
	virtual int getResylt(){
		return mA * mB;
	}
 public:
 	int mA;
 	int mB;
 };
 
 void test01(){
 	AbstractCaculator* caculator = new PlusCaculator;
 	caculator->setOperatorNumber(1, 5); 
 	cout << "ret : " << caculator->getResylt() << endl;
 }
 
 int main(){
 	test01();
 	return 0;
 }
