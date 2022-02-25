.PHONY: main exploit clean all dir

all: main exploit dir

dir:
	mkdir -p "GCONV_PATH=."
	touch "GCONV_PATH=./test"
	chmod a+x "GCONV_PATH=./test"

main: main.c
	cc main.c -o main -g

exploit: exploit.c
	cc exploit.c -o test/exploit.so -shared -fPIC

clean:
	rm main test/exploit.so
	rm -rf "GCONV_PATH=."