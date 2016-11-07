#pragma once
#include "Core.kano.h"
#include "Parameter.h"
#include <algorithm>
#include <ctime>

static int getRand(int d) { static int X = 0; srand(((X) ? X : time(NULL))); X = rand(); return (X % d); };
	/* getRand 함수는 1초 이내의 시간에 반복해서 호출되더라도 다른 난수를 생성하는 함수입니다. */
static int getRand(int d, int m) { return getRand(d) - m; };
static unsigned int regId() { return ++Setting::blockers; };
	/* 개발 과정에서 방해물을 쉽게 알 수 있도록 번호를 붙이기 위해 사용되었던 함수입니다. */

class Car {

protected:

	unsigned int id;
	int posX, posY, carW, carH, carOW, carOH;
	bool scoreCounted, removeSign;

	COORD prePos;

public:

	void setPosX(int x) { posX = x; }; //setCx
	void setPosY(int y) { posY = y; }; //setCy
	void setCarW(int w) { carW = w; }; //setWidth
	void setCarH(int h) { carH = h; }; //setHeight
	void setPrePos(int x, int y) { prePos.X = x; prePos.Y = y; };
		/* Car 출력 시, 이전의 위치 정보를 기억해두었다가 지우기 위해 만들어진 함수입니다. prePos를 설정합니다. */
	void count() { scoreCounted = true; };
		/* 점수를 중복해서 세지 않게 하기 위해 만들어진 함수입니다. scoreCounted를 true로 설정합니다. */
	int getId() { return id; };
		/* 개발 과정에서 방해물을 쉽게 알 수 있도록 번호를 붙이기 위해 사용되었던 함수입니다. */
	int getPosX() { return posX; }; //getCx
	int getRealPosX() { return (posX * 2) - 1; };
		/*
		이번 과제에서는 도로 왼쪽 위를 (0, 0)으로 하는 일종의 픽셀 개념을 활용하였습니다.
		Car Object에서는 현재 위치 정보를 픽셀 개념 기준으로 저장하고, 이전 위치 정보를 COORD 형태로 저장합니다.
		이 함수는 현재 위치 정보가 이전 위치 정보가 될 때, X좌표 변환을 쉽게 하기 위해 만들어진 함수입니다.
		*/
	int getPrePosXAAOP() { return ((prePos.X + 1) / 2); };
		/* 위의 함수(getRealPosX)와 만들어진 경위는 동일합니다. 이 함수는 COORD 형태의 X 좌표를 픽셀 형태로 만듭니다. */
	int getPosY() { return posY; }; //getCy
	int getCarH() { return carH; }; //getHeight
	int getCarW() { return carW; }; //getWidth
	int getOCarH() { return carOH; };
		/*
		모든 방해물은 가장 아래 픽셀에 닿으면 세로 값이 짧은 주기마다 한칸씩 줄어들게 되어 있습니다.
		하지만 방해물이 가장 아래에 닿았을 때도 원래의 크기대로 처리해야 할 때가 있습니다.
		그 경우, 원래 방해물의 크기를 구하기 위해 만든 함수입니다.
		*/
	int getOCarW() { return carOW; };
		/* 위의 함수(getOCarH)와 만들어진 경위가 동일합니다. */
	bool isCounted() { return scoreCounted; };
		/* 점수를 중복해서 세지 않게 하기 위해 만들어진 함수입니다. scoreCounted를 반환합니다. */
	bool hasRemoveSign() { return removeSign; };
		/*
		방해물이 가장 아래 픽셀에 닿아 세로 길이가 0이 되었을 경우에는 removeSign을 띄게 됩니다.
		removeSign이 뜨면 해당 방해물은 곧 링크드 리스트에서 제외됩니다.
		그러한 처리를 위해 만든 함수입니다.
		*/
	COORD getPrePos() { return prePos; };
		/* Car Object의 이전 위치를 알기 위해 만든 함수입니다. */
	bool decompose() { return !(--carH); };
		/*
		getOCarH, getOCarW 함수와 만들어진 경위가 동일합니다.
		가장 아래 픽셀에 닿았을 때 실행되는 함수인데, Car Object의 세로 길이를 한 칸 줄입니다.
		*/
	Car() {};
	Car(int x, int y, int w, int h) : id(regId()), scoreCounted(false), posX(x), posY(y), carW(w), carH(h), carOH(h), carOW(w), removeSign(false) { prePos.X = (2 * x) - 1; prePos.Y = y; };
	~Car() {};

};

