//"uwu" Text Converter
//aka the "uwu" convewtew
//aka the "uwu"fier
//By Renzo Pereyra

//A fun little exercise in converting characters of a file...
//and saving them in a new file.

#include<iostream>
#include<fstream>
using namespace std;

void setIOFiles(string &input, string &output, string txtExtension)
{
	//gets filename from user
	cout << "Enter file you wish to open: ";
	cin >> input;
	
	//checks if ".txt" is included in string, else appends it to end of string
	if (input.find(txtExtension) != input.npos)
	{
		//does .txt exist here? YES
		cout << "Successfully read input file!" << endl;
	}
	else 
	{
		//does .txt exist here? NO
		cout << "Input file set without extension." << endl;
		cout << "Adding extension to input file." << endl;
		input = input + ".txt";
		cout << endl;
	}

	cout << "Enter filename you wish to save: ";
	cin >> output;
	//checks if ".txt" is included in string, else appends it to end of string
	if (output.find(txtExtension) != output.npos)
	{
		cout << "Successfully read output file!" << endl;
	}
	else 
	{
		cout << "Output file set without extension." << endl;
		cout << "Adding extension to output file." << endl;
		output = output + ".txt";
		cout << endl;
	}
}

int main()
{
	ifstream in;
	ofstream out;
	string inputName;
	string outputName;
	string textString;
	string txtExtension = ".txt";

	setIOFiles(inputName, outputName, txtExtension);

	//flag to see if values carry over from "void" function
	cout << "New value of input is: " << inputName << endl;
	cout << "New value of output is: " << outputName << endl;

	//open the file
	in.open(inputName.c_str());
	out.open(outputName.c_str());

	if (!in.is_open())
	{
		//Displays error message
		cout << "Error opening file!" << endl;
	}
	else if (in.is_open())
	{
		out << "============================" << endl;
		out << "Welcome to the UWU Converter!" << endl;
		out << "----------------------------" << endl;
		//present input file
		out << "Below is your input file: " << endl;
		out << "============================" << endl;
		out << endl;

		//prints original text file
		while (!in.eof())
		{
			getline(in, textString);
			out << textString << endl; //prints to file
		}

		in.clear(); //clears file's "end-of-file" flag
		in.seekg(0L, ios::beg); //sets read position to beginning of file
		
		//prints UWU version of text file
		while (!in.eof())
		{
			getline(in, textString);
			for(size_t i=0; i<textString.length(); i++)
			{
				if (textString[i] == 'u')
				{
					i++;
					//flags have been commented out
					//cout << "FOUND AN UWU CANDIDATE!" << endl;
					textString.insert(i, "wu"); //changes each "u" to "uw"
					i++;
				}
				else if (textString[i] == 'l')
				{
					//flags have been commented out
					//cout << "FOUND AN L CANDIDATE!" << endl;
					textString[i] = 'w'; //replace "l" with "w"
				}
				else if (textString[i] == 'r')
				{
					//flags have been commented out
					//cout << "FOUND AN R CANDIDATE!" << endl;
					textString[i] = 'w'; //replace "r" with "w"
				}
			}
			cout << textString << endl;
		}
	}
	return 0;
}