#include <iostream>
#include <algorithm>
#include <deque>
#include <fstream>

using namespace std;

inline void ClearScreen() {
//      printf("\033c"); check which one is working  
      printf("\033[H\033[J");
//    cout << string(100, '\n');
}

class Record {
 protected:
    string name;
    char sex;
    string ID;
    string birthday;    //pairs, or other 3 volumed
    string address;
    unsigned short age;
 public:
    Record() {
        cout << "Please enter Name: ";
        cin >> name;
        cout << "             Sex: ";
        cin >> sex;
        cout << "             ID: ";
        cin >> ID;
        cout << "             Birthday: ";
        cin >> birthday;
        cin.ignore();     // skips \n
        cout << "             Address: ";
        getline(cin, address);
        cout << "             Age: ";
        cin >> age;
    }
    void print() {
       cout << "\nName: " << this->name
             << "\nSex: " << this->sex
             << "\nID: " << this->ID
             << "\nBirthday: " << this->birthday
             << "\nAddress: " << this->address
             << "\nAge: " << this->age 
    }
//    Record(const string a, const char &b, const string c,
//           const string d, const string e, const unsigned short &f)
//    {
//        name = a;
//        sex = b;
//        ID = c;
//        birthday = d;
//        address = e;
//        age = f;
//    }
};
class Student: protected Record {
    string number;
    string dormitory;   //pairs<string name, int number>
    string major;
    unsigned short year;    //1 - 4
 public:
    Student() {
        cout << "             Student Number: ";
        getline(cin,  number);
        //cin.ignore();     // skips \n
        cout << "             Dormitory Number: ";
        getline(cin, dormitory);
        cout << "             Major: ";
        cin >> major;
        cout << "             Year: ";
        cin >> year;
        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }

//  Student(const string a, const char &b, const string c,
//          const string d, const string e, const unsigned short &f,
//          const string g, const string h, const string j,
//          const unsigned short &k) {
//    name = a;
//    sex = b;
//    ID = c;
//    birthday = d;
//    address = e;
//    age = f;
//    number = g;
//    dormitory = h;
//    major = j;
//    year = k;
//  }
    /*inline*/bool operator==(Student const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.number == number
            && a.dormitory == dormitory && a.major == major);
    }

    static void print(deque<Student> &X, string const& stud_num);

    static void change(deque<Student> &X, string const& stud_num);

    static bool lookup(deque<Student> &X, string const& stud_num);
};

class Staff: protected Record {
 protected:
    unsigned long worker_number;
    string appartment;
    unsigned dailyHours;
    unsigned salary;
 public:
    Staff() {
        cout << "             Worker Number: ";
        cin >> worker_number;
        cin.ignore();     // skips \n
        cout << "             Appartment: ";
        getline(cin, appartment);
        cout << "             Working Hours: ";
        cin >> dailyHours;
        cout << "             Salary: ";
        cin >> salary;
    }
};
class Professor: protected Staff {
 protected:
    string fieldOfTeaching;
    string research;
    unsigned numOfPostgrads;
 public:
    Professor() {
        cin.ignore();     // skips \n
        cout << "             Field Of Teaching: ";
        getline(cin, fieldOfTeaching);
        cout << "             Research Project: ";
        getline(cin, research);
        cout << "             Number Of Postgraduate Students: ";
        cin >> numOfPostgrads;

        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }
    bool operator==(Professor const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.worker_number == worker_number
            && a.appartment == appartment && a.dailyHours == dailyHours
            && a.salary == salary && a.fieldOfTeaching == fieldOfTeaching
            && a.research == research && a.numOfPostgrads == numOfPostgrads
        );
    }

    static void print(deque<Professor> &X, const unsigned long &work_num);

    static void change(deque<Professor> &X, const unsigned long &work_num);

    static bool lookup(deque<Professor> &X, const unsigned long &work_num);
};

