#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
using namespace std;

class Building{
    string name, code, type, description;
    public:
        Building();
        Building(const Building&);
        Building(const string, const string, const string, const string);

        string getName() const;
        string getCode() const;
        string getType() const;
        string getDescription() const;

        void setName(const string);
        void setCode(const string);
        void setType(const string);
        void setDescription(const string);

        bool operator==(const string&);
        friend ostream& operator<<(ostream&, const Building&);
};

#endif