scons || exit 1

echo 'Build succeeded.'

bin=bin/main.bin

case $1 in
run)   $bin ;;
debug) gdb $bin ;;
time)  time $bin ;;
check) valgrind --leak-check=yes $bin ;;
*)     echo 'Done.' ;;
esac
