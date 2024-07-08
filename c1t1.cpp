#include <iostream>
#include <string>
using namespace std;

class Person
{
 public:
 int age;
 string name;

 Person()
 {
    name="";
    age=0;
 }

 Person(string n, int a)
 {
 age = a;
 name = n;
 }

 void display_information()
  {
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
  }



};


int main()
{
    Person* list = new Person[1000];
    int count = 0;
    char choice;
    
  while(1)
   {
       std::system("clear");
    cout<<"Please select an option: "<<endl;
    cout<<"1) Generate new person. "<<endl;
    cout<<"2) View existing person(s)."<<endl;
    cout<<"3) Exit. "<<endl;
    cin>>choice;


    if (choice == '1')
      { 
          std::system("clear");
        string N;
        int A = -1;
        char C;
         cout<<"Enter name: "<<endl;
         cin>>N;
         std::system("clear");

         cout<<"Enter age: "<<endl;
         while(A<=0)
         {
         cin>>A;
         if(A<=0)
          { 
            std::system("clear");
            cout<<"Invalid age entered. Try again."<<endl;
          }
         }

         
         list[count].name = N;
         list[count].age = A;
         count++;

         cout<<"Person successfully generated. (Press any key to continue)"<<endl;
         cin>>C;


      }
     
     else if (choice=='2')
     {   
        char C;
        int A = -1;

           if (count==0)
          {
           std::system("clear");

            cout<<"No person generated yet."<<endl;

          }

        else {
          cout<<"Enter person number to view data, or '-1' to return. "<<endl;

           for (int i=0; i<count; i++ )
          {
             cout<<"Person "<<i+1<<")"<<endl;
          }
            
         cin>>A;
          }
     
         if(A>= 1 && A<=count && count!=-1)
          {
            std::system("clear");
            
           cout<<"Person "<<A<<" selected: "<<endl;
           cout<<"Name: "<<list[A-1].name<<endl;
           cout<<"Age: "<<list[A-1].age<<endl;



          }


          else if (A!=-1)
          { 
            while(1)
             {
                std::system("clear");
                for (int i=0; i<count; i++ )
                {
                    cout<<"Person "<<i+1<<")"<<endl;
                }
                cout<<"Invalid person number entered. Try again (Or enter -1 to return). "<<endl;
                cin>>A;

                if (A>= 1 && A<=count)
                 {
                     std::system("clear");
                        
                    cout<<"Person "<<A<<" selected: "<<endl;
                    cout<<"Name: "<<list[A-1].name<<endl;
                    cout<<"Age: "<<list[A-1].age<<endl;


                break;
                 }

                 else if (A==-1)
                 break;
             }
          }

          cout<<"Press any key to continue"<<endl;
          cin>>C;
     }

     
       else if (choice=='3')
       break;

     else 
      {  
         std::system("clear");

        cout<<"Invalid option selected. Try again. " <<endl;
      }

     }
    return 0;
}
