#pragma once
#include "Core.kano.h"
#include "Parameter.h"
#include <algorithm>
#include <ctime>

static int getRand(int d) { static int X = 0; srand(((X) ? X : time(NULL))); X = rand(); return (X % d); };
	/* getRand �Լ��� 1�� �̳��� �ð��� �ݺ��ؼ� ȣ��Ǵ��� �ٸ� ������ �����ϴ� �Լ��Դϴ�. */
static int getRand(int d, int m) { return getRand(d) - m; };
static unsigned int regId() { return ++Setting::blockers; };
	/* ���� �������� ���ع��� ���� �� �� �ֵ��� ��ȣ�� ���̱� ���� ���Ǿ��� �Լ��Դϴ�. */

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
		/* Car ��� ��, ������ ��ġ ������ ����صξ��ٰ� ����� ���� ������� �Լ��Դϴ�. prePos�� �����մϴ�. */
	void count() { scoreCounted = true; };
		/* ������ �ߺ��ؼ� ���� �ʰ� �ϱ� ���� ������� �Լ��Դϴ�. scoreCounted�� true�� �����մϴ�. */
	int getId() { return id; };
		/* ���� �������� ���ع��� ���� �� �� �ֵ��� ��ȣ�� ���̱� ���� ���Ǿ��� �Լ��Դϴ�. */
	int getPosX() { return posX; }; //getCx
	int getRealPosX() { return (posX * 2) - 1; };
		/*
		�̹� ���������� ���� ���� ���� (0, 0)���� �ϴ� ������ �ȼ� ������ Ȱ���Ͽ����ϴ�.
		Car Object������ ���� ��ġ ������ �ȼ� ���� �������� �����ϰ�, ���� ��ġ ������ COORD ���·� �����մϴ�.
		�� �Լ��� ���� ��ġ ������ ���� ��ġ ������ �� ��, X��ǥ ��ȯ�� ���� �ϱ� ���� ������� �Լ��Դϴ�.
		*/
	int getPrePosXAAOP() { return ((prePos.X + 1) / 2); };
		/* ���� �Լ�(getRealPosX)�� ������� ������ �����մϴ�. �� �Լ��� COORD ������ X ��ǥ�� �ȼ� ���·� ����ϴ�. */
	int getPosY() { return posY; }; //getCy
	int getCarH() { return carH; }; //getHeight
	int getCarW() { return carW; }; //getWidth
	int getOCarH() { return carOH; };
		/*
		��� ���ع��� ���� �Ʒ� �ȼ��� ������ ���� ���� ª�� �ֱ⸶�� ��ĭ�� �پ��� �Ǿ� �ֽ��ϴ�.
		������ ���ع��� ���� �Ʒ��� ����� ���� ������ ũ���� ó���ؾ� �� ���� �ֽ��ϴ�.
		�� ���, ���� ���ع��� ũ�⸦ ���ϱ� ���� ���� �Լ��Դϴ�.
		*/
	int getOCarW() { return carOW; };
		/* ���� �Լ�(getOCarH)�� ������� ������ �����մϴ�. */
	bool isCounted() { return scoreCounted; };
		/* ������ �ߺ��ؼ� ���� �ʰ� �ϱ� ���� ������� �Լ��Դϴ�. scoreCounted�� ��ȯ�մϴ�. */
	bool hasRemoveSign() { return removeSign; };
		/*
		���ع��� ���� �Ʒ� �ȼ��� ��� ���� ���̰� 0�� �Ǿ��� ��쿡�� removeSign�� ��� �˴ϴ�.
		removeSign�� �߸� �ش� ���ع��� �� ��ũ�� ����Ʈ���� ���ܵ˴ϴ�.
		�׷��� ó���� ���� ���� �Լ��Դϴ�.
		*/
	COORD getPrePos() { return prePos; };
		/* Car Object�� ���� ��ġ�� �˱� ���� ���� �Լ��Դϴ�. */
	bool decompose() { return !(--carH); };
		/*
		getOCarH, getOCarW �Լ��� ������� ������ �����մϴ�.
		���� �Ʒ� �ȼ��� ����� �� ����Ǵ� �Լ��ε�, Car Object�� ���� ���̸� �� ĭ ���Դϴ�.
		*/
	Car() {};
	Car(int x, int y, int w, int h) : id(regId()), scoreCounted(false), posX(x), posY(y), carW(w), carH(h), carOH(h), carOW(w), removeSign(false) { prePos.X = (2 * x) - 1; prePos.Y = y; };
	~Car() {};

};

class CarA : virtual public Car {

	CarA *Next, *Before;

public:

	CarA* getNext() { return Next; };
	CarA* getBefore() { return Before; }; //��ũ�� ����Ʈ�� �ٲٸ鼭 ������ �Լ�
	CarA* setNext(CarA* a) { return (Next = a); };
	CarA* setBefore(CarA* a) { return (Before = a); }; //��ũ�� ����Ʈ�� �ٲٸ鼭 ������ �Լ�
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
		behave �Լ��� ������ moveX �Լ��� ��ü�մϴ�.
		moveX �Լ����� ���� ���ó�� ��Ȯ�� ����� ����ϰ� �ֽ��ϴ�.
		*/
	CarA() : Next(NULL), Before(NULL), Car(0, -3, 2, 3) {};
	CarA(int x) : Next(NULL), Before(NULL), Car(x, -3, 2, 3) {};
	~CarA() {};
	CarA(CarA* a) : Next(NULL), Before(a), Car(0, -3, 2, 3) {};

};

