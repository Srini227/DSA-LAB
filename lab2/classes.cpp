#include <iostream>
using namespace std;
class Shape {
private:
    float length, width, height;

public:

    void length(float l) {
        length = l;
    }


    void setDimensions(float l, float w, float h) {
        length = l;
        width = w;
        height = h;
    }

    
    void SquareArea() {
        cout<<"Area of Square:"<<length*length<<endl;
    }

    void CubeVolume() {
        cout<<"Volume of Cube:"<< length*length*length<<endl;
    }

    void RectangleArea() {
        cout<<"Area of Rectangle:"<<length*width<<endl;
    }

    void CuboidVolume() {
        cout<<"Volume of Cuboid:"<<length*width*height<<endl;
    }
};

int main() {
    Shape shape;
    int choice;
    float length, width, height;

    while (true) {
        cout << "Menu: \n";
        cout << "1.Square\n";
        cout << "2.Cube\n";
        cout << "3.Rectangle\n";
        cout << "4.Cuboid\n";
        cout << "5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the length of the square: ";
                cin >> length;
                shape.length(length);
                shape.SquareArea();
                break;
            case 2:
                cout<<"Enter the side length of the cube:";
                cin>>length;
                shape.length(length);
                shape.CubeVolume();
                break;
            case 3:
                cout<<"Enter the length and width of the rectangle:";
                cin>>length>>width;
                shape.setDimensions(length, width);
                shape.RectangleArea();
                break;
            case 4:
                cout<<"Enter the length, width, and height of the cuboid:";
                cin>>length>>width>>height;
                shape.setDimensions(length, width, height);
                shape.CuboidVolume();
                break;
            case 5:
                cout<< "Exiting\n";
                return 0;
            default:
                cout <<"Invalid choice\n";
        }
    }

    return 0;
}
