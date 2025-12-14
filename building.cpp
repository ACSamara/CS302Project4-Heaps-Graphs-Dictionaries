#include "building.h"

Building::Building(){
    name = "No name provided";
    code = "No code provided";
    type = "No type provided";
    description = "No description provided";
}
Building::Building(const Building& rhs){
    name = rhs.name;
    code = rhs.code;
    type = rhs.type;
    description = rhs.description;
}
Building::Building(const string n, const string c, const string t, const string d){
    name = n;
    code = c;
    type = t;
    description = d;
}
string Building::getName() const{
    return name;
}
string Building::getCode() const{
    return code;
}
string Building::getType() const{
    return type;
}
string Building::getDescription() const{
    return description;
}
void Building::setName(const string n){
    name = n;
}
void Building::setCode(const string c){
    code = c;
}
void Building::setType(const string t){
    type = t;
}
void Building::setDescription(const string d){
    description = d;
}
bool Building::operator==(const string& rhs){
    if (name == rhs){
        return true;
    }
    return false;
}
ostream& operator<<(ostream& out, const Building& obj){
    out<<obj.name<<endl;
    out<<"Code: "<<obj.code<<endl;
    out<<"Type: "<<obj.type<<endl;
    out<<obj.description<<endl;
    return out;
}