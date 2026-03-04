#include <iostream>

using namespace std;

// variabel
class RobotPemadam {
private:
    int jarak;       
    string status;  

public:
    
    void inputSensor(int nilai) {
        jarak = nilai;
    }

    // percabangan
    void prosesLogika() {
        if (jarak > 20) {
            status = "Maju Mencari Api";
        } else if (jarak <= 20 && jarak > 5) {
            status = "UDAH DEKET NIH BRAY";
        } else { // jarak <= 5
            status = "Posisi Tepat! gas semprot kali ya!";
        }
    }

    // output
    void cetakStatus() const {
        cout << "[Sensor: " << jarak << " cm] -> Action: " << status << endl;
    }
};


int main() {
    // variabel
    RobotPemadam robot;
    int input;

    cout << "Program Robot Pemadam - masukkan angka sensor (67 untuk keluar)" << endl;

    // percabangan
    while (true) {
        cout << "Masukkan jarak sensor: ";
        if (!(cin >> input)) {
            // jika input tidak valid, keluarkan dan hentikan
            cout << "Masukan tidak valid, keluar." << endl;
            break;
        }

        if (input == 67) {
            cout << "Angka 67 diterima, program berhenti." << endl;
            break;
        }

        robot.inputSensor(input);
        robot.prosesLogika();
        robot.cetakStatus();
    }

    return 0;
}

