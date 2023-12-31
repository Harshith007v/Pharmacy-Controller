

// Standard Libraries
#include <iostream>

#include <stdlib.h>

#include <unistd.h>

#include <string>

#include <cstring>

#include <cctype>

#include <cmath>

#include <cstdio>

#include <fstream>

#include <iomanip>

#include <conio.h>

#include <windows.h>

#include<ctime>

#define MAX 10

// Header File
using namespace std;

// Base Class
class pharmacyManagementSystem
{
public:
    void mainMenu();            // Pharmacy Management System Main Menu
    void search();              // Search For Certain Medicine
    void takeOrder();           // Orders To Be Taken
    void deleteOrder();         // Delete The Medicine
    void modify();              // Modify The Medicine/ Customer Information
    void orderList();           // Display The Order List
    void dailySummary();        // Display The Summary List
    void exit();                // Exit Function
    void displayMedicine();     // Displays The Set Of Medicine
    void displayCustomers();    // Displays The Set Of Customers - Back Up
    void userSelection();       // Admin/Customer Selection
    pharmacyManagementSystem(); // Constuctor
};

pharmacyManagementSystem::pharmacyManagementSystem() {} // Constructor For Class pharmacyManagementSystem

// Structure Of Type Node
struct node
{
    string customerName;
    string date;
    string medicineName[MAX] = {
        "Dolo 650",
        "CITRA C",
        "Bupropion",
        "Zoloft",
        "Sumitop",
        "Omeprazole",
        "Digene",
        "HealthVit",
        "Naproxen",
        "Neurobion"};
    int recieptNumber;
    int quantity[MAX];
    int x;
	int menu2[MAX];
    float amount[MAX];
    double Medicine[MAX] = {
        200.00,
        200.00,
        500.00,
        400.00,
        500.00,
        300.00,
        100.00,
        400.00,
        300.00,
        300.00};
    int MedQuant[MAX]={10,10,10,20,20,20,14,14,14,7};
    double total;
    node *prev;
    node *next;
    node *link;
} * q, *temp; // Pointer Of Type Node

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

// Main Menu
void pharmacyManagementSystem::mainMenu()
{
    pharmacyManagementSystem pharmacyManagementSystemObj;
    int choice;
    do
    {
        cout << "\n\t      PHARMACY MANAGEMENT SYSTEM USING PRIMARY AND SECONDARY INDEXING \n";
        cout << "\t    ====================================================================\n\n";
        cout << "\t    --------------------------------------------------------------------\n";
        cout << "\t ||\t\t\t1. Search For The Medicine  \t\t\t||\n";
        cout << "\t ||\t\t\t2. New Medicine Order \t\t\t\t||\n";
        cout << "\t ||\t\t\t3. Delete Latest Medicine Order Details \t||\n";
        cout << "\t ||\t\t\t4. Modify Order List \t\t\t\t||\n";
        cout << "\t ||\t\t\t5. Print Reciept And Make Payment \t\t||\n";
        cout << "\t ||\t\t\t6. Daily Summary Of Total Sales \t\t||\n";
        cout << "\t ||\t\t\t7. Display Available Medicine \t\t\t||\n";
        cout << "\t ||\t\t\t8. Display Back Up Customer Details \t\t||\n";
        cout << "\t ||\t\t\t9. Exit \t\t\t\t\t||\n";
        cout << "\t    -------------------------------------------------------------------\n";
        cout << "\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            pharmacyManagementSystemObj.search();
            break;
        }

        case 2:
        {
            pharmacyManagementSystemObj.takeOrder();
            break;
        }

        case 3:
        {
            pharmacyManagementSystemObj.deleteOrder();
            break;
        }

        case 4:
        {
            pharmacyManagementSystemObj.modify();
            break;
        }

        case 5:
        {
            pharmacyManagementSystemObj.orderList();
            break;
        }

        case 6:
        {
            pharmacyManagementSystemObj.dailySummary();
            break;
        }

        case 7:
        {
            pharmacyManagementSystemObj.displayMedicine();
            break;
        }

        case 8:
        {
            pharmacyManagementSystemObj.displayCustomers();
            break;
        }

        case 9:
        {
            pharmacyManagementSystemObj.exit();
            system("CLS");
            break;
        }

        default:
        {
            cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                 << endl;
            break;
        }
        }
    } while (choice != 9);
}

