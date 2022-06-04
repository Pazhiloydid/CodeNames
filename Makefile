MAKEFLAGS=-j --no-print-directory

debug: header
	cd _debug && ${MAKE}

release: header
	cd _release && ${MAKE}

test-debug: test-header
	cd _debug/bin && ./tests -d yes

test-release: test-header
	cd _release/bin && ./tests -d yes

config-debug : _debug
	cd $< && cmake -DCMAKE_BUILD_TYPE=Debug ..

config-release : _release
	cd $< && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..

clean-release :
	cd _release && make clean

clean-debug :
	cd _debug && make clean

_release:
	mkdir _release

_debug:
	mkdir _debug

header:
	@if [ -d .git ]; then \
		echo "================================================================================"; \
		echo "Building at branch [`git rev-parse --abbrev-ref HEAD`]"; \
		echo "================================================================================"; \
		echo ""; \
	fi
test-header:
	@if [ -d .git ]; then \
		echo "================================================================================"; \
		echo "Testing at branch [`git rev-parse --abbrev-ref HEAD`]"; \
		echo "================================================================================"; \
		echo ""; \
	fi
