#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

char a[3][3]= {'1','2','3','4','5','6','7','8','9'};
char user;

void DISP()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int once(int m)
{
    for(int i=0; i<3; i++)
    {
        int h=0;
        int v=-1;
        for(int j=0; j<3; j++)
        {
            if(a[i][j]=='O')
                h++;
            else if(a[i][j]!='X')
                v=j;
        }
        if((h==2)&&(v>=0))
        {
            a[i][v]='O';
            return m;
        }
    }
    for(i=0; i<3; i++)
    {
        int h=0;
        int v=-1;
        for(int j=0; j<3; j++)
        {
            if(a[j][i]=='O')
                h++;
            else if(a[j][i]!='X')
                v=j;
        }
        if((h==2)&&(v>=0))
        {
            a[v][i]='O';
            return m;
        }
    }
    int gg=0;
    int ff=-1;
    for(i=0; i<3; i++)
    {
        if(a[i][i]=='O')
            gg++;
        else if(a[i][i]!='X')
            ff=i;
    }
    if((gg==2)&&(ff>=0))
    {
        a[ff][ff]='O';
        return m;
    }
    int pak=2,sak=-1;
    int rh=0, nak=-1;
    for(i=0; i<3; i++)
    {
        if(a[i][pak]=='O')
            rh++;
        else if(a[i][pak]!='X')
        {
            nak=pak;
            sak=i;
        }
        pak--;
    }
    if((rh==2)&&(nak>=0)&&(sak>=0))
    {
        a[sak][nak]='O';
        return m;
    }
    m=9;
    return m;
}

void inputt()
{
    char n;
    int x=0;
    cout<<"Enter the field to be replaced."<<endl;
    cin>>n;
    if(n<1&&n>9)
        exit(0);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(n==a[i][j])
            {
                x++;
                a[i][j]='X';
            }
    if(x==0)
    {
        cout<<endl<<"INCORRECT INPUT"<<endl<<endl;
        inputt();
    }
}

void IN()
{
    char n;
    int x=0;
    if(user=='X')
        cout<<"FIRST PLAYER (X)"<<endl;
    else
        cout<<"SECOND PLAYER (O)"<<endl;
    cout<<"Enter the field to be replaced."<<endl;
    cin>>n;
    if(n<1&&n>9)
        exit(0);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(n==a[i][j])
            {
                x++;
                if(user=='X')
                    a[i][j]='X';
                else
                    a[i][j]='O';
            }
    if(x==0)
    {
        cout<<endl<<"INCORRECT INPUT"<<endl<<endl;
        IN();
    }
}

int comp(int m)
{
    if(m==1)
    {
        int e;
        int ssas=1;
        while(ssas)
        {
            e=random(10)+49;
            char t=e;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    if(a[i][j]==t)
                    {
                        a[i][j]='O';
                        ssas=0;
                    }
        }
        m--;
        return m;
    }
    else
    {
        int jjh=1;
        jjh=once(jjh);
        if(jjh==1)
            return m;
        for(int i=0; i<3; i++)
        {
            int h=0;
            int v=-1;
            for(int j=0; j<3; j++)
            {
                if(a[i][j]=='X')
                    h++;
                else if(a[i][j]!='O')
                    v=j;
            }
            if((h==2)&&(v>=0))
            {
                a[i][v]='O';
                return m;
            }
        }
        for(i=0; i<3; i++)
        {
            int h=0;
            int v=-1;
            for(int j=0; j<3; j++)
            {
                if(a[j][i]=='X')
                    h++;
                else if(a[j][i]!='O')
                    v=j;
            }
            if((h==2)&&(v>=0))
            {
                a[v][i]='O';
                return m;
            }
        }
        int gg=0;
        int ff=-1;
        for(i=0; i<3; i++)
        {
            if(a[i][i]=='X')
                gg++;
            else if(a[i][i]!='O')
                ff=i;
        }
        if((gg==2)&&(ff>=0))
        {
            a[ff][ff]='O';
            return m;
        }
        int pak=2,sak=-1;
        int rh=0, nak=-1;
        for(i=0; i<3; i++)
        {
            if(a[i][pak]=='X')
                rh++;
            else if(a[i][pak]!='O')
            {
                nak=pak;
                sak=i;
            }
            pak--;
        }
        if((rh==2)&&(nak>=0)&&(sak>=0))
        {
            a[sak][nak]='O';
            return m;
        }
        int kj;
        int ghf=1;
        while(ghf)
        {
            kj=random(10)+49;
            char tk=kj;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    if(a[i][j]==tk)
                    {
                        a[i][j]='O';
                        ghf=0;
                    }
        }
        return m;
    }
}

void SWITCH()
{
    if(user=='X')
        user='O';
    else
        user='X';
}

