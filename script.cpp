#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
using namespace std;
using namespace cgicc;
#define WORDS_AMOUNT 3
#define WORDS_STEP 1
#define N 256

double antiPlagiarism(string text, string frag);
string getDB();//get origin text from db.txt (don't modify tis function)

bool isOriginalLine(char* w1, char* w2);
bool isSeparator(char c);
void changeInput(char *inputText);
int strLength(char line[]);
int firstWordLength(char textFragment[]);
void getCharArrayFromString(char textArray[], string text);


int main()
{
    Cgicc form;
    string name;

    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Ggi Server</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<p>";
    
    name = form("name");
    if (!name.empty()) {
    	cout << antiPlagiarism(getDB(), name) << "\n";
    } else {
    	cout << "Text is not provided!\n";
    }	
    cout << "</p>\n";
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}

double antiPlagiarism(string text, string frag){
	char textBase[N] = "hello my dear hello world ";
	char textInput[N] = "My,,      dEaR ... heLlo couNTry curRENt dear hello faIl";
	char textFragment[N] = "";
	int attempts = 0;
	int subCarriage = 0;
	int wordsCounter = 0;
	int originalCounter = 20;
	char* base = textBase;
	char* fragment = textInput;
	int inputLength;
	getCharArrayFromString(textBase, text);
	getCharArrayFromString(textInput, frag);
    // my algorithm
	return 20;

}

string getDB(){
	std::ifstream in("db.txt");

    string dbText = "", s1;
    while (getline(in, s1))
    	dbText += s1;
  
    in.close();
    
    return dbText;
}

bool isOriginalLine(char *base, char *fragment)
{
	int i=0;
    int j=0;

    for(i;i < strLength(base); i++)
    {
        if(base[i] == fragment[j])
        {
            j++;
        }
    }

    if(strLength(fragment) == j)
        return false;
    else
        return true;
}

bool isSeparator(char c)
{
	char separatorList[] = " ,.!?<>/\"-'\\:;";
	for (int i = 0; separatorList[i] != '\0'; i++)
		if (separatorList[i] == c or c == '\0') 
			return true;
	return false;
}

void changeInput(char *inputText)
{
	int tempIndex = 0;
	int inputLength = strLength(inputText);
	
	for (int i = 0; inputText[i] != '\0'; i++) {
		if (!isSeparator(inputText[i])) {
			if (inputText[i] >= 'A' and inputText[i] <= 'Z') {
				inputText[tempIndex] = (char)((int)inputText[i] + 32);
				tempIndex++;
			} else {
				inputText[tempIndex] = inputText[i];
				tempIndex++;
			}
		} else if (!isSeparator(inputText[tempIndex - 1])){
			inputText[tempIndex] = ' ';
			tempIndex++;
		}
	}
	
	for (inputLength; inputLength >= tempIndex; inputLength--){
		inputText[inputLength] = 0;
	}
}

int strLength(char line[])
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
	}
	return i + 1;
}

int firstWordLength(char textFragment[])
{
	for (int i = 0; textFragment[i] != '\0'; i++)
		if (isSeparator(textFragment[i]))
			return i;
}

void getCharArrayFromString(char textArray[], string text){
	int i = 0;
	for(i = 0; i < text.length(); i++)
		textArray[i] = text[i];	
	textArray[i] = '\0';
}



