CC=clang

testsecurity: test_code.o
	$(CC) -L ../libsecurity -lsecurity test_code.o -o testsecurity

test_code.o: test_code.c 
	$(CC) -I ../libsecurity -c test_code.c