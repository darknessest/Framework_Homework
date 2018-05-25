#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

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
        cin.ignore();
        getline(cin, name);
        cout << "             Sex: ";
        cin >> sex;
        while (sex != 'M' || sex != 'F') {
            cerr << "\nWrong input. Please enter M or F\n";
            if (sex == 'M' || sex == 'F')
                break;
            cout << "             Sex: ";
            cin >> sex;
        }
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter M or F";
            cout << "\n             Sex: ";
            cin >> sex;
            if (cin)         //doesn't change a shit
                break;
        }
        cout << "             ID: ";
        cin >> ID;
        cout << "             Birthday: ";
        cin >> birthday;
        cin.ignore();     // skips \n
        cout << "             Address: ";
        getline(cin, address);

        cout << "             Age: ";
        cin >> age;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number";
            cout << "\n             Age: ";
            cin >> age;
        }
    }
    Record(string const &a, const char &b, string const &c,
           string const &d, string const &e, const unsigned short &f) {
        name = a;
        sex = b;
        ID = c;
        birthday = d;
        address = e;
        age = f;
    }
};
class Student: public Record {
    string number;
    string dormitory;   //pairs<string name, int number>
    string major;
    unsigned short year;    //1 - 4
 public:
    Student() {
        cout << "             Student Number: ";
        cin.ignore();     // skips \n

        getline(cin, number);
        cout << "             Dormitory Number: ";
        getline(cin, dormitory);

        cout << "             Major: ";
        getline(cin, major);
        cout << "             Year: ";
        cin >> year;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number";
            cout << "\n             Year: ";
            cin >> year;
        }
//        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.ignore();
    }
    Student(string const &a, const char &b, string const &c,
            string const &d, string const &e, const unsigned short &f,
            string const &g, string const &h, string const &j,
            const unsigned short &k) : Record(a, b, c, d, e, f) {
        number = g;
        dormitory = h;
        major = j;
        year = k;
    }
    bool operator==(Student const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.number == number
            && a.dormitory == dormitory && a.major == major);
    }
    friend ostream &operator<<(ostream &out, const Student &a);
    friend istream &operator>>(istream &in, Student &a);

    static void add(vector<Student> &X, const Student &a);

    static void print(vector<Student> &X, string const &stud_num);

    static void change(vector<Student> &X, string const &stud_num);

    static bool lookup(vector<Student> &X, string const &stud_num);
};

class Staff: public Record {
 protected:
    string worker_number;
    string appartment;
    unsigned short dailyHours;
    unsigned salary;
 public:
    Staff() {
        string temp;
        cin.ignore();
        cout << "             Worker Number: ";
        getline(cin, worker_number);
        cout << "             Appartment: ";
        getline(cin, appartment);

        cout << "             Daily Working Hours: ";
        cin >> dailyHours;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number\n";
            cout << "             Daily Working Hours: ";
            cin >> dailyHours;
        }

        cout << "             Salary: ";
        cin >> salary;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number\n";
            cout << "             Salary: ";
            cin >> salary;
        }
    }
    Staff(string const &a, const char &b, string const &c,
          string const &d, string const &e, const unsigned short &f,

          string const &g, string const &h, const unsigned short &j,
          const unsigned &k) : Record(a, b, c, d, e, f) {
        worker_number = g;
        appartment = h;
        dailyHours = j;
        salary = k;
    }
    template<class T, class B>
    static void add(vector<T> &X, const T &a, vector<B> &Z) {
        if (!(T::lookup(X, a.worker_number) && B::lookup(Z, a.worker_number))) {
            X.push_back(a);
            return;
        } else
            cout << "\nRecord with worker number " << a.worker_number << " already exists\n";
    }
};
class Professor: public Staff {
 protected:
    string fieldOfTeaching;
    string research;
    short numOfPostgrads;
 public:
    Professor() {
        string temp;
        cin.ignore();     // skips \n
        cout << "             Field Of Teaching: ";
        getline(cin, fieldOfTeaching);
        cout << "             Research Project: ";
        getline(cin, research);
        cout << "             Number Of Postgraduate Students: ";
        cin >> numOfPostgrads;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number\n";
            cout << "             Number Of Postgraduate Students: ";
            cin >> numOfPostgrads;
        }

//        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.ignore();
    }
    Professor(string const &a, const char &b, string const &c,
              string const &d, string const &e, const unsigned short &f,
              string const &g, string const &h, const unsigned &j,
              const unsigned &k,
              string const &l, string const &m,
              const unsigned &n) : Staff(a, b, c, d, e, f, g, h, j, k) {
        fieldOfTeaching = l;
        research = m;
        numOfPostgrads = n;
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
    friend ostream &operator<<(ostream &out, const Professor &a);
    friend istream &operator>>(istream &in, Professor &a);

    static void print(vector<Professor> &X, string const &work_num);

    static void change(vector<Professor> &X, string const &work_num);

    static bool lookup(vector<Professor> &X, string const &work_num);
};

