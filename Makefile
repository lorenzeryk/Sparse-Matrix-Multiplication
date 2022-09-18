src = 	$(wildcard *.cpp) \
		$(wildcard Matrix/*.cpp) \
		$(wildcard Verification/*.cpp) \
		$(wildcard Verification/ALGLIB/*.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)  # one dependency file for each source
INPUTS = 	$(wildcard *.mtx)

CC = g++
CFLAGS = -std=c++11 -fopenmp -O3 -MMD    # option to generate a .d file during compilation

TARGET=main

$(TARGET): $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

-include $(dep)   # include all dep files in the makefile

.PHONY: clean
clean:
	rm -f $(obj) $(TARGET)

.PHONY: cleandep
cleandep:
	rm -f $(dep)

.PHONY: run
run:
	@for FILE in *.mtx; do echo "Performing multiplication with input file $$FILE" && ./main $$FILE; done
