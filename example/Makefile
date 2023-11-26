BUILD_DIR := build

define BUILD =
	if [ -d $(1) ]; then \
		cd $(1);         \
	else                 \
		mkdir $(1);      \
		cd $(1);         \
		cmake ..;        \
	fi;                  \
	$(MAKE) -j;          \
	cd -
endef

all:
	$(call BUILD,$(BUILD_DIR))

clean:
	$(RM) -rf $(BUILD_DIR)
