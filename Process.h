#include<iostream>

#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Process
{
  public:
    Process();
    //~Process();

    ofstream writeStudent;
    ofstream writeFaculty;
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;
    void printStudents();
    void printFaculty();
    void recPrintStudent(TreeNode<Student> *node);
    void recPrintFaculty(TreeNode<Faculty> *node);
    void printStudentInfo(Student student);
    void printFacultyInfo(Faculty faculty);
    void findStudent(int id);
    void findFaculty(int id);
    void findAdvisor(int id);
    void findAdvisee(int id);
    void addStudent(Student student);
    void addFaculty(Faculty faculty);
    void deleteStudent(int id);
    void deleteFaculty(int id);
    void changeAdvisor(int sId, int fId);
    void removeAdvisee(int fId,int sId);
    void showMenu();
    void readStudentFile();
    void writeStudentFile(TreeNode<Student> *node,string str);
    void writeSFile();
    void writeFile();

    void recStudent(TreeNode<Student> *node,string str);
    void run();
};
