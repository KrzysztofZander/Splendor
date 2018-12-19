#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdio>
#include <conio.h>
#include <string>

using namespace std;

class Table;

class Card
{
    public:

        int white;
        int red;
        int black;
        int green;
        int blue;
        int points;
        int value;
        int checked=0;
        string tmp;

        int parameters[6]={0,0,0,0,0,0};
        int tab1[6]={0,0,0,0,0,0};
        int tab2[6]={0,0,0,0,0,0};



        //Card(int points=0,int value=0,int white=0,int red=0,int black=0,int green=0,int blue=0);
        virtual ~Card();

        void cardLine(int nr)
        {
            if(nr==5){frontCard(1,1);}

            if(nr<5)
            {
                if (value==0)
                {

                        frontCard(1,1);

                }
                else
                {
                int j=0;

                for(int i=1;i<6;i++)
                {
                    if(parameters[i]>0)
                        {
                            tab1[j]=i;tab2[j]=parameters[i];j++;
                        }
                }


                backgroudColor(" ");
                if(tab1[nr]>0)
                {
                    newColorShow(tab1[nr]);backgroudColor("     ");
                }
                else
                {
                    backgroudColor("       ");
                }
                }
            }

        }

        void frontCard(int check,int point)
        {
            if(value==0)cout<<"        ";
            else
            {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_RED | BACKGROUND_GREEN| BACKGROUND_INTENSITY);
            if(points){cout<<"     "<<points;}
            else
                cout<<"      ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            if(value==1)//Bialy
            {
                whiteColor();whiteColor();
            }
            if(value==2)//Czerwony
            {
                redColor();redColor();
            }
            if(value==3)//Czarny
            {
                blackColor();blackColor();
            }
            if(value==4)//Zielony
            {
                greenColor();greenColor();
            }
            if(value==5)//Niebieski
            {
                blueColor();blueColor();
            }
            }
        }

        void whiteColor()
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        void redColor()
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut,BACKGROUND_RED|BACKGROUND_INTENSITY);
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        void blackColor()
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_BLUE|BACKGROUND_RED);
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        void greenColor()
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        void blueColor()
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
         void goldColor()
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_INTENSITY);
            int y=4;
            char wynik = (char)y;
            cout<<wynik;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

        }
        void backgroudColor(string a)
        {
            if(checked==0)
            {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_RED | BACKGROUND_GREEN);
            cout<<a;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
            if(checked==1)
            {
             HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_GREEN);
            cout<<a;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
        }
        void buffor()
        {
            backgroudColor("       ");
            cout<<" ";
        }
        void SetCard(int _white,int _red, int _black, int _green,int _blue, int _points,int color)
        {
        white=_white;
        red=_red;
        black=_black;
        green=_green;
        blue=_blue;
        points=_points;
        value=color;

        parameters[1]=white;
        parameters[2]=red;
        parameters[3]=black;
        parameters[4]=green;
        parameters[5]=blue;

        }
        void newColorShow(int nr)
        {
            switch (nr)
            {
                case 1:{whiteColor(); pointsNumber(parameters[1]);break;}
                case 2:{redColor(); pointsNumber(parameters[2]);break;}
                case 3:{blackColor(); pointsNumber(parameters[3]);break;}
                case 4:{greenColor(); pointsNumber(parameters[4]);break;}
                case 5:{blueColor(); pointsNumber(parameters[5]);break;}
                default :break;


            }
        }
        void pointsNumber(int nr)
        {
                    sprintf((char*)tmp.c_str(), "%d", nr);
                    string str = tmp.c_str();
                    backgroudColor(str);
        }
    private:

};

class Arystoc :public Card
{
    public:
    int arystColor[5]={0,0,0,0,0};
    string arystColorName[5]={"red","blue","black","white","green"};
    int arystpoint=3;

    void frontCard(Arystoc a)
    {
        if(a.points)
        {
            HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_GREEN|BACKGROUND_INTENSITY);
        cout<<"    "<<a.points;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<" ";
        }
        else
        {   HANDLE hOut;
            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                    cout<<"      ";

        }
    }

    void checkcolor(Arystoc a, int i)
    {
                HANDLE hOut;
                hOut = GetStdHandle( STD_OUTPUT_HANDLE );
                SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_GREEN);

                if((a.arystColor[i]<10)&&(a.arystColor[i]>0))
                {
                    if(i==0)redColor();
                    if(i==1)blueColor();
                    if(i==2)blackColor();
                    if(i==3)whiteColor();
                    if(i==4)greenColor();
                    SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_GREEN);
                    cout<<a.arystColor[i];
                    cout<<"   ";
                }
                else if(a.arystColor[i]==99)
                {
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                    cout<<"     ";

                }
                    else
                    cout<<"     ";
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                    cout<<" ";
    }
    void getAryst(Arystoc b,int i)
    {
        frontCard(b);
        checkcolor(b,i);
    }
    void setAryst(int _red,int _blue,int _black,int _white,int _green)
    {
        arystColor[0]=_red;
        arystColor[1]=_blue;
        arystColor[2]=_black;
        arystColor[3]=_white;
        arystColor[4]=_green;
        points=3;
    }



};
class Gracz
{
    private:

    public:

        string name;

        Card onHand[100];
        Card reserve[5];
        Arystoc hand[30];
        int next=0;
        Card temp;
        int playerCoin[6]={0,0,0,0,0,0};
        int numberOfCard[5]={0,0,0,0,0};
        int arystiterator=0;
        int carditerator=0;
        int reserveIterator=0;
        int autoplay=0;
        int points=0;
        int numberOfRound=0;
        bool exist=false;
        bool si=false;

        string playerCoinName[6]={"red","blue","black","white","green","gold"};

