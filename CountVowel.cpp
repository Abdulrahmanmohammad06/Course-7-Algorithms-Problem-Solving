#include<iostream>
#include<string>
using namespace std;
string ReadString() 
{
	string S1;
	cout << "Enter String" << endl;
	getline(cin, S1);
	return S1;


}
bool Check(char C1) 
{
	C1 = tolower(C1);
	return (C1 == 'a' || C1 == 'o' || C1 == 'e' || C1 == 'u' || C1 == 'i');



}
short Check1(string S1) 
{
	short Count = 0;
	for (int i = 0; i < S1.length();i++) 
	{  
		if (S1[i] == Check(S1[i])) 
		{
		
			Count++;
		}
	

	
	}

	return Count;

}
int main() 
{
	string S1 = ReadString();
	cout << "Count is =" << Check1(S1) << endl;

	return 0;
}



