// Copyright (c) 2022 Kevin Csiffary All rights reserved.
//
// Created by: Kevin Csiffary
// Date: Oct. 16, 2022
// This program asks the user for 2 angles in a triangle
// it then tells the user if the triangle is equilateral, isosceles, or scalene
// it also tells the user if it is not possible
// for the 2 angles to make up a triangle
// it also checks input errors like words and negative numbers


// include all required libraries
#include <iostream>



// declares required floats
float angle1f;
float angle2f;
float angle3f;

// declares main fuction so earlier functions can access it
int main();

// this function restarts the program, it is called any time there is an error
void restartFromError() {
    std::string c;
    std::cout << "\nEnter c to continue\n";
    std::cin >> c;
    std::cout << "\n";
    main();
}

// these two fuctions were put together because cpplint was causing errors
void userInputAndMakeAnglesFloats() {
    // gets all required input from the user

    // declares required strings
    std::string angle1str;
    std::string angle2str;

    // gets user input for two of the angles of a triangle
    std::cout << "Please input two angles of a triangle," << std::endl;
    std::cout << "Angle1: ";
    std::cin >> angle1str;
    std::cout << "Angle2: ";
    std::cin >> angle2str;

    // casts the angle variables into floats
    // and checks to ensure the user input is valid

    // try function is used to catch any improper inputs
    try {
        // casts all of the variables into floats
        angle1f = std::stof(angle1str);
        angle2f = std::stof(angle2str);
    } catch (std::invalid_argument) {
        std::cout << "\nThere was an error in your inputs, please try again.";
        restartFromError();
    }

    // adds extra line
    std::cout << "\n";
}

// calculates the third angle of the triangle
// and checks for negative or zero inputs
void thirdAngle() {
    // checks that the to angles are valid and make a triangle
    if (angle1f > 0 && angle2f > 0) {
        // calculates the third angle of the triangle
        angle3f = 180 - angle2f - angle1f;
    } else {
        std::cout
        << "You can not have a negative or zero angle, please try again.";
        restartFromError();
    }
}

// check the angles to see what triangle they form
void checkTriangle() {
    // if the angles dont make up a triangle
    if (angle3f <= 0) {
        std::cout
        << "Your angels will not make a triangle, please try again.\n\n";
        main();

    // check the type of the triangle
    } else if (
        (angle3f == angle2f) | (angle2f == angle1f) | (angle1f == angle3f)) {
        if (angle3f == angle2f && angle1f) {
            std::cout << "Your triangle is equilateral";
        } else {
            std::cout << "Your triangle is isosceles";
        }
    } else if ((angle3f != angle2f != angle1f)) {
        std::cout << "Your triangle is scalene";

    // if none of the triangles are selected (this error should never be called)
    } else {
        std::cout << "An error occurred, please try again.";
        restartFromError();
    }

    // adds extra line
    std::cout << "\n";
}

// asks the user if they want to restart after the program is finished
void userRestart() {
    // defines a restart variable so the program can read the users inputs
    std::string restart;

    // ask the user if they want to restart
    std::cout << "\nWould you like to try again? (y/n)\n";
    std::cin >> restart;

    // if the response is y restart the program
    if (restart == "y") {
        main();

    // if the response is n exit the program
    } else if (restart == "n") {
        exit(0);

    // if the response isn't y or n restart this function
    } else {
        std::cout << "Please enter y or n\n";
        userRestart();
    }
}

// runs the program by calling the functions in the correct order
int main() {
    userInputAndMakeAnglesFloats();
    thirdAngle();
    checkTriangle();
    userRestart();
}
