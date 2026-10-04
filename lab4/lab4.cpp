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
    friend ostream& operator<< (ostream&, Month);

    public:
        // constructors
        Date() : _month(Jan), _year(2018) {} // default constructor
        Date(int im, int year) : _month( static_cast<EMonth>(im)), _year(year) {} // value constructor
        Date(int day, string month_string, int year);
        Date(string month_string);

        void changeMonth(int month_num);

        void outputDateAsString(ostream &out);
        void outputDateAsInt(ostream &out);

    private:
        int _day;
        Month _month;
        int _year;
};

// constructor which takes day and year as int and month as string (e.g. "Dec")
Date::Date(int day, string month_string, int year) : _day(day), _year(year) {
    _month.setMonth(month_string);
}

// constructor which takes month as string and sets day and year to 1 and 1970
Date::Date(string month_string) : _day(1), _year(1970) {
    _month.setMonth(month_string);
}

// change the month to a given month represented as an integer 1-12
void Date::changeMonth(int month_num) {
    if (month_num < 1 || month_num > 12) {
        cerr << "\"" << month_num << "\" is not a valid month. Only values 1-12 are valid" << endl;
        exit(1);
    }
    _month.setMonth(month_num);
}

// writes the current date in a "Dec 31, 2018" format
void Date::outputDateAsString(ostream &out) {
    out << _month.MonthToString() << " " << _day << ", " << _year;
}

// writes the current date in a "12/31/2018" format
void Date::outputDateAsInt(ostream &out) {
    out << _month.MonthToInt() << "/" << _day << "/" << _year;
}