#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
const string fileName = "Clients.txt";
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};



vector<string>SplitString(string S1,string delim) 
{

	short Pos = 0;
	string sWord = " ";
	vector<string>vClientData;
	while ((Pos=S1.find(delim))!=std::string::npos) 
	{
	
		sWord = S1.substr(0, Pos);
		if (sWord!=" ")
		{
		
			vClientData.push_back(sWord);
		
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1 != " ") 
	{
	
		vClientData.push_back(S1);
	
	}
	
	
	return vClientData;


}
sClient ConvertLineToRecord(string Line,string Sperator="#//#") 
{
	sClient Client;
	vector<string>vClientdata = SplitString(Line, Sperator);
	Client.AccountNumber = vClientdata[0];
	Client.PinCode = vClientdata[1];
	Client.Name = vClientdata[2];
	Client.Phone = vClientdata[3];
	Client.AccountBalance = stod(vClientdata[4]);
	return Client;



}
vector<sClient>LoadDataFromFile(string FileName) 
{
	vector<sClient>vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) 
	{
		string Line;
		sClient data;

		while (getline(MyFile,Line)) 
		{
			data = ConvertLineToRecord(Line);
			vClient.push_back(data);
		}
		MyFile.close();
	}
	return  vClient;

}
bool FindClientByAccountNumber(string AccountNumber,vector<sClient>vClient, sClient &Client) 
{

	for (sClient& c : vClient) 
	{
		if (c.AccountNumber == AccountNumber) 
		{
			Client = c;
			return 1;

		}

	}

	return 0;
}
void printClientCard(sClient Client) 
{
	cout << "\nThe following are the client details:\n";
	cout << "Account Number : " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;
}
bool MarkClientDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClient) 
{

	for (sClient& C : vClient) 
	{
	
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = 1;

			return 1;
		}
	}

	return 0;

}
string ConvertRecordToLine(sClient Client,string delim="#//#")
{

	string Line = " ";
	Line = Client.AccountNumber + delim;
	Line += Client.PinCode + delim;
	Line += Client.Name + delim;
	Line += Client.Phone + delim;
	Line +=to_string (Client.AccountBalance);


	return Line;


}
vector<sClient>SaveClientsDataToFile(string fileName,vector<sClient>&vClient) 
{

	fstream MyFile;
	MyFile.open(fileName, ios::out);//OverWrie
		string DataLine;
	if (MyFile.is_open()) 
	{
	
		for (sClient& C : vClient) 
		{
		
			if (C.MarkForDelete== 0)
			{
			
				DataLine = ConvertRecordToLine(C);
					MyFile << DataLine << endl;
			
			}
		
		}

		MyFile.close();
	}
	
	return 	vClient;

}
 bool DeleteClientByAccountNumber(string AccountNumber,vector<sClient>&vClient) 
 {
 
	 sClient Client;
	 char Ans = 'n';
	 if (FindClientByAccountNumber(AccountNumber,vClient,Client)) 
	 {
	 
		 printClientCard(Client);
		 cout << "\n\nAre You Sure Delet This Client ?(Y/N) \n";
		 cin >> Ans;
		 if (toupper(Ans) == 'Y') 
		 {
		 
			 MarkClientDeleteByAccountNumber(AccountNumber, vClient);
			 SaveClientsDataToFile(fileName, vClient);

			 vClient = LoadDataFromFile(fileName);

			 cout << "\n\nClient Deleted Successfully.";
			 return 1;
		 
		 }
	 }
		 else 
		 {
			 cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";

		 	 return 0;
			
		 
		 }
	   
	 
 }
string ReadAccountNumber() 
{

	string AccountNumber = " ";
	cout << "Enter Account Number : ";
	cin >> AccountNumber;
	return AccountNumber;


}
int main() 
{

	vector<sClient>vClient = LoadDataFromFile(fileName);

	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClient);

	system("pause>0");;
	return 0;

}