        void showPlayerCoin(int coins[])
        {
        if(coins[0]){temp.redColor();cout<<coins[0]<<" ";}
        if(coins[1]){temp.blueColor();cout<<coins[1]<<" ";}
        if(coins[2]){temp.blackColor();cout<<coins[2]<<" ";}
        if(coins[3]){temp.whiteColor();cout<<coins[3]<<" ";}
        if(coins[4]){temp.greenColor();cout<<coins[4]<<" ";}
        if(coins[5]){temp.goldColor();cout<<coins[5]<<" ";}

    }
        void showPlayerCard ()
        {
            countPlayerCards();

            if(numberOfCard[3]){onHand->whiteColor();cout<<numberOfCard[3]<<" ";}

            if(numberOfCard[0]){onHand->redColor();cout<<numberOfCard[0]<<" ";}

            if(numberOfCard[2]){onHand->blackColor();cout<<numberOfCard[2]<<" ";}

            if(numberOfCard[4]){onHand->greenColor();cout<<numberOfCard[4]<<" ";}

            if(numberOfCard[1]){onHand->blueColor();cout<<numberOfCard[1]<<" ";}

        }
        void countPlayerCards ()
        {
            for (int i=0;i<5;i++)
            {
                numberOfCard[i]=0;
            }

            for (int i=0;i<40;i++)// Biale karty
            {
                    if(onHand[i].value==1)
                    {
                        numberOfCard[3]++;
                    }
            }

             for (int i=0;i<40;i++)// Czerwone karty
            {
                    if(onHand[i].value==2)
                    {
                        numberOfCard[0]++;
                    }
            }

            for (int i=0;i<40;i++)// Czarne karty
            {
                    if(onHand[i].value==3)
                    {
                        numberOfCard[2]++;
                    }
            }

            for (int i=0;i<40;i++)// Zielone karty
            {
                    if(onHand[i].value==4)
                    {
                        numberOfCard[4]++;
                    }
            }

            for (int i=0;i<40;i++)// Niebieskie karty
            {
                    if(onHand[i].value==5)
                    {
                        numberOfCard[1]++;
                    }
            }

        }
        void showPlayerPionts ()
        {
            cout<<countPlayerPoints();cout<<endl<<endl;
        }
        int countPlayerPoints ()
        {
            points=0;
            for(int i=0;i<30;i++)
            {
                points+=onHand[i].points;
                points+=hand[i].points;
            }
            return points;

        }
};
class Menu
{
    public:


    int show(int type,int start,int rows,string options[])
    {
        int retnum;
        int choose=start;
        int enter;

            if(type==1)
            {
                while (enter!=13)
                {
                    gotoxy(1,39);
                    for(int i=1;i<=rows;i++)
                    {
                        if (choose==i)
                        {
                            HANDLE hOut;
                            hOut = GetStdHandle( STD_OUTPUT_HANDLE );
                            SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                            cout<<options[i]<<endl;
                            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                            retnum=i;
                        }
                        else
                        {
                            cout<<options[i]<<endl;
                        }
                    }
                    enter=_getch();
                    switch (enter)
                    {
                        case 224:
                                    if (kbhit() )
                                    {
                                    int znak1=getch();
                                    switch(znak1)
                                        {
                                        case 72:{choose-=1;break;}  //{ if(start<1){start=1; return start;break;}return start-=1;break;}  // przesuniêcie do góry
                                        case 80: {choose+=1;break;} //{ if(start>=rows){start=rows; return start;break;};return start+=1;break;}  // przesuniecie w dól
                                        }
                                    if(choose>=rows){choose=rows;}
                                    if(choose<1){choose=1;}
                                    break;
                                    }
                        case 13: {return choose;break;}
                        default: {break;}

                    }
                    cout<<choose;
                }
            }

            if(type==2)
            {
                int enter=0;
                int ii;
                for(int i=1;i<=rows;i++)
                {
                    if(choose==i){ii=i;}
                }
                enter= _getch();

                switch (enter)
                {
                    case 224:
                            if (kbhit() )
                            {
                                int znak1=getch();
                                switch(znak1)
                                    {
                                        case 75:{start--;		         break;}  // przesuniêcie w lewo
                                        case 77:{start++;				 break;}  // przesuniêcie w prawo
                                        case 72:{start+=4;if(start>rows)start-=4;				 break;}  // przesuniêcie do góry
                                        case 80:{start-=4;if(start<=0)start+=4;				 break;}  // przesuniecie w dó³
                                    }
                                    if(start>rows)start=rows;if(start<=0)start=1;
                                    return start;break;
                            }
                    case 13: {return start*100;break;}

                }




            }

    }
    void gotoxy(int x, int y)
    {
      COORD c;
      c.X = x - 1;
      c.Y = y - 1;
      SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

};

class Table :public Card
{
    public:
    Card one[40];
    Card two[30];
    Card three[20];
    Card blank;
    Card temp;
    Card onTable[13];
    Arystoc arystOnTable[6];
    Menu menu;

    bool gra=true;

    Arystoc arys[10];
    int arystTableSet=0;
    int numPlayers=1;
    int current;
    Gracz player[5];
    string plname[5]={"pierwszego","drugiego","trzeciego","czwartego","piatego"};
    vector<Card> oneStar;
    vector<Card> twoStar;
    vector<Card> threeStar;
    vector<Arystoc> ArystDeck;
    vector<Gracz> playerline;
    int coins[6]={4,4,4,4,4,4};
    string coinColor[6]={"red","blue","black","white","green","gold"};




    void SetNumberOfPlayers()
    {
        int playerVSautoplay;

        system("cls");

        while((numPlayers<2)||(numPlayers>4))
        {
        char numer;
        cout<<"Witaj, podaj liczbe wszystkich  graczy (od 2 do 4 ):";
        cin>>numer;
        if (isdigit(numer))
        {
            numPlayers=atoi(&numer);
        }
            system("cls");
        }
        cout<<"ile z tego to gracze komputerowi ?"<<endl;
        cin>>playerVSautoplay;
        cout<<endl;
        for (int i=0;i<numPlayers;i++)
        {
            cout<<"Podaj imie "<<plname[i]<<" gracza :";cin>>player[i].name;
            player[i].exist=true;
            if (i>=numPlayers-playerVSautoplay){player[i].autoplay=1;}
            playerline.push_back(player[i]);
            cout<<endl;
        }
    }

