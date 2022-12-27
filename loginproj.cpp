/* Program: This is a login/registration program that
allows user to create an id and password for registration
with forgot user's id and password as addition option */

#include<iostream>
#include<fstream>
using namespace std;

//functions declaration
void menu();
void login();
void registration();
void forgot();

int main()
{

    menu();

}

// Menu function
void menu()
{
    int choice = 0;

    //create a login layout
        cout<<"Welcome to Our Login Page!\n";
        cout<<"           Menu\n";
        cout<<"Press 1 to Login\n";
        cout<<"Press 2 to Register\n";
        cout<<"Press 3 for Forgot ID/PW\n";
        cout<<"Press 4 to Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout<<"Thank You!";
                break;

            default:
                cout<<"\nPlease select one of the option above.\n";
                menu();
        }   
}

// Login function
void login()
{
    int count=0;

    string userID, userPW, id,pw,email;

    cout<<"Enter Username: ";
    cin>>userID;
    cout<<"Enter Password: ";
    cin>>userPW;

    //open database file
    ifstream input ("database.txt");

    //while there is id and pw in database
    //read id and pw from file
    while(input>>id>>pw>>email)
    {
        if(id==userID && pw == userPW)
        {
            count = 1;
  
        }
    }
    input.close();
  
    if(count == 1)
    {
        cout<<"Login sucess.\n";
    }
    else
    {
        cout<<"Check Your username and password.\n\n";
        menu();
    }
}

//Registration function
void registration()
{
    string userID, userPW, userEmail;
  
        cout<<"Enter Username: ";
        cin>>userID;
        while(userID.length()>12)
        {
            cout<<"Please Enter 0-12 character(s).\nEnter Username: ";
            cin>>userID;
        }
        cout<<"Enter Password: ";
        cin>>userPW; 
        while(userPW.length()>12)
        {
            cout<<"Please Enter 0-12 character(s).\nEnter Password: ";
            cin>>userPW;
        }

        cout<<"Enter email: ";
        cin>>userEmail;
        while(userEmail.length()>12)
        {
            cout<<"Please Enter 0-12 character(s).\nEnter E-mail: ";
            cin>>userEmail;
        }
 
    // ios::app to preserve existing data in the file and don't want to overwrite it for each write
    ofstream dataFile("database.txt", ios::app); 
    //record id and password
    dataFile<<userID<<" "<<userPW<<" "<<userEmail<<endl;
    dataFile.close();
    cout<<"Registration Sucess!\n\n";
    menu();
    
}

//forgot id and password function
void forgot()
{

    string userID, userPW, id, pw, userEmail, email;
    int option, count;

    cout<<"Forgot username press 1.\n";
    cout<<"Forgot password press 2.\n";
    cin>>option;

    switch(option)
    {
        //for username >>  need email and password to confirm
        case 1:
            {
                cout<<"Please enter your email address: ";
                cin>>userEmail;
                cout<<"\nPlease enter your password: ";
                cin>>userPW;

                ifstream f1 ("database.txt");

                while(f1>>id>>pw>>email)
                {
                    if(email == userEmail && pw == userPW)
                    {
                        count = 1;
                    }
                }
                f1.close();
                if(count == 1)
                {
                    cout<<"Accouunt Found.\n";
                    cout<<"Your username is: "<<id<<endl;
                }
                else{
                        cout<<"Account not found."<<endl;
                        menu();
                    }  
                break;
                }
        //forgot password >> need email and password to confirm
        case 2:
            {
                cout<<"Please enter your email address: ";
                cin>>userEmail;
                cout<<"\nPlease enter your username: ";
                cin>>userID;
                ifstream f1("database.txt");
                while(f1>>id>>pw>>email)
                {
                    if(email == userEmail && id == userID)
                    {
                        count = 2;
                    }
                }
                f1.close();
                if(count == 2)
                {
                    cout<<"Accouunt Found.\n";
                    cout<<"Your password is: "<<pw<<endl;
                }
                else{
                        cout<<"Account not found."<<endl;
                        menu();
                    } 
                break;
            }
        
        default:
            cout<<"Please press 1 for forgot username\n"<<
            "Press 2 for forgot password";
            forgot();

    }
}
