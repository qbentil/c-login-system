#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;
    string path = "C:\\Users/User/Documents/codeblocksProjects/login_system/users/";
    cout << "Enter username: "; cin >> username;
    cout << "Enter passwword: ";cin >> password;

    ifstream read(path+  username + ".txt"); // read user data from userfiles;

    getline(read, un);
    getline(read, pw);

    if(un == username & pw == password)
    {
        return true;
    }
    return false;
}
void Register()
{
        string username, password;
        string path = "C:\\Users/User/Documents/codeblocksProjects/login_system/users/";
        cout << "Your Username: "; cin >> username;
        cout << "Your Password:"; cin >> password;

        ofstream file;
        file.open(path +username + ".txt");
        file << username << endl << password;
        file.close();

        cout << "\n\n User registration successful!.\n\n";


}

int main()
{
    int pc;
    int years;
    cout << "1: Register \n2: Login\n0:Quit Program\nEnter your choice(0-2): "; cin >> pc;

    if(pc == 1)
    {
        Register();
        main(); // restarting Application.
    }else if(pc == 2)
    {
        bool status = IsLoggedIn();
        if(!status)
        {
            cout << "\n\nLogin Failed!" << endl;
            return 0;
        }else
        {
            cout << "\n\nYou have successfully Logged in!" << endl;
            return 1;
        }
    }
    else if(pc == 0)
    {
        cout << "\nQuiting Program.........." << endl;
        return 0;
    } else{
        cout << "\nUnknown Command! Please try again\n";
        main();
    }

    return 0;
}
