//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5

#include "Student.h"
Student::Student()
{
  m_studentId = 0;
  m_studentName = "a";
  m_level = "a";
  m_studentMajor = "a";
  m_gpa = 0;
  m_advisor = 0;
}
Student::Student(int input)
{
  m_studentId = input;
}
Student::Student(int studentId,string studentName,string level,string studentMajor,double gpa,int advisor)
{
  m_studentId = studentId;
  m_studentName = studentName;
  m_level = level;
  m_studentMajor = studentMajor;
  m_gpa = gpa;
  m_advisor = advisor;
}

int Student::getSID()
{
  return m_studentId;
}

int Student::getAdvisor()
{
  return m_advisor;
}

void Student::printStudent()
{
  cout<<"Student Id: "<<m_studentId<<", Name: "<<m_studentName<<", level: "<<m_level<<", Major: "<<m_studentMajor<<", GPA: "<<m_gpa<<", Advisor: "<<m_advisor;
}

void Student::assignAdvisor(int advisor)
{
  m_advisor = advisor;
}
string Student::getName()
{
  return m_studentName;
}
string Student::getLevel()
{
  return m_level;
}
string Student::getMajor()
{
  return m_studentMajor;
}
double Student::getGPA()
{
  return m_gpa;
}
bool operator !=(const Student &s1, const Student &s2)
{
  return (s1.m_studentId!=s2.m_studentId);
}
bool operator <(const Student &s1, const Student &s2)
{
  return(s1.m_studentId<s2.m_studentId);
}
bool operator >(const Student &s1, const Student &s2)
{
  return(s1.m_studentId>s2.m_studentId);
}
/*
ostream& operator<<(ostream& ot, const Student& s)
{
    ot <<s.studentName<<','<< s.studentId<<','<<s.level<<','<<s.studentMajor<<'.'<<s.gpa<<','<<s.advisor;
    return ot;
}*/
