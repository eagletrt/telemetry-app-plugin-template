MAKEFLAGS += --no-print-directory

.PHONY: release debug format clean

debug:
	@if [ -d lib ]; then \
		echo "removing binaries"; \
		rm -r lib; \
	fi;
	mkdir -p debug; \
	cd debug; \
 	cmake .. -DCMAKE_BUILD_TYPE=Debug; \
	make -j${nproc};

release:
	@if [ -d lib ]; then \
		echo "removing binaries"; \
		rm -r lib; \
	fi;
	mkdir -p release; \
	cd release; \
	cmake .. -DCMAKE_BUILD_TYPE=Release; \
	make -j${nproc};
