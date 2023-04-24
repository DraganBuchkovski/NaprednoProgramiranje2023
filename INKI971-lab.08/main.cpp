#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

struct student
{
    string ime;
    string prezime;
    string indeks;
};

char tocniPrvi[4]={'c', 'c', 'a', 'b'};
char tocniVtori[4]={'b', 'a', 'c', 'a'};
char tocniTreti[4][2]={{'a', 'c'}, {'a', 'b'}, {'b', 'c'}, {'b', 'c'}};


string Starttime()
{
    time_t t = time(NULL);
    char start_time[20];
    strftime(start_time, sizeof(start_time), "%d.%m.%Y %H:%M:%S", localtime(&t));
    return start_time;
}

string Stoptime()
{
    time_t t = time(NULL);
    char stop_time[20];
    strftime(stop_time, sizeof(stop_time), "%d.%m.%Y %H:%M:%S", localtime(&t));
    return stop_time;
}

bool checkFile(string filename)
{
    ifstream infile(filename.c_str());
    return infile.good();
}

  // Funkcija koja se koristi za primanje na vlez
  void studentInput(student &lice)
  {
    cout<<"Vnesete go imeto na studentot: ";
        cin>>lice.ime;
    cout<<"Vnesete go prezimeto na studentot: ";
        cin>>lice.prezime;

    do{
        cout<<"Vnesete go indeksot na studentot: ";
        cin>>lice.indeks;
    } while(lice.indeks.size() != 3 && lice.indeks.size() != 4);
  }
 
  // Funkcija koja se koristi za zapishuvanje na odgovorot vo datoteka
  void writeOdgovor(fstream &file, char odg, char odg2, int br) {
    file << br << ". " << odg << " " << odg2 << endl;
  }
  
  
  // Funkcija koja se koristi za proverka na odgovorot i boduvanje
  float checkOdgovor(int brojnaprasanje, char answer, char answer2){


    if (brojnaprasanje <= 4){

      if ( answer == tocniPrvi[brojnaprasanje-1] )
        return 1.5;

    }
    else if (brojnaprasanje > 4 && brojnaprasanje <= 8 ){
      if ( answer == tocniVtori[brojnaprasanje-5] )
        return 3;
    }
    else if (brojnaprasanje > 8 && brojnaprasanje <= 12 ){
      if ((( answer == tocniTreti[brojnaprasanje-9][0] ) && ( answer2 == tocniTreti[brojnaprasanje-9][1] )) || (( answer == tocniTreti[brojnaprasanje-9][1] ) && ( answer2 == tocniTreti[brojnaprasanje-9][0] )))
        return 8;
    }
  }
  
 // Funkcija koja ovozmozuva proverka na vnes kaj odgovorot i ispishuvanje na odgovorot vo datoteka
  float handleInput(int brojprasanje, fstream &file){

    char odgovor,odgovor2;
    if (brojprasanje <= 8){
      do{
        cout<<"Vashiot odgovor: ";
        cin>>odgovor;
      } while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' );
      writeOdgovor(file, odgovor, ' ', brojprasanje);

    }

    else if (brojprasanje > 8 && brojprasanje <= 12 ){
        do{
          cout<<"Vashiot odgovor: ";
          cin>>odgovor;
        } while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd'  );
        do{
          cout<<"Vashiot odgovor: ";
          cin>>odgovor2;
        } while(( odgovor2 == odgovor )  || ( odgovor2 != 'a' && odgovor2 != 'b' && odgovor2 != 'c' && odgovor2 != 'd' ));
         writeOdgovor(file, odgovor, odgovor2, brojprasanje);
      }

      return checkOdgovor(brojprasanje, odgovor, odgovor2);
    }

 // Funkcija koja se koristi za proverka na poeni i vrakanje na vrednosta na ocenkata
  int score(float poeni){
    if ( poeni >= 0 && poeni <= 24 )
      return 5;
    else if ( poeni >= 25 && poeni <= 32 )
      return 6;
    else if ( poeni >= 32.5 && poeni <= 37 )
      return 7;
    else if ( poeni >= 37.5 && poeni <= 40.5 )
      return 8;
    else if ( poeni >= 41 && poeni <= 45 )
      return 9;
    else if ( poeni >= 45.5 && poeni <= 50 )
      return 10;
  }

  // Funkcija za pechatenje na tabela so tochnite odgovori
  void answersTable(){
    cout<<"Tocni odgovori na prasanjata se:"<<endl;
    for(int i=1;i<=12;i++){
      if (i <= 4)
        cout<<i<<". "<<tocniPrvi[i-1]<<endl;
        else if (i > 4 && i <= 8 )
          cout<<i<<". "<<tocniVtori[i-5]<<endl;
            else if (i > 8 && i <= 12 )
              cout<<i<<". "<<tocniTreti[i-9][0] << " " <<tocniTreti[i-9][1]<<endl;
    }
  }


int main(){


    fstream file,test;
    student lice;
    string prasanje;
    int brojnaprasanje=1;
    float poeni = 0;
    
    studentInput(lice);
    
    int n=0;
    //citanje na n od file i povtorno zapisuvanje vo istiot file
    string filename3 = "n.txt";
    
    file.open(filename3.c_str(), ios::in);
    if (file.is_open())
	{
        file >> n;
    }
    file.close();
    
    n++;

    file.open(filename3.c_str(), ios::out);
 
    if (file.is_open()) {
        file << n;
    }
    file.close();

    // Kreiranje na datotekata so ime i prezime na studentot
    const string filename = lice.ime + lice.prezime + "INKI" + lice.indeks;
    if (checkFile(filename)) 
	{
        cout << "Nemash pravo na test povtorno!" ;
        return 0;
    }

    file.open(filename.c_str(),ios::out);
    file<<"Ime: "<<lice.ime<<"\nPrezime: "<<lice.prezime<<"\nIndeks: INKI"<<lice.indeks<<"\nVreme na start: "<<Starttime();
    file<<"\n-------------------\n";
    file<<"Odgovori:\n";
    file.close();
    
    
    const string filename2="Students.log";
    file.open(filename2.c_str(),ios::app); 
    file<<n<<". " <<Starttime()<<" "<<lice.ime<<", "<<lice.prezime<<", Indeks: INKI"<<lice.indeks<<"\n";
    file.close();
    
    // Otvoranje na datotekata so prasanja i prevzemanje na soodvetnoto prasanje i negovite odgovori
    test.open("prasanja.txt", ios::in);
    while(getline( test , prasanje )){
      for (int i=0; i < prasanje.size();i++){
        if (prasanje[i] == ';'){
          cout<<endl;
          i++;
        }
        else
          cout<<prasanje[i];
      }
      cout<<endl;

      file.open(filename.c_str(), ios::app);
      poeni += handleInput(brojnaprasanje, file);
      file.close();
      brojnaprasanje++;
    }

    test.close();
    
    file.open(filename.c_str(), ios::app);
    file<<"\nVreme na kraj: "<<Stoptime()<<"\n-------------------\n"<<"\nPoeni: "<<poeni<<"\nOcenka: " <<score(poeni);
    file.close();
    
    cout<<"Ocenka: "<<score(poeni)<<endl;

    answersTable();

    return 0;
}
