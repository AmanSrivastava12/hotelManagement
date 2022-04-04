#include<iostream>
#include<string.h>
#include<conio.h>

#define max 100
using namespace std;

//Class Customer
class Customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};


class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;

class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};

//Global Declarations
class Room rooms[max];
int count=0;

Room Room::addRoom(int rno)
{
class Room room;
room.roomNumber=rno;
cout<<"\nType AC/Non-AC (A/N) : ";
cin>>room.ac;
cout<<"\nType Comfort (S/N) : ";
cin>>room.type;
cout<<"\nType Size (B/S) : ";
cin>>room.stype;
cout<<"\nDaily Rent : ";
cin>>room.rent;
room.status=0;

cout<<"\n Room Added Successfully!";
getch();
return room;
}

void Room::searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
cout<<"Room Details\n";
if(rooms[i].status==1)
{
cout<<"\nRoom is Reserved";
}
else
{
cout<<"\nRoom is available";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\nRoom not found";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
cout<<"\nRoom Number: \t"<<tempRoom.roomNumber;
cout<<"\nType AC/Non-AC (A/N) "<<tempRoom.ac;
cout<<"\nType Comfort (S/N) "<<tempRoom.type;
cout<<"\nType Size (B/S) "<<tempRoom.stype;
cout<<"\nRent: "<<tempRoom.rent;
}

//hotel management class
class HotelMgnt:protected Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

if(count==0){
	cout<<"\n No Guest in Hotel !!";
}	
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<"\n Customer First Name : "<<rooms[i].cust.name;
cout<<"\n Room Number : "<<rooms[i].roomNumber;
cout<<"\n Address (only city) : "<<rooms[i].cust.address;
cout<<"\n Phone : "<<rooms[i].cust.phone;
cout<<"\n---------------------------------------";	
}	
}
getch();
}