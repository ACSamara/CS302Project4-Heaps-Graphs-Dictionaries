#include "helpers.h"
#include "heap.h"
#include "dictionary.h"
#include "graph.h"

int main(){

    Job* jobs;
    int numJobs = readMaintenanceJobs("maintenance_jobs.csv", jobs);

    Heap<Job> maintenanceJobs;
    maintenanceJobs.buildMaxHeap(numJobs, jobs);

    Graph<string> campusMap = readMap("campus_map.csv");
    
    Dictionary<Building> buildingDirectory = readBuildings("buildings.csv");

    int choice;
    char yesNo = 'y';
    

    do{
        int in;
        string read, read2;
        Building tempB;
        Job tempJ;
        
        displayMainMenu();

        cin>>choice;
        while(choice>7||choice<1){
            cout<<"Invalid entry. Try again: ";
            cin>>choice;
        }
        
        switch(choice){
            case 1:
                cin.ignore(); 
                cout<<"Enter building name: ";
                getline(cin, read);
                if(!buildingDirectory.contains(read)){
                    cout<<"Building not found."<<endl;
                }
                else{
                    cout<<"===Building Information==="<<endl;
                    cout<<buildingDirectory[read];
                }
                break;
            case 2:
                cin.ignore();    

                cout<<"Enter building name: ";
                getline(cin, read);

                if(buildingDirectory.contains(read)){
                    cout<<"Existing building \""<<read<<"\" found. Remove? (y/n) ";
                    cin>>yesNo;
                    if(yesNo=='y'||yesNo=='Y'){
                        if(buildingDirectory.remove(read)){
                            cout<<"Building removed successfully."<<endl;
                        }
                        else{
                            cout<<"Error removing building."<<endl;
                        }
                    }
                }
                else{
                    cout<<"Adding new building..."<<endl;
                    tempB.setName(read);

                    cout<<"Enter building code: ";
                    getline(cin, read);
                    tempB.setCode(read);

                    cout<<"Enter building type: ";
                    getline(cin, read);
                    tempB.setType(read);

                    cout<<"Enter building description: ";
                    getline(cin, read);
                    tempB.setDescription(read);

                    if(buildingDirectory.insert(tempB.getName(), tempB)){
                        cout<<"Building added successfully."<<endl;
                    }
                    else{
                        cout<<"Error adding building.";
                    }
                }
                break;
            case 3:
                cout<<"===Depth-first==="<<endl;
                campusMap.dfsPrint();
                cout<<endl<<"===Breadth-first==="<<endl;
                campusMap.bfsPrint();
                cout<<endl;
                break;
            case 4:
                cin.ignore();
                cout<<"Enter start building: ";
                getline(cin, read);

                cout<<"Enter destination building: ";
                getline(cin, read2);

                campusMap.printShortestPath(read, read2);
                break;
            case 5:
                cout<<"Enter Job ID: ";
                cin>>in;
                tempJ.setID(in);

                cout<<"Enter Job priority: ";
                cin>>in;
                tempJ.setPriority(in);

                cin.ignore();
                cout<<"Enter Job Description: ";
                getline(cin, read);
                tempJ.setDescription(read);

                if(maintenanceJobs.insert(tempJ)){
                    cout<<"Job added successfully."<<endl;
                }
                else{
                    cout<<"Error adding job."<<endl;
                }
                break;
            case 6:
                cout<<"Next job:"<<endl;
                cout<<maintenanceJobs.extractMax();
                break;
        }
        cout<<"Return to main menu? (y/n) ";
        cin>>yesNo;
    }while(choice!=7&&yesNo!='n'&&yesNo!='N');

    return 0;
}