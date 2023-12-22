#include <iostream>
#include <thread>  // 为了演示目的，使用了std::this_thread::sleep_for
#include <chrono>  // 为了演示目的，使用了std::chrono::seconds

using namespace std;

// 枚举交通灯的状态
enum TrafficLightState {
    RED,
    GREEN
};

// 交通灯类
class TrafficLight {
private:
    TrafficLightState state;

public:
    TrafficLight() : state(RED) {}

    // 切换交通灯状态
    void toggle() {
        state = (state == RED) ? GREEN : RED;
    }

    // 获取交通灯当前状态
    TrafficLightState getState() const {
        return state;
    }
};

// 控制五叉路口的交通灯
class TrafficController {
private:
    TrafficLight trafficLights[6];

public:
    // 设置初始的交通灯状态
    TrafficController() {
        // 初始化为方案1的状态
        trafficLights[0] = TrafficLight(); // A
        trafficLights[1] = TrafficLight(); // B
        trafficLights[2] = TrafficLight(); // C
        trafficLights[3] = TrafficLight(); // D
        trafficLights[4] = TrafficLight(); // E
        trafficLights[5] = TrafficLight(); // F
    }

    // 更新交通灯状态
    void updateLights(int scheme) {
        switch (scheme) {
        case 1:
            // 方案1: AB, CD, E
            trafficLights[0].toggle();
            trafficLights[1].toggle();
            trafficLights[2].toggle();
            trafficLights[3].toggle();
            trafficLights[4].toggle();
            break;

        case 2:
            // 方案2: A, B, CDE, F
            trafficLights[0].toggle();
            trafficLights[1].toggle();
            trafficLights[2].toggle();
            trafficLights[4].toggle();
            trafficLights[5].toggle();
            break;

            // ... 其他方案类似

        default:
            break;
        }
    }

    // 打印当前交通灯状态
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

    // 模拟六个方案，每个方案运行10秒
    for (int scheme = 1; scheme <= 6; ++scheme) {
        cout << "方案" << scheme << "：" << endl;
        controller.updateLights(scheme);
        controller.printStatus();
        cout << "===================" << endl;

        // 暂停10秒，模拟交通灯的状态变化
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
