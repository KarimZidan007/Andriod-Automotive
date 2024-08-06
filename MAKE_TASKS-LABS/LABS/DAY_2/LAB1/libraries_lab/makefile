SHELL := /bin/bash
# Compiler and Flags
Compiler = gcc
INCS = -I ./includes
CFLAGS = -c
# Directories
STATIC_LIB_DIR = STATIC_LIB
DYNAMIC_LIB_DIR = DYNAMIC_LIB
SOURCE_DIR = src
APPLICATION_DIR = build
OBJ_DIR = obj
SHARED_OBJ_DIR=SHARE_OBJ
SOURCE_F = $(wildcard $(SOURCE_DIR)/*.c)





OBJ = $(patsubst $(SOURCE_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCE_F))


DYNAMIC_APP: $(SHARED_OBJ_DIR)/libtest.so
	$(Compiler) ./app/main.c -L $(SHARED_OBJ_DIR) -ltest $(INCS) -o $(APPLICATION_DIR)/DYNAMIC_APP 


$(SHARED_OBJ_DIR)/libtest.so: $(OBJ)
	if [[ ! -d ./${SHARED_OBJ_DIR} ]]; then mkdir ./${SHARED_OBJ_DIR}; fi
	$(Compiler) -shared -o $(SHARED_OBJ_DIR)/libtest.so $^




STATIC_APP: $(STATIC_LIB_DIR)/libstaticlib.a 
	@if [[ ! -d ./${APPLICATION_DIR} ]]; then mkdir ./${APPLICATION_DIR}; fi
	$(Compiler)  ./app/main.c   -L $(STATIC_LIB_DIR) -lstaticlib  $(INCS) -o $(APPLICATION_DIR)/STATIC_APP


libstaticlib.a: $(OBJ) 
	if [[ ! -d ./${STATIC_LIB_DIR} ]]; then mkdir ./${STATIC_LIB_DIR}; fi
	ar -rcs $(STATIC_LIB_DIR)/libstaticlib.a $^
	@echo "$(STATIC_LIB_DIR)/libstaticlib.a" Created Successfully!


$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c
	if [[ ! -d ./obj ]]; then mkdir -p ./obj ; fi
	$(Compiler) $(CFLAGS) $(INCS) $< -o $@ 






    
	


.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(STATIC_LIB_DIR)/*.a $(APPLICATION_DIR)/STATIC_APP
