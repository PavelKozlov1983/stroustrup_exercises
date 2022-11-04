#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Token {
	char kind;  // what kind of token
	double value;  // for numbers: a value
	string name;   // for name of variables
	Token(char ch)
		:kind(ch), value(0) { }  // make a Token from a char
	Token(char ch, double val)
		:kind(ch), value(val) { }  // make a Token from a char and a double
	Token(char ch, string s)
		:kind(ch), name(s){ }  // make a Token from a char and a string

};

class Token_stream {
public:
	Token_stream() :full(0), buffer(0) { } // make a Token_stream that reads from cin
	Token get();  // get a Token (get() is defined elsewhere)
	void unget(Token t) { buffer = t; full = true; }  // put a Token back
	void ignore(char);
private:
	bool full; // is there a Token in the buffer?
	Token buffer; // here is where we keep a Token put back using unget()
};

//------------------------------------------------------------------------------

const char let = 'L';  // t.kind == let for var definition
const char quit = '#'; // t.kind == quit - exit token
const char print = ';';  // t.kind == print - print token
const char number = '8'; // t.kind == number - means number
const char name = 'A';   // t.kind == name - means var name
const char square_root = 'S'; // t.kind == sqare_root
const char exponentiation = 'P'; // t.kind == exponentiation
const char const_setting = 'C';
const string declkey = "let"; // declaration key word
const string sq_root_key = "sqrt"; // declaration of square root command
const string exponent_key = "pow";


//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) // do we already have a Token ready?
		{ full = false; return buffer; } //remove token from buffer
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
	{	cin.unget(); // put digit back into the input stream
	double val;
	cin >> val; // read a floating-point number
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			bool is_a_const;
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
				cin.unget();
				if (s == declkey)
					return Token(let);
				else if(s == sq_root_key)
					return Token(square_root);
				else if (s == exponent_key)
					return Token(exponentiation);

				return Token(name, s);
		}
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------

double expression();

//------------------------------------------------------------------------------

double term();

//------------------------------------------------------------------------------

double primary();

//------------------------------------------------------------------------------

class Variable {
public:
	string name;
	double value;
	
	Variable(string n, double v)
		:name(n), value(v) { } //for non const variables

};
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (Variable v : var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable(var, val));
}
//------------------------------------------------------------------------------

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	define_name(var_name, d);
	return d;
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

//------------------------------------------------------------------------------

double primary()
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
			ts.unget(next);
			return get_value(t.name);
		}
	}
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
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
			ts.unget(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression()
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
			ts.unget(t);
			return left;
		}
	}
}



void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

const string prompt = "> "; // input prompt
const string result = "= "; // indicate that follows is a result

//------------------------------------------------------------------------------

void calculate()
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
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
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