class Worker: protected Staff {
 protected:
    string job;
 public:
    Worker() {
        cin.ignore();     // skips \n
        cout << "             Job: ";
        getline(cin, job);
        cout << "Press any key to continue...\n";
        cin.get();
    }
    bool operator==(Worker const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.worker_number == worker_number
            && a.appartment == appartment && a.dailyHours == dailyHours
            && a.salary == salary && a.job == job

        );
    }
    static void print(deque<Worker> &X, const unsigned long &work_num);

    static void change(deque<Worker> &X, const unsigned long &work_num);

    static bool lookup(deque<Worker> &X, const unsigned long &work_num);
};

//int chooseTimes()
//{
//    cout << "1) Continuous adding\n"
//         << "2) Add just one record\n";
//}

void first_screen() {
    cout << "Welcome !\n" << "Choose the section:\n"
         << "1) Student\n"
         << "2) Professor\n"
         << "3) Worker\n"
         << "4) Exit\n";
//        << "4) Staff record\n"
//        << "5) Make a regular person record\n";
}
void second_screen() {
    //Welcoming to the screen of particular section,
    // add a parameter to customize welcoming
    cout << "1) Add a record\n"
         << "2) Print a record\n"
         << "3) Change a record\n"
         << "4) Delete a record\n"
         << "5) Find a record\n"
         << "6) Exit\n";
}

//void nesting(int option){                                  //second screen choosing menu
//    //add screen cleaning
//    second_screen();
//    cin >> option;
//    switch (option) {                                     //add screen cleaning
//    case 1:
//        break;
//    case 2:
//
//        break;
//    case 3:
//
//        break;
//    case 4:
//
//        break;
//    case 5:
//
//        break;
//    default:
//        cerr << "Wrong Input\n";
//        break;
//    }
//}

//void initialization(ifstream &XX, deque<Student> &list)
//{
//    string temporary;
//    getline(XX, temporary, '|');
//    if (temporary == "Student") {
//
//        string temp_name, temp_id, temp_birthday, temp_address, temp_number, temp_dorm, temp_major;
//        char temp_sex;
//        unsigned short temp_age, temp_year;
//
//        getline(XX, temp_name, '|');    //name
////        getline(XX, temp_sex, '|');
//        XX >> temp_sex;
//        getline(XX, temp_id, '|');
//        getline(XX, temp_birthday, '|');
////        getline(XX, temp_age, '|');
//        XX >> temp_age;
//        getline(XX, temp_number, '|');
//        getline(XX, temp_dorm, '|');
//        getline(XX, temp_major, '|');
//        XX >> temp_year;
//        Student input_temporary(temp_name,
//                                temp_sex,
//                                temp_id,
//                                temp_birthday,
//                                temp_address,
//                                temp_age,
//                                temp_number,
//                                temp_dorm,
//                                temp_major,
//                                temp_year);
//        list.push_back(input_temporary);
//    }
//
//}

