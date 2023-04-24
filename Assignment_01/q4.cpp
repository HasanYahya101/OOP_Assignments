#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MaxRows 500
#define MaxCols 500

class Image
{
private:
	int rows, cols, maxVal;
	int image[MaxRows][MaxCols];
public:
	Image();
	void loadImage(string);
	void saveImage(string);
	void changeBrightness(int);
	void FlipVertically();
	void FlipHorizontally();
	void combineSideBySide(Image, int);
	void Negative();
	void medianFilter(int);
	//void Filter(double[][3], int, int);
	//void applyFilter(double[3][3]);
};

Image::Image()
{
	rows = 0;
	cols = 0;
	maxVal = 0;
}

void Image::loadImage(string fileName)
{
	ifstream inFile;
	inFile.open(fileName.c_str());
	if (!inFile)
	{
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	string magicNum;
	inFile >> magicNum;
	inFile >> cols;
	inFile >> rows;
	inFile >> maxVal;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			inFile >> image[i][j];
		}
	}
	inFile.close();
}

void Image::saveImage(string fileName)
{
	ofstream outFile;
	outFile.open(fileName.c_str());
	if (!outFile)
	{
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	outFile << "P2" << endl;
	outFile << cols << " " << rows << endl;
	outFile << maxVal << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			outFile << image[i][j] << " ";
		}
		outFile << endl;
	}
	outFile.close();
}

void Image::changeBrightness(int amount)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			image[i][j] = image[i][j] + amount;
			if (image[i][j] > maxVal)
			{
				image[i][j] = maxVal;
			}
			else if (image[i][j] < 0)
			{
				image[i][j] = 0;
			}
		}
	}
}

void Image::FlipVertically()
{
	int temp;
	for (int i = 0; i < rows / 2; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp = image[i][j];
			image[i][j] = image[rows - i - 1][j];
			image[rows - i - 1][j] = temp;
		}
	}
}

void Image::FlipHorizontally()
{
	int temp;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols / 2; j++)
		{
			temp = image[i][j];
			image[i][j] = image[i][cols - j - 1];
			image[i][cols - j - 1] = temp;
		}
	}
}

void Image::combineSideBySide(Image GM2, int fillVal)
{
	int newRows, newCols;
	if (rows > GM2.rows)
	{
		newRows = rows;
	}
	else
	{
		newRows = GM2.rows;
	}

	newCols = cols + GM2.cols;

	for (int i = 0; i < newRows; i++)
	{
		for (int j = 0; j < newCols; j++)
		{
			if (i < rows && j < cols)
			{
				image[i][j] = image[i][j];
			}
			else if (i < GM2.rows && j >= cols)
			{
				image[i][j] = GM2.image[i][j - cols];
			}
			else
			{
				image[i][j] = fillVal;
			}
		}
	}
	rows = newRows;
	cols = newCols;
}

void Image::Negative()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			image[i][j] = maxVal - image[i][j];
		}
	}
}

void Image::medianFilter(int windowSize)
{
	double filter[3][3];
	int filterSize = windowSize * windowSize;
	int filterArray[9];
	int temp;
	int median;
	int count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < windowSize; k++)
			{
				for (int l = 0; l < windowSize; l++)
				{
					if (i + k < rows && j + l < cols)
					{
						filterArray[count] = image[i + k][j + l];
						count++;
					}
				}
			}
			for (int k = 0; k < filterSize; k++)
			{
				for (int l = 0; l < filterSize - 1; l++)
				{
					if (filterArray[l] > filterArray[l + 1])
					{
						temp = filterArray[l];
						filterArray[l] = filterArray[l + 1];
						filterArray[l + 1] = temp;
					}
				}
			}
			median = filterArray[filterSize / 2];
			image[i][j] = median;
			count = 0;
		}
	}
}



int main()
{
	Image GM;
	string outputFile;
	string image1;

	cout << "Enter name of image 1: " << endl;
	getline(cin, image1);
	GM.loadImage(image1);


	system("CLS");
	

	int option = 0;

	while (option != -1)
	{
		cout << "Choose an option:\n" << endl;
		cout << " 1. Combine Two images side by side " << endl;
		cout << " 2. Change Brightness of Image" << endl;
		cout << " 3. Find Negative of an Image " << endl;
		cout << " 4. Flip an image Vertically" << endl;
		cout << " 5. Flip an image Horizontally" << endl;
		cout << " 6. Apply Median Filter (Remove Noise)" << endl;
		cout << "ENTER -1 TO EXIT" << endl;
		cout << "Enter value: ";
		cin >> option;

		if (option == 1) //sidebyside
		{
			Image GM2;
			string image2;

			cout << "Enter name of image 2: " << endl;
			getline(cin, image2);
			GM.loadImage(image2);

			int fillVal;
			cout << "Enter the gray fill Value: " << endl;
			cin >> fillVal;
			GM.combineSideBySide(GM2, fillVal);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
		}

		else if (option == 2) { //brightness
			int amount;
			cout << "Enter the amount for brightness: " << endl;
			cin >> amount;
			cout << endl;
			GM.changeBrightness(amount);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			cout << endl;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 3) { //negative
			GM.Negative();
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 4) { //flip v
			GM.FlipVertically();
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 5) { //flip h
			GM.FlipHorizontally();
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 6) { //median
			int filtersize;
			cout << "Enter filter size: " << endl;
			cin >> filtersize;
			GM.medianFilter(filtersize);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			cout << endl;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		
		}
		else if (option == -1)
			break;
	}

	return 0;
}

/*
 A .PGM image format can be represented using a 2D Integer Matrix, each index representing a colour
pixel which ranges from (0 - 255), where 0 is the darkest and 255 is the brightest. Below is a sample pgm
image file, and another can be found by clicking here Sample-2: 60
P2
4 4
255
0 33 0 170
0 143 0 0
0 0 63 0
170 0 0 255
Here the first row represents a magic number “P2” which provides encoded information about the image.
This row can be hard coded. The next row contains information about the total number of columns
and rows of the image respectively. The third row contains information about the maximum grey scale
value of the image. You can read more about Portable Grey Map Images on the following page: PGM
Images Info
Your task is to implement an image editor program in C++ containing a class “Image” that will have the
following functions:
1. Read a PGM image file into a 2D Integer Matrix
2. Save the edited PGM image into a file
3. Change the image's brightness by a value which ranges from -255 to 255
4. Flip the image horizontally or vertically
5. Combine Two Images Side to Side
6. Find the negative of an Image
7. Apply the median filter on an image to reduce noise
8. Implement the additional feature of applying filter which will count towards bonus marks in
the assignment
Use the following skeleton code as a starting point in order to understand the question more briefly.
  
 */