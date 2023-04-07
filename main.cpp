#include <iostream>
#include <windows.h>

using namespace std;

char tablica[3][3]=
{
    {'0','0','0'},
    {'0','0','0'},
    {'0','0','0'},
};


//  "O"  -   Computer's character
//  "X"  -   User's character
void Input_Char(){                  //User inputs character

int i,j, test=1;
for(int a=0;bool(test);a++)
{

if(a>0)
{
    cout<<"Ta komorka jest zajeta, wybierz inna."<<endl;
}

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        Sleep(100);
        if(tablica[i][j]=='X')
        {
            SetConsoleTextAttribute(h,2);
            cout<<"X ";
        }

        else if(tablica[i][j]=='O')
        {
                SetConsoleTextAttribute(h,4);
                cout<<"O ";
        }

        else
        {
            SetConsoleTextAttribute(h,8);
            cout<<"0 ";
        }

    SetConsoleTextAttribute(h,8);
    }
    cout<<endl;
}
cout<<"Input which slot you want to put your character in (for example 'Upper Left=0 0', 'Middle=1 1', 'Upper_Right'=0 2)"<<endl;
cin>>i>>j;

if(tablica[i][j]=='0')
{
    test=0;
    tablica[i][j]='X';
}

}
system("cls");
}


//DEFENCE II
int Seek_n_delete_horizontally(){   //Seeks Horizontally for doubled "X" which leads to lose in next round, and interrupts by putting an "O"
string test;

    for(int i=0;i<3;i++)    //poziomowo
    {

        test=test.erase(0,10);

        for(int j=0;j<3;j++)
        {
            if(tablica[i][j]=='X')
            {
                test+='X';
            }

            if( tablica[i][0]!='0' && tablica[i][1]!='0' && tablica[i][2]!='0')
            {
                test=test.erase(0,10);
            }

        }

        if(test=="XX")
        {
            if(tablica[i][0]=='0'){tablica[i][0]='O';}
            if(tablica[i][1]=='0'){tablica[i][1]='O';}
            if(tablica[i][2]=='0'){tablica[i][2]='O';}
            return 1;
        }

    }
    return 0;
}
int Seek_n_delete_Upright(){        //Same but Uprightly

string test;

for(int j=0;j<3;j++)
{
    test=test.erase(0,10);

    for(int i=0;i<3;i++)
    {
        if(tablica[i][j]=='X') test+='X';
    }
    if(test=="XX")
    {
        if(tablica[0][j]=='0' || tablica[1][j]=='0' || tablica[2][j]=='0')
        {
            if(tablica[0][j]=='0') tablica[0][j]='O';
            if(tablica[1][j]=='0') tablica[1][j]='O';
            if(tablica[2][j]=='0') tablica[2][j]='O';
            return 1;
        }
    }
}

return 0;

}
int Seek_n_delete_Diagonally(){     //Same but Diagonally

string test;

if(tablica[0][0]=='X') test+='X';
if(tablica[1][1]=='X') test+='X';
if(tablica[2][2]=='X') test+='X';

if(test=="XX")
{
    if(tablica[0][0]=='0')
    {

    tablica[0][0]='O';
    return 1;

    }

    if(tablica[1][1]=='0') {

    tablica[1][1]='O';
    return 1;

    }

    if(tablica[2][2]=='0') {

    tablica[2][2]='O';
    return 1;

    }
}


test=test.erase(0,10);


if(tablica[0][2]=='X') test+='X';
if(tablica[1][1]=='X') test+='X';
if(tablica[2][0]=='X') test+='X';

if(test=="XX")
{
    if(tablica[2][0]=='0')
    {

    tablica[2][0]='O';
    return 1;

    }

    if(tablica[1][1]=='0')
    {

    tablica[1][1]='O';
    return 1;

    }

    if(tablica[0][2]=='0')
    {

    tablica[0][2]='O';
    return 1;

    }
    return 1;
}


return 0;
}
int Seek_4Double_n_Interrupt(){     //Seeks for doubled User's character in any line configuration (Combination of 3 belower functions)

    int test=0;

    test=Seek_n_delete_horizontally();
    if(test) return 1;
    test=Seek_n_delete_Upright();
    if(test) return 1;
    test=Seek_n_delete_Diagonally();
    if(test) return 1;
return 0;
}

