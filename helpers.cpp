#include "helpers.h"

void displayMainMenu(){
    cout<<"1. Look up a building" <<endl;
    cout<<"2. Add / remove building"<<endl;
    cout<<"3. View campus map"<<endl;
    cout<<"4. Find shortest path between two buildings"<<endl;
    cout<<"5. Add a maintenance job"<<endl;
    cout<<"6. Process next maintenance job"<<endl;
    cout<<"7. Exit"<<endl;
}

/*
Helper function to read maintenance jobs from a file and load them into an array. Returns the number of maintenance jobs.
*/
int readMaintenanceJobs(string filename, Job*& arr){
    ifstream f;
    string read;
    int size = 0, maxSize = 0;
    arr = new Job[maxSize];

    f.open(filename);

    getline(f, read);

    while(!f.eof()){
        maxSize++;
        arr = resizeArray<Job>(arr, maxSize, size);

        Job temp;

        getline(f, read, ',');
        temp.setID(stoi(read));

        getline(f, read, ',');
        temp.setPriority(stoi(read));

        getline(f, read);
        temp.setDescription(read);

        arr[size] = temp;
        size++;
    }

    f.close();

    return size;
}

Graph<string> readMap(string filename){
    ifstream f;
    string read;

    Graph<string> output;
    
    f.open(filename);

    getline(f, read);

    while(!f.eof()){
        int weight;
        string u, v;

        getline(f, u, ',');
        output.addVertex(u);

        getline(f, v, ',');
        output.addVertex(v);

        getline(f, read);
        output.addEdge(u,v,stoi(read));
    }

    f.close();

    return output;
}
Dictionary<Building> readBuildings(string filename){
    ifstream f;
    string read;
    Dictionary<Building> output;

    f.open(filename);

    getline(f, read);

    while(!f.eof()){
        Building temp;

        getline(f, read, ',');
        temp.setName(read);

        getline(f, read, ',');
        temp.setCode(read);

        getline(f, read, ',');
        temp.setType(read);

        getline(f, read);
        temp.setDescription(read);

        output.insert(temp.getName(), temp);
    }

    f.close();

    return output;
}