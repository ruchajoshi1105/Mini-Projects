#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <cstdlib>

using namespace std;

const string BOOK_FILE = "book.dat";
const string STUDENT_FILE = "student.dat";

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

class Book {
private:
    string bno, bname, aname;

public:
    void createBook() {
        cout << "\nNEW BOOK ENTRY...\n";
        cout << "Enter Book No.: ";
        cin >> bno;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Book Name: ";
        getline(cin, bname);
        cout << "Enter Author Name: ";
        getline(cin, aname);
        cout << "\nBook Created Successfully.\n";
    }

    void showBook() const {
        cout << "\nBook Number : " << bno
             << "\nBook Name   : " << bname
             << "\nAuthor Name : " << aname << '\n';
    }

    void modifyBook() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter New Book Name: ";
        getline(cin, bname);
        cout << "Enter New Author Name: ";
        getline(cin, aname);
    }

    string getBno() const { return bno; }
    string getBname() const { return bname; }
    string getAname() const { return aname; }

    void setData(const string& no, const string& name, const string& author) {
        bno = no;
        bname = name;
        aname = author;
    }

    void report() const {
        cout << left << setw(12) << bno
             << setw(30) << bname
             << setw(25) << aname << '\n';
    }
};

class Student {
private:
    string admno, name, stbno;
    int token = 0;

public:
    void createStudent() {
        cout << "\nNEW STUDENT ENTRY...\n";
        cout << "Enter Admission No.: ";
        cin >> admno;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Student Name: ";
        getline(cin, name);
        token = 0;
        stbno.clear();
        cout << "\nStudent Record Created Successfully.\n";
    }

    void showStudent() const {
        cout << "\nAdmission Number : " << admno
             << "\nStudent Name     : " << name
             << "\nNo. of Books     : " << token;
        if (token == 1)
            cout << "\nBook Number      : " << stbno;
        cout << '\n';
    }

    void modifyStudent() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter New Student Name: ";
        getline(cin, name);
    }

    string getAdmno() const { return admno; }
    string getName() const { return name; }
    string getStbno() const { return stbno; }
    int getToken() const { return token; }

    void addToken() { token = 1; }
    void resetToken() { token = 0; stbno.clear(); }
    void setStbno(const string& bookNo) { stbno = bookNo; }

    void setData(const string& admission, const string& studentName,
                 const string& bookNo, int bookToken) {
        admno = admission;
        name = studentName;
        stbno = bookNo;
        token = bookToken;
    }

    void report() const {
        cout << left << setw(15) << admno
             << setw(30) << name
             << setw(10) << token << '\n';
    }
};

// ---------------- BOOK FILE FUNCTIONS ----------------

vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file(BOOK_FILE);
    if (!file) return books;

    string no, name, author;
    while (getline(file, no, '\t') &&
           getline(file, name, '\t') &&
           getline(file, author)) {
        Book b;
        b.setData(no, name, author);
        books.push_back(b);
    }
    return books;
}

bool saveBooks(const vector<Book>& books) {
    ofstream file(BOOK_FILE, ios::trunc);
    if (!file) return false;

    for (const Book& b : books)
        file << b.getBno() << '\t'
             << b.getBname() << '\t'
             << b.getAname() << '\n';

    return true;
}

// ---------------- STUDENT FILE FUNCTIONS ----------------

vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file(STUDENT_FILE);
    if (!file) return students;

    string admno, name, stbno, tokenText;
    while (getline(file, admno, '\t') &&
           getline(file, name, '\t') &&
           getline(file, stbno, '\t') &&
           getline(file, tokenText)) {
        try {
            int token = stoi(tokenText);
            Student s;
            s.setData(admno, name, stbno, token);
            students.push_back(s);
        } catch (...) {
            // Ignore damaged records.
        }
    }
    return students;
}

bool saveStudents(const vector<Student>& students) {
    ofstream file(STUDENT_FILE, ios::trunc);
    if (!file) return false;

    for (const Student& s : students)
        file << s.getAdmno() << '\t'
             << s.getName() << '\t'
             << s.getStbno() << '\t'
             << s.getToken() << '\n';

    return true;
}

// ---------------- BOOK OPERATIONS ----------------