class CarA : virtual public Car {

	CarA *Next, *Before;

public:

	CarA* getNext() { return Next; };
	CarA* getBefore() { return Before; }; //링크드 리스트로 바꾸면서 생성된 함수
	CarA* setNext(CarA* a) { return (Next = a); };
	CarA* setBefore(CarA* a) { return (Before = a); }; //링크드 리스트로 바꾸면서 생성된 함수
	CarA& behave() {

		this->posY += 1;
		int beX = getRand(3, 1);

		if (this->posX + beX >= 0 && this->posX + beX <= (Setting::E->roadX - this->getCarW()))
			this->posX += beX;

		if (this->posY + this->carH > Setting::E->roadY && this->decompose())
			this->removeSign = true;

		return *this;

	};
		/*
		behave 함수는 기존의 moveX 함수를 대체합니다.
		moveX 함수보다 더욱 사용처가 명확한 기능을 담당하고 있습니다.
		*/
	CarA() : Next(NULL), Before(NULL), Car(0, -3, 2, 3) {};
	CarA(int x) : Next(NULL), Before(NULL), Car(x, -3, 2, 3) {};
	~CarA() {};
	CarA(CarA* a) : Next(NULL), Before(a), Car(0, -3, 2, 3) {};

};

class CarB : virtual public Car { //CarA 설명 참조

	CarB *Next, *Before;

public:

	CarB* getNext() { return Next; };
	CarB* getBefore() { return Before; };
	CarB* setNext(CarB* b) { return (Next = b); };
	CarB* setBefore(CarB* b) { return (Before = b); };
	CarB& behave() {

		this->posY += (getRand(3)) ? 1 : 0;
		//this->posY += 1;

		if (this->posY + this->carH > Setting::E->roadY && this->decompose())
			this->removeSign = true;

		return *this;

	};
	CarB() : Next(NULL), Before(NULL), Car(0, -2, 2, 2) {};
	CarB(int x) : Next(NULL), Before(NULL), Car(x, -2, 2, 2) {};
	~CarB() {};
	CarB(CarB* b) : Next(NULL), Before(b), Car(0, -2, 2, 2) {};

};

class CarC : virtual public Car { //CarA 설명 참조

	CarC *Next, *Before;

public:

	CarC* getNext() { return Next; };
	CarC* getBefore() { return Before; };
	CarC* setNext(CarC* c) { return (Next = c); };
	CarC* setBefore(CarC* c) { return (Before = c); };
	CarC& behave() {

		this->posY += getRand(2);
		//this->posY += 1;

		int beX = getRand(3, 1);

		if (this->posX + beX >= 0 && this->posX + beX <= (Setting::E->roadX - this->getCarW()))
			this->posX += beX;

		if (this->posY + this->carH > Setting::E->roadY && this->decompose())
			this->removeSign = true;

		return *this;

	};
	CarC() : Next(NULL), Before(NULL), Car(0, -2, 3, 2) {};
	CarC(int x) : Next(NULL), Before(NULL), Car(x, -2, 3, 2) {};
	~CarC() {};
	CarC(CarC* c) : Next(NULL), Before(c), Car(0, -2, 3, 2) {};

};

class __Pixel {

	/*
	방해물과 방해물 사이, 방해물과 캐릭터 사이의 충돌 처리를 보다 쉽게 하기 위해 만들어진 Class입니다.
	__Pixel은 한 칸을 담당하는 Class입니다.
	*/

public:

	CarA* A;
	CarB* B;
	CarC* C;

