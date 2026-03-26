Polynomial.o: Polynomial.cpp Polynomial.h
	g++ -c Polynomial.cpp Polynomial.h
	rm -f Polynomial.h.gch

demo: Polynomial.cpp Polynomial.h demo.cpp
	g++ Polynomial.cpp Polynomial.h demo.cpp -o demo

test: Polynomial.cpp Polynomial.h test.cpp
	g++ Polynomial.cpp Polynomial.h test.cpp -o test

run_demo: demo
	./demo

run_test: test
	./test

clean:
	rm -f *.o demo test

rebuild:
	make clean
	make Polynomial.o
	make demo
	make test
	
	