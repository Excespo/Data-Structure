.PHONY: all build clean run-main report format pack env-build activate

all: clean build run-main

build:
	@mkdir -p build && cd build && cmake .. && make

clean:
	@rm -rf build

run-main:
	@./build/main

report:
	@cd report && sh build.sh

format:
	@tree -a >Dir && find . \( -name "*.h" -o -iname "*.cc" \) |xargs clang-format -i -style=file

pack:
	@if [ -f 519260910009.zip ]; then rm 519260910009.zip; fi && make format && zip -qr 519260910009.zip .

env-build:
	@docker build . -t rp

env-activate:
	@docker run -it --rm -v `pwd`:`pwd` -w `pwd` rp