	bool detAAOA(CarA* a) { return ((A != NULL && A != a) || B != NULL || C != NULL); };
		/* 해당 칸이 CarA의 입장에서 이동할 수 있는 칸인지를 판단합니다. */
	bool detAAOB(CarB* b) { return (A != NULL || (B != NULL && B != b) || C != NULL); };
		/* 해당 칸이 CarB의 입장에서 이동할 수 있는 칸인지를 판단합니다. */
	bool detAAOC(CarC* c) { return (A != NULL || B != NULL || (C != NULL && C != c)); };
		/* 해당 칸이 CarC의 입장에서 이동할 수 있는 칸인지를 판단합니다. */
	bool detect() { return (A != NULL || B != NULL || C != NULL); };
		/* 해당 칸에 방해물이 있는지를 판단합니다. */

	void setA(CarA* a) { A = a; }; //해당 칸에 CarA가 있음을 설정합니다.
	void setB(CarB* b) { B = b; }; //해당 칸에 CarB가 있음을 설정합니다.
	void setC(CarC* c) { C = c; }; //해당 칸에 CarC가 있을을 설정합니다.

	__Pixel() : A(NULL), B(NULL), C(NULL) {};
	~__Pixel() {};

};

class _Pixel {

	/*
	방해물과 방해물 사이, 방해물과 캐릭터 사이의 충돌 처리를 보다 쉽게 하기 위해 만들어진 Class입니다.
	_Pixel은 __Pixel들을 배열로 묶어 관리하는 Class입니다.
	*/

	__Pixel* P[40][22]; // P[y][x]
	int C, R;

public:

	__Pixel& getPixel(int x, int y) { return *(P[y][x]); }; //특정 픽셀을 반환합니다.

	__Pixel& setPixel(int x, int y, CarA* a) { P[y][x]->setA(a); return *(P[y][x]); }; //CarA 타입의 픽셀을 설정합니다.
	__Pixel& setPixel(int x, int y, CarB* b) { P[y][x]->setB(b); return *(P[y][x]); }; //CarB 타입의 픽셀을 설정합니다.
	__Pixel& setPixel(int x, int y, CarC* c) { P[y][x]->setC(c); return *(P[y][x]); }; //CarC 타입의 픽셀을 설정합니다.

	_Pixel(int x, int y) : C(x), R(y) {

		using std::endl;

		for (int i = 0; i++ < y;) {

			__Pixel *now;

			for (int j = 0; j++ < x; P[i - 1][j - 1] = now)
				now = new __Pixel;

		}

	};

	~_Pixel() {

		for (int i = 0; i++ < this->R;)
			for (int j = 0; j++ < this->C; delete P[i - 1][j - 1]);

	};

};

namespace Setting {

	static _Pixel* P; //Setting namespace에 _Pixel pointer를 추가시켜줍니다.

}

class _L { //링크드 리스트 Class

	int count[3];

	CarA *AFront, *ARear;
	CarB *BFront, *BRear;
	CarC *CFront, *CRear;

public:

	_L& add(CarA* a, _Pixel& P) { //링크드 리스트에 CarA를 추가하는 함수입니다.

		int count = this->count[0]++;

		if (!count)
			AFront = a;

		a->setBefore(ARear);

		if (count)
			ARear->setNext(a);

		ARear = a;

		for (int j = 0; j++ < a->getOCarH();)
			for (int k = 0; k++ < a->getOCarW();)
				if (a->getPosY() + j - 1 >= 0)
					P.getPixel(a->getPosX() + k - 1, a->getPosY() + j - 1).A = a;

		return *this;

	};

	_L& add(CarB* b, _Pixel& P) { //링크드 리스트에 CarB를 추가하는 함수입니다.

		int count = this->count[1]++;

		if (!count)
			BFront = b;

		b->setBefore(BRear);

		if (count)
			BRear->setNext(b);

		BRear = b;

		for (int j = 0; j++ < b->getOCarH();)
			for (int k = 0; k++ < b->getOCarW();)
				if (b->getPosY() + j - 1 >= 0)
					P.getPixel(b->getPosX() + k - 1, b->getPosY() + j - 1).B = b;

		return *this;

	};

