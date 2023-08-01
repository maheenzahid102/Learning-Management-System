#include<iostream>
#include<string>
#include<string.h>
using namespace std;

//-----------------------------------------------------------------------Structures--------------------------------------------------------------


//---------------Courses-----------------------
struct course
{
    string cname;
    string code;
    int chour;
};

//-------------Faculty---------------------------

struct faculty
{
    char fname[100];
    char fid[50];
    char fpassword[50];
    char fqual[20];
    char fmob[20];
    char faddress[100];
    course* ptr;
};

//------------Student---------------------------

struct student
{
    char sname[100];
    char sid[50];
    char spassword[50];
    char smob[20];
    char saddress[100];
    int courseregister;
    course* stdc;
};

//----------Global Variables------------------------

int n1;
int n2;

//--------------------------------------------------------FUNCTIONS--------------------------------------------------------------------



//-----------------Faculty Input--------------------

void inp_f(faculty f[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl << "------------------------------------------------------------------------------------" << endl;

        cout << "Enter the Faculty Name " << endl;
        cin.ignore();
        cin.getline(f[i].fname, 100);
        cout << "Enter the mobile number " << endl;
        cin >> f[i].fmob;
        cout << "Enter the Qualification " << endl;
        cin.ignore();
        cin.getline(f[i].fqual, 20);
        cout << "Enter the Address of faculty " << endl;
        cin >> f[i].faddress;
        cout << "Enter the USERID for faculty " << endl;
        cin >> f[i].fid;
        cout << "Enter a suitable Password for faculty " << endl;
        cin >> f[i].fpassword;
        cout << endl << "------------------------------------------------------------------------------------" << endl;

        cout << "________________No. of courses assigned to faculty_________________ " << endl;
        cin >> n1;
        f[i].ptr = new course[n1];
        for (int j = 0; j < n1; j++)
        {
            cout << "Enter the name of course" << endl;
            cin >> f[i].ptr[j].cname;
            cout << "Enter the code of the course " << endl;
            cin >> f[i].ptr[j].code;
            cout << "Enter the credit hours of the course " << endl;
            cin >> f[i].ptr[j].chour;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
        }
    }
}



//------------------Student Input-----------------------------------


void inp_std(student s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl << "------------------------------------------------------------------------------------" << endl;
        cout << "Enter the name of Student " << endl;
        cin.ignore();
        cin.getline(s[i].sname, 100);
        cout << "Enter The mobile number of Student " << endl;
        cin >> s[i].smob;
        cout << "Enter the address of Student " << endl;
        cin >> s[i].saddress;
        cout << "Enter the User Id for Student " << endl;
        cin >> s[i].sid;
        cout << "Create a suitable password for Student " << endl;
        cin >> s[i].spassword;
        cout << "_____________Enter How Many Courses he can Read_____________ " << endl;
        cin >> n2;
        s[i].stdc = new course[n2];
        s[i].courseregister = 0;
    }

}

//--------------Update Faculty---------------


void upd_f(faculty f[], int size)
{
    char id[50];
    cout << "Enter the Id of Faculty you want to Update " << endl;
    cin.ignore();
    cin.getline(id, 50);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(f[i].fid, id) == 0)
        {
            cout << "Enter the new Data for Faculty Member " << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "Enter the Faculty Name " << endl;
            cin.ignore();
            cin.getline(f[i].fname, 100);
            cout << "Enter the mobile number " << endl;
            cin >> f[i].fmob;
            cout << "Enter the Qualification " << endl;
            cin.ignore();
            cin.getline(f[i].fqual, 20);
            cout << "Enter the Address of faculty " << endl;
            cin.ignore();
            cin.getline(f[i].faddress, 100);
            cout << "Enter the USERID for faculty " << endl;
            cin >> f[i].fid;
            cout << "Enter a suitable Password for faculty " << endl;
            cin >> f[i].fpassword;
            cout << "___________No. of courses assigned to faculty______________ " << endl;
            cin >> n1;
            f[i].ptr = new course[n1];
            for (int j = 0; j < n1; j++)
            {
                cout << "Enter the name of course" << endl;
                cin >> f[i].ptr[j].cname;
                cout << "Enter the code of the course " << endl;
                cin >> f[i].ptr[j].code;
                cout << "Enter the credit hours of the course " << endl;
                cin >> f[i].ptr[j].chour;
                cout << endl << "------------------------------------------------------------------------------------" << endl;

            }
            break;
        }
        if (i == size)
        {
            cout << "Faculty Does not Found " << endl;
        }

    }
}

//----------------Update Student---------------------------


