//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5
#include<iostream>
#include<string>
#include"DoubleList.h"
using namespace std;
class Faculty
{
  public:
    Faculty();
    Faculty(int input);
    Faculty(int i,string n,string l,string d,DoubleList<int> adv);
    ~Faculty();

    int facultyId;
    string facultyName;
    string facultyLevel;
    string department;
    //int* adviseesId;
    //int maxSize;
    int numAdvisee;

    int getFID();
    string getFName();
    string getFLevel();
    string getDepartment();
    void printFaculty();
    void addAdvisee(int id);
    typedef DoubleList<int> Dlist;
    Dlist advi;
    void printAdvisee();
    int getNumAdvisee();
    DoubleList<int> getAdviList();

    void deleteAdvisee(int studentId);
    friend bool operator< (const Faculty &c1, const Faculty &c2);
    friend bool operator> (const Faculty &c1, const Faculty &c2);
    friend bool operator!= (const Faculty &c1, const Faculty &c2);
};
