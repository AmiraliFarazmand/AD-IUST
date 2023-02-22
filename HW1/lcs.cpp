#include <iostream>
using namespace std;

int main()
{
	int myArray[31];

	cout << "Enter up to 30 characters: " << flush;
	cin.getline(myArray, 31);
	
	cout << "You entered: " << flush;
	
	int i = 0;
	while (myArray[i] != '\0')
	{
		cout << myArray[i];
		i++;
	}


	cin.ignore();
	return 0;

}
