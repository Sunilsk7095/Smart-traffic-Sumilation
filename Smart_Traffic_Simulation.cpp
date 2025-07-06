#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Lane {
public:
    string name;
    queue<int> vehicles;

    Lane(string laneName) {
        name = laneName;
    }

    void addVehicles(int count, int &idStart) {
        for (int i = 0; i < count; i++) {
            vehicles.push(idStart++);
        }
    }

    void processLane() {
        cout << "\n>> Processing " << name << " Lane (" << vehicles.size() << " vehicles)\n";
        int totalTime = 0;

        while (!vehicles.empty()) {
            int id = vehicles.front();
            vehicles.pop();
            totalTime += 2; // 2 seconds per vehicle
            cout << "Vehicle " << id << " passed. (+2s)\n";
        }

        cout << "Total time taken for " << name << " lane: " << totalTime << " seconds\n";
    }
};

int main() {
    cout << "🚦 Simple Traffic Simulation 🚦\n";

    // Create 4 lanes
    Lane north("North"), south("South"), east("East"), west("West");

    // Vehicle ID tracker
    int vehicleID = 1;

    // Input vehicle count per lane
    int n, s, e, w;
    cout << "Enter number of vehicles in North lane: ";
    cin >> n;
    north.addVehicles(n, vehicleID);

    cout << "Enter number of vehicles in South lane: ";
    cin >> s;
    south.addVehicles(s, vehicleID);

    cout << "Enter number of vehicles in East lane: ";
    cin >> e;
    east.addVehicles(e, vehicleID);

    cout << "Enter number of vehicles in West lane: ";
    cin >> w;
    west.addVehicles(w, vehicleID);

    // Process each lane in fixed order
    north.processLane();
    south.processLane();
    east.processLane();
    west.processLane();

    cout << "\n✅ All lanes processed. Simulation complete.\n";
    return 0;
}
