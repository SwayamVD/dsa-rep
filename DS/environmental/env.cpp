#include <iostream>
using namespace std;

struct EnvData {
    float temp;
    float hum;
    float poll;
};

int main() {
    EnvData data[100];
    int n;
    
    // Input data
    cout << "Enter number of records (max 100): ";
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "Record " << i+1 << " (temp hum poll): ";
        cin >> data[i].temp >> data[i].hum >> data[i].poll;
    }
    
    // Calculate stats
    float maxTemp = data[0].temp, minTemp = data[0].temp;
    float avgTemp = 0, avgHum = 0, avgPoll = 0;
    
    for(int i = 0; i < n; i++) {
        if(data[i].temp > maxTemp) maxTemp = data[i].temp;
        if(data[i].temp < minTemp) minTemp = data[i].temp;
        
        avgTemp += data[i].temp;
        avgHum += data[i].hum;
        avgPoll += data[i].poll;
    }
    
    // Display results
    cout << "\nTemperature - High: " << maxTemp << " Low: " << minTemp;
    cout << "\nAverages - Temp: " << avgTemp/n << " Hum: " << avgHum/n << " Poll: " << avgPoll/n;
    
    // Simple safety check
    cout << "\n\nSafety Alerts:\n";
    for(int i = 0; i < n; i++) {
        if(data[i].poll > 100) {
            cout << "Record " << i+1 << ": Bad air (poll=" << data[i].poll << ")\n";
        }
    }
    
    return 0;
}