#ifndef JOB_H
#define JOB_H

#include <iostream>
using namespace std;

class Job{
    int id;
    string description;
    int priority;

    public:
        Job();
        Job(const Job&);
        Job(const int, const string, const int);

        int getID() const;
        string getDescription() const;
        int getPriority() const;

        void setID(const int);
        void setDescription(const string);
        void setPriority(const int);

        bool operator>(Job&);
        bool operator<(Job&);
        bool operator==(Job&);

        friend ostream& operator<<(ostream&, const Job&);
};

#endif