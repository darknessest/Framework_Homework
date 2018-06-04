#include "records.h"

void ClearScreen() {
//    system("cls");       //uncomment for windows
    printf("\033[H\033[J");
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

void initialization(vector<Student> &list1, vector<Professor> &list2, vector<Worker> &list3) {
    cout << "Enter the filename of database (e.g. \"in.txt\") if u have it already: ";

    string database_name;
    getline(cin, database_name);

    fstream XX(database_name, ios::in);
    cout << "initialization is in progress...\n";
    if (!XX) {
        cerr << "couldn't open " << database_name << "\nPress enter to proceed\n";
        cin.get();
    }

    string temporary;
    while (XX) {

        XX >> temporary;
        if (temporary == "Student") {
            Student input_temporary("", 'a', "", "", "", 0, "", "", "", 0);
            XX >> input_temporary;
            list1.push_back(input_temporary);
        }

        if (temporary == "Professor") {
            Professor input_temporary("", 'a', "", "", "", 0, "", "", 0, 0, "", "", 0);
            XX >> input_temporary;
            list2.push_back(input_temporary);
        }
        if (temporary == "Worker") {
            Worker input_temporary("", 'a', "", "", "", 0, "", "", 0, 0, "");
            XX >> input_temporary;
            list3.push_back(input_temporary);
        }
    }

    XX.close();
    ClearScreen();
}
void fin_out(const vector<Student> &list1, const vector<Professor> &list2,
             const vector<Worker> &list3) {
    cout << "Enter the filename of output database (e.g. \"out.txt\"): ";
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
//    std::ios::sync_with_stdio(false);       //improves I/O speed, because doesn't make sync between c++ and c-style I/O
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
                    cin.ignore();
                    goto STUDENT_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Student number of a student you want to print: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::print(students, temp_studnum);
                    cin.ignore();
                    goto STUDENT_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Student number of a student record you want to change: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::change(students, temp_studnum);
                    cin.ignore();
                    goto STUDENT_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a record you want to delete: \n";
                    Student to_be_deleted;
                    auto it = find(students.begin(), students.end(), to_be_deleted);
                    if (it != students.end()) {
                        students.erase(it);
                        cout << "\nRecord has been succesfully deleted.\nPress enter to proceed\n";
                        cin.ignore();
                    } else {
                        cout << "\nNo record with such information were found.\nPress enter to proceed\n";
                        cin.ignore();
                    }
                    goto STUDENT_SCREEN;
                }
                case 5: {   //Find
                    cout << "Student number of a student you want to find: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    if (Student::lookup(students, temp_studnum)) {
                        cin.ignore();
                        cout << "\nThere's a student with student number " << temp_studnum
                             << "\nPress enter to proceed";
                        cin.ignore();
                    } else {
                        cin.ignore();
                        cout << "\nThere's no student with student number " << temp_studnum
                             << "\nPress enter to proceed";
                        cin.ignore();
                    }
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
                    cin.ignore();

                    goto PROFESSOR_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a professor you want to print: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Professor::print(professors, temp_worknum);
                    cin.ignore();
                    goto PROFESSOR_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a professor record you want to change: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Professor::change(professors, temp_worknum);
                    cin.ignore();
                    goto PROFESSOR_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Professor to_be_deleted;
                    auto it = find(professors.begin(), professors.end(), to_be_deleted);
                    if (it != professors.end()) {
                        professors.erase(it);
                        cin.ignore();
                        cout << "Record has been succesfully deleted.\nPress enter to proceed";
                        cin.ignore();
                    } else {
                        cin.ignore();
                        cout << "No record with such information were found.\nPress enter to proceed";
                        cin.ignore();
                    }
                    goto PROFESSOR_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a professor you want to find: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    if (Professor::lookup(professors, temp_worknum)) {
                        cin.ignore();
                        cout << "\nThere's a professor with such worker number.\nPress enter to proceed";
                        cin.ignore();

                    } else {
                        cin.ignore();
                        cout << "\nThere's no professor with such worker number\nPress enter to proceed";
                        cin.ignore();
                    }
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
                    cin.ignore();

                    goto WORKER_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a worker you want to print: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Worker::print(workers, temp_worknum);
                    cin.ignore();

                    goto WORKER_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a worker record you want to change: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    Worker::change(workers, temp_worknum);
                    cin.ignore();
                    goto WORKER_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Worker to_be_deleted;
                    auto it = find(workers.begin(), workers.end(), to_be_deleted);
                    if (it != workers.end()) {
                        workers.erase(it);
                        cout << "\nRecord has been succesfully deleted.\nPress enter to proceed";
                        cin.ignore();
                    } else {
                        cout << "\nNo record with such information were found.\nPress enter to proceed";
                        cin.ignore();
                    }
                    goto WORKER_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a worker you want to find: ";
                    string temp_worknum;
                    cin >> temp_worknum;
                    if (Worker::lookup(workers, temp_worknum)) {
                        cin.ignore();
                        cout << "\nThere's a worker with such worker number.\nPress enter to proceed";
                        cin.ignore();
                    } else {
                        cin.ignore();
                        cout << "\nThere's no worker with such worker number.\nPress enter to proceed";
                        cin.ignore();
                    }
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


