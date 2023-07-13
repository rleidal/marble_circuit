OBJ_DIR := output
CXX := /usr/bin/g++
CPPFLAGS := -std=c++23 -MMD

BIN := test

.PHONY: run clean

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


$(OBJS): | $(OBJ_DIR)
$(OBJ_DIR)/%.o : src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $(BIN)

run: $(BIN)
	@./$(BIN)

clean:
	rm -rf ${OBJ_DIR} $(BIN)

bin: $(BIN)
	@echo "Build complete"

print:
	@echo "$(DEPS)"


-include $(OBJS:%.o=%.d)