	_L& add(CarC* c, _Pixel& P) { //링크드 리스트에 CarC를 추가하는 함수입니다.

		int count = this->count[2]++;

		if (!count)
			CFront = c;

		c->setBefore(CRear);

		if (count)
			CRear->setNext(c);

		CRear = c;

		for (int j = 0; j++ < c->getOCarH();)
			for (int k = 0; k++ < c->getOCarW();)
				if (c->getPosY() + j - 1 >= 0)
					P.getPixel(c->getPosX() + k - 1, c->getPosY() + j - 1).C = c;

		return *this;

	};

	CarA* getAFront() { return AFront; };
	CarB* getBFront() { return BFront; };
	CarC* getCFront() { return CFront; };

	int* getCount() { return count; }; //각 리스트의 개수를 세기 위해 만든 함수입니다.

	inline _L& randomInsert(_Pixel&); //무작위로 CarA, CarB, CarC 중에 선택해서 하나를 추가하는 함수입니다.

	_L() : AFront(NULL), ARear(NULL), BFront(NULL), BRear(NULL), CFront(NULL), CRear(NULL) { count[0] = 0; count[1] = 0, count[2] = 0; };

	inline void X() { //일종의 Destructor같은 함수입니다.

		CarA *A = this->AFront, *tempA;
		CarB *B = this->BFront, *tempB;
		CarC *C = this->CFront, *tempC;

		for (int i = 0; i < this->count[0]; i++) {

			tempA = A;
			A = A->getNext();
			delete tempA;

		}

		for (int i = 0; i < this->count[1]; i++) {

			tempB = B;
			B = B->getNext();
			delete tempB;

		}

		for (int i = 0; i < this->count[2]; i++) {

			tempC = C;
			C = C->getNext();
			delete tempC;

		}

	};

	inline _L& behave(Setting::Env&, _Pixel&); //링크드 리스트 위에 있는 모든 Car에 대해서 행동을 취하게 하는 함수입니다.

	inline _L& remove(CarA *a); //링크드 리스트에서 특정한 CarA를 제거하는 함수입니다.
	inline _L& remove(CarB *b); //링크드 리스트에서 특정한 CarB를 제거하는 함수입니다.
	inline _L& remove(CarC *c); //링크드 리스트에서 특정한 CarC를 제거하는 함수입니다.

};

_L& _L::remove(CarA* a) {

	if (a->getBefore() != NULL)
		a->getBefore()->setNext(a->getNext());

	if (a->getNext() != NULL)
		a->getNext()->setBefore(a->getBefore());

	if (a == this->AFront)
		this->AFront = a->getNext();
	if (a == this->ARear)
		this->ARear = a->getBefore();

	this->count[0]--;

	COORD LastLeft = { (((Setting::scrSize[0]) - (Setting::E->roadX) * 2) / 2) - 2, 2 + Setting::E->roadY };

	COORD LastRight = { Setting::scrSize[0] - (((Setting::scrSize[0]) - (Setting::E->roadX) * 2) / 2), 2 + Setting::E->roadY };

	COORD XY = { LastLeft.X + a->getRealPosX(), LastLeft.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

	for (int i = -1; i++ <= a->getCarW();)
		cout << "  ";

	for (int i = 0; i < Setting::E->roadX; i++)
		if (Setting::P->getPixel(i, Setting::E->roadY - 1).A == a)
			Setting::P->setPixel(i, Setting::E->roadY - 1, (CarA*)NULL);

	Setting::setColor(15);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastLeft);
	cout << "□";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "□";
	Setting::setColor(7);

	delete a;

	return *this;

};

