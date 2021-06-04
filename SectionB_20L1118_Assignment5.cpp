#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void InputWords(int totalWords, string words[], ifstream& infile)	// This function inputs the words to be placed from a file
{
	for (int i = 0; i < totalWords; i++)
	{
		infile >> words[i];	// Taking input of each word one by one
	}
	infile.close();
}

void SearchWords()	// Function to search words from a grid
{
	string FileNameForGrid;
	cout << "\n\nEnter file name for input of Grid:\t";
	cin >> FileNameForGrid;
	ifstream gridInput;
	gridInput.open(FileNameForGrid.c_str(), ifstream::in);
	while (!gridInput)
	{
		cout << "Error: Unable to open file. File name not correct. Enter file name for Grid:\t";
		cin >> FileNameForGrid;
		gridInput.open(FileNameForGrid.c_str(), ifstream::in);
	}
	
	string FileNameForWords;
	cout << "\nEnter file name for input of Words to be Searched:\t";
	cin >> FileNameForWords;
	ifstream wordsInput;
	wordsInput.open(FileNameForWords.c_str(), ifstream::in);
	while (!wordsInput)
	{
		cout << "Error: Unable to open file. File name not correct. \nEnter file name for Words to be Searched:\t";
		cin >> FileNameForWords;
		wordsInput.open(FileNameForWords.c_str(), ifstream::in);
	}
	
	int rows, cols;
	wordsInput >> rows;
	wordsInput >> cols;
	
	char Grid[rows][cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gridInput >> Grid[i][j];	// Input each character into grid matrix
		}
	}
	gridInput.close(); 
	
	int totalWords;
	wordsInput >> totalWords;
	string words[totalWords];
	InputWords(totalWords, words, wordsInput);
	
	string FileNameForOutput;
	cout << "\nEnter file name for output:\t";
	cin >> FileNameForOutput;
	ofstream ofile;
	ofile.open(FileNameForOutput.c_str(), ofstream::out);
	
	bool found = false;	// To keep track of a word for each direction
	bool done = false;	// To check if a word is not found in all directions
	int length;
	
	cout << "\n\n-----Results-----\n";
	for (int c = 0; c < totalWords; c++)	// Searching for all words
	{
		done = false;
		found = false;
		length = words[c].length();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)	// Traversing the grid 
			{
				if (Grid[i][j] == words[c][0])	// If the first letter of the word is found in the grid
				{
					for (int k = 1; k < length; k++)	// Then we check if the subsequent words are also present in that order
					{
						if (Grid[i][j+k] == words[c][k])	// For horizontal checking, only the column number increases
						{
							found = true;
						}
						else
						{
							found = false;
							break;	// No need to check again if any letter is missing
						}
					}
					
					if (found == true)
					{
						ofile << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << j + length - 1 << "}\n";	// Printing on file the coordinates where word is found
						cout << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << j + length - 1 << "}\n";
						done = true;
					}
		
				}
			}
			
		}
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = cols - 1; j >= 0; j--)	
			{
				if (Grid[i][j] == words[c][0])	
				{
					for (int k = 1; k < length; k++)	
					{
						if (Grid[i][j-k] == words[c][k])	
						{
							found = true;
						}
						else
						{
							found = false;
							break;	
						}
					}
					
					if (found == true)
					{
						ofile << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << j - length + 1 << "}\n";
						cout << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << j - length + 1 << "}\n";	
						done = true;
					}
		
				}
			}
			
		}
		
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)	
			{
				if (Grid[i][j] == words[c][0])	
				{
					for (int k = 1; k < length; k++)	
					{
						if (Grid[i+k][j] == words[c][k])	
						{
							found = true;
						}
						else
						{
							found = false;
							break;	
						}
					}
					
					if (found == true)
					{
						ofile << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << i + length - 1 << "}\n";
						cout << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << i + length - 1 << "}\n";	
						done = true;
					}
		
				}
			}
			
		}
		
		for (int i = 0; i < cols; i++)
		{
			for (int j = rows - 1; j >= 0; j--)	
			{
				if (Grid[i][j] == words[c][0])	
				{
					for (int k = 1; k < length; k++)	
					{
						if (Grid[i-k][j] == words[c][k])	
						{
							found = true;
						}
						else
						{
							found = false;
							break;	
						}
					}
					
					if (found == true)
					{
						ofile << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << i - length + 1 << "}\n";	
						cout << endl << words[c] << " at {" << i << ", " << j << "} {" << i << ", " << i - length + 1 << "}\n";	
						done = true;
					}
		
				}
			}
			
		}
		
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)	
			{
				if (Grid[i][j] == words[c][0])	
				{
					for (int k = 1; k < length; k++)	
					{
						if (Grid[i+k][j+k] == words[c][k])	
						{
							found = true;
						}
						else
						{
							found = false;
							break;	
						}
					}
					
					if (found == true)
					{
						ofile << endl << words[c] << " at {" << i << ", " << j << "} {" << i + length -1 << ", " << j + length - 1 << "}\n";
						cout << endl << words[c] << " at {" << i << ", " << j << "} {" << i + length -1 << ", " << j + length - 1 << "}\n";	
						done = true;
					}
		
				}
			}
			
		}
		
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)	
			{
				if (Grid[i][j] == words[c][0])	
				{
					for (int k = 1; k < length; k++)	
					{
						if (Grid[i-k][j-k] == words[c][k])	
						{
							found = true;
						}
						else
						{
							found = false;
							break;	
						}
					}
					
					if (found == true)
					{
						ofile << endl << words[c] << " at {" << i << ", " << j << "} {" << i - length + 1 << ", " << j - length + 1 << "}\n";	
						cout << endl << words[c] << " at {" << i << ", " << j << "} {" << i - length + 1 << ", " << j - length + 1 << "}\n";
						done = true;
					}
		
				}
			}
			
		}
		
		if (found == false && done == false)	// If a word is not found in any direction
		{
			ofile << endl << words[c] << " not found\n";	// Output on file
			cout << endl << words[c] << " not found\n";
		}
	}	// The process repeats for each word
	ofile.close();
}

