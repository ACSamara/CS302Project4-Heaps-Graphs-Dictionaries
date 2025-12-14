#include "job.h"

Job::Job(){
    id = 000;
    description = "No description provided.";
    priority = 1;
}
Job::Job(const Job& rhs){
    id = rhs.id;
    description = rhs.description;
    priority = rhs.priority;
}
Job::Job(const int i, const string d, const int p){
    id = i;
    description = d;
    priority = p;
}
int Job::getID() const{
    return id;
}
string Job::getDescription() const{
    return description;
}
int Job::getPriority() const{
    return priority;
}
void Job::setID(const int i){
    id = i;
}
void Job::setDescription(const string d){
    description = d;
}
void Job::setPriority(const int p){
    priority = p;
}
bool Job::operator>(Job& obj){
    if(priority>obj.priority){
        return true;
    }
    return false;
}
bool Job::operator<(Job& obj){
    if(priority<obj.priority){
        return true;
    }
    return false;
}
bool Job::operator==(Job& obj){
    if(priority==obj.priority){
        return true;
    }
    return false;
}
ostream& operator<<(ostream& out, const Job& obj){
    out << "Job #" <<obj.id<<":"<<endl;
    out << obj.description <<endl;
    return out;
}