// Search Function
void pharmacyManagementSystem::search()
{
    system("CLS");
    string search;
    string line;
    int choice, i, offset, flag = 0;
    node *temp;
    temp = new node;
    cout << "=====================================================" << endl;
    cout << "Search :\n";
    cout << "=====================================================" << endl;
    cout << "Enter The Name Of The Medicine You Wish To Search : "; // Search For Medicine
    cin.ignore();
    getline(cin, search);
    cout << endl;
    for (i = 0; i < MAX; i++)
    {
        if (strcmpi((search.c_str()), (temp->medicineName[i].c_str())) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "Found" << endl;
        cout << "*****************************************************************" << endl;
        cout << "|  DRUG'S NAME  | DRUG'S PRICE(Rs.) | DRUG'S QUANTITY AVAILABLE |" << endl;
        cout << "*****************************************************************" << endl;
        cout << "|    " << temp->medicineName[i] << "     |       " << temp->Medicine[i] << "         |       " <<temp->MedQuant[i] <<"                  |"<<endl;
        cout << "*****************************************************************" << endl;
        cout << endl;
    }
    else
    {
        cout << "Medicine Stocked Out, Kindly Visit Tomorrow!" << endl;
    }
    system("PAUSE");
    system("CLS");
}

// Take Order Function
void pharmacyManagementSystem::takeOrder()
{
    system("CLS");
    int i,ordnm,num;
    float totalPrice = 0;
    string takeOrderText;
    cout << "\nSelect The Medicines That You Would Like To Buy\n";
    cout << "------------------------------------------------ \n\n";
    node *temp;
    temp = new node;
    // ofstream out("takeCustomerInfo.txt");
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);
    ifstream in("takeOrder.txt");
    for (i = 0; i < 14; i++)
    {
        getline(in, takeOrderText);
        cout << takeOrderText << endl;
    }
    cout << "" << endl;
	cout << "Order Number: " ;
	
	//for reading the number from a file
	ifstream on("order.txt");
	on>>ordnm;
	cout<<ordnm<<endl;
	temp->recieptNumber=ordnm++;
	num=ordnm;
	on.close();
	
	//for entering the next order number to the file
	ofstream op("order.txt");
	op<<num;
	op.close();
	
    out << "Order Number : " << temp->recieptNumber << endl;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, temp->customerName);
    out << "Customer Name : " << temp->customerName << endl;
    cout << "Enter Date: ";
    cin >> temp->date;
    out << "Date : " << temp->date << endl;
    cout << "" << endl;
    cout << "\"NOTE : Maximum 10 Medicine Can Be Ordered Per Transaction\" \n";
    cout << "Please Enter The Total Count Of Medicines You Would Like To Order: ";
    cin >> temp->x;
    out << "Number Of Medicine Ordered : " << temp->x << endl;
    if (temp->x > MAX)
    {
        cout << "Excessive Amount Of Medicine Ordered Error!";
        system("PAUSE");
    }
    else
    {
        for (i = 0; i < temp->x; i++)
        {
            cout << "Please Enter The Medicine ID That You Wish To Buy : ";
            cin >> temp->menu2[i];
            cout << "Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
            out << "Medicine Name : " << temp->medicineName[temp->menu2[i] - 1] << endl;
            cout << "Count Of The Respective Medicine : ";
            cin >> temp->quantity[i];
            out << "Medicine Quantity : " << temp->quantity[i] << endl;
            temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
            totalPrice = totalPrice + temp->amount[i];
        }
        cout << "You've Been Charged With Amount Of Rs. " << totalPrice << ".00" << endl; // Displaying The Total Price Charged
        out << "Total Price : Rs. " << totalPrice << ".00\n"
            << endl;
        out << "==================================\n"
            << endl;
        cout << "===========================================================================" << endl;
        cout << "Order Placed Successfully" << endl;
        cout << "===========================================================================" << endl;
        cout << "Head To The Reciept Menu To Pay The Bill" << endl;
        cout << "===========================================================================" << endl;
        sleep(3);
        
        temp->next = NULL;
        if (start_ptr != NULL)
        {
            temp->next = start_ptr;
        }
        start_ptr = temp;
       // system("PAUSE");
        system("CLS");
    }
}

