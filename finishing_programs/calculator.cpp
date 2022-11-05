#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const char let = 'L';  // t.kind == let for var definition
const char quit = '#'; // t.kind == quit - exit token
const char print = ';';  // t.kind == print - print token
const char number = '8'; // t.kind == number - means number
const char name = 'A';   // t.kind == name - means var name
const char square_root = 'S'; // t.kind == sqare_root
const char exponentiation = 'P'; // t.kind == exponentiation
const char con = 'C';
const string declkey = "let"; // declaration key word
const string constkey = "const";	// const keyword
const string sq_root_key = "sqrt"; // declaration of square root command
const string exponent_key = "pow";
const string prompt = "> "; // input prompt
const string result = "= "; // indicate that follows is a result

//------------------------------------------------------------------------------

class Token {
public:
	char kind;  // what kind of token
	double value;  // for numbers: a value
	string name;   // for name of variables
	Token(char ch)
		:kind(ch), value(0) {}  // make a Token from a char
	Token(char ch, double val)
		:kind(ch), value(val) {}  // make a Token from a char and a double
	Token(char ch, string s)
		:kind(ch), name(s) {}  // make a Token from a char and a string

};

class Token_stream {
public:
	Token_stream(); // make a Token_stream that reads from cin
	Token get();  // get a Token (get() is defined elsewhere)
	void putback(Token t);  // put a Token back
	void ignore(char c);
private:
	bool full; // is there a Token in the buffer?
	Token buffer; // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) // do we already have a Token ready?
		{
		full = false;
		return buffer;
		} //remove token from buffer
	char ch; // note that >> skips whitespace (space, newline, tab, etc.)
	cin >> ch;

	switch (ch) {
	case print:
	case quit:
	case square_root:
	case exponentiation:
	case '{':
	case '}':
	case ',':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
		return Token(ch); // let each character represent itself
	case '.':  // floating num can starts from .
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.putback(ch); // put digit back into the input stream
	double val;
	cin >> val; // read a floating-point number
	return Token(number, val);
	}
	default:
		if (isalpha(ch))
		{	// start with a letter
			string s;
		    s += ch;
		    while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch;	// letters digits and underscores
		    cin.putback(ch);
		    if (s == declkey) return Token(let); // keyword "let"
		    if (s == constkey) return Token(con); // keyword "const"
		    return Token(name,s);
		}
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
// c represents the kind of a Token
{
	// first look in buffer:
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	// now search input:
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get() and putback()

//------------------------------------------------------------------------------

class Variable {
public:
	string name;
	double value;
	bool var;	// variable (true) or constant (false)
	Variable(string n, double v, bool va = true)
		:name(n), value(v), var(va) { }
};


//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s) // return the value of the Variable names s
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void set_value(string s, double d) // set the Variable named s to d
{
	for (Variable v : var_table)
		if (v.name == s) {
			if(v.var == false) error(s, " is a constant");
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s) // is var already in var_table?
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

//------------------------------------------------------------------------------

double define_name(string s, double val, bool var = true)
// add (s,val,var) to var_table
{
	if (is_declared(s)) error(s, " declared twice");
	var_table.push_back(Variable(s, val, var));
	return val;
}

//------------------------------------------------------------------------------

double expression();  // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double primary()  // deal with numbers and parentheses
{
	Token t = ts.get();
	switch (t.kind) {
	case exponentiation:
	{
		t = ts.get();
		if (t.kind != '{') error("'{' expected");

		double d = expression(); // num
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		int i = narrow_cast<int>(expression()); // exponent
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return pow(d, i);
	}
	case square_root:
	{
		double d = expression();
			if(d < 0) error("taking the square root of a negative");
		return sqrt(d);
	}
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case '+':
	    	return primary();
	case number:
		return t.value;
	case name: {
		Token next = ts.get();
		if (next.kind == '=') // handle name = expression
			{
				double d = expression();
				set_value(t.name, d);
				return d;
			}
		else
		{
			ts.putback(next);
			return get_value(t.name);
		}
	}
	default:
		error("primary expected");
	}
}
//------------------------------------------------------------------------------

double term()	// deal with *, /, and %
{
	double left = primary();
	Token t = ts.get();  // get the next token from token stream
	while (true) {

		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{
			double d = primary();
		    if (d == 0) error("divide by zero");
		    left = fmod(left, d);
		    t = ts.get();
		    break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression() // deal with + and -
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double declaration(Token k)
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
// k will be "let" or "con"(stant)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);

	double d = expression();
	define_name(var_name, d, k.kind == let);
	return d;
}

//------------------------------------------------------------------------------

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
	case con:
		return declaration(t.kind);
	default:
		ts.putback(t);
		return expression();
	}
}

//------------------------------------------------------------------------------


void clean_up_mess()
{
	ts.ignore(print);
}


//------------------------------------------------------------------------------

void calculate()
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()

try {

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k", 1000);

	 cout << "Welcome to calculator!\n"
	    <<"Please enter expression. Use digits, ., +, -, *, = /\n";


	calculate();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open("~~");
	return 2;
}
