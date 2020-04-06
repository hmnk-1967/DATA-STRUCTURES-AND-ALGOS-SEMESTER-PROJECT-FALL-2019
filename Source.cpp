/*DATA STRUCTURES AND ALGORITHM SEMESTER PROJECT
SUBMITTED BY: AHMAD KHAN (006), FAROOQ HAMID (014) AND HASSAN MAHMOOD (018)*/
#include "reTRIEval.h"
#include "Windows.h"
int main()
{
	char et; string req_word;
	reTRIEval* dictionaryTREE;
	saveNewWord filemanip;
	do
	{

		system("cls");

		system("color 5F");
		cout << " \n\n ";
		cout << "\n\n                                           Personal Dictionary ";
		cout << "\n                                    Tree Data Structure implemenatation ";
		cout << " \n\n ";
		Sleep(900);
		system("cls");
		cout << "\n\n\n\n                                  Loading ...";
		Sleep(400);
		system("cls");
		cout << "\n\n\n\n                                  Loading ......";
		Sleep(400);
		system("cls");
		cout << "\n\n\n\n                                  Loading .........";
		Sleep(400);
		system("cls");
		cout << "\n\n\n\n                                  Loading ...";
		Sleep(400);
		system("cls");
		
		

		cout << "\n\n\n      Developed by : " << endl << endl;
		Sleep(500);
		cout << "\t\t Hassan Mehmood ";
		Sleep(500);
		cout << "\n\n\t\t Farooq Hamid";
		Sleep(500);
		cout << "\n\n\t\t Ahmad Khan";
		Sleep(2500);
		cout << " \n\n\n\n ";
		system("cls");
		system("cls");
		system("color 3F");
		cout << "\n\t\t<--------------------DICTIONARY-------------------->\n\n\n\n";
		cout << "        ===================================================================";
		cout << endl << "        =                                                                 =";
		cout << "\n\t=    Press 1 to make a new entry into the dictionary              =";
		cout << endl << "        =                                                                 =";
		cout << "\n        ===================================================================";
		cout << endl << "        =                                                                 =";
		cout << "\n\t=    Press 2 to show all the available words in the dictionary    =";
		cout << endl << "        =                                                                 =";
		cout << "\n        ===================================================================";
		cout << endl << "        =                                                                 =";
		cout << "\n\t=    Press 3 to find the meaning of a word from the dictionary    =";
		cout << endl << "        =                                                                 =";
		cout << "\n        ===================================================================";
		cout << endl << "        =                                                                 =";
		cout << "\n\t=    Press 4 to quit the program                                  =";
		cout << endl << "        =                                                                 =";
		cout << "\n        ===================================================================";
		cout << "\n\n\tChoice: ";
		int choice;
		cin >> choice;
		cin.ignore();
		system("cls");
		switch (choice)
		{
		case 1:
			filemanip.mod();
			break;
		case 2:
			filemanip.showWordEntries();
			break;
		case 3:
			cout << "Enter the word to find the meaning of: ";
			getline(cin, req_word);
			dictionaryTREE = filemanip.readnInsert();
			cout << "The meaning of the word " << req_word << " is as follows:\n" << dictionaryTREE->findMeaning(dictionaryTREE, req_word) << endl;
			break;
		case 4:
			system("pause");
			exit(0);
		default:
			cout << "Invalid choice! Try again\n";
		}
		cout << "Continue(Y/N): ";
		cin >> et;
	} while (et == 'Y' || et == 'y');
	system("pause");
	return 0;
}