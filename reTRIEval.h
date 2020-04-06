#pragma once
#ifndef reTRIEval_h
#define reTRIEval_h
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map> //Works around the hash-mapping concept.
using namespace std;
//TRIE class
class reTRIEval //Class for retrieval tree.
{
private:
	bool wordEND; //Tells whether the word has reached the end.
	unordered_map <char, reTRIEval*> dictTree; //Creates a retrieval tree using hash-mapping. Key value is of char type. Node (mapped value) will be of retrieval* type. Each node will hold a single character which together will make up a sensible word.
	string holdMeaning; //String to hold the meaning of the said word.
public:
	void insertWordMeaning(reTRIEval*&, string, string); //Function to add the concerned word on the trie. Meaning will be saved in correspondence with the said word, but not on the trie.
	string findMeaning(reTRIEval*, string);
};
void reTRIEval::insertWordMeaning(reTRIEval*& R, string w, string m)
{
	if (R == NULL)
	{
		reTRIEval* node1 = new reTRIEval;
		node1->wordEND = false;
		R = node1;
	}
	reTRIEval* tempNode = R;
	for (int i = 0; i < w.length(); i++)
	{
		char k = w[i];
		if (tempNode->dictTree.find(k) == tempNode->dictTree.end())
		{
			reTRIEval* node2 = new reTRIEval;
			node2->wordEND = false;
			tempNode->dictTree[k] = node2;
		}
		tempNode = tempNode->dictTree[k];
	}
	tempNode->wordEND = true;
	tempNode->holdMeaning = m;
}
string reTRIEval::findMeaning(reTRIEval* R, string w)
{
	if (R == NULL)
	{
		return "The dictionary is either empty or does not exist\n";
	}
	reTRIEval* tempNode = R;
	for (int i = 0; i < w.length(); i++)
	{
		tempNode = tempNode->dictTree[w[i]];
		if (tempNode == NULL)
		{
			return "This word does not exist in the dictionary\n";
		}
	}
	if (tempNode->wordEND == true)
	{
		return tempNode->holdMeaning;
	}
}
//Class to save and read the dictionary file.
class saveNewWord
{
private:
	char wd[250], mng[250];
public:
	void getData();
	void mod();
	reTRIEval* readnInsert();
	void showWordEntries();
};
void saveNewWord::getData()
{
	cout << "Enter the word: ";
	cin.getline(wd, 250);
	cout << "Enter the meaning of the word along with the type: ";
	cin.getline(mng, 250);
}
void saveNewWord::mod()
{
	system("cls");
	cout << "\n\n\t\t<====Adding a new word====>\n\n";
	getData();
	ofstream enterData("Dictionary.dat", ios::app | ios::binary);
	enterData.write((char*)this, sizeof(saveNewWord));
	enterData.close();
	cout << "\n\n\t\t<====Finished====>\n\n";
}
reTRIEval* saveNewWord::readnInsert()
{
	reTRIEval* g = NULL;
	ifstream reax("Dictionary.dat", ios::binary);
	reax.read((char*)this, sizeof(saveNewWord));
	while (!reax.eof())
	{
		string w = wd;
		string m = mng;
		g->insertWordMeaning(g, w, m);
		reax.read((char*)this, sizeof(saveNewWord));
	}
	reax.close();
	return g;
}
void saveNewWord::showWordEntries()
{
	cout << "\n\n\t\t<=====Available Words=====>\n\n";
	ifstream rdr("Dictionary.dat", ios::binary);
	rdr.read((char*)this, sizeof(saveNewWord));
	while (!rdr.eof())
	{
		cout << wd << endl;
		rdr.read((char*)this, sizeof(saveNewWord));
	}
	rdr.close();
	cout << "\n\n\t\t<======Finished======>\n\n";
}
#endif