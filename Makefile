all:
	clang++ -std=c++11 -Wall -Werror -Wextra -c *.cpp
	clang++ -o Nibbler *.o

clean:
	rm -f *.o
	rm -f *.gch

unit-test:
	python3 ./LexerTest.py

fclean: clean
	rm -f ./Nibbler

re: fclean all

