//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5

#include "Faculty.h"
Faculty::Faculty()
{
  facultyId = -1;
  facultyName = "a";
  facultyLevel = "a";
  department = "a";
  //maxSize = 5;
  numAdvisee = 0;
  //advi = new DoubleList<int>();
}
Faculty::Faculty(int input)
{
  facultyId = input;
}

Faculty::Faculty(int i,string n,string l,string d,DoubleList<int> adv)
{
  facultyId = i;
  facultyName = n;
  facultyLevel = l;
  department = d;
  numAdvisee = advi.getSize();
  advi=adv;
  //advi = new DoubleList<int>();
}

Faculty::~Faculty()
{
  //delete adviseesId;
}

int Faculty::getFID()
{
  return facultyId;
}

string Faculty::getFName()
{
  return facultyName;
}

void Faculty::addAdvisee(int id)
{
  advi.insertFront(id);
}
void Faculty::printFaculty()
{
  cout<<"Faculty ID: "<<facultyId<<", Faculty Name: "<<facultyName<<", Faculty Level: "<<facultyLevel<<", Department: "<<department<<endl;
  cout<<"The number of advisees this faculty have is: "<<numAdvisee<<endl;
  cout<<"advisees: "<<" ";
  advi.printList();
  cout<<endl;
}
//list of advisees
void Faculty::printAdvisee()
{
  advi.printList();
}
int Faculty::getNumAdvisee()
{
  return numAdvisee;
}
void Faculty::deleteAdvisee(int studentId)
{
  advi.remove(studentId);
}
string Faculty::getFLevel()
{
  return facultyLevel;
}
string Faculty::getDepartment()
{
  return department;
}

bool operator !=(const Faculty &c1, const Faculty &c2){
  if(c1.facultyId!=c2.facultyId){
    return true;
  }
  else{
    return false;
  }
}
bool operator <(const Faculty &c1, const Faculty &c2){
  if(c1.facultyId<c2.facultyId){
    return true;
  }
  else{
    return false;
  }
}
bool operator >(const Faculty &c1, const Faculty &c2){
  if(c1.facultyId>c2.facultyId){
      return true;
  }
  else{
    return false;
  }
}
/*
ostream& operator<<(ostream& ot, const Faculty& f)
{
    ot <<f.facultyName<<','<<f.facultyId<<','<< f.facultyLevel<<','<<f.department<<','<<f.numAdvisee;
    for(int i =0;i<f.advi.size;i++)
    {
      int x = f.advi.removeBack();
      ot<<x<<",";
      f.advi.insertFront(x);
    }
    return ot;
}*/
DoubleList<int> Faculty::getAdviList()
{
  return advi;
}
