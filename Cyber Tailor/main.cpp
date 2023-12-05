/* This is from an old cs1 project, and my god this code is a mess.
After looking through this excersize I cannot believe that I passed 
this class.

side note: there was NO documentation in this project when I dug it up.

I ended up redoing alot of this program to clean it up and make 
it look better. 

In this program we were given the 3 mathematical functions to determine
the user's other size information.*/
#include <iostream>
using namespace std;

/*This is the decelaration for my functions.
these functions are call by value and not call by referance.
The reason for this is because when the value is kicked into 
the function, the function does not change the value of those 
varaibles.

The function definitions are under the main function*/
double hat(double, double);
double jacket(double, double, int);
double waist(double, double, int);

int main()
{
    double height, weight;
    int age;
    char answer;

    /*This set of instructions will print out 
    2 places to the right of the decimal*/
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do
    {
        /*This statment is going to get the user's height
        and store it in the height varaible.*/
        cout << "Enter me your height in inches: " << endl;
        cin >> height;

        /*This statement is going to get the user's age 
        and store it in the age varaible*/
        cout << "Enter your age(Years): " << endl;
        cin >> age;

        /*This statement is going to get the user's 
        weight and store it in the weight varaible.*/
        cout << "Enter your weight(Pounds): " << endl;
        cin >> weight;

        /*These three statements are going to take the previous varaibles and kick 
        them into the three functions that I declared at the top of the program.*/
        cout << "Your hat size is: " << hat(weight, height) << endl;
        cout << "Your jacket size is: " << jacket(height, weight, age) << endl;
        cout << "Your waist size is: " << waist(height, weight, age) << endl;

        /*This is part of the do while loop. It will ask the user
        if they would like to try the program again.*/
        cout << "Would you like to try again?(Y or y): " << endl;
        cin >> answer;
    }
    
    while (answer == 'Y' || answer == 'y');

    return 0;
}

/*This function is going to take our height and weight 
varaible and determine the user's hat size*/
double hat(double weight, double height)

{
    /**/
    return ((weight / height) * 2.9);
}

/*This function is going to take the user's height, weight,
and age to determine the user's jacket size*/
double jacket(double height, double weight, int age)
{
    double jacketSize;
    int j;

    /*This is going to check the user's age.
    if the user's age is greater than or equal to 30.*/
    if (age >= 30)
    {
        /*After confirming the condition above, it 
        will then check to see if the user's age is also
        divisable by 10. If it is, it will use the equation
        below.*/
        if ((age % 10) != 0)
            age = age - (age % 10);
            j = (age - 30) / 10;
            jacketSize = ((height * weight) / 288) + ((1.0 / 8) * j);

                /*This will check if the user's age is equal to 40.
                If it is, it will use the equation below.*/
                if (age == 40)
                    jacketSize = ((height * weight) / 288);
    }
    /*If the user's age does not fall under any of the
    other conditions above the program will instead 
    use this equation to calculate their jacket size*/
    else
        jacketSize = ((height * weight) / 288);
    
    return jacketSize;
}

/*This function is going to take the user's height, 
weight, and age to determine the user's waist size*/
double waist(double height, double weight, int age)
{
    double waistSize;
    int k;

    /*This is going to check to see if the user's 
    age is greater than or equal to 20.*/
    if (age >= 28)
    {
        /*This will check to see if the user's age 
        is not divisable by 2. If it is, it will use
        the equation below to determine the user's
        waist size.*/
        if ((age % 2) != 0)
            age = age - (age % 2);
            k = (age - 28) / 2;
            waistSize = (weight / (5.7)) + ((1.0 / 10) * k);
    }
    /*If the user's age does not fall under any of the
    conditions above the program will instead use this
    equation to calculate their waist size*/
    else
        waistSize = weight / (5.7);

    return waistSize;
}