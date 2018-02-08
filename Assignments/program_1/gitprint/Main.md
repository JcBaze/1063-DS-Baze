/*
* @ProgramName: Program 1 - Image Manipulation
* @Author: Jesse Baze
  @Description: This program reads a txt. file of (RGB) values of an image
   allowing the user to pick any of the 5 options to manipulate the image.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 1-28-2018
*/

#include<iostream>
#include<fstream>
#include<math.h>
#include"ImageManip.cpp"

using namespace std;

//main will call to the ChangeImage class to do all the
//manipulation and user input. 
int main()
{
	ChangeImage edImage;
	edImage.Readfile();
	edImage.userinput();
	edImage.Printfile();
	return 0;
}
