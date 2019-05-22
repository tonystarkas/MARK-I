#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class grajus
{
private:
    char table[10][10];
    char secret[10][10];
    char a,dir;
    int x,y,xz;
    int health;
public:
    grajus()
    {
        health=20;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                table[i][j]='.';
                secret[i][j]='.';
            }
        }
    }
    virtual void board()
    {
        system("CLS");
        cout<<"   A B C D E F G H I J"<<endl;
        for(int i=0;i<10;i++)
        {
            cout<<i+1<<" ";
            if(i+1!=10)
                cout<<" ";
            for(int j=0;j<10;j++)
            {
                if(j!=9)
                    cout<<table[i][j]<<" ";
                else cout<<table[i][j]<<" | ";

            }
            cout<<endl;
        }
    }
    virtual void printsecret()
    {
        gotoxy(25,0);
        cout<<"   A B C D E F G H I J"<<endl;
        for(int i=0;i<10;i++)
        {
            gotoxy(25,i+1);
            for(int j=0;j<10;j++)
            {
                if(j==0)
                {
                    if(i!=9)
                        cout<<i+1<<"  "<<secret[i][j]<<" ";
                    else cout<<i+1<<" "<<secret[i][j]<<" ";
                }
                else cout<<secret[i][j]<<" ";
            }
        }
        gotoxy(0,15);
    }
    void laivaiPC()
    {
        for(int i=4;i>0;i--)
        {
            for(int j=0;j<5-i;j++)
            {
                x=rand()%10+1;
                y=rand()%10+1;
                dir=rand()%2;
                xz=0;
                if(dir==1)
                {
                    dir='A';
                }
                if(dir==0)
                {
                    dir='D';
                }

                if(dir=='A'&&(x+i-1)<=10)
                {
                    for(int d=x-1; d<=x+i; d++)
                    {
                        for(int u=y-1; u<=y+1; u++)
                        {
                            if(table[d-1][u-1]=='.'||d<1||d>10||u<1||u>10)
                                xz++;
                        }
                    }
                    if(xz==(i+2)*3)
                    {
                        for(int k=0; k<i; k++)
                        {
                            table[x-1+k][y-1]='@';
                        }
                    }
                    else
                    {
                        j--;
                    }
                }
                else if(dir=='D'&&(y+i-1)<=10)
                {
                    for(int d=x-1; d<=x+1; d++)
                    {
                        for(int u=y-1; u<=y+i; u++)
                        {
                            if(table[d-1][u-1]=='.'||d<1||d>10||u<1||u>10)
                                xz++;
                        }
                    }
                    if(xz==(i+2)*3)
                    {
                        for(int k=0; k<i; k++)
                        {
                            table[x-1][y-1+k]='@';
                        }
                    }
                    else
                    {
                        j--;
                    }
                }
                else
                {
                    j--;
                }
            }
        }
    }
    void laivaizm()
    {
        for(int i=4;i>0;i--)
        {
            for(int j=0;j<5-i;j++)
            {
                board();
                cout<<"Iveskite koordinates formatu x, y. Laivo dydis: "<<i<<" "<<endl;
                cin>>a>>x;
                cout<<"Laiva statyti i apacia(A) ar i desine(D)?"<<endl;
                cin>>dir;
                a=toupper(a);
                dir=toupper(dir);
                y=a-64;
                xz=0;
                if (dir=='A'&&(x+i-1)<=10)
                {
                    for (int d=x-1; d<=x+i; d++)
                    {
                        for (int u=y-1; u<=y+1; u++)
                        {
                            if (table[d-1][u-1]=='.' || d<1 || d>10 || u<1 || u>10)
                                xz++;
                        }
                    }
                    if (xz==(i+2)*3)
                    {
                        for (int k=0; k<i; k++)
                        {
                            table[x-1+k][y-1]='@';
                        }
                    }
                    else
                    {
                        cout<<"Blogos koordinates"<<endl;
                        j--;
                    }
                }
                else if (dir=='D' && (y+i-1)<=10)
                {
                    for (int d=x-1; d<=x+1; d++)
                    {
                        for (int u=y-1; u<=y+i; u++)
                        {
                            if (table[d-1][u-1]=='.' || d<1 || d>10 || u<1 || u>10)
                                xz++;
                        }
                    }
                    if (xz==(i+2)*3)
                    {
                        for (int k=0; k<i; k++)
                        {
                            table[x-1][y-1+k]='@';
                        }
                    }
                    else
                    {
                        cout<<"Blogos koordinates"<<endl;
                        j--;
                    }
                }
                else
                {
                    cout<<"Blogos koordinates"<<endl;
                    j--;
                }
            }
        }
        cout<<"Jūsų lentelė jau užpildyta!";
    }
    pair<int,int> SaudymasPC()
    {
        return make_pair(rand()%10, rand()%10);
    }

    bool arGerasSuvis(pair<int,int>shot)
    {
        if(table[shot.first][shot.second] != 'm' && table[shot.first][shot.second] != 'X')
            return true;
        else return false;
    }

    bool PrimtiSuvi(pair<int,int>shot)
    {
        if(table[shot.first-1][shot.second-1] == '@')
        {
            cout << "Kompiuteris i jus pataike!";
            Sleep(2000);
            table[shot.first-1][shot.second-1] = 'X';
            return true;
        }
        else
        {
            table[shot.first-1][shot.second-1] = 'm';
            return false;
        }
    }

    bool PrimtiSuviPC(pair<int,char>shot)
    {
        int a;
        if(shot.second == 'a')
            a=0;
        else if (shot.second == 'b')
            a=1;
        else if (shot.second == 'c')
            a=2;
        else if (shot.second == 'd')
            a=3;
        else if (shot.second == 'e')
            a=4;
        else if (shot.second == 'f')
            a=5;
        else if (shot.second == 'g')
            a=6;
        else if (shot.second == 'h')
            a=7;
        else if (shot.second == 'i')
            a=8;
        else if (shot.second == 'j')
            a=9;
        if(table[shot.first-1][a] == '@')
        {
            cout << "Jus pataikete!";
            Sleep(2000);
            table[shot.first-1][a] = 'X';
            secret[shot.first-1][a] = 'X';
            return true;
        }
        else
        {
            table[shot.first-1][a] = 'm';
            secret[shot.first-1][a] = 'm';
            return false;
        }
    }
    void hpdown()
    {
        health--;
    }
    int hp()
    {
        return health;
    }
