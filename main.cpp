#include <iostream>
#include <string>
#include "List.h"
#include "stack.h"
#include "queue.h"
using namespace std;
//**************************
string borrowered;
int indx, er_ad,ind = 0;
static int ID = 4;//index
//**************************
//base class:
class Library
{
protected:
    string  Library_ID, Name;
public:
    Library();
    void set_Library_ID();
    void set_Name();
    string get_Library_ID();
    string get_Name();
};
class subscriber
{
protected:
    List<string> type; List<string> name; List<string>address; List<string> phone; List<string> email; List<string> borrowed_items;
    List<int> time; List<int> fee; List<int> id;

public:
    subscriber();
    long int conv_str_int(int n_id, string ID);
    void print(int i);
    void search();
    void edit();
    void add();
    void borrow(int err_book);
    int return_borrowed_item(int t);
    void payment();
    void _delete(int del_ret_b, int index);
    void print_reports();

};
class contents
{
protected:
    List<long int> Item_ID, Production_Year;
    List<string> Category, Author, Publisher, Status;
public:
    List<string> Title;
    List<long int>  Copies;
    contents();
    long int conv_str_int(int tc, string ID);
   // void print_sections();
    void edit();
    void _delete(int dele, int j);
    void search();
    void add(int old_book);
};

//outside class Library:
//*************************************************************
Library::Library()
{
    Library_ID = "0";
    Name = "0";
}
void Library::set_Library_ID()
{
    cout << "please enter islam : ";//<< endl;
true_id:
    getline(cin, Library_ID);
    system("color E");
    if (Library_ID != "islam")
    {
        system("color 04");
        cout << "Error==> please enter a true Library_ID:" << endl;
        goto true_id;
    }
}
void Library::set_Name()
{
    Name = "Fayoum University Library";
}
string Library::get_Library_ID()
{
    return Library_ID;
}
string Library::get_Name()
{
    return Name;
}
//*************************************************************
//outside class subscriber:
//*************************************************************
subscriber::subscriber()
{
    id.InsertNode(0, 1); type.InsertNode(0, "golden");  name.InsertNode(0, "ayman"); address.InsertNode(0, "cairo"); phone.InsertNode(0, "01069807034"); email.InsertNode(0, "am5432@fayoum.edu.eg");
    id.InsertNode(1, 2); type.InsertNode(1, "normal");  name.InsertNode(1, "youssef"); address.InsertNode(1, "cairo"); phone.InsertNode(1, "01012345278");  email.InsertNode(1, "yf1234@fayoum.edu.eg");
    id.InsertNode(2, 3); type.InsertNode(2, "golden");  name.InsertNode(2, "islam atef"); address.InsertNode(2, "Giza"); phone.InsertNode(2, "01014785236"); email.InsertNode(2, "is1234@fayoum.edu.eg");
    id.InsertNode(3, 4); type.InsertNode(3, "normal");  name.InsertNode(3, "hamada"); address.InsertNode(3, "octobar"); phone.InsertNode(3, "01015879214"); email.InsertNode(3, "hm1234@fayoum.edu.eg");
    id.InsertNode(4, 5); type.InsertNode(4, "golden");  name.InsertNode(4, "mostafa"); address.InsertNode(4, "fayoum"); phone.InsertNode(4, "01015794325"); email.InsertNode(4, "mm1234@fayoum.edu.eg");
}
long int subscriber::conv_str_int(int n_id, string ID)
{
a:
    string str = "0"; long int int_var = 0;
    long int y[10] = { 0 }, b = 0, j = 0;

    int_var = 0;
    if (n_id == 1)
    {
        str = ID;
        if (str.length() > 3)
        {
            b = 2;
        }
    }
    else
    {
        getline(cin, str);
    }
    system("color E");
    if (b != 2)
    {
        j = str.length() - 1;
        for (int s = 0; s < str.length(); s++)
        {
            y[s] = str[j];

            if (y[s] < 48 || y[s]>57)
            {
                b = 1;
            }
            else
            {
                y[s] = y[s] - 48;
            }
            j--;
        }
        int malt = 1;
        if (b == 1 || str.length() > 10)
        {
            if (n_id != 1)
            {
                system("color 04");
                cout << "Error==>please enter a true time:" << endl;
                goto a;
            }
        }
        if (b != 1)
        {
            for (int s = 0; s < str.length(); s++)
            {
                y[s] = y[s] * malt;
                malt = malt * 10;
                int_var += y[s];
            }
        }
    }
    return int_var;
}
void subscriber::print(int i)
{
    cout << "|-------------------------------------------------------------------|" << endl
        << "| ID        \t\t\t | " << id.search(i,0) << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| type      \t\t\t | " << type.search(i, "0") << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| name      \t\t\t | " << name.search(i, "0") << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| address   \t\t\t | " << address.search(i, "0") << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| phone     \t\t\t | " << phone.search(i, "0") << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| email     \t\t\t | " << email.search(i, "0") << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| borrowered_items  \t\t | " << borrowed_items.search(i, "0") << endl
        << "|-------------------------------------------------------------------|" << endl;
    cout << "| the total borrowered time is:\t | " << time.search(i,0) << " days" << endl
        << "|-------------------------------------------------------------------|" << endl;
    //********************************************************************************************
    if (type.search(i, "0") == "normal")
    {
        //three weeks:
        if (time.search(i,0) > 21)
        {
            cout << "| The delay period:\t\t | '" << time.search(i,0) - 21 << "' days" << endl
                << "|-------------------------------------------------------------------|" << endl;
        }
        else
        {
            cout << "| The delay period:\t\t | " << "<There is no delay>" << endl
                << "|-------------------------------------------------------------------|" << endl;
        }
    }
    else if (type.search(i, "0") == "golden")
    {
        //three months:
        if (time.search(i,0) > 90)
        {
            cout << "| The delay period:\t\t | '" << time.search(i,0) - 90 << "' days" << endl
                << "|-------------------------------------------------------------------|" << endl;
        }
        else
        {
            cout << "| The delay period:\t\t | " << "<There is no delay>" << endl
                << "|-------------------------------------------------------------------|" << endl;
        }
    }
    //********************************************************************************************
    cout << "| the total fee:\t\t | " << fee.search(i,0) << " Pounds" << endl
        << "|-------------------------------------------------------------------|" << endl;
    cout << "|*******************************************************************|" << endl << endl;
}
void subscriber::search()
{
    int search_sub = 0; string choose2 = "0"; long int check_id = 0;
new_e:
    cout << "Please enter the (ID,name,phone,email) of the subscriber you are search: " << endl;
Error_search:
    int error = 0;
    cin >> search_sub;
    system("color E");
    print(search_sub);
 
    //***********************************if you want to search other subscriber:*****************************************
    cout << "if you want to search other subscriber:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
err:
    cin >> choose2;
    system("color E");
    //***********************************yes**********************************
    if (choose2 == "1")
    {
        goto new_e;
    }
    //***********************************no**********************************
    else if (choose2 == "2")
    {
        cout << "its don" << endl;
    }
    //***********************************error**********************************
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto err;
    }
}
void subscriber::edit()
{
new_sub:
    string  choose, new_edit; string choose2 = "0", choose3 = "0"; int error = 0; long int check_id = 0; string edit_sub = "0", x1, x2, x3, x4, x5;
    cout << "Please enter the (ID,name,phone,email) of the subscriber you are editing:" << endl;
Error_search:
    error = 0;
    cin >> edit_sub;
    //small letters:
    for (int j = 0; j < edit_sub.length(); j++)
    {
        edit_sub[j] = tolower(edit_sub[j]);
    }
    system("color E");
    check_id = conv_str_int(1, edit_sub);
    for (int i = 0; i < ID; i++)
    {
        //**********************************check ID/name/phone/email******************************************************
        if (id.search(i,0) == check_id || !name.search(i, "0").compare(edit_sub) || !phone.search(i, "0").compare(edit_sub) || !email.search(i, "0").compare(edit_sub))
        {
            if (id.search(i,0) != 0)
            {
                choose = "6";
            new_ee:
                cout << "What do you need to edit in this subscriber" << endl;
                cout << "1-type" << endl;
                cout << "2-name" << endl;
                cout << "3-address" << endl;
                cout << "4-phone" << endl;
                cout << "5-email" << endl;
            try_again1:
                cin >> choose;
                system("color E");
                //*******************edit type:*******************************
                if (choose == "1")
                {
                    cout << "please enter the new type" << endl;
                try_again2:
                    cin >> x1;
                    type.InsertNode(i, x1);
                    system("color E");
                    if (type.search(i, "0") != "normal" && type.search(i, "0") != "golden")
                    {
                        system("color 04");
                        cout << "Error ==> Please enter a true type==>ex( Normal or Golden)" << endl;
                        goto try_again2;
                    }
                }
                //*******************edit name:*******************************
                else if (choose == "2")
                {
                    cout << "please enter the new name" << endl;
                    cin >> x2;
                    name.InsertNode(i, x2);
                }
                //*******************edit address:****************************
                else if (choose == "3")
                {
                    cout << "please enter the new address" << endl;
                    cin >> x3;
                    address.InsertNode(i, x3);
                }
                //*******************edit phone:******************************
                else if (choose == "4")
                {
                    cout << "please enter the new phone" << endl;
                error_phone:
                    cin >> x4;
                    phone.InsertNode(i, x4);
                    system("color E");
                    if ((!phone.search(i, "0").compare(0, 3, "010") || !phone.search(i, "0").compare(0, 3, "011") || !phone.search(i, "0").compare(0, 3, "012") || !phone.search(i, "0").compare(0, 3, "015")) && phone.search(i, "0").length() == 11)
                    {

                    }
                    else
                    {
                        system("color 04");
                        cout << "Error==> please enter a true phone start(010/011/012/015)and length=11" << endl;
                        goto error_phone;
                    }
                }
                //*******************edit email:******************************
                else if (choose == "5")
                {
                    cout << "please enter the new email" << endl;
                err_email:
                    cin >> x5;
                    email.InsertNode(i, x5);
                    system("color E");
                    if (email.search(i, "0").length() > 14)
                    {
                        if (!email.search(i, "0").compare(email.search(i, "0").length() - 14, email.search(i, "0").length(), "@fayoum.edu.eg"))
                        {

                        }
                        else
                        {
                            system("color 04");
                            cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                            goto err_email;
                        }
                    }
                    else
                    {
                        system("color 04");
                        cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                        goto err_email;
                    }
                }
                //*******************Error:***********************************
                else
                {
                    system("color 04");
                    cout << "Error ==> try again enter 1 or 2 or 3 or 4 or 5 or 6 or 7" << endl;
                    goto try_again1;
                }
                //*******************if you want to edit anything other in this subscriber:***************************
                cout << "if you want to edit anything other in this subscriber:" << endl;
                cout << "1-yes" << endl;
                cout << "2-no" << endl;
            err:
                cin >> choose2;
                system("color E");
                //************************yes*******************************
                if (choose2 == "1")
                {
                    goto new_ee;
                }
                //************************no********************************
                else if (choose2 == "2")
                {
                    cout << "its don" << endl;
                    break;
                }
                //************************error*****************************
                else
                {
                    system("color 04");
                    cout << "Error ==>please enter a true choose:" << endl;
                    goto err;
                }
            }
            else
            {
                error++;
            }
        }
        //**********************************check error*****************************************************************
        else
        {
            error++;
        }

    }
    //**********************************error***********************************************************************
    if (error == 50)
    {
        system("color 04");
        cout << "Error ==>  result not found try again" << endl;
        goto Error_search;
    }
    //************************if you want to edit other subscriber:*************************************************
    cout << "if you want to edit other subscriber:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
error_e:
    getline(cin, choose3);
    system("color E");
    if (choose3 == "1")
    {
        goto new_sub;
    }
    else if (choose3 == "2")
    {
        cout << "its don" << endl;
    }
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto error_e;
    }
}
void subscriber::add()
{
new_add:
    int v = 0; string choose2 = "0", x1, x2, x3, x4, x5; int index = 0;
   // static int ID = 4;//index
    static int i = 5;//id
    i++;
    ID++;
    {
        //**********************************************Search for an empty place in the storage space**********************************************
        {
            //***************************ID:*******************************************
           id.InsertNode(ID, i); index = i;
            //***************************type:*****************************************
            cout << "enter the type:" << endl;
        try_again1:
            cin >> x1;
            type.InsertNode(ID, x1);
            system("color E");
            if (type.search(i, "0") != "normal" && type.search(i, "0") != "golden")
            {
                system("color 04");
                cout << "Error ==> Please enter a true type==>ex( Normal or Golden)" << endl;
                goto try_again1;
            }
            //***************************name:******************************************
            cout << "enter the name:" << endl;
            cin >> x2;
            name.InsertNode(ID, x2);
            //***************************address:***************************************
            cout << "enter address:" << endl;
            cin >> x3;
            address.InsertNode(ID, x3);
            //***************************phone:*****************************************
            cout << "enter phone:" << endl;
        error_phone:
            cin >> x4;
            phone.InsertNode(ID, x4);
            system("color E");
            if ((!phone.search(i, "0").compare(0, 3, "010") || !phone.search(i, "0").compare(0, 3, "011") || !phone.search(i, "0").compare(0, 3, "012") || !phone.search(i, "0").compare(0, 3, "015")) && phone.search(i, "0").length() == 11)
            {

            }
            else
            {
                system("color 04");
                cout << "Error==> please enter a true phone start(010/011/012/015)and length=11" << endl;
                goto error_phone;
            }
            //***************************email:*****************************************
            cout << "enter email:" << endl;
        err_email:
            cin >> x5;
            email.InsertNode(ID, x5);
            system("color E");
            if (email.search(i, "0").length() > 14)
            {
                if (!email.search(i, "0").compare(email.search(i, "0").length() - 14, email.search(i, "0").length(), "@fayoum.edu.eg"))
                {

                }
                else
                {
                    system("color 04");
                    cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                    goto err_email;
                }
            }
            else
            {
                system("color 04");
                cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                goto err_email;
            }
            // break;
        }
       
    }
    ////***************************error:************************************
    
    for (int j = 0; j < index; j++)
    {
        if (!type.search(index, "0").compare(type.search(j, "0")) && !name.search(index, "0").compare(name.search(j, "0")) && !address.search(index, "0").compare(address.search(j, "0")) && !phone.search(index, "0").compare(phone.search(j, "0")) && !email.search(index, "0").compare(email.search(j, "0")))
        {
            cout << endl;
            cout << "\tThis data is already there" << endl << endl;
            id.DeleteNode(id.search(j, 0));
            type.DeleteNode(type.search(j, "0"));
            name.DeleteNode(name.search(j, "0"));
            address.DeleteNode(address.search(j, "0"));
            phone.DeleteNode(phone.search(j, "0"));
            email.DeleteNode(email.search(j, "0"));
        }
    }
    cout << "if you want to add other subscriber:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
err:
    cin>> choose2;
    system("color E");
    if (choose2 == "1")
    {
        goto new_add;
    }
    else if (choose2 == "2")
    {
        cout << "its don" << endl;
    }
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto err;
    }
    //***************************************************************
}

