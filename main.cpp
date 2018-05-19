#include <iostream>
#include <algorithm>
#include <deque>
#include <fstream>
using namespace std;

void ClearScreen()
{
    cout << string(100, '\n');
}

class Record
{
protected:
    string name;
    char sex;
    string ID;
    string birthday;    //pairs, or other 3 volumed
    string address;
    unsigned short age;
public:
    Record()
    {

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
class Student: protected Record
{
    string number;
    string dormitory;   //pairs<string name, int number>
    string major;
    unsigned short year;    //1 - 4
public:
    Student()
    {
        cout << "Please enter Name: ";
        cin >> name;
        cout << "\tSex: ";
        cin >> sex;
        cout << "\tID: ";
        cin >> ID;
        cout << "\tBirthday: ";
        cin >> birthday;
        cout << "\tAddress: ";
        cin >> address;
        cout << "\tAge: ";
        cin >> age;
        cout << "\tStudent Number: ";
        cin >> number;
        cout << "\tDormitory Number: ";
        cin >> dormitory;
        cout << "\tMajor: ";
        cin >> major;
        cout << "\tYear: ";
        cin >> year;
        cout << "Press any key to continue...\n";
    }

    Student(const string a, const char &b, const string c,
            const string d, const string e, const unsigned short &f,
            const string g, const string h, const string j,
            const unsigned short &k)
    {
        name = a;
        sex = b;
        ID = c;
        birthday = d;
        address = e;
        age = f;
        number = g;
        dormitory = h;
        major = j;
        year = k;
    }
    /*inline*/bool operator==(Student const &a)
    {
        return (a.name == name
            && a.sex == sex
            && a.ID == ID
            && a.birthday == birthday
            && a.address == address
            && a.age == age
            && a.number == number
            && a.dormitory == dormitory
            && a.major == major);
    }
//    Student(string stud_num){
//        number = stud_num ;
//    }
//    bool operator== (const Student &a, const Student &b)
//    {
//        return a.number == b.number;
//    }
    static void print(deque<Student> X, const string stud_num);

    static void change(deque<Student> X, string stud_num);

    static bool lookup(deque<Student> X, const string stud_num);
};
void Student::print(deque<Student> X, const string stud_num)
{
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool
    {
        return t.number == stud_num;
    });
    if (it != X.end()) {
        cout << "Name: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nStudent Number: " << it->number
             << "\nDormitory Number: " << it->dormitory
             << "\nMajor: " << it->major
             << "\nPress any key to continue...\n";
    }

}
void Student::change(deque<Student> X, const string stud_num)
{
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool
    {
        return t.number == stud_num;
    });
    if (it == X.end())
        cout << "There's no record with such number.\n";
    else {
        cout << "A record with number " << stud_num << " has been succefully found.\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        cin >> it->name;                            //add feature to leave the same info after pressing enter
        cout << "\tSex: ";
        cin >> it->sex;
        cout << "\tID: ";
        cin >> it->ID;
        cout << "\tBirthday: ";
        cin >> it->birthday;
        cout << "\tAddress: ";
        cin >> it->address;
        cout << "\tAge: ";
        cin >> it->age;
        cout << "\tStudent Number: ";
        cin >> it->number;
        cout << "\tDormitory Number: ";
        cin >> it->dormitory;
        cout << "\tMajor: ";
        cin >> it->major;
        cout << "\tYear: ";
        cin >> it->year;
        cout << "Press any key to continue...\n";
    }
}
bool Student::lookup(deque<Student> X, const string stud_num)
{
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool
    {
        return t.number == stud_num;
    });
//    if (it == X.end())
//        return false;
//    else
//        return true;
    return it == X.end() ? false : true;
}
class Staff: protected Record
{
protected:
    unsigned work_number;
    string appartment;
    unsigned dailyHours;
    unsigned salary;

};
class Profesor: protected Staff
{
protected:
    string givenLectures;
    string research;
    unsigned numOfPostgrads;
};
class Worker: protected Staff
{
protected:
    string job;
//public:
};