    // Karty
    void initCard()
    {
           //###############KARTY#####################
        // 1. white // 2. red // 3. black // 4. green // 5. blue //

        blank.value=0;
        int tr=0;
        for(int j=0;j<numPlayers;j++)
        {
        for (int i=0;i<30;i++)
        {
            player[j].onHand[i].points=0;
            player[j].hand[i].points=0;
        }
        }
        // Arystokraci
        arys[0].setAryst(4,0,4,0,0);
        arys[1].setAryst(4,0,0,0,4);
        arys[2].setAryst(0,3,3,3,0);
        arys[3].setAryst(0,0,4,4,0);
        arys[4].setAryst(3,3,0,0,3);
        arys[5].setAryst(3,0,3,3,0);
        arys[6].setAryst(3,0,3,0,3);
        arys[7].setAryst(0,4,0,0,4);
        arys[8].setAryst(0,3,0,3,3);
        arys[9].setAryst(0,4,0,4,0);
        // *** Karty
        three[tr++].SetCard(0,6,3,3,0,4,3);
        three[tr++].SetCard(0,0,7,0,0,4,1);
        three[tr++].SetCard(3,0,0,3,6,4,4);
        three[tr++].SetCard(0,0,0,3,7,5,4);
        three[tr++].SetCard(0,3,0,6,3,4,2);
        three[tr++].SetCard(3,3,0,5,3,3,3);
        three[tr++].SetCard(3,0,7,0,0,5,1);
        three[tr++].SetCard(7,0,0,0,3,5,5);
        three[tr++].SetCard(0,7,3,0,0,5,3);
        three[tr++].SetCard(0,3,0,7,0,5,2);
        three[tr++].SetCard(0,0,0,7,0,4,2);
        three[tr++].SetCard(6,0,3,0,3,4,5);
        three[tr++].SetCard(0,0,0,0,7,4,4);
        three[tr++].SetCard(3,0,3,3,5,3,2);
        three[tr++].SetCard(0,5,3,3,3,3,1);
        three[tr++].SetCard(3,3,5,3,0,3,5);
        three[tr++].SetCard(5,3,3,0,3,3,4);
        three[tr++].SetCard(3,3,6,0,0,4,1);
        three[tr++].SetCard(0,7,0,0,0,4,3);
        three[tr++].SetCard(7,0,0,0,0,4,5);

        tr=0;// reset licznika
        // 1. white // 2. red // 3. black // 4. green // 5. blue //
        // ** Karty
        two[tr++].SetCard(5,0,0,0,3,2,5);
        two[tr++].SetCard(0,0,6,0,0,3,3);
        two[tr++].SetCard(0,0,5,0,0,2,2);
        two[tr++].SetCard(2,2,3,0,0,1,2);
        two[tr++].SetCard(3,0,2,3,0,1,3);
        two[tr++].SetCard(0,0,0,5,0,2,4);
        two[tr++].SetCard(0,4,2,1,0,2,1);
        two[tr++].SetCard(2,1,4,0,0,2,5);
        two[tr++].SetCard(0,2,3,0,3,1,2);
        two[tr++].SetCard(3,3,0,2,0,1,4);
        two[tr++].SetCard(0,0,0,3,5,2,4);
        two[tr++].SetCard(0,0,0,0,5,2,5);
        two[tr++].SetCard(3,0,0,2,2,1,3);
        two[tr++].SetCard(2,3,0,0,3,1,1);
        two[tr++].SetCard(3,0,5,0,0,2,2);
        two[tr++].SetCard(0,3,0,5,0,2,3);
        two[tr++].SetCard(6,0,0,0,0,3,1);
        two[tr++].SetCard(0,6,0,0,0,3,2);
        two[tr++].SetCard(0,0,0,6,0,3,4);
        two[tr++].SetCard(2,0,2,0,3,1,4);
        two[tr++].SetCard(0,2,0,4,1,2,3);
        two[tr++].SetCard(0,3,0,2,2,1,5);
        two[tr++].SetCard(1,0,0,2,4,2,2);
        two[tr++].SetCard(0,0,3,3,2,1,5);
        two[tr++].SetCard(0,2,2,3,0,1,1);
        two[tr++].SetCard(4,0,1,0,2,2,4);
        two[tr++].SetCard(0,5,3,0,0,2,1);
        two[tr++].SetCard(0,0,0,0,6,3,5);
        two[tr++].SetCard(0,5,0,0,0,2,1);
        two[tr++].SetCard(5,0,0,0,0,2,3);

        tr=0;// reset licznika
        // 1. white // 2. red // 3. black // 4. green // 5. blue //
        // * Karty

        one[tr++].SetCard(1,2,1,1,0,0,5);
        one[tr++].SetCard(3,0,1,0,1,0,1);
        one[tr++].SetCard(0,0,0,4,0,1,1);
        one[tr++].SetCard(0,0,0,0,3,0,1);
        one[tr++].SetCard(4,0,0,0,0,1,2);
        one[tr++].SetCard(3,0,0,0,0,0,2);
        one[tr++].SetCard(0,0,0,0,4,1,3);
        one[tr++].SetCard(1,2,0,2,0,0,5);
        one[tr++].SetCard(0,4,0,0,0,1,5);
        one[tr++].SetCard(0,0,3,0,0,0,5);
        one[tr++].SetCard(0,0,0,3,0,0,3);
        one[tr++].SetCard(1,1,0,1,2,0,3);
        one[tr++].SetCard(0,1,0,2,0,0,3);
        one[tr++].SetCard(0,3,1,1,0,0,3);
        one[tr++].SetCard(2,0,2,1,0,0,2);
        one[tr++].SetCard(2,2,0,0,0,0,2);
        one[tr++].SetCard(1,1,3,0,0,0,2);
        one[tr++].SetCard(1,0,1,1,1,0,2);
        one[tr++].SetCard(0,1,1,2,1,0,1);
        one[tr++].SetCard(0,0,1,2,2,0,1);
        one[tr++].SetCard(0,3,0,0,0,0,4);
        one[tr++].SetCard(1,1,2,0,1,0,4);
        one[tr++].SetCard(2,0,0,0,1,0,4);
        one[tr++].SetCard(0,0,4,0,0,1,4);
        one[tr++].SetCard(0,2,2,0,1,0,4);
        one[tr++].SetCard(0,0,2,2,0,0,5);
        one[tr++].SetCard(0,1,0,3,1,0,5);
        one[tr++].SetCard(0,2,0,0,2,0,4);
        one[tr++].SetCard(2,0,1,1,1,0,2);
        one[tr++].SetCard(2,0,0,2,0,0,3);
        one[tr++].SetCard(2,1,0,0,2,0,3);
        one[tr++].SetCard(1,1,0,1,1,0,3);
        one[tr++].SetCard(0,0,0,1,2,0,2);
        one[tr++].SetCard(1,1,1,1,0,0,5);
        one[tr++].SetCard(1,0,2,0,0,0,5);
        one[tr++].SetCard(0,2,1,0,0,0,1);
        one[tr++].SetCard(0,0,2,0,2,0,1);
        one[tr++].SetCard(0,1,1,1,1,0,1);
        one[tr++].SetCard(1,1,1,0,1,0,4);
        one[tr++].SetCard(1,0,0,1,3,0,4);





        int lengtho = sizeof(one)/sizeof(Card);
        int lengthtw = sizeof(two)/sizeof(Card);
        int lengthth= sizeof(three)/sizeof(Card);
        int lengtarys=sizeof(arys)/sizeof(Arystoc);
        shuffleAryst(ArystDeck,arys,lengtarys);
        shuffleDeck(oneStar,one,lengtho);
        shuffleDeck(twoStar,two,lengthtw);
        shuffleDeck(threeStar,three,lengthth);
        for(int i=0;i<4;i++)
        {
            oneStar.push_back(blank);
            twoStar.push_back(blank);
            threeStar.push_back(blank);
        }

        for (int i=0;i<=numPlayers;i++)
                {
                    arystOnTable[i]=ArystDeck[i];
                    arystOnTable[i].setAryst(1,0,0,0,0);
                }
    }

