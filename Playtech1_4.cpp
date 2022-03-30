#include <iostream>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int decision = 0;
string person, cashier_pass, input_pass, message;
string username, change_pass1, change_pass2, random;
string  duty1, duty2, duty3;
float GST, balance, inventory;
float electricity_bill, net_bill, rent, income_tax, bill ;
//---------newvariables---------
int product_counter = 0, employee_count = 0;
int current_idx;
//------------------------------
    
//-------------------------------------Arrays----------------------------------
string product_nameA[1000];
int product_priceA[1000];
int product_quantityA[1000];
int product_barcodeA[1000];
string sorted_product_nameA[1000];
int sorted_product_priceA[1000];
int sorted_product_quantityA[1000];
int sorted_product_barcodeA[1000];
//---------------------
string names[100];
string passwords[100];
string roles[100];
string contact[100];
int salary[100];
string address[100];
//-------------------------------------Arrays----------------------------------

void admin_header();
void inventory_controller_header();
void cashier_header();
void Header();
void welcome();

void inventory_stock();
void main_menu();
void admin_login();
void admin();
void controller_login();
void controller();
void cashier_login();
void cashier();

void bill_calculation();
string prod_name_func(int id);
int prod_price_func(int id);
int prod_quantity_func(int id);
string getField(string line, int position);
void update_price();
void update_quantity();
void delete_listing();
bool controller_login_additional(string name, string pass);
bool cashier_login_additional(string name, string pass);
bool admin_login_additional(string name, string pass);
void data_input();
void save();

main()
{
    system("color 04");
    GST = 17;
    balance = 5000;
    person = "NULL";
    data_input();
    main_menu();
}

void admin_header()
{
    cout << "     ---------------------------------" << endl;
    cout << "                   Admin              " << endl;
    cout << "     ---------------------------------" << endl;
}
void inventory_controller_header()
{
    cout << "         ---------------------------------" << endl;
    cout << "                 Inventory Controller      " << endl;
    cout << "         ---------------------------------" << endl;
}
void cashier_header()
{
    cout << "         ----------------------------------" << endl;
    cout << "                      Cashier              " << endl;
    cout << "         ----------------------------------" << endl;
}
void Header()

{
    system("cls");
    cout<<"==========================================================================="<<endl;         
    cout<<" =          _____ _                                                      =        "<<endl;   
    cout<<" =         |   __| |_ ___ ___                                            =        "<<endl;   
    cout<<" =         |__   |   | . | . |                                           =        "<<endl;       
    cout<<" =         |_____|_|_|___|  _|                                           =        "<<endl;      
    cout<<" =                       |_|                                             =        "<<endl;      
    cout<<" =                                                                       =        "<<endl;                                                               
    cout<<" =                       _____                                   _       =        "<<endl;             
    cout<<" =                      |     |___ ___ ___ ___ ___ _____ ___ ___| |_     =        "<<endl;             
    cout<<" =                      | | | | .'|   | .'| . | -_|     | -_|   |  _|    =        "<<endl;             
    cout<<" =                      |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|      =        "<<endl;             
    cout<<" =                                        |___|                          =        "<<endl;                             
    cout<<" =    _____         _                                                    =        "<<endl;
    cout<<" =   |   __|_ _ ___| |_ ___ _____                                        =        "<<endl;
    cout<<" =   |__   | | |_ -|  _| -_|     |                                       =        "<<endl;
    cout<<" =   |_____|_  |___|_| |___|_|_|_|                                       =        "<<endl;
    cout<<" =         |___|                                                         =        "<<endl;
    cout<<"==========================================================================="<<endl;
}
void welcome()
{
    system("color 20");
    Header();
    cout << endl
         << endl;
    cout << "Login Successfull !\n\nPress Any Key ...";
    getch();
    system("color 04");
}
void main_menu()
{
    while (person != "4")
    {
        Header();

        cout << "\n\n   1. Admin" << endl;
        cout << "   2. Inventory Controller" << endl;
        cout << "   3. Cashier\n"
             << endl;
        cout << "   4. Exit\n"
             << endl;
        cout << " Enter...";
        cin >> person;

        if (person == "1") // this portion of code deals with the functionality available for admin
        {
            admin_login();
        }

        if (person == "2") // this portion of code deals with the functionality available for inventory controller
        {
            controller_login();
        }

        if (person == "3") // this portion of code deals with the functionality available for cashier
        {
            cashier_login();
        }
        if (person != "1" && person != "2" && person != "3" && person != "4")
        {
            cout << "Inalid Command!\nPress any key to Continue... ";
            main_menu();
        }
    }
    save();
}

