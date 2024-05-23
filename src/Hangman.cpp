#include <iostream> //�� ������ �� ����� ������ �� ���� �������� �� ��������, ��� ��� �� ������ ����
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <stdio.h>
using namespace std;

const char* dictionary(int num) // ������� ���� (�������: �����, �������, ����)
{
    switch (num)
    {
    case 1: return "����";
    case 2: return "������";
    case 3: return "��������";
    case 4: return "����";
    case 5: return "������";
    case 6: return "��������";
    case 7: return "����";
    case 8: return "������";
    case 9: return "��������";
    case 10: return "����";
    case 11: return "������";
    case 12: return "��������";

    }
    return "num"; //����� �� ������� ������� (0 ��� �����������)

}

const char* choice(string difficult) // rand-�� �������� �����
{
    srand(time(NULL));
    int dif = std::stoi(difficult);
    int num = dif + 3 * (rand() % 4);
    const char* word = dictionary(num);
    return word;

}

void hangman(int mist, unsigned char** Letters, bool* Answer, int length) // ������ �������� � ��������/�����
{
    switch (mist)
    {
    case 0: printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n============\n"); break;
    case 1: printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n============\n"); break;
    case 2: printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n============\n"); break;
    case 3: printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n============\n"); break;
    case 4: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n============\n"); break;
    case 5: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n============\n"); break;
    case 6: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n============\n"); break;
    }
    for (int i = 0; i < length; i++)
    {
        if (Answer[i] == false) printf("_");
        else printf("%s", Letters[i]);
    }
    printf("\n");
}

int main()
{
    int i = 0;
    string symbols = "��������������������������������"; // ���� ��������� ����� �� ������ � ��������
    printf("�������� ���������:\n1. ˸����\n2. �������\n3. ������\n");
    string difficult;
    while (difficult != "1" && difficult != "2" && difficult != "3") getline(cin, difficult);
    const int length = 2 + (2 * stoi(difficult));
    const char* Word = choice(difficult); // ���� ����� (�������)
    unsigned char* Letters[length];
    bool Answer[length]; // ������ ������� ������, ������ ����� ��� _
    for (const char* ptr = Word; *ptr != '\0'; ptr += 2) // ������ �������� �� ���� �������� ����� 2-�������� ��������� �������� �� ���� + ��������� ������� �������
    {
        unsigned short ch = (static_cast<unsigned char>(*(ptr)) << 8) | static_cast<unsigned char>(*(ptr + 1));
        Answer[i] = false;
        Letters[i] = new unsigned char[3];
        Letters[i][0] = ch >> 8;
        Letters[i][1] = ch & 0xFF;
        Letters[i][2] = '\0';
        printf("%s", Letters[i]); // ��� ����� (��� ��������, ����� �������)
        i++;

    }
    printf("\n\n");
    int mist = 0;
    hangman(mist, Letters, Answer, length);
    while (mist < 6)
    {
        string l;
        getline(cin, l);
        if (l.find_first_of(symbols) == 0 && l.length() == 2) // �������� �� ��������
        {
            const char* q = l.c_str(); //����� ��� ���� �������� �������� ��� ��������
            const char* ptr = q;
            unsigned short ch = (static_cast<unsigned char>(*(ptr)) << 8) | static_cast<unsigned char>(*(ptr + 1));
            unsigned char* Input[1];
            Input[0] = new unsigned char[3];
            Input[0][0] = ch >> 8;
            Input[0][1] = ch & 0xFF;
            Input[0][2] = '\0';
            int err = 0;
            for (int i = 0; i < length; i++) // ���� ������ �����, �� ������ ���������� ��� � ���� �����
            {
                if (Input[0][0] == Letters[i][0] && Input[0][1] == Letters[i][1])
                {
                    Answer[i] = true;
                }
                else err++;
            }
            if (err == length) mist++; // ���� �� � ����� ����� �� ���� ���������� �� �������� ������������ �� ���

        }
        hangman(mist, Letters, Answer, length);
        int found = 0;
        for (int i = 0; i < length; i++)
        {
            if (Answer[i] == true) found++; // �������� �� ������
        }
        if (found == length) mist = 7;
    }
    if (mist == 6) printf("�� ���������!!!");
    if (mist == 7) printf("�� �������� �����");
    return 0;

}