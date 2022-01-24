CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror=vla -MMD
OBJECTS = main.o cell.o grid.o observer.o subject.o subscription.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = lightsOut

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
