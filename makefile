default:
	gcc -Wall -o prog main.c input.c athletes.c hosts.c listArrayList.c listElem.c mapArrayList.c mapElem.c medals.c show.c load.c clear.c medals_won.c athleteinfo.c
debug:
	gcc -Wall -o prog -g main.c input.c athletes.c hosts.c listArrayList.c listElem.c mapArrayList.c mapElem.c medals.c show.c load.c clear.c medals_won.c athleteinfo.c
clean:
	rm -f prog