void upd_std(student s[], int size)
{
    char id[50];
    cout << "Enter the id of student You wanna update " << endl;
    cin.ignore();
    cin.getline(id, 50);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(s[i].sid, id) == 0)
        {
            cout << "Enter New Data For Student " << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "Enter the name of Student " << endl;
            cin.ignore();
            cin.getline(s[i].sname, 100);
            cout << "Enter The mobile number of Student " << endl;
            cin >> s[i].smob;
            cout << "Enter the address of Student " << endl;
            cin >> s[i].saddress;
            cout << "Enter the User Id for Student " << endl;
            cin >> s[i].sid;
            cout << "Create a suitable password for Student " << endl;
            cin >> s[i].spassword;
            cout << "___________Enter How Many Courses he can Read_____________ " << endl;
            cin >> n2;
            s[i].stdc = new course[n2];
            s[i].courseregister = 0;
            if (i == size)
            {
                cout << "Student of this ID Does not Exist." << endl;
            }
        }


    }


}


//----------------Search For Faculty------------------------

void sr_f(faculty f[], int size)
{
    char id[50];
    cout << "Enter the id of faculty you want to search " << endl;
    cin.ignore();
    cin.getline(id, 50);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(f[i].fid, id) == 0)
        {
            cout << "Faculty has Founded " << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "The name of Faculty is " << f[i].fname << endl;
            cout << "The Address of Faculty is " << f[i].faddress << endl;
            cout << "The Mobile number of Faculty is " << f[i].fmob << endl;
            cout << "The Qualification of Faculty is " << f[i].fqual << endl;
            cout << "_____________The Courses Teach By Faculty are_____________ " << endl;
            for (int j = 0; j < n1; j++)
            {
                cout << "Course Title : " << f[i].ptr[j].cname << endl;
                cout << "Course Code : " << f[i].ptr[j].code << endl;
                cout << "Course Credit Hours : " << f[i].ptr[j].chour << endl;
                cout << endl << "------------------------------------------------------------------------------------" << endl;

            }
            break;
        }
        if (i == size)
        {
            cout << "Faculty With this Id Does Not Exist. " << endl;
        }
    }
}


//---------------Student Search-----------------------

void sr_s(student s[], int size)
{
    char id[50];
    cout << "Enter the Id of Student You Want to Search " << endl;
    cin.ignore();
    cin.getline(id, 50);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(s[i].sid, id) == 0)
        {
            cout << "Student has Founded " << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "The Name of Student is " << s[i].sname << endl;
            cout << "The Mobile Number Of Student " << s[i].smob << endl;
            cout << "The Address of Student is " << s[i].saddress << endl;
            cout << "___________The Courses Read By Student______________ " << endl;
            for (int j = 0; j < s[i].courseregister; j++)
            {
                cout << "Course " << j + 1 << ":" << s[i].stdc[j].cname << endl;
                cout << endl << "------------------------------------------------------------------------------------" << endl;

            }
            break;

        }
        else if (i == size)
        {
            cout << "The Student with This Id Does Not Exist." << endl;
        }
    }
}

//----------------ADD Course--------------------

void add_cou(course c[], int size)
{
    char ch;
    int i = 0;
    do
    {
        cout << endl << "------------------------------------------------------------------------------------" << endl;
        cout << "Enter the name of course " << endl;
        cin >> c[i].cname;
        cout << "Enter the Code of Course " << endl;
        cin >> c[i].code;
        cout << "Enter the Credit hours Of Course " << endl;
        cin >> c[i].chour;

        i++;
        cout << endl << "------------------------------------------------------------------------------------" << endl;
        cout << "Press A to add another Course " << endl;
        cin >> ch;
    } while (ch == 'a' || ch == 'A');
}

//----------------Update Course--------------------

void upd_cou(course c[], int size)
{
    string code;
    cout << "Enter the code of Course you want to update " << endl;
    cin >> code;
    for (int i = 0; i < size; i++)
    {
        if (c[i].code == code)
        {
            course updc;
            cout << "Enter The New Course " << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "Course Code : ";
            cin >> updc.code;
            cout << "Enter the Name of Course : ";
            cin.ignore();
            getline(cin, updc.cname);
            cout << "Credit Hours For Course : ";
            cin >> updc.chour;
            c[i] = updc;
            break;
        }
        if (i == size)
        {
            cout << "Course with this Code does not Exist." << endl;
        }
    }
}

//---------------------Search Course--------------------------------

void sr_course(course c[], int size)
{
    string code;
    cout << "Enter the code of Course you wanna Search " << endl;
    cin >> code;
    for (int i = 0; i < size; i++)
    {
        if (c[i].code == code)
        {
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "Name of Course : " << c[i].cname << endl;
            cout << "Code of Course : " << c[i].code << endl;
            cout << "Credit Hours of Course : " << c[i].chour << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            break;
        }
        if (i == size)
        {
            cout << "The Course of this Code Does Note Exist " << endl;
        }
    }
}


