/*
  @ProgramName: Program 1 - Image Manipulation
  @Author: Jesse Baze
  @Description: This program reads a txt. file of (RGB) values of an image
	allowing the user to pick any of the 5 options to manipulate the image.
  @Course: 1063 Data Structures
  @Semester: Spring 2018
  @Date: 1-28-2018
*/

#include<iostream>
#include<fstream>
#include<math.h>
#include<limits>

using namespace std;

//Structure that will hold the RGB values of the image
struct rgb
{
	int r = 0;
	int g = 0;
	int b = 0;
};


class ChangeImage
{
private:
	rgb **imageArray;
	int width;
	int height;
	ifstream infile;
	ofstream outfile;

public:
	/*
	  @FunctionName: ReadFile
	  @Description: reads the image from the txt and store the RGB values in an array.
	  @Params:
	     bot.txt? - the original RGB txt image
		 rgb **imageArray - 2D array holding the RGB values
		 int height - height of the image
		 int width - width of the image
	  @Returns:
	     void
	*/
	void Readfile()
	{
		infile.open("bot.txt");

		infile >> width >> height;

		imageArray = new rgb*[height];

		for (int i = 0; i < height; i++)
		{
			imageArray[i] = new rgb[width];
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				infile >> imageArray[i][j].r >> imageArray[i][j].g >> imageArray[i][j].b;
			}
		}
	}

	/*
	  @FunctionName: Printfile
	  @Description: depending on the uses input the function will
		output the manipulated image the user
	  @Params:
	     bot2.txt? - the manipulated RGB vaules will output
		 rgb **imageArray - 2D array holding the RGB values
		 int height - height of the image
		 int width - width of the image
	  @Returns:
	     void
	*/
	void Printfile()
	{
		outfile.open("bot2.txt");

		outfile << width << " " << height << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				outfile << imageArray[i][j].r << " " << imageArray[i][j].g << " " << imageArray[i][j].b << " ";
			}
			outfile << endl;
		}
	}

	/*
	  @FunctionName: flipvert
	  @Description: the image will be flipped vertically
	  @Params:
	    rgb **imageArray - 2D array holding the RGB values
		int height - height of the image
		int width - width of the image
	  @Returns:
	     void
	*/
	void flipvert()
	{
		rgb tempArray;

		for (int i = 0; i < height / 2; i++)
		{
			for (int j = 0; j < width; j++)
			{
				tempArray = imageArray[i][j];
				imageArray[i][j] = imageArray[height - 1 - i][j];
				imageArray[height - 1 - i][j] = tempArray;
			}
		}
	}

	/*
	  @FunctionName: fliphorz
	  @Description: the image will be horziontally vertically
	  @Params:
		rgb **imageArray - 2D array holding the RGB values
		int height - height of the image
		int width - width of the image
	  @Returns:
	     void
	*/
	void fliphorz()
	{
		rgb tempArray;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < (width / 2); j++)
			{
				tempArray = imageArray[i][j];
				imageArray[i][j] = imageArray[i][width - 1 - j];
				imageArray[i][width - 1 - j] = tempArray;
			}
		}
	}

	/* 
	  @FunctionName: grayscale
	  @Description: the images color will be changed to grayscale
	  @Params:
	     rgb **imageArray - 2D array holding the RGB values
	     int height - height of the image
	 	 int width - width of the image
	  @Returns:
	    void
	*/
	void grayscale()
	{
		int gray;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				gray = (imageArray[i][j].r + imageArray[i][j].g + imageArray[i][j].b) / 3;

				imageArray[i][j].r = gray;
				imageArray[i][j].g = gray;
				imageArray[i][j].b = gray;
			}
		}
	}
	
	/*
	@FunctionName: userinput
	@Description: Will ask the user which way they would like to
	manipulate the image from any of the 5 choices.
	@Params:
	none
	@Returns:
	void
	*/
	void userinput()
	{
		int input;
		cout << "Enter any of the following commands to change the picture.\n";
		cout << " 1 for Grayscale.\n";
		cout << " 2 for Vertically flipped.\n";
		cout << " 3 for Horizontally flipped.\n";
		cout << "12 for Grayscale and Vertically flippped.\n";
		cout << "13 for Grayscale and Horizontally flippped.\n";

	Uinput:
		cin >> input;

		if (input == 1)
			grayscale();

		else if (input == 2)
			flipvert();

		else if (input == 3)
			fliphorz();

		else if (input == 12)
		{
			grayscale();
			flipvert();
		}

		else if (input == 13)
		{
			grayscale();
			fliphorz();
		}

		else
		{
			cout << "Invalid input, try again...\n";

			/* added these two line incase the user entered a char or string since the
			cout would just loop infinitely and break the program..*/
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto Uinput; /* will go back to the cin and allow the user to 
						enter an input again */
		}
	}
};
