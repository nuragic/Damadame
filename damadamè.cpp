#include <iostream.h>
#include <conio.h>

const int VUOTA = 0;
const int NERA = 1;
const int BIANCA = 2;
const int DAMANERA = 3;
const int DAMABIANCA = 4;

enum turno{nero,bianco};

struct cella
{
    int x, y;
};

int scacchiera [8][8];
int scelta;
int pedinaB=12,pedinaN=12;
turno turnogiocatore=bianco;

int visualizzaSchermo();
void stampaScacchiera();
void effettuaMossa();
cella leggiCoordinate ();
void muoviPedina (cella c1, cella c2);
void muoviDama(cella c1, cella c2);

void main ()
{
	int i,j;
	for (i=0;i<8;i++)
	{
	for (j=0;j<8;j++)
   scacchiera[i][j]=VUOTA;	 // La scacchiera è vuota.
	}
   // CARICAMENTO DELLE PEDINE
	i=0;
	for (j=0;j<8;j+=2)
	{
   scacchiera[i][j+1]=NERA;
	scacchiera[i+1][j]=NERA;
	scacchiera[i+2][j+1]=NERA;
   scacchiera[i+5][j]=BIANCA;
	scacchiera[i+6][j+1]=BIANCA;
	scacchiera[i+7][j]=BIANCA;
	}
   clrscr();
   textcolor(BLACK);
   textbackground(WHITE);
   cprintf("                                _DaMa <> Da*Me'_1.0                             " );
   textbackground(BLACK);
		do
		{
			stampaScacchiera();
			scelta=visualizzaSchermo();
        switch (scelta)
		{
			case 1:{
                   	effettuaMossa();
            break;
				   }
        }
		}
		while (scelta !=0 && pedinaB !=0 && pedinaN !=0);
    cout << "\n* Fine del gioco *\n\a";
    getch();
}


int visualizzaSchermo ()
{
    cout << "\t\t\t\t*----------------------*\n";
    cout << "\t\t\t\t|1) Effettua una mossa |\n";
    cout << "\t\t\t\t|0) per uscire         |\n";
    cout << "\t\t\t\t*----------------------*\n";
    do
	{
        cout << "\n";
        cin >> scelta;
	}
	while (scelta < 0 || scelta > 1);
    return scelta;
}


void stampaScacchiera()
{
    cout << "\n\t\t\t\t  ";
    int i,j;
    for (i=0; i < 8; i++)
	{
        cout << i << " ";
    }
    cout << "\n\t\t\t\t";
    for (i=0; i < 8; i++)
	{
        cout << "\n\t\t\t\t" <<i << " ";
         for (j=0; j < 8; j++)
		{
            if (scacchiera [i] [j] == VUOTA)
                cout << "_ ";
			else if (scacchiera [i] [j] == NERA)
                cout << "o ";
            else if (scacchiera [i] [j] == DAMANERA)
                cout<<"O ";
			else if (scacchiera [i] [j] == BIANCA)
			{
          textcolor(15);
          cprintf("o ");
            }
            else if (scacchiera [i] [j] == DAMABIANCA)
			{
         	textcolor(15);
            cprintf("O ");
            }
        }
    }
    cout << "\n";
    return;
}

void effettuaMossa()
{
    cella c1, c2;
    cout << "\nInserisci le coordinate della pedina da muovere (riga colonna): ";
    c1 = leggiCoordinate();
    cout << "\nInserisci le coordinate della cella in cui muovere (riga colonna): ";
    c2 = leggiCoordinate();
     if((scacchiera[c1.x][c1.y]== 3) || (scacchiera[c1.x][c1.y]== 4))
    muoviDama(c1,c2);
    else
    muoviPedina (c1, c2);
    return;
}


cella leggiCoordinate ()
{
    cella c;
    cin >> c.x >> c.y;
    while (c.x < 0 || c.x > 7)
	{
        cout << "Riga scorretta. Rifai la scelta della riga: ";
        cin >> c.x;
    }
    while (c.y < 0 || c.y > 7)
	{
        cout << "Colonna scorretta. Rifai la scelta della colonna: ";
        cin >> c.y;
    }
    return c;
}

