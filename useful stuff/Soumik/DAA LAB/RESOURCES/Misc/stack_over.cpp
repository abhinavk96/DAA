

	#include <iostream>
	#include <cstdlib>
	#include <cstring>
	using std::cout;
	using std::endl;
	using std::atoi;
	int main(int argc, char *argv[])
	{
		if(argc ==2 )
		{
			if(atoi(argv[1]) == 0 && strcmp(argv[1], "0") != 0)
				cout << "The argument supplied is not an integer" << endl;
			else
				cout << atoi(argv[1]) << " " << endl;
		}
		else if( argc > 2)
			cout << "Too many arguements" << endl;
        else
            cout << "Insufficient arguements" << endl;
		return 0;
	}