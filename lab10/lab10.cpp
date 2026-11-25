#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

using namespace std;

const int IGNORE_SIZE = 256;
const double MAX_DOUBLE = numeric_limits<double>::max();

class input_exception : public exception {
public:
	explicit input_exception(string message) : error_message(move(message)) {}
	const char* what() const noexcept override { return error_message.c_str(); }

private:
	string error_message;
};

template<typename T>
T checkInput(T lower, T upper, const string& message) {
	T in;
	if (!(cin >> in) || in < lower || in > upper) {
		cin.clear();
		cin.ignore(IGNORE_SIZE, '\n');
		throw input_exception(message);
	}
	return in;
}

template<typename T>
T promptInput(const string& prompt, T lower, T upper, const string& message) {
	while (true) {
		cout << prompt;
		try {
			return checkInput(lower, upper, message);
		} catch (const input_exception& e) {
			cout << e.what() << '\n';
		}
	}
}

class Mass {
public:
	void setMassAvoirdupoisPounds( double ap ) { drams = ap*dramsPerAvoirdupoisPound; }
	void setMassTroyPounds( double tp ) { drams = tp*dramsPerTroyPound; }
	void setMassMetricGrams( double mg ) { drams = mg/metricGramsPerDram; }
	double getMassAvoirdupoisPounds() { return drams/dramsPerAvoirdupoisPound; }
	double getMassTroyPounds() { return drams/dramsPerTroyPound; }
	double getMassMetricGrams() { return drams*metricGramsPerDram; }
private:
	double drams;
	const int dramsPerAvoirdupoisPound = 256;
	const int dramsPerTroyPound = 96;
	const double metricGramsPerDram = 1.7718451953125;
};

int main() {
	Mass m;
	const string menuPrompt = "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
	const string massError = "That's not a positive number!";

	while (true) {
		int choice = promptInput(menuPrompt, 0, 3, "That's not a number between 0 and 3!");

		if (choice == 0) {
			cout << "Thanks for using the mass conversion program!\n";
			break;
		}

		switch (choice) {
			case 1:
				m.setMassAvoirdupoisPounds(
					promptInput("Please enter a mass in Avoirdupois pounds: ", 0.0, MAX_DOUBLE, massError));
				break;
			case 2:
				m.setMassTroyPounds(
					promptInput("Please enter a mass in Troy pounds: ", 0.0, MAX_DOUBLE, massError));
				break;
			case 3:
				m.setMassMetricGrams(
					promptInput("Please enter a mass in grams: ", 0.0, MAX_DOUBLE, massError));
				break;
		}

		cout << "Mass in Avoirdupois pounds is " << m.getMassAvoirdupoisPounds() << '\n'
			 << "Mass in Troy pounds is " << m.getMassTroyPounds() << '\n'
			 << "Mass in grams is " << m.getMassMetricGrams() << "\n\n";
	}

	return 0;
}