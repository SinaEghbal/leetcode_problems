all: rebuild

BUILD_DIR := build

build:
	@echo "Building..."
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cmake --build $(BUILD_DIR)

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR)

test: build
	@echo "Running tests..."
	cd $(BUILD_DIR) && ctest --verbose

rebuild: clean build