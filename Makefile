BUILD_DIR = ./out

clean:
	rm -rf $(BUILD_DIR)
all:
	mkdir -p $(BUILD_DIR)
	cmake -B $(BUILD_DIR) -G "MSYS Makefiles"
	cmake --build $(BUILD_DIR) --config Release
run:
	./out/opengl.exe