void Sort(string words[], int total)	// Function to sort list of words according to length
{
	string temp;
	for(int i = 0; i < total - 1; i++)
	{
		for(int j = i + 1; j < total; j++)
		{
			int len1 = words[i].length();
			int len2 = words[j].length();
			
			if(len2 > len1)	// Descending order
			{
				temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}
}

bool CheckDimensions(int& rows, int&cols, string words[], int totalWords)	// This function checks if dimensions of grid are valid
{
	cout << "\nEnter rows for your grid:\t";
	cin >> rows;
	while (rows <= 0)	// Rows must be greater than zero
	{
		cout << "Error: Rows can not be less than or equal to zero. Enter rows again:\t";
		cin >> rows;
	}
	cout << "\nEnter columns for your grid:\t";
	cin >> cols;
	while (cols <= 0)	// Columns must be greater than zero
	{
		cout << "Error: Columns can not be less than or equal to zero. Enter columns again:\t";
		cin >> cols;
	}
	
	for (int i = 0; i < totalWords; i++)	// Checking if dimensions are smaller than length of word
	{
		if (rows < words[i].length() || cols < words[i].length())
		{
			return false;
		}
	}
	
	return true;
}

bool CreateGrid()	// Function for creating grid
{
	int totalWords = 0;			
	ifstream infile;
	string FileName;
	cout << "Enter file name for input:\t";
	cin >> FileName;
	infile.open (FileName.c_str(), ifstream::in);
	
	while (!infile)	// Validating file name entered by user for input
	{
		cout << "Error: Unable to open file. File name not correct. Enter file name:\t";
		cin >> FileName;
		infile.open (FileName.c_str(), ifstream::in);
	}
	
	cout << "\nEnter total words:\t";
	cin >> totalWords;	
	while (totalWords <= 0)	// Total words must be greater than zero
	{
		cout << "Error: Words can not be less than or equal to zero. Enter total words again:\t";
		cin >> totalWords;
	}
		
	string words[totalWords];
	InputWords(totalWords, words, infile);
	
	int rows, cols;
	if (CheckDimensions(rows, cols, words, totalWords) == false)
	{
		return false;	// If grid can not be formed because dimensions are smaller than size of words
	}
	
	cout << "\nEnter file name for output:\t";
	cin >> FileName;
	
	char grid[rows][cols];
	
	for (int i = 0; i < rows; i++)	// Initializing grid
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = ' ';	// This will help in comparison to find empty place
		}
	}
	
	Sort(words, totalWords);
	
	int direction;
	bool empty = false;
	
	for (int c = 0; c < totalWords; )	// Repeating for each word one by one
	{
		direction = rand() % 4;	// Randomly decides in which direction to place the word
		
		if (direction == 0)	// Horizontal
		{
			empty = false;	
			int row = rand()%rows;	// Random place selected for placement of word
			int col = rand()%(cols + 1 - words[c].length());	// Making sure that the word won't fall off the grid
					       
		  	for (int i = col, j = 0; j < words[c].length(); i++, j++)
		    {	// This loop checks if there is available empty space on the grid to place the word
			    if (grid[row][i] == ' ' || words[c][j] == grid[row][i])	// Also checks for overlapping
			    {
					empty = true;
				}
				else
				{
					empty = false;	// No empty space to place the word
				   	break;
				}
			}
					        
			if (empty == true)
			{
				for (int i = 0; words[c][i] != '\0'; i++, col++)	// Only column number increases
			    {
				    grid[row][col] = words[c][i];	// Places the word horizontally in the random place selected if empty space found available
				}
				c++;	// Move to the next word if placed successfully
			}
		}
		if (direction == 1)	// Vertical
		{
			empty = false;	
			int row = rand()%(rows + 1 - words[c].length());	// Restriction on max row number vertically
			int col = rand()%cols;	// Column can be any
					       
		  	for (int i = row, j = 0; j < words[c].length(); i++, j++)
		    {
			    if (grid[i][col] == ' ' || words[c][j] == grid[i][col]) 
			    {
					empty = true;
				}
				else
				{
					empty = false;
				   	break;
				}
			}
					        
			if (empty == true)
			{
				for (int i = 0; words[c][i] != '\0'; i++, row++)
			    {
				    grid[row][col] = words[c][i];
				}
				c++;
			}
		}
		if (direction == 2)	// Diagonally forward
		{
			empty = false;	
			int row = rand()%(rows + 1 - words[c].length());	// Restriction on max row as well as column
			int col = rand()%(cols + 1 - words[c].length());	
					       
		  	for (int i = row, j = 0, k = col; j < words[c].length(); i++, j++, k++)
		    {
			    if (grid[i][k] == ' ' || words[c][j] == grid[i][k]) 
			    {
					empty = true;
				}
				else
				{
					empty = false;
				   	break;
				}
			}
					        
			if (empty == true)
			{
				for (int i = 0; words[c][i] != '\0'; i++, row++, col++)
			    {
				    grid[row][col] = words[c][i];
				}
				c++;
			}
		}
		if (direction == 3)	// Diagonally backward
		{
			empty = false;	
			int row = rand()%(rows + 1 - words[c].length());	
			int col = rand()%(cols + 1 - words[c].length());	
					       
		  	for (int i = row, j = 0, k = col; j < words[c].length(); i--, j++, k++)
		    {
			    if (grid[i][k] == ' ' || words[c][j] == grid[i][k]) 
			    {
					empty = true;
				}
				else
				{
					empty = false;
				   	break;
				}
			}
					        
			if (empty == true)
			{
				for (int i = 0; words[c][i] != '\0'; i++, row--, col++)
			    {
				    grid[row][col] = words[c][i];
				}
				c++;
			}
		}
	}
	
	for(int i = 0; i < rows; i++)	// Filling the grid
    {
        for(int j = 0; j < cols; j++)
        {
        	if (grid[i][j] == ' ')	// Place a random letter wherever an empty space found
        	{
	            char alphabet;
	            int randomNumber;
	            randomNumber = rand() % 26;		// Generate a random number within the range of the alphabet
	            alphabet = 'A' + randomNumber;		// Convert to a character from A-Z and place it
	            grid[i][j] = alphabet;
	        }
        }
    }
    
    ofstream ofile;
    ofile.open(FileName.c_str(), ofstream::out);
	
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			ofile << grid[i][j] << " ";	// Output characters of the grid separated by space
		}
		ofile << endl;
	}
	
	ofile.close();
	
	return true;
}

