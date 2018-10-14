#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>

#define COUNT_LETTER 31
#define ANSI_OFFSET 32
#define VOCABULARY "russian.txt"
                       
using namespace std;
using std::cout;
using std::endl;
using std::ifstream;

int main(){
    setlocale(LC_ALL, "Russian");
	
    int letter[COUNT_LETTER];
    int l_word[50]; 
    int count_word=0;
    int count_char=0;
    char ch;
    int len_word=0;
	
    ifstream fin(VOCABULARY);
    cout << "Словарь: " << VOCABULARY << endl;
    cout << "Идет подсчет..." << endl << endl;
	
    for(int i=0;i<32;i++){letter[i]=0;}
    for(i=0;i<51;i++){l_word[i]=0;}
    
    while (fin.get(ch)){
	if (!(ch == '\n')){
	    if ((ch >= 'А' && ch <= 'Я') || (ch >= 'а' && ch <= 'я')){
		if (ch=='ё'){ch='е';} // as one letter
		count_char++;
		tolower(ch);
		len_word++;
		letter[(int(ch)+ANSI_OFFSET)]++;} // index array as offset encoding Windows1251 to 0
	    else{}}
	else{
	    count_word++;
	    l_word[len_word]++; len_word=0;}}
    fin.close();

    cout << "Частотный анализ букв" << endl << "----------------" << endl;
	for(char c='а'; c<='я'; c++){
        cout << "Буква " << c << " " << letter[(int(c)+ANSI_OFFSET)] << endl;}
    
    cout << "----------------" << endl;
	system("pause");
	
    cout << endl << "Частотный анализ длины слов" << endl << "--------------------------" << endl;
    for(i=1;i<34;i++){
	cout << "Слов длиной с " << i << " буквами: " << l_word[i] << endl;}
		    		    
    cout << "--------------------------" << endl << "Проанализировано" << endl
	 << "Букв: " << count_char << endl 
	 << "Слов: " << count_word << endl << endl;
    system("pause");
return 0;}