void muoviPedina (cella c1, cella c2)
{
if(pedinaB==0)
				{
				   cout<<"\n\t\t\t\tNERO VINCE LA PARTITA!\n";
				   return;
				}
    if (c1.x == c2.x && c1.y == c2.y)
        cout << "\nSe devi restare fermo, non sprecare forze...\n";
	else if (scacchiera [c1.x][c1.y]==0)
        cout << "\nIn questo gioco si spostano le pedine, non le caselle!\n";
	else if (scacchiera [c2.x][c2.y]!=0)
        cout << "\nMi dispiace, è occupato. Riprova dopo\n";
	else if ((c1.x-c2.x)>2||(c1.y-c2.y)>2)
        cout << "\nMacchè vuoi fare??!\n";
	else if (scacchiera [c1.x][c1.y]==1 && turnogiocatore== nero)
	{
        if (((c2.x-c1.x)==1 && (c2.y-c1.y)==1) || ((c2.x-c1.x)== 1 && (c2.y-c1.y)== -1 ) && (scacchiera[c2.x][c2.y]==0))
		{     //SPOSTA PEDINA
            turnogiocatore= bianco;
            scacchiera[c1.x][c1.y]=0;
            scacchiera[c2.x][c2.y]=1;
            cout << "\nNero: hai spostato una pedina.\n";
            if(scacchiera[7][0]== 1 || scacchiera[7][2]== 1 || scacchiera[7][4]== 1 || scacchiera[7][6]== 1)
            { cout<<"\nNero: hai fatto dama!";
            	scacchiera[c2.x][c2.y]=3;
               }
        }
		else if (((c2.x-c1.x)== -1 && (c2.y-c1.y)== -1) || ((c2.x-c1.x)== -1 && (c2.y-c1.y)==1 ) && (scacchiera[c2.x][c2.y]==0))
			cout<<"\nNon puoi muovere all'indetro0oOo!\n";
		else if ((c2.x-c1.x)==2 || (c2.x-c1.x)==-2 && (c2.y-c1.y)==2 || (c2.y-c1.y)==-2 && scacchiera[c2.x][c2.y]==0)
		{     //CONTROLLA SE SI PUO' MANGIARE UNA PEDINA
            if (scacchiera[c1.x+1][(c2.y+c1.y)/2]==0)
                cout << "\nNon c'è nessuna pedina da mangiare!\n";
			else if (scacchiera[c1.x+1][(c2.y+c1.y)/2]==1)
                cout << "\nTi vuoi mangiare da solo?? \n";
			else if (scacchiera[c1.x+1][(c2.y+c1.y)/2]==2 && turnogiocatore== nero)
			{		 //MANGIA PEDINA	BIANCA  *****
                cout << "\nNero: hai mangiato una pedina bianca!\n";
                turnogiocatore= bianco;
                scacchiera[c1.x][c1.y]=0;
                scacchiera[c1.x+1][(c2.y+c1.y)/2]=0;
                scacchiera[c2.x][c2.y]=1;
				    pedinaB=pedinaB-1;
            if(scacchiera[7][0]== 1 || scacchiera[7][2]== 1 || scacchiera[7][4]== 1 || scacchiera[7][6]== 1)
            {
               cout<<"\nNero: hai fatto dama!";
            	scacchiera[c2.x][c2.y]=3;
            }
            }
        }
	}


		else
      if(pedinaN==0)
				{
				   cout<<"\n\t\t\t\tBIANCO VINCE LA PARTITA!\n";
				   return;
				}
      if (scacchiera [c1.x][c1.y]==2 && turnogiocatore== bianco)
	{    //MUOVE PEDINA BIANCA
        if (((c1.x-c2.x)==1 && (c1.y-c2.y)==1) || ((c1.x-c2.x)==1 && (c1.y-c2.y)== -1) && (scacchiera[c2.x][c2.y]==0))
		{     //SPOSTA PEDINA
            turnogiocatore= nero;
            scacchiera[c1.x][c1.y]=0;
            scacchiera[c2.x][c2.y]=2;
            cout << "\nBianco: hai spostato una pedina.\n";
            if(scacchiera[0][1]== 2 || scacchiera[0][3]== 2 || scacchiera[0][5]== 2 || scacchiera[0][7] == 2)
            {
            	cout<<"\nBianco: hai fatto dama!";
            	scacchiera[c2.x][c2.y]=4;
            }

        }
		else if (((c1.x-c2.x)== -1 && (c1.y-c2.y)== -1) || ((c1.x-c2.x)== -1 && (c1.y-c2.y)==1 ) && (scacchiera[c2.x][c2.y]==0))
			cout<<"\nNon puoi muovere all'indetro0oOo!\n";
		else if (((c1.x-c2.x)==2 || (c1.x-c2.x)== -2) && ((c1.y-c2.y)==2 || (c1.y-c2.y)== -2) && scacchiera[c2.x][c2.y]==0)
		{    //CONTROLLA SE SI PUO' MANGIARE UNA PEDINA
            if (scacchiera[c1.x-1][(c2.y+c1.y)/2]==0){
                cout << "\nNon c'è nessuna pedina da mangiare!\n";
            }
			else if (scacchiera[c1.x-1][(c2.y+c1.y)/2]==2)
                cout << "\nTi vuoi mangiare da solo?? \n";
			else if (scacchiera[c1.x-1][(c2.y+c1.y)/2]==1 && turnogiocatore== bianco)
			{      //MANGIA PEDINA NERA
                cout << "\nBianco: hai mangiato una pedina nera!\n";
                turnogiocatore= nero;
                scacchiera[c1.x][c1.y]=0;
                scacchiera[c1.x-1][(c2.y+c1.y)/2]=0;
                scacchiera[c2.x][c2.y]=2;
					 pedinaN=pedinaN-1;
            if(scacchiera[0][1]== 2 || scacchiera[0][3]== 2 || scacchiera[0][5]== 2 || scacchiera[0][7]== 2)
            {
               cout<<"\nBianco: hai fatto dama!";
            	scacchiera[c2.x][c2.y]=4;
				}
            }
        }
    }
    return;
    }

