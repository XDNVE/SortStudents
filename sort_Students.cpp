/*
Created by : Md. Jafrul Hassan
Details: This programm takes name and CGPA of N number of students and then ranks them by CGPA
*/
#include <iostream>
#include <string>
using namespace std;

#define MAX 10;
int num_stu=0; // num of students

class Student
{
    private:
        string  name;
        char Roll[3];
        double CGPA;
        
    public:
        // constructor and destructor to count students
        Student();
        Student(string s_name,double s_CGPA);
        Student(char s_Roll[3],double s_CGPA);
        ~Student();

        //member function to input student's details
        void setDetails(void);
        //member function to print student's details
        void getDetails(void);
        //member function to return students CGPA in double datatype
        double getCGPA();
};

//constructor 1
Student::Student(){
    ++num_stu;
    //cout <<"object created = "<<num_std<<endl;
}
//constructor 2
Student::Student(string s_name,double s_CGPA){
    name=s_name;
    CGPA=s_CGPA;
    ++num_stu;
    //cout <<"object created = "<<num_std<<endl;
    
}
//constructor 3
Student::Student(char s_Roll[3],double s_CGPA){
    Roll[0]=s_Roll[0];
    Roll[1]=s_Roll[1];
    Roll[2]=s_Roll[2];
    CGPA=s_CGPA;
    ++num_stu;
    //cout <<"object created = "<<num_std<<endl;
    
}
Student::~Student(){
    --num_stu;
    //cout <<"Object deleted.\nRemaining objects = "<<num_std<<endl;
}

//member function definition, outside of the class
void Student::setDetails(void){
    cout << "Enter name: " ;
    cin >>name;
    cout << "Enter CGPA: ";
    cin >> CGPA;
    cout <<endl;

}

//member function definition, outside of the class
void Student::getDetails(void){

    cout << "Name:"<< name << ",CGPA:" << CGPA <<endl;
}

double Student::getCGPA(void){
    return CGPA;
}



void sortStudent(Student stu[],int n){
    int loop,max_CGPA_index;
    Student temp_s;
    double maxCGPA;
    for(loop=0;loop< n; loop++){
        maxCGPA=stu[loop].getCGPA();
        max_CGPA_index=loop;         //1 loop tracker
        for(int j=loop;j< n; j++){
            if(stu[j].getCGPA() > maxCGPA){
                max_CGPA_index=j;
                maxCGPA=stu[j].getCGPA();
            }
        }
        
        //swap
        if(max_CGPA_index!=loop){
        temp_s = stu[loop];
        stu[loop] = stu[max_CGPA_index];
        stu[max_CGPA_index] = temp_s;
        }
    }
}


void input_students(Student stu[],int n){
    for(int loop=0;loop< n; loop++){
        cout << "Enter details of student " << loop+1 << ":\n";
        stu[loop].setDetails();
    }
    cout << endl;

}

//print the sorted list
void print_sorted_students(Student stu[],int n){
    //output and delete objects
    cout <<"# Results #"<<endl;
    for(int loop=0;loop< n; loop++){
        cout << "\nStudent Rank : "<< (loop+1) << "\n";
        stu[loop].getDetails();
        }
}

int main()
{   
    int n;  //1mem = array index of lowest
    cout << "Enter total number of students: ";
    cin >> n;
    cout <<endl;

    Student stu[n];       //c++11 use MAX if error occurs array of objects creation

    input_students(stu,n);

    sortStudent(stu,n);

    print_sorted_students(stu,n);

    return 0;
}
