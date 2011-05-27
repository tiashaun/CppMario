scons || exit 1

echo 'Build succeeded.'

case $1 in
run)   bin/main.bin ;;
debug) gdb bin/main.bin ;;
time)  time bin/main.bin ;;
*)     echo 'Done.' ;;
esac