void subscriber::borrow(int err_book)
{
    int id_sub=0; int error_name = 0; string x1;
err_book_i:
    if (err_book != 1)
    {
        cout << "Please enter ID of the subscriber who wants to borrow the book" << endl;
        cin >> id_sub;
        system("color E");
    }

    for (int i = 0; i < ID; i++)
    {
        if (id.search(i, 0)== id.search(id_sub, 0) || err_book == 1)
        {
            if (err_book == 1)
            {
                borrowed_items.search(i, "0") = "0";
            }
            if (borrowed_items.search(i, "0") == "0")
            {
                cout << "Name borrowed book:" << endl;
                cin >> x1;
                   borrowed_items.InsertNode(i,x1);
                system("color E");
                borrowered = borrowed_items.search(i, "0");
                break;
            }
            else
            {
                cout << endl;
                cout << "You have borrowed a book before, you must return it first" << endl << endl;
                break;
            }
        }
        else
        {
            error_name++;
        }

    }
    if (error_name == ID && err_book != 1)
    {
        system("color 04");
        cout << "Error==>This name not found try again:" << endl;
        error_name = 0;
        goto err_book_i;
    }
    err_book = 0;
}

int subscriber::return_borrowed_item(int t) { return 0; }
void subscriber::payment() {}
void subscriber::_delete(int del_ret_b, int index) {}
void subscriber::print_reports() {}

