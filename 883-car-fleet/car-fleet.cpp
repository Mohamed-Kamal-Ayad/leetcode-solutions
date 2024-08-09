class Solution {
public:
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, double>> cars;
    
    // Calculate the time needed for each car to reach the target
    for (int i = 0; i < position.size(); i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }
    
    // Sort cars by their starting position in descending order
    sort(cars.begin(), cars.end(), greater<pair<int, double>>());
    
    int res = 0;
    double currMaxTime = 0;
    
    // Traverse the cars from the nearest to the farthest
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].second > currMaxTime) {
            res++; // New fleet
            currMaxTime = cars[i].second; // Update the max time of the leading car in the current fleet
        }
    }
    
    return res;
}
};