author: Victor Yastrub

platform Ubuntu 16.04.4

C++11 compiled under GCC version 5.4.0

Description:
	Program "trams" works in single thread.
	Program accepts input file with "map" of city and
rails coordinates. Purpose of the program is to proccess the
map and give output with the value describes free space in the
city to set lanterns.  
	To build program: run in command line "./build.sh" or use
makefile rule "make"; 
	Makefile support usual rules (make, make re, make clean,
make fclean);
	To run program: run in command line "./tram path/map_name.txt"
	Output you can find in the root of program with name "out.txt"

Inner working:
	- Program designed with "singleton" design pattern (class City);
	- In case of valid input arguments program start parcing map
	- "Parcer" class have instance of City and put all valid data in it.
	- City get rails coords and merge them in case they have common coordinates.
	- Last step is to subtrack from total city square the total lengh of tram railways in the city and put the result in output file.

No third party libraries used