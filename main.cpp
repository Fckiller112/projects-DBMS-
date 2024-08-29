#include <bits/stdc++.h>
#include<iomanip>
#include <windows.h>
#include <mysql.h>
using namespace std;
void insertion(string centername, string name, int id, string date, string phoneno, int noofcls) {
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "ngo", 0, NULL, 0);
    if (conn) {
        cout << "Connection success" << endl;
            string query = "INSERT INTO `"+centername+"`(Id, Vname, Phone_no, Date_of_join, No_of_cls) VALUES ('" + to_string(id) + "','" + name + "','" + phoneno + "','" + date + "','" +
             to_string(noofcls) + "')";
            const char* q = query.c_str();
            qstate = mysql_query(conn, q);
            if (!qstate) {
                cout << "Record inserted successfully..." << endl;
            }else {
                cout << "Query problem: " << mysql_error(conn) << endl;
            }
    }
     else {
        cout << "Connection object problem! " << mysql_error(conn) << endl;
    }
}

void setConsoleColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printLine(int length, char ch) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

void display(string centername) {
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "ngo", 0, NULL, 0);

    if (conn) {
        cout << "Connection success" << endl;
            string query = "SELECT * FROM `" + centername + "`";
            qstate = mysql_query(conn, query.c_str());
            if (!qstate) {
                res = mysql_store_result(conn);
                int consoleWidth = 80; // Assuming console width of 80 characters
                string tableHeading = centername;
                int headingPosition = (consoleWidth - tableHeading.length()) / 2;

                // Print heading with color
                setConsoleColor(14); // Yellow
                cout << tableHeading << endl;

                // Print top border with color
                setConsoleColor(15); // White
                printLine(consoleWidth - 8, '-'); // Adjusted for left and right padding

                // Print table headers with color
                setConsoleColor(11); // Light Blue
                cout << " | " << setw(6) << "ID"
                     << " | " << setw(15) << "Vname"
                     << " | " << setw(10) << "Phone_no"
                     << " | " << setw(12) << "Date_of_join"
                     << " | " << setw(12) << "No_of_cls"
                     << " |" << endl;

                // Print separator line with color
                setConsoleColor(15); // White
                printLine(consoleWidth - 8, '-');
                bool isAlternate = true;
                while ((row = mysql_fetch_row(res))) {
                    setConsoleColor(isAlternate ? 2 : 3);
                    cout << " | " << setw(6) << left << row[0]
                         << " | " << setw(15) << left << row[1]
                         << " | " << setw(10) << left << row[2]
                         << " | " << setw(12) << left << row[3]
                         << " | " << setw(12) << left << row[4]
                         << " |" << endl;
                    isAlternate = !isAlternate;
                }

                // Print bottom border with color
                setConsoleColor(15); // White
                printLine(consoleWidth - 8, '-');

                // Free the result set
                mysql_free_result(res);
            } else {
                setConsoleColor(12); // Red for errors
                cout << "Query error: " << mysql_error(conn) << endl;
                setConsoleColor(15); // Reset to white
            }
    } else {
        cout << "Connection object problem! " << mysql_error(conn) << endl;
    }

    // Close the MySQL connection
    mysql_close(conn);
}
void specificdis(int id,string centername){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","ngo",0,NULL,0);
    if (conn){
        cout<<"connection success"<<endl;
        string query = "SELECT * FROM `" + centername + "` WHERE Id = '" + to_string(id) + "'";
        qstate = mysql_query(conn, query.c_str());
        if(!qstate){
            res=mysql_store_result(conn);
            int consolewidth=80;
            printLine(consolewidth-8,'-');
            setConsoleColor(11); // Light Blue
                cout << " | " << setw(6) << "ID"
                     << " | " << setw(15) << "Vname"
                     << " | " << setw(10) << "Phone_no"
                     << " | " << setw(12) << "Date_of_join"
                     << " | " << setw(12) << "No_of_cls"
                     << " |" << endl;
            setConsoleColor(15);
            printLine(consolewidth-8,'-');
            bool isalternate=true;
            while(row=mysql_fetch_row(res)){
                    setConsoleColor(isalternate ?  2:3);
                  cout << " | " << setw(6) << left << row[0]
                         << " | " << setw(15) << left << row[1]
                         << " | " << setw(10) << left << row[2]
                         << " | " << setw(12) << left << row[3]
                         << " | " << setw(12) << left << row[4]
                         << " |" << endl;
                  isalternate = !isalternate;
            }
            setConsoleColor(15);
            printLine(consolewidth-8,'-');
            mysql_free_result(res);
        }
        else{
            cout<<"query error"<<mysql_error(conn)<<endl;
        }
    }
    else{
        cout<<"Connection object problem!"<<mysql_error(conn)<<endl;
    }
}
void descdatabase(){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","ngo",0,NULL,0);
    if (conn){
        cout<<"connection success"<<endl;
        qstate=mysql_query(conn,"SHOW TABLES");
        if(!qstate){
            res=mysql_store_result(conn);
            int consolewirdth=80;
            string heading="Available Centers";
            setConsoleColor(14);
            cout<<heading<<endl;
            printLine(consolewirdth-50,'-');
            cout<<" | "<<setw(5)<<"Centers Name"<<endl;
            printLine(consolewirdth-50,'-');
            bool isalternate=true;
            while(row=mysql_fetch_row(res)){
                setConsoleColor(isalternate? 2:3);
                cout<<" | "<<setw(25)<<left<<row[0]<<" | "<<endl;
                isalternate=!isalternate;
            }
            setConsoleColor(14);
            printLine(consolewirdth-50,'-');
            setConsoleColor(15);
            mysql_free_result(res);
        }
        else{
            cout<<"query error"<<endl;
        }
    }
    else{
        cout<<"Connection object problem!"<<mysql_error(conn)<<endl;
    }
}
void deleterec(string cenetername,int id){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","ngo",0,NULL,0);
    if (conn){
        cout<<"connection success"<<endl;
        string quary="DELETE FROM `"+cenetername+"` WHERE ID= '"+to_string(id)+"'";//type of quotes also matters a lot here
        qstate=mysql_query(conn,quary.c_str());
        if(!qstate){
            cout<<"Record deleted successfully"<<endl;
        }
        else{
            cout<<"query error"<<mysql_error(conn)<<endl;
        }
    }
    else{
        cout<<"Connection object problem!"<<mysql_error(conn)<<endl;
    }
}
void updaterec(string centername,int id,int newval){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","ngo",0,NULL,0);
    if (conn){
        cout<<"connection success"<<endl;
        string query = "UPDATE `" + centername + "` SET `No_of_cls` = '" + to_string(newval) + "' WHERE ID = '" + to_string(id) + "'";
        qstate = mysql_query(conn, query.c_str());
        if(!qstate){
            cout<<"Record updated successfully"<<endl;
        }
        else{
            cout<<"query problem"<<endl;
        }
    }
    else{
        cout<<"Connection object problem!"<<mysql_error(conn)<<endl;
    }
}
int main()
{
    char check='y';
    do{
        cout<<"******WELCOME TO VOLUNTEER/INTERNS RECORD SYSTEM******"<<endl;
        cout<<"HOW CAN I HELP YOU?"<<endl;
        cout<<"Available options are given below :)"<<endl;
        cout<<"1: To enter the data for a new intern/volunteer"<<endl;
        cout<<"2: To check the data for all the interns/volunteers"<<endl;
        cout<<"3: To check the data for a specific intern/volunteers"<<endl;
        cout<<"4: To check how many centers are there"<<endl;
        cout<<"5: To delete a record"<<endl;
        cout<<"6: To update a record"<<endl;
        int op;
        cout<<"Enter a valid operation"<<endl;
        cin>>op;
        if(op==1){
            cout<<"Available Center List is given below"<<endl;
            descdatabase();
            string centername,name,date,phoneno;
            int id,noofclasses;
            cout<<"Enter the center name in which the volunteer wishes to go"<<endl;
            cin.ignore();
            getline(cin,centername);
            cout<<"Enter the first name of the volunteer/intern"<<endl;
            cin>>name;
            name+=" ";
            cout<<"Enter the last name of the volunteer/intern"<<endl;
            string last;
            cin>>last;
            name+=last;
            cout<<"Enter the id of the volunteer/intern"<<endl;
            cin>>id;
            cout<<"Enter the date of join"<<endl;
            cin>>date;
            cout<<"Enter the Phone No of the volunteer/intern"<<endl;
            cin>>phoneno;
            cout<<"Enter the No of Classes he/she has attended"<<endl;
            cin>>noofclasses;
            insertion(centername,name,id,date,phoneno,noofclasses);
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>check;
        }
        else if(op==2){
            cout<<"Available Center List is given below"<<endl;
            descdatabase();
            string centername;
            cout<<"Enter the center name who's data you want to see"<<endl;
            cin.ignore();
            getline(cin,centername);
            display(centername);
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>check;
        }
        else if(op==3){
            cout<<"Available Center List is given below"<<endl;
            descdatabase();
            cout<<"Enter the center name where the volunteer/intern is present"<<endl;
            string centername;
            cin.ignore();
            getline(cin,centername);
            cout<<"Enter the id of that intern"<<endl;
            int id;
            cin>>id;
            specificdis(id,centername);
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>check;
        }
        else if(op==4){
            cout<<"Available Center List is given below"<<endl;
            descdatabase();
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>check;
        }
        else if(op==5){
            cout<<"Available Center List is given below"<<endl;
            descdatabase();
            cout<<"Enter the center name where the volunteer/intern is present"<<endl;
            string centername;
            cin.ignore();
            getline(cin,centername);
            cout<<"Enter the id of that intern"<<endl;
            int id;
            cin>>id;
            deleterec(centername,id);
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>check;
        }
        else if(op==6){
            cout<<"Available Center List is given below"<<endl;
            descdatabase();
            cout<<"Enter the center name where you want to do the updation"<<endl;
            string centername;
            cin.ignore();
            getline(cin,centername);
            cout<<"Enter the new value of the No_of_classes attended"<<endl;
            int colname;
            cin>>colname;
            cout<<"Enter the id of the record you want to update"<<endl;
            int id;
            cin>>id;
            updaterec(centername,id,colname);
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>check;
        }
    }while(check!='n');
    return 0;
}
