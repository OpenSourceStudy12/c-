OBJ=sql_lrh.o dishes.o person.o client.o shop.o courier.o order.o menu.o main.o
OPJ=-c -I ../inc/ -g -std=c++11 
all:$(OBJ)
	g++ $(OBJ) -o all -lmysqlclient
menu.o:menu.cpp
	g++ $(OPJ) menu.cpp 
sql_lrh.o:sql_lrh.cpp
	g++ $(OPJ) sql_lrh.cpp 
dishes.o:dishes.cpp
	g++ $(OPJ) dishes.cpp
person.o:person.cpp
	g++ $(OPJ) person.cpp
client.o:client.cpp
	g++ $(OPJ) client.cpp
shop.o:shop.cpp
	g++ $(OPJ) shop.cpp
courier.o:courier.cpp
	g++ $(OPJ) courier.cpp
order.o:order.cpp
	g++ $(OPJ) order.cpp
main.o:main.cpp
	g++ $(OPJ) main.cpp

clean:
	rm *.o all 
