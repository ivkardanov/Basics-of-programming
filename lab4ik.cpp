#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <iostream>

using namespace std;

struct Hotel {
    string name;
    int stars;
    int roomCount;
    string amenities;
    string location;

    void display() const {
        cout << left << setw(20) << name
            << setw(8) << stars
            << setw(12) << roomCount
            << setw(30) << amenities
            << setw(20) << location << endl;
    }
};

void saveToFile(const vector<Hotel>& hotels, const string& filename) {
    ofstream file(filename);
    for (const auto& hotel : hotels) {
        file << hotel.name << ","
            << hotel.stars << ","
            << hotel.roomCount << ","
            << hotel.amenities << ","
            << hotel.location << endl;
    }
}

void loadFromFile(vector<Hotel>& hotels, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file " << filename << " for reading.\n";
        return;
    }
    Hotel hotel;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        getline(iss, hotel.name, ',');
        iss >> hotel.stars; iss.ignore();
        iss >> hotel.roomCount; iss.ignore();
        getline(iss, hotel.amenities, ',');
        getline(iss, hotel.location);
        hotels.push_back(hotel);
    }
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    while (input.empty()) {
        cout << " Cannot be empty. Please enter some text.\n";
        cout << prompt;
        getline(cin, input);
    }
    return input;
}

template <typename T>
T getNumericInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void printHotels(const std::vector<Hotel>& hotels);

void addHotel(vector<Hotel>& hotels) {
    Hotel hotel;
    hotel.name = getStringInput("Enter hotel name: ");
    hotel.stars = getNumericInput<int>("Enter star rating (1-5): ");
    hotel.roomCount = getNumericInput<int>("Enter room count: ");
    hotel.amenities = getStringInput("Enter amenities: ");
    hotel.location = getStringInput("Enter location: ");
    hotels.push_back(hotel);
    cout << "\n\n";  
}

void editHotel(vector<Hotel>& hotels) {
    if (hotels.empty()) {
        cout << "No hotels available to edit.\n";
        return;
    }
    printHotels(hotels);
    int index = getNumericInput<int>("Enter the index of the hotel to edit: ");
    if (index < 0 || index >= hotels.size()) {
        cout << "Invalid index!\n";
        return;
    }
    hotels[index].name = getStringInput("Enter new hotel name: ");
    hotels[index].stars = getNumericInput<int>("Enter new star rating (1-5): ");
    hotels[index].roomCount = getNumericInput<int>("Enter new room count: ");
    hotels[index].amenities = getStringInput("Enter new amenities: ");
    hotels[index].location = getStringInput("Enter new location: ");
    cout << "\n\n";  
}

void deleteHotel(vector<Hotel>& hotels) {
    if (hotels.empty()) {
        cout << "No hotels available to delete.\n";
        return;
    }
    printHotels(hotels);
    int index = getNumericInput<int>("Enter the index of the hotel to delete: ");
    if (index < 0 || index >= hotels.size()) {
        cout << "Invalid index!\n";
        return;
    }
    hotels.erase(hotels.begin() + index);
    cout << "Hotel deleted .\n\n";
}

void printHotels(const vector<Hotel>& hotels) {
    cout << left << setw(20) << "Name"
        << setw(8) << "Stars"
        << setw(12) << "Room Count "
        << setw(30) << "Services"
        << setw(20) << "Location" << endl;
    for (const auto& hotel : hotels) {
        hotel.display();
    }
    cout << "\n\n";  
}
void displayStatistics(const vector<Hotel>& hotels) {
    if (hotels.empty()) {
        cout << "No hotels available to analyze.\n";
        return;
    }
    double totalStars = 0, totalRooms = 0;
    for (const auto& hotel : hotels) {
        totalStars += hotel.stars;
        totalRooms += hotel.roomCount;
    }
    double averageStars = totalStars / hotels.size();
    double averageRooms = totalRooms / hotels.size();
    cout << " Star Rating: " << averageStars << "\n";
    cout << " Room Count: " << averageRooms << "\n\n";
}

void showMenu() {
    cout << "1. Add Hotel\n"
        << "2. Edit Hotel\n"
        << "3. Delete Hotel\n"
        << "4. Display All Hotels\n"
        << "5. Display Statistics\n"
        << "6. Save and Exit\n"
        << "Enter your choice: ";
}

bool processInput(vector<Hotel>& hotels) {
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choice) {
    case 1:
        addHotel(hotels);
        break;
    case 2:
        editHotel(hotels);
        break;
    case 3:
        deleteHotel(hotels);
        break;
    case 4:
        printHotels(hotels);
        break;
    case 5:
        displayStatistics(hotels);
        break;
    case 6:
        return false;  
    default:
        cout << "Erorr. Please try again.\n";
    }
    return true;
}

int main() {
    vector<Hotel> hotels;
    string filename = "hotels.txt";
    loadFromFile(hotels, filename);

    bool running = true;
    while (running) {
        showMenu();
        running = processInput(hotels);
    }

    saveToFile(hotels, filename);
    return 0;
}