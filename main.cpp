#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
using namespace std;

class guest
{
    public:
    string name, CNIC, roomNum,guestEmail, contactNo;
    guest *next;
    guest(const string name,string CNIC, string roomNum, string guestEmail,string contactNo, guest* p=NULL){
        this->name=name;
        this->CNIC=CNIC;
        this->roomNum=roomNum;
        this->guestEmail=guestEmail;
        this->contactNo=contactNo;
        this->next=p;
    }
};

class Room
{
    private:
    guest *head;
    string name, CNIC, roomNum,guestEmail, contactNo;

    public:
    Room()
	{
        head=NULL;
    }

    ~Room()
	{
        guest* p=head,*q=head;
        while(p!=NULL){
            q=head->next;
            delete p;
            p=q;
        }
    }

    void checknameinput()
    {
    	 int a=0;
         cout<<"Enter guest's name: "<<endl;
           getline(cin  >> ws,name);
           name.erase(remove(name.begin(), name.end(), ' '), name.end());
		    while ( a==0) {

                for (int i = 0; i <name.length(); i++) {

                    if(isalpha(name[i])) {
                        a=1;
                    }
                        else { cout << "Please enter a valid name: " <<endl; getline(cin  >> ws,name);
                               name.erase(remove(name.begin(), name.end(), ' '), name.end());
                        }
                }
            }
        }
    void checkroomNuminput()
{
    int c=0;
    cout<<"Enter guest's room number: "<<endl;
    cin  >> roomNum;
    while ( c==0) {
        for (int i = 0; i <roomNum.length(); i++) {
            if(isdigit(roomNum[i])) {
                c=1;
            }
            else {
                cout << "Please enter a valid room number: " <<endl;
                cin  >> roomNum;
            }
        }
        guest* p = head;
        while (p != NULL) {
            if (p->roomNum == roomNum) {
                cout << "This room number is already in use. Please enter a different room number: " <<endl;
                cin  >> roomNum;
                c = 0;
                break;
            }
            p = p->next;
        }
    }
}
    void checkCNIC() {
        cout << "Enter guest's 13-digit CNIC number e.g. 1234567891234: " << endl;
        cin >> CNIC;
        int flag=0;
        while(flag==0){
            if(CNIC.length()==13)
                break;
                else {
                    cout<<"Please enter a valid CNIC Number of 13 digits without dash: "<<endl;
                    cin>>contactNo;
                }
        }
    }

    void checkcontactNo(){
    	cout<<"Enter guest's contact number (e.g. 03331234567): "<<endl;
        cin>>contactNo;
        int flag=0;
        while(flag==0){
            if(contactNo.length()==11)
                break;
                else {
                    cout<<"Please enter a valid contact number of 11 digits: "<<endl;
                    cin>>contactNo;
                }
        }
	}

    bool validateEmail(string email) {
        // check for presence of @ and .
        if (email.find('@') == string::npos || email.find('.') == string::npos) {
            return false;
        }
        // check for proper domain
        if (email.substr(email.find('.')) != ".com" && email.substr(email.find('.')) != ".net" && email.substr(email.find('.')) != ".edu") {
            return false;
        }
        return true;
    }
    void checkguestEmail() {
        cout << "Enter guest's email address: " << endl;
        cin >> guestEmail;
        while (1) {
            if (validateEmail(guestEmail)) {
                break;
            } else {
                cout << "Please enter a valid email address (e.g. example@gmail.com): " << endl;
                cin >> guestEmail;
            }
        }
    }
	void allocate()
    {
        fstream file;
        file.open("guests.txt",ios::app);

        checknameinput();
        file<<"\nName: "<<name;

        checkroomNuminput();
        file<<"\nRoom no.: "<<roomNum;

        checkCNIC();
        file<<"\nID: "<<CNIC;

        checkcontactNo();
        file<<"\nContact no.: "<<contactNo;

        checkguestEmail();
        file<<"\nEmail: "<<guestEmail;

        file.close();
        if(head==NULL)
		{
            head=new guest(name, CNIC, roomNum, guestEmail, contactNo);
            cout<<"Room allocation confirmed!!";
            return;

		    }
			 else
			  {
            guest *p=head;
                p->next=new guest(name,CNIC, roomNum, guestEmail, contactNo, p->next);
                cout<<"Room allocation confirmed!!";
                return;
            }
    }