class CarB : virtual public Car { //CarA ���� ����

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

class CarC : virtual public Car { //CarA ���� ����

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
	���ع��� ���ع� ����, ���ع��� ĳ���� ������ �浹 ó���� ���� ���� �ϱ� ���� ������� Class�Դϴ�.
	__Pixel�� �� ĭ�� ����ϴ� Class�Դϴ�.
	*/

public:

	CarA* A;
	CarB* B;
	CarC* C;

	bool detAAOA(CarA* a) { return ((A != NULL && A != a) || B != NULL || C != NULL); };
		/* �ش� ĭ�� CarA�� ���忡�� �̵��� �� �ִ� ĭ������ �Ǵ��մϴ�. */
	bool detAAOB(CarB* b) { return (A != NULL || (B != NULL && B != b) || C != NULL); };
		/* �ش� ĭ�� CarB�� ���忡�� �̵��� �� �ִ� ĭ������ �Ǵ��մϴ�. */
	bool detAAOC(CarC* c) { return (A != NULL || B != NULL || (C != NULL && C != c)); };
		/* �ش� ĭ�� CarC�� ���忡�� �̵��� �� �ִ� ĭ������ �Ǵ��մϴ�. */
	bool detect() { return (A != NULL || B != NULL || C != NULL); };
		/* �ش� ĭ�� ���ع��� �ִ����� �Ǵ��մϴ�. */

	void setA(CarA* a) { A = a; }; //�ش� ĭ�� CarA�� ������ �����մϴ�.
	void setB(CarB* b) { B = b; }; //�ش� ĭ�� CarB�� ������ �����մϴ�.
	void setC(CarC* c) { C = c; }; //�ش� ĭ�� CarC�� ������ �����մϴ�.

	__Pixel() : A(NULL), B(NULL), C(NULL) {};
	~__Pixel() {};

};

class _Pixel {

	/*
	���ع��� ���ع� ����, ���ع��� ĳ���� ������ �浹 ó���� ���� ���� �ϱ� ���� ������� Class�Դϴ�.
	_Pixel�� __Pixel���� �迭�� ���� �����ϴ� Class�Դϴ�.
	*/

	__Pixel* P[40][22]; // P[y][x]
	int C, R;

public:

	__Pixel& getPixel(int x, int y) { return *(P[y][x]); }; //Ư�� �ȼ��� ��ȯ�մϴ�.

	__Pixel& setPixel(int x, int y, CarA* a) { P[y][x]->setA(a); return *(P[y][x]); }; //CarA Ÿ���� �ȼ��� �����մϴ�.
	__Pixel& setPixel(int x, int y, CarB* b) { P[y][x]->setB(b); return *(P[y][x]); }; //CarB Ÿ���� �ȼ��� �����մϴ�.
	__Pixel& setPixel(int x, int y, CarC* c) { P[y][x]->setC(c); return *(P[y][x]); }; //CarC Ÿ���� �ȼ��� �����մϴ�.

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

	static _Pixel* P; //Setting namespace�� _Pixel pointer�� �߰������ݴϴ�.

}

class _L { //��ũ�� ����Ʈ Class

	int count[3];

	CarA *AFront, *ARear;
	CarB *BFront, *BRear;
	CarC *CFront, *CRear;

public:

	_L& add(CarA* a, _Pixel& P) { //��ũ�� ����Ʈ�� CarA�� �߰��ϴ� �Լ��Դϴ�.

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

	_L& add(CarB* b, _Pixel& P) { //��ũ�� ����Ʈ�� CarB�� �߰��ϴ� �Լ��Դϴ�.

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

	_L& add(CarC* c, _Pixel& P) { //��ũ�� ����Ʈ�� CarC�� �߰��ϴ� �Լ��Դϴ�.

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

	int* getCount() { return count; }; //�� ����Ʈ�� ������ ���� ���� ���� �Լ��Դϴ�.

	inline _L& randomInsert(_Pixel&); //�������� CarA, CarB, CarC �߿� �����ؼ� �ϳ��� �߰��ϴ� �Լ��Դϴ�.

	_L() : AFront(NULL), ARear(NULL), BFront(NULL), BRear(NULL), CFront(NULL), CRear(NULL) { count[0] = 0; count[1] = 0, count[2] = 0; };

	inline void X() { //������ Destructor���� �Լ��Դϴ�.

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

	inline _L& behave(Setting::Env&, _Pixel&); //��ũ�� ����Ʈ ���� �ִ� ��� Car�� ���ؼ� �ൿ�� ���ϰ� �ϴ� �Լ��Դϴ�.

	inline _L& remove(CarA *a); //��ũ�� ����Ʈ���� Ư���� CarA�� �����ϴ� �Լ��Դϴ�.
	inline _L& remove(CarB *b); //��ũ�� ����Ʈ���� Ư���� CarB�� �����ϴ� �Լ��Դϴ�.
	inline _L& remove(CarC *c); //��ũ�� ����Ʈ���� Ư���� CarC�� �����ϴ� �Լ��Դϴ�.

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
	cout << "��";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "��";
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
	cout << "��";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "��";
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
	cout << "��";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "��";
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
	int getColor() { return Colour; }; //���� ���� ��� ���� �Լ��Դϴ�.
	int* getPos() { idioPosSys[0] = this->getPosX(); idioPosSys[1] = this->getPosY(); return idioPosSys; };
		/* ���� myCar�� ��ġ�� �迭 ������ �������� ��ȯ�ϴ� �Լ��Դϴ�. */
	_M(int posX, int posY, int c) : Colour(c) { this->setPosX(posX); this->setPosY(posY); this->idioPosSys[0] = 0; this->idioPosSys[1] = 0; };
	~_M() {};

};
