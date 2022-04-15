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
cout<<"\nEnter Conditioning System\n(A - AC Room, N - Non-AC Room) : ";
cin>>room.ac;
cout<<"\nEnter Service Type\n(W - World Class Service, B - Budget Service) : ";
cin>>room.type;
cout<<"\nEnter Size\n(L - Luxury Room, S - Standard Room) : ";
cin>>room.stype;
cout<<"\nDaily Rent : ";
cin>>room.rent;
room.status=0;
cout<<"\nRoom Added Successfully!";
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
if(rooms[i].status==1)
{
cout<<"\nRoom is reserved.";
}
else
{
cout<<"\nRoom is available.";
}
cout<<"\nRoom Details are :\n";
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\nRoom could not be found.";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
cout<<"\nRoom Number : "<<tempRoom.roomNumber;
if(tempRoom.ac == 'A')
cout<<"\nAir Conditioned Room";
else
cout<<"\nNon-air Conditioned Room";
if(tempRoom.type == 'W')
cout<<"\nWorld Class Room Service";
else
cout<<"\nBudget Room Service";
if(tempRoom.stype == 'L')
cout<<"\nLuxury Room";
else
cout<<"\nStandard Room";
cout<<"\nRent per day : "<<tempRoom.rent;
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

if(count==0)
{
	cout<<"\n No Guest present in Hotel!";
}	
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<"\n Customer First Name : "<<rooms[i].cust.name;
cout<<"\n Room Number : "<<rooms[i].roomNumber;
cout<<"\n Address (only city) : "<<rooms[i].cust.address;
cout<<"\n Phone : "<<rooms[i].cust.phone;
cout<<"\n";	
}	
}
getch();
}

void HotelMgnt::checkIn()
{
int i,found=0,rno;

class Room room;
cout<<"\nEnter Room Number : ";
cin>>rno;
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
if(rooms[i].status==1)
{
cout<<"\nRoom is already booked.";
getch();
return;
}
cout<<"\nEnter Booking ID : ";
cin>>rooms[i].cust.booking_id;
cout<<"\nEnter Customer Name\n(only first name required) : ";
cin>>rooms[i].cust.name;
cout<<"\nEnter Address\n(only city required) : ";
cin>>rooms[i].cust.address;
cout<<"\nEnter Phone Number : ";
cin>>rooms[i].cust.phone;
cout<<"\nEnter Booking Date : ";
cin>>rooms[i].cust.from_date;
cout<<"\nEnter Checkout Date : ";
cin>>rooms[i].cust.to_date;
cout<<"\nEnter Advance Payment : ";
cin>>rooms[i].cust.payment_advance;
rooms[i].status=1;
cout<<"\nCustomer checked-in successfully.";
getch();
}
else
{
cout<<"\nRoom Number "<<rno<<" is not present.\n";
getch();
}
}

//hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\n\nPress enter for next room";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nAll rooms are reserved";
getch();
}
}

//hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
cout<<"\nCustomer Name: "<<rooms[i].cust.name;
cout<<"\nRoom Number: "<<rooms[i].roomNumber;
cout<<"\n\nPress enter for the next record";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nPerson not found.";
getch();
}
}

//hotel management generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//rno = rooms[i].roomNumber;
found=1;
//getch();
break;
}
}
if(found==1)
{
cout<<"\nEnter Number of Days:\t";
cin>>days;
billAmount=days * rooms[i].rent;
cout<<"\n\tHere are the checkout details of the customer :\n";
cout<<"\nCustomer Name : "<<rooms[i].cust.name;
cout<<"\nRoom Number : "<<rooms[i].roomNumber;
cout<<"\nAddress : "<<rooms[i].cust.address;
cout<<"\nPhone : "<<rooms[i].cust.phone;
cout<<"\nTotal Amount Due : "<<billAmount<<" /";
cout<<"\nAdvance Paid : "<<rooms[i].cust.payment_advance<<" /";
cout<<"\nTotal Payable: "<<billAmount-rooms[i].cust.payment_advance<<"/ only";
rooms[i].status=0;
}
getch();
}

//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
cout<<"Enter\n1. Add a Room";
cout<<"\n2. Search a Room";
cout<<"\n3. Return back to Main Menu";
cout<<"\n\nEnter your choice : ";
cin>>opt;
switch(opt)
{
case 1:
cout<<"\nEnter Room Number: ";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout<<"\nRoom Number is already present. Please enter a unique number";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\nEnter Room Number: ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
break;
default:
cout<<"\nPlease enter a correct choice";
break;
}
}while(opt!=3);
}

using namespace std;
int main()
{
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];
system("cls");
do
{
system("cls");
cout<<"Hotel Management System\n";
cout<<"\n1. Manage Rooms";
cout<<"\n2. Room check-in";
cout<<"\n3. Rooms available";
cout<<"\n4. Search a specific Customer";
cout<<"\n5. Room check-out";
cout<<"\n6. Guest Summary Report";
cout<<"\n7. Exit";
cout<<"\n\nEnter Option: ";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\nPlease add the rooms first!";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\nRooms are not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"Enter Customer Name: ";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\nRooms are not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"Enter Room Number : ";
cin>>rno;
hm.checkOut(rno);
}
break;
case 6:
hm.guestSummaryReport();	
break;
case 7:
cout<<"\nTHANK YOU!";
break;
default:
cout<<"\nPlease enter a correct option";
break;
}
}while(opt!=7);
getch();
}

