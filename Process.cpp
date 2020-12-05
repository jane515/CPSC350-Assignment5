#include <iostream>
#include "Process.h"

using namespace std;
Process::Process()
{
  //studen table
  BST<Student> masterStudent;
  //faculty table
  BST<Faculty> masterFaculty;
  ofstream writeStudent;
  ofstream writeFaculty;
}
//add student to the masterStudent BST
void Process::addStudent(Student student)
{
  //cout<<"inserting"<<endl;
  masterStudent.insertNode(student);

}
//recursive print student information
void Process::recPrintStudent(TreeNode<Student> *node)
{
  if (node == NULL)
    {
      //cout<<"NULL"<<endl;
      return;
    }
    recPrintStudent(node->left);
    cout << "Name: " << (node->key).getName() << endl;
    cout << "ID: " << (node->key).getSID() << endl;
    cout << "Level: " << (node->key).getLevel() << endl;
    cout << "Major: " << (node->key).getMajor() << endl;
    cout << "GPA: " << (node->key).getGPA() << endl;
    cout << "Advisor: " << (node->key).getAdvisor() << endl;
    recPrintStudent(node->right);
}
//print student information
void Process::printStudents()
{
  //cout<<"h"<<endl;
  recPrintStudent(masterStudent.root);
}
//recusive print faculty information
void Process::recPrintFaculty(TreeNode<Faculty> *node)
{
  if (node == NULL)
    {
        return;
    }
    recPrintFaculty(node->left);
    cout << "Name: " << (node->key).getFName() << endl;
    cout << "ID: " << (node->key).getFID() << endl;
    cout << "Level: " << (node->key).getFLevel() << endl;
    cout << "Department: " << (node->key).getDepartment() << endl;
    cout << "Advisee: ";
    (node->key).printAdvisee();
    cout <<endl;
    recPrintFaculty(node->right);
}
//print faculty information
void Process::printFaculty()
{
  recPrintFaculty(masterFaculty.root);
}
//print student info
void Process::printStudentInfo(Student student)
{
    cout << "Name: " << student.getName()<<endl;
    cout << "ID: " << student.getSID() << endl;;
    cout << "Level: " << student.getLevel()<< endl;
    cout << "Major: " << student.getMajor()<< endl;
    cout << "GPA: " << student.getGPA()<< endl;
    cout << "Advisor: " << student.getAdvisor() << endl;
}
//print faculty info
void Process::printFacultyInfo(Faculty faculty)
{
  cout << "Name: " << faculty.getFName() << endl;
  cout << "ID: " << faculty.getFID() << endl;
  cout << "Level: " << faculty.getFLevel() << endl;
  cout << "Department: " << faculty.getDepartment() << endl;
  cout << "Advisee: ";
  faculty.printAdvisee();
  cout<<endl;
}
/*
void Process::findStudent(int id)
{
  Student stu(id);
  //see if the student exist
  if(masterStudent.searchNode(stu))
  {
    //get the student obejct
    Student s = *masterStudent.values;
    printStudentInfo(s);
  }
  else
  {
    cout<<"Can't find this student"<<endl;
  }
}*/
//print student info by the student id
void Process::findStudent(int id)
{
  Student stu(id);
  //see if the student exist
  if(masterStudent.searchNode(stu))
  {
    //get the student obejct
    Student s = masterStudent.find(stu);
    printStudentInfo(s);
  }
  else
  {
    cout<<"Can't find this student"<<endl;
  }
}
//print faculty info by the id number
void Process::findFaculty(int id)
{
  //create a faculty object with id
  Faculty fac(id);
  //see if faculty exist
  if(masterFaculty.searchNode(fac))
  {
    Faculty f = masterFaculty.find(fac);
    printFacultyInfo(f);
  }
  else
  {
    cout<<"Can't find this faculty"<<endl;
  }
}
//get the advisor of the student
void Process::findAdvisor(int id)
{
  Student stu(id);
  int adv = 0;
  if(masterStudent.searchNode(stu))
  {
    Student s = masterStudent.find(stu);
    adv = s.getAdvisor();
    findFaculty(adv);
  }
  else
  {
    cout<<"Can't find this student"<<endl;
  }
}
//get the list of advisees
void Process::findAdvisee(int id)
{
  Faculty fac(id);
  if(masterFaculty.searchNode(fac))
  {
    Faculty f = masterFaculty.find(fac);
    DoubleList<int> dList = f.getAdviList();
    for(int i =0;i<dList.getSize();i++)
    {
      printStudentInfo(dList.printElement(i));
    }
  }
  else
  {
    cout<<"Can't find this faculty"<<endl;
  }
}
//add a new faculty to the bst
void Process::addFaculty(Faculty faculty)
{
  masterFaculty.insertNode(faculty);
}
//delete student from bst
void Process::deleteStudent(int id)
{
  Student stu(id);
  if(masterStudent.searchNode(stu))
  {
    Student s = masterStudent.find(stu);
    //delete the student from the faculty's advisee list
    Faculty fac(s.getAdvisor());
    if(masterFaculty.searchNode(fac))
    {
      Faculty f = masterFaculty.find(fac);
      f.deleteAdvisee(id);
    }
    //delete the student from the BST
    masterStudent.deleteNode(s);
  }
  else
  {
    cout<<"Can't find this student"<<endl;
  }
}
//delete faculty from bst
void Process::deleteFaculty(int id)
{
  Faculty fac(id);
  if(masterFaculty.searchNode(fac))
  {
    Faculty f = masterFaculty.find(fac);
    DoubleList<int> dList = f.getAdviList();
    //get the list of advisees and delete advisor for those students
    for(int i =0;i<dList.getSize();i++)
    {
      Student stu(dList.printElement(i));
      if(masterStudent.searchNode(stu))
      {
        Student s = masterStudent.find(s);
        s.assignAdvisor(0);
      }
    }
    masterFaculty.deleteNode(f);
  }
}