//ATTACK
int Seek_n_add_horizontally(){

string test;

for(int i=0;i<3;i++)
{

    test=test.erase(0,10);

    for(int j=0;j<3;j++)
    {
        if(tablica[i][j]=='O') test+='O';
    }

    if(test=="OO")
    {
        if(tablica[i][0]=='0')
        {
            tablica[i][0]='O';
            return 1;
        }

        if(tablica[i][1]=='0')
        {
            tablica[i][1]='O';
            return 1;
        }

        if(tablica[i][2]=='0')
        {
            tablica[i][2]='O';
            return 1;
        }

    }

}

return 0;
}
int Seek_n_add_Upright(){

string test;

for(int j=0;j<3;j++)
{
    test=test.erase(0,10);

    for(int i=0;i<3;i++)
    {
        if(tablica[i][j]=='O') test+='O';
    }

    if(test=="OO")
    {
        if(tablica[0][j]=='0')
        {
            tablica[0][j]='O';
            return 1;
        }
    }

    if(test=="OO")
    {
        if(tablica[1][j]=='0')
        {
            tablica[1][j]='O';
            return 1;
        }
    }

    if(test=="OO")
    {
        if(tablica[2][j]=='0')
        {
            tablica[2][j]='O';
            return 1;
        }
    }

}
return 0;
}
int Seek_n_add_Diagonally(){

string test;

if(tablica[0][0]=='O') test+='O';
if(tablica[1][1]=='O') test+='O';
if(tablica[2][2]=='O') test+='O';

if(test=="OO")
{

    if(tablica[0][0]=='0')
    {
        tablica[0][0]='O';
        return 1;
    }

    if(tablica[1][1]=='0')
    {
        tablica[1][1]='O';
        return 1;
    }

    if(tablica[2][2]=='0')
    {
        tablica[2][2]='O';
        return 1;
    }

}

    test=test.erase(0,10);

    if(tablica[2][0]=='O') test+='O';
    if(tablica[1][1]=='O') test+='O';
    if(tablica[0][2]=='O') test+='O';

    if(test=="OO")
    {
        if(tablica[2][0]=='0')
        {
            tablica[2][0]='O';
            return 1;
        }

        if(tablica[1][1]=='0')
        {
            tablica[1][1]='O';
            return 1;
        }

        if(tablica[0][2]=='0')
        {
            tablica[0][2]='O';
            return 1;
        }
    }

return 0;
}
Seek_4Double_n_Add(){

int test;

    test=Seek_n_add_Diagonally();
    if(test) return 1;

    test=Seek_n_add_horizontally();
    if(test) return 1;

    test=Seek_n_add_Upright();
    if(test) return 1;

    return 0;
}

//No Hazard
int No_Hazard(){

if(tablica[2][2]=='0')
{
tablica[2][2]='O';
return 1;
}

if(tablica[2][0]=='0')
{
tablica[2][0]='O';
return 1;
}

if(tablica[0][0]=='0')
{
tablica[0][0]='O';
return 1;
}

if(tablica[0][2]=='0')
{
tablica[0][2]='O';
return 1;
}

if(tablica[1][1]=='0')
{
tablica[1][1]='O';
return 1;
}


for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(tablica[i][j]=='0')
        {
            tablica[i][j]='O';
            return 1;
        }
    }
}

return 0;
}

//Win Check
int Win_Check()
{
    //poziomo
    if(tablica[0][0]=='X' && tablica[0][1]=='X' && tablica[0][2]=='X')return 1;
    if(tablica[1][0]=='X' && tablica[1][1]=='X' && tablica[1][2]=='X')return 1;
    if(tablica[2][0]=='X' && tablica[2][1]=='X' && tablica[2][2]=='X')return 1;

    if(tablica[0][0]=='O' && tablica[0][1]=='O' && tablica[0][2]=='O')return 2;
    if(tablica[1][0]=='O' && tablica[1][1]=='O' && tablica[1][2]=='O')return 2;
    if(tablica[2][0]=='O' && tablica[2][1]=='O' && tablica[2][2]=='O')return 2;
    //pionowo
    if(tablica[0][0]=='X' && tablica[1][0]=='X' && tablica[2][0]=='X')return 1;
    if(tablica[0][1]=='X' && tablica[1][1]=='X' && tablica[2][1]=='X')return 1;
    if(tablica[0][2]=='X' && tablica[1][2]=='X' && tablica[2][2]=='X')return 1;

    if(tablica[0][0]=='O' && tablica[1][0]=='O' && tablica[2][0]=='O')return 2;
    if(tablica[0][1]=='O' && tablica[1][1]=='O' && tablica[2][1]=='O')return 2;
    if(tablica[0][2]=='O' && tablica[1][2]=='O' && tablica[2][2]=='O')return 2;
    //ukos
    if(tablica[0][0]=='X' && tablica[1][1]=='X' && tablica[2][2]=='X')return 1;
    if(tablica[2][0]=='X' && tablica[1][1]=='X' && tablica[0][2]=='X')return 1;

    if(tablica[0][0]=='O' && tablica[1][1]=='O' && tablica[2][2]=='O')return 2;
    if(tablica[2][0]=='O' && tablica[1][1]=='O' && tablica[0][2]=='O')return 2;

    int test=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tablica[i][j]=='0') test=1;
        }
    }
    if(test==1) return 0;

return 3;
}
int main()
{

    for(int test, licznik=0,test2=0;Win_Check()==0;licznik++)
    {
        test=0;

        Input_Char();

        if(licznik==0&&(tablica[0][0]=='X' || tablica[2][0]=='X' || tablica[0][2]=='X' ||tablica[2][2]=='X'))
        {
            tablica[1][1]='O';
            test=1;
            test2=1;
        }

        if(licznik==1&&test2==1&&test==0)
        {
            test=Seek_4Double_n_Interrupt();

            if(tablica[0][1]=='0'&&test==0)       {    tablica[0][1]='O';      test=1; }
            else if(tablica[1][0]=='0'&&test==0)  {    tablica[1][0]='O';     test=1; }
            else if(tablica[1][2]=='0'&&test==0)  {    tablica[1][2]='O';     test=1; }
            else if(tablica[2][1]=='0'&&test==0)  {    tablica[2][1]='O';     test=1; }


        }

        if(test==0)
        {
            test=Seek_4Double_n_Add();
        }

        if(test==0)
        {
            test=Seek_4Double_n_Interrupt();
        }

        if(test==0)
        {
            test=No_Hazard();
        }

    if(Win_Check()==1) cout<<"Wygrales!"<<endl;
    if(Win_Check()==2) cout<<"Wygral komputer."<<endl;
    if(Win_Check()==3) cout<<"Remis."<<endl;
    if(Win_Check()!=0) Input_Char();

    }
    return 0;

}