//------------------Delete Course--------------------

void del_course(course c[], int size)
{
    string code;
    cout << "Enter the course code you wanna delete " << endl;
    cin >> code;
    for (int i = 0; i < size; i++)
    {
        if (c[i].code == code)
        {
            for (int j = i; j < size - 1; j++)
            {
                c[j] = c[j + 1];
            }
            size--;
            break;
        }
        if (i == size)
        {
            cout << "The Course with this Code Does not Exist." << endl;
        }
    }
}
void regcourse(course c[], int csize,student* stu)
{
    for (int i = 0; i < csize; i++)
    {
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "Name of Course : " << c[i].cname << endl;
            cout << "Code of Course : " << c[i].code << endl;
            cout << "Credit Hours of Course : " << c[i].chour << endl;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
          
    }
    cout << "In which course Do you want to Register?" << endl;
    cout << "Enter the Name Of Course " << endl;
    cin >> stu->stdc[stu->courseregister].cname;
    stu->courseregister++;
    cout << endl << "------------------------------------------------------------------------------------" << endl;

    
}


//--------------------------------------------------------------------------MAIN FUNCTION------------------------------------------------------

int main()
{
    const int size = 2;
    faculty fa[size];
    student st[size];
    course cr[5];
    student* stu = NULL;

    cout << "=============================================================================================================================================" << endl << endl;
    cout << "                                                                    UET LMS                                                                  " << endl << endl;
    cout << "=============================================================================================================================================" << endl << endl;
start:

    char ch;
    cout << "Enter A to Perform Admin Related Activities " << endl;
    cout << "Enter B to Perform Teacher Related Activities " << endl;
    cout << "Enter C to Perform Student Related Activities " << endl;
    cout << "Enter D to Perform Exit LMS " << endl;
    cin >> ch;
    cout << endl << "------------------------------------------------------------------------------------" << endl;

    if (ch == 'a' || ch == 'A')
    {
        string id1;
        string pass1;
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "                                                                 Admin Pannel                                                                  " << endl << endl;
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "                                                                    LOG IN                                                                " << endl << endl;
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "Enter the User ID " << endl;
        cin >> id1;
        cout << "Enter the Password " << endl;
        cin >> pass1;

        if (id1 == "admin" && pass1 == "123")
        {
            int choice;
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            cout << "Enter 1 For Faculty Related Activities " << endl;
            cout << "Enter 2 for Student Related Activities " << endl;
            cout << "Enter 3 for Course Related Activities " << endl;
            cin >> choice;
            cout << endl << "------------------------------------------------------------------------------------" << endl;

            if (choice == 1)
            {
                while (true)
                {
                    int choice2;
                    cout << endl << "------------------------------------------------------------------------------------" << endl;

                    cout << "Enter 1 to add new Faculty member " << endl;
                    cout << "Enter 2 to Search Faculty member " << endl;
                    cout << "Enter 3 to update faculty member " << endl;
                    cout << "Enter 4 to Leave Faculty Pannel" << endl;
                    cin >> choice2;
                    cout << endl << "------------------------------------------------------------------------------------" << endl;

                    if (choice2 == 1)
                    {
                        inp_f(fa, 2);
                    }
                    if (choice2 == 2)
                    {
                        sr_f(fa, 2);
                    }
                    if (choice2 == 3)
                    {
                        upd_f(fa, 2);
                    }
                    if (choice2 == 4)
                    {
                        goto start;
                    }
                }
            }
            if (choice == 2)
            {
                while (true)
                {
                    int choice2;
                    cout << endl << "------------------------------------------------------------------------------------" << endl;

                    cout << "Enter 1 to add new student  " << endl;
                    cout << "Enter 2 to Search student " << endl;
                    cout << "Enter 3 to update student " << endl;
                    cout << "Enter 4 to Leave student Pannel" << endl;
                    cin >> choice2;
                    cout << endl << "------------------------------------------------------------------------------------" << endl;

                    if (choice2 == 1)
                    {
                        inp_std(st, 2);
                    }
                    if (choice2 == 2)
                    {
                        sr_s(st, 2);
                    }
                    if (choice2 == 3)
                    {
                        upd_std(st, 2);
                    }
                    if (choice2 == 4)
                    {
                        goto start;
                    }
                }
            }

            if (choice == 3)
            {

                while (true)
                {
                    int choice2;
                    cout << endl << "------------------------------------------------------------------------------------" << endl;

                    cout << "Enter 1 to add new Course " << endl;
                    cout << "Enter 2 to Search Course " << endl;
                    cout << "Enter 3 to update Course " << endl;
                    cout << "Enter 4 to Delete Course " << endl;
                    cout << "Enter 5 to Exit " << endl;
                    cin >> choice2;
                    cout << endl << "------------------------------------------------------------------------------------" << endl;

                    if (choice2 == 1)
                    {
                        add_cou(cr, 5);
                    }
                    if (choice2 == 2)
                    {
                        sr_course(cr, 5);
                    }
                    if (choice2 == 3)
                    {
                        upd_cou(cr, 5);
                    }
                    if (choice2 == 4)
                    {
                        del_course(cr, 5);
                    }
                    if (choice2 == 5)
                    {
                        goto start;
                    }
                }
            }
        }
        else
        {
            cout << "Enter a valid User Name Or Password " << endl;
        }

    }

    if (ch == 'b' || ch == 'B')
    {
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "                                                                 Teacher Pannel                                                                  " << endl << endl;
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "                                                                    LOG IN                                                                " << endl << endl;
        cout << "=============================================================================================================================================" << endl << endl;
        string tid;
        string tpass;
        int choice;

        while (true)
        {
            cout << endl << "------------------------------------------------------------------------------------" << endl;

            cout << "Enter 1 To Perform Teacher Related Activities " << endl;
            cout << "Enter 0 To Leave Teacher Pannel " << endl;
            cin >> choice;
            cout << endl << "------------------------------------------------------------------------------------" << endl;

            if (choice == 1)
            {

                cout << "Enter the User ID " << endl;
                cin >> tid;
                cout << "Enter the Password " << endl;
                cin >> tpass;
                for (int i = 0; i < size; i++)
                {

                    if (tid == fa[i].fid && tpass == fa[i].fpassword)
                    {
                        cout << endl << "------------------------------------------------------------------------------------" << endl;

                        cout << "The name of Faculty is " << fa[i].fname << endl;
                        cout << "The Address of Faculty is " << fa[i].faddress << endl;
                        cout << "The Mobile number of Faculty is " << fa[i].fmob << endl;
                        cout << "The Qualification of Faculty is " << fa[i].fqual << endl;
                        cout << "The Courses Teach By Faculty are " << endl;
                        for (int j = 0; j < n1; j++)
                        {
                            cout << "Course Title : " << fa[i].ptr[j].cname << endl;
                            cout << "Course Code : " << fa[i].ptr[j].code << endl;
                            cout << "Course Credit Hours : " << fa[i].ptr[j].chour << endl;
                            cout << endl << "------------------------------------------------------------------------------------" << endl;

                        }
                        break;
                    }

                }
            }

            if (choice == 0)
            {
                goto start;
            }
        }
    }
    if (ch == 'C' || ch == 'c')
    {
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "                                                                 Student Pannel                                                                  " << endl << endl;
        cout << "=============================================================================================================================================" << endl << endl;
        cout << "                                                                    LOG IN                                                                " << endl << endl;
        cout << "=============================================================================================================================================" << endl << endl;
        string sid;
        string spass;
        int choice;
        while (true)
        {
            cout << endl << "------------------------------------------------------------------------------------" << endl;

            cout << "Enter 1 to Perform Student related activities " << endl;
            cout<< "Enter 2 to register new course" << endl;
            cout << "Enter 0 to exit Student Pannel " << endl;
            cin >> choice;
            cout << endl << "------------------------------------------------------------------------------------" << endl;

            if (choice == 1)
            {
                cout << "Enter your User ID " << endl;
                cin >> sid;
                cout << "Enter Password " << endl;
                cin >> spass;
                for (int i = 0; i < size; i++)
                {
                    if (sid == st[i].sid && spass == st[i].spassword)
                    {
                        cout << endl << "------------------------------------------------------------------------------------" << endl;
                        stu = &st[i];
                        cout << "The Name of Student is " << st[i].sname << endl;
                        cout << "The Mobile Number Of Student " << st[i].smob << endl;
                        cout << "The Address of Student is " << st[i].saddress << endl;
                        cout << "______________The Courses Read By Student____________ " << endl;
                        for (int j = 0; j < st[i].courseregister; j++)
                        {
                            cout << "Course " << j + 1 << ":" << st[i].stdc[j].cname << endl;
                            cout << endl << "------------------------------------------------------------------------------------" << endl;

                        }
                        break;
                    }
                    else
                    {
                        cout << "Enter the Valid User Id and Password." << endl;
                    }
                }
            }
            if (choice == 2)
            {
                regcourse(cr, 5, stu);
            }
        }
    }
    return 0;
    
}