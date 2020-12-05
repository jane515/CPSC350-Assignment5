//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5
#include<iostream>
#include<string>
using namespace std;
class Student
{
  public:
    Student();
    Student(int input);
    Student(int studentId,string studentName,string level,string studentMajor,double gpa,int advisor);
    int m_studentId;
    string m_studentName;
    string m_level;
    string m_studentMajor;
    double m_gpa;
    int m_advisor;


    int getSID();
    string getName();
    string getLevel();
    string getMajor();
    double getGPA();
    int getAdvisor();
    void printStudent();
    void assignAdvisor(int advisor);
    //friend ostream& operator<<(ostream& ot, const Student& s);
    friend bool operator< (const Student &c1, const Student &c2);
    friend bool operator!= (const Student &c1, const Student &c2);
    friend bool operator> (const Student &c1, const Student &c2);
};
