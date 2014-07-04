TARGET=Practica4
OUTDIR=../PDF's/

all: pdf clean move

pdf:
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@hr #Se necesita descargar el programa con 'brew install hr'
	@/usr/texbin/pdflatex -interaction=batchmode $(TARGET).tex
	@/usr/texbin/pdflatex -interaction=batchmode $(TARGET).tex

clean:
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.aux *.log *.fdb_latexmk

move:
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR) $(TARGET).pdf"