    void cancel()
	{
        checknameinput();
        int c=0;
        cout<<"Enter guest's room number: "<<endl;
        cin  >> roomNum;
        while ( c==0) {
            for (int i = 0; i <roomNum.length(); i++) {
                if(isdigit(roomNum[i])) {
                    c=1;
                }
                else {
                    cout << "Please enter a valid room number: " <<endl;
                    cin  >> roomNum;
                }
            }
        }
        if (head==NULL) {
            cout << "The guest does not exist\n";
            return;
        }
        guest *p=head,*q=head;
        if((p->name==name)&&(p->roomNum==roomNum)){
            head=head->next;
            cout<<"Room booking has been cancelled";
            delete p;
            return;
        }

	    p=head->next;

	    while(p)
		{
            if((p->name==name)&&(p->roomNum==roomNum))
			{
            q->next=p->next;
            delete p;
            cout<<"Room booking has been cancelled";
            return;

		    }
			else
			{
                q=p;
                p=p->next;
            }
        }
        cout<<"No such guest in our list!";
        return;
    }

    void check()
	{

        checknameinput();
        guest* p=head;
        while(p!=NULL)
		{
            if(p->name==name)
			{
                cout<<"\nName: "<< p-> name
                <<"\nguest ID: "<<p-> CNIC
                <<"\nRoom Number: "<<p-> roomNum
                <<"\nEmail address: "<<p-> guestEmail
                <<"\nContact number: "<<p-> contactNo;
                return;
            }

			else
                p=p->next;
        }

        cout<<"No such guest in our list!";
        return;

	}

//Mantaining the Alphatized linked list of names.
void sortList()
 {
    guest* temp = head;
    guest* current = temp;
    guest* nextguest = temp->next;

    for (; temp->next; temp = temp->next)
	{
        current = temp;
        for (nextguest = temp->next; nextguest; nextguest = nextguest->next)
		 {
            if (current->name > nextguest->name)
			{
                current = nextguest;
            }
        }

		if (current != temp)
		{
            swap(temp->name, current->name);
            swap(temp->CNIC, current->CNIC);
            swap(temp->roomNum, current->roomNum);
            swap(temp->guestEmail, current->guestEmail);
            swap(temp->contactNo, current->contactNo);
        }
    }

}


    void display()
	{
	    if (head==NULL) {
                cout << "There are no guests in the list\n";
            return;
	    }
        guest* p=head;
        sortList();
        int num=0;
        while(p!=NULL)
		{   num++;
            cout << "DATA OF guest " << num << endl;
            cout<<"Name: "<< p-> name
            <<"\nCNIC: "<<p-> CNIC
            <<"\nRoom Number: "<<p-> roomNum
            <<"\nEmail address: "<<p-> guestEmail
            <<"\nContact number: "<<p-> contactNo;
            cout << endl << endl;
            p=p->next;
        }

    }


};

int main()
  {
system("color 04");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // set the text color to green
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    Room r1;
    cout<<"*******************************************************************************"<<endl;
    cout<<"                     Bed & Breakfast Room Reservation System                   "<<endl;
    cout<<"*******************************************************************************"<<endl;
    cout<<"\t\t\t\tWELCOME ADMIN\n";
    while(true){
        cout<<"\n\n\t\tMENU";
        cout<<"\n\n\t1. Book a New Room"<<endl;
        cout<<"\t2. Cancel Room Booking"<<endl;
        cout<<"\t3. Check Room Number"<<endl;
        cout<<"\t4. Display all Guests' Data"<<endl;
        cout<<"\t5. Quit"<<endl;
        cout<<"\n---------------------------------"<<endl;
        cout<<"Enter your choice from the menu: ";
        char option;
        cin>>option;
        cout<<"------------------------------------"<<endl;
        switch(option){
            case '1':
                r1.allocate();
                break;
            case '2':
                r1.cancel();
                break;
            case '3':
                r1.check();
                break;
            case '4':
                r1.display();
                Sleep(2000);
                break;
            case '5':
                return 0;
            default:
                cout<<"No such choice!"<<endl;
                break;
        }
    }
    return 0;
}