_L& _L::remove(CarB* b) {

	if (b->getBefore() != NULL)
		b->getBefore()->setNext(b->getNext());

	if (b->getNext() != NULL)
		b->getNext()->setBefore(b->getBefore());

	if (b == this->BFront)
		this->BFront = b->getNext();
	if (b == this->BRear)
		this->BRear = b->getBefore();

	this->count[1]--;

	COORD LastLeft = { (((Setting::scrSize[0]) - (Setting::E->roadX) * 2) / 2) - 2, 2 + Setting::E->roadY };

	COORD LastRight = { Setting::scrSize[0] - (((Setting::scrSize[0]) - (Setting::E->roadX) * 2) / 2), 2 + Setting::E->roadY };

	COORD XY = { LastLeft.X + b->getRealPosX(), LastLeft.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

	for (int i = -1; i++ <= b->getCarW();)
		cout << "  ";

	for (int i = 0; i < Setting::E->roadX; i++)
		if (Setting::P->getPixel(i, Setting::E->roadY - 1).B == b)
			Setting::P->setPixel(i, Setting::E->roadY - 1, (CarB*)NULL);

	Setting::setColor(15);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastLeft);
	cout << "□";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "□";
	Setting::setColor(7);

	delete b;

	return *this;

};

_L& _L::remove(CarC* c) {

	if (c->getBefore() != NULL)
		c->getBefore()->setNext(c->getNext());

	if (c->getNext() != NULL)
		c->getNext()->setBefore(c->getBefore());

	if (c == this->CFront)
		this->CFront = c->getNext();
	if (c == this->CRear)
		this->CRear = c->getBefore();

	this->count[2]--;

	COORD LastLeft = { (((Setting::scrSize[0]) - (Setting::E->roadX) * 2) / 2) - 2, 2 + Setting::E->roadY };

	COORD LastRight = { Setting::scrSize[0] - (((Setting::scrSize[0]) - (Setting::E->roadX) * 2) / 2), 2 + Setting::E->roadY };

	COORD XY = { LastLeft.X + c->getRealPosX(), LastLeft.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

	for (int i = -1; i++ <= c->getCarW();)
		cout << "  ";

	for (int i = 0; i < Setting::E->roadX; i++)
		if (Setting::P->getPixel(i, Setting::E->roadY - 1).C == c)
			Setting::P->setPixel(i, Setting::E->roadY - 1, (CarC*)NULL);

	Setting::setColor(15);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastLeft);
	cout << "□";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "□";
	Setting::setColor(7);

	delete c;

	return *this;

};

_L& _L::randomInsert(_Pixel& P) {

	CarA* a;
	CarB* b;
	CarC* c;

	switch (getRand(11)) {

	case 7:
	case 3:
	case 0:
		a = new CarA(getRand(Setting::E->roadX - 1));
		add(a, P);
		break;

	case 10:
	case 8:
	case 4:
	case 1:
		b = new CarB(getRand(Setting::E->roadX - 1));
		add(b, P);
		break;

	case 9:
	case 5:
	case 2:
		c = new CarC(getRand(Setting::E->roadX - 2));
		add(c, P);
		break;

	case 6:
		break;

	}

	return *this;

};

