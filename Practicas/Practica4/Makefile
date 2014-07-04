TARGET=Practica4
OUTDIR=../PDF's/

all: pdf clean move

pdf:
	@hr #Se necesita descargar el programa con 'brew install hr'
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@hr
	@/usr/texbin/pdflatex -interaction=batchmode $(TARGET).tex
	@/usr/texbin/pdflatex -interaction=batchmode $(TARGET).tex

clean:
	@hr
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.aux *.log *.fdb_latexmk

move:
	@hr
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET).pdf"
