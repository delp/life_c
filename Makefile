default:
	@gcc life.c -o life

run:
	@gcc life.c -o life
	@./life

clean:
	@rm life
