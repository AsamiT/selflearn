OUTPUT = asn_motd

all: main.cpp
	clang++ main.cpp -o $(OUTPUT)

install: asn_motd
	clang++ main.cpp -o $(OUTPUT)
	cp $< /usr/bin

uninstall: motd
	rm -f /usr/bin/asn_motd

clean: main.cpp
	rm -f $(OUTPUT)
	rm -f *.o
