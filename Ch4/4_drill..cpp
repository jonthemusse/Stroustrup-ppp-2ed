// drill4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "../std_lib_facilities.h"

int main()
{
	constexpr double cm_per_inch = 2.54;
	constexpr double cm_per_meter = 100.0;
	constexpr double feet_per_inch = 12.0;

	string unit = " ";
	double value;
	double meters;
	int count = 0;
	double sum = 0.0;

	constexpr double double_min = std::numeric_limits<double>::lowest();
	constexpr double double_max = std::numeric_limits<double>::max();

	double min = double_max; // Making sure the value is intialised to something that will be replaced in all cases.
	double max = double_min; // What a hack

	vector<double> inputs; // all inputs stored in meters
	
	// Do we need to have a first input before the first loop? Rethink the boolean evaluation on the while header 
	cout << "Welcome. Enter a positive value followed by unit (m cm ft, in), end with | :";

	while (cin >> value >> unit)
	{
		cout << "The value is: " << value << " and the unit is: " << unit << endl;

		if (unit == "cm")
		{
			cout << " you chose centimeters\n";

			meters = value / cm_per_meter;
		}
		else if (unit == "ft")
		{
			cout << " you chose feet\n";
			meters = value * feet_per_inch * cm_per_inch / cm_per_meter;
		}
		else if (unit == "in")
		{
			cout << " you chose inches\n";
			meters = value * cm_per_inch / cm_per_meter;

		}
		else if (unit == "m")
		{
			cout << " you chose meters\n";
			meters = value;
		}
		else // OK, we didn't find our acceptable units, skip this loop and start again.
		{
			cout << " you chose NONSENSE\n";
			cout << "Enter another value followed by unit (m cm ft, in), end with <enter> or entering 0: ";
			continue;
		}

		// Do the min max value saving and total normalised sum math now

		if (value < min) min = value;
		if (value > max) max = value;
		sum += meters;
		inputs.push_back(meters);
		++count;

		cout << "Enter another value followed by unit (m cm ft, in), end with <enter> or entering 0: ";

	}
	cout << "count:\t" << count << endl;
	cout << "min:\t" << min << endl;
	cout << "max:\t" << max << endl;
	cout << "sum:\t" << sum << endl;

	cout << "print out the input history in meters sorted\n";
	sort(inputs);
	for (double m : inputs) {
		cout << m << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
