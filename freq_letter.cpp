#include <iostream>        // �������� I/O
#include <cstdlib>         // ��������� ������
#include <fstream>         // �������� �����
#include <conio.h>

#define COUNT_LETTER 31          // ���������� ���� �������� 0-31 
#define ANSI_OFFSET 32           // �������� ��� ��������� 1251
#define VOCABULARY "russian.txt" // ������� ������� 
                        
// ���������� ������������ ����
using namespace std;
using std::cout;
using std::endl;
using std::ifstream;

int main(){
	setlocale(LC_ALL, "Russian"); // ��� ������ ������� ��������
	
	int letter[COUNT_LETTER]; // ������ ���������� ������������� ����
    int l_word[50]; // ������ ���� ����	 
	int count_word=0; // ���������� ����
	int count_char=0; // ���������� ��������
	char ch; // ������� ����������� ������
	int len_word=0; // ����� �������� �����
	
	ifstream fin(VOCABULARY);
    cout << "���� �������: " << VOCABULARY << endl;
    cout << "���� �������..." << endl << endl;

    // �������� �������, ��� ��� �������������
    for(int i=0;i<32;i++){letter[i]=0;}
    for(i=0;i<51;i++){l_word[i]=0;}
    
    // ���������� �����������, ���� �� ����� false
	while (fin.get(ch)){
		if (!(ch == '\n')){ // ���� ���� �� ������� ������
			if ((ch >= '�' && ch <= '�') || (ch >= '�' && ch <= '�')){
				if (ch=='�'){ch='�';} // � � � - ��� ���� �����
				count_char++; // ������� ����
				tolower(ch); // ����� � ������ �������
				len_word++;
				letter[(int(ch)+ANSI_OFFSET)]++;} // ������ ������� ��� �������� �� ��������� 1251
			else{}}
		else{
			count_word++; // ������� ����
			l_word[len_word]++; len_word=0;}} // ������������� ������� �� ���������� ���� 
    fin.close();

    // ������������ ������ ������
    cout << "��������� ������ ����" << endl << "----------------" << endl;
	for(char c='�'; c<='�'; c++){
        cout << "����� " << c << " " << letter[(int(c)+ANSI_OFFSET)] << endl;}
    
    cout << "----------------" << endl;
	system("pause"); // ��������� �����
	
    cout << endl << "��������� ������ ����� ����" << endl << "--------------------------" << endl;
    for(i=1;i<34;i++){
		cout << "���� ������ � " << i << " �������: " << l_word[i] << endl;}
		    		    
    cout << "--------------------------" << endl << "����������������" << endl
	     << "����: " << count_char << endl 
		 << "����: " << count_word << endl << endl;
	system("pause");
return 0;}
