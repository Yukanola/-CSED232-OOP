#if _WIN32
#include "Products.h"
#else
#include "Products_Linux.h"
#endif

using std::endl;

class SnackList {

	Snack* Head;	// 첫 노드를 가리키는 변수
	Snack* Tail;	// 마지막 노드를 가리키는 변수
	int Amounts;	// 총 노드 수

public:

	SnackList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };	// 과자 목록의 생성자로, 기본 값들을 설정한다.

	void Add(Snack* NewProd);

	void Delete(Snack* TargetProd);

	void dispAllProducts();

	Snack* getProdByID(int id) { Snack* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };	// 일치하는 ID가 나올때까지 계속 찾는다.

	Snack* getProdByName(string name) { Snack* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };	// 일치하는 Name이 나올떼까지 계속 찾는다.

	SnackList* getProdsByManufacturer(SnackList* Box, string man);

	Snack* getHead() { return this->Head; };	// Head를 반환한다.

	int getAmounts() { return this->Amounts; };	// 총 개수를 반환한다.

};

class DrinkList {	// Snack 참조.

	Drink* Head;
	Drink* Tail;
	int Amounts;

public:

	DrinkList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Drink* NewProd);

	void Delete(Drink* TargetProd);

	void dispAllProducts();

	Drink* getProdByID(int id) { Drink* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Drink* getProdByName(string name) { Drink* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	DrinkList* getProdsByManufacturer(DrinkList* Box, string man);

	Drink* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class IceList {	// Snack 참조.

	Ice* Head;
	Ice* Tail;
	int Amounts;

public:

	IceList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Ice* NewProd);

	void Delete(Ice* TargetProd);

	void dispAllProducts();

	Ice* getProdByID(int id) { Ice* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Ice* getProdByName(string name) { Ice* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	IceList* getProdsByManufacturer(IceList* Box, string man);

	Ice* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class OtherList {	// Snack 참조.

	Other* Head;
	Other* Tail;
	int Amounts;

public:

	OtherList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Other* NewProd);

	void Delete(Other* TargetProd);

	void dispAllProducts();

	Other* getProdByID(int id) { Other* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Other* getProdByName(string name) { Other* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	OtherList* getProdsByManufacturer(OtherList* Box, string man);

	Other* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};
