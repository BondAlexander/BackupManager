export opts=-D_FORTIFY_SOURCE=2 -fno-diagnostics-show-option		\
    -fstack-protector-all -g -O3 -std=c++14 -Walloc-zero -Walloca	\
    -Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches		\
    -Werror -Wextra -Wfatal-errors -Winit-self -Wlogical-op		\
    -Wold-style-cast -Wpedantic -Wshadow -Wunused-const-variable=1	\
    -Wzero-as-null-pointer-constant -v
CXXFLAGS=-Wall

executable=BM_Console
class1=BackupManager

all:
<<<<<<< HEAD
	g++ -std=c++17 $(class1).cc -o $(executable) $(CXXFlags)

=======
	g++ $(class1).cc -o $(executable) $(CXXFlags)
>>>>>>> master
clean:
	rm -f *.o *.gch *.gcov a.out *.a
