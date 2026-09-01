.PHONY: build clean

build:
	cmake -B build && cmake --build build -- -j 10 && scan-build -k -V cmake -DBUILD_TESTING=OFF build

clean:
	rm -rf ./build/ .cache