contents::contents()
{

}
long int contents::conv_str_int(int tc, string ID)
{
    long int int_var = 0;
a:
    int_var = 0;
    string str = "0";
    long int y[4] = { 0 }, b = 0, j = 0;
    if (tc != 3)
    {
        getline(cin, str);
    }
    if (tc == 3)
    {
        str = ID;
        if (str.length() > 3)
        {
            b = 2;
        }

    }
    system("color E");
    if (b != 2)
    {
        if (str.length() > 4)
        {
            system("color 04");
            cout << "Error==> please enter a true value(int & 4 bit):" << endl;
            goto a;
        }
        j = str.length() - 1;
        for (int s = 0; s < str.length(); s++)
        {
            y[s] = str[j];

            if (y[s] < 48 || y[s]>57)
            {
                b = 1;
            }
            else
            {
                y[s] = y[s] - 48;
            }
            j--;
        }
        int malt = 1;
        if (b == 1)
        {
            system("color 04");
            cout << "Error==> please enter a true value(int & 4 bit):" << endl;
            goto a;
        }
        for (int s = 0; s < str.length(); s++)
        {
            y[s] = y[s] * malt;

            malt = malt * 10;
            int_var += y[s];
        }

        if (tc == 1)
        {
            if (int_var > 2021)
            {
                system("color 04");
                cout << "Error==>please enter a true value(int & 4 bit):" << endl;
                goto a;
            }
        }
        if (tc == 2)
        {
            if (int_var > 50)
            {
                system("color 04");
                cout << "Error==>please enter a true value(int & 4 bit):" << endl;
                goto a;
            }
        }
    }
    return int_var;
}