void writeBook() {
    char ch;
    do {
        clearScreen();

        vector<Book> books = loadBooks();
        Book b;
        b.createBook();

        bool duplicate = false;
        for (const Book& oldBook : books) {
            if (oldBook.getBno() == b.getBno()) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            cout << "\nBook number already exists.\n";
        } else {
            books.push_back(b);
            if (saveBooks(books))
                cout << "\nBook record saved.\n";
            else
                cout << "\nError: Unable to save book record.\n";
        }

        cout << "\nDo you want to add more records? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void displayAllBooks() {
    clearScreen();
    vector<Book> books = loadBooks();

    cout << "\n================ ALL BOOK RECORDS ================\n";
    if (books.empty()) {
        cout << "\nNo book records found.\n";
        return;
    }

    cout << left << setw(12) << "Book No."
         << setw(30) << "Book Name"
         << setw(25) << "Author Name" << '\n';
    cout << string(67, '-') << '\n';

    for (const Book& b : books)
        b.report();
}

void displaySpecificBook(const string& n) {
    vector<Book> books = loadBooks();
    bool found = false;

    cout << "\nBOOK DETAILS\n";
    for (const Book& b : books) {
        if (b.getBno() == n) {
            b.showBook();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nBook does not exist.\n";
}

void searchBook() {
    string n;
    cout << "\nEnter Book Number: ";
    cin >> n;
    displaySpecificBook(n);
}

void modifyBookRecord() {
    clearScreen();

    string n;
    cout << "\nMODIFY BOOK RECORD...\n";
    cout << "Enter the Book Number: ";
    cin >> n;

    vector<Book> books = loadBooks();
    bool found = false;

    for (Book& b : books) {
        if (b.getBno() == n) {
            b.showBook();
            cout << "\nEnter the new details:\n";
            b.modifyBook();
            found = true;
            break;
        }
    }

    if (found) {
        if (saveBooks(books))
            cout << "\nRecord Updated Successfully.\n";
        else
            cout << "\nError: Unable to update record.\n";
    } else {
        cout << "\nRecord Not Found.\n";
    }
}

void deleteBookRecord() {
    clearScreen();

    string n;
    cout << "\nDELETE BOOK RECORD...\n";
    cout << "Enter Book Number: ";
    cin >> n;

    vector<Book> books = loadBooks();
    vector<Book> remaining;
    bool found = false;

    for (const Book& b : books) {
        if (b.getBno() == n)
            found = true;
        else
            remaining.push_back(b);
    }

    if (!found) {
        cout << "\nRecord Not Found.\n";
        return;
    }

    if (saveBooks(remaining))
        cout << "\nBook Deleted Successfully.\n";
    else
        cout << "\nError: Unable to delete record.\n";
}

// ---------------- STUDENT OPERATIONS ----------------

void writeStudent() {
    char ch;
    do {
        clearScreen();

        vector<Student> students = loadStudents();
        Student s;
        s.createStudent();

        bool duplicate = false;
        for (const Student& oldStudent : students) {
            if (oldStudent.getAdmno() == s.getAdmno()) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            cout << "\nAdmission number already exists.\n";
        } else {
            students.push_back(s);
            if (saveStudents(students))
                cout << "\nStudent record saved.\n";
            else
                cout << "\nError: Unable to save student record.\n";
        }

        cout << "\nDo you want to add more records? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void displayAllStudents() {
    clearScreen();
    vector<Student> students = loadStudents();

    cout << "\n================ ALL STUDENT RECORDS ================\n";
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << left << setw(15) << "Admission No."
         << setw(30) << "Student Name"
         << setw(10) << "Books" << '\n';
    cout << string(55, '-') << '\n';

    for (const Student& s : students)
        s.report();
}

void displaySpecificStudent(const string& n) {
    vector<Student> students = loadStudents();
    bool found = false;

    cout << "\nSTUDENT DETAILS\n";
    for (const Student& s : students) {
        if (s.getAdmno() == n) {
            s.showStudent();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent does not exist.\n";
}

void searchStudent() {
    string n;
    cout << "\nEnter Admission Number: ";
    cin >> n;
    displaySpecificStudent(n);
}

void modifyStudentRecord() {
    clearScreen();

    string n;
    cout << "\nMODIFY STUDENT RECORD...\n";
    cout << "Enter the Admission Number: ";
    cin >> n;

    vector<Student> students = loadStudents();
    bool found = false;

    for (Student& s : students) {
        if (s.getAdmno() == n) {
            s.showStudent();
            cout << "\nEnter the new details:\n";
            s.modifyStudent();
            found = true;
            break;
        }
    }

    if (found) {
        if (saveStudents(students))
            cout << "\nRecord Updated Successfully.\n";
        else
            cout << "\nError: Unable to update record.\n";
    } else {
        cout << "\nRecord Not Found.\n";
    }
}

void deleteStudentRecord() {
    clearScreen();

    string n;
    cout << "\nDELETE STUDENT RECORD...\n";
    cout << "Enter Admission Number: ";
    cin >> n;

    vector<Student> students = loadStudents();
    vector<Student> remaining;
    bool found = false;

    for (const Student& s : students) {
        if (s.getAdmno() == n)
            found = true;
        else
            remaining.push_back(s);
    }

    if (!found) {
        cout << "\nRecord Not Found.\n";
        return;
    }

    if (saveStudents(remaining))
        cout << "\nStudent Deleted Successfully.\n";
    else
        cout << "\nError: Unable to delete record.\n";
}

// ---------------- ISSUE / DEPOSIT ----------------

void bookIssue() {
    clearScreen();

    string admno, bno;
    cout << "\nBOOK ISSUE...\n";
    cout << "Enter the Admission Number: ";
    cin >> admno;

    vector<Student> students = loadStudents();
    vector<Book> books = loadBooks();

    int studentIndex = -1;
    for (int i = 0; i < static_cast<int>(students.size()); ++i) {
        if (students[i].getAdmno() == admno) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        cout << "\nStudent Record Not Found!\n";
        return;
    }

    if (students[studentIndex].getToken() == 1) {
        cout << "\nYou have already issued a book!\n";
        return;
    }

    cout << "Enter the Book Number: ";
    cin >> bno;

    bool bookFound = false;
    for (const Book& b : books) {
        if (b.getBno() == bno) {
            b.showBook();
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "\nBook Number does not exist!\n";
        return;
    }

    students[studentIndex].addToken();
    students[studentIndex].setStbno(bno);

    if (saveStudents(students))
        cout << "\nBook Issued Successfully!\n";
    else
        cout << "\nError: Unable to update student record.\n";
}

void bookDeposit() {
    clearScreen();

    string admno;
    int days;

    cout << "\nBOOK DEPOSIT...\n";
    cout << "Enter the Admission Number: ";
    cin >> admno;

    vector<Student> students = loadStudents();
    int studentIndex = -1;

    for (int i = 0; i < static_cast<int>(students.size()); ++i) {
        if (students[i].getAdmno() == admno) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        cout << "\nStudent Record Not Found!\n";
        return;
    }

    if (students[studentIndex].getToken() == 0) {
        cout << "\nNo book is issued to this student!\n";
        return;
    }

    string issuedBookNo = students[studentIndex].getStbno();
    vector<Book> books = loadBooks();

    for (const Book& b : books) {
        if (b.getBno() == issuedBookNo) {
            b.showBook();
            break;
        }
    }

    cout << "\nEnter the number of days after which book is being deposited: ";
    cin >> days;

    if (days > 15) {
        int fine = (days - 15) * 10;
        cout << "\nYou have to pay a fine of Rs." << fine << '\n';
    }

    students[studentIndex].resetToken();

    if (saveStudents(students))
        cout << "\nBook Deposited Successfully!\n";
    else
        cout << "\nError: Unable to update student record.\n";
}

// ---------------- ADMIN MENU ----------------

void adminMenu() {
    int choice;

    do {
        clearScreen();

        cout << "\n========== ADMINISTRATOR MENU ==========\n";
        cout << "1.  CREATE STUDENT RECORD\n";
        cout << "2.  DISPLAY ALL STUDENTS RECORD\n";
        cout << "3.  DISPLAY SPECIFIC STUDENT RECORD\n";
        cout << "4.  MODIFY STUDENT RECORD\n";
        cout << "5.  DELETE STUDENT RECORD\n";
        cout << "6.  CREATE BOOK RECORD\n";
        cout << "7.  DISPLAY ALL BOOKS\n";
        cout << "8.  DISPLAY SPECIFIC BOOK\n";
        cout << "9.  MODIFY BOOK RECORD\n";
        cout << "10. DELETE BOOK RECORD\n";
        cout << "11. BACK TO MAIN MENU\n";
        cout << "Enter Your Choice (1-11): ";

        cin >> choice;

        switch (choice) {
        case 1:
            writeStudent();
            break;
        case 2:
            displayAllStudents();
            pauseScreen();
            break;
        case 3:
            searchStudent();
            pauseScreen();
            break;
        case 4:
            modifyStudentRecord();
            pauseScreen();
            break;
        case 5:
            deleteStudentRecord();
            pauseScreen();
            break;
        case 6:
            writeBook();
            break;
        case 7:
            displayAllBooks();
            pauseScreen();
            break;
        case 8:
            searchBook();
            pauseScreen();
            break;
        case 9:
            modifyBookRecord();
            pauseScreen();
            break;
        case 10:
            deleteBookRecord();
            pauseScreen();
            break;
        case 11:
            return;
        default:
            cout << "\nInvalid Choice. Try Again.\n";
            pauseScreen();
        }
    } while (choice != 11);
}

// ---------------- MAIN ----------------

int main() {
    char choice;

    do {
        clearScreen();

        cout << "\n====================================\n";
        cout << "       LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. BOOK ISSUE\n";
        cout << "2. BOOK DEPOSIT\n";
        cout << "3. ADMINISTRATOR MENU\n";
        cout << "4. EXIT\n";
        cout << "Please Enter Your Choice (1-4): ";

        cin >> choice;

        switch (choice) {
        case '1':
            bookIssue();
            pauseScreen();
            break;
        case '2':
            bookDeposit();
            pauseScreen();
            break;
        case '3':
            adminMenu();
            break;
        case '4':
            cout << "\nExiting the program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid Choice. Try Again.\n";
            pauseScreen();
        }
    } while (choice != '4');

    return 0;
}