int main() {
    std::ios::sync_with_stdio(false);
    short temp = 0;
    ifstream fs;    //add a checking system whether
                    //file has some records already
                    //and make an initialization func
    fs.open("/Users/Alexey/ClionProjects/cpp17shiyan/out1.txt");
    if (!fs.is_open())
        cerr << ("couldn't open file");

    deque<Student> students;
    deque<Professor> professors;
    deque<Worker> workers;

//    initialization(fs, students);

    FIRST_SCREEN:

    first_screen();
    cin >> temp;
//    ClearScreen();
    switch (temp) {
        case 1: {
            //add screen cleaning
            STUDENT_SCREEN:
            second_screen();

            cin >> temp;
            switch (temp) {
                //add screen cleaning
                case 1: {     //Adding record
                    Student temp_inp;       //stud_num recur check
                    students.push_back(temp_inp);
                    goto STUDENT_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Student number of a student you want to print: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::print(students, temp_studnum); //print is static, somewhy
                    goto STUDENT_SCREEN;
                    break;
                }
                case 3: {   //Changing
                    cout << "Student number of a student record you want to change: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::change(students, temp_studnum);    //change is static, somewhy
                    goto STUDENT_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a record you want to delete: \n";
                    Student to_be_deleted;
                    auto it = find(students.begin(), students.end(), to_be_deleted);
                    if (it != students.end()) {
                        students.erase(it);
                        cout << "Record has been succesfully deleted.\n";
                    } else
                        cout << "No record with such information were found.\n";
                    goto STUDENT_SCREEN;
                }
                case 5: {   //Find
                    cout << "Student number of a student you want to find: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    if (Student::lookup(students, temp_studnum))
                        cout << "There's a student with such student number.\n";
                    else
                        cout << "There's no student with such student number\n";
                    goto STUDENT_SCREEN;
                }
                case 6: {
                    goto FIRST_SCREEN;
                }
                default: {
                    cerr << "\nWrong Input\n\n";
                    goto STUDENT_SCREEN;
                }
            }
        }

        case 2: {
            PROFESSOR_SCREEN:
            second_screen();
            cin >> temp;
            switch (temp) {
                case 1: {     //Adding record
                    Professor temp_inp;       //stud_num recur check
                    professors.push_back(temp_inp);
                    goto PROFESSOR_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a professor you want to print: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Professor::print(professors, temp_worknum); //print is static, somewhy
                    goto PROFESSOR_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a professor record you want to change: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Professor::change(professors, temp_worknum);    //change is static, somewhy
                    goto PROFESSOR_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Professor to_be_deleted;
                    auto it = find(professors.begin(), professors.end(), to_be_deleted);
                    if (it != professors.end()) {
                        professors.erase(it);
                        cout << "Record has been succesfully deleted.\n";
                    } else
                        cout << "No record with such information were found.\n";
                    goto PROFESSOR_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a professor you want to find: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    if (Professor::lookup(professors, temp_worknum))
                        cout << "There's a professor with such worker number.\n";
                    else
                        cout << "There's no professor with such worker number\n";
                    goto PROFESSOR_SCREEN;
                }
                case 6: {
                    goto FIRST_SCREEN;
                }
                default: {
                    cerr << "\nWrong Input\n\n";
                    goto PROFESSOR_SCREEN;
                }
            }
        }
        case 3: {
            WORKER_SCREEN:

            second_screen();

            cin >> temp;
            switch (temp) {
                case 1: {     //Adding record
                    Worker temp_inp;       //stud_num recur check
                    workers.push_back(temp_inp);
                    goto WORKER_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a worker you want to print: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Worker::print(workers, temp_worknum); //print is static, somewhy
                    goto WORKER_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a worker record you want to change: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Worker::change(workers, temp_worknum);    //change is static, somewhy
                    goto WORKER_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Worker to_be_deleted;
                    auto it = find(workers.begin(), workers.end(), to_be_deleted);
                    if (it != workers.end()) {
                        workers.erase(it);
                        cout << "Record has been succesfully deleted.\n";
                    } else
                        cout << "No record with such information were found.\n";
                    goto WORKER_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a worker you want to find: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    if (Worker::lookup(workers, temp_worknum))
                        cout << "There's a worker with such worker number.\n";
                    else
                        cout << "There's no worker with such worker number\n";
                    goto WORKER_SCREEN;
                }
                case 6: {
                    goto FIRST_SCREEN;
                }
                default: {
                    cerr << "\nWrong Input\n\n";
                    goto WORKER_SCREEN;
                }
            }

        }
        case 4: {
            //saving to output file;
            fs.close();
            return 0;
        }
        default: {
            cerr << "\nWrong Input\n\n";
            goto FIRST_SCREEN;
        }
    }
}


