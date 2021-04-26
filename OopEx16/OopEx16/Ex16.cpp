#include<iostream>
#include<assert.h>
using namespace std;
#define MAX 10

template<typename T>
class Stack {
private:
	T items[MAX];
	int top;
public:
	Stack() {
		top = -1;
	}

	bool push(T item) {
		if (top >= (MAX - 1)) {
			cout << "Stack overflow!";
			return false;
		}
		else {
			++top;
			items[top] = item;
			return true;
		}
	}
	T peek() {
		if (top < 0) {
			cout << "Stack is Empty!" << endl;

		}
		else {
			return items[top];
		}
	}
	T pop() {
		if (top < 0) {
			cout << "Stack is underflow!" << endl;
			return *(new T);
		}
		else {
			return items[top--];
		}
	}
	bool isEmpty() const { return top < 0; }
	bool isFull() const { return top == (MAX - 1); }

};

class Engine {
	int _engine_no;
	string _company;
	double _volume;
public:
	Engine() :_engine_no(), _company(), _volume() {}
	Engine(const int engine_no, const string& company, const double volume)
	{
		SetEngineNo(engine_no);
		SetCompany(company);
		SetVolume(volume);
	}

	int GetEngineNo()const { return _engine_no; }
	string GetCompany()const { return _company; }
	double GetVolume()const { return _volume; }

	void SetEngineNo(const int engine_no) {
		assert(engine_no > 0 && "Engine no < 0");
		_engine_no = engine_no;
	}
	void SetCompany(const string& company) {
		if (company.empty()) return;
		_company = company;
	}
	void SetVolume(const double volume) {
		assert(volume > 0 && "Volume < 0");
		_volume = volume;
	}

	void show() {
		cout << "******** Engine Info ********" << endl;
		cout << "Engine no: " << _engine_no << endl;
		cout << "Company: " << _company << endl;
		cout << "Volume: " << _volume << endl;
	}
};

class Transportation {
	int _id;
	string _model;
	string _vendor;
	Engine _engine;
public:
	Transportation() :_id(), _model(), _vendor(), _engine() {}
	Transportation(const int id, const string& model, const string& vendor, Engine& engine)
	{
		SetId(id);
		SetModel(model);
		SetVendor(vendor);
		SetEngine(engine);
	}

	int GetId()const { return _id; }
	string GetModel()const { return _model; }
	string GetVendor()const { return _vendor; }
	Engine GetEngine()const { return _engine; }

	void SetId(const int id) {
		assert(id >= 0 && "Id < 0");
		_id = id;
	}
	void SetModel(const string& model) {
		if (model.empty()) return;
		_model = model;
	}
	void SetVendor(const string& vendor) {
		if (vendor.empty()) return;
		_vendor = vendor;
	}
	void SetEngine(const Engine& engine) {
		_engine = engine;
	}

	void show() {
		cout << "Id: " << GetId() << endl;
		cout << "Model: " << GetModel() << endl;
		cout << "Vendor: " << GetVendor() << endl;
		_engine.show();
	}
};

class Car :public Transportation {
	bool _hasSpoiler;
public:
	Car() :_hasSpoiler() {}
	Car(const int id, const string& model, const string& vendor, Engine& engine, const bool hasSpoiler) :Transportation(id, model, vendor, engine)
	{
		SetHasSpoiler(hasSpoiler);
	}

	bool GetHasSpoiler()const { return _hasSpoiler; }
	void SetHasSpoiler(const bool hasSpoiler) {
		_hasSpoiler = hasSpoiler;
	}

	void show() {
		cout << "******** Car Info ********" << endl;
		Transportation::show();
		if (_hasSpoiler == 1) cout << "Has spoiler: Yes" << endl << endl;
		else cout << "Has spoiler: No" << endl << endl;
	}
};

class Ship :public Transportation {
	bool _hasSail;
public:
	Ship() :_hasSail() {}
	Ship(const int id, const string& model, const string& vendor, Engine& engine, const bool hasSail) :Transportation(id, model, vendor, engine)
	{
		SetHasSail(hasSail);
	}

	bool GetHasSail()const { return _hasSail; }
	void SetHasSail(const bool hasSail) {
		_hasSail = hasSail;
	}

	void show() {
		cout << "******** Ship Info ********" << endl;
		Transportation::show();
		if (_hasSail == 1) cout << "Has sail: Yes" << endl << endl;
		else cout << "Has sail: No" << endl << endl;
	}
};

class Airplane :public Transportation {
	int _engineCount;
	int _passengersCapacity;
public:
	Airplane() :_engineCount(), _passengersCapacity() {}
	Airplane(const int id, const string& model, const string& vendor, Engine& engine, const int engineCount, const int passengersCapacity) :Transportation(id, model, vendor, engine)
	{
		SetEngineCount(engineCount);
		SetPassengersCapacity(passengersCapacity);
	}

	int GetEngineCount()const { return _engineCount; }
	int GetPassengersCapacity()const { return _passengersCapacity; }
	void SetEngineCount(const int engineCount) {
		assert(engineCount >= 0 && "Engine count < 0");
		_engineCount = engineCount;
	}
	void SetPassengersCapacity(const int passengersCapacity) {
		assert(passengersCapacity >= 0 && "Passengers capacity < 0");
		_passengersCapacity = passengersCapacity;
	}

	void show() {
		cout << "******** Airplane Info ********" << endl;
		Transportation::show();
		cout << "Engine count: " << _engineCount << endl;
		cout << "Passengers capacity: " << _passengersCapacity << endl;
	}
};

class VehicleDepo {
public:
	Stack<Car>cars;
	Stack<Ship>ships;
	Stack<Airplane>airplanes;

	VehicleDepo() = default;
	VehicleDepo(Stack<Car> cars, Stack<Ship> ships, Stack<Airplane> airplanes)
	{
		SetCars(cars);
		SetShips(ships);
		SetAirplanes(airplanes);
	}

	void SetCars(const Stack<Car>& cars) {
		this->cars = cars;
	}
	void SetShips(const Stack<Ship>& ships) {
		this->ships = ships;
	}
	void SetAirplanes(const Stack<Airplane>& airplanes) {
		this->airplanes = airplanes;
	}

	void showAllVehicle() {
		Stack<Car> temp1 = cars;
		Stack<Ship> temp2 = ships;
		Stack<Airplane> temp3 = airplanes;
		cout << "************ Vehicle Depo ************" << endl;
		while (!temp1.isEmpty()) {
			temp1.pop().show();
		}
		while (!temp2.isEmpty()) {
			temp2.pop().show();
		}
		while (!temp3.isEmpty()) {
			temp3.pop().show();
		}

	}
};

int main() {
	Engine engine_car1(1, "Motorsport", 4500);
	Car car1(1, "X6", "BMW", engine_car1, true);
	Engine engine_car2(2, "AMG S", 2500);
	Car car2(2, "S63", "Mersedes", engine_car2, false);


	Engine engine_ship1(3, "Ship engine", 2000);
	Ship ship1(3, "Ship model", "ShipFF", engine_ship1, true);


	Engine engine_airplane1(4, "air engine1", 7000);
	Airplane airplane1(4, "737", "Boeing", engine_airplane1, 2, 215);
	Engine engine_airplane2(5, "air engine2", 5000);
	Airplane airplane2(5, "7J7", "Boeing", engine_airplane2, 3, 166);


	VehicleDepo v1;
	v1.cars.push(car1);
	v1.cars.push(car2);
	v1.ships.push(ship1);
	v1.airplanes.push(airplane1);
	v1.airplanes.push(airplane2);
	v1.showAllVehicle();


}

