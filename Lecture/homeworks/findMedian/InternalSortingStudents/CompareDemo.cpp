#include "Compare.h"
using namespace std;

int main()
{
	// A double-quotes pair marked string terminates with '\0' by default
	char a[] = "atom"; // i.e. 'a','t','o','m','\0'
	char b[] = "bright";
	char b2[] = "bright";
	char c[] = "computer";
	char c2[] = "comauter";
	char c3[] = "comxuter";

	cout << a << " < " << b << " is " << CharsCompare::lt(a,b) << endl;
	cout << b2 << " < " << a << " is " << CharsCompare::lt(b2,a) << endl;
	cout << b << " == " << b2 << " is " << CharsCompare::eq(b,b2) << endl;
	cout << b << " < " << b2 << " is " << CharsCompare::lt(b,b2) << endl;
	cout << b << " > " << b2 << " is " << CharsCompare::gt(b,b2) << endl;
	cout << c2 << " > " << c << " is " << CharsCompare::gt(c2,c) << endl;
	cout << c2 << " > " << c3 << " is " << CharsCompare::gt(c2,c3) << endl;
	cout << c << " == " << c << " is " << CharsCompare::eq(c,c) << endl;
	cout << c2 << " < " << c << " is " << CharsCompare::lt(c2,c) << endl;
	cout << c2 << " < " << c3 << " is " << CharsCompare::lt(c2,c3) << endl;

	return 0;
}