void Student::print(deque<Student> &X, string const& stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });
    if (it != X.end()) {
        //Record::it.print();
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nStudent Number: " << it->number
             << "\nDormitory Number: " << it->dormitory
             << "\nMajor: " << it->major;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n\n";
        cin.get();
    } else {
        cout << "There's no student with number " << stud_num << endl;
    }
}
void Student::change(deque<Student> &X, string const& stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });
    if (it == X.end()) {
        cout << "There's no student with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A student with number " << stud_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        getline(cin, it->name);                            //add feature to leave the same info after pressing enter
        cout << "             Sex: ";
        getline(cin, it->sex);
        cout << "             ID: ";
        getline(cin, it->ID);
        cout << "             Birthday: ";
        getline(cin, it->birthday);
        cout << "             Address: ";
        //cin.ignore();
        getline(cin, it->address);
        cout << "             Age: ";
        getline(cin,it->age);
        cout << "             Student Number: ";
        getline(cinv, it->number);
        //cin.ignore();
        cout << "             Dormitory Number: ";
        getline(cin, it->dormitory);
        cout << "             Major: ";
        getline(cin, it->major);
        cout << "             Year: ";
        getline(cin, it->year);
//        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }
}
bool Student::lookup(deque<Student> &X, string const& stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });

    return it == X.end() ? false : true;
}
void Professor::print(deque<Professor> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it != X.end()) {
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nWorker Number: " << it->worker_number
             << "\nAppartment: " << it->appartment
             << "\nWorking Hours: " << it->dailyHours
             << "\nSalary: " << it->salary;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n\n";
        cin.get();
    } else {
        cout << "There's no professor with number " << work_num << endl;
    }
}
void Professor::change(deque<Professor> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A professor with number " << work_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        getline(cin, it->name);                            //add feature to leave the same info after pressing enter
        cout << "             Sex: ";
        getline(cin, it->sex);
        cout << "             ID: ";
        getline(cin, it->ID);
        cout << "             Birthday: ";
        getline(cin, it->birthday);
        cout << "             Address: ";
//        cin.ignore();
        getline(cin, it->address);
        cout << "             Age: ";
        getline(cin, it->age);
        cout << "             Worker Number: ";
        getline(cin, it->worker_number);
//        cin.ignore();     // skips \n
        cout << "             Appartment: ";
        getline(cin, it->appartment);
        cout << "             Working Hours: ";
        getline(cin,it->dailyHours);
        cout << "             Salary: ";
        getline(cin,it->salary);
//        cin.ignore();     // skips \n
        cout << "             Field Of Teaching: ";
        getline(cin, it->fieldOfTeaching);
        cout << "             Research Project: ";
        getline(cin, it->research);
        cout << "             Number Of Postgraduate Students: ";
        getline(cin,it->numOfPostgrads);

//        cin.ignore();

        cout << "Press any key to continue...\n";
        cin.get();
    }
}
bool Professor::lookup(deque<Professor> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });

    return it == X.end() ? false : true;
}
void Worker::print(deque<Worker> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it != X.end()) {
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nWorker Number: " << it->worker_number
             << "\nAppartment: " << it->appartment
             << "\nWorking Hours: " << it->dailyHours
             << "\nSalary: " << it->salary
             << "\nJob: " << it->job;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n\n";
        cin.get();
    } else {
        cout << "There's no worker with number " << work_num << endl;
    }
}
void Worker::change(deque<Worker> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A worker with number " << work_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        getline(cin, it->name);                            //add feature to leave the same info after pressing enter
        cout << "             Sex: ";
        getline(cin, it->sex);
        cout << "             ID: ";
        getline(cin, it->ID);
        cout << "             Birthday: ";
        getline(cin, it->birthday);
        cout << "             Address: ";
//        cin.ignore();
        getline(cin, it->address);
        cout << "             Age: ";
        getline(cin, it->age);
        cout << "             Worker Number: ";
        getline(cin,it->worker_number);
//        cin.ignore();     // skips \n
        cout << "             Appartment: ";
        getline(cin, it->appartment);
        cout << "             Working Hours: ";
        getline(cin, it->dailyHours);
        cout << "             Salary: ";
        getline(cin, it->salary);
//        cin.ignore();     // skips \n
        cout << "             Job: ";
        getline(cin, it->job);

//        cin.ignore();

        cout << "Press any key to continue...\n";
        cin.get();
    }
}
bool Worker::lookup(deque<Worker> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });

    return it == X.end() ? false : true;
}