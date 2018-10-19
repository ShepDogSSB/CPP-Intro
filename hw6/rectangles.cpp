/*
  File: rectangles.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/23/18
  Synopsis: ??
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Point
{
private:
	double px;
	double py;

public:
	void setX(const double x);
	void setY(const double y);
	double getX() const;
	double getY() const;
};

class Rectangle
{
private:
	string name;
	Point blPoint;
	double length, height;

public:
	// member functions
	void setName(const string & inName);
	void setBottomLeft(const double x, const double y);
	void setDimensions(const double inLength, const double inHeight);

	string getName() const;
	Point getBottomLeft() const;
	double getLength() const;
	double getHeight() const;
	
	double area() const;
	double perimeter() const;
	Point midPoint() const;
	void scaleBy4();
	void display() const;
};

// FUNCTION PROTOTYPES GO HERE:
void display_banner();
bool read_rectangle(const string prompt, const string error_one, const string error_two, string & input, vector<Rectangle> & rectangles);
void read_coords(const string prompt, double & x, double & y);
void read_measurements(const string prompt, double & height, double & length);
void add_rect(string & name, double & x, double & y, double & height, double & length, vector<Rectangle> & rectangles);

int main()
{
	// Define your local variables, e.g. a vector of class Rectangle
    vector<Rectangle> rectangles;

	string rect_prompt("Enter the name of the first rectangle: ");
	string coord_prompt("Enter x's bottom left x and y coord: ");
	string measurement_prompt("Enter x's length and height: ");

	string error_one("This name is already being used!");
    string error_two("Invalid input. Type 'rec' followed by the name or 'stop' if done.");

    string input = "x";
    string tempName;
    double x(0.0), y(0.0), height(0.0), length(0.0);


    display_banner();
    while(input != "stop") {
        if(read_rectangle(rect_prompt, error_one, error_two, input, rectangles)){
            if(input == "stop") {
                if (rectangles.empty()) {
                    cout << "You have no rectangles in your list." << endl;
                } else {
                    for(int i = 0; i < rectangles.size(); i++){
                        rectangles.at(i).display();
                        rectangles.at(i).scaleBy4();
                        cout << "     After scale by 4: ";
                        rectangles.at(i).display();
                        cout << endl;
                    }
                }
            }else{
                tempName = input.substr(4, input.length() - 1);
                coord_prompt = "Enter " + tempName + "'s bottom left x and y coord: ";
                measurement_prompt = "Enter " + tempName + "'s length and height: ";

                read_coords(coord_prompt, x, y);
                read_measurements(measurement_prompt, height, length);
                add_rect(tempName, x, y, height, length, rectangles);
                cout << "Thank you! ";
            }
        }
        rect_prompt = "Enter the name of the next rectangle: ";
    }
    return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
void display_banner(){
    cout << "Welcome! Create your own list of rectangles." << endl <<
         "You will be asked to provide information about each rectangle in your list by name." << endl <<
         "Type the word 'stop' for the rectangle name when you are done." << endl << endl;
}
bool read_rectangle(const string prompt, const string error_one, const string error_two, string & input, vector<Rectangle> & rectangles){
    string keyword("rec ");

    cout << prompt;
    fflush(stdin);
    getline(cin, input);
    if(input != "stop"){
        if(input.substr(0, 4) != keyword){
            cout << error_two << endl << "Try again! ";
            return false;
        }
        else if(! rectangles.empty()){
            for(int i = 0; i < rectangles.size(); i++){
                if(input.substr(4, input.length() - 1) == rectangles.at(i).getName()){
                    cout << error_one << endl << "Try again! ";
                    return false;
                }
            }
        }
    }
    return true;
}
void read_coords(const string prompt, double & x, double & y){
    cout << prompt;
    cin >> x >> y;
}
void read_measurements(const string prompt, double & length, double & height){
    cout << prompt;
    cin >> length >> height;
    while(height < 0 || length < 0){
        cout << "Make length and height positive values. Try again." << endl;
        cout << prompt;
        cin >> length >> height;
    }
}
void add_rect(string & name, double & x, double & y, double & length, double & height, vector<Rectangle> & rectangles){
    Rectangle r;
    r.setName(name);
    r.setDimensions(length, height);
    r.setBottomLeft(x, y);
    rectangles.push_back(r);
}

// CLASS MEMBER FUNCTION DEFINITIONS GO HERE:

void Point::setX(const double x) 
{
	px = x;
}

void Point::setY(const double y) 
{
	py = y;
}

double Point::getX() const 
{
	return (px);
}

double Point::getY() const 
{
	return (py);
}

void Rectangle::setName(const string & inName) 
{
	name = inName;
}

void Rectangle::setBottomLeft(const double x, const double y) 
{
    blPoint.setX(x);
    blPoint.setY(y);
}

void Rectangle::setDimensions(const double inLength, const double inHeight) 
{
	length = inLength;
	height = inHeight;
}

string Rectangle::getName() const
{
	return (name);
}

Point Rectangle::getBottomLeft() const
{
	return (blPoint);
}

double Rectangle::getLength() const
{
	return (length);
}

double Rectangle::getHeight() const
{
	return (height);
}

double Rectangle::area() const
{
	double area(0.0);
	area = getHeight() * getLength();
	return area;
}
	
double Rectangle::perimeter() const
{
	double perimeter(0.0);
	perimeter = (getLength() * 2) + (getHeight() * 2);
	return perimeter;
}

Point Rectangle::midPoint() const
{
	Point midPoint;
    midPoint.setX(blPoint.getX() + (getLength()/2));
	midPoint.setY(blPoint.getY() + (getHeight()/2));
	return midPoint;
}
	
void Rectangle::scaleBy4() 
{
    double newLength(getLength() * 4);
    double newHeight(getHeight() * 4);
    setBottomLeft((blPoint.getX() - ((newLength - getLength())/2)), (blPoint.getY() - ((newHeight - getHeight())/2)));
    setDimensions(newLength, newHeight);

}

void Rectangle::display() const
{
    cout << "Rectangle '" << getName() << "': ";
	cout << "Location is (" << blPoint.getX() << ", " << blPoint.getY() << "), ";
	cout << "Length is " << getLength() << ", ";
	cout << "Height is "  << getHeight() << "; ";
	cout << "Area is " << area() << ", ";
	cout << "Perimeter is " << perimeter() << ", ";
	cout << "Midpoint is located at (" << midPoint().getX() << ", " << midPoint().getY() << ").";
    cout << endl;
}			
