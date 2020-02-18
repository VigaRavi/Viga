#include<iostream>
#include <sstream>     
#include<string>
#include<fstream>

using namespace std;



struct fseat{
	string row;
	string clas;
	string ar;
};
class flight{
	public:                                                                        
		string flightNo;
		string dateTime;
		string departure;
		string arrival;
		int noBuclz; 
		int noEclz; 
		int rows;
		fseat st[100];  
			
};


flight fArr[1000];
int Fcount;

int GetNoofFlight();
void ViewDisplay();
void FlightSearching();
void SeatsAvailability();
void SeatBookings();
void Exit();


int main()
{
	int choice;
	Fcount=GetNoofFlight();
	string line;
		ifstream file("flights.txt");
	int seatsnum=0;	
		fseat st[100];	
	
		int i;
			for(i=0;i<Fcount;i++)
			{
				string line;
				int N=0;
				
					while(!file.eof()){
     getline(file,line);
		
	if(!line.empty())
	{
		
	if(N==0){
		fArr[i].flightNo=line;
	
		N++;
	}
	else 
	if(N==1){
	   fArr[i].dateTime=line;
	
	   N++;
	}
	else
	 if(N==2){
		fArr[i].arrival=line;
	
		N++;
	}
	else
	 if (N==3){
		fArr[i].departure=line;
	
		N++;
		
	}
	else 
	if(N>=4){
			
	
		
		istringstream ss(line);
		ss >> fArr[i].st[seatsnum].row >> fArr[i].st[seatsnum].clas>> fArr[i].st[seatsnum].ar;
		
	
		N++;
		seatsnum++;
	
	}
		}else
		{
			N=0;
			i++;
			seatsnum=0;
		}
			
	}
	}
	cout<<"___________________Welcome to VIRGIN Airline______________"<<endl;
int check = 1;
    while(check){
    	
    	cout<<endl<<"..........Your Options........"<<endl<<endl;
		cout<<endl<<"1. Display available flights";
		cout<<endl<<"2. View flight";
		cout<<endl<<"3. Seat availability";
		cout<<endl<<"4. Seat booking";
		cout<<endl<<"5. Exit"<<endl<<endl;
		cout<<"___________________________________________"<<endl;
		cout<<endl<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 1: 
				ViewDisplay();
				break;
			case 2:
				FlightSearching();
				break;
			case 3:
			SeatsAvailability();
				break;
			case 4:
			SeatBookings();
				break;
			case 5:
				check = 0;
				
				Exit();
				break;
			default: 
				cout<<endl<<"False Choice ";
				
				break;
		}
	}
	
	return 0;
}

int GetNoofFlight()
{


		ifstream file("flights.txt");
		string ch;
		int i=0;
		int Fcount=0;
		while(getline(file,ch)!=NULL)
			if(i==0){
				if(!ch.empty()){
					Fcount++;
					i++;
				}
			}
			else{
				if(ch.empty()){
					i++;
					getline(file,ch);
					if(!ch.empty()){
						Fcount++;
						i++;
					}
					else{
						i++;
					}
					
				}
				else{
					i++;
				}
			}
		
		return Fcount;
}


void ViewDisplay()
{
		int n,j;
	for(n=0;n<Fcount;n++){
		
		cout<<endl<<"Flight number: "<<fArr[n].flightNo;
		cout<<endl<<"Departure date & time: "<<fArr[n].dateTime;
		cout<<endl<<"Arrival airport code: "<<fArr[n].arrival;
		cout<<endl<<"Departure airport code: "<<fArr[n].departure;
		
			fArr[n].noEclz = 0;
		fArr[n].noBuclz = 0;
		for(j=0;j<10;j++){
			if(fArr[n].st[j].clas == "B"){
				fArr[n].noBuclz = fArr[n].noBuclz + fArr[n].st[j].ar.length();
			}
			else{
				fArr[n].noEclz = fArr[n].noEclz + fArr[n].st[j].ar.length();
			}
		
		}
		cout<<endl<<"Available Economic class seats : "<<fArr[n].noEclz;
		cout<<endl<<"Available Business class seats : "<<fArr[n].noBuclz<<endl<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}
		cout<<endl<<"____________________________________________";
	}

	
	
	
	
	
	void FlightSearching()
	{
	string flightNo;
	cout<<endl<<"Enter the Flight no :";
	cin>>flightNo;
	int avail;
	int i;
	int n;
		for(i=0;i<Fcount;i++){
		if(flightNo == fArr[i].flightNo)
		{
			n = i;
			avail = 1;
			break;
		}
}
if(avail == 1){

		cout<<endl<<"Flight no: "<<fArr[i].flightNo;
		cout<<endl<<"Departure date and time: "<<fArr[i].dateTime;
		cout<<endl<<"Arrival airport code: "<<fArr[i].arrival;
		cout<<endl<<"Departure airport code: "<<fArr[i].departure;
		int avail;
			int j;
		int i;
		int n; 
		for(i=0;i<Fcount;i++){
			if(flightNo == fArr[i].flightNo){
				n = i;
				avail = 1;
				break;
			}
		}
		fArr[n].noEclz = 0;
		fArr[n].noBuclz = 0;
		for(j=0;j<10;j++){
			if(fArr[n].st[j].clas == "B"){
				fArr[n].noBuclz = fArr[n].noBuclz + fArr[n].st[j].ar.length();
			}
			else{
				fArr[n].noEclz = fArr[n].noEclz + fArr[n].st[j].ar.length();
			}
		
		}
	
		
		cout<<endl<<"Available Business class seats  : "<<fArr[n].noBuclz;
			for(j=0;j<10;j++)
			{
				if(fArr[n].st[j].clas== "B")
				{
					cout<<endl<<fArr[n].st[j].row<<"  "<<" B"<<" "<<fArr[n].st[j].ar;
				}
			}
			cout<<endl<<"Available Economic class seats  : "<<fArr[n].noEclz;
			for(j=0;j<10;j++)
			{
				if(fArr[n].st[j].clas == "E"){
					cout<<endl<<fArr[n].st[j].row<<"  "<<"E"<<" "<<fArr[n].st[j].ar;
				}
	}
}
	else{
		cout<<endl<<"OOps! Sorry, flight is not available"; 
	}
		
}