    void shuffleDeck(vector<Card> &deck, Card card[],int length)
    {
        int next[length];

        for(int i=0;i<length;i++)
        {
            next[i]=rand()%length;

            for(int j=0;j<i;j++)
            {
                if (next[j]==next[i])
                {
                    next[i]=rand()%length;
                    j=-1;
                }
            }

        }
        for(int i=0;i<length;i++)
        {
            deck.push_back(card[next[i]]);

        }
    }
    void shuffleAryst(vector<Arystoc> &deck, Arystoc card[],int length)
    {
        int next[length];

        for(int i=0;i<length;i++)
        {
            next[i]=rand()%length;

            for(int j=0;j<i;j++)
            {
                if (next[j]==next[i])
                {
                    next[i]=rand()%length;
                    j=-1;
                }
            }

        }
        for(int i=0;i<length;i++)
        {
            deck.push_back(card[next[i]]);

        }
    }
    void updateTable()
    {
        for (int i=1;i<5;i++)
        {
            onTable[i]=oneStar[i-1];
            onTable[i+4]=twoStar[i-1];
            onTable[i+8]=threeStar[i-1];
        }
        onTable[0].value=0;

        playerline[0].countPlayerPoints();
    }
   void showCardFromDeck(int acc,int numer,vector<Card> deck)
   {
       for(int k=numer;k<numer+4;k++)
                {
                if(k<10)cout<<" Karta "<<k<<" ";
                else cout<<" Karta"<<k<<" ";
                }
        cout<<endl;
        for(int i=5;i>=0;i--)
        {
            for(int j=numer;j<numer+5;j++)
            {
                if(j<numer+4)
                {
                onTable[j].cardLine(i);cout<<" ";
                }
                if(j==numer+4&&i!=2){onTable[0].backgroudColor("        ");}
                if(j==numer+4&&i==2)
                    {
                        char isleft[33];
                        if(deck.size()>=18){deck.back().backgroudColor("   ");}
                        else{deck.back().backgroudColor("    ");}
                        string left= itoa((deck.size()-8),isleft,10);
                        if(deck.size()>=9){deck.back().backgroudColor(left);}
                        else{deck.back().backgroudColor(" ");}
                        deck.back().backgroudColor("   ");
                    }
            }
            if(i==5&&acc+1<=numPlayers){cout<<" "<<playerline[acc].name;}
            if(i==3&&acc+1<=numPlayers){cout<<" Zetony:";playerline[acc].showPlayerCoin(playerline[acc].playerCoin);}
            if(i==2&&acc+1<=numPlayers){cout<<" Karty:";playerline[acc].showPlayerCard();}
            if(i==1&&acc+1<=numPlayers){cout<<" Punkty:"<<playerline[acc].countPlayerPoints();}

        cout<<endl;
        }

   }
   void showCard2()
   {
       showAryst(numPlayers+1);
       showCardFromDeck(3,9,threeStar);
       showCardFromDeck(2,5,twoStar);
       showCardFromDeck(1,1,oneStar);
   }
    void showAryst(int dlugosc)
    {
        cout<<"      ";

        for (int i=0;i<dlugosc;i++)
        {

        arystOnTable[i].frontCard(arystOnTable[i]);
        }
        cout<<endl;
        for (int j=0;j<5;j++)
        {

        cout<<"      ";
        for(int i=0;i<dlugosc;i++)
        {
            arystOnTable[i].checkcolor(arystOnTable[i],j);
        }

        cout<<endl;
        }

    }
    void showReservcard(Gracz* acc,int lenght)
    {
        for(int i=0;i<lenght;i++)
        {cout<<i+1<<"."<<"       ";
        }
        cout<<endl;
        for(int k=5;k>=0;k--)
        {
        for(int i=0;i<lenght;i++)
        {
            if(acc->reserve[i].value){acc->reserve[i].cardLine(k);cout<<" ";}
        }
        cout<<endl;
        }

    }
    void getAryst ( Arystoc arys )
    {
        cout<<"      ";
        arys.frontCard(arys);
        cout<<endl;
        for (int j=0;j<5;j++)
        {

        cout<<"      ";

        arys.checkcolor(arys,j);

        cout<<endl;
        }



    }
    // Zetony
    void showCoin(int coins[])
    {
        if(coins[0]){temp.redColor();cout<<coins[0]<<" ";}
        if(coins[1]){temp.blueColor();cout<<coins[1]<<" ";}
        if(coins[2]){temp.blackColor();cout<<coins[2]<<" ";}
        if(coins[3]){temp.whiteColor();cout<<coins[3]<<" ";}
        if(coins[4]){temp.greenColor();cout<<coins[4]<<" ";}
        if(coins[5]){temp.goldColor();cout<<coins[5]<<" ";}
        cout<<endl;


    }