void muoviDama(cella c1, cella c2)
{
    if(pedinaB==0)
				{
				   cout<<"\n\t\t\t\tNERO VINCE LA PARTITA!\n";
				   return;
				}
    if (c1.x == c2.x && c1.y == c2.y)
        cout << "\nSe devi restare fermo, non sprecare forze...\n";
	else if (scacchiera [c1.x][c1.y]==0)
        cout << "\nIn questo gioco si spostano le pedine, non le caselle!\n";
	else if (scacchiera [c2.x][c2.y]!=0)
        cout << "\nMi dispiace, è occupato. Riprova dopo\n";
	else if ((c1.x-c2.x)>2||(c1.y-c2.y)>2)
        cout << "\nMacchè vuoi fare???\n";
	else if (scacchiera [c1.x][c1.y]==3 && turnogiocatore== nero)
   {
        //MUOVE DAMA NERA
        if (((c2.x-c1.x)==1 && (c2.y-c1.y)==1) || ((c2.x-c1.x)== 1 && (c2.y-c1.y)== -1 ) || ((c1.x-c2.x)==1 && (c1.y-c2.y)==1) || ((c1.x-c2.x)==1 && (c1.y-c2.y)== -1) && (scacchiera[c2.x][c2.y]==0))
		{     //SPOSTA PEDINA
            turnogiocatore= bianco;
            scacchiera[c1.x][c1.y]=0;
            scacchiera[c2.x][c2.y]=3;
            cout << "\nNero: hai spostato la dama.\n";
        }
		else if ((c2.x-c1.x)==2 || (c2.x-c1.x)==-2 && (c2.y-c1.y)==2 || (c2.y-c1.y)==-2 && scacchiera[c2.x][c2.y]==0)
		{     //CONTROLLA SE SI PUO' MANGIARE UNA PEDINA
            if (scacchiera[c1.x+1][(c2.y+c1.y)/2]==0)
                cout << "\nNon c'è nessuna pedina da mangiare!\n";
			else if (scacchiera[c1.x+1][(c2.y+c1.y)/2]==1 || scacchiera[c1.x+1][(c2.y+c1.y)/2]==3)
                cout << "\nTi vuoi mangiare da solo?? \n";
			else if (scacchiera[c1.x+1][(c2.y+c1.y)/2]==2 || scacchiera[c1.x+1][(c2.y+c1.y)/2]==4 && turnogiocatore== nero)
			{      //MANGIA PEDINA	BIANCA
                cout << "\nNero: hai mangiato una pedina bianca!\n";
                turnogiocatore= bianco;
                scacchiera[c1.x][c1.y]=0;
                scacchiera[c1.x+1][(c2.y+c1.y)/2]=0;
                scacchiera[c2.x][c2.y]=3;
				    pedinaB=pedinaB-1;

            }
        }
	}

		else
      if(pedinaN==0)
				{
				   cout<<"\n\t\t\t\tBIANCO VINCE LA PARTITA!\n";
				   return;
				}
      if (scacchiera [c1.x][c1.y]==4 && turnogiocatore== bianco)
	{
        //MUOVE DAMA BIANCA
        if (((c2.x-c1.x)==1 && (c2.y-c1.y)==1) || ((c2.x-c1.x)== 1 && (c2.y-c1.y)== -1 ) || ((c1.x-c2.x)==1 && (c1.y-c2.y)==1) || ((c1.x-c2.x)==1 && (c1.y-c2.y)== -1) && (scacchiera[c2.x][c2.y]==0))
		{     //SPOSTA PEDINA
      		turnogiocatore= nero;
            scacchiera[c1.x][c1.y]=0;
            scacchiera[c2.x][c2.y]=4;
            cout << "\nBianco: hai spostato la dama.\n";
        }
		else if (((c1.x-c2.x)==2 || (c1.x-c2.x)== -2) && ((c1.y-c2.y)==2 || (c1.y-c2.y)== -2) && scacchiera[c2.x][c2.y]==0)
		{     //CONTROLLA SE SI PUO' MANGIARE UNA PEDINA
            if (scacchiera[c1.x-1][(c2.y+c1.y)/2]==0)
                cout << "\nNon c'è nessuna pedina da mangiare!\n";
			else if (scacchiera[c1.x-1][(c2.y+c1.y)/2]==2 || scacchiera[c1.x-1][(c2.y+c1.y)/2]==4)
                cout << "\nTi vuoi mangiare da solo?? \n";
			else if (scacchiera[c1.x-1][(c2.y+c1.y)/2]==1 || scacchiera[c1.x-1][(c2.y+c1.y)/2]==3 && turnogiocatore== bianco)
			{      //MANGIA PEDINA NERA
                cout << "\nBianco: hai mangiato una pedina nera!\n";
                turnogiocatore= nero;
                scacchiera[c1.x][c1.y]=0;
                scacchiera[c1.x-1][(c2.y+c1.y)/2]=0;
                scacchiera[c2.x][c2.y]=4;
                pedinaN=pedinaN-1;
            }
        }
    }
    return;
    }



