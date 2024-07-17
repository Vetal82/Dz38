#include <iostream>
#include <set>
#include <string>
#include <ctime>

using namespace std;

class TicketRequest {
private:
    static int counter;
    int id;
    string destination;
    string passengerName;
    string departureDate;

public:
    TicketRequest(const string& destination, const string& passengerName, const string& departureDate)
        : id(counter++), destination(destination), passengerName(passengerName), departureDate(departureDate) {}

    int getId() const {
        return id;
    }

    string getDestination() const {
        return destination;
    }

    string getPassengerName() const {
        return passengerName;
    }

    string getDepartureDate() const {
        return departureDate;
    }

    bool operator<(const TicketRequest& other) const {
        if (destination != other.destination) {
            return destination < other.destination;
        }
        else {
            return departureDate < other.departureDate;
        }
    }
};

int TicketRequest::counter = 0;

int main() {
    set<TicketRequest> requests;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add ticket request" << endl;
        cout << "2. Remove ticket request" << endl;
        cout << "3. Print requests by destination" << endl;
        cout << "4. Count requests by date range and destination" << endl;
        cout << "5. Print all requests" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string destination, passengerName, departureDate;
            cout << "Enter destination: ";
            cin >> destination;
            cout << "Enter passenger name: ";
            cin >> passengerName;
            cout << "Enter departure date: ";
            cin >> departureDate;
            requests.insert(TicketRequest(destination, passengerName, departureDate));
            break;
        }
        case 2: {
            int id;
            cout << "Enter request ID to remove: ";
            cin >> id;
            for (auto it = requests.begin(); it != requests.end(); ++it) {
                if (it->getId() == id) {
                    requests.erase(it);
                    cout << "Request removed." << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            string destination;
            cout << "Enter destination: ";
            cin >> destination;
            for (auto it = requests.begin(); it != requests.end(); ++it) {
                if (it->getDestination() == destination) {
                    cout << "Request ID: " << it->getId() << endl;
                    cout << "Passenger name: " << it->getPassengerName() << endl;
                    cout << "Departure date: " << it->getDepartureDate() << endl;
                    cout << endl;
                }
            }
            break;
        }
        case 4: {
            string destination;
            string startDate, endDate;
            cout << "Enter destination: ";
            cin >> destination;
            cout << "Enter start date: ";
            cin >> startDate;
            cout << "Enter end date: ";
            cin >> endDate;
            int count = 0;
            for (auto it = requests.begin(); it != requests.end(); ++it) {
                if (it->getDestination() == destination && it->getDepartureDate() >= startDate && it->getDepartureDate() <= endDate) {
                    count++;
                }
            }
            cout << "Number of requests: " << count << endl;
            break;
        }
        case 5: {
            for (auto it = requests.begin(); it != requests.end(); ++it) {
                cout << "Request ID: " << it->getId() << endl;
                cout << "Destination: " << it->getDestination() << endl;
                cout << "Passenger name: " << it->getPassengerName() << endl;
                cout << "Departure date: " << it->getDepartureDate() << endl;
                cout << endl;
            }
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}