#include<iostream>
using namespace std;
활발한 업데이트 진행중 지금도 계속 진행하고있음
class Vehicle {
private:
    string Serial_number;
protected:
    string engine_type;
public:
    Vehicle(string serial, string engine) : Serial_number(serial), engine_type(engine) {
        cout << "차량 생성: " << Serial_number << endl;
    }

    ~Vehicle() {
        cout << "차량 소멸: " << Serial_number << endl;
    }

    void set_engine_type(string type) {
        engine_type = type;
    }

    string get_engine_type() const {
        return engine_type;
    }
};

class Gasoline : public Vehicle {
protected:
    int oil_gauge;
public:
    Gasoline(string serial, string engine, int oil) : Vehicle(serial, engine), oil_gauge(oil) {
        cout << "가솔린 차량 생성: " << serial << endl;
    }

    void start_engine() {
        cout << "가솔린 엔진 시작" << endl;
    }

    int get_oil_gauge() const {
        return oil_gauge;
    }

    void accelerate() {
        if (oil_gauge <= 0) {
            cout << "기름을 충전하세요" << endl;
        }
        else {
            oil_gauge -= 5;
            cout << "엔진 가속" << endl;
            cout << "잔여 기름 양: " << oil_gauge << endl;
        }
    }
};

class Electric : public Vehicle {
protected:
    int charged_gauge;
public:
    Electric(string serial, string engine, int charged) : Vehicle(serial, engine), charged_gauge(charged) {
        cout << "전기 차량 생성: " << serial << endl;
    }

    void start_motor() {
        cout << "전기 모터 시작" << endl;
        cout << "잔여 배터리: " << charged_gauge << endl;
    }

    int get_charged_gauge() const {
        return charged_gauge;
    }

    void accelerate() {
        if (charged_gauge <= 0) {
            cout << "배터리를 충전하세요" << endl;
        }
        else {
            charged_gauge -= 10;
            cout << "전기 모터 가속" << endl;
            cout << "잔여 배터리: " << charged_gauge << endl;
        }
    }
};

class Hybrid : public Gasoline, public Electric {
public:
    Hybrid(string serial, string engine, int oil, int charged)
        : Gasoline(serial, engine, oil), Electric(serial, engine, charged) {
        cout << "하이브리드 차량 생성: " << serial << endl;
    }

    void accelerate() {
        if (oil_gauge > 0) {
            Gasoline::accelerate();
        }
        else {
            Electric::accelerate();
        }
    }
};

int main() {
    Gasoline gasCar("GAS", "가솔린 엔진", 10);
    Electric elecCar("ELECTRIC", "전기 모터", 20);
    Hybrid hybridCar("HYBRID", "하이브리드", 10, 20);

    cout << "가솔린 차량 가속:" << endl;
    gasCar.accelerate();
    gasCar.accelerate();
    gasCar.accelerate();

    cout << "\n전기 차량 가속:" << endl;
    elecCar.accelerate();
    elecCar.accelerate();
    elecCar.accelerate();

    cout << "\n하이브리드 차량 가속:" << endl;
    hybridCar.accelerate();
    hybridCar.accelerate();
    hybridCar.accelerate();
    hybridCar.accelerate();
    hybridCar.accelerate();

    return 0;
}
