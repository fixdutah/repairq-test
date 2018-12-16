//Main driver file for 'repairQueue' project
#include <Header.h>


class Repair{


	//Data Members
	private:
		string device;
		string customer;
		string employee;
		string doneByDate;
		string doneByTime;
		string doneBy[2]{doneByDate, doneByTime};
		string quote;
	public:
	//Parameterized constructor
		Repair(string _device, string _customer, string _employee, string _doneByDate, string _doneByTime, string _quote) :
			device(_device), customer(_customer), employee(_employee), doneByDate(_doneByDate), doneByTime(_doneByTime), quote(_quote) {}
		string * getDoneBy(){
			return doneBy;
		}
		void printRepair(){
			cout << setw(15) << device << " | " << setw(15) << customer << " | " << setw(15) << employee << " | " << setw(7) << doneByTime << " " << setw(5) << doneByDate << " | " << setw(10) << "$" << quote << endl;
		}
		Repair(){
		
		}

};


void printList(vector<Repair> rep){
	int choice, repNum;
	bool val;
	do{
		system("clear");
		cout << setw(25) << "CURRENT REPAIR QUEUE \n(Window must be fullscreen for proper list formatting)" << endl << endl;
		
		for(int i = 0; i < rep.size(); i++){
			cout << "#" << i+1 << " | ";
			rep[i].printRepair();
		}

		cout << endl << endl << endl << "Return to menu (0)  Reload List (1)  Show Details (2)" << endl;
		cin >> choice;
		switch(choice){				
			case 0:
				break;
			default:
				break;
			case 1:
				printList(rep);
				break;
			case 2:
				do{
					cout << "Repair #";
					cin >> repNum;
					if(!(repNum > rep.size() + 1) | !(repNum < 1)){
						val = true;
					}else{
						cin.ignore();
						cout << "Invalid Selection" << endl;
						val = false;
						repNum = 0;
					}

				}while(!val);
				if(val){
					cout << "Extra repair details to be added here later..." << endl;
					break;
				}
				break;

			}
	}while(choice != 0 && (choice == 1 | choice == 2));

}

int main(){

vector <Repair> repairList;
int choice;
string devName, customerName,employeeName,dayMonth,dueTime ,quoted;
Repair repA;

	cout << "Employee: ";
	getline(cin, employeeName);
	do{	
		system("clear");
		cout << "Employee: " << employeeName << endl;
		cout << "Exit(0)  List Repair(1)  Add Repair(2)  Remove Repair(3)  Change Employee(4)" << endl;
		cin >> choice;
		cin.ignore();
		switch(choice){
			case 1:
				printList(repairList);
				break;
			case 2:
				system("clear");
					cout << "Device: ";
					getline(cin, devName);

					//cin.ignore();
			
					cout << endl << "Customer: ";
					getline(cin, customerName);

					//cin.ignore();
			
					cout << endl << "Month/Day due: ";
				 	getline(cin,dayMonth);

					//cin.ignore();
			
					cout << endl << "Time due: ";
					getline(cin, dueTime);
					
					//cin.ignore();

					cout << endl << "Quote: ";
					getline(cin, quoted);

					//cin.ignore(); 

					repA = Repair(devName, customerName, employeeName, dayMonth, dueTime, quoted);
					repairList.push_back(repA);
					cin.ignore();
					cout << "Repair added..\nHit ENTER to continue.." << endl;
					if(cin.get() == '\n'){
						break;
					}
			case 3:
				system("clear");
				repairList.pop_back();
				break;
			case 0:
				break;
			case 4: 
				cout << "Employee: ";
				getline(cin,employeeName);
				break;
			/*default:
				system("clear");
				cout << "Error" << endl;
				break; */
		}
	} while (choice != 0 && (choice == 1 | choice == 2 | choice == 3 | choice == 4));

do {
	cout << "Press enter to continue.." << endl;
}while(cin.get() != '\n');
return 0;
}