void admin_login()
{
    system("cls");
    Header();
    admin_header();
    cout << "Enter UserName, ";
    cin >> username;
    cout << "Enter Password, ";
    cin >> input_pass;
    if (admin_login_additional(username, input_pass))
    {
        admin();
    }
    if (!admin_login_additional(username, input_pass))
    {
        system("color 40");
        cout << endl
             << "Wrong Password! ";
        getch();
        system("color 04");
    }
}
void admin()
{
    welcome();
    while (decision != 10)
    {
        Header();
        admin_header();

        cout << "   Select One of These Options\n"
             << endl;
        cout << "  1-  Check Balance" << endl;
        cout << "  2-  Check Inventory Worth" << endl;
        cout << "  3-  Transfer Salaries" << endl;
        cout << "  4-  Pay Bill" << endl;
        cout << "  5-  Leave Message for Employees" << endl;
        cout << "  6-  Set GST" << endl;
        cout << "  7-  Check Inventory Stock" << endl;
        cout << "  8-  Update Users" << endl;
        cout << "  9-  Update Salary" << endl;
        cout << "  10- Log Out\n"
             << endl;
        cout << "  Your Option...";
        cin >> decision;

        if (decision == 1)
        {

            Header();

            admin_header();
            cout << "\n  The Shop Balance is, " << balance << endl
                 << endl;
            cout << "  Press any key to continue";
            getch();
        }
        else if (decision == 2)
        {
            Header();
            admin_header();

            int worth = 0;
            for (int i = 0; i <= product_counter; i++)
            {
                worth = worth + (product_quantityA[i] * product_priceA[i]);
            }
            cout << "  You have Inventory Worth, " << worth << endl;
            cout << endl
                 << "  Press any Key to Continue...";

            getch();
        }
        else if (decision == 3)
        {
            Header();

            admin_header();
            for (int i = 0; i < employee_count; i++)
            {
                balance = balance - salary[i];
            }
            cout << "  Salaries have been deducted from balance\nPress any key to Continue...  ";
            getch();
        }
        else if (decision == 4)
        {

            Header();

            admin_header();
            cout << "  Enter Electricity Bill, \n  ";
            cin >> electricity_bill;
            cout << "  Enter Internet Bill, \n  " ;
            cin >> net_bill;
            cout << "  Enter Mischalaneous \n  " ;
            cin >> rent;
            cout << "  Enter Income tax, \n  ";
            cin >> income_tax;
            balance = balance - electricity_bill - net_bill - rent - income_tax;
            cout << "  Bills have been deducted\n  Press any key to Continue... ";
            getch();
        }
        else if (decision == 5)
        {
            Header();

            admin_header();
            cout << "  Leave Message for Employees\n  ";
            cin.ignore();
            getline(cin, message);
            cout << "  Press any Key to Continue... ";
            getch();
        }
        else if (decision == 6)
        {
            Header();

            admin_header();
            cout << "  Current GST is, " << GST << endl;
            cout << "  Enter New GST, ";
            cin >> GST;
            cout << "  Press any Key to Continue... ";
            getch();
        }
        else if (decision == 7)
        {
            Header();

            admin_header();
            inventory_stock();
            cout << endl
                 << endl
                 << "  Press any key to continue";
            getch();
        }
        else if (decision == 8)
        {
            while (decision != 4)
            {
                string temp;
                int x;
                Header();
                admin_header();
                cout << "  1- Add User" << endl;
                cout << "  2- Remove User" << endl;
                cout << "  3- View Users" << endl;
                cout << "  4- Go Back" << endl;
                cout << "\n  Your Option... " << endl;
                cin >> decision;

                if (decision == 1)
                {
                    cout << "  Enter New User's Name\n  ";
                    cin.ignore();
                    getline(cin, names[employee_count ]);
                    cout << "  Enter New User's Password\n  ";
                    cin >> passwords[employee_count ];
                    cout << "  Enter New User's Role\n  ";
                    cin >> roles[employee_count ];
                    cout << "  Enter New User's Contact\n  ";
                    cin >> contact[employee_count ];
                    cout << "  Enter New User's Salary\n  ";
                    cin >> salary[employee_count ];
                    cout << "  Enter New User's Address\n  ";
                    cin.ignore();
                    getline(cin, address[employee_count ]);
                    employee_count++;
                    cout << "\n  User Added Successfully!";
                    getch();
                }
                else if (decision == 2)
                {
                    x = -1;
                    cout << "  Enter User Name ";
                    cin >> temp;
                    for (int i = 0; i <= employee_count; i++)
                    {
                        if (temp == names[i])
                        {
                            x = i;
                            break;
                        }
                    }
                    if (x == -1)
                    {
                        cout << "  Invalid Name!";
                        getch();
                    }
                    else
                    {
                        for (int i = x; i < employee_count; i++)
                        {
                            names[i] = names[i + 1];
                            passwords[i] = passwords[i + 1];
                            roles[i] = roles[i + 1];
                            contact[i] = contact[i + 1];
                            salary[i] = salary[i + 1];
                            address[i] = address[i + 1];
                        }
                        employee_count--;
                        cout << "  User Profile Deleted Successfully!";
                        getch();
                    }
                }
                else if (decision == 3)
                {
                    Header();
                    cout<<endl<<"Names"<<"\t\t\t"<<"Password"<<"\t"<<"Role"<<"\t\t\t"<<"Contact"<<"\t\t\t"<<"Salary"<<"\t\t"<<"Address"<<endl;
                    cout<<"-----"<<"\t\t\t"<<"--------"<<"\t"<<"----"<<"\t\t\t"<<"-------"<<"\t\t\t"<<"------"<<"\t\t"<<"-------"<<endl;
                    for(int i=0; i<employee_count;i++)
                    {
                        cout<<names[i]<<"\t\t\t"<<passwords[i]<<"\t\t"<<roles[i]<<"\t\t\t"<<contact[i]<<"\t\t"<<salary[i]<<"\t\t"<<address[i]<<endl;
                    }
                    cout<<"  Press any Key to Continue...";
                    getch();
                }
                else if (decision != 4)
                {
                    cout << "  Invalid Command!\nTry Again...";
                    cin >> decision;
                }
            }
        }
        else if (decision == 9)
        {
            int x;
            string temp;
            x = -1;
            cout << "  Enter User Name ";
            cin >> temp;
            for (int i = 0; i <= employee_count; i++)
            {
                if (temp == names[i])
                {
                    x = i;
                    break;
                }
            }
            if (x == -1)
            {
                cout << "  Invalid Name!";
                getch();
            }
            else
            {
                cout<<"  Current Salary is, "<<salary[x]<<endl;
                cout<<"  Enter New Salary ";
                cin>>salary[x];
                cout << "  Salary Updated Successfully!";
                getch();
            }
        }
        else if (decision != 10)
        {
            cout << "  Wrong Command\n  Press any key to Continue... ";
            getch();
            admin();
        }
    }
    decision = 0;
}
void controller_login()
{
    system("cls");
    Header();
    inventory_controller_header();

    cout << "Enter UserName, ";
    cin >> username;
    cout << "Enter Password, ";
    cin >> input_pass;
    if (!controller_login_additional(username, input_pass))
    {
        system("color 40");
        cout << endl
             << "Wrong Credentials ! ";
        getch();
        system("color 04");
    }

    if (controller_login_additional(username, input_pass))
    {
        welcome();
        while (decision != 6)
        {
            controller();
        }
        decision = 0;
    }
}
void controller()
{
    system("cls");
    Header();
    inventory_controller_header();

    cout << "  Select One of these options\n"
         << endl;
    cout << "  1- Check Inventory" << endl;
    cout << "  2- Set Duties of Warehouse Employees" << endl;
    cout << "  3- Add Products" << endl;
    cout << "  4- Update Stock" << endl;
    cout << "  5- Message from Admin" << endl;
    cout << "  6- Log Out\n"
         << endl;
    cout << " Your Option..." << endl;
    cin >> decision;

    if (decision == 1)
    {
        system("cls");
        Header();
        inventory_controller_header();
        inventory_stock();
        cout << endl
             << endl;
    }
    else if (decision == 2)
    {
        system("cls");
        Header();
        inventory_controller_header();
        cout << "  Set Duty of Employeee 1 ";
        cin.ignore();
        getline(cin ,duty1);
        cout << "  Set Duty of Employeee 2 ";
        cin.ignore();
        getline(cin, duty2);
        cout << "  Set Duty of Employeee 3 ";
        cin.ignore();
        getline(cin ,duty3);
        cout << "  Press any Key to Continue... ";
        getch();
    }
    else if (decision == 3)
    {
        while (true)
        {
            system("cls");
            Header();
            inventory_controller_header();
            cout << "   ------------------------------------\n";
            cout << "               Add Products            \n";
            cout << "   ------------------------------------\n\n";

            cout << "  Enter Product Name ";
            cin >> product_nameA[product_counter];
            cout << "  Enter Product Price ";
            cin >> product_priceA[product_counter];
            cout << "  Enter Product Quantity ";
            cin >> product_quantityA[product_counter];
            cout << "  Enter Product Barcode ";
            cin >> product_barcodeA[product_counter];
            product_counter = product_counter + 1;

            char a;
            cout << endl
                 << endl
                 << "  Do you Want to Add more Products?\n  Press Any key for Yes, or N for No ";
            cin >> a;
            if (a == 'n' || a == 'N')
            {
                break;
            }
        }
    }
    else if (decision == 4)
    {
        while (true)
        {
            system("cls");
            Header();

            cout << "   ------------------------------------\n";
            cout << "               Update Stock            \n";
            cout << "   ------------------------------------\n\n";

            cout << "  1- Update Price " << endl;
            cout << "  2- Update Quantity " << endl;
            cout << "  3- Delete Product Listing " << endl;
            cout << "  4- Go Back " << endl;
            cout << "\n  Your Option...  " << endl;
            cin >> decision;
            while (decision != 1 && decision != 2 && decision != 3 && decision != 4)
            {
                cout << "  Invalid Command \n  Try Again ";
                cin >> decision;
            }

            if (decision == 1)
            {
                update_price();
            }
            else if (decision == 2)
            {
                update_quantity();
            }
            else if (decision == 3)
            {
                delete_listing();
            }
            else if (decision == 4)
            {
                break;
            }

            char a;
            cout << endl
                 << endl
                 << "  Do you Want to Update more Products?\n  Press Any key for Yes, or N for No ";
            cin >> a;
            if (a == 'n' || a == 'N')
            {
                break;
            }
        }
    }
    else if (decision == 5)
    {
        system("cls");
        Header();
        inventory_controller_header();
        cout << "--------Message from Admin--------\n\n";
        cout << message;
        cout << endl
             << endl
             << "  Press any key to continue";
        getch();
    }
    else if (decision != 6)
    {
        cout << "  Invalid Command!\n  Press any Key to Continue...";
        getch();
        controller();
    }
}
void cashier_login()
{
    system("cls");
    Header();
    cashier_header();

    cout << "Enter UserName, ";
    cin >> username;
    cout << "Enter Password, ";
    cin >> input_pass;

    if (!cashier_login_additional(username, input_pass))
    {
        system("color 40");
        cout << endl
             << "Wrong Credentials ! ";
        getch();
        system("color 04");
    }
    if (cashier_login_additional(username, input_pass))
    {
        welcome();
        while (decision != 5)
        {
            cashier();
        }
        decision = 0;
    }
}
void cashier()
{

    string input_pass1,name;
    system("cls");
    Header();
    cashier_header();

    cout << "  Select one of these Options\n"
         << endl;
    cout << "  1- Bill Calculation" << endl;
    cout << "  2- Change Password" << endl;
    cout << "  3- Return Policy" << endl;
    cout << "  4- Message from Manager" << endl;
    cout << "  5- Log Out\n"
         << endl;
    cout << "  Your Option...";
    cin >> decision;

    if (decision == 1)
    {
        bill_calculation();
    }
    if (decision == 2)
    {
        system("cls");
        Header();
        cashier_header();
        cout << "  Enter Name, ";
        cin>>name;
        cout << "  Enter Password, ";
        cin >> input_pass1;
        cout << "  Enter New Password, ";
        cin >> change_pass1;
        cout << "  Re Enter New Password, ";
        cin >> change_pass2;
        if (change_pass1 == change_pass2 && (cashier_login_additional(name, input_pass1)))
        {
            passwords[current_idx] = change_pass1;
        }
        else
        {
            cout << "  Password dont match";

            cout << endl
                 << endl
                 << "  Press any key to continue";
            getch();
        }
    }
    if (decision == 3)
    {
        int barcodeR, qtyR, x=-1 ;
        cout << "  Enter Product Barcode ";
        cin>>barcodeR;
        cout << "  Enter Quantity ";
        cin>>qtyR;
        for(int i=0; i<product_counter; i++)
        {   
            if(product_barcodeA[i]==barcodeR)
            {
                x=i;
            }
        }
        if(x==-1)
        {
            cout<<"  Invalid Barcode! ";
            getch();
        }
        else{
            balance = balance - (product_quantityA[x]*qtyR);
            product_quantityA[x]=product_quantityA[x]-qtyR;
            cout<<"  Thanks for Coming! ";
            getch();
        }
    }
    if (decision == 4)
    {
        system("cls");
        Header();
        inventory_controller_header();
        cout << "--------Message from Admin--------\n\n";
        cout << message << endl
             << endl;
        cout << "  Press any key to continue";
        getch();
    }
    if (decision != 1 && decision != 2 && decision != 3 && decision != 4 && decision != 5)
    {
        cout << "  Wrong Command\n  Press any key to Continue... ";
        getch();
        cashier();
    }
}

