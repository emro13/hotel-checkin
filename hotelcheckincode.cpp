#include <iostream>
#include <vector>

using namespace std;

// Room class
class Room {
private:
    int roomNumber;
    bool isBooked;
    bool isClean;
public:
    Room(int number) 
    {
        roomNumber = number;
        isBooked = false;
        isClean = true;
    }
    int getRoomNumber() 
    {
        return roomNumber;
    }
    bool getIsBooked() 
    {
        return isBooked;
    }
    bool getIsClean()
    {
        return isClean;
    }
    void setBooked(bool booked) 
    {
        isBooked = booked;
    }
    void setClean(bool clean) 
    {
        isClean = clean;
    }
};

// Hotel class
class Hotel 
{
private:
    string name;
    vector<Room> rooms;
public:
    Hotel(string n) 
    {
        name = n;
        for (int i = 0; i < 10; i++) 
        {
            Room room(i+1);
            rooms.push_back(room);
        }
    }
    void bookRoom(int roomNumber) {
        for (int i = 0; i < rooms.size(); i++) 
        {
            if (rooms[i].getRoomNumber() == roomNumber) 
            {
                if (rooms[i].getIsBooked())
                {
                    cout << "Sorry, Room " << roomNumber << " is already booked.\n";
                }
                else 
                {
                    rooms[i].setBooked(true);
                    cout << "Thank you, Room " << roomNumber << " has been successfully booked.\n";
                }
                return;
            }
        }
        cout << "Invalid room number.\n";
    }
    void cleanRoom(int roomNumber) {
        for (int i = 0; i < rooms.size(); i++) 
        {
            if (rooms[i].getRoomNumber() == roomNumber) 
            {
                if (rooms[i].getIsClean()) 
                {
                    cout << "Room " << roomNumber << " is already clean.\n";
                }
                else 
                {
                    rooms[i].setClean(true);
                    cout << "Room " << roomNumber << " has been cleaned.\n";
                }
                return;
            }
        }
        cout << "Invalid room number.\n";
    }
    void dirtyRoom(int roomNumber) {
        for (int i = 0; i < rooms.size(); i++) 
        {
            if (rooms[i].getRoomNumber() == roomNumber) 
            {
                if (!rooms[i].getIsClean()) 
                {
                    cout << "Room " << roomNumber << " is already dirty.\n";
                }
                else 
                {
                    rooms[i].setClean(false);
                    cout << "Room " << roomNumber << " has been marked as dirty.\n";
                }
                return;
            }
        }
        cout << "Invalid room number.\n";
    }
    void printRooms() 
    {
        cout << "Rooms at " << name << ":\n";
        for (int i = 0; i < rooms.size(); i++) 
        {
            cout << "Room " << rooms[i].getRoomNumber() << ": ";
            if (rooms[i].getIsBooked()) 
            {
                cout << "Booked";
            }
            else 
            {
                cout << "Available";
            }
            cout << ", ";
            if (rooms[i].getIsClean()) 
            {
                cout << "Clean";
            }
            else 
            {
                cout << "Dirty";
            }
            cout << "\n";
        }
    }
    int checkIn() 
    {
        for (int i = 0; i < rooms.size(); i++) 
        {
            if (!rooms[i].getIsBooked()) 
            {
               
                rooms[i].setBooked(true);
                rooms[i].setClean(false);
                cout << "You have checked into Room " << rooms[i].getRoomNumber() << ".\n";
                return rooms[i].getRoomNumber();
            }
        }
        cout << "Sorry, there are no available rooms.\n";
        return -1;
    }
    void checkOut(int roomNumber) {
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i].getRoomNumber() == roomNumber) {
                if (!rooms[i].getIsBooked()) {
                    cout << "Room " << roomNumber << " is not currently booked.\n";
                }
                else {
                    rooms[i].setBooked(false);
                    cout << "You have checked out of Room " << roomNumber << ".\n";
                }
                return;
            }
        }
        cout << "Invalid room number.\n";
    }
};

int main() {
    Hotel hotel("My Hotel");
    int choice;
    int roomNumber;
    while (true) {
        cout << "Please select the number designated to the service you are requesting. 1. To Book a room (1-10)\n2. Check in\n3. Check out\n4. Mark room as clean\n5. Mark room as dirty\n6. View rooms\n7. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                hotel.bookRoom(roomNumber);
                break;
            case 2:
                roomNumber = hotel.checkIn();
                if (roomNumber != -1) {
                    cout << "Your room number is " << roomNumber << ".\n";
                }
                break;
            case 3:
                cout << "Enter room number to check out: ";
                cin >> roomNumber;
                hotel.checkOut(roomNumber);
                break;
            case 4:
                cout << "Enter room number to mark as clean: ";
                cin >> roomNumber;
                hotel.cleanRoom(roomNumber);
                break;
            case 5:
                cout << "Enter room number to mark as dirty: ";
                cin >> roomNumber;
                hotel.dirtyRoom(roomNumber);
                break;
            case 6:
                hotel.printRooms();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
    return 0;
}
