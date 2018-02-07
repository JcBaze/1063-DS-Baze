/*
  @ProgramName: Program 1 - Image Manipulation
  @Author: Jesse Baze
  @Description: This program reads the txt. (RGB) values of an image
  allowing the user to pick any of the 5 options to manipulate the
  image to their choice.
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

public:
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
		Readfile();

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
		Printfile();
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
		Readfile();

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
		Printfile();
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
		Readfile();

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
		Printfile();
	}

	/*
	@FunctionName: Vertgrayscale
	@Description: the images color will be changed to grayscale, then
	will be flipped vertically
	@Params:
	rgb **imageArray - 2D array holding the RGB values
	int height - height of the image
	int width - width of the image
	@Returns:
	void
	*/
	void Vertgrayscale()
	{
		Readfile();

		int gray;
		rgb tempArray;
		
		//Vertical flip
		for (int i = 0; i < height / 2; i++)
		{
			for (int j = 0; j < width; j++)
			{
				tempArray = imageArray[i][j];
				imageArray[i][j] = imageArray[height - 1 - i][j];
				imageArray[height - 1 - i][j] = tempArray;
			}
		}
		
		//Grayscalling the image
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
		Printfile();
	}

	/*
	@FunctionName: Horzgrayscale
	@Description: the images color will be changed to grayscale, then
	will be horizontally flipped
	@Params:
	rgb **imageArray - 2D array holding the RGB values
	int height - height of the image
	int width - width of the image
	@Returns:
	void
	*/
	void Horzgrayscale()
	{
		Readfile();

		int gray;
		rgb tempArray;

		//Horizontal Flip
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < (width / 2); j++)
			{
				tempArray = imageArray[i][j];
				imageArray[i][j] = imageArray[i][width - 1 - j];
				imageArray[i][width - 1 - j] = tempArray;
			}
		}
		//Grayscale
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
		Printfile();
	}

	/*
	@FunctionName: userinput
	@Description: Asks the user which manipulation of the image
	the would like to preform
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

	start:
		cin >> input;

		if (input == 1)
			grayscale();

		else if (input == 2)
			flipvert();

		else if (input == 3)
			fliphorz();

		else if (input == 12)
			Vertgrayscale();

		else if (input == 13)
			Horzgrayscale();

		else
		{
			cout << "Invalid input, try again...\n";

			/* added these two line incase the user entered a char or string since the
			cout would just loop infinitely and break the program..*/
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto start; /* will go back to the cin and allow the user to 
						enter an input again */

		}
	}
};
