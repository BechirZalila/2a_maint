#
# TP GDB : Makefile
#

# Compilateur et editeur de liens
#
CC		= gcc
LD		= $(CC)

#
# Options de compilation et d'edition de liens
#
CFLAGS		= -c -Wall
LDFLAGS		=

#
# Bibliotheques eventuelles
#
LDLIBS		=

#
# Fichiers : sources, objets, executable
#
SRCS		= tri.c fonctions.c
OBJS		= tri.o fonctions.o
EXEC		= tri

#
# Regle de dependance pour la production de l'application
#
$(EXEC): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

fonctions.c: fonctions.h types.h
tri.c: fonctions.h types.h

#
# Nettoyage
#
clean:
		-@rm $(OBJS) 1>/dev/null 2>&1

clean-all:	clean
		-@rm $(EXEC) *~ 1>/dev/null 2>&1

