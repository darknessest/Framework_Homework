#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::fstream;
using std::ofstream;
using std::ios;
void spaces(string &a) {
    unsigned long i = a.length() - 1;
    for (; i >= 0; --i) {
        if (a[i] != ' ')
            break;
    }
    a.erase(i + 1, a.length());
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
        cin.ignore();
        getline(cin, name);
        cout << "             Sex: ";
        cin >> sex;
        while (sex != 'M' || sex != 'F') {
            if (sex == 'M' || sex == 'F')
                break;
            cerr << "\nWrong input. Please enter M or F\n";

            cout << "             Sex: ";
            cin >> sex;
        }
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\n--Wrong input. Please enter M or F";
            cout << "\n             Sex: ";
            cin >> sex;
            if (cin)         //potentially useless
                break;
        }
        cin.ignore();
        cout << "             ID: ";
        getline(cin, ID);
        cout << "             Birthday: ";
        getline(cin, birthday);
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
        //checking
        spaces(name);
        spaces(ID);
        spaces(birthday);
        spaces(address);

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
    string studNum;
    string dormitory;   //pairs<string name, int studNum>
    string major;
    unsigned short year;    //1 - 4
 public:
    Student() {
        cout << "             Student Number: ";
        cin.ignore();     // skips \n

        getline(cin, studNum);
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
        //checking
        spaces(studNum);
        spaces(dormitory);
        spaces(major);
        cout << "Press any key to continue...\n";
        cin.ignore();
    }
    Student(string const &a, const char &b, string const &c,
            string const &d, string const &e, const unsigned short &f,
            string const &g, string const &h, string const &j,
            const unsigned short &k) : Record(a, b, c, d, e, f) {
        studNum = g;
        dormitory = h;
        major = j;
        year = k;
    }
    inline bool operator==(Student const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.studNum == studNum
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
            cerr << "\nWrong input. Please enter a number";
            cout << "\n             Daily Working Hours: ";
            cin >> dailyHours;
        }
        cout << "             Salary: ";
        cin >> salary;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number";
            cout << "\n             Salary: ";
            cin >> salary;
        }
        //checking
        spaces(worker_number);
        spaces(appartment);
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
        if (!(T::lookup(X, a.worker_number) || B::lookup(Z, a.worker_number))) {
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
    unsigned short numOfPostgrads;
 public:
    Professor() {
        cin.ignore();
        cout << "             Field Of Teaching: ";
        getline(cin, fieldOfTeaching);
        cout << "             Research Project: ";
        getline(cin, research);
        cout << "             Number Of Postgraduate Students: ";
        cin >> numOfPostgrads;
        while (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
            cerr << "\nWrong input. Please enter a number";
            cout << "\n             Number Of Postgraduate Students: ";
            cin >> numOfPostgrads;
        }
        //checking
        spaces(fieldOfTeaching);
        spaces(research);
        cout << "Press any key to continue...\n";
        cin.ignore();
    }
    Professor(string const &a, const char &b, string const &c,
              string const &d, string const &e, const unsigned short &f,
              string const &g, string const &h, const unsigned &j,
              const unsigned &k,
              string const &l, string const &m,
              const unsigned short &n) : Staff(a, b, c, d, e, f, g, h, j, k) {
        fieldOfTeaching = l;
        research = m;
        numOfPostgrads = n;
    }
    inline bool operator==(Professor const &a) {
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
        cin.ignore();
        cout << "             Job: ";
        getline(cin, job);
        //checking
        spaces(job);
        cout << "Press any key to continue...\n";
        cin.ignore();
    }
    Worker(string const &a, const char &b, string const &c,
           string const &d, string const &e, const unsigned short &f,
           string const &g, string const &h, const unsigned short &j,
           const unsigned &k, string const &l) : Staff(a, b, c, d, e, f, g, h, j, k) {
        job = l;
    }
    inline bool operator==(Worker const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.worker_number == worker_number
            && a.appartment == appartment && a.dailyHours == dailyHours
            && a.salary == salary && a.job == job);
    }
    friend ostream &operator<<(ostream &out, const Worker &a);
    friend istream &operator>>(istream &in, Worker &a);

    static void print(vector<Worker> &X, string const &work_num);

    static void change(vector<Worker> &X, string const &work_num);

    static bool lookup(vector<Worker> &X, string const &work_num);
};

