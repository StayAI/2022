
build: lint
	# g++ ./0824/08.singleton_1.cpp -o ./build/08.singleton_1
	# ./build/08.singleton_1
	# g++ ./0824/08.singleton_2.cpp -o ./build/08.singleton_2
	# ./build/08.singleton_2

	# g++ ./0825/01.simpleauto.cc -o ./build/01.simpleauto
	# ./build/01.simpleauto
	# g++ ./0825/01.simpleauto2.cc -o ./build/01.simpleauto2
	# ./build/01.simpleauto2

	# g++ ./0825/integral_constant.cc -o ./build/integral_constant
	# ./build/integral_constant

	g++ -fno-elide-constructors ./0827/EffectiveModernC++25.cc -o ./build/EffectiveModernC++25
	./build/EffectiveModernC++25

lint:
	cpplint \
		--filter=-legal/copyright,-whitespace/blank_line \
		./*/*.cpp ./*/*.cc ./*/*.hpp ./*/*.h

clean:
	rm -rf build/*

tree:
	tree > file.log