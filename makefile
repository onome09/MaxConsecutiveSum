OBJ = main.o MaxConsecutiveSum.o

EXE = main

CXX = g++
CXXFLAGS = -Wall -g -MMD

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

clean:
	rm -f $(EXE) $(OBJ) $(OBJ:.o=.d) *~ *#

.PHONY: clean