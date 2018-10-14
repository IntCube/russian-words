#include <iostream>        // поточный I/O
#include <cstdlib>         // системные вызовы
#include <fstream>         // файловый поток
#include <conio.h>

#define COUNT_LETTER 31          // количество букв алфавита 0-31 
#define ANSI_OFFSET 32           // смещение для кодировки 1251
#define VOCABULARY "russian.txt" // Русский словарь 
                        
// используем пространтсво имен
using namespace std;
using std::cout;
using std::endl;
using std::ifstream;

int main(){
	setlocale(LC_ALL, "Russian"); // для вывода русских символов
	
	int letter[COUNT_LETTER]; // массив частотного распределения букв
    int l_word[50]; // массив длин слов	 
	int count_word=0; // количество слов
	int count_char=0; // количество символов
	char ch; // текущий считываемый символ
	int len_word=0; // длина текущего слова
	
	ifstream fin(VOCABULARY);
    cout << "Файл словаря: " << VOCABULARY << endl;
    cout << "Идет подсчет..." << endl << endl;

    // обнулять массивы, так как накопительные
    for(int i=0;i<32;i++){letter[i]=0;}
    for(i=0;i<51;i++){l_word[i]=0;}
    
    // считывание посимвольно, пока не будет false
	while (fin.get(ch)){
		if (!(ch == '\n')){ // если знак не перевод строки
			if ((ch >= 'А' && ch <= 'Я') || (ch >= 'а' && ch <= 'я')){
				if (ch=='ё'){ch='е';} // Е и Ё - как одна буква
				count_char++; // счетчик букв
				tolower(ch); // букву в нижний регистр
				len_word++;
				letter[(int(ch)+ANSI_OFFSET)]++;} // индекс массива как смещение по кодировке 1251
			else{}}
		else{
			count_word++; // счетчик слов
			l_word[len_word]++; len_word=0;}} // накопительные массивы по количеству букв 
    fin.close();

    // Формирование потока вывода
    cout << "Частотный анализ букв" << endl << "----------------" << endl;
	for(char c='а'; c<='я'; c++){
        cout << "Буква " << c << " " << letter[(int(c)+ANSI_OFFSET)] << endl;}
    
    cout << "----------------" << endl;
	system("pause"); // системный вызов
	
    cout << endl << "Частотный анализ длины слов" << endl << "--------------------------" << endl;
    for(i=1;i<34;i++){
		cout << "Слов длиной с " << i << " буквами: " << l_word[i] << endl;}
		    		    
    cout << "--------------------------" << endl << "Проанализировано" << endl
	     << "Букв: " << count_char << endl 
		 << "Слов: " << count_word << endl << endl;
	system("pause");
return 0;}