//int chooseTimes()
//{
//    cout << "1) Continuous adding\n"
//         << "2) Add just one record\n";
//}
void first_screen()
{
    cout << "Welcome !\n" << "Choose the section:\n"
         << "1) Student\n"
         << "2) Professor\n"
         << "3) Worker\n"
         << "4) Exit\n";
//        << "4) Staff record\n"
//        << "5) Make a regular person record\n";
}
void second_screen()
{
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

void initialization(ifstream &XX, deque<Student> list)
{
    string temporary;
    getline(XX, temporary, '|');
    if (temporary == "Student") {

        string temp_name, temp_id, temp_birthday, temp_address, temp_number, temp_dorm, temp_major;
        char temp_sex;
        unsigned short temp_age, temp_year;

        getline(XX, temp_name, '|');    //name
//        getline(XX, temp_sex, '|');
        XX >> temp_sex;
        getline(XX, temp_id, '|');
        getline(XX, temp_birthday, '|');
//        getline(XX, temp_age, '|');
        XX >> temp_age;
        getline(XX, temp_number, '|');
        getline(XX, temp_dorm, '|');
        getline(XX, temp_major, '|');
        XX >> temp_year;
        Student input_temporary(temp_name,
                                temp_sex,
                                temp_id,
                                temp_birthday,
                                temp_address,
                                temp_age,
                                temp_number,
                                temp_dorm,
                                temp_major,
                                temp_year);
        list.push_back(input_temporary);
    }

}
int main()
{
    short temp = 0;
    ifstream fs;   //add a checking system whether
    //file has some records already
    //and make an initialization func
    fs.open("/Users/Alexey/ClionProjects/cpp17shiyan/out.txt");
    if (!fs.is_open())
        cerr << ("couldn't open file");

    deque<Student> students;
    deque<Profesor> professors;
    deque<Worker> workers;

//    initialization(fs, students);

    FIRST_SCREEN:

    first_screen();
    cin >> temp;
//    ClearScreen();
    switch (temp) {
    case 1:
        //add screen cleaning

    STUDENT_SCREEN:
        second_screen();
        cin >> temp;
        switch (temp) {
            //add screen cleaning
        case 1: {     //Adding record
            Student temp_inp;       //stud_num recur check
            students.push_back(temp_inp);
            break;
        }
        case 2: {   //Printing
            cout << "Student number of a student you want to print: ";
            string temp_studnum;
            cin >> temp_studnum;
            Student::print(students, temp_studnum); //print is static, somewhy
            break;
        }
        case 3: {   //Changing
            cout << "Student number of a student record you want to change: ";
            string temp_studnum;
            cin >> temp_studnum;
            Student::change(students, temp_studnum);    //change is static, somewhy
            break;
        }
        case 4: {   //Deleting
            cout << "Enter information about a record you want to delete: \n";
            Student to_be_deleted;
            auto it = find(students.begin(), students.end(), to_be_deleted);
            if (it != students.end()) {
                students.erase(it);
                cout << "Record has been succesfully deleted.\n";
            }
            else
                cout << "No record with such information were found.\n";
            break;
        }
        case 5: {   //Find
            cout << "Student number of a student you want to find: ";
            string temp_studnum;
            cin >> temp_studnum;
            if (Student::lookup(students, temp_studnum))
                cout << "There's a student with such student number.\n";
            break;
        }
        case 6: {
            break;
        }
        default:
            cerr << "Wrong Input\n";
            break;
        }
        //clear_screen()
        goto STUDENT_SCREEN;
        //
    case 2: {

        break;
    }
    case 3: {
        break;
    }
    case 4: {
        fs.close();
        return 0;
    }
    default: {
        cerr << "Wrong Input\n";
        break;
    }
    }

}

