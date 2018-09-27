#include<iostream>

using namespace std;

struct st
{

  int roll;

  char name[10];

  struct st *next;

};


struct st *hptr = 0;		// declare null header of linked list

float totalpoints[999] = { 0 };

float earnedpoints[999] = { 0 };

int addClass ();

int delete_class ();

int editClass ();

void calculate ();

int assignment ();

int grades ();

void contact ();

int
main ()
{

  char ch;

  int opt;

  do

    {

      cout <<
	"Welcome to Zack's Grade Tracker Program \n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n Menu: \n\t1. Add Class\n"
	"\t2. Remove Class\n" "\t3. Edit Class\n" "\t4. Input Assignment\n"
	"\t5. Calculate GPA\n" "\t6. Display Grades\n"
	"\t7. Contact Tutoring Office\n";

      cin >> opt;

      switch (opt)

	{

	case 1:
	  addClass ();

	  break;

	case 2:
	  delete_class ();

	  break;

	case 3:
	  editClass ();

	  break;

	case 4:
	  assignment ();

	  break;

	case 5:
	  calculate ();

	  break;

	case 6:
	  grades ();

	  break;

	case 7:
	  contact ();

	  break;

	default:

	  cout << "Invaild Option... Try again: \n";

	  break;

	}

      cout << "Do you wants another operation(y/n)? : ";

      cin >> ch;

    }
  while (ch == 'Y' || ch == 'y');

}

/* Add Class */

int
addClass ()
{

  st *temp = new st;

  st *temp1 = new st;

  cout << "Enter class number: ";

  cin >> temp->roll;

  if (cin.fail ())
    {

      cout << "Not numeric\n";

      return 0;

    }

  cout << "Enter class name: ";

  cin >> temp->name;

  if (hptr == 0)

    {

      temp->next = hptr;

      hptr = temp;

    }

  else

    {

      temp1 = hptr;

      while (temp1->next)

	temp1 = temp1->next;

      temp->next = temp1->next;	//NULL

      temp1->next = temp;

    }

}

/* Delete Class */

int
delete_class ()
{

  int rollno;

  st *temp = new st;

  st *temp1 = new st;

  cout << "Enter Class Number: ";

  cin >> rollno;

//Rollno is not numeric

  if (cin.fail ())
    {

      cout << "Not numeric\n";

      return 0;

    }

  temp = hptr;

  while (temp)

    {

      if (temp->roll == rollno)

	{

	  if (temp == hptr)

	    {

	      hptr = temp->next;

	      free (temp);

	      return 0;

	    }

	  else

	    {

	      temp1->next = temp->next;

	      free (temp);

	      return 0;

	    }

	}

      temp1 = temp;

      temp = temp->next;

    }

  cout << "Record is not found\n";

}

/* Edit Class */

int
editClass ()
{

  int rollno;

  st *temp = new st;

  st *temp1 = new st;

  cout << "Enter class number:";

  cin >> rollno;

  if (cin.fail ())
    {

      cout << "Not numeric\n";

      return 0;

    }

  temp = hptr;

  while (temp)

    {

      if (temp->roll == rollno)

	{

	  float temptotal;
	  float tempearned;

	  cout << "Enter new total points: ";
	  cin >> temptotal;
	  cout << "Enter new earned points: ";
	  cin >> tempearned;

	  totalpoints[rollno] = temptotal;
	  earnedpoints[rollno] = tempearned;

//cin>>temp->grade;

	  return 0;

	}

      temp1 = temp;

      temp = temp->next;

    }

  cout << "Record not found\n";


}




/* Input Assignment */

int
assignment ()
{

  int rollno;

  st *temp = new st;

  st *temp1 = new st;

  cout << "Enter class number:";

  cin >> rollno;

  if (cin.fail ())
    {

      cout << "Not numeric\n";

      return 0;

    }

  temp = hptr;

  while (temp)

    {

      if (temp->roll == rollno)

	{

	  float temptotal;
	  float tempearned;

	  cout << "Enter assignment total points: ";
	  cin >> temptotal;
	  cout << "Enter assignment earned points: ";
	  cin >> tempearned;

	  totalpoints[rollno] = totalpoints[rollno] + temptotal;
	  earnedpoints[rollno] = earnedpoints[rollno] + tempearned;

//cin>>temp->grade;

	  return 0;

	}

      temp1 = temp;

      temp = temp->next;

    }

  cout << "Record not found\n";

}

// Caclulate GPA

void
calculate ()
{
  float earnedsum = 0;
  float totalsum = 0;

  for (int i = 0; i < 4; i++)
    {
      earnedsum = earnedsum + earnedpoints[i];
    }

  for (int i = 0; i < 4; i++)
    {
      totalsum = totalsum + totalpoints[i];

    }

  float GPA = (earnedsum / totalsum) * 4;
  cout << "GPA: " << GPA << "\n";

}

/* Grades */

int
grades ()
{

  int rollno;

  st *temp = new st;

  st *temp1 = new st;

  cout << "Enter class number: ";

  cin >> rollno;

  if (cin.fail ())
    {

      cout << "Not numeric\n";

      return 0;

    }

  temp = hptr;

  float score = earnedpoints[rollno] / totalpoints[rollno];

  char grade;

  if (score >= .90)
    {
      grade = 'A';
    }
  else if (score >= .81 && score < .90)
    {
      grade = 'B';
    }
  else if (score >= .71 && score < .80)
    {
      grade = 'C';
    }
  else if (score >= .61 && score < .70)
    {
      grade = 'D';
    }
  else if (score < .61)
    {
      grade = 'F';
    }


  cout << "#\t\tClass\t\tGrade\n";

  cout << "-------------------------------------------\n";

  while (temp)

    {

      if (temp->roll == rollno)

	{

	  cout << temp->roll << "\t\t|" << temp->
	    name << "\t\t|" << grade << "\n";

	  return 0;

	}

      temp1 = temp;

      temp = temp->next;

    }

  cout << "Record is not present\n";

}

/* Contact */

void
contact ()
{

  cout << "\tEmail: collegetutoring@gmail.com \n" "\tPhone: (123)-123-1234\n";
}
