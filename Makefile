all:
	g++ -o KNN main.cpp knn.cpp neighbor.cpp instance.cpp data_set.cpp result.cpp -W -Wall -ansi -pedantic
	echo 'Run "./KNN help" to know how can you use this program!'

clean:
	rm KNN
