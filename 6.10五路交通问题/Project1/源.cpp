#include <iostream>
#include <thread>  // Ϊ����ʾĿ�ģ�ʹ����std::this_thread::sleep_for
#include <chrono>  // Ϊ����ʾĿ�ģ�ʹ����std::chrono::seconds

using namespace std;

// ö�ٽ�ͨ�Ƶ�״̬
enum TrafficLightState {
    RED,
    GREEN
};

// ��ͨ����
class TrafficLight {
private:
    TrafficLightState state;

public:
    TrafficLight() : state(RED) {}

    // �л���ͨ��״̬
    void toggle() {
        state = (state == RED) ? GREEN : RED;
    }

    // ��ȡ��ͨ�Ƶ�ǰ״̬
    TrafficLightState getState() const {
        return state;
    }
};

// �������·�ڵĽ�ͨ��
class TrafficController {
private:
    TrafficLight trafficLights[6];

public:
    // ���ó�ʼ�Ľ�ͨ��״̬
    TrafficController() {
        // ��ʼ��Ϊ����1��״̬
        trafficLights[0] = TrafficLight(); // A
        trafficLights[1] = TrafficLight(); // B
        trafficLights[2] = TrafficLight(); // C
        trafficLights[3] = TrafficLight(); // D
        trafficLights[4] = TrafficLight(); // E
        trafficLights[5] = TrafficLight(); // F
    }

    // ���½�ͨ��״̬
    void updateLights(int scheme) {
        switch (scheme) {
        case 1:
            // ����1: AB, CD, E
            trafficLights[0].toggle();
            trafficLights[1].toggle();
            trafficLights[2].toggle();
            trafficLights[3].toggle();
            trafficLights[4].toggle();
            break;

        case 2:
            // ����2: A, B, CDE, F
            trafficLights[0].toggle();
            trafficLights[1].toggle();
            trafficLights[2].toggle();
            trafficLights[4].toggle();
            trafficLights[5].toggle();
            break;

            // ... ������������

        default:
            break;
        }
    }

    // ��ӡ��ǰ��ͨ��״̬
    void printStatus() const {
        cout << "A: " << (trafficLights[0].getState() == RED ? "RED" : "GREEN") << endl;
        cout << "B: " << (trafficLights[1].getState() == RED ? "RED" : "GREEN") << endl;
        cout << "C: " << (trafficLights[2].getState() == RED ? "RED" : "GREEN") << endl;
        cout << "D: " << (trafficLights[3].getState() == RED ? "RED" : "GREEN") << endl;
        cout << "E: " << (trafficLights[4].getState() == RED ? "RED" : "GREEN") << endl;
        cout << "F: " << (trafficLights[5].getState() == RED ? "RED" : "GREEN") << endl;
    }
};

int main() {
    TrafficController controller;

    // ģ������������ÿ����������10��
    for (int scheme = 1; scheme <= 6; ++scheme) {
        cout << "����" << scheme << "��" << endl;
        controller.updateLights(scheme);
        controller.printStatus();
        cout << "===================" << endl;

        // ��ͣ10�룬ģ�⽻ͨ�Ƶ�״̬�仯
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