    // Akcje
    void action(Gracz* active)
    {
        int endTr=0;
        int cnumber=0;
        int reserveCard=55;
        int choose=1;

        playerStatus(active);

        string playermanu[5]{" ","Pobierz zetony","Pobierz karte","Rezerwuj Karte","Zobacz zarezerwowane"};

        choose=menu.show(1,choose,4,playermanu);

        switch(choose)
        {
            case 1:
                {       // Wybor zetonow ( skonczone !)
                        menu.gotoxy(1,30);
                        cout<<endl<<"Tura gracza "<<active->name<<endl<<endl<<"Twoje zetony:";
                        active->showPlayerCoin(active->playerCoin);
                        cout<<endl<<endl<<"Twoje karty:";
                        active->showPlayerCard();
                        cout<<endl<<endl<<"Twoje punkty:";active->showPlayerPionts();


                    char pickcoin[3];

                    int choosenCoin[5]={0,0,0,0,0};
                    cout<<"Wybierz zetony"<<endl;
                    cout<<"1.";temp.redColor();cout<<"                      "<<endl;
                    cout<<"2.";temp.blueColor();cout<<"                     "<<endl;
                    cout<<"3.";temp.blackColor();cout<<"                     "<<endl;
                    cout<<"4.";temp.whiteColor();cout<<"                    "<<endl;
                    cout<<"5.";temp.greenColor();cout<<"                     "<<endl<<endl;

                    for (int i=0;i<3;i++)
                    {
                        int check=0;
                        while ((check<=0||check>5)||(!isdigit(pickcoin[i])))
                        {
                            pickcoin[i]=_getch();
                            check=atoi(&pickcoin[i]);
                        }

                    int numOfCoin=selectCoin(pickcoin[i]);
                    choosenCoin[numOfCoin]++;

                    if(choosenCoin[numOfCoin]>=2)
                    {
                        int tooMuchCoin=0;
                        for (int k=0;k<5;k++)
                        {
                            if(choosenCoin[k])
                            {
                                tooMuchCoin++;
                            }
                            if(tooMuchCoin>=2)
                            {
                                cout<<"<- Nie mozesz teraz pobrac kolejnego zetonu tego koloru"<<endl;
                                i--;
                                choosenCoin[numOfCoin]--;
                                break;
                            }


                        }

                        if ((choosenCoin[numOfCoin]>=2)&&(coins[numOfCoin]<4))
                        {
                        cout<<"Na stole musza byc przynajmniej 4 zetony tego koloru, by pobrac 2 sztuki"<<endl<<"Wybierz jeszcze raz !"<<endl;
                        _getch();break;
                        }
                    }
                    if(coins[numOfCoin]<=0)
                    {
                        cout<<"<- Tego zetonu nie ma na stole, nie mozesz go pobrac !"<<endl<<"Wybierz jeszcze raz !"<<endl;
                        _getch();break;
                    }


                        for (int j=0;j<5;j++)
                        {
                            if((choosenCoin[j]>=2)||(i==2))
                            {
                            cout<<endl<<"Czy chcesz pobrac te zetony ?  ";
                                if(choosenCoin[0]==1){selectCoin('1');}
                                if(choosenCoin[0]==2){selectCoin('1');selectCoin('1');}
                                if(choosenCoin[1]==1){selectCoin('2');}
                                if(choosenCoin[1]==2){selectCoin('2');selectCoin('2');}
                                if(choosenCoin[2]==1){selectCoin('3');}
                                if(choosenCoin[2]==2){selectCoin('3');selectCoin('3');}
                                if(choosenCoin[3]==1){selectCoin('4');}
                                if(choosenCoin[3]==2){selectCoin('4');selectCoin('4');}
                                if(choosenCoin[4]==1){selectCoin('5');}
                                if(choosenCoin[4]==2){selectCoin('5');selectCoin('5');}
                            cout<<endl<<"Wcisnij dowolny klawisz by zatwierdzic, lub ''n'' , by anulowac"<<endl;
                                char decysion;
                                decysion=_getch();
                                if(decysion=='n'){i=3;cout<<"Zdecyduj sie ;-)";_getch();break;}
                                else
                                {
                                    for (int t=0;t<5;t++)
                                    {
                                    active->playerCoin[t]+=choosenCoin[t];
                                    coins[t]-=choosenCoin[t];
                                    }
                                    i=3;endTr=1;
                                    screenReset();

                                    cout<<endl<<endl<<" POBRANE ZETONY  ";
                                    if(choosenCoin[0]==1){selectCoin('1');}
                                if(choosenCoin[0]==2){selectCoin('1');selectCoin('1');}
                                if(choosenCoin[1]==1){selectCoin('2');}
                                if(choosenCoin[1]==2){selectCoin('2');selectCoin('2');}
                                if(choosenCoin[2]==1){selectCoin('3');}
                                if(choosenCoin[2]==2){selectCoin('3');selectCoin('3');}
                                if(choosenCoin[3]==1){selectCoin('4');}
                                if(choosenCoin[3]==2){selectCoin('4');selectCoin('4');}
                                if(choosenCoin[4]==1){selectCoin('5');}
                                if(choosenCoin[4]==2){selectCoin('5');selectCoin('5');}
                                    _getch();
                                }

                            }

                        }
                    }




                break;}
            case 2:
                {       // Wybor Karty ( skonczone ! )

                    cnumber=1;
                    int old;
                    while (cnumber<13)
                    {
                        if(cnumber<13){onTable[cnumber].checked=1;}
                        screenReset();
                        playerStatus(active);
                        old=cnumber;
                        cnumber=menu.show(2,cnumber,12,NULL);
                        if(cnumber<13){onTable[old].checked=0;}

                    }
                    cnumber=cnumber/100;

                    getCard(cnumber, active, endTr);
                    ifAryst(active);
                break;}
            case 3:
                {       // Rezerwacja ( skonczone !)
                    char pick;
                    if(coins[5]>=1)
                    {
                    cout<<"Wybierz karte ,lub 0 by wyjsc ";
                    while (reserveCard<0||reserveCard>=13)
                        {
                            pick=_getch();
                            reserveCard=atoi(&pick);
                        }
                        if(reserveCard==0)break;
                        else
                        {
                        resCard(reserveCard,active, endTr);
                        active->playerCoin[5]+=1;
                        coins[5]-=1;
                        endTr=1;
                        }

                    }
                    else
                    {
                        cout<<"Nie mozna zarezerwowac karty, na stole nie ma zlotych zetonow !";
                        _getch();
                    }

                break;
                }
            case 4:
                {       // Wybor zarezerwowanej
                    int lenght=0;
                    for(int i=0;i<5;i++)
                    {
                        if(active->reserve[i].value>0)lenght++;
                    }
                    if(lenght>0)
                    {
                    char pick;
                    int choice;
                    showReservcard(active,lenght);
                    cout<<endl<<"Wybierz karte lub 0 by wyjsc ";
                    do{
                            pick=_getch();
                            choice=atoi(&pick);
                    cout<<endl;
                    }while(choice>lenght);
                    if(choice==0)break;
                    int ok=cardAfford(active,active->reserve[choice-1]);
                    if(ok>=1)
                    {
                        active->onHand[active->carditerator++]=active->reserve[choice-1];
                        for (int i=choice-1;i<lenght;i++)
                        {
                            active->reserve[i]=active->reserve[i+1];
                        }
                        active->reserveIterator--;
                        cout<<endl<<"Pobrano karte !";
                        ifAryst(active);
                        endTr=1;
                    }

                    }
                    else cout<<"Nie masz zarezerwowanych kart";
                    _getch();
                break;}
            default:{cout<<endl<<endl<<"Cos poszlo nie tak";_getch();break;}
        }

        if (endTr)endTurn();
    }

