.DEFAULT_GOAL := test
SHELL := /bin/bash

ECHO ?= echo -e

.PHONY: build
build:
	@-rm -r _build
	@mkdir -p _build
	@cd _build; cmake ..; make

.PHONY: clean
clean:
	-rm -r _build
	-rm -r _output

include_files := $(wildcard include/**/*)
test_files := $(wildcard test/*)
# $(info include_files: $(include_files))
# $(info test_files: $(test_files))

_output/stream_test: CMakeLists.txt $(include_files) $(test_files)
	@make build

.PHONY: stream_test
stream_test: _output/stream_test
	@$(ECHO) "\033[1;35m$@\033[0m"
	@./_output/stream_test

.PHONY: test
test: stream_test

# doc

.PHONY: doc
doc:
	@cd doc; make html

.PHONY: cleandoc
cleandoc:
	-rm -r doc/_build
	-rm -r doc/_doxygen
