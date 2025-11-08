#include <bits/stdc++.h>
using namespace std;

class c1{
    public : 
        string name;
        int id;
        void printData(){
            cout << name << " : " << id << endl;
        }
};

class c2{
    public : 
        string name;
        int id;
        c2(){
            // default constructor
            name = "UnAvailable";
            id = -1;
        }
        c2(string str,int x){
            // user defined or paramatized constructor
            name = str;
            id = x;
        }
        void printData(){
            cout << name << " : " << id << endl;
        }
};

class c3{
    private:
        string name;
        int id;
};

class c4{
    private:
        string name;
        int id;
    public:
        c4(){
            name = "Un Available";
            id = -1;
        }
        c4(string str,int x){
            name = str;
            id = x;
        }
        void printData(){
            cout << name << " : " << id << endl;
        }
};

class c5{
    private:
        string userName;
        string email;
        int password;

    public:
        // c5(string name,string mail,int key){
        //     userName = name;
        //     email = mail;
        //     password = key;
        // }
        c5(string name,string mail,int key):userName(name),email(mail),password(key){

        }
        void printData(){
            cout << "User Name : " << userName << endl;
            cout << "User Mail : " << email << endl;
        }
        void changeUserName(string mail,int key,string newUserName){
            if (mail == email && key == password){
                cout << "User Name changed successfully" << endl;
                cout << userName << " -> " << newUserName << endl;
                userName = newUserName;
            }else{
                cout << "InCorrect Login Data" << endl;
            }
        }
};

class c6{
    public:
        int id;
        c6(int x): id(x){
            cout << "constructor : " << id << endl;
        }
        ~c6(){
            cout << "Destructor : " << id << endl;
        }
};

class c7_support{
    public:
        virtual void f1() = 0; // pure virtual function, all classes which are connected to c7_support should also have these function.
        
        void f3(){
            cout << "support c7  : f3 " << endl;
        }
};

class c7: c7_support{
    public:
        // c7 connected to c7_support
        // c7_support have a pure virtual function
        // here f1() is a overrider to that.
        void f1(){
            cout << "class 7 - f1 - overrider of c7_support" << endl;
        }
        void f2(){
            cout << "class 7 - f2" << endl;
        }
};

class Animal {
    public:
        virtual void makeSound(){
            cout << "Animal !! !!" << endl;
        }
        void sleep() {
            std::cout << "Animal Zzz..." << std::endl;
        }
};

class Dog : public Animal {
    public:
        void bark() {
            cout << "Dog bow bow !" << std::endl;
        }
        void makeSound(){
            cout << "Dog zzz !" << endl;
        }
};

class c8_parent {
    public:
        int id_p;
};
// Sub class inheriting from Base Class(Parent)
class c8 : public c8_parent {
    public:
        int id_c;
};

// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A {
    public:
        int x;

    protected:
        int y;

    private:
        int z;
};
class B : public A {
	// x is public
	// y is protected
	// z is not accessible from B
};
class C : protected A {
	// x is protected
	// y is protected
	// z is not accessible from C
};
class D : private A // 'private' is default for classes
{
	// x is private
	// y is private
	// z is not accessible from D
};

class parentA_1{
    public:
        parentA_1(){
            cout << "this is parentA_1 : " << -1 << endl; 
        }
        parentA_1(int y){
            cout << "this is parentA_1 :" << y*2 << endl;
        }
};
class childA_1: public parentA_1{
    public:
        childA_1(int x):parentA_1(x){
            cout << "this is childA_1 : " << x << endl;
        }
};

class parentA_2{
    public:
        parentA_2(){
            cout << "this is parentA_2" << endl;
        }
};
class parentB_2{
    public:
        parentB_2(){
            cout << "this is parentB_2" << endl;
        }
};
class childAB_2:public parentA_2, public parentB_2{
    public:
        childAB_2(){
            cout << "this is childAB_2" << endl;
        }
};

class classA_3{
    public:
        classA_3(){
            cout << "this follows class A" << endl;
        }
};
class classB_3:classA_3{
    public:
        classB_3(){
            cout << "this follows class B" << endl;
        }
};
class classC_3:classB_3{
    public:
        classC_3(){
            cout << "this follows class C" << endl;
        }
};

class classA_4{
    public:
        classA_4(){
            cout << "this is from class A" << endl;
        }
};
class classB_4: public classA_4{
    
};
class classC_4: public classA_4{

};

class base1{
    public:
        string color = "black";
};
class derive1: public base1{
    public:
        string color = "white";
};

class base2{
    public:
        string color = "black";
        virtual void f1(){
            cout << "base2 f1" << endl;
        }
        void f2(){
            cout << "Non virtual base2 f2" << endl;

        }
};
class derive2: public base2{
    public:
        string color = "white";
        void f1(){
            cout << "derive2 f1" << endl;
        }
        void f2(){
            cout << "Non virtual derive2 f2" << endl;
            
        }
};

