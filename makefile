project4: main.o helpers.o job.o building.o
	g++ -o project4 main.o helpers.o job.o building.o -g
main.o: main.cpp heap.h helpers.h graph.h graphnode.h
	g++ -c main.cpp -g
helpers.o: helpers.h
	g++ -c helpers.cpp -g
job.o: job.h
	g++ -c job.cpp -g
building.o: building.h
	g++ -c building.cpp -g
clean:
	rm *.o project4