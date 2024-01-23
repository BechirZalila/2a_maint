# 
# $Id: Makefile 14722 2019-02-18 14:03:18Z zalila $
# 

# Nom de l'application 
APPLICATION = arithm

# Compilateur et options de compilation et d'édition des liens 
CC = gcc 
LD = $(CC) 
CFLAGS = -c -g -Wall 
LDFLAGS = -g

# Paramètres d'installation 
prefix = /tmp 

# Bibliothèques 
LIBS = -lm

# Constituants de l'application 
DIST = $(APPLICATION)-src
OBJS = arithm.o fonctions_basiques.o fonctions_avancees.o
SRCS = arithm.c fonctions_basiques.c fonctions_avancees.c
INCL = fonctions_basiques.h fonctions_avancees.h

# Règle d'inférence, construction des .o a partir des .c 
.c.o:
	$(CC) $(CFLAGS) $< -o $@

# Cibles et leurs actions 

all: $(APPLICATION)

$(APPLICATION): $(OBJS) 
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	@-rm -f $(APPLICATION) $(OBJS) $(APPLICATION).tar.gz $(DIST).tar.gz

install: all
	mkdir -p $(prefix)
	cp $(APPLICATION) $(prefix)

dist: $(DIST).tar.gz 

$(DIST).tar.gz: $(SRCS) $(INCL) Makefile
	mkdir -p $(DIST)
	cp -f $(SRCS) $(INCL) Makefile $(DIST) 
	tar czf $(DIST).tar.gz $(DIST)
	rm -rf $(DIST)

# Dépendances

arithm.o: fonctions_basiques.h fonctions_avancees.h
fonctions_avancee.o: fonctions_basiques.h