~grajus()
{
}
};
int main()
{
    int turn=1;
    srand (time(0));
    grajus G;
    grajus Gl;
    G.laivaizm();
    Gl.laivaiPC();
    while(true)
    {
        G.board();
        Gl.printsecret();
        if(turn == 2)
        {
            cout << "Kompiuterio eile sauti: "<<endl;
            Sleep(3000);
            while(true)
            {

                pair<int,int> suvis;
                suvis = Gl.SaudymasPC();
                if(G.arGerasSuvis(suvis))
                {
                    turn = 1;
                    if(G.PrimtiSuvi(suvis))
                        G.hpdown();
                    break;
                }
            }
        }
        else
        {
            cout << "Jusu eile sauti, iveskite koordinates:"<<endl;;
            while(true)
            {
                pair<int,char> suvis1;
                cin>>suvis1.second>>suvis1.first;
                if(suvis1.first >= 0 && suvis1.first <= 10 && suvis1.second >= 'a' && suvis1.second <= 'j')
                {
                    if(Gl.PrimtiSuviPC(suvis1))
                        Gl.hpdown();
                    turn=2;
                    break;
                }
            }
        }
        if(G.hp()==0)
        {
            cout<<"PRLAIMEJOTE!"<<endl;;
            break;
        }
        if(Gl.hp()==0)
        {
            cout<<"LAIMEJOTE!"<<endl;
            break;
        }
    }
    return 0;
}