int main()
{
	char choice = ' ';
	string temp;
	cout << "\n------Welcome to Word Search Game------";
	
	while (choice != 'Q' && choice != 'q')	// Playing until user enters Q
	{
		cout << "\n\nPress C to Create Grid, S to Search Words from a grid, or Q to quit.\nEnter your choice:\t";
		cin >> choice;
		
		if (choice == 'C' || choice == 'c')	// Create grid for choice C
		{
			cout << "\n\n------Creating Grid------\n\n";
			
			bool success = CreateGrid();
			if (success == true)
			{
				cout << "\n\nGrid created successfully! Press any key to return to home screen\t";
				cin >> temp;
			}
			else if (success == false)
			{
				cout << "\nGrid cannot be formed, press any key to return to the home screen\t";
				cin >> temp;
			}
		}
		else if (choice == 'S' || choice == 's')	// Search words for choice S
		{
			cout << "\n\n------Searching Words------\n";
			SearchWords();
			cout << "\n\nPress any key to return to home screen\t";
			cin >> temp;
		}
		else if (choice != 'C' && choice != 'c' && choice != 'S' && choice != 's' && choice != 'Q' && choice != 'q')
		{
			cout << "\nWrong input for choice. Please choose one of the given options.";
		}
	}
	
	cout << "\n\n------Thankyou for Playing------\n";
	
	return 0;
}

