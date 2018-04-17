3)
int size = 10;
int *A = new int[size];

4)
int **B = new int *[x];
	for (int i=0; i<x; i++)
	{
		B[i] = new int [y];
	}
	
5)
int sumArray(int A[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += A[i];
	}
	return sum;
}

6)
int smallest2DArray(int **B, int height, int width)
{
	int smallest = B[0][0];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (B[i][j] <= smallest)
				smallest = B[i][j];
		}
	}
	return smallest;
}

7)
void evenSum(int A[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i+=2)
	{
		sum += A[i];
	}
}

8)
void copyArray(int A[], int B[])
{
	for (int i = 0; i < size; i++)
	{
		B[i] = A[i];
	}
}

9)
void reverseArray(int A[], int B[], int size)
{
	for (int i = 0, j = size - 1; i < size; i++, j--) 
	{
		B[j] = A[i];
	}
}

10)
void readArray(int A[], int size)
{
	ifstream infile;
	infile.open("numbers.txt");
	for (int i = 0; i < size; i++)
	{
		infile >> A[i];
	}
}

11)
Stats Cals(int A[], int size)
{
	Stats S;

	int     min = A[0];
	int     max = A[0];
	double  avg = 0.0;
	double  total = 0;

	for (int i = 0; i<size; i++) 
	{
		
		if (A[i]<min) 
		{
			min = A[i];
		}
	
		if (A[i]>max) 
		{
			max = A[i];
		}
		
		total += A[i];
	}
	
	S.min = min;
	S.max = max;
	S.avg = total / (double)size;

	return S;
}

12)
Stats(int MIN, int MAX, double AVG)
{
min = MIN;

max = MAX;

avg = AVG;
}