    void getCard(int cnumber, Gracz* acc,int &endTr)
    {
        Card* choice;
        int n;
        int ok;
                if((cnumber<=4)&&(oneStar[cnumber-1].value==0))
                {
                    cout<<"Nie ma takiej karty";
                }

                if ((cnumber<=4)&&(oneStar[cnumber-1].value))
                {

                    n=cnumber-1;
                    choice=&oneStar[n];
                    ok=(cardAfford(acc,oneStar[n]));
                    if (ok)
                    {
                    acc->onHand[acc->carditerator++]=*choice;
                    oneStar[n]=oneStar[4];
                    oneStar.erase(oneStar.begin()+4);
                    endTr=1;
                    onTable[cnumber].value=0;
                    cout<<"Pobrano karte nr :"<<cnumber;
                    if(acc->autoplay){acc->si=true;}
                    }


                }
                if (((cnumber>4)&&(cnumber<9))&&(twoStar[cnumber-5].value==0))
                {
                    cout<<"Nie ma takiej karty";
                }

                if (((cnumber>4)&&(cnumber<9))&&(twoStar[cnumber-5].value))
                {
                    n=cnumber-5;
                    choice=&twoStar[n];
                    ok=(cardAfford(acc,twoStar[n]));
                    if (ok)
                    {
                    acc->onHand[acc->carditerator++]=*choice;
                    twoStar[n]=twoStar[4];
                    twoStar.erase(twoStar.begin()+4);
                    endTr=1;
                    onTable[cnumber].value=0;
                    cout<<"Pobrano karte nr :"<<cnumber;
                    if(acc->autoplay){acc->si=true;}
                    }

                }
                 if (((cnumber>=9)&&(cnumber<13))&&(threeStar[cnumber-9].value==0))
                {
                    cout<<"Nie ma takiej karty";
                }

                if (((cnumber>=9)&&(cnumber<13))&&(threeStar[cnumber-9].value))
                {
                    n=cnumber-9;
                    choice=&threeStar[n];
                    ok=(cardAfford(acc,threeStar[n]));
                    if (ok)
                    {
                    acc->onHand[acc->carditerator++]=*choice;
                    threeStar[n]=threeStar[4];
                    threeStar.erase(threeStar.begin()+4);
                    onTable[cnumber].value=0;
                    cout<<"Pobrano Karte nr :"<<cnumber;
                    if(acc->autoplay){acc->si=true;}
                    endTr=1;
                    }
                }
               if(!acc->autoplay) _getch();

    }
    void resCard(int cnumber, Gracz* acc,int &endTr)
    {
        Card* choice;
        int n;
        int ok=1;
                if((cnumber<=4)&&(oneStar[cnumber-1].value==0))
                {
                    cout<<"Nie ma takiej karty";
                }

                if ((cnumber<=4)&&(oneStar[cnumber-1].value))
                {

                    n=cnumber-1;
                    choice=&oneStar[n];
                    if (ok)
                    {
                    acc->reserve[acc->reserveIterator++]=*choice;
                    oneStar[n]=oneStar[4];
                    oneStar.erase(oneStar.begin()+4);
                    endTr=1;
                    cout<<"Zarezerwowano karte nr :"<<cnumber;
                    }


                }
                if (((cnumber>4)&&(cnumber<9))&&(twoStar[cnumber-5].value==0))
                {
                    cout<<"Nie ma takiej karty";
                }

                if (((cnumber>4)&&(cnumber<9))&&(twoStar[cnumber-5].value))
                {
                    n=cnumber-5;
                    choice=&twoStar[n];
                    if (ok)
                    {
                    acc->reserve[acc->reserveIterator++]=*choice;
                    twoStar[n]=twoStar[4];
                    twoStar.erase(twoStar.begin()+4);
                    endTr=1;
                    cout<<"Zarezerwowano karte nr :"<<cnumber;
                    }

                }
                 if (((cnumber>=9)&&(cnumber<13))&&(threeStar[cnumber-9].value==0))
                {
                    cout<<"Nie ma takiej karty";
                }

                if (((cnumber>=9)&&(cnumber<13))&&(threeStar[cnumber-9].value))
                {
                    n=cnumber-9;
                    choice=&threeStar[n];
                    if (ok)
                    {
                    acc->reserve[acc->reserveIterator++]=*choice;
                    threeStar[n]=threeStar[4];
                    threeStar.erase(threeStar.begin()+4);
                    cout<<"Zarezerwowano karte nr :"<<cnumber;
                    endTr=1;
                    }
                }
                _getch();

    }