// Delete Order Function
void pharmacyManagementSystem::deleteOrder()
{
    system("CLS");
    int i, num, count;
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);

    cout << "Enter the Order Number You Wish To Delete : ";
    cin >> num;
    node *q;
    node *temp;
    bool found;

    if (start_ptr == NULL)
        cerr << "Empty List, No Entries Detected To Delete\n";
    else
    {
        if (start_ptr->recieptNumber == num)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;
            count--;
            if (start_ptr == NULL)
                last = NULL;
            delete q;
            cout << "The Order is Deleted Successfully!" << endl;
        }
        else
        {
            found = false;
            temp = start_ptr;
            q = start_ptr->next;
            while ((!found) && (q != NULL))
            {
                if (q->recieptNumber != num)
                {
                    temp = q;
                    q = q->next;
                }
                else
                    found = true;
            }
            if (found)
            {
                temp->next = q->next;
                count--;
                if (last == q)
                    last = temp;
                delete q;
                cout << "The Order is Deleted Successfully!" << endl;
            }
            else
                cout << "Sorry, No Such Order Found!\n"
                     << endl;
        }
    }
}

// Modify Order/Customer Details Function
void pharmacyManagementSystem::modify()
{
    system("CLS");
    int i, sid;
    bool found;
    found = false;
    float totalPrice = 0;
    node *temp;
    temp = start_ptr;
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);

    cout << "Enter Order Number To Modify: ";
    cin >> sid;
    if (temp == NULL || sid == 0)
    {
        cout << "No Such Record Found To Modify!" << endl;
    }
    else
    {
        while (temp != NULL && !found)
        {
            if (temp->recieptNumber == sid)
            {
                found = true;
            }
            else
            {
                temp = temp->next;
            }
            if (found)
            {
                cout << "Order Number : ";
                cout<<temp->recieptNumber;
                //out << "Reciept Number : " << temp->recieptNumber << endl;
                cout << "\nChange Customer Name : ";
                cin.ignore();
                getline(cin, temp->customerName);
                out << "Customer Name : " << temp->customerName << endl;
                cout << "Change Date : ";
                cin >> temp->date;
                out << "Date : " << temp->date << endl;
                cout << "" << endl;
                cout << "\"NOTE : Maximum 10 Medicine Can Be Ordered Per Transaction\" \n";
                cout << "Please Enter The Total Count Of Medicines You Would Like To Order: ";
                cin >> temp->x;
                out << "Number Of Medicine Ordered : " << temp->x << endl;
                if (temp->x > MAX)
                {
                    cout << "Excessive Amount Of Medicine Ordered Error!";
                    system("PAUSE");
                }
                else
                {
                    for (i = 0; i < temp->x; i++)
                    {
                        cout << "Please Enter The Medicine ID That You Wish To Buy : ";
                        cin >> temp->menu2[i];
                        cout << "Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
                        out << "Medicine Name : " << temp->medicineName[temp->menu2[i] - 1] << endl;
                        cout << "Count Of The Respective Medicine : ";
                        cin >> temp->quantity[i];
                        out << "Medicine Quantity : " << temp->quantity[i] << endl;
                        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
                        totalPrice = totalPrice + temp->amount[i];
                    }
                    cout << "You've Been Charged With Amount Of Rs. " << totalPrice << ".00" << endl; // Displaying The Total Price Charged
                    out << "Total Price : Rs. " << totalPrice << ".00\n"
                        << endl;
                    out << "==================================\n"
                        << endl;
                    temp = temp->next;
                    system("CLS");
                }
                cout << "Record Modification Successful!" << endl;
                sleep(3);
            }
            else
            {
                if (temp != NULL && temp->recieptNumber != sid)
                {
                    cout << "Invalid Order Number, Kindly Check The Order Number Entered" << endl;
                }
            }
        }
    }
}

