default:
	gcc -Wall -o prog main.c input.c athletes.c hosts.c listArrayList.c listElem.c mapArrayList.c mapElem.c medals.c load_a.c
debug:
	gcc -Wall -o prog -g main.c input.c athletes.c hosts.c listArrayList.c listElem.c mapArrayList.c mapElem.c medals.c load_a.c
clean:
	rm -f prog