class Worker: public Staff {
 protected:
    string job;
 public:
    Worker() {
        cout << "             Job: ";
        getline(cin, job);
        cout << "Press any key to continue...\n";
        cin.ignore();
    }
    Worker(string const &a, const char &b, string const &c,
           string const &d, string const &e, const unsigned short &f,
           string const &g, string const &h, const unsigned &j,
           const unsigned &k, string const &l) : Staff(a, b, c, d, e, f, g, h, j, k) {
        job = l;
    }
    bool operator==(Worker const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.worker_number == worker_number
            && a.appartment == appartment && a.dailyHours == dailyHours
            && a.salary == salary && a.job == job

        );
    }
    friend ostream &operator<<(ostream &out, const Worker &a);
    friend istream &operator>>(istream &in, Worker &a);

    static void print(vector<Worker> &X, string const &work_num);

    static void change(vector<Worker> &X, string const &work_num);

    static bool lookup(vector<Worker> &X, string const &work_num);
};
void ClearScreen() {
//      printf("\033c"); //check which one is working
    printf("\033[H\033[J");
//    cout << string(100, '\n');
}
void first_screen() {
    ClearScreen();
    cout << "Choose the section:\n"
         << "1) Student\n"
         << "2) Professor\n"
         << "3) Worker\n"
         << "4) Exit\n";
}
void second_screen() {
    ClearScreen();
    cout << "1) Add a record\n"
         << "2) Print a record\n"
         << "3) Change a record\n"
         << "4) Delete a record\n"
         << "5) Find a record\n"
         << "6) Exit\n";
}

//void nesting(int option){                                  //second screen choosing menu
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

void initialization(vector<Student> &list1, vector<Professor> &list2, vector<Worker> &list3) {
    cout << "Enter the filename of database (e.g. \"in.txt\") if u have it already: ";

    string database_name;
    getline(cin, database_name);

    fstream XX(database_name, ios::in);
    if (!XX)
        cerr << "couldn't open " << database_name << "\n";
    cout << "initialization is in progress...\n";

    string temporary;
    while (XX) {

        XX >> temporary;
        if (temporary == "Student") {
            Student input_temporary("", 'a', "", "", "", 0, "", "", "", 0);
            XX >> input_temporary;
            list1.push_back(input_temporary);
        }
        if (temporary == "Professor") {
            Professor input_temporary("", 'a', "", "", "", 0, 0, "", 0, 0, "", "", 0);
            XX >> input_temporary;
            list2.push_back(input_temporary);
        }
        if (temporary == "Worker") {
            Worker input_temporary("", 'a', "", "", "", 0, 0, "", 0, 0, "");
            XX >> input_temporary;
            list3.push_back(input_temporary);
        }
    }
    XX.close();
    ClearScreen();
}

void fin_out(const vector<Student> &list1, const vector<Professor> &list2,
             const vector<Worker> &list3) {
    cout << "Enter the filename of output database (e.g. \"out.txt\") if u have it already: ";
    cin.ignore();
    string database_name;
    getline(cin, database_name);

    ofstream ofs(database_name, ios::out);
    if (!ofs)
        cerr << ("couldn't create file");
    for (auto const &x : list1)
        ofs << x;
    for (auto const &x : list2)
        ofs << x;
    for (auto const &x : list3)
        ofs << x;

    ofs.close();
    cout << "\nAll records were stored\n";
}