class triangle{
    private:
        int side;
        int circumference;
        float area;
    public:
        triangle(int x):side(x){
            circumference = 3*side;
            area = (1.732 * side * side)/4;
            cout << "triangel with side length : " << x << endl;
        }
    friend void calculate(triangle);
};
void calculate(triangle t){
    cout << "circumference : " << t.circumference << endl;
    cout << "area : " << t.area << endl;
}

int main(){

    // here c1 class have all variables, functions in public -> so we can access or change or use them outside class also.
    cout << "\nclass 1" << endl;
    c1 ob1_c1;
    ob1_c1.name = "satwik";
    ob1_c1.id = 129;
    ob1_c1.printData(); // ? this is abstraction

    // c2 is a class with user defined constructor, so adding data is easy
    cout << "\nclass 2" << endl;
    c2 ob1_c2;
    c2 ob2_c2("satwik",129);
    ob1_c2.printData();
    ob2_c2.printData();

    // c3 is a class with all variables are kept private
    cout << "\nclass 3" << endl;
    c3 ob1_c3;
    // ob1_c3.name = "satwik"; error as name is private variable, it is accesible only in c3 class.
    // we defined object of c3 class but we can't access to variables as there are private 
    // which means c3 is useless

    // c4 is a class with variables kept private, but they are some public functions to access the variables
    // ? this is called encapsulation
    cout << "\nclass 4" << endl;
    c4 ob1_c4;
    c4 ob2_c4("satwik",129); // we are accessing name,id (not directly) using constructor which is public;
    // ob1_c4.name = "kedar"; error -> we can't directly access to name as it is private variable
    ob2_c4.printData();

    // c5 is a same as c4 , but in c4 we can access to variables only at time of declaring using constuctor
    // now in c5 we are adding some another public functions to access private variables.
    cout << "\nclass 5" << endl;
    c5 ob1_c5("satwik","satwik1330@gmail.com",129);
    ob1_c5.printData();
    // ob1_c5.userName = "kedar" -> error
    ob1_c5.changeUserName("satwik1330@gmail.com",129,"kedar");

    // c6 is a class with both constructor + destructor
    cout << "\nclass 6" << endl;
    c6* ob1_c6 = new c6(8);
    for (int i = 1;i<3;i++){
        c6 ob2_c6(i);
    }
    delete ob1_c6; // dynamically delete

    // c7 is a class connected with c7_support
    cout << "\nclass 7" << endl;
    c7 ob1_c7;
    // c7_support ob2_c7; error as c7_support is a abstract class beacuse it has a pure virtual function
    ob1_c7.f1();
    ob1_c7.f2();
    // ob1_c7.f3(); ? error as f3 is declared in c7_support which is abstract class. 

    // animal -> dog 
    cout << "\nAnimal -> dog" << endl;
    Dog d1;
    d1.bark(); // declared in dog
    d1.makeSound(); // declared in animal but override by dog
    d1.sleep(); // declared in animal 

    // c8 is a subclass of c8_parent
    cout << "\nclass - c8" << endl;
    c8 ob1_c8;
    ob1_c8.id_c = 1; // child id
    ob1_c8.id_p = 2; // parent id // id_p is a variable declared in parent class

    c8_parent ob2_c8;
    // ob2_c8.id_c = 1; -> error becuase id_c is a variable defined in c8 not in c8_parent
    ob2_c8.id_p = 3;

    // parentA_1 -> childA_1 | single type inheritance
    cout << "\nsingle inheritance" << endl;
    childA_1 ob1_childA_1(8); // constructor of parentA_1 -> childA_1

    // parentA_2 + parentB_2 -> childAB_2 | multiple inheritance
    cout << "\nmultiple inheritance" << endl;
    childAB_2 ob1_childAB_2;

    // classA -> classB -> classC | multi level inheritance
    cout << "\nmutliLevel inheritance" << endl;
    classC_3 ob1_classC_3;

    // class A -> class B, class C
    cout << "\nhybrid inheritance" << endl;
    classB_4 ob1_classB_4;
    classC_4 ob1_classC_4;

    // ? polymorphism
    cout << "\npolymorphism" << endl;

    base1 ob1_base1;
    cout << "base object : " << ob1_base1.color << endl;
    derive1 ob1_derive1;
    cout << "derive object : " << ob1_derive1.color << endl;
    base1 ob2_base1 = derive1(); // it is not derive object, it is base class pointing to derive 
     // as we are using derive1() we think we will get white as answer, but we will get black
    cout << "derive object : " << ob2_base1.color << endl;

    // base pointer to derived object
    cout << "\nbase pointer to derive\n" << endl;
    base2* ob1;
    derive2 ob2;
    ob1 = &ob2;
    ob1->f1();
    ob1->f2();
    cout << ob1->color << endl;
    cout << endl;
    ob2.f1();
    ob2.f2();
    cout << ob2.color << endl;

    // ? friend functions
    cout << "\nfriend Functions\n" << endl;
    triangle t1(5);
    // cout << t1.circumference << endl; -> error as it is private
    // we can print circumference by writing public functions inside the class
    // or trinagle  cout << t1.circumference << endl same but in friend function which is connected to triangle class.
    // here calculate also have cout << t1.circumference << endl same code but it is firend class so no error
    calculate(t1);

    cout << endl;
    return 0;
}