    void ifAryst(Gracz* acc)
    {
        acc->countPlayerCards ();

        for(int j=0;j<numPlayers+1;j++)

        {
            int ok=1;
            for(int i=0;i<5;i++)
            {

                if(acc->numberOfCard[i]<arystOnTable[j].arystColor[i])
                    {
                        ok=0;
                    }

            }
                if(ok)
                {   Arystoc ne[1];
                    acc->hand[acc->arystiterator++]=arystOnTable[j];
                    ne[0]=arystOnTable[j];

                for(int k=0;k<5;k++)
                {
                    arystOnTable[j].arystColor[k]=99;
                    arystOnTable[j].points=0;
                }
                    system("cls");
                    getAryst(ne[0]);
                    cout<<"Zdobywasz Karte"<<endl;
                    getch();
                }

        }


    }
    void endTurn()
    {
        if(checkNumberOfCoin(&playerline[0])>10)

                        {




                            cout<<endl<<endl<<"Masz wiecej niz 10 zetonow, odloz nadmiarowe !"<<endl<<endl;

                                char choose;
                                cout<<endl<<endl<<"Wybierz zeton"<<endl;
                                cout<<"1.";temp.redColor();cout<<endl;
                                cout<<"2.";temp.blueColor();cout<<endl;
                                cout<<"3.";temp.blackColor();cout<<endl;
                                cout<<"4.";temp.whiteColor();cout<<endl;
                                cout<<"5.";temp.greenColor();cout<<endl;

                            while(checkNumberOfCoin(&playerline[0])>10)
                            {



                                cout<<"\rTwoje zetony :"; playerline[0].showPlayerCoin(playerline[0].playerCoin);cout<<"Odlozono: ";
                                int decyscion=10;
                                if(!playerline[0].autoplay){choose=_getch();
                                decyscion=selectCoin(choose);}
                                if(playerline[0].autoplay==1)
                                    {
                                    int y=rand()%5+49;
                                    char wynik = (char)y;
                                    if(playerline[0].playerCoin[y-1])decyscion=selectCoin(wynik);
                                    }
                                if(playerline[0].playerCoin[decyscion])
                                {
                                    playerline[0].playerCoin[decyscion]--;
                                    coins[decyscion]++;
                                    if(playerline[0].autoplay)Sleep(1000);
                                }

                            }
                            Sleep(1000);
                        }

        playerline[0].countPlayerPoints();
        screenReset();
        playerline[0].numberOfRound++;
        int allPlayersround=0;
        for (int i=0;i<numPlayers;i++)
        {
                allPlayersround+=playerline[i].numberOfRound;

        }

        if((playerline[0].points>=15)&&(allPlayersround%numPlayers==0))
        {
            system("cls");
            cout<<"                     K O N I E C  G R Y"<<endl<<endl;
            cout<<" W Y G R Y W A :    "<<playerline[0].name<<endl<<" Z D O B Y W A J A C   "<<playerline[0].points<<"   P U N K T O W"<<endl<<endl<<endl;
            for (int i=0;i<numPlayers;i++)
            {
                cout<<playerline[i].name<<" "<<playerline[i].points<<" punkty"<<endl;
                gra=false;
            }

        }

        else //(playerline[0].points<15)
        {
        screenReset();
        playerline.push_back(playerline.front());
        playerline.erase(playerline.begin());
        playerline.resize(numPlayers);

        cout<<endl<<"   K ON I E C   T U R Y    "<<endl<<endl<<"   N A S T E P N Y   G R A C Z :  ";

        cout<<playerline[0].name;
        }
       _getch();

    }
    int selectCoin(char num)
    {
         switch(num)
        {
            case '1':
                    {
                        temp.redColor();cout<<" ";return 0;
                    break;
                    }
            case '2':
                    {
                        temp.blueColor();cout<<" ";return 1;
                    break;
                    }
            case '3':
                    {
                        temp.blackColor();cout<<" ";return 2;
                    break;
                    }
            case '4':
                    {
                        temp.whiteColor();cout<<" ";return 3;
                    break;
                    }
            case '5':
                    {
                        temp.greenColor();cout<<" ";return 4;
                    break;
                    }


        }

    }
    void setCoins()
    {
        if (numPlayers==2)
        {
            for (int i=0;i<5;i++)
            {
            coins[i]=4;
            coins[5]=5;
            }
        }
        if (numPlayers==3)
        {
            for (int i=0;i<6;i++)
            {
            coins[i]=5;
            }

        }
        if (numPlayers==4)
        {
            for (int i=0;i<5;i++)
            {
            coins[i]=7;
            coins[5]=5;
            }
        }



    }
    int checkNumberOfCoin(Gracz* acc)
    {
        int howMany=0;
        for (int i=0;i<6;i++)
        {
            howMany+=acc->playerCoin[i];
        }
        return howMany;
    }
    int cardAfford(Gracz *acc,Card check) // DO NAPRAWY !!
    {
        bool byCard=true;
        bool overall=true;
        int over=1;
        int Goldbufor=acc->playerCoin[5];
        int GoldbuforTable=coins[5];
        int pointFromCard[5]={0,0,0,0,0};
        int pointOverall[5]={0,0,0,0,0};
        int cardPoint[5]={0,0,0,0,0};
        cardPoint[0]=check.red;
        cardPoint[1]=check.blue;
        cardPoint[2]=check.black;
        cardPoint[3]=check.white;
        cardPoint[4]=check.green;

        for(int i=0;i<5;i++) // za same karty
        {
            pointFromCard[i]=acc->numberOfCard[i];
            if(pointFromCard[i]<cardPoint[i])
            {
                byCard=false;
            }
        }

        if(byCard){return 1;}

        else
        {


        for(int i=0;i<5;i++) // Zliczanie punktow za karty + zetony
        {
            pointOverall[i]=acc->playerCoin[i]+pointFromCard[i];
            if(pointOverall[i]<cardPoint[i])
            {
                overall=false;
                if(acc->playerCoin[5]>=cardPoint[i]-pointOverall[i])
                    {
                    overall=true;
                    acc->playerCoin[5]-=cardPoint[i]-pointOverall[i];
                    coins[5]+=cardPoint[i]-pointOverall[i];
                    cardPoint[i]-=cardPoint[i]-pointOverall[i];
                    }

            }
        }
        if(!overall){if (!acc->autoplay){cout<<"Nie stac Cie na ta karte!"<<endl;}acc->playerCoin[5]=Goldbufor;coins[5]=GoldbuforTable;return 0;}
        if(overall)
        {
        for(int i=0;i<5;i++)
        {
            cardPoint[i]-=pointFromCard[i];
            if(cardPoint[i]<=0)cardPoint[i]=0;
            acc->playerCoin[i]-=cardPoint[i];
            coins[i]+=cardPoint[i];

        }
        return 1;
        }
    }
    }
    void screenReset()
    {
                        system("cls"); // Reset Ekranu
                        showCard2();
                        cout<<endl<<"Zetony na stole :";
                        showCoin(coins);

    }

