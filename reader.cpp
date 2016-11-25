#include<iostream>
#include<string>
#include<ctime>
#include<sstream>
#include<fstream>

using namespace std;

string begin = "^";
string end = "/";

string opening();
void error_check(string& input);
string parse_name(string& input);
string date();

int main() {
    string input = opening();
    void error_check(input);
    while (input != "exit") {

        //Parse out the string for name
        string name = parse_name(input);

        //Tell user their name
        cout << endl << name << endl;

        //Find out the current date
        string date = date();

        //Find time of swipe in
        string time = time();

        //make date into the filename for output file
        date.append(".csv");

        //write name and time to output file
        ofstream out;
        out.open(date, ios_base::app);
        out << name << "," << time << endl;
        out.close();

        //start process over
        input = opening();
        error_check(input);
    }
    return 0;
}

string opening() {
	cout << "**************************" << endl;
    cout << "*****     Hello!     *****" << endl;
    cout << "**************************" << endl << endl;
    cout << "Swipe your Mcard or type 'exit': " << endl;
    string input;
    getline(cin, input);
    return input;
}

void error_check(string& input) {
	while (input.find(begin) == string::npos || input.find(end) == string::npos) {
        if (input == "exit") {
            break;
        }
        cout << endl << "*******************************" << endl;
        cout << "***Invalid input, try again:***" << endl;
        cout << "*******************************" << endl;
        getline(cin, input);
    }
   	return;
}

string parse_name(string& input) {
	string name = input.substr(input.find(begin) + 1, input.find(end) - input.find(begin) - 1);
	return name;
}

string date() {
	string date;
    stringstream ss;
    time_t t = time(0);
    struct tm * now = localtime(&t);
    ss << (now->tm_mon + 1) << "-"
    	<< now->tm_mday << "-"
    	<< (now->tm_year + 1900)
    	<< endl;
    ss >> date;
    return date;
}

string time() {
	string time;
    string am_pm;
    int hour = now->tm_hour % 12;
    int min = now->tm_min;
    string min_print;
    if(min < 10) {
      	stringstream ss;
       	ss << "0" << min;
       	ss >> min_print;
    }
    if (hour == 0) {
        hour = 12;
    }
    if (now->tm_hour >= 12) {
        am_pm = "pm";
    }
    else {
    	am_pm = "am";
    }

    //make a string of the time
    stringstream ss;
    ss << hour << ":" << min_print << am_pm << endl;
    ss >> time;

    //tell user time they clocked in and make a noise
    cout << time << '\a' << endl << endl;
    return time;
}