ostream &operator<<(ostream &out, const Student &a) {
    if (!a.name.empty()) {
        out << "Student | " << a.name
            << "| " << a.sex
            << " | " << a.ID
            << "| " << a.birthday
            << "| " << a.address
            << "| " << a.age
            << " | " << a.studNum
            << "| " << a.dormitory
            << "| " << a.major
            << "| " << a.year << endl;
    }
    return out;
}
istream &operator>>(istream &in, Student &a) {
    in.ignore(3, '|');
    in.ignore(2, ' ');
    getline(in, a.name, '|');
    in.ignore(2, ' ');
    in >> a.sex;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.ID, '|');
    in.ignore(2, ' ');
    getline(in, a.birthday, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.age;
    in.ignore(2, '|');
    in.ignore(2, ' ');

    getline(in, a.studNum, '|');
    in.ignore(2, ' ');

    getline(in, a.dormitory, '|');

    in.ignore(2, ' ');
    getline(in, a.major, '|');
    in >> a.year;

    return in;
}
void Student::add(vector<Student> &X, const Student &a) {
    if (!Student::lookup(X, a.studNum)) {
        X.push_back(a);
        return;
    } else
        cout << "\nRecord with student number " << a.studNum << " already exists\n";
}
void Student::print(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.studNum == stud_num;
    });
    if (it != X.end()) {
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nStudent Number: " << it->studNum
             << "\nDormitory Number: " << it->dormitory
             << "\nMajor: " << it->major
             << "\nYear: " << it->year;
//        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.ignore();
    } else {
        cout << "\nThere's no student with student number " << stud_num << "\nPress enter to proceed";
        cin.ignore();
    }
}
void Student::change(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.studNum == stud_num;
    });
    if (it == X.end()) {
        cout << "There's no student with such number.\nPress enter to proceed";
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
      return t.studNum == stud_num;
    });

    return !(it == X.end());
}

ostream &operator<<(ostream &out, const Professor &a) {
    if (!a.name.empty()) {
        out << "Professor | " << a.name
            << "| " << a.sex
            << " | " << a.ID
            << "| " << a.birthday
            << "| " << a.address
            << "| " << a.age
            << " | " << a.worker_number
            << "| " << a.appartment
            << "| " << a.dailyHours
            << " | " << a.salary
            << " | " << a.fieldOfTeaching
            << "| " << a.research
            << "| " << a.numOfPostgrads << endl;
    }
    return out;
}
istream &operator>>(istream &in, Professor &a) {
    in.ignore(3, '|');
    in.ignore(2, ' ');
    getline(in, a.name, '|');
    in.ignore(2, ' ');
    in >> a.sex;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.ID, '|');
    in.ignore(2, ' ');
    getline(in, a.birthday, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.age;

    in.ignore(2, '|');
    in.ignore(2, ' ');

    getline(in, a.worker_number, '|');
    in.ignore(2, ' ');
    getline(in, a.appartment, '|');
    in.ignore(2, ' ');
    in >> a.dailyHours;
    in.ignore(2, '|');
    in >> a.salary;

    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.fieldOfTeaching, '|');
    in.ignore(2, ' ');

    getline(in, a.research, '|');

    in >> a.numOfPostgrads;

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
//        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.ignore();
    } else {
        cout << "\nThere's no professor with number " << work_num << "\nPress enter to proceed";
        cin.ignore();
    }
}
void Professor::change(vector<Professor> &X, string const &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed";
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
            << "| " << a.sex
            << " | " << a.ID
            << "| " << a.birthday
            << "| " << a.address
            << "| " << a.age
            << " | " << a.worker_number
            << "| " << a.appartment
            << "| " << a.dailyHours
            << " | " << a.salary
            << " | " << a.job << "|" << endl;
    }
    return out;
}
istream &operator>>(istream &in, Worker &a) {
    in.ignore(3, '|');
    in.ignore(2, ' ');
    getline(in, a.name, '|');
    in.ignore(2, ' ');
    in >> a.sex;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.ID, '|');
    in.ignore(2, ' ');
    getline(in, a.birthday, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.age;

    in.ignore(2, '|');
    in.ignore(2, ' ');

    getline(in, a.worker_number, '|');
    in.ignore(2, ' ');
    getline(in, a.appartment, '|');
    in.ignore(2, ' ');
    in >> a.dailyHours;
    in.ignore(2, '|');
    in >> a.salary;

    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.job, '|');
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
//        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.ignore();
    } else {
        cout << "\nThere's no worker with number " << work_num << "\nPress enter to proceed";
        cin.ignore();
    }
}
void Worker::change(vector<Worker> &X, string const &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed";
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