int main() {
    std::ios::sync_with_stdio(false);       //improves I/O speed, because doesn't make sync between c++ and c-style I/O
    short temp = 0;

    vector<Student> students;
    vector<Professor> professors;
    vector<Worker> workers;
    initialization(students, professors, workers);   //fs is handled inside

    cout << "Welcome !\n";
    ClearScreen();
    FIRST_SCREEN:

    first_screen();
    cin >> temp;
    ClearScreen();
    switch (temp) {
        case 1: {
            STUDENT_SCREEN:
            temp = 0;
            second_screen();
            cin >> temp;
            switch (temp) {
                case 1: {     //Adding record
                    Student temp_inp;
                    Student::add(students, temp_inp);
                    goto STUDENT_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Student number of a student you want to print: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::print(students, temp_studnum);
                    goto STUDENT_SCREEN;
                    break;
                }
                case 3: {   //Changing
                    cout << "Student number of a student record you want to change: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::change(students, temp_studnum);
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
                        cout << "There's a student with student number " << temp_studnum << "\n";
                    else
                        cout << "There's no student with student number " << temp_studnum << "\n";
                    goto STUDENT_SCREEN;
                }
                case 6: {   //leave
                    goto FIRST_SCREEN;
                }
                default: {
                    cin.clear();
                    cin.ignore(999, '\n');
                    cerr << "\nWrong Input\n\n";
                    goto STUDENT_SCREEN;
                }
            }
        }

        case 2: {
            PROFESSOR_SCREEN:
            temp = 0;
            second_screen();
            cin >> temp;
            switch (temp) {
                case 1: {     //Adding record
                    Professor temp_inp;
                    Staff::add(professors, temp_inp, workers);
                    goto PROFESSOR_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a professor you want to print: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Professor::print(professors, temp_worknum);
                    goto PROFESSOR_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a professor record you want to change: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Professor::change(professors, temp_worknum);
                    goto PROFESSOR_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Professor to_be_deleted;
                    auto it = find(professors.begin(), professors.end(), to_be_deleted);
                    if (it != professors.end()) {
                        professors.erase(it);
                        cout << "Record has been succesfully deleted.\n\n";
                    } else
                        cout << "No record with such information were found.\n\n";
                    goto PROFESSOR_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a professor you want to find: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    if (Professor::lookup(professors, temp_worknum))
                        cout << "There's a professor with such worker number.\n\n";
                    else
                        cout << "There's no professor with such worker number\n\n";
                    goto PROFESSOR_SCREEN;
                }
                case 6: {   //leave
                    goto FIRST_SCREEN;
                }
                default: {
                    cin.clear();
                    cin.ignore(999, '\n');
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
                case 1: {     //Adding
                    Worker temp_inp;
                    Staff::add(workers, temp_inp, professors);
                    goto WORKER_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a worker you want to print: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Worker::print(workers, temp_worknum);
                    goto WORKER_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a worker record you want to change: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Worker::change(workers, temp_worknum);
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
                    string temp_worknum;
                    cin >> temp_worknum;
                    if (Worker::lookup(workers, temp_worknum))
                        cout << "There's a worker with such worker number.\n";
                    else
                        cout << "There's no worker with such worker number\n";
                    goto WORKER_SCREEN;
                }
                case 6: {   //leave
                    goto FIRST_SCREEN;
                }
                default: {
                    cin.clear();
                    cin.ignore(999, '\n');
                    cerr << "\nWrong Input\n\n";
                    goto WORKER_SCREEN;
                }
            }
        }
        case 4: {
            fin_out(students, professors, workers);
            return 0;
        }
        default: {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong Input\n\n";

            goto FIRST_SCREEN;
        }
    }
}
ostream &operator<<(ostream &out, const Student &a) {
    if (!a.name.empty()) {
        out << "Student | " << a.name
            << " | " << a.sex
            << " | " << a.ID
            << " | " << a.birthday
            << " | " << a.address
            << " | " << a.age
            << " | " << a.number
            << " | " << a.dormitory
            << " | " << a.major
            << " | " << a.year << endl;
    }
    return out;
}
istream &operator>>(istream &in, Student &a) {
    in.ignore(3, '|');
    in >> a.name;
    in.ignore(2, '|');
    in >> a.sex;
    in.ignore(2, '|');
    in >> a.ID;
    in.ignore(2, '|');
    in >> a.birthday;
    in.ignore(2, '|');

    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');

    in >> a.age;
    in.ignore(2, '|');
    in >> a.number;
    in.ignore(2, '|');
    in >> a.dormitory;
    in.ignore(3, '|');

    in.ignore(2, ' ');
    getline(in, a.major, '|');
    in >> a.year;

    return in;
}
void Student::add(vector<Student> &X, const Student &a) {
    if (!Student::lookup(X, a.number)) {
        X.push_back(a);
        return;
    } else
        cout << "\nRecord with student number " << a.number << " already exists\n";
}
void Student::print(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });
    if (it != X.end()) {
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nStudent Number: " << it->number
             << "\nDormitory Number: " << it->dormitory
             << "\nMajor: " << it->major
             << "\nYear: " << it->year;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.get();
    } else {
        cout << "\nThere's no student with student number " << stud_num << endl << endl;
    }
}
void Student::change(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });
    if (it == X.end()) {
        cout << "There's no student with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A student with number " << stud_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        X.erase(it);
        Student anewone;
        X.push_back(anewone);
    }
}
bool Student::lookup(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });

    return !(it == X.end());
}