// Order List Function
void pharmacyManagementSystem::orderList()
{
    int i, num, num2;
    bool found = false; // Search Variable
    system("cls");
    node *temp;
    temp = start_ptr;
    float totalPrice = 0;

    cout << "Enter the Order Number To Print The Reciept : ";
    cin >> num2;
    cout << "\n";
    cout << "=====================================================" << endl;
    cout << "List Of Orders :\n";
    cout << "=====================================================" << endl;

    if (temp == NULL) // Entered Receipt Number Is Invalid
    {
        cout << "No Such Order Number Found In Our Record!\nKindly Enter The Correct Receipt Number\n\n";
    }
    while (temp != NULL && !found)
    {
        if (temp->recieptNumber == num2)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
        if (found) // Print The Receipt
        {
            cout << "Order Number : " << temp->recieptNumber;
            cout << "\n";
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Order Date : " << temp->date << endl;
            cout << "_____________________________________________________" << endl;
            cout << "=====================================================" << endl;
            cout << "|  Medicine Name  |  	Quantity    |  Total Price  |" << endl;
            cout << "=====================================================" << endl;
            for (i = 0; i < temp->x; i++)
            {
                cout << "|    " << temp->medicineName[temp->menu2[i] - 1] << "     ";
                cout << "|        " << temp->quantity[i] << "        ";
                cout << "|    "
                     << " Rs." << temp->amount[i] << "    |" << endl;
                cout << "_____________________________________________________" << endl;
                totalPrice = totalPrice + temp->amount[i];
            }
            cout << "Total Bill : "
                 << " Rs." << totalPrice << ".00" << endl; // Displaying The Total Bill
            cout << "\n";
        b:
            cout << "Type In The Amount To Be Payed : ";
            cin >> num;
            if (num < totalPrice)
            {
                cout << "Kindly Pay The Prescribed Amount!\n"
                     << endl;
                goto b;
            }
            else if (num > totalPrice)
            {
                cout << "_____________________________________________________\n";
                cout << "Payment Done Successfully!" << endl;
                cout << "Here's Your Change Of Rs. " << num - totalPrice << ".00" << endl;
                cout << "Thank You" << endl;
            }
            else
            {
                cout << "Payment Done Successfully!\nThank You\n";
                cout << "_____________________________________________________\n";
            }
        }
    }
    system("PAUSE");
    system("CLS");
}

// Daily Summary Function
void pharmacyManagementSystem::dailySummary()
{
    int i, num;
    system("CLS");
    node *temp;
    temp = start_ptr;
    float totalPrice = 0;

    if (temp == NULL) // Invalid Receipt Code
    {
        cout << "No Orders To Show!\n"
             << endl;
    }
    else
    {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Daily Summary Of All Orders \n"; // Print All Transactions Occurred
        cout << "=====================================================" << endl;

        while (temp != NULL)
        {
            cout << "Order Number : " << temp->recieptNumber;
            cout << "\n";
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Order Date : " << temp->date << endl;
            cout << "_____________________________________________________" << endl;
            cout << "=====================================================" << endl;
            cout << "|  Medicine Name  |  	Quantity    |  Total Price  |" << endl;
            cout << "=====================================================" << endl;
            for (i = 0; i < temp->x; i++)
            {
                cout << "|    " << temp->medicineName[temp->menu2[i] - 1] << "     ";
                cout << "|        " << temp->quantity[i] << "        ";
                cout << "|    "
                     << " Rs." << temp->amount[i] << "    |" << endl;
                cout << "_____________________________________________________" << endl;
                totalPrice = totalPrice + temp->amount[i];
            }
            cout << "Total Bill : "
                 << " Rs." << totalPrice << ".00" << endl; // Displaying The Total Bill
            cout << "_____________________________________________________\n";

            temp = temp->next;
        }
    }
    system("PAUSE");
    system("CLS");
}

// Display Medicine Function
void pharmacyManagementSystem::displayMedicine()
{
    system("CLS");
    cout << "=====================================================" << endl;
    cout << "Medicines In Stock \n"; // Print All Medicines In Stock
    cout << "=====================================================" << endl;
    string takeOrderText;
    ifstream in("takeOrder.txt");
    for (int i = 0; i < 14; i++)
    {
        getline(in, takeOrderText);
        cout << takeOrderText << endl;
    }
    cout << "" << endl;
    system("PAUSE");
    system("CLS");
}

