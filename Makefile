.PHONY: build deploy configure

build: 
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && ninja -j8
	
configure: configure-debug


configure-release:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake -DCMAKE_TOOLCHAIN_FILE=../lib/vcpkg/scripts/buildsystems/vcpkg.cmake \
				-DUSE_GTEST=ON \
				-DCMAKE_C_COMPILER=clang \
				-DCMAKE_CXX_COMPILER=clang++ \
				-DCMAKE_BUILD_TYPE=RELEASE \
				-GNinja .. 

configure-debug:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake -DCMAKE_TOOLCHAIN_FILE=../lib/vcpkg/scripts/buildsystems/vcpkg.cmake \
				-DUSE_GTEST=ON \
				-DCMAKE_C_COMPILER=clang \
				-DCMAKE_CXX_COMPILER=clang++ \
				-DCMAKE_BUILD_TYPE=DEBUG \
				-GNinja .. 


clean: 
	rm -rf build

vcpkg:
	git clone https://github.com/microsoft/vcpkg ./lib/vcpkg && \
	./lib/vcpkg/bootstrap-vcpkg.sh && \
	./lib/vcpkg/vcpkg install