//----------------------------------------------------------------------------------------
void bill_calculation()
{
    string ordered_ids = "";
    string ordered_qty = "";
    char goback = 'n';
    int items_counter = 0;
    int prod_id, quantity, price, bill = 0;
    char continuity = 'y';
    while (continuity != 'n' && continuity != 'N')
    {
        system("cls");
        Header();
        cashier_header();

        cout << "   -----------------------------" << endl;
        cout << "          Bill Calculation      " << endl;
        cout << "   -----------------------------\n"
             << endl;

        cout << "  Enter Product ID "
             << "                                               Total Bill :  " << bill << endl;
        cin >> prod_id;

        if (prod_name_func(prod_id) == "" || prod_quantity_func(prod_id) == 0)
        {
            cout << "  Product Not Available! " << endl;
            cout << "  To retry, Press Y otherwise N ";
            cin >> continuity;
            while (continuity != 'N' && continuity != 'n' && continuity != 'Y' && continuity != 'y')
            {
                cout << "  Invalid Command\n\n";
                cout << "  To retry, Press Y otherwise N  ";
                cin >> continuity;
            }
            if (continuity == 'n' || continuity == 'N')
            {
                goback = 'y';
            }
            continue;
        }
        cout << "  Product Name " << prod_name_func(prod_id) << endl;
        price = prod_price_func(prod_id);
        cout << "  Product Price " << price << endl
             << endl;
        cout << "  Enter Quantity ";
        cin >> quantity;
        if (quantity > prod_quantity_func(prod_id))
        {
            cout << "  There are only " << prod_quantity_func(prod_id) << " Units left\nTry Again";
            getch();
            continue;
        }

        bill = bill + (price * quantity);

        ordered_ids = ordered_ids.append(to_string(prod_id));
        ordered_ids = ordered_ids.append(",");
        ordered_qty = ordered_qty.append(to_string(quantity));
        ordered_qty = ordered_qty.append(",");

        cout << "  Do you want to Enter Another Product?\nFor Yes, Enter Y, For No, Enter N ";
        cin >> continuity;
        while (continuity != 'N' && continuity != 'n' && continuity != 'Y' && continuity != 'y')
        {
            cout << "  Invalid Command";
            getch();
            cout << "  Do you want to Enter Another Product?\nFor Yes, Enter Y, For No, Enter N ";
            cin >> continuity;
        }
        items_counter = items_counter + 1;
    }
    if (goback != 'y')
    {
        system("cls");
        Header();

        cout << "   -----------------------------" << endl;
        cout << "          Bill Calculation      " << endl;
        cout << "   -----------------------------\n"
             << endl;

        cout << "  Your Bill is, " << bill << endl
             << "  And GST is, " << (bill * GST / 100) << endl
             << endl
             << "  Your Gross Bill is, " << (bill + (bill * GST / 100));
        cout << endl
             << endl
             << "  To Confirm Payment, Press Y otherwise Press N ";
        cin >> continuity;
        while (continuity != 'y' && continuity != 'Y' && continuity != 'n' && continuity != 'N')
        {
            cout << "  Invalid Command ";
            getch();
            cout << "  Try Again  ";
            cin >> continuity;
        }
        if (continuity == 'Y' || continuity == 'Y')
        {
            for (int i = 1; i <= items_counter + 1; i++)
            {
                

                int id = stoi(getField(ordered_ids, i));
                int qty = stoi(getField(ordered_qty, i));
                for (int i = 0; i < 1000; i++)
                {
                    if (product_barcodeA[i] == id)
                    {
                        product_quantityA[i] = product_quantityA[i] - qty;
                    }
                }
            }
        }
        balance = balance + bill;
    }
}
void inventory_stock()
{
    cout << "Sr#\tProduct Name\t\t\tUnit Price\t\tQuantity" << endl;
    cout << "---\t------------\t\t\t----------\t\t--------" << endl;
    for (int i = 0; i <= product_counter-1 ; i++)
    {
        cout << i + 1 << "\t" << product_nameA[i] << "\t\t\t\t" << product_priceA[i] << "\t\t\t" << product_quantityA[i] << endl;
    }
        cout << endl
             << "Press any Key to Continue ...";
        getch();
}
string prod_name_func(int id)
{
    int x;
    string name = "";
    for (int i = 0; i < 1000; i++)
    {
        if (id == product_barcodeA[i])
        {
            name = product_nameA[i];
            break;
        }
    }
    return name;
}
int prod_price_func(int id)
{
    int x, price = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (id == product_barcodeA[i])
        {
            price = product_priceA[i];
            break;
        }
    }
    return price;
}
int prod_quantity_func(int id)
{
    int x, quantity = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (id == product_barcodeA[i])
        {
            x = i;
            quantity = product_quantityA[x];
            break;
        }
    }
    return quantity;
}
void update_price()
{
    system("cls");
    Header();
    cout << "   ------------------------------------\n";
    cout << "               Update Price            \n";
    cout << "   ------------------------------------\n\n";

    int id, price, x;
    cout << "  Enter Product Barcode ";
    cin >> id;
    cout << "  Enter New Price ";
    cin >> price;

    for (int i = 0; i <= product_counter; i++)
    {
        if (id == product_barcodeA[i])
        {
            x = i;
            break;
        }
    }
    product_priceA[x] = price;
}
void update_quantity()
{
    system("cls");
    Header();
    cout << "  -----------------------------------\n";
    cout << "            Update Quantity           \n";
    cout << "  -----------------------------------\n\n";

    int id, qty, x;
    cout << "  Enter Product Barcode ";
    cin >> id;
    cout << "  Enter New Quantity ";
    cin >> qty;

    for (int i = 0; i <= product_counter; i++)
    {
        if (id == product_barcodeA[i])
        {
            x = i;
            break;
        }
    }
    product_quantityA[x] = qty;
}
void delete_listing()
{
    system("cls");
    Header();
    cout << "  ----------------------------------------\n";
    cout << "           Delete Product Listing         \n";
    cout << "  ----------------------------------------\n\n";

    cout << "  Enter the Product Barcode that You Want to Delete " << endl;
    int id, idx = -1;
    cin >> id;
    for (int i = 0; i <= product_counter; i++)
    {
        if (id == product_barcodeA[i])
        {
            idx = i;
            for (int j = idx; j <= product_counter; j++)
            {
                product_nameA[j] = product_nameA[j + 1];
                product_priceA[j] = product_priceA[j + 1];
                product_quantityA[j] = product_quantityA[j + 1];
                product_barcodeA[j] = product_barcodeA[j + 1];
            }
            product_nameA[product_counter] = "";
            product_priceA[product_counter] = 0;
            product_quantityA[product_counter] = 0;
            product_barcodeA[product_counter] = 0;
            product_counter = product_counter - 1;
        }
    }
    if (idx == -1)
    {
        cout << "  Invalid Barcode !";
        getch();
    }
    else
    {
        cout << "  Product Deleted Successfully !";
        getch();
    }
}
bool controller_login_additional(string name, string pass)
{
    for (int i = 0; i < employee_count; i++)
    {
        if (name == names[i] && pass == passwords[i] && roles[i] == "iv_ctrl")
        {
            current_idx=1;
            return true;
        }
    }
    return false;
}
bool cashier_login_additional(string name, string pass)
{
    for (int i = 0; i < employee_count; i++)
    {
        if (name == names[i] && pass == passwords[i] && roles[i] == "cashier")
        {
            current_idx=1;
            return true;
        }
    }
    return false;
}
bool admin_login_additional(string name, string pass)
{
    for (int i = 0; i < employee_count; i++)
    {
        if (name == names[i] && pass == passwords[i] && roles[i] == "admin")
        {
            current_idx=1;
            return true;
        }
    }
    return false;
}
void data_input()
{
    string line = " ";
    fstream file;
    file.open("employees.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        names[employee_count] = getField(line, 1);
        passwords[employee_count] = getField(line, 2);
        roles[employee_count] = getField(line, 3);
        contact[employee_count] = getField(line, 4);
        salary[employee_count] = stoi(getField(line, 5));
        address[employee_count] = getField(line, 6);
        employee_count++;
    }
    file.close();

    int temp;
    string helper;
    fstream doc;
    doc.open("products.txt", ios::in);
    while (!doc.eof())
    {
        getline(doc, line);
        cout << line;
        product_nameA[product_counter] = getField(line, 1);
        helper = getField(line, 2);
        product_priceA[product_counter] = stoi(helper);
        helper = getField(line, 3);
        product_quantityA[product_counter] = stoi(helper);
        helper = getField(line, 4);
        product_barcodeA[product_counter] = stoi(helper);
        product_counter++;
    }
    doc.close();


    fstream file2;
    file2.open("data.txt", ios::in);
    while(!file.eof())
    {
        string u;
        file>>u;
        
        balance = stoi(getField(u,1));
        GST = stoi(getField(u,2));
    }
    file2.close();
}
string getField(string line, int position)
{
    string item;
    int commaCount = 1;

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '^')
            commaCount++;
        else if (commaCount == position)
            item = item + line[i];
    }

    return item;
}
void save()
{
    fstream file;
    file.open("products.txt", ios::out);
    for (int i = 0; i <= product_counter-1; i++)
    {
        if(i!=0)
        {
            file << endl;
        }
        file << product_nameA[i] << "^" << product_priceA[i] << "^" << product_quantityA[i] << "^" << product_barcodeA[i];
    }
    file.close();
    file.open("employees.txt", ios::out);
    for (int i = 0; i <= employee_count-1; i++)
    {
        if(i!=0)
        {
            file << endl;
        }
        file << names[i] << "^" << passwords[i] << "^" << roles[i] << "^" << contact[i] << "^"<< salary[i] << "^" << address[i];
    }
    file.close();
    fstream file1;
    file1.open("data.txt",ios::out);
    file<<balance<<"^"<<GST;
    file1.close();
}
//----------------------------------------------------------------------------------------
