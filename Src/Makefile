CXX      = g++

.DEFAULT_GOAL := all

SOURCES = 
SOURCES += couleurs.cpp
SOURCES += case.cpp
SOURCES += mur.cpp
SOURCES += randomuniform.cpp
SOURCES += melangeur.cpp
SOURCES += tuile.cpp
SOURCES += direction.cpp
SOURCES += supermarche.cpp
SOURCES += joueur.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS  += -g -Wall -std=c++11 -pedantic
LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 

########## test_melangeur ##########

#MELANGEUR_SOURCES = test_melangeur.cpp
#MELANGEUR_OBJECTS = $(MELANGEUR_SOURCES:.cpp=.o)

#test_melangeur : $(MELANGEUR_OBJECTS) $(OBJECTS) $(HEADERS)
#	$(CXX) $(MELANGEUR_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
#$(MELANGEUR_OBJECTS): %.o : %.cpp
#	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@
#
#all : test_melangeur
#TARGETS += test_melangeur
#CLEAN_OBJECTS += $(MELANGEUR_OBJECTS)

########## test_tuile ##########

TUILE_SOURCES = test_tuile.cpp
TUILE_OBJECTS = $(TUILE_SOURCES:.cpp=.o)

test_tuile : $(TUILE_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(TUILE_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(TUILE_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_tuile
TARGETS += test_tuile
CLEAN_OBJECTS += $(TUILE_OBJECTS)

########## cleanup ##########
DEPS = $(CLEAN_OBJECTS:.o=.d)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)