void SeatsAvailability()
{
		string flightNo;
	cout<<endl<<"Choose your Flight no  :";
	cin>>flightNo;
	int noOfSeats;
	cout<<endl<<"Enter the no of seats you required :";
	cin>>noOfSeats;
	int avail;
	int noOfAvailableSeats;
	
		int j;
	int i;
	int n; 
	for(i=0;i<Fcount;i++){
		if(flightNo == fArr[i].flightNo)
		{
			n = i;
			avail = 1;
			break;
		}
	}
	
		fArr[n].noEclz = 0;
	fArr[n].noBuclz = 0;
	for(j=0;j<10;j++)
	{
		if(fArr[n].st[j].clas == "B"){
			fArr[n].noBuclz = fArr[n].noBuclz + fArr[n].st[j].ar.length();
		}
		else{
			fArr[n].noEclz = fArr[n].noEclz + fArr[n].st[j].ar.length();
		}
		
	}
		noOfAvailableSeats = fArr[n].noEclz + fArr[n].noBuclz;
	if(avail == 1){
		if(noOfSeats > noOfAvailableSeats){
			cout<<endl<<"Oops! only Available, ";
			cout<<endl<<"Business class : ";
			cout<<fArr[n].noBuclz;
			cout<<endl<<"Economic class : ";
			cout<<fArr[n].noEclz;
		}
		else{
			cout<<endl<<"It's available";
			cout<<endl<<"Available Business class seats  : "<<fArr[n].noBuclz;
			for(j=0;j<10;j++)
			{
				if(fArr[n].st[j].clas== "B")
				{
					cout<<endl<<fArr[n].st[j].row<<"  "<<"B"<<" "<<fArr[n].st[j].ar;
				}
			}
			cout<<endl<<"Available Economic class seats  : "<<fArr[n].noEclz;
			for(j=0;j<10;j++)
			{
				if(fArr[n].st[j].clas == "E"){
					cout<<endl<<fArr[n].st[j].row<<"  "<<"E"<<" "<<fArr[n].st[j].ar;
				}
			}
		}
	}
	else{
		cout<<endl<<"Sorry, that flight is not available..."; 
	}
	
}

void SeatBookings()
{
	string flightNo;
	string row;
	string clmn;
	cout<<endl<<"Enter the Flight No:";
	cin>>flightNo;
	int avail;
	int booked;
	int i;
	int n; 
	int k;
	for(i=0;i<Fcount;i++)
	{ 
	 
		if(flightNo == fArr[i].flightNo){
			n = i;
			avail = 1;
			break;
		}
	}
		if(avail== 1){
		cout<<endl<<"_____ The seat location____";
		cout<<endl<<"Enter the row number of seat  :";
		cin>>row;
		cout<<endl<<"Enter the column letter of seat  :";
		cin>>clmn;
		for(k=0;k<=60;k++){
			
			if(fArr[n].st[k].row==row){
				if(fArr[n].st[k].ar.find(clmn)!=string::npos){
					fArr[n].st[k].ar.erase(fArr[n].st[k].ar.find(clmn),1);
					booked = 1;
					break;
				}else{
					booked = 0;
				}
				
			}
			
		}
		
		if(booked == 1){
			cout<<endl<<"The seat is Booked";
			cout<<endl<<"___Thank you____";
		}else{
			cout<<endl<<"Sorry, That seat is not in present.....";
		}
			
	}else{
		cout<<endl<<"Sorry, that flight is not available...";
	}
		}	



void Exit()
{
	ofstream MFile("flights.dat");
	for(int i=0;i<Fcount;i++){
		int k=0;
		MFile<<fArr[i].flightNo<<endl;
		MFile<<fArr[i].dateTime<<endl;
		MFile<<fArr[i].departure<<endl;
		MFile<<fArr[i].arrival<<endl;
		while(1){
			if(fArr[i].st[k].row==""){
				break;
			}
			else{
				MFile<<fArr[i].st[k].row<<" "<<fArr[i].st[k].clas<<" "<<fArr[i].st[k].ar<<endl;
			}
			
			k++;
		}
		MFile<<endl;
	}MFile.close();
	exit(0);
}
	
	
	
	
	
	
	
	