    void playerStatus(Gracz* active)
    {
        cout<<endl<<"Tura gracza "<<active->name<<endl<<endl;
        cout<<"Twoje zetony:";
        active->showPlayerCoin(active->playerCoin);
        cout<<endl<<endl<<"Twoje karty:";
        active->showPlayerCard();
        cout<<endl<<endl<<"Twoje punkty:"; active->showPlayerPionts();
    }

    void simpleSiAutoplay(Gracz* player)
    {
        cout<<endl<<"Tura gracza "<<player->name<<endl;
        cout<<endl<<"Zetony:";player->showPlayerCoin(player->playerCoin);cout<<endl<<endl;
        cout<<"Karty:";player->showPlayerCard();cout<<endl<<endl;
        cout<<"Punkty:";player->showPlayerPionts();
    	int targetColor[6]={0,0,0,0,0,0};
    	int targer=0;
    	player->si=false;

    	for (int i=0;i<numPlayers+1;i++)
    	{
    		for (int j=1;j<6;j++)
    		{
    		targetColor[j]+=arystOnTable[i].arystColor[j];


    		}
    	}
    	Sleep(2000);
    	//Pobieranie karty
    	for(int i=12;i>0;i--)
    	{
    		if (!player->si)
    		{
    			getCard(i,player,i);
    			if (player->si)
    			{
    				cout<<endl;
    				Sleep(6000);
    			}
    		}
    	}
    	int checkTablecoin=0;
    	{
    	    for(int i=0;i<5;i++)
            {
                if (coins[i])checkTablecoin++;
            }
    	}
    	if ((!player->si)&&(checkTablecoin>=3))
    	{
    	    cout<<"Pobieram zetony ";
    		int choose[3]={111,100,10};
    		for (int i=0;i<3;i++)
    		{
    			while (((choose[0]==choose[1]||choose[1]==choose[2]||choose[2]==choose[0]))||(choose[i]>5))
    			{
    				choose[i]=rand()%5+1;
    				if (coins[choose[i]-1]<=0)
    				{choose[i]=9;}
    			}
    			switch ( choose[i] )
    			{
    				case 1:	{player->playerCoin[selectCoin('1')]++;
    				coins[choose[i]-1]--;
    				break;}
    				case 2:	{player->playerCoin[selectCoin('2')]++;
    				coins[choose[i]-1]--;
    				break;}
    				case 3:	{player->playerCoin[selectCoin('3')]++;
    				coins[choose[i]-1]--;
    				break;}
    				case 4:	{player->playerCoin[selectCoin('4')]++;
    				coins[choose[i]-1]--;
    				break;}
    				case 5:	{player->playerCoin[selectCoin('5')]++;
    				coins[choose[i]-1]--;
    				break;}
    				default :{i--;break;}

    			}
    			cout<<" ";

    			Sleep(1000);
    			player->si=true;
    		}


    	}
    	if ((!player->si)&&(checkTablecoin<=3))
        {
            if (coins[5])
            {
                player->playerCoin[5]++;
                coins[5]--;
            }
        }
    	endTurn();
    }

};


