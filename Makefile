BUILD_DIR := build

define BUILD_EXAMPLE =
	mkdir -p $(1);    \
	cd $(1);          \
	cmake ../example; \
	$(MAKE) -j;       \
	cd -
endef

define RUN_EXAMPLE =
	if [ -d $(1) ]; then           \
		cd $(1);                   \
		ctest --output-on-failure; \
	    cd -;                      \
	fi
endef

all: clean build test

build:
	$(call BUILD_EXAMPLE,$(BUILD_DIR))

test:
	$(call RUN_EXAMPLE,$(BUILD_DIR))

clean:
	$(RM) -rf $(BUILD_DIR)
