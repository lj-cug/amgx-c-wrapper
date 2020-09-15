AMGXWRAPPER_INCLUDE_DIR	?= /lustre/scratch2/ws/0/hpclab48-p_hack-7/checkout/AmgXWrapper/install/include
AMGX_INCLUDE_DIR		?= /lustre/scratch2/ws/0/hpclab48-p_hack-7/spack/opt/spack/linux-rhel7-nehalem/gcc-7.3.0/amgx-2.1.0-cemsiua4kfpirnbmj3psltjujd3wheyu/include
PETSC_INCLUDE_DIR		?= /lustre/scratch2/ws/0/hpclab48-p_hack-7/spack/opt/spack/linux-rhel7-nehalem/gcc-7.3.0/petsc-3.13.4-ewj7iso4x7jiybfsmldux2ef2mgjkpfx/include

CC						:= gcc
CXX						:= g++
CFLAGS					:= -fPIC -Wall -Wextra -O2
INCLUDES				:= -I $(AMGXWRAPPER_INCLUDE_DIR) -I $(AMGX_INCLUDE_DIR) -I $(PETSC_INCLUDE_DIR)
TARGET_LIB				:= libamgx_c_wrapper.so

SOURCES					:= "src/amgx_c_wrapper.cpp"

all: $(TARGET_LIB)

$(TARGET_LIB): obj
	$(CC) $(CFLAGS) -shared -o $(TARGET_LIB) amgx_c_wrapper.o

obj:
	$(CXX) $(CFLAGS) $(INCLUDES) -o amgx_c_wrapper.o -c $(SOURCES)

install:
	mkdir -p lib include
	cp $(TARGET_LIB) lib/.
	cp src/amgx_c_wrapper.h include/.

clean:
	rm amgx_c_wrapper.o libamgx_c_wrapper.so

