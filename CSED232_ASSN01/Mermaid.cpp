#include "libKano.h"
#include <string>

class Snack {

	int id, amount;

	string name, manufacturer;

	float primeCost, sailCost, margin;

	Snack(int id, string name, int amount, float primeCost, float margin, float sailCost, string manufacturer) {
	
		this->id = id;
		this->name = name;
		this->amount = amount;
		this->margin = margin;
		this->primeCost = primeCost;
		this->manufacturer = manufacturer;
		this->sailCost = sailCost;
	
	};

public:

	bool setId(int id) {


	};

	bool setName(string name) {


	};

	bool setInfo(int price) {
	
	};

	int getId() {



	};

	string getName() {



	};

	int getInfo() {


	};

};