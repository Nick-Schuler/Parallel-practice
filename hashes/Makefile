CC=time mpicc -Wall -Werror -O2 -Wno-unused-result


CSOURCES=${wildcard *.c}
TARGET=hash_cracker

all: ${TARGET}	

${TARGET}: ${CSOURCES}

test: ${TARGET}	
	echo "vowelsRfun lFtqQCPzGxs/jOa1WSAVq1A40onc4iV1WcBdcVgxKV0  aeioupy  5"		| mpiexec -n 4 ./hash_cracker
	@echo "Correct answer: 1730: 'iouea'"

clean:
	rm -f  *.o ${TARGET}