void contents::edit()
{
t_again2:
    int v = 0; long int id = 0;
    string choose = "0", new_edit = "0", choose2 = "0", edit_book = "0", choose3 = "0"; string x1, x2, x3, x4, x5; int z = 0;
    cout << "Please enter the ID of the book you are edit" << endl;
    cin>> edit_book;
    system("color E");
    id = conv_str_int(3, edit_book);
            new_e:
                cout << "What do you need to edit in this book" << endl;
                cout << "1-Category" << endl;
                cout << "2-title" << endl;
                cout << "3-auther" << endl;
                cout << "4-publisher" << endl;
                cout << "5-production Year" << endl;
                cout << "6-status" << endl;
            try_again1:
                cin >> choose;
                system("color E");
                //*********************Category*******************************
                if (choose == "1")
                {
                    cout << "please enter the new Category" << endl;
                err_cat:
                    cin >> x1;
                    Category.edit(id,x1);
                    system("color E");
                    if (!Category.search(id, "0").compare("book") || !Category.search(id, "0").compare("article_in_a_journal") || !Category.search(id, "0").compare("digital_media"))
                    {

                    }
                    else
                    {
                        system("color 04");
                        cout << "Error==> Please enter a true Category:(book,article_in_a_journal,digital_media):" << endl;
                        goto err_cat;
                    }
                }
                //*********************title**********************************
                else if (choose == "2")
                {
                    cout << "please enter the new title" << endl;
                    cin >> x2;
                    Title.edit(id, x2);
                }
                //*********************auther*********************************
                else if (choose == "3")
                {
                    cout << "please enter the new auther" << endl;
                    cin >> x3;
                        Author.edit(id,x3);
                }
                //*********************publisher******************************
                else if (choose == "4")
                {
                    cout << "please enter the new publisher" << endl;
                    cin >> x4;
                    Publisher.edit(id,x4);
                }
                //*********************production Year************************
                else if (choose == "5")
                {
                    cout << "please enter the new production Year" << endl;
                    cin >> z;
                    Production_Year.edit(id,z) ;
                }
                //*********************status*********************************
                else if (choose == "6")
                {
                    cout << "please enter the new status" << endl;
                err_st:
                    cin >> x5;
                       Status.edit(id,x5);
                    system("color e");
                    if (Status.search(id, "0") != "on shelf" || Status.search(id, "0") != "on the site")
                    {
                        system("color 04");
                        cout << "Error==> Please enter a true Status ex:(on shelf,on the site)" << endl;
                        goto err_st;
                    }
                }
                //*********************error**********************************
                else
                {
                    system("color 04");
                    cout << "Error ==> try again enter 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 " << endl;
                    goto try_again1;
                }
              
    //***************************if you want to edit other book:***************************
    cout << "if you want to edit other book:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
error:
    cin >> choose3;
    system("color E");
    //***************************yes*************************
    if (choose3 == "1")
    {
        goto  t_again2;
    }
    //***************************no**************************
    else if (choose3 == "2")
    {
        cout << "its don" << endl;
    }
    //***************************error***********************
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto error;
    }
}
void contents::_delete(int dele, int j)
{
    //*******************(delete book if copies=0)**********************
    if (dele == 1)
    {
        Item_ID.DeleteNode(j);
        Category.DeleteNode(Category.search(j,"0"));
        Title.DeleteNode(Category.search(j, "0"));
        Author.DeleteNode(Category.search(j, "0"));
        Publisher.DeleteNode(Category.search(j, "0"));
        Production_Year.DeleteNode(j);
        Status.DeleteNode(Category.search(j, "0"));
        Copies.DeleteNode(j);
    }

    if (dele != 1)
    {
    new_e:
        string delete_book = "0";  int xx = 0; string choose2 = "0"; long int id = 0;
        cout << "Please enter the ID of the book you are delete" << endl;
    t_again:
        cin>>delete_book;
        system("color E");
        id = conv_str_int(3, delete_book);
                if (Item_ID.search(id,0) != 0)
                {
                    Item_ID.DeleteNode(id);
                    Category.DeleteNode(Category.search(id, "0"));
                    Title.DeleteNode(Category.search(id, "0"));
                    Author.DeleteNode(Category.search(id, "0"));
                    Publisher.DeleteNode(Category.search(id, "0"));
                    Production_Year.DeleteNode(id);
                    Status.DeleteNode(Category.search(id, "0"));
                    Copies.DeleteNode(id);
                    xx = 1;
                }
        //*****************************************error******************************************************************
        if (xx == 0)
        {
            system("color 04");
            cout << "Error ==>This name not found try again" << endl;
            goto t_again;
        }
        xx = 0;
        //*****************************************if you want to delete other book:**************************************
        cout << "if you want to delete other book:" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
    err:
       cin>>choose2;
        system("color E");
        //*****************************yes*******************************
        if (choose2 == "1")
        {
            goto new_e;
        }
        //*****************************no********************************
        else if (choose2 == "2")
        {
            cout << "its don" << endl;
        }
        //*****************************error*****************************
        else
        {
            system("color 04");
            cout << "Error ==>please enter a true choose:" << endl;
            goto err;
        }
    }
}
void contents::search()
{
new_e:
    int General_search = 0; string choose2 = "0"; long int id = 0;
    int xx = 0;
    cout << "Please enter the ID of the book you are search: " << endl;
error_search:
    cin>> General_search;
    system("color E");
            if (Item_ID.search(id, 0) != 0)
            {
                cout << endl;
                cout << "Item_ID         ==> " << Item_ID.Displayitem(id) << endl;
                cout << "Category        ==> " << Category.Displayitem(id) << endl;
                cout << "Title           ==> " << Title.Displayitem(id) << endl;
                cout << "Author          ==> " << Author.Displayitem(id) << endl;
                cout << "Publisher       ==> " << Publisher.Displayitem(id) << endl;
                cout << "Production_Year ==> " << Production_Year.Displayitem(id) << endl;
                cout << "Status          ==> " << Status.Displayitem(id) << endl;
                cout << "Copies          ==> " << Copies.Displayitem(id) << endl << endl;
                xx = 1;
            }

    //******************************************error******************************************************************
    if (xx == 0)
    {
        system("color 04");
        cout << "Error ==> Search result not found try again" << endl;
        goto error_search;
    }
}
void contents::add(int old_book)
{
new_e:
    int v = 0; string  choose2 = "0"; string x1, x2, x3, x4, x5;int xx;
    if (old_book == 0)
    {
                //***********************************ID*************************************
                Item_ID.InsertNode(ind, (ind + 1)) ; indx = ind;
                //***********************************Category*******************************
                cout << "enter the Category:" << endl;
            err_cat:
                cin >> x1;
                   Category.InsertNode(ind, x1);
                system("color E");
                if (!Category.search(ind, "0").compare("book") || !Category.search(ind, "0").compare("article in a journal") || !Category.search(ind, "0").compare("digital media"))
                {

                }
                else
                {
                    system("color 04");
                    cout << "Error==> Please enter a true Category:(book,article in a journal,digital media):" << endl;
                    goto err_cat;
                }
                //************************************title*********************************
                cout << "enter the title:" << endl;
                cin >> x2;
                Title.InsertNode(ind, x2);
                //************************************auther*********************************
                cout << "enter the auther:" << endl;
                cin >> x3;
                    Author.InsertNode(ind, x3);
                //************************************publisher******************************
                cout << "enter the publisher:" << endl;
                cin >> x4;
                Publisher.InsertNode(ind,x4);
                //************************************Production Year************************
                cout << "enter the Production Year:" << endl;
                cin >> xx;
                Production_Year.InsertNode(ind,xx);
                //************************************status*********************************
                cout << "enter the status:" << endl;
            err_st:
                cin >> x5;
                Status.InsertNode(ind,x5);
                //************************************copies*********************************
               // cout << "enter the copies:" << endl;
                Copies.InsertNode(ind,1);
                ind++;
    }
    if (old_book == 1)
    {
        //************************************if you want to add other book:**********
        cout << "if you want to add other book:" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
    err:
        cin>> choose2;
        system("color E");
        //*******************yes****************************
        if (choose2 == "1")
        {
            old_book = 0;
            er_ad = 1;
            goto new_e;
        }
        //*******************no*****************************
        else if (choose2 == "2")
        {
            er_ad = 0;
            cout << "its don" << endl;
        }
        //*******************error**************************
        else
        {
            system("color 04");
            cout << "Error ==>please enter a true choose:" << endl;
            goto err;
        }
    }
}
int main()
{
    //*******************************************
    Library ob_l;
    //*******************************************
    subscriber ob_s;
    string choose_s;
    //*******************************************
    contents ob;
    List<string> ob_l_s;
    //*******************************************
    string choose = "0", section1 = "0";
    //*******************************************
                  //interface project:
//**********************************************************************************************
    cout << "      *****welcome*****" << endl;
    cout << "**program of Library Management System**" << endl;
    //interface Library:
    ob_l.set_Library_ID();
    ob_l.set_Name();
    cout << endl;
    cout << "*******************************************************" << endl;
    cout << "Library ID: " << ob_l.get_Library_ID() << "\t";
    cout << "Name: " << ob_l.get_Name() << endl;
    cout << "*******************************************************" << endl << endl;
    //********************************************
again_end:
    cout << "1-Subscribers section:" << endl;
    cout << "2-Books section:" << endl;
    cout << "please enter choose (1 or 2):" << endl;
ERR:
    cin>>section1;
    system("color E");
    //interface subscriber:
//******************************************************************************************
    if (section1 == "1")
    {
    new_operation_s:
        cout << "1-Search:" << endl;
        cout << "2-Edit:" << endl;
        cout << "3-Add:" << endl;
        cout << "4-Delete:" << endl;
        cout << "5-Borrow items:" << endl;
        cout << "6-Return borrowed item:" << endl;
        cout << "7-Payment:" << endl;
        cout << "8-If you want print reports of overdue borrowed items:" << endl;
    error_s:
        cin>>choose_s;
        system("color E");
        //***********************search:*************************
        if (choose_s == "1")
        {
            ob_s.search();
        }
        //***********************edit****************************
        else if (choose_s == "2")
        {
            ob_s.edit();

        }
        //***********************add*******************
        else if (choose_s == "3")
        {
            ob_s.add();

        }
        //***********************delete**************************
        else if (choose_s == "4")
        {
            ob_s._delete(0, 0);
        }
        //***********************borrowed************************
        else if (choose_s == "5")
        {
            ob_s.borrow(0);
            z:
            if (ob_l_s.FindNode(borrowered))
            {
                ob_s.borrow(0);
            }
            else
            {
                cout << "error:this book not found" << endl;
                ob_s.borrow(1);
                goto z;
            }
        }
        //***********************return_borrowed_item************
        else if (choose_s == "6")
        {

        }
        //************************payment*************************
        else if (choose_s == "7")
        {
            ob_s.payment();
        }
        //***********************print reports*******************
        else if (choose_s == "8")
        {
            ob_s.print_reports();
        }
        //***********************error***************************
        else
        {
            system("color 04");
            cout << "Error==> please enter a true choose:" << endl;
            goto error_s;
        }
        string x, y;
        //***********************Do you want to go to the list of subscribers section?******************
        cout << "Do you want to go to the list of subscribers section?" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
        cout << "please enter 1 or 2" << endl;
    right_choice_s:
        getline(cin, x);
        system("color E");
        //*****************yes***************************************
        if (x == "1")
        {
            //*****************************Do you want to clear the screen?**************************
            cout << "Do you want to clear the screen?" << endl;
            cout << "1-yes" << endl;
            cout << "2-no" << endl;
            cout << "please enter 1 or 2" << endl;
        right_ch_1:
            getline(cin, y);
            system("color E");
            //*****************yes***************************************
            if (y == "1")
            {
                system("cls");
                goto new_operation_s;
            }
            //*****************no****************************************
            else if (y == "2")
            {
                goto new_operation_s;
            }
            //*****************error*************************************
            else
            {
                system("color 04");
                cout << "Error==> please enter the right choice:" << endl;
                goto right_ch_1;
            }
        }
        //*****************error*************************************
        else if (x != "2")
        {
            system("color 04");
            cout << "Error==> please enter a true choose" << endl;
            goto right_choice_s;
        }

    }
    //interface contents:
//*********************************************************************************************
    else if (section1 == "2")
    {
    again:
        cout << "Please enter the operation number you want to perform:" << endl;
        cout << "1-searsh" << endl;
        cout << "2-delete" << endl;
        cout << "3-edite" << endl;
        cout << "4-add" << endl;
    try_again:
        cin>>choose;
        system("color E");
        //*****************searsh:*****************************************
        if (choose == "1")
        {
            ob.search();
        }
        //*****************delete:*****************************************
        else if (choose == "2")
        {
            ob._delete(0, 0);
        }
        //*****************edite:******************************************
        else if (choose == "3")
        {
                ob.edit();
        }
        //*****************add:********************************************
        else if (choose == "4")
        {
            ob.add(0);
        }
        //*****************Do you want to do another operation?***********************
        string x, n;
        cout << "Do you want to do another operation?" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
        cout << "please enter 1 or 2" << endl;
    right_choice:
        cin>> x;
        system("color E");
        //*******************yes*******************************************************
        if (x == "1")
        {
            //*******************Do you want to clear the screen?**************************
            cout << "Do you want to clear the screen?" << endl;
            cout << "1-yes" << endl;
            cout << "2-no" << endl;
            cout << "please enter 1 or 2" << endl;
        right_ch:
            cin>>n;
            system("color E");
            //*******************yes*******************************************************
            if (n == "1")
            {
                system("cls");
                goto again;
            }
            //*******************no********************************************************
            else if (n == "2")
            {
                goto again;
            }
            //*******************error*****************************************************
            else
            {
                system("color 04");
                cout << "Error==> please enter the right choice:" << endl;
                goto right_ch;
            }
        }
        //*******************no********************************************************
        else if (x == "2")
        {
            goto end;
        }
        //*******************error*****************************************************
        else
        {
            system("color 04");
            cout << "Error==> please enter the right choice:" << endl;
            goto right_choice;
        }
    }
    //*******************error*********************************************************************
    else
    {
        system("color 04");
        cout << "Error==> please enter the right choice:" << endl;
        goto ERR;
    }
end:
    //*****************************************************************************************
    //********************Do you want to go to the main menu?**********************************
    string xx, nn;
    cout << "Do you want to go to the main menu?" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
    cout << "please enter 1 or 2" << endl;
right_choice_end:
   cin>> xx;
    system("color E");
    //************************yes***************************************************
    if (xx == "1")
    {
        cout << "Do you want to clear the screen?" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
        cout << "please enter 1 or 2" << endl;
    right_ch_end:
       cin>>nn;
        system("color E");
        //************************yes*************************************************
        if (nn == "1")
        {
            system("cls");
            goto again_end;
        }
        //************************no**************************************************
        else if (nn == "2")
        {
            goto again_end;
        }
        //************************error***********************************************
        else
        {
            system("color 04");
            cout << "Error==> please enter the right choice:" << endl;
            goto right_ch_end;
        }

    }
    //************************no****************************************************
    else if (xx == "2")
    {
        goto end_end;
    }
    //************************error*************************************************
    else
    {
        system("color 04");
        cout << "Error==> please enter the right choice:" << endl;
        goto right_choice_end;
    }
end_end:
    cout << "**********Thanks for using this program*********" << endl;
    return 0;
}



