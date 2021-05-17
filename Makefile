include config.mk

SRC_DIR = src
SRC_H = $(wildcard $(SRC_DIR)/*.h)
SRC_SRC = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJ = $(SRC_SRC:%.cpp=%.o)

DOCS = doc
DOC_SRC = $(DOCS)/src

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_H)
	$(CXX) $(CFLAGS) $(DEFINES) -c $< -o $@

all: packer

gen_class_diagram:
	hpp2plantuml -i "src/*.h" -o $(DOC_SRC)/class_diagram.puml -t $(DOC_SRC)/template.j2

doc:
	$(PLANTUML) $(DOC_SRC)/*.puml -o ..

$(TARGET): $(SRC_OBJ)
	$(CXX) $(CFLAGS) $(DEFINES) $(SRC_OBJ) -o $@

clean:
	$(RM) $(SRC_OBJ)
	$(RM) $(TARGET)
	# $(RM) $(DOCS)/*.png

.PHONY: all clean doc