ostream &operator<<(ostream &out, const Professor &a) {
    if (!a.name.empty()) {
        out << "Professor | " << a.name
            << " | " << a.sex
            << " | " << a.ID
            << " | " << a.birthday
            << " | " << a.address
            << " | " << a.age
            << " | " << a.worker_number
            << " | " << a.appartment
            << " | " << a.dailyHours
            << " | " << a.salary
            << " | " << a.fieldOfTeaching
            << " | " << a.research
            << " | " << a.numOfPostgrads << endl;
    }
    return out;
}
istream &operator>>(istream &in, Professor &a) {
    in.ignore(3, '|');
    in >> a.name;
    in.ignore(2, '|');
    in >> a.sex;
    in.ignore(2, '|');
    in >> a.ID;
    in.ignore(2, '|');
    in >> a.birthday;
    in.ignore(2, '|');

    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');

    in >> a.age;
    in.ignore(2, '|');
    in >> a.worker_number;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.dailyHours;
    in.ignore(2, '|');
    in >> a.salary;

    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.fieldOfTeaching, '|');
    in.ignore(2, ' ');

    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.research, '|');
    in.ignore(2, ' ');
    cin >> a.numOfPostgrads;

    return in;
}

void Professor::print(vector<Professor> &X, string const &work_num) {
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
             << "\nDaily Working Hours: " << it->dailyHours
             << "\nSalary: " << it->salary
             << "\nField Of Teaching: " << it->fieldOfTeaching
             << "\nResearch Project: " << it->research
             << "\nNumber Of Postgraduate Students: " << it->numOfPostgrads;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.get();
    } else {
        cout << "There's no professor with number " << work_num << endl << endl;
    }
}
void Professor::change(vector<Professor> &X, string const &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A professor with number " << work_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        X.erase(it);
        Professor anewone;
        X.push_back(anewone);
    }
}
bool Professor::lookup(vector<Professor> &X, string const &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    return !(it == X.end());
}

ostream &operator<<(ostream &out, const Worker &a) {
    if (!a.name.empty()) {
        out << "Worker | " << a.name
            << " | " << a.sex
            << " | " << a.ID
            << " | " << a.birthday
            << " | " << a.address
            << " | " << a.age
            << " | " << a.worker_number
            << " | " << a.appartment
            << " | " << a.dailyHours
            << " | " << a.salary
            << " | " << a.job << endl;
    }
    return out;
}
istream &operator>>(istream &in, Worker &a) {
    in.ignore(3, '|');
    in >> a.name;
    in.ignore(2, '|');
    in >> a.sex;
    in.ignore(2, '|');
    in >> a.ID;
    in.ignore(2, '|');
    in >> a.birthday;
    in.ignore(2, '|');

    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');

    in >> a.age;
    in.ignore(2, '|');
    in >> a.worker_number;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.dailyHours;
    in.ignore(2, '|');
    in >> a.salary;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.job, '|');
    in.ignore(2, ' ');
    return in;
}
void Worker::print(vector<Worker> &X, string const &work_num) {
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
             << "\nDaily Working Hours: " << it->dailyHours
             << "\nSalary: " << it->salary
             << "\nJob: " << it->job;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.get();
    } else {
        cout << "\nThere's no worker with number\n" << work_num << endl;
    }
}
void Worker::change(vector<Worker> &X, string const &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A worker with number " << work_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        X.erase(it);
        Worker anewone;
        X.push_back(anewone);
    }
}
bool Worker::lookup(vector<Worker> &X, string const &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });

    return !(it == X.end());
}