int CHECK()
{
    for(int i=0; i<3; i++)
    {
        int m=0;
        int k=0;
        for(int j=0; j<3; j++)
        {
            if(a[i][j]=='X')
                m++;
            if(a[i][j]=='O')
                k++;
        }
        if(m==3)
        {
            cout<<"FIRST PLAYER (X) WON !"<<endl;
            return 1;
        }
        if(k==3)
        {
            cout<<"SECOND PLAYER (Y) WON !"<<endl;
            return 1;
        }
    }
    for(i=0; i<3; i++)
    {
        int m=0;
        int k=0;
        for(int j=0; j<3; j++)
        {
            if(a[j][i]=='X')
                m++;
            if(a[j][i]=='O')
                k++;
        }
        if(m==3)
        {
            cout<<"FIRST PLAYER (X) WON !"<<endl;
            return 1;
        }
        if(k==3)
        {
            cout<<"SECOND PLAYER (Y) WON !"<<endl;
            return 1;
        }
    }
    if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')
    {
        cout<<"FIRST PLAYER (X) WON !"<<endl;
        return 1;
    }
    if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')
    {
        cout<<"SECOND PLAYER (Y) WON !"<<endl;
        return 1;
    }
    if(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
    {
        cout<<"FIRST PLAYER (X) WON !"<<endl;
        return 1;
    }
    if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
    {
        cout<<"SECOND PLAYER (Y) WON !"<<endl;
        return 1;
    }
    return 0;
}

int checkc()
{
    for(int i=0; i<3; i++)
    {
        int m=0;
        int k=0;
        for(int j=0; j<3; j++)
        {
            if(a[i][j]=='X')
                m++;
            if(a[i][j]=='O')
                k++;
        }
        if(m==3)
        {
            cout<<"YOU WON !"<<endl;
            return 1;
        }
        if(k==3)
        {
            cout<<"COMPUTER WON !"<<endl;
            return 1;
        }
    }
    for(i=0; i<3; i++)
    {
        int m=0;
        int k=0;
        for(int j=0; j<3; j++)
        {
            if(a[j][i]=='X')
                m++;
            if(a[j][i]=='O')
                k++;
        }
        if(m==3)
        {
            cout<<"YOU WON !"<<endl;
            return 1;
        }
        if(k==3)
        {
            cout<<"COMPUTER WON !"<<endl;
            return 1;
        }
    }
    if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')
    {
        cout<<"YOU WON !"<<endl;
        return 1;
    }
    if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')
    {
        cout<<"COMPUTER WON !"<<endl;
        return 1;
    }
    if(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
    {
        cout<<"YOU WON !"<<endl;
        return 1;
    }
    if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
    {
        cout<<"COMPUTER WON !"<<endl;
        return 1;
    }
    return 0;
}

void main()
{
    clrscr();
    randomize();
    cout<<"T I C  T A C  T O E"<<endl;
    DISP();
    cout<<endl;
    char corf;
    cout<<"Do you want to play with computer or with your friend? (Enter C or F)"<<endl;
    cin>>corf;
    if(corf=='F')
    {
        cout<<endl<<"FIRST PLAYER : X"<<endl<<"SECOND PLAYER : O"<<endl;
        cout<<endl;
        cout<<"PLEASE NOTE THAT ANY INCORRECT INPUT WILL RESULT IN THE TERMINATON OF THE PROGRAM."<<endl;
        cout<<"Which player would like to start the game? (Enter X or O)"<<endl;
        cin>>user;
        if((user!='X')&&(user!='O'))
            exit(0);
        cout<<endl<<"Starting..."<<endl<<endl;
        int c=9;
        int s=0;
        while(c)
        {
            IN();
            clrscr();
            s=CHECK();
            if(s==1)
            {
                cout<<endl;
                DISP();
                break;
            }
            DISP();
            cout<<endl;
            SWITCH();
            c--;
        }
        if(c==0)
        {
            clrscr();
            cout<<"DRAW :) ";
        }
        getch();
    }
    else if(corf=='C')
    {
        cout<<endl<<"YOU : X"<<endl<<"COMPUTER : O"<<endl;
        cout<<endl;
        char yorn;
        cout<<"PLEASE NOTE THAT ANY INCORRECT INPUT WILL RESULT IN THE TERMINATON OF THE PROGRAM."<<endl;
        cout<<"Do you want to go first? (Enter Y or N)"<<endl;
        cin>>yorn;
        if((yorn!='Y')&&(yorn!='N'))
            exit(0);
        else if(yorn=='Y')
            user='X';
        else
        {
            int pkj=random(10)+49;
            char digk=pkj;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    if(a[i][j]==digk)
                        a[i][j]='O';
            user='X';
        }
        cout<<endl<<"Starting..."<<endl<<endl;
        int c;
        if(yorn=='Y')
            c=5;
        else
            c=4;
        if(c==4)
        {
            DISP();
            cout<<endl;
        }
        int s=0;
        int m=1;
        while(c)
        {
            inputt();
            clrscr();
            cout<<"Your Entry :"<<endl<<endl;
            DISP();
            cout<<endl;
            if(c!=1)
            {
                m=comp(m);
                cout<<"Computer's Entry :"<<endl<<endl;
                DISP();
                cout<<endl;
                s=checkc();
            }
            if(s==1)
            {
                cout<<endl;
                break;
            }
            cout<<endl;
            c--;
        }
        if(c==0)
        {
            clrscr();
            DISP();
            cout<<endl<<"DRAW :) ";
        }
        getch();
    }
    else
        exit(0);
}
