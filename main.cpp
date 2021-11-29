#include "std_lib_facilities.h"	

//declare coefficients
double a,b,c;

//variable to check if the result is close to 0
const double epsilon = 1.0e-7;

//Prototype Functions Here
double check_result(double num);
void solve_no_check();
void solve_with_check();

int main()
try{
    //declare variables here
    string answer;
    //ask if the user wants to check the results
	cout << "Do you want your results to be checked? (yes or no): ";
    //get user answer
	cin >> answer;
	if (answer=="no"){
        //solve without checking
        solve_no_check();
    }
	else if (answer=="yes"){
        //solve with checking
        solve_with_check();
    }
	else{
        //invalid input
        error("Invalid input. Enter 'yes' or 'no' ",answer);
    }
	keep_window_open("~");
}
//produce error messages
catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");
}
//function to check the result
double check_result(double num){
    //compute res to compare with epsilon
	double res = a*num*num+b*num+c;
    //start to compare result and epsilon
	if (res==0){
        //result is zero
        //return num
        return num;
    }
	if (0<res && epsilon<res){
        //+ and greater than epsilon
        cout << "Bad result. Off by " << res << '\n';
    }
	else if (res<-epsilon){
        //- and smaller than epsilon
        cout << "Bad result. Off by " << res << '\n';
    }
    //return num
	return num;
}
//function to solve the quadratic equation without checking
void solve_no_check(){
    //ask the user for a b c
	cout << "Enter floating-point numbers (a b c) to be used as coefficients in the formula a*x*x + b*x + c == 0: ";
    //read user input and perform tasks accordingly
	while (cin>>a>>b>>c) {
        //check if a==0
		if(a==0) {
            //check if b==0
			if (b==0){
                //c==0
				cout << "x is not used, so no root solution\n";
            }
			else{
                //x==-c/b
				cout << "x = " << -c/b << '\n';
            }
		}
        //check if b==0
		else if (b==0) {
            //compute -c/a
			double neg_c_over_a = -c/a;
			if (neg_c_over_a == 0){
                //x==0
                cout << "x==0\n";
            }
			else if (neg_c_over_a < 0){
                //no real solutions
                cout << "no real solutions\n";
            }
			else{
                //two real solutions
                cout << "two real solutions: " << sqrt(neg_c_over_a) << " and " << -sqrt(neg_c_over_a) << '\n';
            }
		}
        //apply the whole formula
        //a and b are not zero for sure
		else {
            //compute the formula
			double formula = b*b-4*a*c;
			if (formula==0){
                //one real solution
				cout << "one real solution: " << -b/(2*a) << '\n';
            }
			else if (formula<0){
                //no real solutions
                cout << "no real solutions\n";
            }
			else{
                //two real solutions
                cout << "two real solutions: " << setprecision(12) << (-b+sqrt(formula))/(2*a) << " and " << (-b-sqrt(formula))/(2*a) << '\n';
            }
		}
        //Try again
		cout << "Try again. Enter (a b c): ";
	}
}
//function to solve the quadratic equation with checking
void solve_with_check(){
	//ask the user for a b c
	cout << "Enter floating-point numbers (a b c) to be used as coefficients in the formula a*x*x + b*x + c == 0: ";
    //read user input and perform tasks accordingly
	while (cin>>a>>b>>c) {
        //check if a==0
		if(a==0) {
            //check if b==0
			if (b==0){
                //c==0
                cout << "x is not used, so no root solution\n";
            }
			else{
                //x==-c/b
                cout << "x == " << check_result(-c/b) << '\n';
            }
		}
        //check if b==0
		else if (b==0) {
            //compute -c/a
			double neg_c_over_a = -c/a;
			if (neg_c_over_a == 0){
                //x==0
                cout << "x==0\n";
            }
			else if (neg_c_over_a < 0){
                //no real solutions
                cout << "no real solutions\n";
            }
			else{
                //two real solutions
                cout << "two real solutions: " << check_result(sqrt(neg_c_over_a)) << " and " << check_result(-sqrt(neg_c_over_a)) << '\n';
            }
		}
        //apply the whole formula
        //a and b are not zero for sure
		else {
            //compute the formula
			double formula = b*b-4*a*c;
			if (formula==0){
                //one real solution
                cout << "one real solution: " << check_result(-b/(2*a)) << '\n';
            }
			else if (formula<0){
                //no real solution
                cout << "no real solution\n";
            }
			else{
                //two real solutions
                cout << "two real solutions: " << setprecision(12) << check_result((-b+sqrt(formula))/(2*a)) << " and " << check_result((-b-sqrt(formula))/(2*a)) << '\n';
            }
		}
        //Try again
		cout << "Try again. Enter (a b c): ";
	}
}