// Display Back-Up Customer Details
void pharmacyManagementSystem::displayCustomers()
{
    system("CLS");
    cout << "=====================================================" << endl;
    cout << "Back-Up Customer Details \n"; // Print All Transactions Occurred
    cout << "=====================================================" << endl;
    string takeCustomerInfo;
    ifstream in("takeCustomerInfo.txt");
    while (!in.eof())
    {
        getline(in, takeCustomerInfo);
        cout << takeCustomerInfo << endl;
    }
    system("PAUSE");
    system("CLS");
}

// Exit Function
void pharmacyManagementSystem::exit()
{
    cout << "\nYou Chose To Exit" << endl;
    cout << "Thank You So Much!\n"
         << endl;
    system("PAUSE");
}

void delay(int milliseconds)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
        ;
}

// Admin/Customer Selection
void pharmacyManagementSystem::userSelection()
{
    string userName, passWord = "";
    int choice;
    int L_PER_INCR = 2;
    do
    {
        cout << "\n\t    PHARMACY MANAGEMENT SYSTEM USING PRIMARY AND SECONDARY INDEXING \n";
        cout << "\t======================================================================\n\n";
        cout << "\t----------------------------------------------------------------------\n";
        cout << "\t||\t\t\t1. Admin \t\t\t\t||\n";
        cout << "\t||\t\t\t2. Customer \t\t\t\t||\n";
        cout << "\t||\t\t\t3. Exit \t\t\t\t||\n";
        cout << "\t----------------------------------------------------------------------\n";
        cout << "\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter The Username : ";
            cin.ignore();
            getline(cin, userName);
            cin.ignore();
            cout << "Enter The Password : ";
            getline(cin, passWord);
            if (!(strcmp((userName.c_str()), ("Harshith"))) && (passWord == "12345") )
            {
                cout << "\n******************Access Granted******************\n"
                     << endl;
                sleep(2);
                system("CLS");
                mainMenu(); // Calling Of Main Menu To Run
            }
            else
            {
                cout << "\n******************Access Denied*******************\n\n";
                system("PAUSE");
                system("CLS");
            }
            break;
        }

        case 2:
        {
            system("CLS");
            int c;
             
            do
            {
                cout << "\n\t    PHARMACY MANAGEMENT SYSTEM USING PRIMARY AND SECONDARY INDEXING \n";
                cout << "\t=======================================================================\n\n";
                cout << "\t-----------------------------------------------------------------------\n";
                cout << "\t||\t\t\t1. Search For The Medicine   \t\t\t||\n";
                cout << "\t||\t\t\t2. Display Available Medicine      \t\t||\n";
                cout << "\t||\t\t\t3. Exit     \t\t\t\t\t||\n";
                cout << "\t-----------------------------------------------------------------------\n";
                cout << "\t\t\tEnter Your Choice: ";
                cin >> c;
                switch (c)
                {
                case 1:
                {
                    search();
                    break;
                }
                case 2:
                {
                    displayMedicine();
                    break;
                }
                case 3:
                {
                    exit();
                    system("CLS");
                    break;
                }

                default:
                {
                    cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                         << endl;
                    break;
                }
                }
            } while (c != 3);
            break;
        }
        case 3:
        {
            exit();
            break;
        }
        default:
        {
            cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                 << endl;
            break;
        }
        }
    } while (choice != 3);
}



// Main Function
int main(void)
{
    system("CLS");
    system("COLOR 3F");
    //20 or 02
    pharmacyManagementSystem pharmacyManagementSystemObj;
    cout<<"\n     PHARMACY MANAGEMENT SYSTEM USING PRIMARY AND SECONDARY INDEXING\n";
    cout<<"=========================================================================\n\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"||\t\t\tFile Structure Mini Project\t\t\t||\n";
    cout<<"||\t\t\tBy : \t\t\t\t\t\t||\n";
    cout<<"||\t\t\tHarshith V             \t\t\t\t||\n";
    cout<<"-------------------------------------------------------------------------\n";
    sleep(3);
    system("CLS");
    pharmacyManagementSystemObj.userSelection(); // Calling User Selection Page To Run
    return 0;
}
/***************************************END OF PROGRAM***************************************/