//change the advisor of a Studnet given the student id and the new advisor's id
void Process::changeAdvisor(int sId,int fId)
{
  Student stu(sId);
  if(masterStudent.searchNode(stu))
  {
    Faculty fac(fId);
    if(masterFaculty.searchNode(fac))
    {
      /*
      Student s = masterStudent.find(stu);
      s.assignAdvisor(fId);*/
      //assign the student a new advisor
      masterStudent.find(stu).assignAdvisor(fId);
      //add the student to new advisor's list
      masterFaculty.find(fac).addAdvisee(sId);
    }
    else
    {
      cout<<"Can't find this faculty"<<endl;
    }
  }
  else
  {
    cout<<"Can't find this student"<<endl;
  }
}
//delate an advisee
void Process::removeAdvisee(int fId,int sId)
{
  Faculty fac(fId);
  if(masterFaculty.searchNode(fac))
  {
    Student stu(sId);
    Faculty f = masterFaculty.find(fac);
    f.deleteAdvisee(sId);
    if(masterStudent.searchNode(stu))
    {
      /*
      Student s = masterStudent.find(stu);
      s.assignAdvisor(0);*/
      masterStudent.find(stu).assignAdvisor(0);

    }
    else
    {
      cout<<"Can't find this student"<<endl;
    }
  }
  else
  {
    cout<<"Can't find this faculty"<<endl;
  }
}
//menu
void Process::showMenu()
{
  cout<<"Please enter the number for the options: "<<endl;
  cout<<"1. Print all students and their information"<<endl;
  cout<<"2. Print all faculty and their information"<<endl;
  cout<<"3. Find and display student information given the students id"<<endl;
  cout<<"4. Find and display faculty information given the faculty id"<<endl;
  cout<<"5. Given a student’s id, print the name and info of their faculty advisor"<<endl;
  cout<<"6. Given a faculty id, print ALL the names and info of his/her advisees."<<endl;
  cout<<"7. Add a new student"<<endl;
  cout<<"8. Delete a student given the id"<<endl;
  cout<<"9. Add a new faculty member"<<endl;
  cout<<"10. Delete a faculty member given the id"<<endl;
  cout<<"11. Change a student’s advisor given the student id and the new faculty id"<<endl;
  cout<<"12. Remove an advisee from a faculty member given the ids"<<endl;
  cout<<"13. Rollback"<<endl;
  cout<<"14. Exit"<<endl;
}
void Process::run()
{
  readStudentFile();

  while(true)
  {
    int answer = 0;
    showMenu();
    cin>>answer;
    if(answer == 1)
    {
      printStudents();
      cout<<endl;
    }
    else if(answer == 2)
    {
      printFaculty();
      cout<<endl;
    }
    else if(answer == 3)
    {
      int id = 0;
      cout<<"Enter student id: "<<endl;
      cin>>id;
      findStudent(id);
    }
    else if(answer == 4)
    {
      int id = 0;
      cout<<"Enter faculty id: "<<endl;
      cin>>id;
      findFaculty(id);
    }
    else if(answer == 5)
    {
      int id = 0;
      cout<<"Enter student id: "<<endl;
      cin>>id;
      findAdvisor(id);
    }
    else if(answer == 6)
    {
      int id = 0;
      cout<<"Enter faculty id: "<<endl;
      cin>>id;
      findAdvisee(id);
    }
    else if(answer == 7)
    {
      string sName;
      int sId;
      string sLevel;
      string sMajor;
      double gpa;
      int advisor;
      cout<<"Please enter the name of the student: "<<endl;
      cin>>sName;
      cout<<"Enter the student's ID: "<<endl;
      cin>>sId;
      cout<<"Enter the student's level: "<<endl;
      cin>>sLevel;
      cout<<"Enter the student's major: "<<endl;
      cin>>sMajor;
      cout<<"Enter the student's gpa: "<<endl;
      cin>>gpa;
      cout<<"Enter the student's advisor, if no advisor, enter 0: "<<endl;
      cin>>advisor;
      Student stu(sId,sName,sLevel,sMajor,gpa,advisor);
      //stu.printStudent();
      addStudent(stu);
    }
    else if(answer==8)
    {
      int id = 0;
      cout<<"Enter student id: "<<endl;
      cin>>id;
      deleteStudent(id);
    }
    else if(answer == 9)
    {
      int fId;
      string fName;
      string fLevel;
      string department;
      int numAdi;
      DoubleList<int> list;

      cout<<"Enter the name of the faculty: "<<endl;
      cin>>fName;
      cout<<"Enter the id of the faculty: "<<endl;
      cin>>fId;
      cout<<"Enter the level of the faculty: "<<endl;
      cin>>fLevel;
      cout<<"Enter the department of the faculty: "<<endl;
      cin>>department;
      cout<<"Enter the number of advisees this advisor has: "<<endl;
      cin>>numAdi;
      for(int i =0;i<numAdi;i++)
      {
        int sid;
        cout<<"Enter the student id: "<<endl;
        cin>>sid;
        list.insertBack(sid);
      }
      Faculty f(fId,fName,fLevel,department,list);
      //f.printFaculty();
      addFaculty(f);
    }
    else if(answer==10)
    {
      int id = 0;
      cout<<"Enter faculty id: "<<endl;
      cin>>id;
      deleteFaculty(id);
    }
    else if(answer==11)
    {
      int sid = 0;
      cout<<"Enter student id: "<<endl;
      cin>>sid;
      int fid = 0;
      cout<<"Enter the faculty id: "<<endl;
      cin>>fid;
      changeAdvisor(sid,fid);
    }
    else if(answer==12)
    {
      int sid = 0;
      cout<<"Enter student id: "<<endl;
      cin>>sid;
      int fid = 0;
      cout<<"Enter the faculty id: "<<endl;
      cin>>fid;
      removeAdvisee(fid,sid);
    }
    else if(answer==13)
    {

      //previousStudent(masterStudent);
      //previousFaculty(masterFaculty);
    }
    else if(answer==14)
    {
      writeSFile();
      cout<<"bye"<<endl;
      break;
    }
  }
}
//read the student information from txt file
void Process::readStudentFile()
{
  ifstream studentFile;
  int lines = 0;
  int studentCount = 0;
  studentFile.open("studentTable.txt");
  if(studentFile.is_open())
  {
    string line;
    while(std::getline(studentFile,line))
    {
      lines++;
    }
    //each student take 6 lines
    studentCount = lines/6;
    for(int i =0;i<studentCount;i++)
    {
      string sName;
      int sId;
      string sLevel;
      string major;
      double gpa;
      int advisor;
      //iterate 6 lines and read the information
      for(int j =0;j<6;j++)
      {
        if(j==0)
        {
          sName = line;
        }
        else if(j==1)
        {
          sId = stoi(line);
        }
        else if(j==2)
        {
          sLevel = line;
        }
        else if(j==3)
        {
          major = line;
        }
        else if(j==4)
        {
          gpa = stod(line);
        }
        else
        {
          advisor = stoi(line);
        }
      }
      Student s = Student(sId,sName,sLevel,major,gpa,advisor);
      //insert the student to student table
      masterStudent.insertNode(s);
    }
  }
}
//recursive write to student file
void Process::writeStudentFile(TreeNode<Student> *node,string str)
{
  ofstream file;
  file.open(str);
  if(node == NULL)
  {
    //file<<"ha"<<endl;
    return;
  }
  writeStudentFile(node->left,str);
  file<<(node->key).getName()<<endl;
  file <<(node->key).getSID() << endl;
  file << (node->key).getLevel() << endl;
  file << (node->key).getMajor() << endl;
  file << (node->key).getGPA() << endl;
  file << (node->key).getAdvisor() << endl;
  writeStudentFile(node->right,str);
}
void Process::writeSFile()
{
  ofstream studentFile;
  studentFile.open("studentTable.txt");
  if(studentFile.is_open())
  {
    //TreeNode<Student> *node = masterStudent.root;
    writeStudentFile(masterStudent.root,"studentTable.txt");
  }
  studentFile.close();
  cout<<"Writen to a file"<<endl;
}
/*
void Process::readFile()
{
  ifstream studentFile;
  ifstream facultyFile;
  int lines = 0;
  int studentCount = 0;
  studentFile.open("studentTable.txt");
  if(studentFile.is_open())
  {
    string line;
    while(std::getline(studentFile,line))
    {
      lines++;
    }
    //each student take 6 lines
    studentCount = lines/6;
    for(int i =0;i<studentCount;i++)
    {
      string sName;
      int sId;
      string sLevel;
      string major;
      double gpa;
      int advisor;
      //iterate 6 lines
      for(int j =0;j<6;j++)
      {
        if(j==0)
        {
          sName = line;
        }
        else if(j==1)
        {
          sId = stoi(line);
        }
        else if(j==2)
        {
          sLevel = line;
        }
        else if(j==3)
        {
          major = line;
        }
        else if(j==4)
        {
          gpa = stod(line);
        }
        else
        {
          advisor = stoi(line);
        }
      }
      Student s = Student(sId,sName,sLevel,major,gpa,advisor);
      //insert the student to student table
      masterStudent->insertNode(s);
    }
  }
  studentFile.close();
  int facultyCount = 0;
  int flines = 0;
  facultyFile.open("facultyTable.txt");
  if(facultyFile.is_open())
  {
    string line;
    //get the total lines
    while(std::getline(facultyFile,line))
    {
      flines++;
    }
    //each faculty take 6 lines
    facultyCount = flines/6;
    for(int i =0;i<facultyCount;i++)
    {
      string fName;
      int fId;
      string fLevel;
      string department;
      //int advisee;
      Faculty f;
      DoubleList<int> dList;
      //iterate 5 lines
      std::string idNumber;
      for(int j =0;j<5;j++)
      {
        if(j==0)
        {
          fName = line;
        }
        else if(j==1)
        {
          fId = stoi(line);
        }
        else if(j==2)
        {
          fLevel = line;
        }
        else if(j==3)
        {
          department = line;
        }
        else if(j==4)
        {
          //iterate through the line, each id is separate by |
          for(char x:line)
          {
            if(x=="|")
            {
              dList.insertBack(stoi(idNumber));
              idNumber="";
            }
            else
            {
              idNumber.push_back(x);
            }
          }
        //the advisee id is stored in a single line, separate by |
        }
        f = Faculty(fId,fName,fLevel,department,Dlist);
        masterFaculty.insertNode(f);
      }
    }
    facultyFile.close();
  }
}
void Process::recStudent(TreeNode<Student> *node,string str)
{
  ofstream file;
  file.open(str);
  if(node!=NULL)
  {
    file<<node->getName()<<endl;
    file<<node->getSID()<<endl;
    file<<node->getLevel()<<endl;
    file<<node->getMajor()<<endl;
    file<<node->getGPA()<<endl;
    file<<node->getAdvisor()<<endl;
    if(node->left !=NULL)
    {
      recStudent(node->left,str);
    }
    if(node->right !=NULL)
    {
      recStudent(node->right,str);
    }
  }
  else
  {
    return;
  }
  file.close();
}

void Process::recFaculty(TreeNode<Faculty> *node,string str)
{
  ofstream file;
  file.open(str);
  if(node!=NULL)
  {
    file<<node->getFName()<<endl;
    file<<node->getFID()<<endl;
    file<<node->getFLevel()<<endl;
    file<<node->getDepartmentr()<<endl;

    file<<endl;
    if(node->left !=NULL)
    {
      recFaculty(node->left,str);
    }
    if(node->right !=NULL)
    {
      recFaculty(node->right,str);
    }
  }
  else
  {
    return;
  }
  file.close();
}*/
/*
void Process::writeFile()
{
  ofstream studentFile;
  ofstream facultyFile;
  studentFile.open("studentTable.txt");
  if(studentFile.is_open())
  {
    TreeNode<Student> *node = masterStudent.getRoot();
    recStudent(node,"studentTable.txt");
  }
  studentFile.close();
  facultyFile.open("facultyTable.txt");
  if(facultyFile.is_open())
  {
    TreeNode<Faculty> *node = masterFaculty.getRoot();
    recFaculty(node,"facultyTable.txt");
  }
  facultyFile.close();
  cout<<"Writen to a file"<<endl;
}*/
