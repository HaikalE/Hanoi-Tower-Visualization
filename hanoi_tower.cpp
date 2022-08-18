#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;
int langkah=0,tower_a,tower_b=0,tower_c=0;
string bar="";
void tampilkan(vector<string>a,vector<string>b,vector<string>c,int tower_a,int tower_b,int tower_c){
  cout<<"Try of-"<<langkah++<<"\n";
  cout<<"TOWER A\n";
  for (int ar=0;ar<tower_a;ar++) { 
    cout<<a[ar];
  }
  cout<<bar;
  cout<<"TOWER B\n";
  for (int ar=0;ar<tower_b;ar++) { 
    cout<<b[ar];
  }
  cout<<bar;
  cout<<"TOWER C\n";
  for (int ar=0;ar<tower_c;ar++) { 
    cout<<c[ar];
  }
  cout<<bar;
}
void proses(int tower_a,int tower_b,int tower_c,vector<string>&a,vector<string>&b,vector<string>&c,string dari,string ke){
  switch (ke[0]){
    case 'a':
      switch (dari[0]){
        case 'b':
          a.insert(a.begin(),b[0]);
          b.erase(b.begin());
          break;
        case 'c':
          a.insert(a.begin(),c[0]);
          c.erase(c.begin());
          break;
      }
      break;
    case 'b':
      switch (dari[0]){
        case 'a':
          b.insert(b.begin(),a[0]);
          a.erase(a.begin());
          break;
        case 'c':
          b.insert(b.begin(),c[0]);
          c.erase(c.begin());
          break;
      }break;
    default:
      switch (dari[0]){
        case 'a':
          c.insert(c.begin(),a[0]);
          a.erase(a.begin());
          break;
        case 'b':
          c.insert(c.begin(),b[0]);
          b.erase(b.begin());
          break;
      }
  }
  tampilkan(a,b,c,tower_a,tower_b,tower_c);
} 
void input(int &tower_a,int &tower_b,int &tower_c,vector<string>&a,vector<string>&b,vector<string>&c){//berguna untuk menginput elemen setiap tower
  string dari,ke;
  input_1:
  cout<<"Which one do you want to move : ";
  getline(cin,dari);
  if (dari.length()!=1) {
    system("cls");
    if (langkah==0||langkah==1)  {
      tampilkan(a,b,c,tower_a,tower_b,tower_c);
      goto input_1;}
    cout<<"You get wrong input let's try out !\n";
    tampilkan(a,b,c,tower_a,tower_b,tower_c);
    goto input_1;
  }
  switch (dari[0]){
    case 'a':
      if (a[0]=="") {
      system("cls");
      cout<<"Can't move in this tower\n";
      tampilkan(a,b,c,tower_a,tower_b,tower_c);
      goto input_1;
      }
      break;
    case 'b':
      if (b[0]=="") {
      system("cls");
      cout<<"Can't move in this tower\n";
      tampilkan(a,b,c,tower_a,tower_b,tower_c);
      goto input_1;
      }
      break;
    case 'c':
      if (c[0]=="") {
      system("cls");
      cout<<"Can't move in this tower\n";
      tampilkan(a,b,c,tower_a,tower_b,tower_c);
      goto input_1;
      }
      break;
    default :
    system("cls");
    cout<<"You get wrong input let's try out !\n";
    tampilkan(a,b,c,tower_a,tower_b,tower_c);
    goto input_1;
  }
  cout<<"Move where                    : ";
  getline(cin,ke);
  if (ke.length()!=1) {
    system("cls");
    cout<<"You get wrong input let's try out !\n";
    tampilkan(a,b,c,tower_a,tower_b,tower_c);
    goto input_1;
  }
  switch (ke[0]){
    case 'a':
      switch (dari[0]){
        case 'a':
          system("cls");
          cout<<"You recurse to this tower !\n";
          tampilkan(a,b,c,tower_a,tower_b,tower_c);
          goto input_1;
          break;
        case 'b':
          if (a[0].length()>b[0].length()||a[0]=="") {
            tower_b--;
            a.push_back("");
            tower_a++;
          }
          else {
            system("cls");
            cout<<"You can't move to more size than you move\n";
            tampilkan(a,b,c,tower_a,tower_b,tower_c);
            goto input_1;
          }
          break;
        case 'c':
          if (a[0].length()>c[0].length()||a[0]=="") {
            tower_c--;
            a.push_back("");
            tower_a++;
          }
          else {
            system("cls");
            cout<<"You can't move to more size than you move\n";
            tampilkan(a,b,c,tower_a,tower_b,tower_c);
            goto input_1;
          }
          break;
      }
      break;
    case 'b':
      switch (dari[0]){
        case 'a':
          if (b[0].length()>a[0].length()||b[0]=="") {
            tower_a--;
            b.push_back("");
            tower_b++;
          }
          else {
            system("cls");
            cout<<"You can't move to more size than you move\n";
            tampilkan(a,b,c,tower_a,tower_b,tower_c);
            goto input_1;
          }
          break;
        case 'b':
          system("cls");
          cout<<"You recurse to this tower !\n";
          tampilkan(a,b,c,tower_a,tower_b,tower_c);
          goto input_1;
          break;
        case 'c':
          if (b[0].length()>c[0].length()||b[0]=="") {
            tower_c--;
            b.push_back("");
            tower_b++;
          }
          else {
            system("cls");
            cout<<"You can't move to more size than you move\n";//"Tidak bisa meletakkan ke yang lebih besar ulangi\n";
            tampilkan(a,b,c,tower_a,tower_b,tower_c);
            goto input_1;
          }
          break;
      }break;
    case 'c':
      switch (dari[0]){
        case 'a':
          if (c[0].length()>a[0].length()||c[0]=="") {
            tower_a--;
            c.push_back("");
            tower_c++;
          }
          else {
            system("cls");
            cout<<"You can't move to more size than you move\n";
            tampilkan(a,b,c,tower_a,tower_b,tower_c);
            goto input_1;
          }
          break;
        case 'b':
          if (c[0].length()>b[0].length()||c[0]=="") {
            tower_b--;
            c.push_back("");
            tower_c++;
          }
          else {
            system("cls");
            cout<<"You can't move to more size than you move\n";
            tampilkan(a,b,c,tower_a,tower_b,tower_c);
            goto input_1;
          }
          break;
        case 'c':
          system("cls");
          cout<<"You recurse to this tower !\n";
          tampilkan(a,b,c,tower_a,tower_b,tower_c);
          goto input_1;
          break;
      }
      break;
    default :
    system("cls");
    cout<<"You get wrong input let's try out !\n";
    tampilkan(a,b,c,tower_a,tower_b,tower_c);
    goto input_1;
  }
  system("cls");
  proses(tower_a,tower_b,tower_c,a,b,c,dari,ke);
}
void solve_computer(int &tower_a,int &tower_b,int &tower_c,vector<string>&a,vector<string>&b,vector<string>&c,int n, char T1, char T2, char T3){
    if (n == 1){
        switch (T3){
            case 'a':
                switch (T1){
                    case 'b':
                        tower_b--;
                        a.push_back("");
                        tower_a++;
                        break;
                    case 'c':
                        tower_c--;
                        a.push_back("");
                        tower_a++;
                        break;
                }
                break;
            case 'b':
                switch (T1){
                    case 'a':
                        tower_a--;
                        b.push_back("");
                        tower_b++;
                        break;
                    case 'c':
                        tower_c--;
                        b.push_back("");
                        tower_b++;
                        break;
                }
                break;
        default :
            switch (T1){
                case 'a':
                    tower_a--;
                    c.push_back("");
                    tower_c++;
                    break;
                case 'b':
                    tower_b--;
                    c.push_back("");
                    tower_c++;
                    break;
            }
        break;
        }
    system("cls");
      switch (T3){
    case 'a':
      switch (T1){
        case 'b':
          a.insert(a.begin(),b[0]);
          b.erase(b.begin());
          break;
        case 'c':
          a.insert(a.begin(),c[0]);
          c.erase(c.begin());
          break;
      }
      break;
    case 'b':
      switch (T1){
        case 'a':
          b.insert(b.begin(),a[0]);
          a.erase(a.begin());
          break;
        case 'c':
          b.insert(b.begin(),c[0]);
          c.erase(c.begin());
          break;
      }break;
    default :
      switch (T1){
        case 'a':
          c.insert(c.begin(),a[0]);
          a.erase(a.begin());
          break;
        case 'b':
          c.insert(c.begin(),b[0]);
          b.erase(b.begin());
          break;
      }
  }
  cout<<"Try of-"<<langkah++<<"\n";
  cout<<"TOWER A\n";
  for (int ar=0;ar<tower_a;ar++) { 
    cout<<a[ar];
  }
  cout<<bar;
  cout<<"TOWER B\n";
  for (int ar=0;ar<tower_b;ar++) { 
    cout<<b[ar];
  }
  cout<<bar;
  cout<<"TOWER C\n";
  for (int ar=0;ar<tower_c;ar++) { 
    cout<<c[ar];
  }
  cout<<bar;
  cout<<"Move from "<<T1<<" to "<<T3;
    sleep(1);
    }
    else
    {
        solve_computer(tower_a,tower_b,tower_c,a,b,c,n-1, T1, T3, T2);
        solve_computer(tower_a,tower_b,tower_c,a,b,c,1, T1, T2, T3);
        solve_computer(tower_a,tower_b,tower_c,a,b,c,n-1, T2, T1, T3);
    }
}
void input_disk(vector<string>&a,int tower_a){
  a.push_back("");
  for (int c=tower_a-1;c>=2;c--) a[0]+="  ";
  a[0]+=" ()\n";  
  for (int b=1;b<tower_a;b++){
    a.push_back("");
    for (int c=tower_a-1;c>=b+1;c--) a[b]+=("  ");
    for (int d=1;d<=b;d++) a[b]+="()()";
    a[b]+="\n";
   }
  for (int b=1;b<(tower_a*4)-3;b++) bar+="=";
  bar+="\n\n";
}
int main (){
  utama:
  system("cls");
  cout<<"Program Hanoi Tower\n";
  cout<<"===================\n";
  cout<<"\n";
  char iya;
  int total,menu;
  vector<string>a;
  vector<string>b={""},c={""};
  cout<<"Menu\n1. Solve with computer\n2. Play now\n3. What is Hanoi Tower\nChoose your menu    : ";
  cin>>menu;
  system("cls");
  if (menu==2) goto play_now;
  else if (menu==1) goto solve_computer;
  else if (menu==3) goto what;
  play_now:
  cout<<"How much disk  : ";
  cin>>tower_a;
  if (tower_a<3) goto end;
  input_disk(a,tower_a);
  total=tower_a;
    tampilkan(a,b,c,tower_a,tower_b,tower_c);
    while (tower_b!=total){
      input(tower_a,tower_b,tower_c,a,b,c);
      if (tower_c==total) break;
    }
    cout<<"Alhamdulillah you win\n";
    goto end;
  what:
  cout<<"The Tower of Hanoi \nalso called The problem of Benares Temple or Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers, or simply pyramid puzzle\n\n is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters,\n which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, \nthe smallest at the top, thus approximating a conical shape. \n\nThe objective of the puzzle is to move the entire stack to the last rod, obeying the following rules:\n1. Only one disk may be moved at a time.\n2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.\n3. No disk may be placed on top of a disk that is smaller than it.\nWith 3 disks, the puzzle can be solved in 7 moves. \nThe minimal number of moves required to solve a Tower of Hanoi puzzle is 2^n - 1, where n is the number of disks.\n\n";
  goto end;
  solve_computer:
  cout<<"How much disk  : ";
  cin>>tower_a;
  if (tower_a<3) goto end;
  input_disk(a,tower_a);
  total=tower_a;
  tampilkan(a,b,c,tower_a,tower_b,tower_c);
  sleep(1);
  solve_computer(tower_a,tower_b,tower_c,a,b,c,total, 'a','b', 'c');
  cout<<"\nAlhamdulillah you win\n";
  end:
  cout<<"Do you want to return program (1=Yes/Other number=No) : ";
  cin>>total;
  if (total==1) goto utama;
}
