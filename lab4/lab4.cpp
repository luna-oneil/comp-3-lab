#include <iostream>
#include <string>
using namespace std;
// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****
// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.
class Month {
    friend class Date;
    friend ostream& operator<< (ostream&, Month);

    private:
        enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

        Month() : _month(Jan) {} // default constructor
        Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor

        void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions

        void setMonth(int im) { _month = static_cast<EMonth>(im); }
/* Private helper member functions */
        EMonth StringToEMonth(string);

        int MonthToInt() { return static_cast<int>(_month); }

        string MonthToString();
        string MonthToString2();
        EMonth _month;
};

/* Definitions of helper member functions for class Month */
Month::EMonth Month::StringToEMonth(string m) {
    if (m == "Jan") return Jan;
    else if (m == "Feb") return Feb;
    else if (m == "Mar") return Mar;
    else if (m == "Apr") return Apr;
    else if (m == "May") return May;
    else if (m == "Jun") return Jun;
    else if (m == "Jul") return Jul;
    else if (m == "Aug") return Aug;
    else if (m == "Sep") return Sep;
    else if (m == "Oct") return Oct;
    else if (m == "Nov") return Nov;
    else if (m == "Dec") return Dec;
    else {
        cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
        exit(1);
    }
}

string Month::MonthToString() {
    switch (_month) {
    case Jan: return "Jan";
    case Feb: return "Feb";
    case Mar: return "Mar";
    case Apr: return "Apr";
    case May: return "May";
    case Jun: return "Jun";
    case Jul: return "Jul";
    case Aug: return "Aug";
    case Sep: return "Sep";
    case Oct: return "Oct";
    case Nov: return "Nov";
    case Dec: return "Dec";
    default:
        cerr << "MonthToString: invalid input month \'" << _month <<
        "\'\n";
        exit(1);
    }
}

string Month::MonthToString2() {
    switch (_month) {
    case Jan: return "January";
    case Feb: return "February";
    case Mar: return "March";
    case Apr: return "April";
    case May: return "May";
    case Jun: return "June";
    case Jul: return "July";
    case Aug: return "August";
    case Sep: return "September";
    case Oct: return "October";
    case Nov: return "November";
    case Dec: return "December";
    default:
        cerr << "MonthToString: invalid input month \'" << _month <<
        "\'\n";
        exit(1);
    }
}

/* Definition of friend function operator<< */
ostream& operator<< (ostream& out, Month m) {
    out << m.MonthToString2();
    return out;
}

class Date {
    public:
        // constructors
        Date() : _month(1), _day(1), _year(2018) {} // default constructor
        Date(int month, int day, int year) : _month(month), _day(day), _year(year) {} // value constructor
        Date(int day, string month, int year);
        Date(string month);

        void changeMonth(int month);

        void outputDateAsString(ostream &out);
        void outputDateAsInt(ostream &out);

        friend ostream &operator<<(ostream &out, Date date);

        // Pre-increment operator
        Date &operator++() {
            ++_year;
            return *this;
        }

    private:
        int _day;
        Month _month;
        int _year;
};

// constructor which takes day and year as int and month as string (e.g. "Dec")
Date::Date(int day, string month, int year) : _day(day), _year(year) {
    _month.setMonth(month);
}

// constructor which takes month as string and sets day and year to 1 and 1970
Date::Date(string month) : _day(1), _year(1970) {
    _month.setMonth(month);
}

// change the month to a given month represented as an integer 1-12
void Date::changeMonth(int month) {
    if (month < 1 || month > 12) {
        cerr << "\"" << month << "\" is not a valid month. Only values 1-12 are valid" << endl;
        exit(1);
    }
    _month.setMonth(month);
}

// writes the current date in a "Dec 31, 2018" format
void Date::outputDateAsString(ostream &out) {
    out << _month.MonthToString() << " " << _day << ", " << _year;
}

// writes the current date in a "12/31/2018" format
void Date::outputDateAsInt(ostream &out) {
    out << _month.MonthToInt() << "/" << _day << "/" << _year;
}

// friend non-member function for Date class operator
ostream &operator<<(ostream &out, Date date) {
    out << date._month << " " << date._day << ", " << date._year;
    return out;
}

int main() {
    // Test the default and value constructors
    Date d1;
    Date d2(2, 1, 2018);
    Date d3(1, "Mar", 2018);

    cout << "With the following declarations:" << endl;
    cout << "   Date d1, d2(2, 1, 2018), d3(\"Mar\", 1, 2018);" << endl;
    cout << "...and using operator<< :" << endl;

    // Test the overloaded << operator
    cout << "d1 == " << d1 << endl;
    cout << "d2 == " << d2 << endl;
    cout << "d3 == " << d3 << endl;
    cout << endl;

    // Test the changeMonth function
    d3.changeMonth(4);
    cout << "After d3.changeMonth(4):" << endl;
    cout << "d3 == " << d3 << endl;
    cout << endl;

    // Test the integer month constructor
    Date d4(12, 31, 2018);
    cout << "With the following declaration:" << endl;
    cout << "   Date d4(12, 31, 2018);" << endl;

    // Test outputDateAsInt
    cout << "d4.outputDateAsInt(cout) outputs ";
    d4.outputDateAsInt(cout);
    cout << endl;

    // Test outputDateAsString.
    cout << "d4.outputDateAsString(cout) outputs ";
    d4.outputDateAsString(cout);
    cout << endl;

    // Test the pre-increment operator
    ++d4;
    cout << endl;
    cout << "++d4 == " << d4 << endl;

    return 0;
}