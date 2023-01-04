//"uwu" Text Converter
//By Renzo Pereyra

//A fun little exercise in converting characters of a file
//and saving them in a new file

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

		while (!in.eof())
		{
			getline(in, textString);
			cout << textString << endl; //prints to console
			out << textString << endl; //prints to file
		}
		in.clear(); //clears file's "end-of-file" flag
		in.seekg(0L, ios::beg); //sets read position to beginning of file
		while (!in.eof())
		{
			getline(in, textString);
			string line[textString.length()];
			
			for(size_t i=0; i<textString.length(); i++)
			{
				line[i] = textString[i];
				cout << line[i] << endl;
				if (line[i] == "u")
				{
					cout << "FOUND AN UWU LETTER" << endl;
				}
			}
		}

		//present UWU-fied file
		//...
	}
	return 0;
}