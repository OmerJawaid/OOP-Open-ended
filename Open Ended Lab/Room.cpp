#include"Room.h"

void Room :: displayRooms_available()
{
    cout << "Rooms available: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << rooms_available[i] << endl;
    }
}

void Room::assignRoom(Course* course)
{
    bool check = false;
    do
    {
        cout << "Enter room number: ";
        cin >> roomNumber;
        check =  checkAvailabitiy(roomNumber);
        if (check == true)
        {
            course->setAssignedRoom(this);
        }
        else
        {
            cout << "Room not available" << endl;
        }
    } while (check == false);
}
bool Room::checkAvailabitiy(int room_number) 
{
    for (int i = 0; i < 3; i++)
    {
        if (rooms_available[i] == room_number)
        {
            return true;
        }
    }
    return false;
}	

void Room :: update_room(Course* course)
{
    int up_room;
   cout<<"Enter room number that you want to update = ";
   cin>>up_room;
   auto it = find (total_rooms.begin(),total_rooms.end(),up_room);
    if(it != total_rooms.end() )
    {
        course->setAssiignedRoom(up_room);
    }
    else
    {
        cout<<"Room Number dosen't exist . Try Again!" << endl;
    }
   
}
void Room::bookRoom() {}