_L& _L::behave(Setting::Env& E, _Pixel& P) {

	bool breakSign = false;

	if (count[0]) {

		CarA *a = AFront, *tempA;

		for (int i = 0; i++ < count[0];) {

			if (a->behave().hasRemoveSign()) {

				tempA = a;

				a = a->getNext();

				this->remove(tempA);

			}
			else {

				for (int j = 0; j < a->getCarH() && !breakSign; j++)
					for (int k = 0; k < a->getCarW() && !breakSign; k++)
						if (a->getPosY() + j >= 0)
							if (P.getPixel(a->getPosX() + k, a->getPosY() + j).detAAOA(a)) {

								a->setPosX(a->getPrePosXAAOP());
								a->setPosY(a->getPrePos().Y);

								breakSign = true;

							};

				if (!breakSign) {

					for (int j = 0; j < a->getCarH(); j++)
						for (int k = 0; k < a->getCarW(); k++)
							if (a->getPrePos().Y + j >= 0)
								P.getPixel(a->getPrePosXAAOP() + k, a->getPrePos().Y + j).A = NULL;

					for (int j = 0; j < a->getCarH(); j++)
						for (int k = 0; k < a->getCarW(); k++)
							if (a->getPosY() + j >= 0) {

								int pad = (((Setting::scrSize[0]) - (E.roadX * 2)) / 2);

								/* For checking blocker's real position
								COORD temp = { (a->getPosX() + k) * 2 + pad, (a->getPosY() + j) + 3 };
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
								cout << "XX";
								*/

								P.getPixel(a->getPosX() + k, a->getPosY() + j).A = a;

							}

				}
				else
					breakSign = false;

				a = a->getNext();

			}

		}

	}

	if (count[1]) {

		CarB *b = BFront, *tempB;

		for (int i = 0; i++ < count[1];) {

			if (b->behave().hasRemoveSign()) {

				tempB = b;

				b = b->getNext();

				this->remove(tempB);

			}
			else {

				for (int j = 0; j < b->getCarH() && !breakSign; j++)
					for (int k = 0; k < b->getCarW() && !breakSign; k++)
						if (b->getPosY() + j >= 0)
							if (P.getPixel(b->getPosX() + k, b->getPosY() + j).detAAOB(b)) {

								b->setPosX(b->getPrePosXAAOP());
								b->setPosY(b->getPrePos().Y);

								breakSign = true;

							};

				if (!breakSign) {

					for (int j = 0; j < b->getCarH(); j++)
						for (int k = 0; k < b->getCarW(); k++)
							if (b->getPrePos().Y + j >= 0)
								P.getPixel(b->getPrePosXAAOP() + k, b->getPrePos().Y + j).B = NULL;

					for (int j = 0; j < b->getCarH(); j++)
						for (int k = 0; k < b->getCarW(); k++)
							if (b->getPosY() + j >= 0) {

								int pad = (((Setting::scrSize[0]) - (E.roadX * 2)) / 2);

								P.getPixel(b->getPosX() + k, b->getPosY() + j).B = b;

							}

				}
				else
					breakSign = false;

				b = b->getNext();

			}

		}

	}

	if (count[2]) {

		CarC *c = CFront, *tempC;

		for (int i = 0; i++ < count[2];) {

			if (c->behave().hasRemoveSign()) {

				tempC = c;

				c = c->getNext();

				this->remove(tempC);

			}
			else {

				for (int j = 0; j < c->getCarH() && !breakSign; j++)
					for (int k = 0; k < c->getCarW() && !breakSign; k++)
						if (c->getPosY() + j >= 0)
							if (P.getPixel(c->getPosX() + k, c->getPosY() + j).detAAOC(c)) {

								c->setPosX(c->getPrePosXAAOP());
								c->setPosY(c->getPrePos().Y);

								breakSign = true;

							};

				if (!breakSign) {

					for (int j = 0; j < c->getCarH(); j++)
						for (int k = 0; k < c->getCarW(); k++)
							if (c->getPrePos().Y + j >= 0)
								P.getPixel(c->getPrePosXAAOP() + k, c->getPrePos().Y + j).C = NULL;

					for (int j = 0; j < c->getCarH(); j++)
						for (int k = 0; k < c->getCarW(); k++)
							if (c->getPosY() + j >= 0) {

								int pad = (((Setting::scrSize[0]) - (E.roadX * 2)) / 2);

								P.getPixel(c->getPosX() + k, c->getPosY() + j).C = c;

							}

				}
				else
					breakSign = false;

				c = c->getNext();

			}

		}

	}

	return *this;

};

class _M : virtual public CarA, virtual public CarB { //myCar

	int Colour;
	int idioPosSys[2];

public:

	void setColor(int c) { Colour = c; };
	int getColor() { return Colour; }; //색상 값을 얻기 위한 함수입니다.
	int* getPos() { idioPosSys[0] = this->getPosX(); idioPosSys[1] = this->getPosY(); return idioPosSys; };
		/* 현재 myCar의 위치를 배열 포인터 형식으로 반환하는 함수입니다. */
	_M(int posX, int posY, int c) : Colour(c) { this->setPosX(posX); this->setPosY(posY); this->idioPosSys[0] = 0; this->idioPosSys[1] = 0; };
	~_M() {};

};
